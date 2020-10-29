import * as cfdjs from "cfd-js";

export function CreateKeyPair() {
  const reqJson: cfdjs.CreateKeyPairRequest = {
    wif: false,
  };
  return cfdjs.CreateKeyPair(reqJson);
}

export function GetPubkeyFromPrivkey(privkey: string) {
  const reqPrivKey = {
    privkey,
    isCompressed: true,
  };

  return cfdjs.GetPubkeyFromPrivkey(reqPrivKey).pubkey;
}

export function GetSchnorrPubkeyFromPrivkey(privkey: string) {
  const reqPrivKey = {
    privkey,
  };

  return cfdjs.GetSchnorrPubkeyFromPrivkey(reqPrivKey).pubkey;
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

export function GetAddressScript(address: string) {
  const req = { address };

  const info = cfdjs.GetAddressInfo(req);
  return info.lockingScript;
}
