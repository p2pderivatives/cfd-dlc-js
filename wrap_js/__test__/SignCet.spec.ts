import * as cfddlcjs from "../../index";
import TestHelper from "./TestHelper";
import * as TestData from "./data/TestData";

const testCase = [
  TestHelper.createTestCase(
    "SignCet",
    cfddlcjs.SignCet,
    {
      cetHex: TestData.CetHexUnsigned,
      localFundPubkey: TestData.LocalFundPubkey,
      remoteFundPubkey: TestData.RemoteFundPubkey,
      fundTxId: TestData.FundTxId,
      adaptorSignature: TestData.CetLocalAdaptorSignature,
      fundPrivkey: TestData.RemoteFundPrivkey,
      fundInputAmount: TestData.FundInputAmount,
      oracleSignature: TestData.OracleSignature,
    },
    {
      hex: TestData.CetHexSigned,
    }
  ),
];

TestHelper.doTest("AddSignaturesToCet", testCase);
