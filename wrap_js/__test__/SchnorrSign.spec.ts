import * as cfddlcjs from "../../index.js";
import TestHelper from "./TestHelper";
import * as TestData from "./data/TestData";

const testCase = [
  TestHelper.createTestCase(
    "SchnorrSign",
    cfddlcjs.SchnorrSign,
    {
      privkey:
        "0000000000000000000000000000000000000000000000000000000000000001",
      kValue:
        "0000000000000000000000000000000000000000000000000000000000000002",
      message: "test",
    },
    { hex: "c87469c34bf55925a07d38153e16730963bc4e027570c1723e7176201d492d6c" }
  ),
];

TestHelper.doTest("SchnorrSign", testCase);
