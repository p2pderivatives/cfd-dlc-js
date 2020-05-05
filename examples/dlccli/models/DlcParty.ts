import PartyInputs from "./PartyInputs";
import Client from "bitcoin-core";
import * as Utils from "../utils/Utils";
import * as cfddlcjs from "../../../index";
import Contract from "./Contract";
import OfferMessage from "./OfferMessage";
import AcceptMessage from "./AcceptMessage";
import SignMessage from "./SignMessage";
import Outcome from "./Outcome";
import MutualClosingMessage from "./MutualClosingMessage";
import Amount from "./Amount";
import Utxo from "./Utxo";

const BurnAddress = "bcrt1qxcjufgh2jarkp2qkx68azh08w9v5gah8u6es8s";

export default class DlcParty {
  readonly walletClient: Client;
  readonly passphrase: string;
  partyInputs: PartyInputs;
  fundPrivateKey: string;
  sweepPrivateKey: string;
  inputPrivateKeys: string[];
  contract: Contract;

  constructor(walletClient: Client, passphrase: string) {
    this.walletClient = walletClient;
    this.passphrase = passphrase;
  }

  private async Initialize(collateral: Amount) {
    await this.walletClient.walletPassphrase(this.passphrase, 10);
    const changeAddress = await this.walletClient.getNewAddress();
    const finalAddress = await this.walletClient.getNewAddress();
    this.fundPrivateKey = await this.GetNewPrivateKey();
    this.sweepPrivateKey = await this.GetNewPrivateKey();
    const fundPublicKey = Utils.GetPubkeyFromPrivkey(this.fundPrivateKey);
    const sweepPublicKey = Utils.GetPubkeyFromPrivkey(this.sweepPrivateKey);
    const utxos = await this.GetUtxosForAmount(collateral);

    const inputs = new PartyInputs(
      fundPublicKey,
      sweepPublicKey,
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
      });
      if (total.CompareWith(amount) >= 0) break;
      console.log(total.GetSatoshiAmount(), "  ", amount.GetSatoshiAmount());
    }

    if (total.CompareWith(amount) < 0) throw new Error("Not enough funds");

    return utxoSet;
  }

  private CreateDlcTransactions() {
    const dlcTxRequest: cfddlcjs.CreateDlcTransactionsRequest = {
      outcomes: this.contract.outcomes.map((outcome) => {
        return {
          messages: [outcome.message],
          local: outcome.local.GetSatoshiAmount(),
          remote: outcome.remote.GetSatoshiAmount(),
        };
      }),
      oracleRPoints: [this.contract.oracleInfo.rValue],
      oraclePubkey: this.contract.oracleInfo.publicKey,
      localFundPubkey: this.contract.localPartyInputs.fundPublicKey,
      localSweepPubkey: this.contract.localPartyInputs.sweepPublicKey,
      localFinalAddress: this.contract.localPartyInputs.finalAddress,
      remoteFundPubkey: this.contract.remotePartyInputs.fundPublicKey,
      remoteSweepPubkey: this.contract.remotePartyInputs.sweepPublicKey,
      remoteFinalAddress: this.contract.remotePartyInputs.finalAddress,
      localInputAmount: this.contract.localPartyInputs.GetTotalInputAmount(),
      localCollateralAmount: this.contract.localCollateral.GetSatoshiAmount(),
      remoteInputAmount: this.contract.remotePartyInputs.GetTotalInputAmount(),
      remoteCollateralAmount: this.contract.remoteCollateral.GetSatoshiAmount(),
      timeout: this.contract.cetCsvDelay,
      localInputs: this.contract.localPartyInputs.utxos,
      remoteInputs: this.contract.remotePartyInputs.utxos,
      localChangeAddress: this.contract.localPartyInputs.changeAddress,
      remoteChangeAddress: this.contract.remotePartyInputs.changeAddress,
      feeRate: this.contract.feeRate,
      maturityTime: Math.floor(this.contract.maturityTime.getTime() / 1000),
    };

    const dlcTransactions = cfddlcjs.CreateDlcTransactions(dlcTxRequest);
    this.contract.fundTxHex = dlcTransactions.fundTxHex;
    const fundTransaction = Utils.DecodeRawTransaction(this.contract.fundTxHex);
    this.contract.fundTxId = fundTransaction.txid;
    this.contract.fundTxOutAmount = Amount.FromSatoshis(
      Number(fundTransaction.vout[0].value)
    );
    this.contract.refundTransaction = dlcTransactions.refundTxHex;
    this.contract.localCetsHex = dlcTransactions.localCetsHex;
    this.contract.remoteCetsHex = dlcTransactions.remoteCetsHex;
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
    const cetSignRequest: cfddlcjs.GetRawCetSignaturesRequest = {
      cetsHex: this.contract.localCetsHex,
      privkey: this.fundPrivateKey,
      fundTxId: this.contract.fundTxId,
      localFundPubkey: offerMessage.localPartyInputs.fundPublicKey,
      remoteFundPubkey: this.partyInputs.fundPublicKey,
      fundInputAmount: this.contract.fundTxOutAmount.GetSatoshiAmount(),
    };

    const cetSignatures = cfddlcjs.GetRawCetSignatures(cetSignRequest);

    const refundSignRequest: cfddlcjs.GetRawRefundTxSignatureRequest = {
      refundTxHex: this.contract.refundTransaction,
      privkey: this.fundPrivateKey,
      fundTxId: this.contract.fundTxId,
      localFundPubkey: offerMessage.localPartyInputs.fundPublicKey,
      remoteFundPubkey: this.partyInputs.fundPublicKey,
      fundInputAmount: this.contract.fundTxOutAmount.GetSatoshiAmount(),
    };

    const refundSignature = cfddlcjs.GetRawRefundTxSignature(refundSignRequest);

    const acceptMessage = new AcceptMessage(
      this.partyInputs,
      cetSignatures.hex,
      refundSignature.hex
    );

    return acceptMessage;
  }

  public OnAcceptMessage(acceptMessage: AcceptMessage) {
    this.contract.ApplyAcceptMessage(acceptMessage);
    this.CreateDlcTransactions();

    const verifyCetSignaturesRequest: cfddlcjs.VerifyCetSignaturesRequest = {
      cetsHex: this.contract.localCetsHex,
      signatures: acceptMessage.cetSignatures,
      localFundPubkey: this.contract.localPartyInputs.fundPublicKey,
      remoteFundPubkey: acceptMessage.remotePartyInputs.fundPublicKey,
      fundTxId: this.contract.fundTxId,
      fundInputAmount: this.contract.fundTxOutAmount.GetSatoshiAmount(),
      verifyRemote: true,
    };

    let areSigsValid = cfddlcjs.VerifyCetSignatures(verifyCetSignaturesRequest)
      .valid;

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

    const cetSignRequest: cfddlcjs.GetRawCetSignaturesRequest = {
      cetsHex: this.contract.remoteCetsHex,
      privkey: this.fundPrivateKey,
      fundTxId: this.contract.fundTxId,
      localFundPubkey: this.partyInputs.fundPublicKey,
      remoteFundPubkey: this.contract.remotePartyInputs.fundPublicKey,
      fundInputAmount: this.contract.fundTxOutAmount.GetSatoshiAmount(),
    };

    const cetSignatures = cfddlcjs.GetRawCetSignatures(cetSignRequest).hex;

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
      cetSignatures,
      refundSignature,
      inputPubKeys
    );
  }

  public async OnSignMessage(signMessage: SignMessage) {
    this.contract.ApplySignMessage(signMessage);

    const verifyCetSignaturesRequest: cfddlcjs.VerifyCetSignaturesRequest = {
      cetsHex: this.contract.remoteCetsHex,
      signatures: this.contract.cetSignatures,
      localFundPubkey: this.contract.localPartyInputs.fundPublicKey,
      remoteFundPubkey: this.contract.remotePartyInputs.fundPublicKey,
      fundTxId: this.contract.fundTxId,
      fundInputAmount: this.contract.fundTxOutAmount.GetSatoshiAmount(),
      verifyRemote: false,
    };

    let areSigsValid = cfddlcjs.VerifyCetSignatures(verifyCetSignaturesRequest)
      .valid;

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

  public CreateMutualClosingMessage(outcome: Outcome) {
    const mutualClosingRequest = {
      localFinalAddress: this.contract.localPartyInputs.finalAddress,
      remoteFinalAddress: this.contract.remotePartyInputs.finalAddress,
      localAmount: outcome.local.GetSatoshiAmount(),
      remoteAmount: outcome.remote.GetSatoshiAmount(),
      fundTxId: this.contract.fundTxId,
      feeRate: this.contract.feeRate,
    };

    const mutualClosingTx = cfddlcjs.CreateMutualClosingTransaction(
      mutualClosingRequest
    ).hex;

    const signRequest: cfddlcjs.GetRawMutualClosingTxSignatureRequest = {
      fundTxId: this.contract.fundTxId,
      mutualClosingHex: mutualClosingTx,
      privkey: this.fundPrivateKey,
      localFundPubkey: this.contract.localPartyInputs.fundPublicKey,
      remoteFundPubkey: this.contract.remotePartyInputs.fundPublicKey,
      fundInputAmount: this.contract.fundTxOutAmount.GetSatoshiAmount(),
    };

    const signature = cfddlcjs.GetRawMutualClosingTxSignature(signRequest).hex;

    return new MutualClosingMessage(outcome, signature);
  }

  public async OnMutualClosingMessage(
    mutualClosingMessage: MutualClosingMessage
  ) {
    const mutualClosingRequest = {
      localFinalAddress: this.contract.localPartyInputs.finalAddress,
      remoteFinalAddress: this.contract.remotePartyInputs.finalAddress,
      localAmount: mutualClosingMessage.outcome.local.GetSatoshiAmount(),
      remoteAmount: mutualClosingMessage.outcome.remote.GetSatoshiAmount(),
      fundTxId: this.contract.fundTxId,
      feeRate: this.contract.feeRate,
    };

    let mutualClosingTx = cfddlcjs.CreateMutualClosingTransaction(
      mutualClosingRequest
    ).hex;

    const signRequest: cfddlcjs.GetRawMutualClosingTxSignatureRequest = {
      fundTxId: this.contract.fundTxId,
      mutualClosingHex: mutualClosingTx,
      privkey: this.fundPrivateKey,
      localFundPubkey: this.contract.localPartyInputs.fundPublicKey,
      remoteFundPubkey: this.contract.remotePartyInputs.fundPublicKey,
      fundInputAmount: this.contract.fundTxOutAmount.GetSatoshiAmount(),
    };

    const signature = cfddlcjs.GetRawMutualClosingTxSignature(signRequest).hex;

    const signatures = this.contract.isLocalParty
      ? [signature, mutualClosingMessage.signature]
      : [mutualClosingMessage.signature, signature];

    const addSigsRequest: cfddlcjs.AddSignaturesToMutualClosingTxRequest = {
      mutualClosingTxHex: mutualClosingTx,
      signatures,
      fundTxId: this.contract.fundTxId,
      localFundPubkey: this.contract.localPartyInputs.fundPublicKey,
      remoteFundPubkey: this.contract.remotePartyInputs.fundPublicKey,
    };

    mutualClosingTx = cfddlcjs.AddSignaturesToMutualClosingTx(addSigsRequest)
      .hex;

    await this.walletClient.sendRawTransaction(mutualClosingTx);

    await this.GenerateBlocks(1);
  }

  public async ExecuteUnilateralClose(
    oracleSignature: string,
    outcomeIndex: number
  ) {
    const cets = this.contract.isLocalParty
      ? this.contract.localCetsHex
      : this.contract.remoteCetsHex;

    let cetHex = cets[outcomeIndex];

    const signRequest: cfddlcjs.GetRawCetSignatureRequest = {
      cetHex,
      privkey: this.fundPrivateKey,
      fundTxId: this.contract.fundTxId,
      localFundPubkey: this.contract.localPartyInputs.fundPublicKey,
      remoteFundPubkey: this.contract.remotePartyInputs.fundPublicKey,
      fundInputAmount: this.contract.fundTxOutAmount.GetSatoshiAmount(),
    };

    const cetSign = cfddlcjs.GetRawCetSignature(signRequest).hex;

    const signatures = this.contract.isLocalParty
      ? [cetSign, this.contract.cetSignatures[outcomeIndex]]
      : [this.contract.cetSignatures[outcomeIndex], cetSign];

    const addSignRequest: cfddlcjs.AddSignaturesToCetRequest = {
      cetHex,
      signatures,
      fundTxId: this.contract.fundTxId,
      localFundPubkey: this.contract.localPartyInputs.fundPublicKey,
      remoteFundPubkey: this.contract.remotePartyInputs.fundPublicKey,
    };

    cetHex = cfddlcjs.AddSignaturesToCet(addSignRequest).hex;

    const cet = Utils.DecodeRawTransaction(cetHex);

    const outcomeAmount = this.contract.isLocalParty
      ? this.contract.outcomes[outcomeIndex].local
      : this.contract.outcomes[outcomeIndex].remote;

    const closingTxRequest: cfddlcjs.CreateClosingTransactionRequest = {
      address: this.partyInputs.finalAddress,
      amount: outcomeAmount.GetSatoshiAmount(),
      cetTxId: cet.txid,
    };

    let closingTxHex = cfddlcjs.CreateClosingTransaction(closingTxRequest).hex;

    const remoteSweepKey = this.contract.isLocalParty
      ? this.contract.remotePartyInputs.sweepPublicKey
      : this.contract.localPartyInputs.sweepPublicKey;

    const signClosingRequest: cfddlcjs.SignClosingTransactionRequest = {
      closingTxHex,
      cetTxId: cet.txid,
      amount: cet.vout[0].value,
      localFundPrivkey: this.fundPrivateKey,
      localSweepPubkey: this.partyInputs.sweepPublicKey,
      remoteSweepPubkey: remoteSweepKey,
      oraclePubkey: this.contract.oracleInfo.publicKey,
      oracleRPoints: [this.contract.oracleInfo.rValue],
      oracleSigs: [oracleSignature],
      messages: [this.contract.outcomes[outcomeIndex].message],
      delay: this.contract.cetCsvDelay,
    };

    closingTxHex = cfddlcjs.SignClosingTransaction(signClosingRequest).hex;

    await this.walletClient.sendRawTransaction(cetHex);
    await this.walletClient.sendRawTransaction(closingTxHex);
    await this.GenerateBlocks(1);
  }

  async GenerateBlocks(nbBlocks: number) {
    await this.walletClient.generateToAddress(nbBlocks, BurnAddress);
  }
}
