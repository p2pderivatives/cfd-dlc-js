import * as cfddlcjs from "../../index.js";
import TestHelper from "./TestHelper";
import * as TestData from "./data/TestData";

const testCase = [
  TestHelper.createTestCase(
    "VerifyCetSignatures",
    cfddlcjs.VerifyCetAdaptorSignatures,
    {
      cetsHex: [
        TestData.CetHexUnsigned,
        "02000000019246862ea34db0833bd4bd9e657d61e2e5447d0438f6f6181d1cd329e8cf71c30000000000ffffffff02a0860100000000001600145dedfbf9ea599dd4e3ca6a80b333c472fd0b3f69603bea0b000000001600149652d86bedf43ad264362e6e6eba6eb76450812700000000",
      ],
      localFundPubkey: TestData.LocalFundPubkey,
      remoteFundPubkey: TestData.RemoteFundPubkey,
      fundTxId: TestData.FundTxId,
      fundInputAmount: TestData.FundInputAmount,
      adaptorPairs: [
        {
          signature: TestData.CetLocalAdaptorSignature,
          proof: TestData.CetLocalAdaptorProof,
        },
        {
          signature:
            "0181de460ae3c75d05d83ea40ecd0d28cc31c1807cfe021935b9cdb8ac8957e71485263b445847d2f4aa79eeaff06e8601478b4e2c0e206499472430dd82df9ae0",
          proof:
            "000b8d891be111325d965296dec76909f7ce815bd152263cb5112c0f37dcf05cf2f09cd7991eaf30278ee0547e4f22cb3596909c5478c9799c349566a5e1ff38c4c5ad442ba4c3631ada85e9a75cab100757b10bb8091f99e237661fbb8d6c76f9",
        },
      ],
      verifyRemote: false,
      messagesList: [
        { messages: [TestData.Messages[0]] },
        { messages: [TestData.Messages[1]] },
      ],
      oraclePubkey: TestData.OraclePubkey,
      oracleRValues: [TestData.OracleRPoint],
    },
    {
      valid: true,
    }
  ),
  TestHelper.createTestCase(
    "VerifyCetSignatures invalid signature",
    cfddlcjs.VerifyCetAdaptorSignatures,
    {
      cetsHex: [
        TestData.CetHexUnsigned,
        "02000000019246862ea34db0833bd4bd9e657d61e2e5447d0438f6f6181d1cd329e8cf71c30000000000ffffffff02a0860100000000001600145dedfbf9ea599dd4e3ca6a80b333c472fd0b3f69603bea0b000000001600149652d86bedf43ad264362e6e6eba6eb76450812700000000",
      ],
      localFundPubkey: TestData.LocalFundPubkey,
      remoteFundPubkey: TestData.RemoteFundPubkey,
      fundTxId: TestData.FundTxId,
      fundInputAmount: TestData.FundInputAmount,
      adaptorPairs: [
        {
          signature: TestData.CetLocalAdaptorSignature,
          proof: TestData.CetLocalAdaptorProof,
        },
        {
          signature:
            "0181de460ae3c75d15d83ea40ecd0d28cc31c1807cfe021935b9cdb8ac8957e71485263b445847d2f4aa79eeaff06e8601478b4e2c0e206499472430dd82df9ae0",
          proof:
            "000b8d891be111325d965296dec76909f7ce815bd152263cb5112c0f37dcf05cf2f09cd7991eaf30278ee0547e4f22cb3596909c5478c9799c349566a5e1ff38c4c5ad442ba4c3631ada85e9a75cab100757b10bb8091f99e237661fbb8d6c76f9",
        },
      ],
      verifyRemote: false,
      messagesList: [
        { messages: [TestData.Messages[0]] },
        { messages: [TestData.Messages[1]] },
      ],
      oraclePubkey: TestData.OraclePubkey,
      oracleRValues: [TestData.OracleRPoint],
    },
    {
      valid: false,
    }
  ),
];

TestHelper.doTest("VerifyCetSignature", testCase);
