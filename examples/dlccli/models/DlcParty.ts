import { Client } from "bitcoin-simple-rpc";
import * as cfddlcjs from "../../../index";
import * as Utils from "../utils/Utils";
import AcceptMessage from "./AcceptMessage";
import Amount from "./Amount";
import Contract from "./Contract";
import OfferMessage from "./OfferMessage";
import PartyInputs from "./PartyInputs";
import SignMessage from "./SignMessage";
import Utxo from "./Utxo";

const BurnAddress = "bcrt1qxcjufgh2jarkp2qkx68azh08w9v5gah8u6es8s";

export default class DlcParty {
  readonly walletClient: Client;
  partyInputs: PartyInputs;
  fundPrivateKey: string;
  inputPrivateKeys: string[];
  contract: Contract;

  constructor(walletClient: Client) {
    this.walletClient = walletClient;
  }

  private async Initialize(collateral: Amount) {
    const changeAddress = await this.walletClient.getNewAddress();
    const finalAddress = await this.walletClient.getNewAddress();
    this.fundPrivateKey = await this.GetNewPrivateKey();
    const fundPublicKey = Utils.GetPubkeyFromPrivkey(this.fundPrivateKey);
    const utxos = await this.GetUtxosForAmount(collateral);

    const inputs = new PartyInputs(
      fundPublicKey,
      changeAddress,
      finalAddress,
      utxos
    );

    this.inputPrivateKeys = await Promise.all(
      inputs.utxos.map(async (input) => await this.DumpPrivHex(input.address))
    );
    this.partyInputs = inputs;
  }

  private async GetNewPrivateKey() {
    const address = await this.walletClient.getNewAddress();
    return this.DumpPrivHex(address);
  }

  private async DumpPrivHex(address: string) {
    const wif = await this.walletClient.dumpPrivKey(address);
    return Utils.GetPrivkeyFromWif(wif);
  }

  private async GetUtxosForAmount(amount: Amount) {
    const unspent = await this.walletClient.listUnspent(1);
    const utxoSet: Utxo[] = [];
    let total = Amount.FromBitcoin(0);
    for (let i = 0; i < unspent.length; i++) {
      const utxo = unspent[i];
      total = total.AddBitcoins(utxo.amount);
      i++;
      utxoSet.push({
        txid: utxo.txid,
        vout: utxo.vout,
        amount: Amount.FromBitcoin(utxo.amount),
        address: utxo.address,
        maxWitnessLength: 108,
      });
      if (total.CompareWith(amount) >= 0) break;
      console.log(total.GetSatoshiAmount(), "  ", amount.GetSatoshiAmount());
    }

    if (total.CompareWith(amount) < 0) throw new Error("Not enough funds");

    return utxoSet;
  }

  private CreateDlcTransactions() {
    const dlcTxRequest: cfddlcjs.CreateDlcTransactionsRequest = {
      payouts: this.contract.payouts.map((payout) => {
        return {
          local: payout.local.GetSatoshiAmount(),
          remote: payout.remote.GetSatoshiAmount(),
        };
      }),
      localFundPubkey: this.contract.localPartyInputs.fundPublicKey,
      localFinalScriptPubkey: Utils.GetAddressScript(
        this.contract.localPartyInputs.finalAddress
      ),
      remoteFundPubkey: this.contract.remotePartyInputs.fundPublicKey,
      remoteFinalScriptPubkey: Utils.GetAddressScript(
        this.contract.remotePartyInputs.finalAddress
      ),
      localInputAmount: this.contract.localPartyInputs.GetTotalInputAmount(),
      localCollateralAmount: this.contract.localCollateral.GetSatoshiAmount(),
      remoteInputAmount: this.contract.remotePartyInputs.GetTotalInputAmount(),
      remoteCollateralAmount: this.contract.remoteCollateral.GetSatoshiAmount(),
      refundLocktime: this.contract.refundLockTime,
      localInputs: this.contract.localPartyInputs.utxos,
      remoteInputs: this.contract.remotePartyInputs.utxos,
      localChangeScriptPubkey: Utils.GetAddressScript(
        this.contract.localPartyInputs.changeAddress
      ),
      remoteChangeScriptPubkey: Utils.GetAddressScript(
        this.contract.remotePartyInputs.changeAddress
      ),
      feeRate: this.contract.feeRate,
    };

    const dlcTransactions = cfddlcjs.CreateDlcTransactions(dlcTxRequest);
    this.contract.fundTxHex = dlcTransactions.fundTxHex;
    const fundTransaction = Utils.DecodeRawTransaction(
      this.contract.fundTxHex
    );
    this.contract.fundTxId = fundTransaction.txid;
    this.contract.fundTxOutAmount = Amount.FromSatoshis(
      Number(fundTransaction.vout[0].value)
    );
    this.contract.refundTransaction = dlcTransactions.refundTxHex;
    this.contract.cetsHex = dlcTransactions.cetsHex;
  }

