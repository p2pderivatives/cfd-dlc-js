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
      oracleRValues: [TestData.OracleRPoint],
      messages: [TestData.Messages[0]],
    },
    {
      signature: TestData.CetLocalAdaptorSignature,
      proof: TestData.CetLocalAdaptorProof,
    }
  ),
  TestHelper.createTestCase(
    "CreateCetAdaptorSignature Multiple Nonces",
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
      oracleRValues: [
        TestData.OracleRPoint,
        "7fb1cbb510efe5eb03b5381dafbe82db8e751bb546a3e203aabe7ebbc9d441c4",
      ],
      messages: [TestData.WinMessage, "MORE"],
    },
    {
      signature:
        "00cc296470e546717aaa8f54832c17d06ef81f61fba359df514b37faaa0ce0d9d431e88837d1ecc2e18899b77fab4fe76e123c1d4adfe960ecd12bf0f2d8950991",
      proof:
        "01912e7e952c7d1d569f8e745b9457a73668e56a0795efa1cdcec7058b66db5cb4d665daa2e387d48338b74e9865aca387207240840c6db22533245d4ae2a7e608c4f4adbecfb6ef9cb6329aeca2ca54a90e145d1ad31ea6dc7d5e1d048a31f902",
    }
  ),
];

TestHelper.doTest("GetRawCetSignature", testCase);
