import * as cfddlcjs from "../../index.js";
import TestHelper from "./TestHelper";
import * as TestData from "./data/TestData";

const testCase = [
  TestHelper.createTestCase(
    "VerifyRefundTxSignature Local",
    cfddlcjs.VerifyRefundTxSignature,
    {
      refundTxHex: TestData.RefundTransactionUnsigned,
      localFundPubkey: TestData.LocalFundPubkey,
      remoteFundPubkey: TestData.RemoteFundPubkey,
      fundTxId: TestData.FundTxId,
      fundVout: 0,
      fundInputAmount: TestData.FundInputAmount,
      signature: TestData.RefundTransactionLocalRawSignature,
      verifyRemote: false,
    },
    {
      valid: true,
    }
  ),
  TestHelper.createTestCase(
    "VerifyRefundTxSignature Remote",
    cfddlcjs.VerifyRefundTxSignature,
    {
      refundTxHex: TestData.RefundTransactionUnsigned,
      localFundPubkey: TestData.LocalFundPubkey,
      remoteFundPubkey: TestData.RemoteFundPubkey,
      fundTxId: TestData.FundTxId,
      fundVout: 0,
      fundInputAmount: TestData.FundInputAmount,
      signature: TestData.RefundTransactionRemoteRawSignature,
      verifyRemote: true,
    },
    {
      valid: true,
    }
  ),
  TestHelper.createTestCase(
    "VerifyRefundTxSignature Bad Signature",
    cfddlcjs.VerifyRefundTxSignature,
    {
      refundTxHex: TestData.RefundTransactionUnsigned,
      localFundPubkey: TestData.LocalFundPubkey,
      remoteFundPubkey: TestData.RemoteFundPubkey,
      fundTxId: TestData.FundTxId,
      fundVout: 0,
      fundInputAmount: TestData.FundInputAmount,
      signature:
        "7b3460f1e7f5af3738467715f621774282eba8fa1752c859338c095dd952764d13b3ba4b2a3ec489715b2c10974c4395cb49e7ba7acae7f0125549a53f68679a",
      verifyRemote: true,
    },
    {
      valid: false,
    }
  ),
];

TestHelper.doTest("VerifyRefundTxSignature", testCase);
