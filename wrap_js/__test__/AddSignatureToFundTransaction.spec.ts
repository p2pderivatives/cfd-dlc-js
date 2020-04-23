import * as cfddlcjs from "../../index.js";
import TestHelper from "./TestHelper";
import * as TestData from "./data/TestData";

const testCase = [
  TestHelper.createTestCase(
    "AddSignatureToFundTransaction",
    cfddlcjs.AddSignatureToFundTransaction,
    {
      fundTxHex: TestData.FundTxHexUnsigned,
      prevTxId: TestData.LocalInputs[0].txid,
      prevVout: TestData.LocalInputs[0].vout,
      signature: TestData.FundTxLocalRawSignature,
      pubkey: TestData.LocalInputPubkey,
    },
    {
      hex: TestData.FundTxHexLocalSigned,
    }
  ),
];

TestHelper.doTest("AddSignatureToFundTransaction", testCase);
