import * as cfddlcjs from "../../index.js";
import TestHelper from "./TestHelper";
import * as TestData from "./data/TestData";

function GetRequest(
  optionPremium = 0,
  optionDest = "",
  localChange = 4899999789,
  remoteChange = 4899999789
) {
  return {
    localPubkey: TestData.LocalFundPubkey,
    remotePubkey: TestData.RemoteFundPubkey,
    outputAmount: TestData.FundInputAmount,
    feeRate: 1,
    localInputs: TestData.LocalInputs,
    localChange: {
      amount: localChange,
      address: TestData.LocalChangeAddress,
    },
    remoteInputs: TestData.RemoteInputs,
    remoteChange: {
      amount: remoteChange,
      address: TestData.RemoteChangeAddress,
    },
    nLockTime: 0,
    optionPremium,
    optionDest,
  };
}

const testCase = [
  TestHelper.createTestCase(
    "CreateFundTransaction",
    cfddlcjs.CreateFundTransaction,
    GetRequest(),
    {
      hex: TestData.FundTxHexUnsigned,
    }
  ),
  TestHelper.createTestCase(
    "CreateFundTransactionWithPremium",
    cfddlcjs.CreateFundTransaction,
    GetRequest(
      100000,
      "bcrt1qxyzqgxhnnhwtp9m0n2m9ygqp7zt2lckwvxx4jq",
      4899899758,
      4899999789
    ),
    {
      hex: TestData.FundTxWithPremium,
    }
  ),
];

const errorCase = [
  TestHelper.createTestCase(
    "CreateFundTransaction invalid Pubkey",
    cfddlcjs.CreateFundTransaction,
    { ...GetRequest(), localPubkey: "" },
    TestHelper.createIllegalArgumentError("Invalid Pubkey data.")
  ),
  TestHelper.createTestCase(
    "CreateFundTransaction invalid hex string(3 chars)",
    cfddlcjs.CreateFundTransaction,
    { ...GetRequest(), localPubkey: "000" },
    TestHelper.createIllegalArgumentError("hex to byte convert error.")
  ),
];

TestHelper.doTest("CreateFundTransaction", testCase);
TestHelper.doTest("CreateFundTransaction ErrorCase", errorCase);
