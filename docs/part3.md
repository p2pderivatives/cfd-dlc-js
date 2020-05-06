# Part 3: Models

In this part we will define some base models of our application.
But before starting let's have a look at how the DLC library works.

## Crypto Financial Development Kit for DLC

The `cfd-dlc` library is a C++ library providing a set of functions to create DCL transactions, sign them and verify signatures.
The `cfd-dlc-js` library is a JavaScript wrapper for it.
The functions provided by the library all take as parameter an object named `functionNameRequest` and return an object named `functionNameResponse`.
The library also contains a type definition file to make it easier to create these objects in TypeScript.

## Amount

As you probably know, Bitcoin has different units, the satoshi being the smallest one, while the bitcoin is the largest.
To enable easy conversion to and from these units we start by defining an `Amount` class.
Create a `models` folder in the root of your app and add the following in a `Amount.ts` file.

```typescript
// Used to convert between satoshi and bitcoin.
const ConversionFactor = 100000000;

export default class Amount {
  // Holds the actual amount in satoshis
  private readonly _satoshis: number;

  private constructor(satoshis) {
    this._satoshis = satoshis;
  }

  // Create an Amount object using bitcoin unit.
  public static FromBitcoin(bitcoin: number) {
    return new Amount(bitcoin * ConversionFactor);
  }

  // Create an Amount object using satoshi unit.
  public static FromSatoshis(satoshis: number) {
    return new Amount(satoshis);
  }

  // Get the amount value in bitcoin.
  public GetBitcoinAmount() {
    return this._satoshis * ConversionFactor;
  }

  // Get the amount value in satoshi.
  public GetSatoshiAmount() {
    return this._satoshis;
  }

  // Return a new Amount object with value increased by the given amount of
  // satoshi.
  public AddSatoshis(satoshis: number) {
    return new Amount(this._satoshis + satoshis);
  }

  // Return a new Amount object with value increased by the given amount of
  // bitcoin.
  public AddBitcoins(bitcoins: number) {
    return new Amount(this._satoshis + bitcoins * ConversionFactor);
  }

  // Return a new Amount object with value increased by the given amount.
  public AddAmount(amount: Amount) {
    return new Amount(this._satoshis + amount._satoshis);
  }

  // Returns the difference between the amount of satoshi in this object and
  // the amount of satoshi of the given object.
  public CompareWith(amount: Amount) {
    return this._satoshis - amount._satoshis;
  }
}
```

## Utxo

Having represented amounts, we add the `Utxo` class in the same folder to hold information about unspent transaction outputs:

```typescript
import Amount from "./Amount";

export default class Utxo {
  constructor(
    readonly txid: string,
    readonly vout: number,
    readonly amount: Amount,
    readonly address: string
  ) {}
}
```

