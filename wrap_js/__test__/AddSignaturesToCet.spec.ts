import * as cfddlcjs from "../../index.js";
import TestHelper from "./TestHelper";
import * as TestData from "./data/TestData";

const testCase = [
  TestHelper.createTestCase(
    "AddSignaturesToCet",
    cfddlcjs.AddSignaturesToCet,
    {
      cetHex: TestData.CetHexUnsigned,
      localFundPubkey: TestData.LocalFundPubkey,
      remoteFundPubkey: TestData.RemoteFundPubkey,
      fundTxId: TestData.FundTxId,
      fundVout: 0,
      signatures: [
        TestData.CetLocalRawSignature,
        TestData.CetRemoteRawSignature,
      ],
    },
    {
      hex: TestData.CetHexSigned,
    }
  ),
];

TestHelper.doTest("AddSignaturesToCet", testCase);
