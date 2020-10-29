import * as cfddlcjs from "../../index.js";
import TestHelper from "./TestHelper";
import * as TestData from "./data/TestData";

const testCase = [
  TestHelper.createTestCase(
    "CreateCetAdaptorSignatures",
    cfddlcjs.CreateCetAdaptorSignatures,
    {
      cetsHex: [
        TestData.CetHexUnsigned,
        "0200000001e8b791f27c983a7d9b0ee9b010b12563911ced584d88eb105fcece8b0bd18cff0000000000ffffffff02a0860100000000001600145dedfbf9ea599dd4e3ca6a80b333c472fd0b3f69603bea0b000000001600149652d86bedf43ad264362e6e6eba6eb76450812700000000",
      ],
      privkey: TestData.LocalFundPrivkey,
      localFundPubkey: TestData.LocalFundPubkey,
      remoteFundPubkey: TestData.RemoteFundPubkey,
      fundTxId: TestData.FundTxId,
      fundVout: 0,
      fundInputAmount: TestData.FundInputAmount,
      oraclePubkey: TestData.OraclePubkey,
      oracleRValues: [TestData.OracleRPoint],
      messagesList: [
        { messages: [TestData.Messages[0]] },
        { messages: [TestData.Messages[1]] },
      ],
    },
    {
      adaptorPairs: [
        {
          signature: TestData.CetLocalAdaptorSignature,
          proof: TestData.CetLocalAdaptorProof,
        },
        {
          signature:
            "00852d3ca14daf7434320479d4cc7f4998f70831383d8d653c11fc3aec24b5d25a398420c18daf05047228c2fc1b9ee9ab3e4d41f73a6be9a887f822d69a01847d",
          proof:
            "01cb861e808da35791c390e5eacb749441a3d86009a6b29bad394c2b332a889f9d0618b52234b6d5296e2aba8c811c2a027e18a39ec7f609b25706e97cb1a5bca6b1722d81e78ed64956924a6f2df9edfce1ffb9767284a2293828feb26d6184c7",
        },
      ],
    }
  ),
  TestHelper.createTestCase(
    "CreateCetAdaptorSignatures Multiple Nonces",
    cfddlcjs.CreateCetAdaptorSignatures,
    {
      cetsHex: [
        TestData.CetHexUnsigned,
        "0200000001e8b791f27c983a7d9b0ee9b010b12563911ced584d88eb105fcece8b0bd18cff0000000000ffffffff02a0860100000000001600145dedfbf9ea599dd4e3ca6a80b333c472fd0b3f69603bea0b000000001600149652d86bedf43ad264362e6e6eba6eb76450812700000000",
      ],
      privkey: TestData.LocalFundPrivkey,
      localFundPubkey: TestData.LocalFundPubkey,
      remoteFundPubkey: TestData.RemoteFundPubkey,
      fundTxId: TestData.FundTxId,
      fundVout: 0,
      fundInputAmount: TestData.FundInputAmount,
      oraclePubkey: TestData.OraclePubkey,
      oracleRValues: [TestData.OracleRPoint],
      messagesList: [
        { messages: [TestData.Messages[0]] },
        { messages: [TestData.Messages[1]] },
      ],
    },
    {
      adaptorPairs: [
        {
          signature: TestData.CetLocalAdaptorSignature,
          proof: TestData.CetLocalAdaptorProof,
        },
        {
          signature:
            "00852d3ca14daf7434320479d4cc7f4998f70831383d8d653c11fc3aec24b5d25a398420c18daf05047228c2fc1b9ee9ab3e4d41f73a6be9a887f822d69a01847d",
          proof:
            "01cb861e808da35791c390e5eacb749441a3d86009a6b29bad394c2b332a889f9d0618b52234b6d5296e2aba8c811c2a027e18a39ec7f609b25706e97cb1a5bca6b1722d81e78ed64956924a6f2df9edfce1ffb9767284a2293828feb26d6184c7",
        },
      ],
    }
  ),
];

TestHelper.doTest("GetRawCetSignatures", testCase);
