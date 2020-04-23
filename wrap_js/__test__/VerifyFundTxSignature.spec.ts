import * as cfddlcjs from "../../index.js";
import TestHelper from "./TestHelper";
import * as TestData from "./data/TestData";

const testCase = [
  TestHelper.createTestCase(
    "VerifyFundTxSignature Good Signature",
    cfddlcjs.VerifyFundTxSignature,
    {
      fundTxHex: TestData.FundTxHexUnsigned,
      signature: TestData.FundTxLocalRawSignature,
      pubkey: TestData.LocalInputPubkey,
      fundInputAmount: TestData.LocalInputAmount,
      prevTxId: TestData.LocalInputs[0].txid,
      prevVout: 0,
    },
    {
      valid: true,
    }
  ),
  TestHelper.createTestCase(
    "VerifyFundTxSignature Bad Signature",
    cfddlcjs.VerifyFundTxSignature,
    {
      fundTxHex: TestData.FundTxHexUnsigned,
      signature:
        "7208de1563ae311f8d4217e1c0c7463386c1a135be6af88cbe8d89a3a08d6509195a2b0140fb9ba83f20cf45ad6ea088bb0c6860c0d4995f1cf1353739ca65a9",
      pubkey: TestData.LocalInputPubkey,
      fundInputAmount: TestData.LocalInputAmount,
      prevTxId: TestData.LocalInputs[0].txid,
      prevVout: 0,
    },
    {
      valid: false,
    }
  ),
];

TestHelper.doTest("VerifyFundTxSignature", testCase);
