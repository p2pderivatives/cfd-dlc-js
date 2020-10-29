import Amount from "./Amount";

export default class Payout {
  constructor(readonly local: Amount, readonly remote: Amount) {}
}
