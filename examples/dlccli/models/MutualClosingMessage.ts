import Outcome from "./Outcome";

export default class MutualClosingMessage {
  constructor(readonly outcome: Outcome, readonly signature: string) {}
}
