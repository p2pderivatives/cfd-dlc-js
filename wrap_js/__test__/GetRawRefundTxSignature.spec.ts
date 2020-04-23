import * as cfddlcjs from "../../index.js";
import TestHelper from "./TestHelper";
import * as TestData from "./data/TestData";

const testCase = [
  TestHelper.createTestCase(
    "GetRawRefundTxSignature",
    cfddlcjs.GetRawRefundTxSignature,
    {
      refundTxHex: TestData.RefundTransactionUnsigned,
      privkey: TestData.LocalFundPrivkey,
      localFundPubkey: TestData.LocalFundPubkey,
      remoteFundPubkey: TestData.RemoteFundPubkey,
      fundTxId: TestData.FundTxId,
      fundVout: 0,
      fundInputAmount: TestData.FundInputAmount,
    },
    {
      hex: TestData.RefundTransactionLocalRawSignature,
    }
  ),
];

TestHelper.doTest("GetRefundTxSignature", testCase);
