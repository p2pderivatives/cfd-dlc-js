"use strict";
var __importStar = (this && this.__importStar) || function (mod) {
    if (mod && mod.__esModule) return mod;
    var result = {};
    if (mod != null) for (var k in mod) if (Object.hasOwnProperty.call(mod, k)) result[k] = mod[k];
    result["default"] = mod;
    return result;
};
Object.defineProperty(exports, "__esModule", { value: true });
const CfdUtils = __importStar(require("../../cfd_utils"));
const CfdDlcUtils = __importStar(require("../../cfddlc_utils"));
exports.OraclePrivkey = "ded9a76a0a77399e1c2676324118a0386004633f16245ad30d172b15c1f9e2d3";
exports.OraclePubkey = CfdUtils.GetPubkeyFromPrivkey(exports.OraclePrivkey);
exports.OracleKValue = "be3cc8de25c50e25f69e2f88d151e3f63e99c3a44fed2bdd2e3ee70fe141c5c3";
exports.OracleRPoints = CfdDlcUtils.GetSchnorrPublicNonce(exports.OracleKValue);
exports.OracleSignature = "8a820c2a94e3f85362c457b80cff914b13fbbd67df49df24181f3b916331a2e6";
exports.LocalFundPrivkey = "0000000000000000000000000000000000000000000000000000000000000001";
exports.LocalFundPubkey = CfdUtils.GetPubkeyFromPrivkey(exports.LocalFundPrivkey);
exports.RemoteFundPrivkey = "0000000000000000000000000000000000000000000000000000000000000002";
exports.RemoteFundPubkey = CfdUtils.GetPubkeyFromPrivkey(exports.RemoteFundPrivkey);
exports.LocalSweepPrivkey = "0000000000000000000000000000000000000000000000000000000000000003";
exports.LocalSweepPubkey = CfdUtils.GetPubkeyFromPrivkey(exports.LocalSweepPrivkey);
exports.RemoteSweepPrivkey = "0000000000000000000000000000000000000000000000000000000000000004";
exports.RemoteSweepPubkey = CfdUtils.GetPubkeyFromPrivkey(exports.RemoteSweepPrivkey);
exports.LocalInputPrivkey = "0000000000000000000000000000000000000000000000000000000000000005";
exports.LocalInputPubkey = CfdUtils.GetPubkeyFromPrivkey(exports.LocalInputPrivkey);
exports.RemoteInputPrivkey = "0000000000000000000000000000000000000000000000000000000000000006";
exports.RemoteInputPubkey = CfdUtils.GetPubkeyFromPrivkey(exports.RemoteInputPrivkey);
exports.LocalInputAmount = 50;
exports.RemoteInputAmount = 50;
exports.LocalCollateralAmount = BigInt(100000000);
exports.RemoteCollateralAmount = BigInt(100000000);
exports.FundOutput = BigInt(200000312);
exports.WinAmount = BigInt(199900000);
exports.LoseAmount = BigInt(100000);
exports.WinMessages = ["WIN"];
exports.LoseMessages = ["LOSE"];
exports.LocalInputs = [
    {
        txid: "83266d6b22a9babf6ee469b88fd0d3a0c690525f7c903aff22ec8ee44214604f",
        vout: 0,
    },
];
exports.RemoteInputs = [
    {
        txid: "bc92a22f07ef23c53af343397874b59f5f8c0eb37753af1d1a159a2177d4bb98",
        vout: 0,
    },
];
exports.LocalChangeAddress = "bcrt1qlgmznucxpdkp5k3ktsct7eh6qrc4tju7ktjukn";
exports.RemoteChangeAddress = "bcrt1qvh2dvgjctwh4z5w7sc93u7h4sug0yrdz2lgpqf";
exports.LocalFinalAddress = "bcrt1qthklh702txwafc72d2qtxv7ywt7sk0mfv7esk7";
exports.RemoteFinalAddress = "bcrt1qjefds6ld7sadyepk9ehxawnwkaj9pqf8wnz54j";
exports.MaturityTime = 1579072156;
