// Copyright 2020 CryptoGarage
/**
 * @file cfd_dlc_js_api_json_autogen.cpp
 *
 * @brief JSON mapping file (auto generate)
 */
#include <set>
#include <string>
#include <vector>

#include "cfd_dlc_js_api_json_autogen.h"  // NOLINT

namespace cfd {
namespace dlc {
namespace js {
namespace api {
namespace json {

using cfd::core::JsonClassBase;
using cfd::core::JsonObjectVector;
using cfd::core::JsonValueVector;
using cfd::core::JsonVector;
// clang-format off
// @formatter:off

// ------------------------------------------------------------------------
// Messages
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<Messages>
  Messages::json_mapper;
std::vector<std::string> Messages::item_list;

void Messages::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<Messages> func_table;  // NOLINT

  func_table = {
    Messages::GetMessagesString,
    Messages::SetMessagesString,
    Messages::GetMessagesFieldType,
  };
  json_mapper.emplace("messages", func_table);
  item_list.push_back("messages");
}

void Messages::ConvertFromStruct(
    const MessagesStruct& data) {
  messages_.ConvertFromStruct(data.messages);
  ignore_items = data.ignore_items;
}

MessagesStruct Messages::ConvertToStruct() const {  // NOLINT
  MessagesStruct result;
  result.messages = messages_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// TxInInfoRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<TxInInfoRequest>
  TxInInfoRequest::json_mapper;
std::vector<std::string> TxInInfoRequest::item_list;

void TxInInfoRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<TxInInfoRequest> func_table;  // NOLINT

  func_table = {
    TxInInfoRequest::GetTxidString,
    TxInInfoRequest::SetTxidString,
    TxInInfoRequest::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    TxInInfoRequest::GetVoutString,
    TxInInfoRequest::SetVoutString,
    TxInInfoRequest::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
  func_table = {
    TxInInfoRequest::GetRedeemScriptString,
    TxInInfoRequest::SetRedeemScriptString,
    TxInInfoRequest::GetRedeemScriptFieldType,
  };
  json_mapper.emplace("redeemScript", func_table);
  item_list.push_back("redeemScript");
  func_table = {
    TxInInfoRequest::GetMaxWitnessLengthString,
    TxInInfoRequest::SetMaxWitnessLengthString,
    TxInInfoRequest::GetMaxWitnessLengthFieldType,
  };
  json_mapper.emplace("maxWitnessLength", func_table);
  item_list.push_back("maxWitnessLength");
  func_table = {
    TxInInfoRequest::GetSerialIdString,
    TxInInfoRequest::SetSerialIdString,
    TxInInfoRequest::GetSerialIdFieldType,
  };
  json_mapper.emplace("serialId", func_table);
  item_list.push_back("serialId");
}

void TxInInfoRequest::ConvertFromStruct(
    const TxInInfoRequestStruct& data) {
  txid_ = data.txid;
  vout_ = data.vout;
  redeem_script_ = data.redeem_script;
  max_witness_length_ = data.max_witness_length;
  serial_id_ = data.serial_id;
  ignore_items = data.ignore_items;
}

TxInInfoRequestStruct TxInInfoRequest::ConvertToStruct() const {  // NOLINT
  TxInInfoRequestStruct result;
  result.txid = txid_;
  result.vout = vout_;
  result.redeem_script = redeem_script_;
  result.max_witness_length = max_witness_length_;
  result.serial_id = serial_id_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// AddSignatureToFundTransactionRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<AddSignatureToFundTransactionRequest>
  AddSignatureToFundTransactionRequest::json_mapper;
std::vector<std::string> AddSignatureToFundTransactionRequest::item_list;

void AddSignatureToFundTransactionRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<AddSignatureToFundTransactionRequest> func_table;  // NOLINT

  func_table = {
    AddSignatureToFundTransactionRequest::GetFundTxHexString,
    AddSignatureToFundTransactionRequest::SetFundTxHexString,
    AddSignatureToFundTransactionRequest::GetFundTxHexFieldType,
  };
  json_mapper.emplace("fundTxHex", func_table);
  item_list.push_back("fundTxHex");
  func_table = {
    AddSignatureToFundTransactionRequest::GetSignatureString,
    AddSignatureToFundTransactionRequest::SetSignatureString,
    AddSignatureToFundTransactionRequest::GetSignatureFieldType,
  };
  json_mapper.emplace("signature", func_table);
  item_list.push_back("signature");
  func_table = {
    AddSignatureToFundTransactionRequest::GetPrevTxIdString,
    AddSignatureToFundTransactionRequest::SetPrevTxIdString,
    AddSignatureToFundTransactionRequest::GetPrevTxIdFieldType,
  };
  json_mapper.emplace("prevTxId", func_table);
  item_list.push_back("prevTxId");
  func_table = {
    AddSignatureToFundTransactionRequest::GetPrevVoutString,
    AddSignatureToFundTransactionRequest::SetPrevVoutString,
    AddSignatureToFundTransactionRequest::GetPrevVoutFieldType,
  };
  json_mapper.emplace("prevVout", func_table);
  item_list.push_back("prevVout");
  func_table = {
    AddSignatureToFundTransactionRequest::GetPubkeyString,
    AddSignatureToFundTransactionRequest::SetPubkeyString,
    AddSignatureToFundTransactionRequest::GetPubkeyFieldType,
  };
  json_mapper.emplace("pubkey", func_table);
  item_list.push_back("pubkey");
}

void AddSignatureToFundTransactionRequest::ConvertFromStruct(
    const AddSignatureToFundTransactionRequestStruct& data) {
  fund_tx_hex_ = data.fund_tx_hex;
  signature_ = data.signature;
  prev_tx_id_ = data.prev_tx_id;
  prev_vout_ = data.prev_vout;
  pubkey_ = data.pubkey;
  ignore_items = data.ignore_items;
}

AddSignatureToFundTransactionRequestStruct AddSignatureToFundTransactionRequest::ConvertToStruct() const {  // NOLINT
  AddSignatureToFundTransactionRequestStruct result;
  result.fund_tx_hex = fund_tx_hex_;
  result.signature = signature_;
  result.prev_tx_id = prev_tx_id_;
  result.prev_vout = prev_vout_;
  result.pubkey = pubkey_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// AddSignatureToFundTransactionResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<AddSignatureToFundTransactionResponse>
  AddSignatureToFundTransactionResponse::json_mapper;
std::vector<std::string> AddSignatureToFundTransactionResponse::item_list;

void AddSignatureToFundTransactionResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<AddSignatureToFundTransactionResponse> func_table;  // NOLINT

  func_table = {
    AddSignatureToFundTransactionResponse::GetHexString,
    AddSignatureToFundTransactionResponse::SetHexString,
    AddSignatureToFundTransactionResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
}

void AddSignatureToFundTransactionResponse::ConvertFromStruct(
    const AddSignatureToFundTransactionResponseStruct& data) {
  hex_ = data.hex;
  ignore_items = data.ignore_items;
}

AddSignatureToFundTransactionResponseStruct AddSignatureToFundTransactionResponse::ConvertToStruct() const {  // NOLINT
  AddSignatureToFundTransactionResponseStruct result;
  result.hex = hex_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// AddSignaturesToRefundTxRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<AddSignaturesToRefundTxRequest>
  AddSignaturesToRefundTxRequest::json_mapper;
std::vector<std::string> AddSignaturesToRefundTxRequest::item_list;

void AddSignaturesToRefundTxRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<AddSignaturesToRefundTxRequest> func_table;  // NOLINT

  func_table = {
    AddSignaturesToRefundTxRequest::GetRefundTxHexString,
    AddSignaturesToRefundTxRequest::SetRefundTxHexString,
    AddSignaturesToRefundTxRequest::GetRefundTxHexFieldType,
  };
  json_mapper.emplace("refundTxHex", func_table);
  item_list.push_back("refundTxHex");
  func_table = {
    AddSignaturesToRefundTxRequest::GetSignaturesString,
    AddSignaturesToRefundTxRequest::SetSignaturesString,
    AddSignaturesToRefundTxRequest::GetSignaturesFieldType,
  };
  json_mapper.emplace("signatures", func_table);
  item_list.push_back("signatures");
  func_table = {
    AddSignaturesToRefundTxRequest::GetFundTxIdString,
    AddSignaturesToRefundTxRequest::SetFundTxIdString,
    AddSignaturesToRefundTxRequest::GetFundTxIdFieldType,
  };
  json_mapper.emplace("fundTxId", func_table);
  item_list.push_back("fundTxId");
  func_table = {
    AddSignaturesToRefundTxRequest::GetFundVoutString,
    AddSignaturesToRefundTxRequest::SetFundVoutString,
    AddSignaturesToRefundTxRequest::GetFundVoutFieldType,
  };
  json_mapper.emplace("fundVout", func_table);
  item_list.push_back("fundVout");
  func_table = {
    AddSignaturesToRefundTxRequest::GetOfferFundPubkeyString,
    AddSignaturesToRefundTxRequest::SetOfferFundPubkeyString,
    AddSignaturesToRefundTxRequest::GetOfferFundPubkeyFieldType,
  };
  json_mapper.emplace("offerFundPubkey", func_table);
  item_list.push_back("offerFundPubkey");
  func_table = {
    AddSignaturesToRefundTxRequest::GetAcceptFundPubkeyString,
    AddSignaturesToRefundTxRequest::SetAcceptFundPubkeyString,
    AddSignaturesToRefundTxRequest::GetAcceptFundPubkeyFieldType,
  };
  json_mapper.emplace("acceptFundPubkey", func_table);
  item_list.push_back("acceptFundPubkey");
}

void AddSignaturesToRefundTxRequest::ConvertFromStruct(
    const AddSignaturesToRefundTxRequestStruct& data) {
  refund_tx_hex_ = data.refund_tx_hex;
  signatures_.ConvertFromStruct(data.signatures);
  fund_tx_id_ = data.fund_tx_id;
  fund_vout_ = data.fund_vout;
  offer_fund_pubkey_ = data.offer_fund_pubkey;
  accept_fund_pubkey_ = data.accept_fund_pubkey;
  ignore_items = data.ignore_items;
}

AddSignaturesToRefundTxRequestStruct AddSignaturesToRefundTxRequest::ConvertToStruct() const {  // NOLINT
  AddSignaturesToRefundTxRequestStruct result;
  result.refund_tx_hex = refund_tx_hex_;
  result.signatures = signatures_.ConvertToStruct();
  result.fund_tx_id = fund_tx_id_;
  result.fund_vout = fund_vout_;
  result.offer_fund_pubkey = offer_fund_pubkey_;
  result.accept_fund_pubkey = accept_fund_pubkey_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// AddSignaturesToRefundTxResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<AddSignaturesToRefundTxResponse>
  AddSignaturesToRefundTxResponse::json_mapper;
std::vector<std::string> AddSignaturesToRefundTxResponse::item_list;

void AddSignaturesToRefundTxResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<AddSignaturesToRefundTxResponse> func_table;  // NOLINT

  func_table = {
    AddSignaturesToRefundTxResponse::GetHexString,
    AddSignaturesToRefundTxResponse::SetHexString,
    AddSignaturesToRefundTxResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
}

void AddSignaturesToRefundTxResponse::ConvertFromStruct(
    const AddSignaturesToRefundTxResponseStruct& data) {
  hex_ = data.hex;
  ignore_items = data.ignore_items;
}

AddSignaturesToRefundTxResponseStruct AddSignaturesToRefundTxResponse::ConvertToStruct() const {  // NOLINT
  AddSignaturesToRefundTxResponseStruct result;
  result.hex = hex_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateCetRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateCetRequest>
  CreateCetRequest::json_mapper;
std::vector<std::string> CreateCetRequest::item_list;

void CreateCetRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateCetRequest> func_table;  // NOLINT

  func_table = {
    CreateCetRequest::GetOfferFundPubkeyString,
    CreateCetRequest::SetOfferFundPubkeyString,
    CreateCetRequest::GetOfferFundPubkeyFieldType,
  };
  json_mapper.emplace("offerFundPubkey", func_table);
  item_list.push_back("offerFundPubkey");
  func_table = {
    CreateCetRequest::GetAcceptFundPubkeyString,
    CreateCetRequest::SetAcceptFundPubkeyString,
    CreateCetRequest::GetAcceptFundPubkeyFieldType,
  };
  json_mapper.emplace("acceptFundPubkey", func_table);
  item_list.push_back("acceptFundPubkey");
  func_table = {
    CreateCetRequest::GetOfferFinalAddressString,
    CreateCetRequest::SetOfferFinalAddressString,
    CreateCetRequest::GetOfferFinalAddressFieldType,
  };
  json_mapper.emplace("offerFinalAddress", func_table);
  item_list.push_back("offerFinalAddress");
  func_table = {
    CreateCetRequest::GetAcceptFinalAddressString,
    CreateCetRequest::SetAcceptFinalAddressString,
    CreateCetRequest::GetAcceptFinalAddressFieldType,
  };
  json_mapper.emplace("acceptFinalAddress", func_table);
  item_list.push_back("acceptFinalAddress");
  func_table = {
    CreateCetRequest::GetOfferPayoutString,
    CreateCetRequest::SetOfferPayoutString,
    CreateCetRequest::GetOfferPayoutFieldType,
  };
  json_mapper.emplace("offerPayout", func_table);
  item_list.push_back("offerPayout");
  func_table = {
    CreateCetRequest::GetAcceptPayoutString,
    CreateCetRequest::SetAcceptPayoutString,
    CreateCetRequest::GetAcceptPayoutFieldType,
  };
  json_mapper.emplace("acceptPayout", func_table);
  item_list.push_back("acceptPayout");
  func_table = {
    CreateCetRequest::GetOfferPayoutSerialIdString,
    CreateCetRequest::SetOfferPayoutSerialIdString,
    CreateCetRequest::GetOfferPayoutSerialIdFieldType,
  };
  json_mapper.emplace("offerPayoutSerialId", func_table);
  item_list.push_back("offerPayoutSerialId");
  func_table = {
    CreateCetRequest::GetAcceptPayoutSerialIdString,
    CreateCetRequest::SetAcceptPayoutSerialIdString,
    CreateCetRequest::GetAcceptPayoutSerialIdFieldType,
  };
  json_mapper.emplace("acceptPayoutSerialId", func_table);
  item_list.push_back("acceptPayoutSerialId");
  func_table = {
    CreateCetRequest::GetFundTxIdString,
    CreateCetRequest::SetFundTxIdString,
    CreateCetRequest::GetFundTxIdFieldType,
  };
  json_mapper.emplace("fundTxId", func_table);
  item_list.push_back("fundTxId");
  func_table = {
    CreateCetRequest::GetFundVoutString,
    CreateCetRequest::SetFundVoutString,
    CreateCetRequest::GetFundVoutFieldType,
  };
  json_mapper.emplace("fundVout", func_table);
  item_list.push_back("fundVout");
  func_table = {
    CreateCetRequest::GetLockTimeString,
    CreateCetRequest::SetLockTimeString,
    CreateCetRequest::GetLockTimeFieldType,
  };
  json_mapper.emplace("lockTime", func_table);
  item_list.push_back("lockTime");
}

void CreateCetRequest::ConvertFromStruct(
    const CreateCetRequestStruct& data) {
  offer_fund_pubkey_ = data.offer_fund_pubkey;
  accept_fund_pubkey_ = data.accept_fund_pubkey;
  offer_final_address_ = data.offer_final_address;
  accept_final_address_ = data.accept_final_address;
  offer_payout_ = data.offer_payout;
  accept_payout_ = data.accept_payout;
  offer_payout_serial_id_ = data.offer_payout_serial_id;
  accept_payout_serial_id_ = data.accept_payout_serial_id;
  fund_tx_id_ = data.fund_tx_id;
  fund_vout_ = data.fund_vout;
  lock_time_ = data.lock_time;
  ignore_items = data.ignore_items;
}

CreateCetRequestStruct CreateCetRequest::ConvertToStruct() const {  // NOLINT
  CreateCetRequestStruct result;
  result.offer_fund_pubkey = offer_fund_pubkey_;
  result.accept_fund_pubkey = accept_fund_pubkey_;
  result.offer_final_address = offer_final_address_;
  result.accept_final_address = accept_final_address_;
  result.offer_payout = offer_payout_;
  result.accept_payout = accept_payout_;
  result.offer_payout_serial_id = offer_payout_serial_id_;
  result.accept_payout_serial_id = accept_payout_serial_id_;
  result.fund_tx_id = fund_tx_id_;
  result.fund_vout = fund_vout_;
  result.lock_time = lock_time_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateCetResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateCetResponse>
  CreateCetResponse::json_mapper;
std::vector<std::string> CreateCetResponse::item_list;

void CreateCetResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateCetResponse> func_table;  // NOLINT

  func_table = {
    CreateCetResponse::GetHexString,
    CreateCetResponse::SetHexString,
    CreateCetResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
}

void CreateCetResponse::ConvertFromStruct(
    const CreateCetResponseStruct& data) {
  hex_ = data.hex;
  ignore_items = data.ignore_items;
}

CreateCetResponseStruct CreateCetResponse::ConvertToStruct() const {  // NOLINT
  CreateCetResponseStruct result;
  result.hex = hex_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateCetAdaptorSignatureRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateCetAdaptorSignatureRequest>
  CreateCetAdaptorSignatureRequest::json_mapper;
std::vector<std::string> CreateCetAdaptorSignatureRequest::item_list;

void CreateCetAdaptorSignatureRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateCetAdaptorSignatureRequest> func_table;  // NOLINT

  func_table = {
    CreateCetAdaptorSignatureRequest::GetCetHexString,
    CreateCetAdaptorSignatureRequest::SetCetHexString,
    CreateCetAdaptorSignatureRequest::GetCetHexFieldType,
  };
  json_mapper.emplace("cetHex", func_table);
  item_list.push_back("cetHex");
  func_table = {
    CreateCetAdaptorSignatureRequest::GetPrivkeyString,
    CreateCetAdaptorSignatureRequest::SetPrivkeyString,
    CreateCetAdaptorSignatureRequest::GetPrivkeyFieldType,
  };
  json_mapper.emplace("privkey", func_table);
  item_list.push_back("privkey");
  func_table = {
    CreateCetAdaptorSignatureRequest::GetFundTxIdString,
    CreateCetAdaptorSignatureRequest::SetFundTxIdString,
    CreateCetAdaptorSignatureRequest::GetFundTxIdFieldType,
  };
  json_mapper.emplace("fundTxId", func_table);
  item_list.push_back("fundTxId");
  func_table = {
    CreateCetAdaptorSignatureRequest::GetFundVoutString,
    CreateCetAdaptorSignatureRequest::SetFundVoutString,
    CreateCetAdaptorSignatureRequest::GetFundVoutFieldType,
  };
  json_mapper.emplace("fundVout", func_table);
  item_list.push_back("fundVout");
  func_table = {
    CreateCetAdaptorSignatureRequest::GetOfferFundPubkeyString,
    CreateCetAdaptorSignatureRequest::SetOfferFundPubkeyString,
    CreateCetAdaptorSignatureRequest::GetOfferFundPubkeyFieldType,
  };
  json_mapper.emplace("offerFundPubkey", func_table);
  item_list.push_back("offerFundPubkey");
  func_table = {
    CreateCetAdaptorSignatureRequest::GetAcceptFundPubkeyString,
    CreateCetAdaptorSignatureRequest::SetAcceptFundPubkeyString,
    CreateCetAdaptorSignatureRequest::GetAcceptFundPubkeyFieldType,
  };
  json_mapper.emplace("acceptFundPubkey", func_table);
  item_list.push_back("acceptFundPubkey");
  func_table = {
    CreateCetAdaptorSignatureRequest::GetOraclePubkeyString,
    CreateCetAdaptorSignatureRequest::SetOraclePubkeyString,
    CreateCetAdaptorSignatureRequest::GetOraclePubkeyFieldType,
  };
  json_mapper.emplace("oraclePubkey", func_table);
  item_list.push_back("oraclePubkey");
  func_table = {
    CreateCetAdaptorSignatureRequest::GetOracleRValuesString,
    CreateCetAdaptorSignatureRequest::SetOracleRValuesString,
    CreateCetAdaptorSignatureRequest::GetOracleRValuesFieldType,
  };
  json_mapper.emplace("oracleRValues", func_table);
  item_list.push_back("oracleRValues");
  func_table = {
    CreateCetAdaptorSignatureRequest::GetFundInputAmountString,
    CreateCetAdaptorSignatureRequest::SetFundInputAmountString,
    CreateCetAdaptorSignatureRequest::GetFundInputAmountFieldType,
  };
  json_mapper.emplace("fundInputAmount", func_table);
  item_list.push_back("fundInputAmount");
  func_table = {
    CreateCetAdaptorSignatureRequest::GetMessagesString,
    CreateCetAdaptorSignatureRequest::SetMessagesString,
    CreateCetAdaptorSignatureRequest::GetMessagesFieldType,
  };
  json_mapper.emplace("messages", func_table);
  item_list.push_back("messages");
}

void CreateCetAdaptorSignatureRequest::ConvertFromStruct(
    const CreateCetAdaptorSignatureRequestStruct& data) {
  cet_hex_ = data.cet_hex;
  privkey_ = data.privkey;
  fund_tx_id_ = data.fund_tx_id;
  fund_vout_ = data.fund_vout;
  offer_fund_pubkey_ = data.offer_fund_pubkey;
  accept_fund_pubkey_ = data.accept_fund_pubkey;
  oracle_pubkey_ = data.oracle_pubkey;
  oracle_r_values_.ConvertFromStruct(data.oracle_r_values);
  fund_input_amount_ = data.fund_input_amount;
  messages_.ConvertFromStruct(data.messages);
  ignore_items = data.ignore_items;
}

CreateCetAdaptorSignatureRequestStruct CreateCetAdaptorSignatureRequest::ConvertToStruct() const {  // NOLINT
  CreateCetAdaptorSignatureRequestStruct result;
  result.cet_hex = cet_hex_;
  result.privkey = privkey_;
  result.fund_tx_id = fund_tx_id_;
  result.fund_vout = fund_vout_;
  result.offer_fund_pubkey = offer_fund_pubkey_;
  result.accept_fund_pubkey = accept_fund_pubkey_;
  result.oracle_pubkey = oracle_pubkey_;
  result.oracle_r_values = oracle_r_values_.ConvertToStruct();
  result.fund_input_amount = fund_input_amount_;
  result.messages = messages_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateCetAdaptorSignatureResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateCetAdaptorSignatureResponse>
  CreateCetAdaptorSignatureResponse::json_mapper;
std::vector<std::string> CreateCetAdaptorSignatureResponse::item_list;

void CreateCetAdaptorSignatureResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateCetAdaptorSignatureResponse> func_table;  // NOLINT

  func_table = {
    CreateCetAdaptorSignatureResponse::GetSignatureString,
    CreateCetAdaptorSignatureResponse::SetSignatureString,
    CreateCetAdaptorSignatureResponse::GetSignatureFieldType,
  };
  json_mapper.emplace("signature", func_table);
  item_list.push_back("signature");
}

void CreateCetAdaptorSignatureResponse::ConvertFromStruct(
    const CreateCetAdaptorSignatureResponseStruct& data) {
  signature_ = data.signature;
  ignore_items = data.ignore_items;
}

CreateCetAdaptorSignatureResponseStruct CreateCetAdaptorSignatureResponse::ConvertToStruct() const {  // NOLINT
  CreateCetAdaptorSignatureResponseStruct result;
  result.signature = signature_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateCetAdaptorSignaturesRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateCetAdaptorSignaturesRequest>
  CreateCetAdaptorSignaturesRequest::json_mapper;
std::vector<std::string> CreateCetAdaptorSignaturesRequest::item_list;

void CreateCetAdaptorSignaturesRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateCetAdaptorSignaturesRequest> func_table;  // NOLINT

  func_table = {
    CreateCetAdaptorSignaturesRequest::GetCetsHexString,
    CreateCetAdaptorSignaturesRequest::SetCetsHexString,
    CreateCetAdaptorSignaturesRequest::GetCetsHexFieldType,
  };
  json_mapper.emplace("cetsHex", func_table);
  item_list.push_back("cetsHex");
  func_table = {
    CreateCetAdaptorSignaturesRequest::GetPrivkeyString,
    CreateCetAdaptorSignaturesRequest::SetPrivkeyString,
    CreateCetAdaptorSignaturesRequest::GetPrivkeyFieldType,
  };
  json_mapper.emplace("privkey", func_table);
  item_list.push_back("privkey");
  func_table = {
    CreateCetAdaptorSignaturesRequest::GetFundTxIdString,
    CreateCetAdaptorSignaturesRequest::SetFundTxIdString,
    CreateCetAdaptorSignaturesRequest::GetFundTxIdFieldType,
  };
  json_mapper.emplace("fundTxId", func_table);
  item_list.push_back("fundTxId");
  func_table = {
    CreateCetAdaptorSignaturesRequest::GetFundVoutString,
    CreateCetAdaptorSignaturesRequest::SetFundVoutString,
    CreateCetAdaptorSignaturesRequest::GetFundVoutFieldType,
  };
  json_mapper.emplace("fundVout", func_table);
  item_list.push_back("fundVout");
  func_table = {
    CreateCetAdaptorSignaturesRequest::GetOfferFundPubkeyString,
    CreateCetAdaptorSignaturesRequest::SetOfferFundPubkeyString,
    CreateCetAdaptorSignaturesRequest::GetOfferFundPubkeyFieldType,
  };
  json_mapper.emplace("offerFundPubkey", func_table);
  item_list.push_back("offerFundPubkey");
  func_table = {
    CreateCetAdaptorSignaturesRequest::GetAcceptFundPubkeyString,
    CreateCetAdaptorSignaturesRequest::SetAcceptFundPubkeyString,
    CreateCetAdaptorSignaturesRequest::GetAcceptFundPubkeyFieldType,
  };
  json_mapper.emplace("acceptFundPubkey", func_table);
  item_list.push_back("acceptFundPubkey");
  func_table = {
    CreateCetAdaptorSignaturesRequest::GetOraclePubkeyString,
    CreateCetAdaptorSignaturesRequest::SetOraclePubkeyString,
    CreateCetAdaptorSignaturesRequest::GetOraclePubkeyFieldType,
  };
  json_mapper.emplace("oraclePubkey", func_table);
  item_list.push_back("oraclePubkey");
  func_table = {
    CreateCetAdaptorSignaturesRequest::GetOracleRValuesString,
    CreateCetAdaptorSignaturesRequest::SetOracleRValuesString,
    CreateCetAdaptorSignaturesRequest::GetOracleRValuesFieldType,
  };
  json_mapper.emplace("oracleRValues", func_table);
  item_list.push_back("oracleRValues");
  func_table = {
    CreateCetAdaptorSignaturesRequest::GetFundInputAmountString,
    CreateCetAdaptorSignaturesRequest::SetFundInputAmountString,
    CreateCetAdaptorSignaturesRequest::GetFundInputAmountFieldType,
  };
  json_mapper.emplace("fundInputAmount", func_table);
  item_list.push_back("fundInputAmount");
  func_table = {
    CreateCetAdaptorSignaturesRequest::GetMessagesListString,
    CreateCetAdaptorSignaturesRequest::SetMessagesListString,
    CreateCetAdaptorSignaturesRequest::GetMessagesListFieldType,
  };
  json_mapper.emplace("messagesList", func_table);
  item_list.push_back("messagesList");
}

void CreateCetAdaptorSignaturesRequest::ConvertFromStruct(
    const CreateCetAdaptorSignaturesRequestStruct& data) {
  cets_hex_.ConvertFromStruct(data.cets_hex);
  privkey_ = data.privkey;
  fund_tx_id_ = data.fund_tx_id;
  fund_vout_ = data.fund_vout;
  offer_fund_pubkey_ = data.offer_fund_pubkey;
  accept_fund_pubkey_ = data.accept_fund_pubkey;
  oracle_pubkey_ = data.oracle_pubkey;
  oracle_r_values_.ConvertFromStruct(data.oracle_r_values);
  fund_input_amount_ = data.fund_input_amount;
  messages_list_.ConvertFromStruct(data.messages_list);
  ignore_items = data.ignore_items;
}

CreateCetAdaptorSignaturesRequestStruct CreateCetAdaptorSignaturesRequest::ConvertToStruct() const {  // NOLINT
  CreateCetAdaptorSignaturesRequestStruct result;
  result.cets_hex = cets_hex_.ConvertToStruct();
  result.privkey = privkey_;
  result.fund_tx_id = fund_tx_id_;
  result.fund_vout = fund_vout_;
  result.offer_fund_pubkey = offer_fund_pubkey_;
  result.accept_fund_pubkey = accept_fund_pubkey_;
  result.oracle_pubkey = oracle_pubkey_;
  result.oracle_r_values = oracle_r_values_.ConvertToStruct();
  result.fund_input_amount = fund_input_amount_;
  result.messages_list = messages_list_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateCetAdaptorSignaturesResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateCetAdaptorSignaturesResponse>
  CreateCetAdaptorSignaturesResponse::json_mapper;
std::vector<std::string> CreateCetAdaptorSignaturesResponse::item_list;

void CreateCetAdaptorSignaturesResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateCetAdaptorSignaturesResponse> func_table;  // NOLINT

  func_table = {
    CreateCetAdaptorSignaturesResponse::GetAdaptorSignaturesString,
    CreateCetAdaptorSignaturesResponse::SetAdaptorSignaturesString,
    CreateCetAdaptorSignaturesResponse::GetAdaptorSignaturesFieldType,
  };
  json_mapper.emplace("adaptorSignatures", func_table);
  item_list.push_back("adaptorSignatures");
}

void CreateCetAdaptorSignaturesResponse::ConvertFromStruct(
    const CreateCetAdaptorSignaturesResponseStruct& data) {
  adaptor_signatures_.ConvertFromStruct(data.adaptor_signatures);
  ignore_items = data.ignore_items;
}

CreateCetAdaptorSignaturesResponseStruct CreateCetAdaptorSignaturesResponse::ConvertToStruct() const {  // NOLINT
  CreateCetAdaptorSignaturesResponseStruct result;
  result.adaptor_signatures = adaptor_signatures_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// PayoutRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<PayoutRequest>
  PayoutRequest::json_mapper;
std::vector<std::string> PayoutRequest::item_list;

void PayoutRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<PayoutRequest> func_table;  // NOLINT

  func_table = {
    PayoutRequest::GetOfferString,
    PayoutRequest::SetOfferString,
    PayoutRequest::GetOfferFieldType,
  };
  json_mapper.emplace("offer", func_table);
  item_list.push_back("offer");
  func_table = {
    PayoutRequest::GetAcceptString,
    PayoutRequest::SetAcceptString,
    PayoutRequest::GetAcceptFieldType,
  };
  json_mapper.emplace("accept", func_table);
  item_list.push_back("accept");
}

void PayoutRequest::ConvertFromStruct(
    const PayoutRequestStruct& data) {
  offer_ = data.offer;
  accept_ = data.accept;
  ignore_items = data.ignore_items;
}

PayoutRequestStruct PayoutRequest::ConvertToStruct() const {  // NOLINT
  PayoutRequestStruct result;
  result.offer = offer_;
  result.accept = accept_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateDlcTransactionsRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateDlcTransactionsRequest>
  CreateDlcTransactionsRequest::json_mapper;
std::vector<std::string> CreateDlcTransactionsRequest::item_list;

void CreateDlcTransactionsRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateDlcTransactionsRequest> func_table;  // NOLINT

  func_table = {
    CreateDlcTransactionsRequest::GetPayoutsString,
    CreateDlcTransactionsRequest::SetPayoutsString,
    CreateDlcTransactionsRequest::GetPayoutsFieldType,
  };
  json_mapper.emplace("payouts", func_table);
  item_list.push_back("payouts");
  func_table = {
    CreateDlcTransactionsRequest::GetOfferFundPubkeyString,
    CreateDlcTransactionsRequest::SetOfferFundPubkeyString,
    CreateDlcTransactionsRequest::GetOfferFundPubkeyFieldType,
  };
  json_mapper.emplace("offerFundPubkey", func_table);
  item_list.push_back("offerFundPubkey");
  func_table = {
    CreateDlcTransactionsRequest::GetOfferPayoutScriptPubkeyString,
    CreateDlcTransactionsRequest::SetOfferPayoutScriptPubkeyString,
    CreateDlcTransactionsRequest::GetOfferPayoutScriptPubkeyFieldType,
  };
  json_mapper.emplace("offerPayoutScriptPubkey", func_table);
  item_list.push_back("offerPayoutScriptPubkey");
  func_table = {
    CreateDlcTransactionsRequest::GetOfferPayoutSerialIdString,
    CreateDlcTransactionsRequest::SetOfferPayoutSerialIdString,
    CreateDlcTransactionsRequest::GetOfferPayoutSerialIdFieldType,
  };
  json_mapper.emplace("offerPayoutSerialId", func_table);
  item_list.push_back("offerPayoutSerialId");
  func_table = {
    CreateDlcTransactionsRequest::GetAcceptFundPubkeyString,
    CreateDlcTransactionsRequest::SetAcceptFundPubkeyString,
    CreateDlcTransactionsRequest::GetAcceptFundPubkeyFieldType,
  };
  json_mapper.emplace("acceptFundPubkey", func_table);
  item_list.push_back("acceptFundPubkey");
  func_table = {
    CreateDlcTransactionsRequest::GetAcceptPayoutScriptPubkeyString,
    CreateDlcTransactionsRequest::SetAcceptPayoutScriptPubkeyString,
    CreateDlcTransactionsRequest::GetAcceptPayoutScriptPubkeyFieldType,
  };
  json_mapper.emplace("acceptPayoutScriptPubkey", func_table);
  item_list.push_back("acceptPayoutScriptPubkey");
  func_table = {
    CreateDlcTransactionsRequest::GetAcceptPayoutSerialIdString,
    CreateDlcTransactionsRequest::SetAcceptPayoutSerialIdString,
    CreateDlcTransactionsRequest::GetAcceptPayoutSerialIdFieldType,
  };
  json_mapper.emplace("acceptPayoutSerialId", func_table);
  item_list.push_back("acceptPayoutSerialId");
  func_table = {
    CreateDlcTransactionsRequest::GetOfferInputAmountString,
    CreateDlcTransactionsRequest::SetOfferInputAmountString,
    CreateDlcTransactionsRequest::GetOfferInputAmountFieldType,
  };
  json_mapper.emplace("offerInputAmount", func_table);
  item_list.push_back("offerInputAmount");
  func_table = {
    CreateDlcTransactionsRequest::GetOfferCollateralAmountString,
    CreateDlcTransactionsRequest::SetOfferCollateralAmountString,
    CreateDlcTransactionsRequest::GetOfferCollateralAmountFieldType,
  };
  json_mapper.emplace("offerCollateralAmount", func_table);
  item_list.push_back("offerCollateralAmount");
  func_table = {
    CreateDlcTransactionsRequest::GetAcceptInputAmountString,
    CreateDlcTransactionsRequest::SetAcceptInputAmountString,
    CreateDlcTransactionsRequest::GetAcceptInputAmountFieldType,
  };
  json_mapper.emplace("acceptInputAmount", func_table);
  item_list.push_back("acceptInputAmount");
  func_table = {
    CreateDlcTransactionsRequest::GetAcceptCollateralAmountString,
    CreateDlcTransactionsRequest::SetAcceptCollateralAmountString,
    CreateDlcTransactionsRequest::GetAcceptCollateralAmountFieldType,
  };
  json_mapper.emplace("acceptCollateralAmount", func_table);
  item_list.push_back("acceptCollateralAmount");
  func_table = {
    CreateDlcTransactionsRequest::GetRefundLocktimeString,
    CreateDlcTransactionsRequest::SetRefundLocktimeString,
    CreateDlcTransactionsRequest::GetRefundLocktimeFieldType,
  };
  json_mapper.emplace("refundLocktime", func_table);
  item_list.push_back("refundLocktime");
  func_table = {
    CreateDlcTransactionsRequest::GetOfferInputsString,
    CreateDlcTransactionsRequest::SetOfferInputsString,
    CreateDlcTransactionsRequest::GetOfferInputsFieldType,
  };
  json_mapper.emplace("offerInputs", func_table);
  item_list.push_back("offerInputs");
  func_table = {
    CreateDlcTransactionsRequest::GetOfferChangeScriptPubkeyString,
    CreateDlcTransactionsRequest::SetOfferChangeScriptPubkeyString,
    CreateDlcTransactionsRequest::GetOfferChangeScriptPubkeyFieldType,
  };
  json_mapper.emplace("offerChangeScriptPubkey", func_table);
  item_list.push_back("offerChangeScriptPubkey");
  func_table = {
    CreateDlcTransactionsRequest::GetOfferChangeSerialIdString,
    CreateDlcTransactionsRequest::SetOfferChangeSerialIdString,
    CreateDlcTransactionsRequest::GetOfferChangeSerialIdFieldType,
  };
  json_mapper.emplace("offerChangeSerialId", func_table);
  item_list.push_back("offerChangeSerialId");
  func_table = {
    CreateDlcTransactionsRequest::GetAcceptInputsString,
    CreateDlcTransactionsRequest::SetAcceptInputsString,
    CreateDlcTransactionsRequest::GetAcceptInputsFieldType,
  };
  json_mapper.emplace("acceptInputs", func_table);
  item_list.push_back("acceptInputs");
  func_table = {
    CreateDlcTransactionsRequest::GetAcceptChangeScriptPubkeyString,
    CreateDlcTransactionsRequest::SetAcceptChangeScriptPubkeyString,
    CreateDlcTransactionsRequest::GetAcceptChangeScriptPubkeyFieldType,
  };
  json_mapper.emplace("acceptChangeScriptPubkey", func_table);
  item_list.push_back("acceptChangeScriptPubkey");
  func_table = {
    CreateDlcTransactionsRequest::GetAcceptChangeSerialIdString,
    CreateDlcTransactionsRequest::SetAcceptChangeSerialIdString,
    CreateDlcTransactionsRequest::GetAcceptChangeSerialIdFieldType,
  };
  json_mapper.emplace("acceptChangeSerialId", func_table);
  item_list.push_back("acceptChangeSerialId");
  func_table = {
    CreateDlcTransactionsRequest::GetFeeRateString,
    CreateDlcTransactionsRequest::SetFeeRateString,
    CreateDlcTransactionsRequest::GetFeeRateFieldType,
  };
  json_mapper.emplace("feeRate", func_table);
  item_list.push_back("feeRate");
  func_table = {
    CreateDlcTransactionsRequest::GetFundOutputSerialIdString,
    CreateDlcTransactionsRequest::SetFundOutputSerialIdString,
    CreateDlcTransactionsRequest::GetFundOutputSerialIdFieldType,
  };
  json_mapper.emplace("fundOutputSerialId", func_table);
  item_list.push_back("fundOutputSerialId");
  func_table = {
    CreateDlcTransactionsRequest::GetCetLockTimeString,
    CreateDlcTransactionsRequest::SetCetLockTimeString,
    CreateDlcTransactionsRequest::GetCetLockTimeFieldType,
  };
  json_mapper.emplace("cetLockTime", func_table);
  item_list.push_back("cetLockTime");
  func_table = {
    CreateDlcTransactionsRequest::GetFundLockTimeString,
    CreateDlcTransactionsRequest::SetFundLockTimeString,
    CreateDlcTransactionsRequest::GetFundLockTimeFieldType,
  };
  json_mapper.emplace("fundLockTime", func_table);
  item_list.push_back("fundLockTime");
  func_table = {
    CreateDlcTransactionsRequest::GetOptionDestString,
    CreateDlcTransactionsRequest::SetOptionDestString,
    CreateDlcTransactionsRequest::GetOptionDestFieldType,
  };
  json_mapper.emplace("optionDest", func_table);
  item_list.push_back("optionDest");
  func_table = {
    CreateDlcTransactionsRequest::GetOptionPremiumString,
    CreateDlcTransactionsRequest::SetOptionPremiumString,
    CreateDlcTransactionsRequest::GetOptionPremiumFieldType,
  };
  json_mapper.emplace("optionPremium", func_table);
  item_list.push_back("optionPremium");
}

void CreateDlcTransactionsRequest::ConvertFromStruct(
    const CreateDlcTransactionsRequestStruct& data) {
  payouts_.ConvertFromStruct(data.payouts);
  offer_fund_pubkey_ = data.offer_fund_pubkey;
  offer_payout_script_pubkey_ = data.offer_payout_script_pubkey;
  offer_payout_serial_id_ = data.offer_payout_serial_id;
  accept_fund_pubkey_ = data.accept_fund_pubkey;
  accept_payout_script_pubkey_ = data.accept_payout_script_pubkey;
  accept_payout_serial_id_ = data.accept_payout_serial_id;
  offer_input_amount_ = data.offer_input_amount;
  offer_collateral_amount_ = data.offer_collateral_amount;
  accept_input_amount_ = data.accept_input_amount;
  accept_collateral_amount_ = data.accept_collateral_amount;
  refund_locktime_ = data.refund_locktime;
  offer_inputs_.ConvertFromStruct(data.offer_inputs);
  offer_change_script_pubkey_ = data.offer_change_script_pubkey;
  offer_change_serial_id_ = data.offer_change_serial_id;
  accept_inputs_.ConvertFromStruct(data.accept_inputs);
  accept_change_script_pubkey_ = data.accept_change_script_pubkey;
  accept_change_serial_id_ = data.accept_change_serial_id;
  fee_rate_ = data.fee_rate;
  fund_output_serial_id_ = data.fund_output_serial_id;
  cet_lock_time_ = data.cet_lock_time;
  fund_lock_time_ = data.fund_lock_time;
  option_dest_ = data.option_dest;
  option_premium_ = data.option_premium;
  ignore_items = data.ignore_items;
}

CreateDlcTransactionsRequestStruct CreateDlcTransactionsRequest::ConvertToStruct() const {  // NOLINT
  CreateDlcTransactionsRequestStruct result;
  result.payouts = payouts_.ConvertToStruct();
  result.offer_fund_pubkey = offer_fund_pubkey_;
  result.offer_payout_script_pubkey = offer_payout_script_pubkey_;
  result.offer_payout_serial_id = offer_payout_serial_id_;
  result.accept_fund_pubkey = accept_fund_pubkey_;
  result.accept_payout_script_pubkey = accept_payout_script_pubkey_;
  result.accept_payout_serial_id = accept_payout_serial_id_;
  result.offer_input_amount = offer_input_amount_;
  result.offer_collateral_amount = offer_collateral_amount_;
  result.accept_input_amount = accept_input_amount_;
  result.accept_collateral_amount = accept_collateral_amount_;
  result.refund_locktime = refund_locktime_;
  result.offer_inputs = offer_inputs_.ConvertToStruct();
  result.offer_change_script_pubkey = offer_change_script_pubkey_;
  result.offer_change_serial_id = offer_change_serial_id_;
  result.accept_inputs = accept_inputs_.ConvertToStruct();
  result.accept_change_script_pubkey = accept_change_script_pubkey_;
  result.accept_change_serial_id = accept_change_serial_id_;
  result.fee_rate = fee_rate_;
  result.fund_output_serial_id = fund_output_serial_id_;
  result.cet_lock_time = cet_lock_time_;
  result.fund_lock_time = fund_lock_time_;
  result.option_dest = option_dest_;
  result.option_premium = option_premium_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateDlcTransactionsResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateDlcTransactionsResponse>
  CreateDlcTransactionsResponse::json_mapper;
std::vector<std::string> CreateDlcTransactionsResponse::item_list;

void CreateDlcTransactionsResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateDlcTransactionsResponse> func_table;  // NOLINT

  func_table = {
    CreateDlcTransactionsResponse::GetFundTxHexString,
    CreateDlcTransactionsResponse::SetFundTxHexString,
    CreateDlcTransactionsResponse::GetFundTxHexFieldType,
  };
  json_mapper.emplace("fundTxHex", func_table);
  item_list.push_back("fundTxHex");
  func_table = {
    CreateDlcTransactionsResponse::GetCetsHexString,
    CreateDlcTransactionsResponse::SetCetsHexString,
    CreateDlcTransactionsResponse::GetCetsHexFieldType,
  };
  json_mapper.emplace("cetsHex", func_table);
  item_list.push_back("cetsHex");
  func_table = {
    CreateDlcTransactionsResponse::GetRefundTxHexString,
    CreateDlcTransactionsResponse::SetRefundTxHexString,
    CreateDlcTransactionsResponse::GetRefundTxHexFieldType,
  };
  json_mapper.emplace("refundTxHex", func_table);
  item_list.push_back("refundTxHex");
  func_table = {
    CreateDlcTransactionsResponse::GetFundingScriptPubkeyString,
    CreateDlcTransactionsResponse::SetFundingScriptPubkeyString,
    CreateDlcTransactionsResponse::GetFundingScriptPubkeyFieldType,
  };
  json_mapper.emplace("fundingScriptPubkey", func_table);
  item_list.push_back("fundingScriptPubkey");
  func_table = {
    CreateDlcTransactionsResponse::GetFundVoutString,
    CreateDlcTransactionsResponse::SetFundVoutString,
    CreateDlcTransactionsResponse::GetFundVoutFieldType,
  };
  json_mapper.emplace("fundVout", func_table);
  item_list.push_back("fundVout");
}

void CreateDlcTransactionsResponse::ConvertFromStruct(
    const CreateDlcTransactionsResponseStruct& data) {
  fund_tx_hex_ = data.fund_tx_hex;
  cets_hex_.ConvertFromStruct(data.cets_hex);
  refund_tx_hex_ = data.refund_tx_hex;
  funding_script_pubkey_ = data.funding_script_pubkey;
  fund_vout_ = data.fund_vout;
  ignore_items = data.ignore_items;
}

CreateDlcTransactionsResponseStruct CreateDlcTransactionsResponse::ConvertToStruct() const {  // NOLINT
  CreateDlcTransactionsResponseStruct result;
  result.fund_tx_hex = fund_tx_hex_;
  result.cets_hex = cets_hex_.ConvertToStruct();
  result.refund_tx_hex = refund_tx_hex_;
  result.funding_script_pubkey = funding_script_pubkey_;
  result.fund_vout = fund_vout_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateFundTransactionRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateFundTransactionRequest>
  CreateFundTransactionRequest::json_mapper;
std::vector<std::string> CreateFundTransactionRequest::item_list;

void CreateFundTransactionRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateFundTransactionRequest> func_table;  // NOLINT

  func_table = {
    CreateFundTransactionRequest::GetOfferPubkeyString,
    CreateFundTransactionRequest::SetOfferPubkeyString,
    CreateFundTransactionRequest::GetOfferPubkeyFieldType,
  };
  json_mapper.emplace("offerPubkey", func_table);
  item_list.push_back("offerPubkey");
  func_table = {
    CreateFundTransactionRequest::GetAcceptPubkeyString,
    CreateFundTransactionRequest::SetAcceptPubkeyString,
    CreateFundTransactionRequest::GetAcceptPubkeyFieldType,
  };
  json_mapper.emplace("acceptPubkey", func_table);
  item_list.push_back("acceptPubkey");
  func_table = {
    CreateFundTransactionRequest::GetOfferCollateralAmountString,
    CreateFundTransactionRequest::SetOfferCollateralAmountString,
    CreateFundTransactionRequest::GetOfferCollateralAmountFieldType,
  };
  json_mapper.emplace("offerCollateralAmount", func_table);
  item_list.push_back("offerCollateralAmount");
  func_table = {
    CreateFundTransactionRequest::GetAcceptCollateralAmountString,
    CreateFundTransactionRequest::SetAcceptCollateralAmountString,
    CreateFundTransactionRequest::GetAcceptCollateralAmountFieldType,
  };
  json_mapper.emplace("acceptCollateralAmount", func_table);
  item_list.push_back("acceptCollateralAmount");
  func_table = {
    CreateFundTransactionRequest::GetOfferInputsString,
    CreateFundTransactionRequest::SetOfferInputsString,
    CreateFundTransactionRequest::GetOfferInputsFieldType,
  };
  json_mapper.emplace("offerInputs", func_table);
  item_list.push_back("offerInputs");
  func_table = {
    CreateFundTransactionRequest::GetAcceptInputsString,
    CreateFundTransactionRequest::SetAcceptInputsString,
    CreateFundTransactionRequest::GetAcceptInputsFieldType,
  };
  json_mapper.emplace("acceptInputs", func_table);
  item_list.push_back("acceptInputs");
  func_table = {
    CreateFundTransactionRequest::GetOfferChangeScriptPubkeyString,
    CreateFundTransactionRequest::SetOfferChangeScriptPubkeyString,
    CreateFundTransactionRequest::GetOfferChangeScriptPubkeyFieldType,
  };
  json_mapper.emplace("offerChangeScriptPubkey", func_table);
  item_list.push_back("offerChangeScriptPubkey");
  func_table = {
    CreateFundTransactionRequest::GetOfferChangeSerialIdString,
    CreateFundTransactionRequest::SetOfferChangeSerialIdString,
    CreateFundTransactionRequest::GetOfferChangeSerialIdFieldType,
  };
  json_mapper.emplace("offerChangeSerialId", func_table);
  item_list.push_back("offerChangeSerialId");
  func_table = {
    CreateFundTransactionRequest::GetAcceptChangeScriptPubkeyString,
    CreateFundTransactionRequest::SetAcceptChangeScriptPubkeyString,
    CreateFundTransactionRequest::GetAcceptChangeScriptPubkeyFieldType,
  };
  json_mapper.emplace("acceptChangeScriptPubkey", func_table);
  item_list.push_back("acceptChangeScriptPubkey");
  func_table = {
    CreateFundTransactionRequest::GetAcceptChangeSerialIdString,
    CreateFundTransactionRequest::SetAcceptChangeSerialIdString,
    CreateFundTransactionRequest::GetAcceptChangeSerialIdFieldType,
  };
  json_mapper.emplace("acceptChangeSerialId", func_table);
  item_list.push_back("acceptChangeSerialId");
  func_table = {
    CreateFundTransactionRequest::GetOfferPayoutScriptPubkeyString,
    CreateFundTransactionRequest::SetOfferPayoutScriptPubkeyString,
    CreateFundTransactionRequest::GetOfferPayoutScriptPubkeyFieldType,
  };
  json_mapper.emplace("offerPayoutScriptPubkey", func_table);
  item_list.push_back("offerPayoutScriptPubkey");
  func_table = {
    CreateFundTransactionRequest::GetOfferPayoutSerialIdString,
    CreateFundTransactionRequest::SetOfferPayoutSerialIdString,
    CreateFundTransactionRequest::GetOfferPayoutSerialIdFieldType,
  };
  json_mapper.emplace("offerPayoutSerialId", func_table);
  item_list.push_back("offerPayoutSerialId");
  func_table = {
    CreateFundTransactionRequest::GetAcceptPayoutScriptPubkeyString,
    CreateFundTransactionRequest::SetAcceptPayoutScriptPubkeyString,
    CreateFundTransactionRequest::GetAcceptPayoutScriptPubkeyFieldType,
  };
  json_mapper.emplace("acceptPayoutScriptPubkey", func_table);
  item_list.push_back("acceptPayoutScriptPubkey");
  func_table = {
    CreateFundTransactionRequest::GetAcceptPayoutSerialIdString,
    CreateFundTransactionRequest::SetAcceptPayoutSerialIdString,
    CreateFundTransactionRequest::GetAcceptPayoutSerialIdFieldType,
  };
  json_mapper.emplace("acceptPayoutSerialId", func_table);
  item_list.push_back("acceptPayoutSerialId");
  func_table = {
    CreateFundTransactionRequest::GetFeeRateString,
    CreateFundTransactionRequest::SetFeeRateString,
    CreateFundTransactionRequest::GetFeeRateFieldType,
  };
  json_mapper.emplace("feeRate", func_table);
  item_list.push_back("feeRate");
  func_table = {
    CreateFundTransactionRequest::GetFundOutputSerialIdString,
    CreateFundTransactionRequest::SetFundOutputSerialIdString,
    CreateFundTransactionRequest::GetFundOutputSerialIdFieldType,
  };
  json_mapper.emplace("fundOutputSerialId", func_table);
  item_list.push_back("fundOutputSerialId");
  func_table = {
    CreateFundTransactionRequest::GetOptionDestString,
    CreateFundTransactionRequest::SetOptionDestString,
    CreateFundTransactionRequest::GetOptionDestFieldType,
  };
  json_mapper.emplace("optionDest", func_table);
  item_list.push_back("optionDest");
  func_table = {
    CreateFundTransactionRequest::GetOptionPremiumString,
    CreateFundTransactionRequest::SetOptionPremiumString,
    CreateFundTransactionRequest::GetOptionPremiumFieldType,
  };
  json_mapper.emplace("optionPremium", func_table);
  item_list.push_back("optionPremium");
}

void CreateFundTransactionRequest::ConvertFromStruct(
    const CreateFundTransactionRequestStruct& data) {
  offer_pubkey_ = data.offer_pubkey;
  accept_pubkey_ = data.accept_pubkey;
  offer_collateral_amount_ = data.offer_collateral_amount;
  accept_collateral_amount_ = data.accept_collateral_amount;
  offer_inputs_.ConvertFromStruct(data.offer_inputs);
  accept_inputs_.ConvertFromStruct(data.accept_inputs);
  offer_change_script_pubkey_ = data.offer_change_script_pubkey;
  offer_change_serial_id_ = data.offer_change_serial_id;
  accept_change_script_pubkey_ = data.accept_change_script_pubkey;
  accept_change_serial_id_ = data.accept_change_serial_id;
  offer_payout_script_pubkey_ = data.offer_payout_script_pubkey;
  offer_payout_serial_id_ = data.offer_payout_serial_id;
  accept_payout_script_pubkey_ = data.accept_payout_script_pubkey;
  accept_payout_serial_id_ = data.accept_payout_serial_id;
  fee_rate_ = data.fee_rate;
  fund_output_serial_id_ = data.fund_output_serial_id;
  option_dest_ = data.option_dest;
  option_premium_ = data.option_premium;
  ignore_items = data.ignore_items;
}

CreateFundTransactionRequestStruct CreateFundTransactionRequest::ConvertToStruct() const {  // NOLINT
  CreateFundTransactionRequestStruct result;
  result.offer_pubkey = offer_pubkey_;
  result.accept_pubkey = accept_pubkey_;
  result.offer_collateral_amount = offer_collateral_amount_;
  result.accept_collateral_amount = accept_collateral_amount_;
  result.offer_inputs = offer_inputs_.ConvertToStruct();
  result.accept_inputs = accept_inputs_.ConvertToStruct();
  result.offer_change_script_pubkey = offer_change_script_pubkey_;
  result.offer_change_serial_id = offer_change_serial_id_;
  result.accept_change_script_pubkey = accept_change_script_pubkey_;
  result.accept_change_serial_id = accept_change_serial_id_;
  result.offer_payout_script_pubkey = offer_payout_script_pubkey_;
  result.offer_payout_serial_id = offer_payout_serial_id_;
  result.accept_payout_script_pubkey = accept_payout_script_pubkey_;
  result.accept_payout_serial_id = accept_payout_serial_id_;
  result.fee_rate = fee_rate_;
  result.fund_output_serial_id = fund_output_serial_id_;
  result.option_dest = option_dest_;
  result.option_premium = option_premium_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateFundTransactionResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateFundTransactionResponse>
  CreateFundTransactionResponse::json_mapper;
std::vector<std::string> CreateFundTransactionResponse::item_list;

void CreateFundTransactionResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateFundTransactionResponse> func_table;  // NOLINT

  func_table = {
    CreateFundTransactionResponse::GetHexString,
    CreateFundTransactionResponse::SetHexString,
    CreateFundTransactionResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
}

void CreateFundTransactionResponse::ConvertFromStruct(
    const CreateFundTransactionResponseStruct& data) {
  hex_ = data.hex;
  ignore_items = data.ignore_items;
}

CreateFundTransactionResponseStruct CreateFundTransactionResponse::ConvertToStruct() const {  // NOLINT
  CreateFundTransactionResponseStruct result;
  result.hex = hex_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateRefundTransactionRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateRefundTransactionRequest>
  CreateRefundTransactionRequest::json_mapper;
std::vector<std::string> CreateRefundTransactionRequest::item_list;

void CreateRefundTransactionRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateRefundTransactionRequest> func_table;  // NOLINT

  func_table = {
    CreateRefundTransactionRequest::GetOfferFinalScriptPubkeyString,
    CreateRefundTransactionRequest::SetOfferFinalScriptPubkeyString,
    CreateRefundTransactionRequest::GetOfferFinalScriptPubkeyFieldType,
  };
  json_mapper.emplace("offerFinalScriptPubkey", func_table);
  item_list.push_back("offerFinalScriptPubkey");
  func_table = {
    CreateRefundTransactionRequest::GetAcceptFinalScriptPubkeyString,
    CreateRefundTransactionRequest::SetAcceptFinalScriptPubkeyString,
    CreateRefundTransactionRequest::GetAcceptFinalScriptPubkeyFieldType,
  };
  json_mapper.emplace("acceptFinalScriptPubkey", func_table);
  item_list.push_back("acceptFinalScriptPubkey");
  func_table = {
    CreateRefundTransactionRequest::GetOfferAmountString,
    CreateRefundTransactionRequest::SetOfferAmountString,
    CreateRefundTransactionRequest::GetOfferAmountFieldType,
  };
  json_mapper.emplace("offerAmount", func_table);
  item_list.push_back("offerAmount");
  func_table = {
    CreateRefundTransactionRequest::GetAcceptAmountString,
    CreateRefundTransactionRequest::SetAcceptAmountString,
    CreateRefundTransactionRequest::GetAcceptAmountFieldType,
  };
  json_mapper.emplace("acceptAmount", func_table);
  item_list.push_back("acceptAmount");
  func_table = {
    CreateRefundTransactionRequest::GetLockTimeString,
    CreateRefundTransactionRequest::SetLockTimeString,
    CreateRefundTransactionRequest::GetLockTimeFieldType,
  };
  json_mapper.emplace("lockTime", func_table);
  item_list.push_back("lockTime");
  func_table = {
    CreateRefundTransactionRequest::GetFundTxIdString,
    CreateRefundTransactionRequest::SetFundTxIdString,
    CreateRefundTransactionRequest::GetFundTxIdFieldType,
  };
  json_mapper.emplace("fundTxId", func_table);
  item_list.push_back("fundTxId");
  func_table = {
    CreateRefundTransactionRequest::GetFundVoutString,
    CreateRefundTransactionRequest::SetFundVoutString,
    CreateRefundTransactionRequest::GetFundVoutFieldType,
  };
  json_mapper.emplace("fundVout", func_table);
  item_list.push_back("fundVout");
}

void CreateRefundTransactionRequest::ConvertFromStruct(
    const CreateRefundTransactionRequestStruct& data) {
  offer_final_script_pubkey_ = data.offer_final_script_pubkey;
  accept_final_script_pubkey_ = data.accept_final_script_pubkey;
  offer_amount_ = data.offer_amount;
  accept_amount_ = data.accept_amount;
  lock_time_ = data.lock_time;
  fund_tx_id_ = data.fund_tx_id;
  fund_vout_ = data.fund_vout;
  ignore_items = data.ignore_items;
}

CreateRefundTransactionRequestStruct CreateRefundTransactionRequest::ConvertToStruct() const {  // NOLINT
  CreateRefundTransactionRequestStruct result;
  result.offer_final_script_pubkey = offer_final_script_pubkey_;
  result.accept_final_script_pubkey = accept_final_script_pubkey_;
  result.offer_amount = offer_amount_;
  result.accept_amount = accept_amount_;
  result.lock_time = lock_time_;
  result.fund_tx_id = fund_tx_id_;
  result.fund_vout = fund_vout_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateRefundTransactionResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateRefundTransactionResponse>
  CreateRefundTransactionResponse::json_mapper;
std::vector<std::string> CreateRefundTransactionResponse::item_list;

void CreateRefundTransactionResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateRefundTransactionResponse> func_table;  // NOLINT

  func_table = {
    CreateRefundTransactionResponse::GetHexString,
    CreateRefundTransactionResponse::SetHexString,
    CreateRefundTransactionResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
}

void CreateRefundTransactionResponse::ConvertFromStruct(
    const CreateRefundTransactionResponseStruct& data) {
  hex_ = data.hex;
  ignore_items = data.ignore_items;
}

CreateRefundTransactionResponseStruct CreateRefundTransactionResponse::ConvertToStruct() const {  // NOLINT
  CreateRefundTransactionResponseStruct result;
  result.hex = hex_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// InnerErrorResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<InnerErrorResponse>
  InnerErrorResponse::json_mapper;
std::vector<std::string> InnerErrorResponse::item_list;

void InnerErrorResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<InnerErrorResponse> func_table;  // NOLINT

  func_table = {
    InnerErrorResponse::GetCodeString,
    InnerErrorResponse::SetCodeString,
    InnerErrorResponse::GetCodeFieldType,
  };
  json_mapper.emplace("code", func_table);
  item_list.push_back("code");
  func_table = {
    InnerErrorResponse::GetTypeString,
    InnerErrorResponse::SetTypeString,
    InnerErrorResponse::GetTypeFieldType,
  };
  json_mapper.emplace("type", func_table);
  item_list.push_back("type");
  func_table = {
    InnerErrorResponse::GetMessageString,
    InnerErrorResponse::SetMessageString,
    InnerErrorResponse::GetMessageFieldType,
  };
  json_mapper.emplace("message", func_table);
  item_list.push_back("message");
}

void InnerErrorResponse::ConvertFromStruct(
    const InnerErrorResponseStruct& data) {
  code_ = data.code;
  type_ = data.type;
  message_ = data.message;
  ignore_items = data.ignore_items;
}

InnerErrorResponseStruct InnerErrorResponse::ConvertToStruct() const {  // NOLINT
  InnerErrorResponseStruct result;
  result.code = code_;
  result.type = type_;
  result.message = message_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// ErrorResponseBase
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<ErrorResponseBase>
  ErrorResponseBase::json_mapper;
std::vector<std::string> ErrorResponseBase::item_list;

void ErrorResponseBase::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<ErrorResponseBase> func_table;  // NOLINT

  func_table = {
    ErrorResponseBase::GetErrorString,
    ErrorResponseBase::SetErrorString,
    ErrorResponseBase::GetErrorFieldType,
  };
  json_mapper.emplace("error", func_table);
  item_list.push_back("error");
}

// ------------------------------------------------------------------------
// GetRawFundTxSignatureRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetRawFundTxSignatureRequest>
  GetRawFundTxSignatureRequest::json_mapper;
std::vector<std::string> GetRawFundTxSignatureRequest::item_list;

void GetRawFundTxSignatureRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetRawFundTxSignatureRequest> func_table;  // NOLINT

  func_table = {
    GetRawFundTxSignatureRequest::GetFundTxHexString,
    GetRawFundTxSignatureRequest::SetFundTxHexString,
    GetRawFundTxSignatureRequest::GetFundTxHexFieldType,
  };
  json_mapper.emplace("fundTxHex", func_table);
  item_list.push_back("fundTxHex");
  func_table = {
    GetRawFundTxSignatureRequest::GetPrivkeyString,
    GetRawFundTxSignatureRequest::SetPrivkeyString,
    GetRawFundTxSignatureRequest::GetPrivkeyFieldType,
  };
  json_mapper.emplace("privkey", func_table);
  item_list.push_back("privkey");
  func_table = {
    GetRawFundTxSignatureRequest::GetPrevTxIdString,
    GetRawFundTxSignatureRequest::SetPrevTxIdString,
    GetRawFundTxSignatureRequest::GetPrevTxIdFieldType,
  };
  json_mapper.emplace("prevTxId", func_table);
  item_list.push_back("prevTxId");
  func_table = {
    GetRawFundTxSignatureRequest::GetPrevVoutString,
    GetRawFundTxSignatureRequest::SetPrevVoutString,
    GetRawFundTxSignatureRequest::GetPrevVoutFieldType,
  };
  json_mapper.emplace("prevVout", func_table);
  item_list.push_back("prevVout");
  func_table = {
    GetRawFundTxSignatureRequest::GetAmountString,
    GetRawFundTxSignatureRequest::SetAmountString,
    GetRawFundTxSignatureRequest::GetAmountFieldType,
  };
  json_mapper.emplace("amount", func_table);
  item_list.push_back("amount");
}

void GetRawFundTxSignatureRequest::ConvertFromStruct(
    const GetRawFundTxSignatureRequestStruct& data) {
  fund_tx_hex_ = data.fund_tx_hex;
  privkey_ = data.privkey;
  prev_tx_id_ = data.prev_tx_id;
  prev_vout_ = data.prev_vout;
  amount_ = data.amount;
  ignore_items = data.ignore_items;
}

GetRawFundTxSignatureRequestStruct GetRawFundTxSignatureRequest::ConvertToStruct() const {  // NOLINT
  GetRawFundTxSignatureRequestStruct result;
  result.fund_tx_hex = fund_tx_hex_;
  result.privkey = privkey_;
  result.prev_tx_id = prev_tx_id_;
  result.prev_vout = prev_vout_;
  result.amount = amount_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// GetRawFundTxSignatureResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetRawFundTxSignatureResponse>
  GetRawFundTxSignatureResponse::json_mapper;
std::vector<std::string> GetRawFundTxSignatureResponse::item_list;

void GetRawFundTxSignatureResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetRawFundTxSignatureResponse> func_table;  // NOLINT

  func_table = {
    GetRawFundTxSignatureResponse::GetHexString,
    GetRawFundTxSignatureResponse::SetHexString,
    GetRawFundTxSignatureResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
}

void GetRawFundTxSignatureResponse::ConvertFromStruct(
    const GetRawFundTxSignatureResponseStruct& data) {
  hex_ = data.hex;
  ignore_items = data.ignore_items;
}

GetRawFundTxSignatureResponseStruct GetRawFundTxSignatureResponse::ConvertToStruct() const {  // NOLINT
  GetRawFundTxSignatureResponseStruct result;
  result.hex = hex_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// GetRawRefundTxSignatureRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetRawRefundTxSignatureRequest>
  GetRawRefundTxSignatureRequest::json_mapper;
std::vector<std::string> GetRawRefundTxSignatureRequest::item_list;

void GetRawRefundTxSignatureRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetRawRefundTxSignatureRequest> func_table;  // NOLINT

  func_table = {
    GetRawRefundTxSignatureRequest::GetRefundTxHexString,
    GetRawRefundTxSignatureRequest::SetRefundTxHexString,
    GetRawRefundTxSignatureRequest::GetRefundTxHexFieldType,
  };
  json_mapper.emplace("refundTxHex", func_table);
  item_list.push_back("refundTxHex");
  func_table = {
    GetRawRefundTxSignatureRequest::GetPrivkeyString,
    GetRawRefundTxSignatureRequest::SetPrivkeyString,
    GetRawRefundTxSignatureRequest::GetPrivkeyFieldType,
  };
  json_mapper.emplace("privkey", func_table);
  item_list.push_back("privkey");
  func_table = {
    GetRawRefundTxSignatureRequest::GetFundTxIdString,
    GetRawRefundTxSignatureRequest::SetFundTxIdString,
    GetRawRefundTxSignatureRequest::GetFundTxIdFieldType,
  };
  json_mapper.emplace("fundTxId", func_table);
  item_list.push_back("fundTxId");
  func_table = {
    GetRawRefundTxSignatureRequest::GetFundVoutString,
    GetRawRefundTxSignatureRequest::SetFundVoutString,
    GetRawRefundTxSignatureRequest::GetFundVoutFieldType,
  };
  json_mapper.emplace("fundVout", func_table);
  item_list.push_back("fundVout");
  func_table = {
    GetRawRefundTxSignatureRequest::GetOfferFundPubkeyString,
    GetRawRefundTxSignatureRequest::SetOfferFundPubkeyString,
    GetRawRefundTxSignatureRequest::GetOfferFundPubkeyFieldType,
  };
  json_mapper.emplace("offerFundPubkey", func_table);
  item_list.push_back("offerFundPubkey");
  func_table = {
    GetRawRefundTxSignatureRequest::GetAcceptFundPubkeyString,
    GetRawRefundTxSignatureRequest::SetAcceptFundPubkeyString,
    GetRawRefundTxSignatureRequest::GetAcceptFundPubkeyFieldType,
  };
  json_mapper.emplace("acceptFundPubkey", func_table);
  item_list.push_back("acceptFundPubkey");
  func_table = {
    GetRawRefundTxSignatureRequest::GetFundInputAmountString,
    GetRawRefundTxSignatureRequest::SetFundInputAmountString,
    GetRawRefundTxSignatureRequest::GetFundInputAmountFieldType,
  };
  json_mapper.emplace("fundInputAmount", func_table);
  item_list.push_back("fundInputAmount");
}

void GetRawRefundTxSignatureRequest::ConvertFromStruct(
    const GetRawRefundTxSignatureRequestStruct& data) {
  refund_tx_hex_ = data.refund_tx_hex;
  privkey_ = data.privkey;
  fund_tx_id_ = data.fund_tx_id;
  fund_vout_ = data.fund_vout;
  offer_fund_pubkey_ = data.offer_fund_pubkey;
  accept_fund_pubkey_ = data.accept_fund_pubkey;
  fund_input_amount_ = data.fund_input_amount;
  ignore_items = data.ignore_items;
}

GetRawRefundTxSignatureRequestStruct GetRawRefundTxSignatureRequest::ConvertToStruct() const {  // NOLINT
  GetRawRefundTxSignatureRequestStruct result;
  result.refund_tx_hex = refund_tx_hex_;
  result.privkey = privkey_;
  result.fund_tx_id = fund_tx_id_;
  result.fund_vout = fund_vout_;
  result.offer_fund_pubkey = offer_fund_pubkey_;
  result.accept_fund_pubkey = accept_fund_pubkey_;
  result.fund_input_amount = fund_input_amount_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// GetRawRefundTxSignatureResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetRawRefundTxSignatureResponse>
  GetRawRefundTxSignatureResponse::json_mapper;
std::vector<std::string> GetRawRefundTxSignatureResponse::item_list;

void GetRawRefundTxSignatureResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetRawRefundTxSignatureResponse> func_table;  // NOLINT

  func_table = {
    GetRawRefundTxSignatureResponse::GetHexString,
    GetRawRefundTxSignatureResponse::SetHexString,
    GetRawRefundTxSignatureResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
}

void GetRawRefundTxSignatureResponse::ConvertFromStruct(
    const GetRawRefundTxSignatureResponseStruct& data) {
  hex_ = data.hex;
  ignore_items = data.ignore_items;
}

GetRawRefundTxSignatureResponseStruct GetRawRefundTxSignatureResponse::ConvertToStruct() const {  // NOLINT
  GetRawRefundTxSignatureResponseStruct result;
  result.hex = hex_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// SignCetRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<SignCetRequest>
  SignCetRequest::json_mapper;
std::vector<std::string> SignCetRequest::item_list;

void SignCetRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<SignCetRequest> func_table;  // NOLINT

  func_table = {
    SignCetRequest::GetCetHexString,
    SignCetRequest::SetCetHexString,
    SignCetRequest::GetCetHexFieldType,
  };
  json_mapper.emplace("cetHex", func_table);
  item_list.push_back("cetHex");
  func_table = {
    SignCetRequest::GetFundPrivkeyString,
    SignCetRequest::SetFundPrivkeyString,
    SignCetRequest::GetFundPrivkeyFieldType,
  };
  json_mapper.emplace("fundPrivkey", func_table);
  item_list.push_back("fundPrivkey");
  func_table = {
    SignCetRequest::GetFundTxIdString,
    SignCetRequest::SetFundTxIdString,
    SignCetRequest::GetFundTxIdFieldType,
  };
  json_mapper.emplace("fundTxId", func_table);
  item_list.push_back("fundTxId");
  func_table = {
    SignCetRequest::GetFundVoutString,
    SignCetRequest::SetFundVoutString,
    SignCetRequest::GetFundVoutFieldType,
  };
  json_mapper.emplace("fundVout", func_table);
  item_list.push_back("fundVout");
  func_table = {
    SignCetRequest::GetOfferFundPubkeyString,
    SignCetRequest::SetOfferFundPubkeyString,
    SignCetRequest::GetOfferFundPubkeyFieldType,
  };
  json_mapper.emplace("offerFundPubkey", func_table);
  item_list.push_back("offerFundPubkey");
  func_table = {
    SignCetRequest::GetAcceptFundPubkeyString,
    SignCetRequest::SetAcceptFundPubkeyString,
    SignCetRequest::GetAcceptFundPubkeyFieldType,
  };
  json_mapper.emplace("acceptFundPubkey", func_table);
  item_list.push_back("acceptFundPubkey");
  func_table = {
    SignCetRequest::GetFundInputAmountString,
    SignCetRequest::SetFundInputAmountString,
    SignCetRequest::GetFundInputAmountFieldType,
  };
  json_mapper.emplace("fundInputAmount", func_table);
  item_list.push_back("fundInputAmount");
  func_table = {
    SignCetRequest::GetAdaptorSignatureString,
    SignCetRequest::SetAdaptorSignatureString,
    SignCetRequest::GetAdaptorSignatureFieldType,
  };
  json_mapper.emplace("adaptorSignature", func_table);
  item_list.push_back("adaptorSignature");
  func_table = {
    SignCetRequest::GetOracleSignaturesString,
    SignCetRequest::SetOracleSignaturesString,
    SignCetRequest::GetOracleSignaturesFieldType,
  };
  json_mapper.emplace("oracleSignatures", func_table);
  item_list.push_back("oracleSignatures");
}

void SignCetRequest::ConvertFromStruct(
    const SignCetRequestStruct& data) {
  cet_hex_ = data.cet_hex;
  fund_privkey_ = data.fund_privkey;
  fund_tx_id_ = data.fund_tx_id;
  fund_vout_ = data.fund_vout;
  offer_fund_pubkey_ = data.offer_fund_pubkey;
  accept_fund_pubkey_ = data.accept_fund_pubkey;
  fund_input_amount_ = data.fund_input_amount;
  adaptor_signature_ = data.adaptor_signature;
  oracle_signatures_.ConvertFromStruct(data.oracle_signatures);
  ignore_items = data.ignore_items;
}

SignCetRequestStruct SignCetRequest::ConvertToStruct() const {  // NOLINT
  SignCetRequestStruct result;
  result.cet_hex = cet_hex_;
  result.fund_privkey = fund_privkey_;
  result.fund_tx_id = fund_tx_id_;
  result.fund_vout = fund_vout_;
  result.offer_fund_pubkey = offer_fund_pubkey_;
  result.accept_fund_pubkey = accept_fund_pubkey_;
  result.fund_input_amount = fund_input_amount_;
  result.adaptor_signature = adaptor_signature_;
  result.oracle_signatures = oracle_signatures_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// SignCetResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<SignCetResponse>
  SignCetResponse::json_mapper;
std::vector<std::string> SignCetResponse::item_list;

void SignCetResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<SignCetResponse> func_table;  // NOLINT

  func_table = {
    SignCetResponse::GetHexString,
    SignCetResponse::SetHexString,
    SignCetResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
}

void SignCetResponse::ConvertFromStruct(
    const SignCetResponseStruct& data) {
  hex_ = data.hex;
  ignore_items = data.ignore_items;
}

SignCetResponseStruct SignCetResponse::ConvertToStruct() const {  // NOLINT
  SignCetResponseStruct result;
  result.hex = hex_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// SignFundTransactionRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<SignFundTransactionRequest>
  SignFundTransactionRequest::json_mapper;
std::vector<std::string> SignFundTransactionRequest::item_list;

void SignFundTransactionRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<SignFundTransactionRequest> func_table;  // NOLINT

  func_table = {
    SignFundTransactionRequest::GetFundTxHexString,
    SignFundTransactionRequest::SetFundTxHexString,
    SignFundTransactionRequest::GetFundTxHexFieldType,
  };
  json_mapper.emplace("fundTxHex", func_table);
  item_list.push_back("fundTxHex");
  func_table = {
    SignFundTransactionRequest::GetPrivkeyString,
    SignFundTransactionRequest::SetPrivkeyString,
    SignFundTransactionRequest::GetPrivkeyFieldType,
  };
  json_mapper.emplace("privkey", func_table);
  item_list.push_back("privkey");
  func_table = {
    SignFundTransactionRequest::GetPrevTxIdString,
    SignFundTransactionRequest::SetPrevTxIdString,
    SignFundTransactionRequest::GetPrevTxIdFieldType,
  };
  json_mapper.emplace("prevTxId", func_table);
  item_list.push_back("prevTxId");
  func_table = {
    SignFundTransactionRequest::GetPrevVoutString,
    SignFundTransactionRequest::SetPrevVoutString,
    SignFundTransactionRequest::GetPrevVoutFieldType,
  };
  json_mapper.emplace("prevVout", func_table);
  item_list.push_back("prevVout");
  func_table = {
    SignFundTransactionRequest::GetAmountString,
    SignFundTransactionRequest::SetAmountString,
    SignFundTransactionRequest::GetAmountFieldType,
  };
  json_mapper.emplace("amount", func_table);
  item_list.push_back("amount");
}

void SignFundTransactionRequest::ConvertFromStruct(
    const SignFundTransactionRequestStruct& data) {
  fund_tx_hex_ = data.fund_tx_hex;
  privkey_ = data.privkey;
  prev_tx_id_ = data.prev_tx_id;
  prev_vout_ = data.prev_vout;
  amount_ = data.amount;
  ignore_items = data.ignore_items;
}

SignFundTransactionRequestStruct SignFundTransactionRequest::ConvertToStruct() const {  // NOLINT
  SignFundTransactionRequestStruct result;
  result.fund_tx_hex = fund_tx_hex_;
  result.privkey = privkey_;
  result.prev_tx_id = prev_tx_id_;
  result.prev_vout = prev_vout_;
  result.amount = amount_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// SignFundTransactionResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<SignFundTransactionResponse>
  SignFundTransactionResponse::json_mapper;
std::vector<std::string> SignFundTransactionResponse::item_list;

void SignFundTransactionResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<SignFundTransactionResponse> func_table;  // NOLINT

  func_table = {
    SignFundTransactionResponse::GetHexString,
    SignFundTransactionResponse::SetHexString,
    SignFundTransactionResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
}

void SignFundTransactionResponse::ConvertFromStruct(
    const SignFundTransactionResponseStruct& data) {
  hex_ = data.hex;
  ignore_items = data.ignore_items;
}

SignFundTransactionResponseStruct SignFundTransactionResponse::ConvertToStruct() const {  // NOLINT
  SignFundTransactionResponseStruct result;
  result.hex = hex_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// VerifyCetAdaptorSignatureRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<VerifyCetAdaptorSignatureRequest>
  VerifyCetAdaptorSignatureRequest::json_mapper;
std::vector<std::string> VerifyCetAdaptorSignatureRequest::item_list;

void VerifyCetAdaptorSignatureRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<VerifyCetAdaptorSignatureRequest> func_table;  // NOLINT

  func_table = {
    VerifyCetAdaptorSignatureRequest::GetCetHexString,
    VerifyCetAdaptorSignatureRequest::SetCetHexString,
    VerifyCetAdaptorSignatureRequest::GetCetHexFieldType,
  };
  json_mapper.emplace("cetHex", func_table);
  item_list.push_back("cetHex");
  func_table = {
    VerifyCetAdaptorSignatureRequest::GetAdaptorSignatureString,
    VerifyCetAdaptorSignatureRequest::SetAdaptorSignatureString,
    VerifyCetAdaptorSignatureRequest::GetAdaptorSignatureFieldType,
  };
  json_mapper.emplace("adaptorSignature", func_table);
  item_list.push_back("adaptorSignature");
  func_table = {
    VerifyCetAdaptorSignatureRequest::GetMessagesString,
    VerifyCetAdaptorSignatureRequest::SetMessagesString,
    VerifyCetAdaptorSignatureRequest::GetMessagesFieldType,
  };
  json_mapper.emplace("messages", func_table);
  item_list.push_back("messages");
  func_table = {
    VerifyCetAdaptorSignatureRequest::GetOfferFundPubkeyString,
    VerifyCetAdaptorSignatureRequest::SetOfferFundPubkeyString,
    VerifyCetAdaptorSignatureRequest::GetOfferFundPubkeyFieldType,
  };
  json_mapper.emplace("offerFundPubkey", func_table);
  item_list.push_back("offerFundPubkey");
  func_table = {
    VerifyCetAdaptorSignatureRequest::GetAcceptFundPubkeyString,
    VerifyCetAdaptorSignatureRequest::SetAcceptFundPubkeyString,
    VerifyCetAdaptorSignatureRequest::GetAcceptFundPubkeyFieldType,
  };
  json_mapper.emplace("acceptFundPubkey", func_table);
  item_list.push_back("acceptFundPubkey");
  func_table = {
    VerifyCetAdaptorSignatureRequest::GetOraclePubkeyString,
    VerifyCetAdaptorSignatureRequest::SetOraclePubkeyString,
    VerifyCetAdaptorSignatureRequest::GetOraclePubkeyFieldType,
  };
  json_mapper.emplace("oraclePubkey", func_table);
  item_list.push_back("oraclePubkey");
  func_table = {
    VerifyCetAdaptorSignatureRequest::GetOracleRValuesString,
    VerifyCetAdaptorSignatureRequest::SetOracleRValuesString,
    VerifyCetAdaptorSignatureRequest::GetOracleRValuesFieldType,
  };
  json_mapper.emplace("oracleRValues", func_table);
  item_list.push_back("oracleRValues");
  func_table = {
    VerifyCetAdaptorSignatureRequest::GetFundTxIdString,
    VerifyCetAdaptorSignatureRequest::SetFundTxIdString,
    VerifyCetAdaptorSignatureRequest::GetFundTxIdFieldType,
  };
  json_mapper.emplace("fundTxId", func_table);
  item_list.push_back("fundTxId");
  func_table = {
    VerifyCetAdaptorSignatureRequest::GetFundVoutString,
    VerifyCetAdaptorSignatureRequest::SetFundVoutString,
    VerifyCetAdaptorSignatureRequest::GetFundVoutFieldType,
  };
  json_mapper.emplace("fundVout", func_table);
  item_list.push_back("fundVout");
  func_table = {
    VerifyCetAdaptorSignatureRequest::GetFundInputAmountString,
    VerifyCetAdaptorSignatureRequest::SetFundInputAmountString,
    VerifyCetAdaptorSignatureRequest::GetFundInputAmountFieldType,
  };
  json_mapper.emplace("fundInputAmount", func_table);
  item_list.push_back("fundInputAmount");
  func_table = {
    VerifyCetAdaptorSignatureRequest::GetVerifyAcceptString,
    VerifyCetAdaptorSignatureRequest::SetVerifyAcceptString,
    VerifyCetAdaptorSignatureRequest::GetVerifyAcceptFieldType,
  };
  json_mapper.emplace("verifyAccept", func_table);
  item_list.push_back("verifyAccept");
}

void VerifyCetAdaptorSignatureRequest::ConvertFromStruct(
    const VerifyCetAdaptorSignatureRequestStruct& data) {
  cet_hex_ = data.cet_hex;
  adaptor_signature_ = data.adaptor_signature;
  messages_.ConvertFromStruct(data.messages);
  offer_fund_pubkey_ = data.offer_fund_pubkey;
  accept_fund_pubkey_ = data.accept_fund_pubkey;
  oracle_pubkey_ = data.oracle_pubkey;
  oracle_r_values_.ConvertFromStruct(data.oracle_r_values);
  fund_tx_id_ = data.fund_tx_id;
  fund_vout_ = data.fund_vout;
  fund_input_amount_ = data.fund_input_amount;
  verify_accept_ = data.verify_accept;
  ignore_items = data.ignore_items;
}

VerifyCetAdaptorSignatureRequestStruct VerifyCetAdaptorSignatureRequest::ConvertToStruct() const {  // NOLINT
  VerifyCetAdaptorSignatureRequestStruct result;
  result.cet_hex = cet_hex_;
  result.adaptor_signature = adaptor_signature_;
  result.messages = messages_.ConvertToStruct();
  result.offer_fund_pubkey = offer_fund_pubkey_;
  result.accept_fund_pubkey = accept_fund_pubkey_;
  result.oracle_pubkey = oracle_pubkey_;
  result.oracle_r_values = oracle_r_values_.ConvertToStruct();
  result.fund_tx_id = fund_tx_id_;
  result.fund_vout = fund_vout_;
  result.fund_input_amount = fund_input_amount_;
  result.verify_accept = verify_accept_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// VerifyCetAdaptorSignatureResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<VerifyCetAdaptorSignatureResponse>
  VerifyCetAdaptorSignatureResponse::json_mapper;
std::vector<std::string> VerifyCetAdaptorSignatureResponse::item_list;

void VerifyCetAdaptorSignatureResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<VerifyCetAdaptorSignatureResponse> func_table;  // NOLINT

  func_table = {
    VerifyCetAdaptorSignatureResponse::GetValidString,
    VerifyCetAdaptorSignatureResponse::SetValidString,
    VerifyCetAdaptorSignatureResponse::GetValidFieldType,
  };
  json_mapper.emplace("valid", func_table);
  item_list.push_back("valid");
}

void VerifyCetAdaptorSignatureResponse::ConvertFromStruct(
    const VerifyCetAdaptorSignatureResponseStruct& data) {
  valid_ = data.valid;
  ignore_items = data.ignore_items;
}

VerifyCetAdaptorSignatureResponseStruct VerifyCetAdaptorSignatureResponse::ConvertToStruct() const {  // NOLINT
  VerifyCetAdaptorSignatureResponseStruct result;
  result.valid = valid_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// VerifyCetAdaptorSignaturesRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<VerifyCetAdaptorSignaturesRequest>
  VerifyCetAdaptorSignaturesRequest::json_mapper;
std::vector<std::string> VerifyCetAdaptorSignaturesRequest::item_list;

void VerifyCetAdaptorSignaturesRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<VerifyCetAdaptorSignaturesRequest> func_table;  // NOLINT

  func_table = {
    VerifyCetAdaptorSignaturesRequest::GetCetsHexString,
    VerifyCetAdaptorSignaturesRequest::SetCetsHexString,
    VerifyCetAdaptorSignaturesRequest::GetCetsHexFieldType,
  };
  json_mapper.emplace("cetsHex", func_table);
  item_list.push_back("cetsHex");
  func_table = {
    VerifyCetAdaptorSignaturesRequest::GetAdaptorSignaturesString,
    VerifyCetAdaptorSignaturesRequest::SetAdaptorSignaturesString,
    VerifyCetAdaptorSignaturesRequest::GetAdaptorSignaturesFieldType,
  };
  json_mapper.emplace("adaptorSignatures", func_table);
  item_list.push_back("adaptorSignatures");
  func_table = {
    VerifyCetAdaptorSignaturesRequest::GetMessagesListString,
    VerifyCetAdaptorSignaturesRequest::SetMessagesListString,
    VerifyCetAdaptorSignaturesRequest::GetMessagesListFieldType,
  };
  json_mapper.emplace("messagesList", func_table);
  item_list.push_back("messagesList");
  func_table = {
    VerifyCetAdaptorSignaturesRequest::GetOfferFundPubkeyString,
    VerifyCetAdaptorSignaturesRequest::SetOfferFundPubkeyString,
    VerifyCetAdaptorSignaturesRequest::GetOfferFundPubkeyFieldType,
  };
  json_mapper.emplace("offerFundPubkey", func_table);
  item_list.push_back("offerFundPubkey");
  func_table = {
    VerifyCetAdaptorSignaturesRequest::GetAcceptFundPubkeyString,
    VerifyCetAdaptorSignaturesRequest::SetAcceptFundPubkeyString,
    VerifyCetAdaptorSignaturesRequest::GetAcceptFundPubkeyFieldType,
  };
  json_mapper.emplace("acceptFundPubkey", func_table);
  item_list.push_back("acceptFundPubkey");
  func_table = {
    VerifyCetAdaptorSignaturesRequest::GetOraclePubkeyString,
    VerifyCetAdaptorSignaturesRequest::SetOraclePubkeyString,
    VerifyCetAdaptorSignaturesRequest::GetOraclePubkeyFieldType,
  };
  json_mapper.emplace("oraclePubkey", func_table);
  item_list.push_back("oraclePubkey");
  func_table = {
    VerifyCetAdaptorSignaturesRequest::GetOracleRValuesString,
    VerifyCetAdaptorSignaturesRequest::SetOracleRValuesString,
    VerifyCetAdaptorSignaturesRequest::GetOracleRValuesFieldType,
  };
  json_mapper.emplace("oracleRValues", func_table);
  item_list.push_back("oracleRValues");
  func_table = {
    VerifyCetAdaptorSignaturesRequest::GetFundTxIdString,
    VerifyCetAdaptorSignaturesRequest::SetFundTxIdString,
    VerifyCetAdaptorSignaturesRequest::GetFundTxIdFieldType,
  };
  json_mapper.emplace("fundTxId", func_table);
  item_list.push_back("fundTxId");
  func_table = {
    VerifyCetAdaptorSignaturesRequest::GetFundVoutString,
    VerifyCetAdaptorSignaturesRequest::SetFundVoutString,
    VerifyCetAdaptorSignaturesRequest::GetFundVoutFieldType,
  };
  json_mapper.emplace("fundVout", func_table);
  item_list.push_back("fundVout");
  func_table = {
    VerifyCetAdaptorSignaturesRequest::GetFundInputAmountString,
    VerifyCetAdaptorSignaturesRequest::SetFundInputAmountString,
    VerifyCetAdaptorSignaturesRequest::GetFundInputAmountFieldType,
  };
  json_mapper.emplace("fundInputAmount", func_table);
  item_list.push_back("fundInputAmount");
  func_table = {
    VerifyCetAdaptorSignaturesRequest::GetVerifyAcceptString,
    VerifyCetAdaptorSignaturesRequest::SetVerifyAcceptString,
    VerifyCetAdaptorSignaturesRequest::GetVerifyAcceptFieldType,
  };
  json_mapper.emplace("verifyAccept", func_table);
  item_list.push_back("verifyAccept");
}

void VerifyCetAdaptorSignaturesRequest::ConvertFromStruct(
    const VerifyCetAdaptorSignaturesRequestStruct& data) {
  cets_hex_.ConvertFromStruct(data.cets_hex);
  adaptor_signatures_.ConvertFromStruct(data.adaptor_signatures);
  messages_list_.ConvertFromStruct(data.messages_list);
  offer_fund_pubkey_ = data.offer_fund_pubkey;
  accept_fund_pubkey_ = data.accept_fund_pubkey;
  oracle_pubkey_ = data.oracle_pubkey;
  oracle_r_values_.ConvertFromStruct(data.oracle_r_values);
  fund_tx_id_ = data.fund_tx_id;
  fund_vout_ = data.fund_vout;
  fund_input_amount_ = data.fund_input_amount;
  verify_accept_ = data.verify_accept;
  ignore_items = data.ignore_items;
}

VerifyCetAdaptorSignaturesRequestStruct VerifyCetAdaptorSignaturesRequest::ConvertToStruct() const {  // NOLINT
  VerifyCetAdaptorSignaturesRequestStruct result;
  result.cets_hex = cets_hex_.ConvertToStruct();
  result.adaptor_signatures = adaptor_signatures_.ConvertToStruct();
  result.messages_list = messages_list_.ConvertToStruct();
  result.offer_fund_pubkey = offer_fund_pubkey_;
  result.accept_fund_pubkey = accept_fund_pubkey_;
  result.oracle_pubkey = oracle_pubkey_;
  result.oracle_r_values = oracle_r_values_.ConvertToStruct();
  result.fund_tx_id = fund_tx_id_;
  result.fund_vout = fund_vout_;
  result.fund_input_amount = fund_input_amount_;
  result.verify_accept = verify_accept_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// VerifyCetAdaptorSignaturesResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<VerifyCetAdaptorSignaturesResponse>
  VerifyCetAdaptorSignaturesResponse::json_mapper;
std::vector<std::string> VerifyCetAdaptorSignaturesResponse::item_list;

void VerifyCetAdaptorSignaturesResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<VerifyCetAdaptorSignaturesResponse> func_table;  // NOLINT

  func_table = {
    VerifyCetAdaptorSignaturesResponse::GetValidString,
    VerifyCetAdaptorSignaturesResponse::SetValidString,
    VerifyCetAdaptorSignaturesResponse::GetValidFieldType,
  };
  json_mapper.emplace("valid", func_table);
  item_list.push_back("valid");
}

void VerifyCetAdaptorSignaturesResponse::ConvertFromStruct(
    const VerifyCetAdaptorSignaturesResponseStruct& data) {
  valid_ = data.valid;
  ignore_items = data.ignore_items;
}

VerifyCetAdaptorSignaturesResponseStruct VerifyCetAdaptorSignaturesResponse::ConvertToStruct() const {  // NOLINT
  VerifyCetAdaptorSignaturesResponseStruct result;
  result.valid = valid_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// VerifyFundTxSignatureRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<VerifyFundTxSignatureRequest>
  VerifyFundTxSignatureRequest::json_mapper;
std::vector<std::string> VerifyFundTxSignatureRequest::item_list;

void VerifyFundTxSignatureRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<VerifyFundTxSignatureRequest> func_table;  // NOLINT

  func_table = {
    VerifyFundTxSignatureRequest::GetFundTxHexString,
    VerifyFundTxSignatureRequest::SetFundTxHexString,
    VerifyFundTxSignatureRequest::GetFundTxHexFieldType,
  };
  json_mapper.emplace("fundTxHex", func_table);
  item_list.push_back("fundTxHex");
  func_table = {
    VerifyFundTxSignatureRequest::GetSignatureString,
    VerifyFundTxSignatureRequest::SetSignatureString,
    VerifyFundTxSignatureRequest::GetSignatureFieldType,
  };
  json_mapper.emplace("signature", func_table);
  item_list.push_back("signature");
  func_table = {
    VerifyFundTxSignatureRequest::GetPubkeyString,
    VerifyFundTxSignatureRequest::SetPubkeyString,
    VerifyFundTxSignatureRequest::GetPubkeyFieldType,
  };
  json_mapper.emplace("pubkey", func_table);
  item_list.push_back("pubkey");
  func_table = {
    VerifyFundTxSignatureRequest::GetPrevTxIdString,
    VerifyFundTxSignatureRequest::SetPrevTxIdString,
    VerifyFundTxSignatureRequest::GetPrevTxIdFieldType,
  };
  json_mapper.emplace("prevTxId", func_table);
  item_list.push_back("prevTxId");
  func_table = {
    VerifyFundTxSignatureRequest::GetPrevVoutString,
    VerifyFundTxSignatureRequest::SetPrevVoutString,
    VerifyFundTxSignatureRequest::GetPrevVoutFieldType,
  };
  json_mapper.emplace("prevVout", func_table);
  item_list.push_back("prevVout");
  func_table = {
    VerifyFundTxSignatureRequest::GetFundInputAmountString,
    VerifyFundTxSignatureRequest::SetFundInputAmountString,
    VerifyFundTxSignatureRequest::GetFundInputAmountFieldType,
  };
  json_mapper.emplace("fundInputAmount", func_table);
  item_list.push_back("fundInputAmount");
}

void VerifyFundTxSignatureRequest::ConvertFromStruct(
    const VerifyFundTxSignatureRequestStruct& data) {
  fund_tx_hex_ = data.fund_tx_hex;
  signature_ = data.signature;
  pubkey_ = data.pubkey;
  prev_tx_id_ = data.prev_tx_id;
  prev_vout_ = data.prev_vout;
  fund_input_amount_ = data.fund_input_amount;
  ignore_items = data.ignore_items;
}

VerifyFundTxSignatureRequestStruct VerifyFundTxSignatureRequest::ConvertToStruct() const {  // NOLINT
  VerifyFundTxSignatureRequestStruct result;
  result.fund_tx_hex = fund_tx_hex_;
  result.signature = signature_;
  result.pubkey = pubkey_;
  result.prev_tx_id = prev_tx_id_;
  result.prev_vout = prev_vout_;
  result.fund_input_amount = fund_input_amount_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// VerifyFundTxSignatureResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<VerifyFundTxSignatureResponse>
  VerifyFundTxSignatureResponse::json_mapper;
std::vector<std::string> VerifyFundTxSignatureResponse::item_list;

void VerifyFundTxSignatureResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<VerifyFundTxSignatureResponse> func_table;  // NOLINT

  func_table = {
    VerifyFundTxSignatureResponse::GetValidString,
    VerifyFundTxSignatureResponse::SetValidString,
    VerifyFundTxSignatureResponse::GetValidFieldType,
  };
  json_mapper.emplace("valid", func_table);
  item_list.push_back("valid");
}

void VerifyFundTxSignatureResponse::ConvertFromStruct(
    const VerifyFundTxSignatureResponseStruct& data) {
  valid_ = data.valid;
  ignore_items = data.ignore_items;
}

VerifyFundTxSignatureResponseStruct VerifyFundTxSignatureResponse::ConvertToStruct() const {  // NOLINT
  VerifyFundTxSignatureResponseStruct result;
  result.valid = valid_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// VerifyRefundTxSignatureRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<VerifyRefundTxSignatureRequest>
  VerifyRefundTxSignatureRequest::json_mapper;
std::vector<std::string> VerifyRefundTxSignatureRequest::item_list;

void VerifyRefundTxSignatureRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<VerifyRefundTxSignatureRequest> func_table;  // NOLINT

  func_table = {
    VerifyRefundTxSignatureRequest::GetRefundTxHexString,
    VerifyRefundTxSignatureRequest::SetRefundTxHexString,
    VerifyRefundTxSignatureRequest::GetRefundTxHexFieldType,
  };
  json_mapper.emplace("refundTxHex", func_table);
  item_list.push_back("refundTxHex");
  func_table = {
    VerifyRefundTxSignatureRequest::GetSignatureString,
    VerifyRefundTxSignatureRequest::SetSignatureString,
    VerifyRefundTxSignatureRequest::GetSignatureFieldType,
  };
  json_mapper.emplace("signature", func_table);
  item_list.push_back("signature");
  func_table = {
    VerifyRefundTxSignatureRequest::GetOfferFundPubkeyString,
    VerifyRefundTxSignatureRequest::SetOfferFundPubkeyString,
    VerifyRefundTxSignatureRequest::GetOfferFundPubkeyFieldType,
  };
  json_mapper.emplace("offerFundPubkey", func_table);
  item_list.push_back("offerFundPubkey");
  func_table = {
    VerifyRefundTxSignatureRequest::GetAcceptFundPubkeyString,
    VerifyRefundTxSignatureRequest::SetAcceptFundPubkeyString,
    VerifyRefundTxSignatureRequest::GetAcceptFundPubkeyFieldType,
  };
  json_mapper.emplace("acceptFundPubkey", func_table);
  item_list.push_back("acceptFundPubkey");
  func_table = {
    VerifyRefundTxSignatureRequest::GetFundTxIdString,
    VerifyRefundTxSignatureRequest::SetFundTxIdString,
    VerifyRefundTxSignatureRequest::GetFundTxIdFieldType,
  };
  json_mapper.emplace("fundTxId", func_table);
  item_list.push_back("fundTxId");
  func_table = {
    VerifyRefundTxSignatureRequest::GetFundVoutString,
    VerifyRefundTxSignatureRequest::SetFundVoutString,
    VerifyRefundTxSignatureRequest::GetFundVoutFieldType,
  };
  json_mapper.emplace("fundVout", func_table);
  item_list.push_back("fundVout");
  func_table = {
    VerifyRefundTxSignatureRequest::GetFundInputAmountString,
    VerifyRefundTxSignatureRequest::SetFundInputAmountString,
    VerifyRefundTxSignatureRequest::GetFundInputAmountFieldType,
  };
  json_mapper.emplace("fundInputAmount", func_table);
  item_list.push_back("fundInputAmount");
  func_table = {
    VerifyRefundTxSignatureRequest::GetVerifyAcceptString,
    VerifyRefundTxSignatureRequest::SetVerifyAcceptString,
    VerifyRefundTxSignatureRequest::GetVerifyAcceptFieldType,
  };
  json_mapper.emplace("verifyAccept", func_table);
  item_list.push_back("verifyAccept");
}

void VerifyRefundTxSignatureRequest::ConvertFromStruct(
    const VerifyRefundTxSignatureRequestStruct& data) {
  refund_tx_hex_ = data.refund_tx_hex;
  signature_ = data.signature;
  offer_fund_pubkey_ = data.offer_fund_pubkey;
  accept_fund_pubkey_ = data.accept_fund_pubkey;
  fund_tx_id_ = data.fund_tx_id;
  fund_vout_ = data.fund_vout;
  fund_input_amount_ = data.fund_input_amount;
  verify_accept_ = data.verify_accept;
  ignore_items = data.ignore_items;
}

VerifyRefundTxSignatureRequestStruct VerifyRefundTxSignatureRequest::ConvertToStruct() const {  // NOLINT
  VerifyRefundTxSignatureRequestStruct result;
  result.refund_tx_hex = refund_tx_hex_;
  result.signature = signature_;
  result.offer_fund_pubkey = offer_fund_pubkey_;
  result.accept_fund_pubkey = accept_fund_pubkey_;
  result.fund_tx_id = fund_tx_id_;
  result.fund_vout = fund_vout_;
  result.fund_input_amount = fund_input_amount_;
  result.verify_accept = verify_accept_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// VerifyRefundTxSignatureResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<VerifyRefundTxSignatureResponse>
  VerifyRefundTxSignatureResponse::json_mapper;
std::vector<std::string> VerifyRefundTxSignatureResponse::item_list;

void VerifyRefundTxSignatureResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<VerifyRefundTxSignatureResponse> func_table;  // NOLINT

  func_table = {
    VerifyRefundTxSignatureResponse::GetValidString,
    VerifyRefundTxSignatureResponse::SetValidString,
    VerifyRefundTxSignatureResponse::GetValidFieldType,
  };
  json_mapper.emplace("valid", func_table);
  item_list.push_back("valid");
}

void VerifyRefundTxSignatureResponse::ConvertFromStruct(
    const VerifyRefundTxSignatureResponseStruct& data) {
  valid_ = data.valid;
  ignore_items = data.ignore_items;
}

VerifyRefundTxSignatureResponseStruct VerifyRefundTxSignatureResponse::ConvertToStruct() const {  // NOLINT
  VerifyRefundTxSignatureResponseStruct result;
  result.valid = valid_;
  result.ignore_items = ignore_items;
  return result;
}

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace dlc
}  // namespace cfd
