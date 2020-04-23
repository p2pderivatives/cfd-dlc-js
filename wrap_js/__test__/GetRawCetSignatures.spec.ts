import * as cfddlcjs from "../../index.js";
import TestHelper from "./TestHelper";
import * as TestData from "./data/TestData";

const testCase = [
  TestHelper.createTestCase(
    "GetRawCetSignature",
    cfddlcjs.GetRawCetSignatures,
    {
      cetsHex: [
        TestData.CetHexUnsigned,
        "0200000000010164b0942d90b9b815f76548b207a2d8ee75fc250a233ab44c3e13e01cd4a5f1f40000000000feffffff021a87010000000000220020f2f30cbf414fd2049e779e9f72ef31c00fe183b5775956a0380a838bd1bc9033603bea0b000000001600149652d86bedf43ad264362e6e6eba6eb7645081270400473044022001e046a58606c9085ff19064b7721c3d8e2f80d5c69f91d384c20e08a9c6b4da02205fdca97989e486c62c98de4f7a6e24cd8b1bf7ba296f844a6e61193e9dc646b10147304402207b641cc41c185061e7e5b0d05fb0c7a2967a4d0cf7eed5e38dd6f8aa2550b1aa02203c0099c127df54b2adfc418e86469d11d127960c9a3ee2d659a39f7cf7d4cea8014752210279be667ef9dcbbac55a06295ce870b07029bfcdb2dce28d959f2815b16f817982102c6047f9441ed7d6d3045406e95c07cd85c778e4b8cef3ca7abac09b95c709ee552ae9cba1e5e",
      ],
      privkey: TestData.LocalFundPrivkey,
      localFundPubkey: TestData.LocalFundPubkey,
      remoteFundPubkey: TestData.RemoteFundPubkey,
      fundTxId: TestData.FundTxId,
      fundVout: 0,
      fundInputAmount: TestData.FundInputAmount,
    },
    {
      hex: [
        TestData.CetLocalRawSignature,
        "01e046a58606c9085ff19064b7721c3d8e2f80d5c69f91d384c20e08a9c6b4da5fdca97989e486c62c98de4f7a6e24cd8b1bf7ba296f844a6e61193e9dc646b1",
      ],
    }
  ),
];

TestHelper.doTest("GetRawCetSignatures", testCase);
