import * as cfddlcjs from "../../index.js";
import TestHelper from "./TestHelper";
import * as TestData from "./data/TestData";

const testCase = [
  TestHelper.createTestCase(
    "GetSchnorrPublicNonce 1",
    cfddlcjs.GetSchnorrPublicNonce,
    {
      kValue:
        "0000000000000000000000000000000000000000000000000000000000000002",
    },
    {
      hex: "02c6047f9441ed7d6d3045406e95c07cd85c778e4b8cef3ca7abac09b95c709ee5",
    }
  ),
  TestHelper.createTestCase(
    "GetSchnorrPublicNonce 2",
    cfddlcjs.GetSchnorrPublicNonce,
    {
      kValue:
        "0000000000000000000000000000000000000000000000000000000000000003",
    },
    {
      hex: "03f9308a019258c31049344f85f89d5229b531c845836f99b08601f113bce036f9",
    }
  ),
];

TestHelper.doTest("SchnorrSign", testCase);
