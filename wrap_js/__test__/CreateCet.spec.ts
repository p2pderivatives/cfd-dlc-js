import * as cfddlcjs from "../../index.js";
import TestHelper from "./TestHelper";
import * as TestData from "./data/TestData";

const testCase = [
  TestHelper.createTestCase(
    "CreateCet",
    cfddlcjs.CreateCet,
    {
      localFundPubkey: TestData.LocalFundPubkey,
      remoteFinalAddress: TestData.RemoteFinalAddress,
      localPayout: TestData.WinAmount,
      remotePayout: TestData.LoseAmount,
      fundTxId: TestData.FundTxId,
      fundVout: 0,
      remoteFundPubkey: TestData.RemoteFundPubkey,
      localFinalAddress: TestData.LocalFinalAddress,
      lockTime: 0,
    },
    {
      hex: TestData.CetHexUnsigned,
    }
  ),
];

TestHelper.doTest("CreateCet", testCase);
