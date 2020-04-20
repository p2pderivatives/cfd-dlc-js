import * as cfddlcjs from "../../index.js";
import TestHelper from "./TestHelper";
import * as TestData from "./data/TestData";

const testCase = [
  TestHelper.createTestCase(
    "CreateMutualClosingTransaction",
    cfddlcjs.CreateMutualClosingTransaction,
    {
      localFinalAddress: TestData.LocalFinalAddress,
      remoteFinalAddress: TestData.RemoteFinalAddress,
      localAmount: TestData.LocalCollateralAmount + BigInt(72),
      remoteAmount: TestData.LocalCollateralAmount + BigInt(72),
      fundTxId: TestData.FundTxId,
      fundVout: 0,
    },
    {
      hex: TestData.MutualClosingTransactionUnsigned,
    }
  ),
];

TestHelper.doTest("CreateMutualClosingTransaction", testCase);
