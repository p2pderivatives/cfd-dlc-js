import * as cfdjs from "cfd-js";

export function GetPubkeyFromPrivkey(privkey: string) {
  const reqPrivKey = {
    privkey,
    isCompressed: true,
  };

  return cfdjs.GetPubkeyFromPrivkey(reqPrivKey).pubkey;
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
  const data: cfdjs.CreateAddressKeyData = {
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

export function DecodeRawTransaction(rawTransaction: string) {
  const reqJson: cfdjs.DecodeRawTransactionRequest = {
    hex: rawTransaction,
  };

  return cfdjs.DecodeRawTransaction(reqJson);
}
