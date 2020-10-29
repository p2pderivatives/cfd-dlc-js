import { AdaptorPair } from "../../..";

export default class SignMessage {
  constructor(
    readonly fundTxSignatures: string[],
    readonly cetAdaptorPairs: AdaptorPair[],
    readonly refundSignature: string,
    readonly utxoPublicKeys: string[]
  ) {}
}
