# Part 4: Application logic

In this part we will write the functions to create the protocol messages as well as the callbacks to react to received messages.

We encapsulate these function in a `DlcParty` class, which represents a single party in a DLC.
We include this class within the `models` directory.
The logic of the application will also require interacting with a bitcoind instance.
To do so we use the [`bitcoin-simple-rpc` library](https://github.com/p2pderivatives/bitcoin-simple-rpc), which enables communication through JSON-RPC.

## Class members

We start by writing down the class members, including the private keys used by the party to sign the various transactions, as well as a `Contract` instance to keep track of the DLC information and a `Client` object to communicate with a bitcoind instance.

```typescript
import { Client } from "bitcoin-simple-rpc";
import Contract from "./Contract";
import PartyInputs from "./PartyInputs";

export default class DlcParty {
  readonly walletClient: Client;
  partyInputs: PartyInputs;
  fundPrivateKey: string;
  inputPrivateKeys: string[];
  contract: Contract;

  constructor(walletClient: Client) {
    this.walletClient = walletClient;
  }
```

## Initialization

At initialization, we need to get the required private keys, some addresses for change and receiving the payout, as well as the set of Utxos.

We first add some utility functions to our `Utils.ts` file (the names should be explicit about what they do):

```typescript
export function GetPrivkeyFromWif(wif: string) {
  const req = {
    wif,
  };

  return cfdjs.GetPrivkeyFromWif(req).hex;
}

export function DecodeRawTransaction(rawTransaction: string) {
  const reqJson: cfdjs.DecodeRawTransactionRequest = {
    hex: rawTransaction,
  };

  return cfdjs.DecodeRawTransaction(reqJson);
}
```

We can then write our `Initialize` method.
As the number of Utxos required depends on the amount of collateral input in the contract, we take this as a parameter.
We also extract a couple of functions to make our code more readable.

```typescript
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
      });
      if (total.CompareWith(amount) >= 0) break;
    }

    if (total.CompareWith(amount) < 0) throw new Error("Not enough funds");

    return utxoSet;
  }
```

You will also need to add the following imports to the file:

```typescript
import Amount from "./Amount";
import Utxo from "./Utxo";
import * as Utils from "../Utils/Utils";
```

## Creating transactions

During the setup of the DLC, we will need to create the transactions.
The DLC library provides a function to create them using the parameters generated in the initialization function.
We encapsulate it in a `CreateDlcTransactions` function:

```typescript
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
```

Note that we update the contract information at the same time.

You will also need to add the import for the `cfd-dlc-js` library:

```typescript
import * as cfddlcjs from "cfd-dlc-js";
```

## Contract initialization

Finally we can initialize a contract!
We create the `InitializeContract` function taking as input a partially filled contract, use it to initialize our instance and create an `OfferMessage`:

```typescript
  public async InitiateContract(initialContract: Contract) {
    this.contract = initialContract;
    await this.Initialize(this.contract.localCollateral);
    this.contract.localPartyInputs = this.partyInputs;
    return this.contract.GetOfferMessage();
  }
```

Note that we cannot yet create the transactions as when we are the initiator of the contract (the local party) we are missing information from our counter party to do so.

## Receiving an offer message

We then handle receiving an offer message.
Note that we assume that the contract is accepted in that case, we keep the acceptance/rejection logic outside the scope of this class.

When we receive an offer message, a couple of thing need to happen:

- First we will initialize our instance using the remote collateral amount (if we receive an offer message, we are the remote party),
- Second we can create the transactions, as we got the necessary information from the local party,
- Finally we can create the adaptor signatures for the CETs and the signature for the refund transaction, that we use to create an accept message, which also contains our set of Utxos.

```typescript
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
```

Don't forget to add the required imports:

```typescript
import OfferMessage from "./OfferMessage";
import AcceptMessage from "./AcceptMessage";
```

## Receiving an accept message

When receiving an accept message, the local party can create the transactions, verify that the signatures they received are valid for these transactions, and finally create their signatures to send them back in a sign message.

```typescript
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
```

And add the import for `SignMessage`:

```typescript
import SignMessage from "./SignMessage";
```

## Receiving a sign message

When receiving a sign message, the remote party should verify the adaptor signatures for the CETs and the signature for the refund transaction, and can then sign and broadcast the fund transaction.
Note that we could also verify the signature(s) for the fund transaction, but an invalid transaction for it will simply trigger an error from the bitcoind instance so we will skip that here.

```typescript
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
```

Note that we also generated a block so that the fund transaction gets included in the chain in regtest mode.
The code for this function is as follow:

```typescript
  // Put this outside the class
  const BurnAddress = "bcrt1qxcjufgh2jarkp2qkx68azh08w9v5gah8u6es8s";

  // And this inside
  async GenerateBlocks(nbBlocks: number) {
    await this.walletClient.generateToAddress(nbBlocks, BurnAddress);
  }
```

We use a burn address to generate the block to avoid changing the balance of the parties (otherwise it is more difficult to verify that the contract was properly executed).

## Closing the contract

Recall that the contract can be closed by either party, without any required communication between them.
We simply need to get the oracle signature, as well as which CET to use.
We thus take the signature as a parameter, and the outcome index that will determine which CET to select.
We then simply call the `SignCet` function that will take care of decrypting the adaptor signature of our counter-party and adding our own signature.
We can then finally broadcast the CET to receive our payout.

```typescript
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
```

That's it!
We now have all the methods we need to setup and execute a DLC.
This code could be integrated in any application, but in the [next part](./part5.md) we will use it to create a simple DLC CLI application.
