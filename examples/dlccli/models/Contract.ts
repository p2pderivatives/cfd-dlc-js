import Outcome from "./Outcome";
import PartyInputs from "./PartyInputs";
import OracleInfo from "./OracleInfo";
import OfferMessage from "./OfferMessage";
import AcceptMessage from "./AcceptMessage";
import SignMessage from "./SignMessage";
import Amount from "./Amount";

export default class Contract {
  id: string;
  localCollateral: Amount;
  remoteCollateral: Amount;
  outcomes: Outcome[];
  maturityTime: Date;
  feeRate: number;
  localPartyInputs: PartyInputs;
  remotePartyInputs: PartyInputs;
  oracleInfo: OracleInfo;
  cetCsvDelay: number;
  refundLockTime: number;
  isLocalParty: boolean;
  fundTxHex: string;
  fundTxId: string;
  fundTxOutAmount: Amount;
  fundTxSignatures: string[];
  refundTransaction: string;
  refundLocalSignature: string;
  refundRemoteSignature: string;
  localCetsHex: string[];
  remoteCetsHex: string[];
  cetSignatures: string[];

  constructor() {
    this.outcomes = [];
  }

  public static FromOfferMessage(offerMessage: OfferMessage) {
    const contract = new Contract();
    contract.id = offerMessage.contractId;
    contract.localCollateral = offerMessage.localCollateral;
    contract.remoteCollateral = offerMessage.remoteCollateral;
    contract.maturityTime = offerMessage.maturityTime;
    contract.outcomes = offerMessage.outcomes;
    contract.oracleInfo = offerMessage.oracleInfo;
    contract.localPartyInputs = offerMessage.localPartyInputs;
    contract.feeRate = offerMessage.feeRate;
    contract.cetCsvDelay = offerMessage.cetCsvDelay;
    contract.refundLockTime = offerMessage.refundLockTime;
    contract.isLocalParty = false;
    return contract;
  }

  public GetOfferMessage(): OfferMessage {
    this.isLocalParty = true;
    return {
      contractId: this.id,
      localCollateral: this.localCollateral,
      remoteCollateral: this.remoteCollateral,
      maturityTime: this.maturityTime,
      outcomes: this.outcomes,
      oracleInfo: this.oracleInfo,
      localPartyInputs: this.localPartyInputs,
      feeRate: this.feeRate,
      cetCsvDelay: this.cetCsvDelay,
      refundLockTime: this.refundLockTime,
    };
  }

  public ApplyAcceptMessage(acceptMessage: AcceptMessage) {
    this.cetSignatures = acceptMessage.cetSignatures;
    this.refundRemoteSignature = acceptMessage.refundSignature;
    this.remotePartyInputs = acceptMessage.remotePartyInputs;
  }

  public ApplySignMessage(signMessage: SignMessage) {
    this.cetSignatures = signMessage.cetSignatures;
    this.refundLocalSignature = signMessage.refundSignature;
    this.fundTxSignatures = signMessage.fundTxSignatures;
  }
}
