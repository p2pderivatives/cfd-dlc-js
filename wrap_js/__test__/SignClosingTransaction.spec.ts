import * as cfddlcjs from "../../index.js";
import TestHelper from "./TestHelper";
import * as TestData from "./data/TestData";

const testCase = [
  TestHelper.createTestCase(
    "SignClosingTransaction",
    cfddlcjs.SignClosingTransaction,
    {
      closingTxHex: TestData.ClosingTransactionUnsigned,
      localFundPrivkey: TestData.LocalFundPrivkey,
      localSweepPubkey: TestData.LocalSweepPubkey,
      remoteSweepPubkey: TestData.RemoteSweepPubkey,
      oraclePubkey: TestData.OraclePubkey,
      oracleRPoints: TestData.OracleRPoints,
      messages: TestData.WinMessages,
      delay: 100,
      oracleSigs: [TestData.OracleSignature],
      cetTxId: TestData.CetTxId,
      cetVout: 0,
      amount: TestData.WinAmount + 122,
    },
    {
      hex:
        "02000000000101d65cb677571e387cc1c22a26832dce5e77f978b1fc9f478a44e77428e15863b70000000000ffffffff017837ea0b000000001600145dedfbf9ea599dd4e3ca6a80b333c472fd0b3f690347304402207452592666a8465e86eb6e3766e534c79e6ce064a7648e9cce519454cf8f6ea10220123c46a022c2bb1f03e68826b45cfa7c7af07223c0b46f1e7c6c90d6b570fbc70101014c632102e07cca3429680d949f968ea585d3e04f5b536fc46a0caf90108328fd663a86de670164b2752102e493dbf1c10d80f3581e4904930b1404cc6c13900ee0758474fa94abe8c4cd1368ac00000000",
    }
  ),
];

TestHelper.doTest("SignClosingTransaction", testCase);
