import * as CfdUtils from "./cfd_utils";

export async function GetNewPrivateKeyFromWallet(wallet: any) {
  const resp = await wallet.getNewAddress("p2pkh", "");
  const wif = await wallet.dumpPrivkey(resp.address);
  return CfdUtils.GetPrivkeyFromWif(wif);
}

export async function GetP2WPKHAddress(wallet: any) {
  const resp = await wallet.getNewAddress("p2wpkh", "");
  return resp.address;
}
