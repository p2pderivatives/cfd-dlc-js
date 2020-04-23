import * as cfddlcjs from "../../index.js";
import TestHelper from "./TestHelper";
import * as TestData from "./data/TestData";

const testCase = [
  TestHelper.createTestCase(
    "GetRawFundTxSignature",
    cfddlcjs.GetRawFundTxSignature,
    {
      fundTxHex: TestData.FundTxHexUnsigned,
      privkey: TestData.LocalInputPrivkey,
      prevTxId: TestData.LocalInputs[0].txid,
      prevVout: TestData.LocalInputs[0].vout,
      amount: TestData.LocalInputAmount,
    },
    {
      hex: TestData.FundTxLocalRawSignature,
    }
  ),
];

TestHelper.doTest("GetRawFundTxSignature", testCase);
