# Part 4: Application logic

In this part we will write the functions to create the protocol messages as well as the callbacks to react to received messages.

We encapsulate these function in a `DlcParty` class, which represents a single party in a DLC.
We include this class within the `models` directory.
The logic of the application will also require interacting with a bitcoind instance.
To do so we use the `bitcoin-core` library, which enables communication through JSON-RPC.
You can find the type definition files (`bitcoin-core.d.ts`) [here](https://github.com/p2pderivatives/cfd-js/blob/master/example/dlccli/types/bitcoin-core.d.ts).
Put this file in a `types` folder in the root directory.

## Class members

We start by writing down the class members, including the private keys used by the party to sign the various transactions, as well as a `Contract` instance to keep track of the DLC information and a `Client` object to communicate with a bitcoind instance.

```typescript
import PartyInputs from "./PartyInputs";
import Contract from "./Contract";
import Client from "bitcoin-core";

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
}
```

## Initialization

At initialization, we need to get the required private keys, some addresses for change and receiving the payout, as well as the set of Utxos.

We first add some utility functions to our `Utils.ts` file (the names should be explicit about what they do):

```typescript
export function GetPubkeyFromPrivkey(privkey: string) {
  const reqPrivKey = {
    privkey,
    isCompressed: true,
  };

  return cfdjs.GetPubkeyFromPrivkey(reqPrivKey).pubkey;
}

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

We can the write our `Initialize` method.
As the number of Utxos required depends on the amount of collateral input in the contract, we take this as a parameter.
We also extract a couple of functions to make our code more readable.

```typescript

  private async Initialize(collateral: Amount) {
    await this.walletClient.walletPassphrase(this.passphrase, 10);
    const changeAddress = await this.walletClient.getNewAddress();
    const finalAddress = await this.walletClient.getNewAddress();
    this.fundPrivateKey = await this.GetNewPrivateKey();
    this.sweepPrivateKey = await this.GetNewPrivateKey();
    const fundPublicKey = Utils.GetPubkeyFromPrivkey(this.fundPrivateKey);
    const sweepPublicKey = Utils.GetPubkeyFromPrivkey(this.sweepPrivateKey);
    const utxos = await this.GetUtxosForAmount(
      collateral
    );

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
- Finally we can create the signatures for the CETs and the refund transaction, that we use to create an accept message, which also contains our set of Utxos.

```typescript

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
```

And add the import for `SignMessage`:

```typescript
import SignMessage from "./SignMessage";
```

## Receiving a sign message

When receiving a sign message, the remote party should verify the signatures for the CETs and refund transaction, and can then sign and broadcast the fund transaction.
Note that we could also verify the signature(s) for the fund transaction, but an invalid transaction for it will simply trigger an error from the bitcoind instance so we will skip that here.

```typescript
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

Recall that the contract can be closed either cooperatively using a mutual closing transaction, or unilaterally.

### Cooperative closing

To handle cooperative closing, we add two functions, one to create a mutual closing message, and another one to receive it.
We of course need to know the outcome on which to close the contract so we take that as a parameter.

```typescript
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
```

You will need the following imports:

```typescript
import Outcome from "./Outcome";
import MutualClosingMessage from "./MutualClosingMessage";
```

### Unilateral closing

To close the channel unilaterally, we need to get the oracle signature, as well as which CET to use.
We thus take the signature as a parameter, and the outcome index that will determine which CET to select.
We first sign the adequate CET, and add the signature from our counter party (that we received during the setup).
We then sign the closing transaction using our private key and the oracle signature, and then broadcast both transactions:

```typescript

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
```

That's it!
We now have all the methods we need to setup and execute a DLC.
This code could be integrated in any application, but in the [next part](./part5.md) we will use it to create a simple DLC CLI application.
