import * as cfdjs from "cfd-js";

export function GetPubkeyFromPrivkey(privkey: string) {
  const reqPrivKey = {
    privkey,
    isCompressed: true,
  };

  return cfdjs.GetPubkeyFromPrivkey(reqPrivKey).pubkey;
}

export function GetSchnorrPubkeyFromPrivkey(privkey: string) {
  const req = { privkey };

  return cfdjs.GetSchnorrPubkeyFromPrivkey(req).pubkey;
}

export function GetExtPubFromExtPriv(extPriv: string) {
  const reqJson = {
    extkey: extPriv,
    network: "testnet",
  };

  const resp = cfdjs.CreateExtPubkey(reqJson);
  return resp.extkey;
}

export function GetPrivKeyFromExtPriv(extPriv: string) {
  const reqJson = {
    extkey: extPriv,
    network: "testnet",
    wif: false,
    isCompressed: true,
  };

  const resp = cfdjs.GetPrivkeyFromExtkey(reqJson);
  return resp.privkey;
}

export function GetPubkeyFromExtPriv(extPriv: string) {
  const priv = GetPrivKeyFromExtPriv(extPriv);
  return GetPubkeyFromPrivkey(priv);
}

export function GetChildPrivKeyFromExtPriv(extPriv: string, index: number) {
  const reqJson: cfdjs.CreateExtkeyFromParentPathRequest = {
    extkey: extPriv,
    network: "regtest",
    path: `m/0/${index}`,
    extkeyType: "extPrivkey",
    childNumberArray: [],
  };
  const extChild = cfdjs.CreateExtkeyFromParentPath(reqJson).extkey;

  const reqJson2: cfdjs.GetPrivkeyFromExtkeyRequest = {
    extkey: extChild,
    network: "regtest",
    wif: false,
    isCompressed: false,
  };

  const priv = cfdjs.GetPrivkeyFromExtkey(reqJson2).privkey;
  return priv;
}

export function GetAddressFromPubkey(pubkey: string) {
  const data: cfdjs.HashKeyData = {
    hex: pubkey,
    type: "pubkey",
  };
  const reqJson: cfdjs.CreateAddressRequest = {
    isElements: false,
    keyData: data,
    network: "regtest",
    hashType: "p2wpkh",
  };

  return cfdjs.CreateAddress(reqJson).address;
}

export function GetPrivkeyFromWif(wif: string) {
  const req = {
    wif,
  };

  return cfdjs.GetPrivkeyFromWif(req).hex;
}

export function DecodeRawTransaction(
  rawTransaction: string
): cfdjs.DecodeRawTransactionResponse {
  const reqJson: cfdjs.DecodeRawTransactionRequest = {
    hex: rawTransaction,
  };

  return cfdjs.DecodeRawTransaction(reqJson);
}

export function CreateKeyPair() {
  const reqJson: cfdjs.CreateKeyPairRequest = {
    wif: false,
  };
  return cfdjs.CreateKeyPair(reqJson);
}

export function SchnorrSign(
  message: string,
  privkey: string,
  nonceOrAux: string,
  isHashed = false,
  isNonce = true
) {
  const req: cfdjs.SchnorrSignRequest = {
    privkey,
    message,
    nonceOrAux,
    isNonce,
    isHashed,
  };

  return cfdjs.SchnorrSign(req).hex;
}

export function SchnorrVerify(
  message: string,
  signature: string,
  pubkey: string
) {
  const req = {
    message,
    signature,
    pubkey,
  };

  return cfdjs.SchnorrVerify(req).valid;
}

export function GetAddressScript(address: string) {
  const req = { address };

  const info = cfdjs.GetAddressInfo(req);
  return info.lockingScript;
}

export function ParseAsmScript(input: string) {
  const items = [input];
  const req = {
    items,
  };
  return cfdjs.CreateScript(req).hex;
}
