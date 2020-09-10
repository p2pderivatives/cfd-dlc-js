import * as cfddlcjs from "../../index.js";
import * as CfdUtils from "../cfd_utils";
import TestHelper from "./TestHelper";
import * as TestData from "./data/TestData";

const testCase = [
  TestHelper.createTestCase(
    "CreateRefundTransaction",
    cfddlcjs.CreateRefundTransaction,
    {
      localFinalScriptPubkey: CfdUtils.GetAddressScript(
        TestData.LocalFinalAddress
      ),
      remoteFinalScriptPubkey: CfdUtils.GetAddressScript(
        TestData.RemoteFinalAddress
      ),
      localAmount: TestData.LocalCollateralAmount,
      remoteAmount: TestData.LocalCollateralAmount,
      fundTxId: TestData.FundTxId,
      fundVout: 0,
      lockTime: 100,
    },
    {
      hex: TestData.RefundTransactionUnsigned,
    }
  ),
];

TestHelper.doTest("CreateRefundTransaction", testCase);
