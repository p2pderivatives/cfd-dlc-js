import Utxo from "./Utxo";

export default class PartyInputs {
  constructor(
    readonly fundPublicKey: string,
    readonly sweepPublicKey: string,
    readonly changeAddress: string,
    readonly finalAddress: string,
    readonly utxos: Utxo[]
  ) {}

  public GetTotalInputAmount() {
    return this.utxos.reduce<number>(
      (prev, cur) => prev + cur.amount.GetSatoshiAmount(),
      0
    );
  }
}
