import * as cfddlcjs from "../../index.js";
/**
 * Express one test case.
 * This class has only fields for test execution.
 */
export class TestCase<TRequest, TResponse> {
  testCaseName: string;
  testFunction: (req: TRequest) => TResponse;
  testRequest: TRequest;
  expected: TResponse | cfddlcjs.ErrorResponse;
  setupFunction: () => void;
  tearDownFunction: () => void;
  convertFunction: (arg: any) => any;

  /**
   * constructor
   *
   * @param {String} caseName
   * @param {Function} testFunction
   * @param {Array.<any>} args
   * @param {any} expected
   * @param {Function} setupFunc
   * @param {Function} teardownFunc
   * @param {Function} convertFunc
   */
  constructor(
    caseName,
    testFunction,
    testRequest,
    expected,
    setupFunc,
    teardownFunc,
    convertFunc
  ) {
    // eslint-disable-line max-len
    this.testCaseName = caseName;
    this.testFunction = testFunction;
    this.testRequest = testRequest;
    this.expected = expected;
    this.setupFunction = setupFunc;
    this.tearDownFunction = teardownFunc;
    this.convertFunction = convertFunc;
  }
}
