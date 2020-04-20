import * as cfddlcjs from "../../index.js";
import TestHelper from "./TestHelper";
import * as TestData from "./data/TestData";

const testCase = [
  TestHelper.createTestCase(
    "AddSignaturesToMutualClosingTx",
    cfddlcjs.AddSignaturesToMutualClosingTx,
    {
      mutualClosingTxHex: TestData.MutualClosingTransactionUnsigned,
      localFundPubkey: TestData.LocalFundPubkey,
      remoteFundPubkey: TestData.RemoteFundPubkey,
      fundTxId: TestData.FundTxId,
      fundVout: 0,
      signatures: [
        TestData.MutualClosingTransactionLocalRawSignature,
        TestData.MutualClosingTransactionRemoteRawSignature,
      ],
    },
    {
      hex: TestData.MutualClosingTransactionSigned,
    }
  ),
];

TestHelper.doTest("AddSignaturesToCet", testCase);
