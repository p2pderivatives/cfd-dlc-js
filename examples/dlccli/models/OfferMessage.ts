import { Messages } from "../../.."
import Amount from "./Amount";
import OracleInfo from "./OracleInfo";
import PartyInputs from "./PartyInputs";
import Payout from "./Payout";

export default class OfferMessage {
  constructor(
    readonly contractId: string,
    readonly localCollateral: Amount,
    readonly remoteCollateral: Amount,
    readonly payouts: Payout[],
    readonly messagesList: Messages[],
    readonly oracleInfo: OracleInfo,
    readonly localPartyInputs: PartyInputs,
    readonly feeRate: number,
    readonly refundLockTime: number
  ) { }
}
