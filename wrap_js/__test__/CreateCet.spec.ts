import * as cfddlcjs from "../../index.js";
import TestHelper from "./TestHelper";
import * as TestData from "./data/TestData";

const testCase = [
  TestHelper.createTestCase(
    "CreateCet",
    cfddlcjs.CreateCet,
    {
      localFundPubkey: TestData.LocalFundPubkey,
      localSweepPubkey: TestData.LocalSweepPubkey,
      remoteSweepPubkey: TestData.RemoteSweepPubkey,
      remoteFinalAddress: TestData.RemoteFinalAddress,
      oraclePubkey: TestData.OraclePubkey,
      oracleRPoints: TestData.OracleRPoints,
      messages: TestData.WinMessages,
      delay: 100,
      localPayout: TestData.WinAmount + BigInt(122),
      remotePayout: TestData.LoseAmount,
      fundTxId: TestData.FundTxId,
      fundVout: 0,
      maturityTime: BigInt(TestData.MaturityTime),
    },
    {
      hex: TestData.CetHexUnsigned,
    }
  ),
];

TestHelper.doTest("CreateCet", testCase);