  public async InitiateContract(initialContract: Contract) {
    this.contract = initialContract;
    await this.Initialize(this.contract.localCollateral);
    this.contract.localPartyInputs = this.partyInputs;
    return this.contract.GetOfferMessage();
  }

  public async OnOfferMessage(offerMessage: OfferMessage) {
    this.contract = Contract.FromOfferMessage(offerMessage);
    await this.Initialize(offerMessage.remoteCollateral);
    this.contract.remotePartyInputs = this.partyInputs;
    this.CreateDlcTransactions();
    const cetSignRequest: cfddlcjs.CreateCetAdaptorSignaturesRequest = {
      messages: this.contract.messages,
      cetsHex: this.contract.cetsHex,
      privkey: this.fundPrivateKey,
      fundTxId: this.contract.fundTxId,
      localFundPubkey: offerMessage.localPartyInputs.fundPublicKey,
      remoteFundPubkey: this.partyInputs.fundPublicKey,
      fundInputAmount: this.contract.fundTxOutAmount.GetSatoshiAmount(),
      oraclePubkey: this.contract.oracleInfo.publicKey,
      oracleRValue: this.contract.oracleInfo.rValue,
    };

    const cetSignatures = cfddlcjs.CreateCetAdaptorSignatures(cetSignRequest);

    const refundSignRequest: cfddlcjs.GetRawRefundTxSignatureRequest = {
      refundTxHex: this.contract.refundTransaction,
      privkey: this.fundPrivateKey,
      fundTxId: this.contract.fundTxId,
      localFundPubkey: offerMessage.localPartyInputs.fundPublicKey,
      remoteFundPubkey: this.partyInputs.fundPublicKey,
      fundInputAmount: this.contract.fundTxOutAmount.GetSatoshiAmount(),
    };

    const refundSignature = cfddlcjs.GetRawRefundTxSignature(
      refundSignRequest
    );

    const acceptMessage = new AcceptMessage(
      this.partyInputs,
      cetSignatures.adaptorPairs,
      refundSignature.hex
    );

    return acceptMessage;
  }

  public OnAcceptMessage(acceptMessage: AcceptMessage) {
    this.contract.ApplyAcceptMessage(acceptMessage);
    this.CreateDlcTransactions();

    const verifyCetAdaptorSignaturesRequest = {
      cetsHex: this.contract.cetsHex,
      messages: this.contract.messages,
      oraclePubkey: this.contract.oracleInfo.publicKey,
      oracleRValue: this.contract.oracleInfo.rValue,
      adaptorPairs: acceptMessage.cetAdaptorPairs,
      localFundPubkey: this.contract.localPartyInputs.fundPublicKey,
      remoteFundPubkey: acceptMessage.remotePartyInputs.fundPublicKey,
      fundTxId: this.contract.fundTxId,
      fundInputAmount: this.contract.fundTxOutAmount.GetSatoshiAmount(),
      verifyRemote: true,
    };

    let areSigsValid = cfddlcjs.VerifyCetAdaptorSignatures(
      verifyCetAdaptorSignaturesRequest
    ).valid;

    const verifyRefundSigRequest: cfddlcjs.VerifyRefundTxSignatureRequest = {
      refundTxHex: this.contract.refundTransaction,
      signature: acceptMessage.refundSignature,
      localFundPubkey: this.contract.localPartyInputs.fundPublicKey,
      remoteFundPubkey: acceptMessage.remotePartyInputs.fundPublicKey,
      fundTxId: this.contract.fundTxId,
      fundInputAmount: this.contract.fundTxOutAmount.GetSatoshiAmount(),
      verifyRemote: true,
    };

    areSigsValid =
      areSigsValid &&
      cfddlcjs.VerifyRefundTxSignature(verifyRefundSigRequest).valid;

    if (!areSigsValid) {
      throw new Error("Invalid signatures received");
    }

    const cetAdaptorSignRequest: cfddlcjs.CreateCetAdaptorSignaturesRequest = {
      cetsHex: this.contract.cetsHex,
      privkey: this.fundPrivateKey,
      fundTxId: this.contract.fundTxId,
      localFundPubkey: this.partyInputs.fundPublicKey,
      remoteFundPubkey: this.contract.remotePartyInputs.fundPublicKey,
      fundInputAmount: this.contract.fundTxOutAmount.GetSatoshiAmount(),
      oraclePubkey: this.contract.oracleInfo.publicKey,
      oracleRValue: this.contract.oracleInfo.rValue,
      messages: this.contract.messages,
    };

    const cetAdaptorPairs = cfddlcjs.CreateCetAdaptorSignatures(
      cetAdaptorSignRequest
    ).adaptorPairs;

    const refundSignRequest: cfddlcjs.GetRawRefundTxSignatureRequest = {
      refundTxHex: this.contract.refundTransaction,
      privkey: this.fundPrivateKey,
      fundTxId: this.contract.fundTxId,
      localFundPubkey: this.partyInputs.fundPublicKey,
      remoteFundPubkey: this.contract.remotePartyInputs.fundPublicKey,
      fundInputAmount: this.contract.fundTxOutAmount.GetSatoshiAmount(),
    };

    const refundSignature = cfddlcjs.GetRawRefundTxSignature(refundSignRequest)
      .hex;

    const fundTxSigs = this.partyInputs.utxos.map((input, index) => {
      const fundTxSignRequest: cfddlcjs.GetRawFundTxSignatureRequest = {
        fundTxHex: this.contract.fundTxHex,
        privkey: this.inputPrivateKeys[index],
        prevTxId: input.txid,
        prevVout: input.vout,
        amount: input.amount.GetSatoshiAmount(),
      };

      return cfddlcjs.GetRawFundTxSignature(fundTxSignRequest).hex;
    });

    this.contract.refundLocalSignature = refundSignature;

    const inputPubKeys = this.inputPrivateKeys.map(Utils.GetPubkeyFromPrivkey);

    return new SignMessage(
      fundTxSigs,
      cetAdaptorPairs,
      refundSignature,
      inputPubKeys
    );
  }

