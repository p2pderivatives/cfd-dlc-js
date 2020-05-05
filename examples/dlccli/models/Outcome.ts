import Amount from "./Amount";

export default class Outcome {
  constructor(
    readonly message: string,
    readonly local: Amount,
    readonly remote: Amount
  ) {}
}
