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
      localAmount: TestData.LocalCollateralAmount + 72,
      remoteAmount: TestData.LocalCollateralAmount + 72,
      feeRate: 1,
      fundTxId: TestData.FundTxId,
      fundVout: 0,
    },
    {
      hex: TestData.MutualClosingTransactionUnsigned,
    }
  ),
];

TestHelper.doTest("CreateMutualClosingTransaction", testCase);
