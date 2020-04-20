import * as cfddlcjs from "../../index.js";
import { TestHelper } from "./TestHelper";
import * as TestData from "./data/TestData";

function GetRequest() {
  return {
    localPubkey: TestData.LocalFundPubkey,
    remotePubkey: TestData.RemoteFundPubkey,
    outputAmount: TestData.FundOutput,
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
      hex:
        "020000000001024f601442e48eec22ff3a907c5f5290c6a0d3d08fb869e46ebfbaa9226b6d26830000000000ffffffff98bbd477219a151a1daf5377b30e8c5f9fb574783943f33ac523ef072fa292bc0000000000ffffffff0338c3eb0b000000002200209b984c7bae3efddc3a3f0a20ff81bfe89ed1fe07ff13e562149ee654bed845dbe70f102401000000160014fa3629f3060b6c1a5a365c30bf66fa00f155cb9ee70f10240100000016001465d4d622585baf5151de860b1e7af58710f20da20247304402207108de1563ae311f8d4217e1c0c7463386c1a135be6af88cbe8d89a3a08d65090220195a2b0140fb9ba83f20cf45ad6ea088bb0c6860c0d4995f1cf1353739ca65a90121022f8bde4d1a07209355b4a7250a5c5128e88b84bddc619ab7cba8d569b240efe4024730440220048716eaee918aebcb1bfcfaf7564e78293a7bb0164d9a7844e42fceb5ae393c022022817d033c9db19c5bdcadd49b7587a810b6fc2264158a59665aba8ab298455b012103fff97bd5755eeea420453a14355235d382f6472f8568a18b2f057a146029755600000000",
    }
  ),
];

const errorCase = [
  TestHelper.createTestCase(
    "CreateFundTransaction empty hex string",
    cfddlcjs.CreateFundTransaction,
    { localPubkey: "", ...GetRequest() },
    TestHelper.createIllegalArgumentError("Invalid hex string. empty txHex.")
  ),
  TestHelper.createTestCase(
    "CreateFundTransaction invalid hex string(3 chars)",
    cfddlcjs.CreateFundTransaction,
    { localPubkey: "000", ...GetRequest() },
    TestHelper.createIllegalArgumentError("hex to byte convert error.")
  ),
];

TestHelper.doTest("AddMultisigSign", testCase);
TestHelper.doTest("AddMultisigSign ErrorCase", errorCase);
