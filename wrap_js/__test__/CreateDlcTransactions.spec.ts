import * as cfddlcjs from "../../index.js";
import * as CfdUtils from "../cfd_utils";
import TestHelper from "./TestHelper";
import * as TestData from "./data/TestData";

const testCase = [
  TestHelper.createTestCase(
    "CreateDlcTransactions",
    cfddlcjs.CreateDlcTransactions,
    {
      payouts: [
        {
          local: TestData.WinAmount,
          remote: TestData.LoseAmount,
        },
        {
          local: TestData.LoseAmount,
          remote: TestData.WinAmount,
        },
      ],
      localFundPubkey: TestData.LocalFundPubkey,
      remoteFundPubkey: TestData.RemoteFundPubkey,
      localInputAmount: TestData.LocalInputAmount,
      localCollateralAmount: TestData.LocalCollateralAmount,
      remoteInputAmount: TestData.RemoteInputAmount,
      remoteCollateralAmount: TestData.RemoteCollateralAmount,
      cetLockTime: 0,
      fundLockTime: 0,
      refundLocktime: 100,
      localInputs: [
        {
          txid: TestData.LocalInputs[0].txid,
          vout: TestData.LocalInputs[0].vout,
          maxWitnessLength: 108,
        },
      ],
      localChangeScriptPubkey: CfdUtils.GetAddressScript(
        TestData.LocalChangeAddress
      ),
      remoteInputs: [
        {
          txid: TestData.RemoteInputs[0].txid,
          vout: TestData.RemoteInputs[0].vout,
          maxWitnessLength: 108,
        },
      ],
      remoteChangeScriptPubkey: CfdUtils.GetAddressScript(
        TestData.RemoteChangeAddress
      ),
      feeRate: 1,
      localFinalScriptPubkey: CfdUtils.GetAddressScript(
        TestData.LocalFinalAddress
      ),
      remoteFinalScriptPubkey: CfdUtils.GetAddressScript(
        TestData.RemoteFinalAddress
      ),
    },
    {
      fundTxHex: TestData.FundTxHexUnsigned,
      cetsHex: [
        TestData.CetHexUnsigned,
        "02000000019246862ea34db0833bd4bd9e657d61e2e5447d0438f6f6181d1cd329e8cf71c30000000000ffffffff02a0860100000000001600145dedfbf9ea599dd4e3ca6a80b333c472fd0b3f69603bea0b000000001600149652d86bedf43ad264362e6e6eba6eb76450812700000000",
      ],
      refundTxHex: TestData.RefundTransactionUnsigned,
    }
  ),
];

TestHelper.doTest("CreateDlcTransactions", testCase);
