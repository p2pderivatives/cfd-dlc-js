import * as cfddlcjs from "../../index.js";
import TestHelper from "./TestHelper";
import * as TestData from "./data/TestData";

const testCase = [
  TestHelper.createTestCase(
    "CreateDlcTransactions",
    cfddlcjs.CreateDlcTransactions,
    {
      outcomes: [
        {
          local: TestData.WinAmount,
          remote: TestData.LoseAmount,
          messages: TestData.WinMessages,
        },
        {
          local: TestData.LoseAmount,
          remote: TestData.WinAmount,
          messages: TestData.LoseMessages,
        },
      ],
      oracleRPoints: TestData.OracleRPoints,
      oraclePubkey: TestData.OraclePubkey,
      localFundPubkey: TestData.LocalFundPubkey,
      remoteFundPubkey: TestData.RemoteFundPubkey,
      localSweepPubkey: TestData.LocalSweepPubkey,
      remoteSweepPubkey: TestData.RemoteSweepPubkey,
      localInputAmount: BigInt(TestData.LocalInputAmount),
      localCollateralAmount: BigInt(TestData.LocalCollateralAmount),
      remoteInputAmount: BigInt(TestData.RemoteInputAmount),
      remoteCollateralAmount: TestData.RemoteCollateralAmount,
      timeout: 100,
      localInputs: [
        {
          txid: TestData.LocalInputs[0].txid,
          vout: TestData.LocalInputs[0].vout,
        },
      ],
      localChangeAddress: TestData.LocalChangeAddress,
      remoteInputs: [
        {
          txid: TestData.RemoteInputs[0].txid,
          vout: TestData.RemoteInputs[0].vout,
        },
      ],
      remoteChangeAddress: TestData.RemoteChangeAddress,
      maturityTime: BigInt(1579072156),
      feeRate: 1,
      localFinalAddress: TestData.LocalFinalAddress,
      remoteFinalAddress: TestData.RemoteFinalAddress,
    },
    {
      fundTxHex:
        "02000000024f601442e48eec22ff3a907c5f5290c6a0d3d08fb869e46ebfbaa9226b6d26830000000000ffffffff98bbd477219a151a1daf5377b30e8c5f9fb574783943f33ac523ef072fa292bc0000000000ffffffff0338c3eb0b000000002200209b984c7bae3efddc3a3f0a20ff81bfe89ed1fe07ff13e562149ee654bed845dbe70f102401000000160014fa3629f3060b6c1a5a365c30bf66fa00f155cb9ee70f10240100000016001465d4d622585baf5151de860b1e7af58710f20da200000000",
      closingCetsHex: [
        "020000000164b0942d90b9b815f76548b207a2d8ee75fc250a233ab44c3e13e01cd4a5f1f40000000000feffffff02da3bea0b00000000220020a8df06fb6408f8502af80f09cd9a9084603568c2338eda1a30b8e9bf62b679aea0860100000000001600149652d86bedf43ad264362e6e6eba6eb7645081279cba1e5e",
        "020000000164b0942d90b9b815f76548b207a2d8ee75fc250a233ab44c3e13e01cd4a5f1f40000000000feffffff021a87010000000000220020f2f30cbf414fd2049e779e9f72ef31c00fe183b5775956a0380a838bd1bc9033603bea0b000000001600149652d86bedf43ad264362e6e6eba6eb7645081279cba1e5e",
      ],
      refundTxHex:
        "020000000164b0942d90b9b815f76548b207a2d8ee75fc250a233ab44c3e13e01cd4a5f1f40000000000feffffff0248e1f505000000001600145dedfbf9ea599dd4e3ca6a80b333c472fd0b3f6948e1f505000000001600149652d86bedf43ad264362e6e6eba6eb76450812764000000",
    }
  ),
];

TestHelper.doTest("CreateDlcTransactions", testCase);
