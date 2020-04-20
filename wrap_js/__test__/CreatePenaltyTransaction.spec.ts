import * as cfddlcjs from "../../index.js";
import TestHelper from "./TestHelper";
import * as TestData from "./data/TestData";

const testCase = [
  TestHelper.createTestCase(
    "CreatePenaltyTransaction",
    cfddlcjs.CreatePenaltyTransaction,
    {
      amount: TestData.WinAmount - BigInt(1000),
      finalAddress: TestData.RemoteFinalAddress,
      cetTxId: TestData.CetTxId,
      cetVout: 0,
    },
    {
      hex:
        "0200000001d65cb677571e387cc1c22a26832dce5e77f978b1fc9f478a44e77428e15863b70000000000ffffffff017837ea0b000000001600149652d86bedf43ad264362e6e6eba6eb76450812700000000",
    }
  ),
];

TestHelper.doTest("CreatePenaltyTransaction", testCase);
