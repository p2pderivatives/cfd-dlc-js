import * as cfddlcjs from "../../index.js";
import TestHelper from "./TestHelper";
import * as TestData from "./data/TestData";

const testCase = [
  TestHelper.createTestCase(
    "VerifyCetAdaptorSignature Local",
    cfddlcjs.VerifyCetAdaptorSignature,
    {
      cetHex: TestData.CetHexUnsigned,
      localFundPubkey: TestData.LocalFundPubkey,
      remoteFundPubkey: TestData.RemoteFundPubkey,
      fundTxId: TestData.FundTxId,
      fundInputAmount: TestData.FundInputAmount,
      adaptorSignature: TestData.CetLocalAdaptorSignature,
      adaptorProof: TestData.CetLocalAdaptorProof,
      messages: [TestData.WinMessage],
      oraclePubkey: TestData.OraclePubkey,
      oracleRValues: [TestData.OracleRPoint],
      verifyRemote: false,
    },
    {
      valid: true,
    }
  ),
  TestHelper.createTestCase(
    "VerifyCetSignature Remote",
    cfddlcjs.VerifyCetAdaptorSignature,
    {
      cetHex: TestData.CetHexUnsigned,
      localFundPubkey: TestData.LocalFundPubkey,
      remoteFundPubkey: TestData.RemoteFundPubkey,
      fundTxId: TestData.FundTxId,
      fundInputAmount: TestData.FundInputAmount,
      adaptorSignature: TestData.CetRemoteAdaptorSignature,
      adaptorProof: TestData.CetRemoteAdaptorProof,
      messages: [TestData.Messages[0]],
      oraclePubkey: TestData.OraclePubkey,
      oracleRValues: [TestData.OracleRPoint],
      verifyRemote: true,
    },
    {
      valid: true,
    }
  ),
  TestHelper.createTestCase(
    "VerifyCetSignature Bad Signature",
    cfddlcjs.VerifyCetAdaptorSignature,
    {
      cetHex: TestData.CetHexUnsigned,
      localFundPubkey: TestData.LocalFundPubkey,
      remoteFundPubkey: TestData.RemoteFundPubkey,
      fundTxId: TestData.FundTxId,
      fundInputAmount: TestData.FundInputAmount,
      adaptorSignature:
        "007ae15ae89be929e7a022ec370e4edf9e7e8dca29e6ee8aa4a3b73596b8987caf798443cd661eeee26e5514e905479b5a3b352d3777ce9d8c8ecea130d50fe7ac",
      adaptorProof: TestData.CetLocalAdaptorProof,
      oraclePubkey: TestData.OraclePubkey,
      oracleRValues: [TestData.OracleRPoint],
      messages: [TestData.Messages[0]],
      verifyRemote: true,
    },
    {
      valid: false,
    }
  ),
];

TestHelper.doTest("VerifyCetSignature", testCase);
