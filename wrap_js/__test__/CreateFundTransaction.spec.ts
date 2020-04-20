import * as cfddlcjs from "../../index.js";
import TestHelper from "./TestHelper";
import * as TestData from "./data/TestData";

function GetRequest() {
  return {
    localPubkey: TestData.LocalFundPubkey,
    remotePubkey: TestData.RemoteFundPubkey,
    outputAmount: TestData.FundInputAmount,
    localInputs: TestData.LocalInputs,
    localChange: {
      amount: BigInt(4899999719),
      address: TestData.LocalChangeAddress,
    },
    remoteInputs: TestData.RemoteInputs,
    remoteChange: {
      amount: BigInt(4899999719),
      address: TestData.RemoteChangeAddress,
    },
    nLockTime: BigInt(0),
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
