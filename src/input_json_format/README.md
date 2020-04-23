
- 説明
  - in/outをわかりやすく定義するため、request/responseとして定義
  - クラス名については、クラスの先頭で":class"フィールドとして定義する。
  - 数値型については、"フィールド名:type"のフィールドを定義し、値にデータ型の名称を設定する。
    - "フィールド名:type"："データ型"
    - 未指定時は int64_t となる。
  - 生成ファイルは、jsonファイル名＋"_json"で生成される。
```
{
  "namespace": ["cfd","api"],
  "export": "CFD_EXPORT",
  "common_header": "cfd/cfd_common.h",
  "request":
  {
    ":class":"CreateRawTransactionRequest",
    "version": 2,
    "version:type":"uint32_t",
    "locktime": 0,
    "locktime:type":"uint32_t",
    "txins": [{
      ":class": "TxInRequest",
      "txid": "",
      "vout": 0,
      "vout:type":"uint32_t",
      "data": "",
      "addr_type": "mainnet"
    }],
    "txouts": [{
      ":class": "TxOutRequest",
      "address": "",
      "amount": 0
    }],
  },
  "response":
  {
    ":class":"CreateRawTransactionResponse",
    "hex": ""
  }
}
```
