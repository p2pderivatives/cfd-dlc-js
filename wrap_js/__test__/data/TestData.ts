import * as CfdUtils from "../../cfd_utils";
import * as CfdDlcUtils from "../../cfddlc_utils";

export const OraclePrivkey =
  "ded9a76a0a77399e1c2676324118a0386004633f16245ad30d172b15c1f9e2d3";
export const OraclePubkey = CfdUtils.GetPubkeyFromPrivkey(OraclePrivkey);
export const OracleKValue =
  "be3cc8de25c50e25f69e2f88d151e3f63e99c3a44fed2bdd2e3ee70fe141c5c3";
export const OracleRPoints = CfdDlcUtils.GetSchnorrPublicNonce(OracleKValue);
export const OracleSignature =
  "8a820c2a94e3f85362c457b80cff914b13fbbd67df49df24181f3b916331a2e6";
export const LocalFundPrivkey =
  "0000000000000000000000000000000000000000000000000000000000000001";
export const LocalFundPubkey = CfdUtils.GetPubkeyFromPrivkey(LocalFundPrivkey);
export const RemoteFundPrivkey =
  "0000000000000000000000000000000000000000000000000000000000000002";
export const RemoteFundPubkey = CfdUtils.GetPubkeyFromPrivkey(
  RemoteFundPrivkey
);
export const LocalSweepPrivkey =
  "0000000000000000000000000000000000000000000000000000000000000003";
export const LocalSweepPubkey = CfdUtils.GetPubkeyFromPrivkey(
  LocalSweepPrivkey
);
export const RemoteSweepPrivkey =
  "0000000000000000000000000000000000000000000000000000000000000004";
export const RemoteSweepPubkey = CfdUtils.GetPubkeyFromPrivkey(
  RemoteSweepPrivkey
);
export const LocalInputPrivkey =
  "0000000000000000000000000000000000000000000000000000000000000005";
export const LocalInputPubkey = CfdUtils.GetPubkeyFromPrivkey(
  LocalInputPrivkey
);
export const RemoteInputPrivkey =
  "0000000000000000000000000000000000000000000000000000000000000006";
export const RemoteInputPubkey = CfdUtils.GetPubkeyFromPrivkey(
  RemoteInputPrivkey
);
export const LocalInputAmount = 50;
export const RemoteInputAmount = 50;
export const LocalCollateralAmount = BigInt(100000000);
export const RemoteCollateralAmount = BigInt(100000000);
export const FundOutput = BigInt(200000312);
export const WinAmount = BigInt(199900000);
export const LoseAmount = BigInt(100000);
export const WinMessages = ["WIN"];
export const LoseMessages = ["LOSE"];
export const LocalInputs = [
  {
    txid: "83266d6b22a9babf6ee469b88fd0d3a0c690525f7c903aff22ec8ee44214604f",
    vout: 0,
  },
];
export const RemoteInputs = [
  {
    txid: "bc92a22f07ef23c53af343397874b59f5f8c0eb37753af1d1a159a2177d4bb98",
    vout: 0,
  },
];
export const LocalChangeAddress =
  "bcrt1qlgmznucxpdkp5k3ktsct7eh6qrc4tju7ktjukn";
export const RemoteChangeAddress =
  "bcrt1qvh2dvgjctwh4z5w7sc93u7h4sug0yrdz2lgpqf";
export const LocalFinalAddress = "bcrt1qthklh702txwafc72d2qtxv7ywt7sk0mfv7esk7";
export const RemoteFinalAddress =
  "bcrt1qjefds6ld7sadyepk9ehxawnwkaj9pqf8wnz54j";
export const MaturityTime = 1579072156;