  public async OnSignMessage(signMessage: SignMessage) {
    this.contract.ApplySignMessage(signMessage);

    const verifyCetSignaturesRequest = {
      cetsHex: this.contract.cetsHex,
      adaptorPairs: this.contract.cetAdaptorPairs,
      localFundPubkey: this.contract.localPartyInputs.fundPublicKey,
      remoteFundPubkey: this.contract.remotePartyInputs.fundPublicKey,
      fundTxId: this.contract.fundTxId,
      fundInputAmount: this.contract.fundTxOutAmount.GetSatoshiAmount(),
      verifyRemote: false,
      messages: this.contract.messages,
      oraclePubkey: this.contract.oracleInfo.publicKey,
      oracleRValue: this.contract.oracleInfo.rValue,
    };

    let areSigsValid = cfddlcjs.VerifyCetAdaptorSignatures(
      verifyCetSignaturesRequest
    ).valid;

    const verifyRefundSigRequest: cfddlcjs.VerifyRefundTxSignatureRequest = {
      refundTxHex: this.contract.refundTransaction,
      signature: this.contract.refundLocalSignature,
      localFundPubkey: this.contract.localPartyInputs.fundPublicKey,
      remoteFundPubkey: this.contract.remotePartyInputs.fundPublicKey,
      fundTxId: this.contract.fundTxId,
      fundInputAmount: this.contract.fundTxOutAmount.GetSatoshiAmount(),
      verifyRemote: false,
    };

    areSigsValid =
      areSigsValid &&
      cfddlcjs.VerifyRefundTxSignature(verifyRefundSigRequest).valid;

    if (!areSigsValid) {
      throw new Error("Invalid signatures received");
    }

    let fundTxHex = this.contract.fundTxHex;

    this.partyInputs.utxos.forEach((input, i) => {
      const fundSignRequest: cfddlcjs.SignFundTransactionRequest = {
        fundTxHex,
        privkey: this.inputPrivateKeys[i],
        prevTxId: input.txid,
        prevVout: input.vout,
        amount: input.amount.GetSatoshiAmount(),
      };

      fundTxHex = cfddlcjs.SignFundTransaction(fundSignRequest).hex;
    });

    signMessage.fundTxSignatures.forEach((signature, index) => {
      const addSignRequest: cfddlcjs.AddSignatureToFundTransactionRequest = {
        fundTxHex,
        signature,
        prevTxId: this.contract.localPartyInputs.utxos[index].txid,
        prevVout: this.contract.localPartyInputs.utxos[index].vout,
        pubkey: signMessage.utxoPublicKeys[index],
      };
      fundTxHex = cfddlcjs.AddSignatureToFundTransaction(addSignRequest).hex;
    });

    await this.walletClient.sendRawTransaction(fundTxHex);

    await this.GenerateBlocks(1);
  }

  public async SignAndBroadcastCet(
    outcomeIndex: number,
    oracleSignature: string
  ) {
    const signCetRequest: cfddlcjs.SignCetRequest = {
      cetHex: this.contract.cetsHex[outcomeIndex],
      fundPrivkey: this.fundPrivateKey,
      fundTxId: this.contract.fundTxId,
      localFundPubkey: this.contract.localPartyInputs.fundPublicKey,
      remoteFundPubkey: this.contract.remotePartyInputs.fundPublicKey,
      oracleSignature,
      fundInputAmount: this.contract.fundTxOutAmount.GetSatoshiAmount(),
      adaptorSignature: this.contract.cetAdaptorPairs[outcomeIndex].signature,
    };

    const finalCet = cfddlcjs.SignCet(signCetRequest).hex;

    await this.walletClient.sendRawTransaction(finalCet);
    await this.GenerateBlocks(1);
  }

  async GenerateBlocks(nbBlocks: number) {
    await this.walletClient.generateToAddress(nbBlocks, BurnAddress);
  }
}
