import * as cfddlcjs from "../../index.js";
import TestHelper from "./TestHelper";
import * as TestData from "./data/TestData";

const testCase = [
  TestHelper.createTestCase(
    "GetRawMutualClosingTxSignature",
    cfddlcjs.GetRawMutualClosingTxSignature,
    {
      mutualClosingHex: TestData.MutualClosingTransactionUnsigned,
      privkey: TestData.LocalFundPrivkey,
      localFundPubkey: TestData.LocalFundPubkey,
      remoteFundPubkey: TestData.RemoteFundPubkey,
      fundTxId: TestData.FundTxId,
      fundVout: 0,
      fundInputAmount: TestData.FundInputAmount,
    },
    {
      hex: TestData.MutualClosingTransactionLocalRawSignature,
    }
  ),
];

TestHelper.doTest("GetMutualClosingTxSignature", testCase);
