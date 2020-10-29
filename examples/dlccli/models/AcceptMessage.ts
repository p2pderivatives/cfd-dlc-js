import { AdaptorPair } from "../../..";
import PartyInputs from "./PartyInputs";

export default class AcceptMessage {
  constructor(
    readonly remotePartyInputs: PartyInputs,
    readonly cetAdaptorPairs: AdaptorPair[],
    readonly refundSignature: string
  ) {}
}
