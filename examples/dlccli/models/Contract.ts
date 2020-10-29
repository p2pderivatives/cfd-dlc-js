import { AdaptorPair } from "../../..";
import AcceptMessage from "./AcceptMessage";
import Amount from "./Amount";
import OfferMessage from "./OfferMessage";
import OracleInfo from "./OracleInfo";
import PartyInputs from "./PartyInputs";
import Payout from "./Payout";
import SignMessage from "./SignMessage";

export default class Contract {
  id: string;
  localCollateral: Amount;
  remoteCollateral: Amount;
  payouts: Payout[];
  messages: string[];
  feeRate: number;
  localPartyInputs: PartyInputs;
  remotePartyInputs: PartyInputs;
  oracleInfo: OracleInfo;
  refundLockTime: number;
  isLocalParty: boolean;
  fundTxHex: string;
  fundTxId: string;
  fundTxOutAmount: Amount;
  fundTxSignatures: string[];
  refundTransaction: string;
  refundLocalSignature: string;
  refundRemoteSignature: string;
  cetsHex: string[];
  cetAdaptorPairs: AdaptorPair[];

  constructor() {
    this.payouts = [];
    this.messages = [];
  }

  public static FromOfferMessage(offerMessage: OfferMessage) {
    const contract = new Contract();
    contract.id = offerMessage.contractId;
    contract.localCollateral = offerMessage.localCollateral;
    contract.remoteCollateral = offerMessage.remoteCollateral;
    contract.payouts = offerMessage.payouts;
    contract.oracleInfo = offerMessage.oracleInfo;
    contract.localPartyInputs = offerMessage.localPartyInputs;
    contract.feeRate = offerMessage.feeRate;
    contract.refundLockTime = offerMessage.refundLockTime;
    contract.isLocalParty = false;
    contract.messages = offerMessage.messages;
    return contract;
  }

  public GetOfferMessage(): OfferMessage {
    this.isLocalParty = true;
    return {
      contractId: this.id,
      localCollateral: this.localCollateral,
      remoteCollateral: this.remoteCollateral,
      payouts: this.payouts,
      oracleInfo: this.oracleInfo,
      localPartyInputs: this.localPartyInputs,
      feeRate: this.feeRate,
      refundLockTime: this.refundLockTime,
      messages: this.messages,
    };
  }

  public ApplyAcceptMessage(acceptMessage: AcceptMessage) {
    this.cetAdaptorPairs = acceptMessage.cetAdaptorPairs;
    this.refundRemoteSignature = acceptMessage.refundSignature;
    this.remotePartyInputs = acceptMessage.remotePartyInputs;
  }

  public ApplySignMessage(signMessage: SignMessage) {
    this.cetAdaptorPairs = signMessage.cetAdaptorPairs;
    this.refundLocalSignature = signMessage.refundSignature;
    this.fundTxSignatures = signMessage.fundTxSignatures;
  }
}
