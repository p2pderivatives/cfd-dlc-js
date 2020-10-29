import * as cfdjs from "cfd-js";
import * as CfdUtils from "../utils/Utils";
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
    this.publicKey = CfdUtils.GetSchnorrPubkeyFromPrivkey(this.privateKey);
    keyPair = CfdUtils.CreateKeyPair();
    this.kValue = keyPair.privkey;
    this.rValue = CfdUtils.GetSchnorrPubkeyFromPrivkey(this.kValue);
  }

  // Returns the public information for the Oracle.
  public GetOracleInfo() {
    return new OracleInfo(this.name, this.rValue, this.publicKey);
  }

  // Sign a given message using the private key and the R value.
  public GetSignature(message: string) {
    const signRequest: cfdjs.SchnorrSignRequest = {
      privkey: this.privateKey,
      message,
      nonceOrAux: this.kValue,
      isNonce: true,
    };

    return cfdjs.SchnorrSign(signRequest).hex;
  }
}