Note that this is using the [parameter properties](https://www.typescriptlang.org/docs/handbook/classes.html#parameter-properties) to save space, feel free not to use it.

## PartyInputs

And with this we can represent the set of inputs to a DLC for a single party with the `PartyInputs` class.
Note that the inputs are only the one that relate to the Bitcoin blockchain, not to the contract.

```typescript
import Utxo from "./Utxo";

export default class PartyInputs {
  constructor(
    readonly fundPublicKey: string,
    readonly sweepPublicKey: string,
    readonly changeAddress: string,
    readonly finalAddress: string,
    readonly utxos: Utxo[]
  ) {}

  public GetTotalInputAmount() {
    return this.utxos.reduce<number>(
      (prev, cur) => prev + cur.amount.GetSatoshiAmount(),
      0
    );
  }
}
```

We also added a convenient method to get the sum of the Utxo values.

## Outcomes

As we saw in [Part 1](./index.md), a DLC can have multiple different outcomes, each potentially giving different payouts to each party.
We define the `Outcome` class to represent a single outcome:

```typescript
import Amount from "./Amount";

export default class Outcome {
  constructor(
    readonly message: string,
    readonly local: Amount,
    readonly remote: Amount
  ) {}
}
```

## Oracle and Oracle Info

We are going to create two classes for the Oracle.
One containing the information private to the Oracle, and another one containing the public information.

### Oracle Info

The `OracleInfo` class contains the public information, that is the oracle public key, and the R value that will be used when signing the outcome of the event.
Note that in a more realistic case we would have multiple R values, one for each event on which the oracle plans to provide a signature.

```typescript
export default class OracleInfo {
  constructor(
    readonly name: string,
    readonly rValue: string,
    readonly publicKey: string
  ) {}
}
```

### Oracle

Before defining the Oracle class, we are going to need some utility function from the CFD library.

Create a `utils` folder with a `Utils.ts` file inside and add the following code:

```typescript
import * as cfdjs from "cfd-js";

export function CreateKeyPair() {
  const reqJson: cfdjs.CreateKeyPairRequest = {
    wif: false,
  };
  return cfdjs.CreateKeyPair(reqJson);
}
```

This will enable us to generate public/private key pairs.

We can now define the Oracle class:

```typescript
import * as Utils from "../Utils/Utils";
import * as cfddlcjs from "cfd-dlc-js";
import OracleInfo from "./OracleInfo";

export default class Oracle {
  readonly name: string;
  readonly kValue: string;
  readonly rValue: string;
  readonly publicKey: string;
  readonly privateKey: string;

  constructor(name: string) {
    this.name = name;
    let keyPair = Utils.CreateKeyPair();
    this.privateKey = keyPair.privkey;
    this.publicKey = keyPair.pubkey;
    keyPair = Utils.CreateKeyPair();
    this.kValue = keyPair.privkey;
    this.rValue = cfddlcjs.GetSchnorrPublicNonce({ kValue: this.kValue }).hex;
  }

  // Returns the public information for the Oracle.
  public GetOracleInfo() {
    return new OracleInfo(this.name, this.rValue, this.publicKey);
  }

  // Sign a given message using the private key and the R value.
  public GetSignature(message: string) {
    const signRequest: cfddlcjs.SchnorrSignRequest = {
      privkey: this.privateKey,
      kValue: this.kValue,
      message,
    };

    return cfddlcjs.SchnorrSign(signRequest).hex;
  }
}
```

Here we use two functions from the DLC library:

- `GetSchnorrPublicNonce` enable getting the R value from the k value of the oracle. Note that in a further update this API will change due to updates to the BIP 340 defining Schnorr signature usage in Bitcoin.
- `SchnorrSignRequest` is the function performing the actual signing.

## Protocol messages

We will now define the four message types that make up the DLC protocol.

### OfferMessage

In the offer message we include information about the contract for the remote party to decide on whether to accept it or not, in addition to information about the oracle and the DLC inputs for the local party.
After receiving this message, and if they decide to accept the contract, the remote party will have all the required information to create the set of transaction for the DLC.

```typescript
import Outcome from "./Outcome";
import OracleInfo from "./OracleInfo";
import PartyInputs from "./PartyInputs";
import Amount from "./Amount";

export default class OfferMessage {
  constructor(
    readonly contractId: string,
    readonly localCollateral: Amount,
    readonly remoteCollateral: Amount,
    readonly maturityTime: Date,
    readonly outcomes: Outcome[],
    readonly oracleInfo: OracleInfo,
    readonly localPartyInputs: PartyInputs,
    readonly feeRate: number,
    readonly cetCsvDelay: number,
    readonly refundLockTime: number
  ) {}
}
```

### AcceptMessage

The accept message contains the DLC inputs for the remote party as well as their signatures for the CETs and refund transaction:

```typescript
import PartyInputs from "./PartyInputs";

export default class AcceptMessage {
  constructor(
    readonly remotePartyInputs: PartyInputs,
    readonly cetSignatures: string[],
    readonly refundSignature: string
  ) {}
}
```

### SignMessage

The sign message contains the signatures for the fund transaction, CETs and refund transaction.
We also add the public keys for the set of UTXOs that are used as input to the fund transaction as a convenience.

```typescript
export default class SignMessage {
  constructor(
    readonly fundTxSignatures: string[],
    readonly cetSignatures: string[],
    readonly refundSignature: string,
    readonly utxoPublicKeys: string[]
  ) {}
}
```

### Mutual closing message

The last message is used for a party to propose a cooperative closing of the DLC.
It contains the outcome on which the party proposes to close, as well as a signature for the corresponding mutual closing transaction.

```typescript
import Outcome from "./Outcome";

export default class MutualClosingMessage {
  constructor(readonly outcome: Outcome, readonly signature: string) {}
}
```

## Contract

To keep information about a DLC, we define a `Contract` class.
This class will keep track of everything needed to create the transactions as well as the signatures.
We also add some useful function to create the offer message and update the contract based on the content of the accept and sign messages.

```typescript
import Outcome from "./Outcome";
import PartyInputs from "./PartyInputs";
import OracleInfo from "./OracleInfo";
import OfferMessage from "./OfferMessage";
import AcceptMessage from "./AcceptMessage";
import SignMessage from "./SignMessage";
import Amount from "./Amount";

export default class Contract {
  id: string;
  localCollateral: Amount;
  remoteCollateral: Amount;
  outcomes: Outcome[];
  maturityTime: Date;
  feeRate: number;
  localPartyInputs: PartyInputs;
  remotePartyInputs: PartyInputs;
  oracleInfo: OracleInfo;
  cetCsvDelay: number;
  refundLockTime: number;
  isLocalParty: boolean;
  fundTxHex: string;
  fundTxId: string;
  fundTxOutAmount: Amount;
  fundTxSignatures: string[];
  refundTransaction: string;
  refundLocalSignature: string;
  refundRemoteSignature: string;
  localCetsHex: string[];
  remoteCetsHex: string[];
  cetSignatures: string[];

  constructor() {
    this.outcomes = [];
  }

  public static FromOfferMessage(offerMessage: OfferMessage) {
    const contract = new Contract();
    contract.id = offerMessage.contractId;
    contract.localCollateral = offerMessage.localCollateral;
    contract.remoteCollateral = offerMessage.remoteCollateral;
    contract.maturityTime = offerMessage.maturityTime;
    contract.outcomes = offerMessage.outcomes;
    contract.oracleInfo = offerMessage.oracleInfo;
    contract.localPartyInputs = offerMessage.localPartyInputs;
    contract.feeRate = offerMessage.feeRate;
    contract.cetCsvDelay = offerMessage.cetCsvDelay;
    contract.refundLockTime = offerMessage.refundLockTime;
    contract.isLocalParty = false;
    return contract;
  }

  public GetOfferMessage(): OfferMessage {
    this.isLocalParty = true;
    return {
      contractId: this.id,
      localCollateral: this.localCollateral,
      remoteCollateral: this.remoteCollateral,
      maturityTime: this.maturityTime,
      outcomes: this.outcomes,
      oracleInfo: this.oracleInfo,
      localPartyInputs: this.localPartyInputs,
      feeRate: this.feeRate,
      cetCsvDelay: this.cetCsvDelay,
      refundLockTime: this.refundLockTime,
    };
  }

  public ApplyAcceptMessage(acceptMessage: AcceptMessage) {
    this.cetSignatures = acceptMessage.cetSignatures;
    this.refundRemoteSignature = acceptMessage.refundSignature;
    this.remotePartyInputs = acceptMessage.remotePartyInputs;
  }

  public ApplySignMessage(signMessage: SignMessage) {
    this.cetSignatures = signMessage.cetSignatures;
    this.refundLocalSignature = signMessage.refundSignature;
    this.fundTxSignatures = signMessage.fundTxSignatures;
  }
}
```

Now that we have some base models, we will implement the application logic in [part 4](./part4.md).
