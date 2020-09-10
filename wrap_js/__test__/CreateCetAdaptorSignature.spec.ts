import * as cfddlcjs from "../../index.js";
import TestHelper from "./TestHelper";
import * as TestData from "./data/TestData";

const testCase = [
  TestHelper.createTestCase(
    "CreateCetAdaptorSignature",
    cfddlcjs.CreateCetAdaptorSignature,
    {
      cetHex: TestData.CetHexUnsigned,
      privkey: TestData.LocalFundPrivkey,
      localFundPubkey: TestData.LocalFundPubkey,
      remoteFundPubkey: TestData.RemoteFundPubkey,
      fundTxId: TestData.FundTxId,
      fundVout: 0,
      fundInputAmount: TestData.FundInputAmount,
      oraclePubkey: TestData.OraclePubkey,
      oracleRValue: TestData.OracleRPoint,
      message: TestData.Messages[0],
    },
    {
      signature: TestData.CetLocalAdaptorSignature,
      proof: TestData.CetLocalAdaptorProof,
    }
  ),
];

TestHelper.doTest("GetRawCetSignature", testCase);
