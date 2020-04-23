import * as cfddlcjs from "../../index.js";
import TestHelper from "./TestHelper";
import * as TestData from "./data/TestData";

const testCase = [
  TestHelper.createTestCase(
    "CreateClosingTransaction",
    cfddlcjs.CreateClosingTransaction,
    {
      address: TestData.LocalFinalAddress,
      amount: TestData.WinAmount - 1000,
      cetTxId: TestData.CetTxId,
      cetVout: 0,
    },
    {
      hex:
        "0200000001d65cb677571e387cc1c22a26832dce5e77f978b1fc9f478a44e77428e15863b70000000000ffffffff017837ea0b000000001600145dedfbf9ea599dd4e3ca6a80b333c472fd0b3f6900000000",
    }
  ),
];

TestHelper.doTest("CreateClosingTransaction", testCase);
