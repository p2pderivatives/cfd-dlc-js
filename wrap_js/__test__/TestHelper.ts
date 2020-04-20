import * as cfddlcjs from "../../index.js";
import { TestCase } from "./TestCase";
/**
 * @class Utility class for running unit tests.
 */
export class TestHelper {
  /**
   * @param {String} testDescribe describe test suite
   * @param {Array.<TestCase>} testCases array of test_case
   */
  static doTest<TRequest, TResponse>(
    testDescribe: string,
    testCases: TestCase<TRequest, TResponse>[]
  ) {
    // if testCases is not array, ends test
    if (!Array.isArray(testCases)) {
      return;
    }

    testCases.forEach((testCase) => {
      describe(testDescribe, () => {
        beforeEach(() => testCase.setupFunction());
        it(testCase.testCaseName, () => {
          const response = testCase.testFunction(testCase.testRequest);
          if (testCase.convertFunction !== null) {
            const received2 = testCase.convertFunction(response);
            expect(received2).toEqual(testCase.expected);
          } else {
            expect(response).toEqual(testCase.expected);
          }
        });
        afterEach(() => testCase.tearDownFunction());
      });
    });
  }

  /**
   * create test case for api
   *
   * @param {String} caseName
   * @param {Function} testFunction
   * @param {Array.<any>} args
   * @param {any} expected
   * @param {Function?} setupFunc
   * @param {Function?} teardownFunc
   * @param {Function?} convertFunc
   * @return {TestCase} instance of TestCase
   */
  public static createTestCase<TRequest, TResponse>(
    caseName: string,
    testFunction: (request: TRequest) => TResponse,
    request: TRequest,
    expected: TResponse | cfddlcjs.ErrorResponse,
    setupFunc: () => void | null = () => undefined,
    teardownFunc: () => void | null = () => undefined,
    convertFunc: () => void | null = null
  ): TestCase<TRequest, TResponse> {
    return new TestCase(
      caseName,
      testFunction,
      request,
      expected,
      setupFunc,
      teardownFunc,
      convertFunc
    );
  }

  static createIllegalArgumentError(message: string): cfddlcjs.ErrorResponse {
    const error = {
      error: {
        code: 1,
        type: "illegal_argument",
        message,
      },
    };
    return error;
  }
}

module.exports = TestHelper;
