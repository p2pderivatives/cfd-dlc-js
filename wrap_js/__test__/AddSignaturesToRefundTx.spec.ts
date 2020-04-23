import * as cfddlcjs from "../../index.js";
import TestHelper from "./TestHelper";
import * as TestData from "./data/TestData";

const testCase = [
  TestHelper.createTestCase(
    "AddSignaturesToRefundTx",
    cfddlcjs.AddSignaturesToRefundTx,
    {
      refundTxHex: TestData.RefundTransactionUnsigned,
      localFundPubkey: TestData.LocalFundPubkey,
      remoteFundPubkey: TestData.RemoteFundPubkey,
      fundTxId: TestData.FundTxId,
      signatures: [
        TestData.RefundTransactionLocalRawSignature,
        TestData.RefundTransactionRemoteRawSignature,
      ],
    },
    {
      hex: TestData.RefundTransactionSigned,
    }
  ),
];

TestHelper.doTest("AddSignaturesToCet", testCase);
