import Outcome from "./Outcome";
import OracleInfo from "./OracleInfo";
import PartyInputs from "./PartyInputs";
import Amount from "./Amount";

export default class OfferMessage {
  constructor(
    readonly contractId: string,
    readonly localCollateral: Amount,
    readonly remoteCollateral: Amount,
    readonly maturityTime: Date,
    readonly outcomes: Outcome[],
    readonly oracleInfo: OracleInfo,
    readonly localPartyInputs: PartyInputs,
    readonly feeRate: number,
    readonly cetCsvDelay: number,
    readonly refundLockTime: number
  ) {}
}
