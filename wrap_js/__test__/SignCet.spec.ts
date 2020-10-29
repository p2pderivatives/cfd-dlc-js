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
      oracleSignatures: [TestData.OracleSignature],
    },
    {
      hex: TestData.CetHexSigned,
    }
  ),
  TestHelper.createTestCase(
    "SignCet Multiple Nonces",
    cfddlcjs.SignCet,
    {
      cetHex:
        "02000000019246862ea34db0833bd4bd9e657d61e2e5447d0438f6f6181d1cd329e8cf71c30000000000ffffffff02603bea0b000000001600145dedfbf9ea599dd4e3ca6a80b333c472fd0b3f69a0860100000000001600149652d86bedf43ad264362e6e6eba6eb76450812700000000",
      localFundPubkey: TestData.LocalFundPubkey,
      remoteFundPubkey: TestData.RemoteFundPubkey,
      fundTxId: TestData.FundTxId,
      adaptorSignature:
        "00cc296470e546717aaa8f54832c17d06ef81f61fba359df514b37faaa0ce0d9d431e88837d1ecc2e18899b77fab4fe76e123c1d4adfe960ecd12bf0f2d8950991",
      fundPrivkey: TestData.RemoteFundPrivkey,
      fundInputAmount: TestData.FundInputAmount,
      oracleSignatures: [
        TestData.OracleSignature,
        "7fb1cbb510efe5eb03b5381dafbe82db8e751bb546a3e203aabe7ebbc9d441c435150376091aacc419061a44f431f123c0c089e6c443455f78d512b789049dc2",
      ],
    },
    {
      hex:
        "020000000001019246862ea34db0833bd4bd9e657d61e2e5447d0438f6f6181d1cd329e8cf71c30000000000ffffffff02603bea0b000000001600145dedfbf9ea599dd4e3ca6a80b333c472fd0b3f69a0860100000000001600149652d86bedf43ad264362e6e6eba6eb7645081270400483045022100cc296470e546717aaa8f54832c17d06ef81f61fba359df514b37faaa0ce0d9d40220036813b999126191c9afa52e27037aff1cf40937affa22eb601e29ea3aff899f01473044022036d971f3da54303facb5fbf8dc7e9eef452cd94723eb6dc52f7aeee454791a0002204cf335114c47bae5e6dc2e00f566d1e37ec6fe25350fe797d48bff2573eeb548014752210279be667ef9dcbbac55a06295ce870b07029bfcdb2dce28d959f2815b16f817982102c6047f9441ed7d6d3045406e95c07cd85c778e4b8cef3ca7abac09b95c709ee552ae00000000",
    }
  ),
];

TestHelper.doTest("AddSignaturesToCet", testCase);
