import PartyInputs from "./PartyInputs";

export default class AcceptMessage {
  constructor(
    readonly remotePartyInputs: PartyInputs,
    readonly cetSignatures: string[],
    readonly refundSignature: string
  ) {}
}
