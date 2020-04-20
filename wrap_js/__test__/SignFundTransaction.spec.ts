import * as cfddlcjs from "../../index.js";
import TestHelper from "./TestHelper";
import * as TestData from "./data/TestData";

const testCase = [
  TestHelper.createTestCase(
    "SignFundTransaction",
    cfddlcjs.SignFundTransaction,
    {
      fundTxHex: TestData.FundTxHexUnsigned,
      privkey: TestData.LocalInputPrivkey,
      prevTxId: TestData.LocalInputs[0].txid,
      prevVout: TestData.LocalInputs[0].vout,
      amount: BigInt(TestData.LocalInputAmount),
    },
    {
      hex: TestData.FundTxHexLocalSigned,
    }
  ),
];

TestHelper.doTest("SignFundTransaction", testCase);
