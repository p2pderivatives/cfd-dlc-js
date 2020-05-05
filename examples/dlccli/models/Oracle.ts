import * as CfdUtils from "../utils/Utils";
import * as cfddlcjs from "../../../index";
import OracleInfo from "./OracleInfo";

export default class Oracle {
  readonly name: string;
  readonly kValue: string;
  readonly rValue: string;
  readonly publicKey: string;
  readonly privateKey: string;

  constructor(name: string) {
    this.name = name;
    let keyPair = CfdUtils.CreateKeyPair();
    this.privateKey = keyPair.privkey;
    this.publicKey = keyPair.pubkey;
    keyPair = CfdUtils.CreateKeyPair();
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
