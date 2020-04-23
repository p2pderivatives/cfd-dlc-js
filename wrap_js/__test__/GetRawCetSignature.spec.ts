import * as cfddlcjs from "../../index.js";
import TestHelper from "./TestHelper";
import * as TestData from "./data/TestData";

const testCase = [
  TestHelper.createTestCase(
    "GetRawCetSignature",
    cfddlcjs.GetRawCetSignature,
    {
      cetHex: TestData.CetHexUnsigned,
      privkey: TestData.LocalFundPrivkey,
      localFundPubkey: TestData.LocalFundPubkey,
      remoteFundPubkey: TestData.RemoteFundPubkey,
      fundTxId: TestData.FundTxId,
      fundVout: 0,
      fundInputAmount: TestData.FundInputAmount,
    },
    {
      hex: TestData.CetLocalRawSignature,
    }
  ),
];

TestHelper.doTest("GetRawCetSignature", testCase);
