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
// TxInRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<TxInRequest>
  TxInRequest::json_mapper;
std::vector<std::string> TxInRequest::item_list;

void TxInRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<TxInRequest> func_table;  // NOLINT

  func_table = {
    TxInRequest::GetTxidString,
    TxInRequest::SetTxidString,
    TxInRequest::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    TxInRequest::GetVoutString,
    TxInRequest::SetVoutString,
    TxInRequest::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
}

void TxInRequest::ConvertFromStruct(
    const TxInRequestStruct& data) {
  txid_ = data.txid;
  vout_ = data.vout;
  ignore_items = data.ignore_items;
}

TxInRequestStruct TxInRequest::ConvertToStruct() const {  // NOLINT
  TxInRequestStruct result;
  result.txid = txid_;
  result.vout = vout_;
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
// AddSignaturesToCetRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<AddSignaturesToCetRequest>
  AddSignaturesToCetRequest::json_mapper;
std::vector<std::string> AddSignaturesToCetRequest::item_list;

void AddSignaturesToCetRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<AddSignaturesToCetRequest> func_table;  // NOLINT

  func_table = {
    AddSignaturesToCetRequest::GetCetHexString,
    AddSignaturesToCetRequest::SetCetHexString,
    AddSignaturesToCetRequest::GetCetHexFieldType,
  };
  json_mapper.emplace("cetHex", func_table);
  item_list.push_back("cetHex");
  func_table = {
    AddSignaturesToCetRequest::GetSignaturesString,
    AddSignaturesToCetRequest::SetSignaturesString,
    AddSignaturesToCetRequest::GetSignaturesFieldType,
  };
  json_mapper.emplace("signatures", func_table);
  item_list.push_back("signatures");
  func_table = {
    AddSignaturesToCetRequest::GetFundTxIdString,
    AddSignaturesToCetRequest::SetFundTxIdString,
    AddSignaturesToCetRequest::GetFundTxIdFieldType,
  };
  json_mapper.emplace("fundTxId", func_table);
  item_list.push_back("fundTxId");
  func_table = {
    AddSignaturesToCetRequest::GetFundVoutString,
    AddSignaturesToCetRequest::SetFundVoutString,
    AddSignaturesToCetRequest::GetFundVoutFieldType,
  };
  json_mapper.emplace("fundVout", func_table);
  item_list.push_back("fundVout");
  func_table = {
    AddSignaturesToCetRequest::GetLocalFundPubkeyString,
    AddSignaturesToCetRequest::SetLocalFundPubkeyString,
    AddSignaturesToCetRequest::GetLocalFundPubkeyFieldType,
  };
  json_mapper.emplace("localFundPubkey", func_table);
  item_list.push_back("localFundPubkey");
  func_table = {
    AddSignaturesToCetRequest::GetRemoteFundPubkeyString,
    AddSignaturesToCetRequest::SetRemoteFundPubkeyString,
    AddSignaturesToCetRequest::GetRemoteFundPubkeyFieldType,
  };
  json_mapper.emplace("remoteFundPubkey", func_table);
  item_list.push_back("remoteFundPubkey");
}

void AddSignaturesToCetRequest::ConvertFromStruct(
    const AddSignaturesToCetRequestStruct& data) {
  cet_hex_ = data.cet_hex;
  signatures_.ConvertFromStruct(data.signatures);
  fund_tx_id_ = data.fund_tx_id;
  fund_vout_ = data.fund_vout;
  local_fund_pubkey_ = data.local_fund_pubkey;
  remote_fund_pubkey_ = data.remote_fund_pubkey;
  ignore_items = data.ignore_items;
}

AddSignaturesToCetRequestStruct AddSignaturesToCetRequest::ConvertToStruct() const {  // NOLINT
  AddSignaturesToCetRequestStruct result;
  result.cet_hex = cet_hex_;
  result.signatures = signatures_.ConvertToStruct();
  result.fund_tx_id = fund_tx_id_;
  result.fund_vout = fund_vout_;
  result.local_fund_pubkey = local_fund_pubkey_;
  result.remote_fund_pubkey = remote_fund_pubkey_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// AddSignaturesToCetResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<AddSignaturesToCetResponse>
  AddSignaturesToCetResponse::json_mapper;
std::vector<std::string> AddSignaturesToCetResponse::item_list;

void AddSignaturesToCetResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<AddSignaturesToCetResponse> func_table;  // NOLINT

  func_table = {
    AddSignaturesToCetResponse::GetHexString,
    AddSignaturesToCetResponse::SetHexString,
    AddSignaturesToCetResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
}

void AddSignaturesToCetResponse::ConvertFromStruct(
    const AddSignaturesToCetResponseStruct& data) {
  hex_ = data.hex;
  ignore_items = data.ignore_items;
}

AddSignaturesToCetResponseStruct AddSignaturesToCetResponse::ConvertToStruct() const {  // NOLINT
  AddSignaturesToCetResponseStruct result;
  result.hex = hex_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// AddSignaturesToMutualClosingTxRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<AddSignaturesToMutualClosingTxRequest>
  AddSignaturesToMutualClosingTxRequest::json_mapper;
std::vector<std::string> AddSignaturesToMutualClosingTxRequest::item_list;

void AddSignaturesToMutualClosingTxRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<AddSignaturesToMutualClosingTxRequest> func_table;  // NOLINT

  func_table = {
    AddSignaturesToMutualClosingTxRequest::GetMutualClosingTxHexString,
    AddSignaturesToMutualClosingTxRequest::SetMutualClosingTxHexString,
    AddSignaturesToMutualClosingTxRequest::GetMutualClosingTxHexFieldType,
  };
  json_mapper.emplace("mutualClosingTxHex", func_table);
  item_list.push_back("mutualClosingTxHex");
  func_table = {
    AddSignaturesToMutualClosingTxRequest::GetSignaturesString,
    AddSignaturesToMutualClosingTxRequest::SetSignaturesString,
    AddSignaturesToMutualClosingTxRequest::GetSignaturesFieldType,
  };
  json_mapper.emplace("signatures", func_table);
  item_list.push_back("signatures");
  func_table = {
    AddSignaturesToMutualClosingTxRequest::GetFundTxIdString,
    AddSignaturesToMutualClosingTxRequest::SetFundTxIdString,
    AddSignaturesToMutualClosingTxRequest::GetFundTxIdFieldType,
  };
  json_mapper.emplace("fundTxId", func_table);
  item_list.push_back("fundTxId");
  func_table = {
    AddSignaturesToMutualClosingTxRequest::GetFundVoutString,
    AddSignaturesToMutualClosingTxRequest::SetFundVoutString,
    AddSignaturesToMutualClosingTxRequest::GetFundVoutFieldType,
  };
  json_mapper.emplace("fundVout", func_table);
  item_list.push_back("fundVout");
  func_table = {
    AddSignaturesToMutualClosingTxRequest::GetLocalFundPubkeyString,
    AddSignaturesToMutualClosingTxRequest::SetLocalFundPubkeyString,
    AddSignaturesToMutualClosingTxRequest::GetLocalFundPubkeyFieldType,
  };
  json_mapper.emplace("localFundPubkey", func_table);
  item_list.push_back("localFundPubkey");
  func_table = {
    AddSignaturesToMutualClosingTxRequest::GetRemoteFundPubkeyString,
    AddSignaturesToMutualClosingTxRequest::SetRemoteFundPubkeyString,
    AddSignaturesToMutualClosingTxRequest::GetRemoteFundPubkeyFieldType,
  };
  json_mapper.emplace("remoteFundPubkey", func_table);
  item_list.push_back("remoteFundPubkey");
}

void AddSignaturesToMutualClosingTxRequest::ConvertFromStruct(
    const AddSignaturesToMutualClosingTxRequestStruct& data) {
  mutual_closing_tx_hex_ = data.mutual_closing_tx_hex;
  signatures_.ConvertFromStruct(data.signatures);
  fund_tx_id_ = data.fund_tx_id;
  fund_vout_ = data.fund_vout;
  local_fund_pubkey_ = data.local_fund_pubkey;
  remote_fund_pubkey_ = data.remote_fund_pubkey;
  ignore_items = data.ignore_items;
}

AddSignaturesToMutualClosingTxRequestStruct AddSignaturesToMutualClosingTxRequest::ConvertToStruct() const {  // NOLINT
  AddSignaturesToMutualClosingTxRequestStruct result;
  result.mutual_closing_tx_hex = mutual_closing_tx_hex_;
  result.signatures = signatures_.ConvertToStruct();
  result.fund_tx_id = fund_tx_id_;
  result.fund_vout = fund_vout_;
  result.local_fund_pubkey = local_fund_pubkey_;
  result.remote_fund_pubkey = remote_fund_pubkey_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// AddSignaturesToMutualClosingTxResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<AddSignaturesToMutualClosingTxResponse>
  AddSignaturesToMutualClosingTxResponse::json_mapper;
std::vector<std::string> AddSignaturesToMutualClosingTxResponse::item_list;

void AddSignaturesToMutualClosingTxResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<AddSignaturesToMutualClosingTxResponse> func_table;  // NOLINT

  func_table = {
    AddSignaturesToMutualClosingTxResponse::GetHexString,
    AddSignaturesToMutualClosingTxResponse::SetHexString,
    AddSignaturesToMutualClosingTxResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
}

void AddSignaturesToMutualClosingTxResponse::ConvertFromStruct(
    const AddSignaturesToMutualClosingTxResponseStruct& data) {
  hex_ = data.hex;
  ignore_items = data.ignore_items;
}

AddSignaturesToMutualClosingTxResponseStruct AddSignaturesToMutualClosingTxResponse::ConvertToStruct() const {  // NOLINT
  AddSignaturesToMutualClosingTxResponseStruct result;
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
    AddSignaturesToRefundTxRequest::GetLocalFundPubkeyString,
    AddSignaturesToRefundTxRequest::SetLocalFundPubkeyString,
    AddSignaturesToRefundTxRequest::GetLocalFundPubkeyFieldType,
  };
  json_mapper.emplace("localFundPubkey", func_table);
  item_list.push_back("localFundPubkey");
  func_table = {
    AddSignaturesToRefundTxRequest::GetRemoteFundPubkeyString,
    AddSignaturesToRefundTxRequest::SetRemoteFundPubkeyString,
    AddSignaturesToRefundTxRequest::GetRemoteFundPubkeyFieldType,
  };
  json_mapper.emplace("remoteFundPubkey", func_table);
  item_list.push_back("remoteFundPubkey");
}

void AddSignaturesToRefundTxRequest::ConvertFromStruct(
    const AddSignaturesToRefundTxRequestStruct& data) {
  refund_tx_hex_ = data.refund_tx_hex;
  signatures_.ConvertFromStruct(data.signatures);
  fund_tx_id_ = data.fund_tx_id;
  fund_vout_ = data.fund_vout;
  local_fund_pubkey_ = data.local_fund_pubkey;
  remote_fund_pubkey_ = data.remote_fund_pubkey;
  ignore_items = data.ignore_items;
}

AddSignaturesToRefundTxRequestStruct AddSignaturesToRefundTxRequest::ConvertToStruct() const {  // NOLINT
  AddSignaturesToRefundTxRequestStruct result;
  result.refund_tx_hex = refund_tx_hex_;
  result.signatures = signatures_.ConvertToStruct();
  result.fund_tx_id = fund_tx_id_;
  result.fund_vout = fund_vout_;
  result.local_fund_pubkey = local_fund_pubkey_;
  result.remote_fund_pubkey = remote_fund_pubkey_;
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
    CreateCetRequest::GetLocalFundPubkeyString,
    CreateCetRequest::SetLocalFundPubkeyString,
    CreateCetRequest::GetLocalFundPubkeyFieldType,
  };
  json_mapper.emplace("localFundPubkey", func_table);
  item_list.push_back("localFundPubkey");
  func_table = {
    CreateCetRequest::GetLocalSweepPubkeyString,
    CreateCetRequest::SetLocalSweepPubkeyString,
    CreateCetRequest::GetLocalSweepPubkeyFieldType,
  };
  json_mapper.emplace("localSweepPubkey", func_table);
  item_list.push_back("localSweepPubkey");
  func_table = {
    CreateCetRequest::GetRemoteSweepPubkeyString,
    CreateCetRequest::SetRemoteSweepPubkeyString,
    CreateCetRequest::GetRemoteSweepPubkeyFieldType,
  };
  json_mapper.emplace("remoteSweepPubkey", func_table);
  item_list.push_back("remoteSweepPubkey");
  func_table = {
    CreateCetRequest::GetRemoteFinalAddressString,
    CreateCetRequest::SetRemoteFinalAddressString,
    CreateCetRequest::GetRemoteFinalAddressFieldType,
  };
  json_mapper.emplace("remoteFinalAddress", func_table);
  item_list.push_back("remoteFinalAddress");
  func_table = {
    CreateCetRequest::GetOraclePubkeyString,
    CreateCetRequest::SetOraclePubkeyString,
    CreateCetRequest::GetOraclePubkeyFieldType,
  };
  json_mapper.emplace("oraclePubkey", func_table);
  item_list.push_back("oraclePubkey");
  func_table = {
    CreateCetRequest::GetOracleRPointsString,
    CreateCetRequest::SetOracleRPointsString,
    CreateCetRequest::GetOracleRPointsFieldType,
  };
  json_mapper.emplace("oracleRPoints", func_table);
  item_list.push_back("oracleRPoints");
  func_table = {
    CreateCetRequest::GetMessagesString,
    CreateCetRequest::SetMessagesString,
    CreateCetRequest::GetMessagesFieldType,
  };
  json_mapper.emplace("messages", func_table);
  item_list.push_back("messages");
  func_table = {
    CreateCetRequest::GetCsvDelayString,
    CreateCetRequest::SetCsvDelayString,
    CreateCetRequest::GetCsvDelayFieldType,
  };
  json_mapper.emplace("csvDelay", func_table);
  item_list.push_back("csvDelay");
  func_table = {
    CreateCetRequest::GetLocalPayoutString,
    CreateCetRequest::SetLocalPayoutString,
    CreateCetRequest::GetLocalPayoutFieldType,
  };
  json_mapper.emplace("localPayout", func_table);
  item_list.push_back("localPayout");
  func_table = {
    CreateCetRequest::GetRemotePayoutString,
    CreateCetRequest::SetRemotePayoutString,
    CreateCetRequest::GetRemotePayoutFieldType,
  };
  json_mapper.emplace("remotePayout", func_table);
  item_list.push_back("remotePayout");
  func_table = {
    CreateCetRequest::GetFeeRateString,
    CreateCetRequest::SetFeeRateString,
    CreateCetRequest::GetFeeRateFieldType,
  };
  json_mapper.emplace("feeRate", func_table);
  item_list.push_back("feeRate");
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
    CreateCetRequest::GetMaturityTimeString,
    CreateCetRequest::SetMaturityTimeString,
    CreateCetRequest::GetMaturityTimeFieldType,
  };
  json_mapper.emplace("maturityTime", func_table);
  item_list.push_back("maturityTime");
}

void CreateCetRequest::ConvertFromStruct(
    const CreateCetRequestStruct& data) {
  local_fund_pubkey_ = data.local_fund_pubkey;
  local_sweep_pubkey_ = data.local_sweep_pubkey;
  remote_sweep_pubkey_ = data.remote_sweep_pubkey;
  remote_final_address_ = data.remote_final_address;
  oracle_pubkey_ = data.oracle_pubkey;
  oracle_r_points_.ConvertFromStruct(data.oracle_r_points);
  messages_.ConvertFromStruct(data.messages);
  csv_delay_ = data.csv_delay;
  local_payout_ = data.local_payout;
  remote_payout_ = data.remote_payout;
  fee_rate_ = data.fee_rate;
  fund_tx_id_ = data.fund_tx_id;
  fund_vout_ = data.fund_vout;
  maturity_time_ = data.maturity_time;
  ignore_items = data.ignore_items;
}

CreateCetRequestStruct CreateCetRequest::ConvertToStruct() const {  // NOLINT
  CreateCetRequestStruct result;
  result.local_fund_pubkey = local_fund_pubkey_;
  result.local_sweep_pubkey = local_sweep_pubkey_;
  result.remote_sweep_pubkey = remote_sweep_pubkey_;
  result.remote_final_address = remote_final_address_;
  result.oracle_pubkey = oracle_pubkey_;
  result.oracle_r_points = oracle_r_points_.ConvertToStruct();
  result.messages = messages_.ConvertToStruct();
  result.csv_delay = csv_delay_;
  result.local_payout = local_payout_;
  result.remote_payout = remote_payout_;
  result.fee_rate = fee_rate_;
  result.fund_tx_id = fund_tx_id_;
  result.fund_vout = fund_vout_;
  result.maturity_time = maturity_time_;
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
// CreateClosingTransactionRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateClosingTransactionRequest>
  CreateClosingTransactionRequest::json_mapper;
std::vector<std::string> CreateClosingTransactionRequest::item_list;

void CreateClosingTransactionRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateClosingTransactionRequest> func_table;  // NOLINT

  func_table = {
    CreateClosingTransactionRequest::GetAddressString,
    CreateClosingTransactionRequest::SetAddressString,
    CreateClosingTransactionRequest::GetAddressFieldType,
  };
  json_mapper.emplace("address", func_table);
  item_list.push_back("address");
  func_table = {
    CreateClosingTransactionRequest::GetAmountString,
    CreateClosingTransactionRequest::SetAmountString,
    CreateClosingTransactionRequest::GetAmountFieldType,
  };
  json_mapper.emplace("amount", func_table);
  item_list.push_back("amount");
  func_table = {
    CreateClosingTransactionRequest::GetCetTxIdString,
    CreateClosingTransactionRequest::SetCetTxIdString,
    CreateClosingTransactionRequest::GetCetTxIdFieldType,
  };
  json_mapper.emplace("cetTxId", func_table);
  item_list.push_back("cetTxId");
  func_table = {
    CreateClosingTransactionRequest::GetCetVoutString,
    CreateClosingTransactionRequest::SetCetVoutString,
    CreateClosingTransactionRequest::GetCetVoutFieldType,
  };
  json_mapper.emplace("cetVout", func_table);
  item_list.push_back("cetVout");
}

void CreateClosingTransactionRequest::ConvertFromStruct(
    const CreateClosingTransactionRequestStruct& data) {
  address_ = data.address;
  amount_ = data.amount;
  cet_tx_id_ = data.cet_tx_id;
  cet_vout_ = data.cet_vout;
  ignore_items = data.ignore_items;
}

CreateClosingTransactionRequestStruct CreateClosingTransactionRequest::ConvertToStruct() const {  // NOLINT
  CreateClosingTransactionRequestStruct result;
  result.address = address_;
  result.amount = amount_;
  result.cet_tx_id = cet_tx_id_;
  result.cet_vout = cet_vout_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateClosingTransactionResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateClosingTransactionResponse>
  CreateClosingTransactionResponse::json_mapper;
std::vector<std::string> CreateClosingTransactionResponse::item_list;

void CreateClosingTransactionResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateClosingTransactionResponse> func_table;  // NOLINT

  func_table = {
    CreateClosingTransactionResponse::GetHexString,
    CreateClosingTransactionResponse::SetHexString,
    CreateClosingTransactionResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
}

void CreateClosingTransactionResponse::ConvertFromStruct(
    const CreateClosingTransactionResponseStruct& data) {
  hex_ = data.hex;
  ignore_items = data.ignore_items;
}

CreateClosingTransactionResponseStruct CreateClosingTransactionResponse::ConvertToStruct() const {  // NOLINT
  CreateClosingTransactionResponseStruct result;
  result.hex = hex_;
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
    PayoutRequest::GetLocalString,
    PayoutRequest::SetLocalString,
    PayoutRequest::GetLocalFieldType,
  };
  json_mapper.emplace("local", func_table);
  item_list.push_back("local");
  func_table = {
    PayoutRequest::GetRemoteString,
    PayoutRequest::SetRemoteString,
    PayoutRequest::GetRemoteFieldType,
  };
  json_mapper.emplace("remote", func_table);
  item_list.push_back("remote");
  func_table = {
    PayoutRequest::GetMessagesString,
    PayoutRequest::SetMessagesString,
    PayoutRequest::GetMessagesFieldType,
  };
  json_mapper.emplace("messages", func_table);
  item_list.push_back("messages");
}

void PayoutRequest::ConvertFromStruct(
    const PayoutRequestStruct& data) {
  local_ = data.local;
  remote_ = data.remote;
  messages_.ConvertFromStruct(data.messages);
  ignore_items = data.ignore_items;
}

PayoutRequestStruct PayoutRequest::ConvertToStruct() const {  // NOLINT
  PayoutRequestStruct result;
  result.local = local_;
  result.remote = remote_;
  result.messages = messages_.ConvertToStruct();
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
    CreateDlcTransactionsRequest::GetOutcomesString,
    CreateDlcTransactionsRequest::SetOutcomesString,
    CreateDlcTransactionsRequest::GetOutcomesFieldType,
  };
  json_mapper.emplace("outcomes", func_table);
  item_list.push_back("outcomes");
  func_table = {
    CreateDlcTransactionsRequest::GetOracleRPointsString,
    CreateDlcTransactionsRequest::SetOracleRPointsString,
    CreateDlcTransactionsRequest::GetOracleRPointsFieldType,
  };
  json_mapper.emplace("oracleRPoints", func_table);
  item_list.push_back("oracleRPoints");
  func_table = {
    CreateDlcTransactionsRequest::GetOraclePubkeyString,
    CreateDlcTransactionsRequest::SetOraclePubkeyString,
    CreateDlcTransactionsRequest::GetOraclePubkeyFieldType,
  };
  json_mapper.emplace("oraclePubkey", func_table);
  item_list.push_back("oraclePubkey");
  func_table = {
    CreateDlcTransactionsRequest::GetLocalFundPubkeyString,
    CreateDlcTransactionsRequest::SetLocalFundPubkeyString,
    CreateDlcTransactionsRequest::GetLocalFundPubkeyFieldType,
  };
  json_mapper.emplace("localFundPubkey", func_table);
  item_list.push_back("localFundPubkey");
  func_table = {
    CreateDlcTransactionsRequest::GetLocalSweepPubkeyString,
    CreateDlcTransactionsRequest::SetLocalSweepPubkeyString,
    CreateDlcTransactionsRequest::GetLocalSweepPubkeyFieldType,
  };
  json_mapper.emplace("localSweepPubkey", func_table);
  item_list.push_back("localSweepPubkey");
  func_table = {
    CreateDlcTransactionsRequest::GetLocalFinalAddressString,
    CreateDlcTransactionsRequest::SetLocalFinalAddressString,
    CreateDlcTransactionsRequest::GetLocalFinalAddressFieldType,
  };
  json_mapper.emplace("localFinalAddress", func_table);
  item_list.push_back("localFinalAddress");
  func_table = {
    CreateDlcTransactionsRequest::GetRemoteFundPubkeyString,
    CreateDlcTransactionsRequest::SetRemoteFundPubkeyString,
    CreateDlcTransactionsRequest::GetRemoteFundPubkeyFieldType,
  };
  json_mapper.emplace("remoteFundPubkey", func_table);
  item_list.push_back("remoteFundPubkey");
  func_table = {
    CreateDlcTransactionsRequest::GetRemoteSweepPubkeyString,
    CreateDlcTransactionsRequest::SetRemoteSweepPubkeyString,
    CreateDlcTransactionsRequest::GetRemoteSweepPubkeyFieldType,
  };
  json_mapper.emplace("remoteSweepPubkey", func_table);
  item_list.push_back("remoteSweepPubkey");
  func_table = {
    CreateDlcTransactionsRequest::GetRemoteFinalAddressString,
    CreateDlcTransactionsRequest::SetRemoteFinalAddressString,
    CreateDlcTransactionsRequest::GetRemoteFinalAddressFieldType,
  };
  json_mapper.emplace("remoteFinalAddress", func_table);
  item_list.push_back("remoteFinalAddress");
  func_table = {
    CreateDlcTransactionsRequest::GetLocalInputAmountString,
    CreateDlcTransactionsRequest::SetLocalInputAmountString,
    CreateDlcTransactionsRequest::GetLocalInputAmountFieldType,
  };
  json_mapper.emplace("localInputAmount", func_table);
  item_list.push_back("localInputAmount");
  func_table = {
    CreateDlcTransactionsRequest::GetLocalCollateralAmountString,
    CreateDlcTransactionsRequest::SetLocalCollateralAmountString,
    CreateDlcTransactionsRequest::GetLocalCollateralAmountFieldType,
  };
  json_mapper.emplace("localCollateralAmount", func_table);
  item_list.push_back("localCollateralAmount");
  func_table = {
    CreateDlcTransactionsRequest::GetRemoteInputAmountString,
    CreateDlcTransactionsRequest::SetRemoteInputAmountString,
    CreateDlcTransactionsRequest::GetRemoteInputAmountFieldType,
  };
  json_mapper.emplace("remoteInputAmount", func_table);
  item_list.push_back("remoteInputAmount");
  func_table = {
    CreateDlcTransactionsRequest::GetRemoteCollateralAmountString,
    CreateDlcTransactionsRequest::SetRemoteCollateralAmountString,
    CreateDlcTransactionsRequest::GetRemoteCollateralAmountFieldType,
  };
  json_mapper.emplace("remoteCollateralAmount", func_table);
  item_list.push_back("remoteCollateralAmount");
  func_table = {
    CreateDlcTransactionsRequest::GetCsvDelayString,
    CreateDlcTransactionsRequest::SetCsvDelayString,
    CreateDlcTransactionsRequest::GetCsvDelayFieldType,
  };
  json_mapper.emplace("csvDelay", func_table);
  item_list.push_back("csvDelay");
  func_table = {
    CreateDlcTransactionsRequest::GetRefundLocktimeString,
    CreateDlcTransactionsRequest::SetRefundLocktimeString,
    CreateDlcTransactionsRequest::GetRefundLocktimeFieldType,
  };
  json_mapper.emplace("refundLocktime", func_table);
  item_list.push_back("refundLocktime");
  func_table = {
    CreateDlcTransactionsRequest::GetLocalInputsString,
    CreateDlcTransactionsRequest::SetLocalInputsString,
    CreateDlcTransactionsRequest::GetLocalInputsFieldType,
  };
  json_mapper.emplace("localInputs", func_table);
  item_list.push_back("localInputs");
  func_table = {
    CreateDlcTransactionsRequest::GetLocalChangeAddressString,
    CreateDlcTransactionsRequest::SetLocalChangeAddressString,
    CreateDlcTransactionsRequest::GetLocalChangeAddressFieldType,
  };
  json_mapper.emplace("localChangeAddress", func_table);
  item_list.push_back("localChangeAddress");
  func_table = {
    CreateDlcTransactionsRequest::GetRemoteInputsString,
    CreateDlcTransactionsRequest::SetRemoteInputsString,
    CreateDlcTransactionsRequest::GetRemoteInputsFieldType,
  };
  json_mapper.emplace("remoteInputs", func_table);
  item_list.push_back("remoteInputs");
  func_table = {
    CreateDlcTransactionsRequest::GetRemoteChangeAddressString,
    CreateDlcTransactionsRequest::SetRemoteChangeAddressString,
    CreateDlcTransactionsRequest::GetRemoteChangeAddressFieldType,
  };
  json_mapper.emplace("remoteChangeAddress", func_table);
  item_list.push_back("remoteChangeAddress");
  func_table = {
    CreateDlcTransactionsRequest::GetFeeRateString,
    CreateDlcTransactionsRequest::SetFeeRateString,
    CreateDlcTransactionsRequest::GetFeeRateFieldType,
  };
  json_mapper.emplace("feeRate", func_table);
  item_list.push_back("feeRate");
  func_table = {
    CreateDlcTransactionsRequest::GetMaturityTimeString,
    CreateDlcTransactionsRequest::SetMaturityTimeString,
    CreateDlcTransactionsRequest::GetMaturityTimeFieldType,
  };
  json_mapper.emplace("maturityTime", func_table);
  item_list.push_back("maturityTime");
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
  outcomes_.ConvertFromStruct(data.outcomes);
  oracle_r_points_.ConvertFromStruct(data.oracle_r_points);
  oracle_pubkey_ = data.oracle_pubkey;
  local_fund_pubkey_ = data.local_fund_pubkey;
  local_sweep_pubkey_ = data.local_sweep_pubkey;
  local_final_address_ = data.local_final_address;
  remote_fund_pubkey_ = data.remote_fund_pubkey;
  remote_sweep_pubkey_ = data.remote_sweep_pubkey;
  remote_final_address_ = data.remote_final_address;
  local_input_amount_ = data.local_input_amount;
  local_collateral_amount_ = data.local_collateral_amount;
  remote_input_amount_ = data.remote_input_amount;
  remote_collateral_amount_ = data.remote_collateral_amount;
  csv_delay_ = data.csv_delay;
  refund_locktime_ = data.refund_locktime;
  local_inputs_.ConvertFromStruct(data.local_inputs);
  local_change_address_ = data.local_change_address;
  remote_inputs_.ConvertFromStruct(data.remote_inputs);
  remote_change_address_ = data.remote_change_address;
  fee_rate_ = data.fee_rate;
  maturity_time_ = data.maturity_time;
  option_dest_ = data.option_dest;
  option_premium_ = data.option_premium;
  ignore_items = data.ignore_items;
}

CreateDlcTransactionsRequestStruct CreateDlcTransactionsRequest::ConvertToStruct() const {  // NOLINT
  CreateDlcTransactionsRequestStruct result;
  result.outcomes = outcomes_.ConvertToStruct();
  result.oracle_r_points = oracle_r_points_.ConvertToStruct();
  result.oracle_pubkey = oracle_pubkey_;
  result.local_fund_pubkey = local_fund_pubkey_;
  result.local_sweep_pubkey = local_sweep_pubkey_;
  result.local_final_address = local_final_address_;
  result.remote_fund_pubkey = remote_fund_pubkey_;
  result.remote_sweep_pubkey = remote_sweep_pubkey_;
  result.remote_final_address = remote_final_address_;
  result.local_input_amount = local_input_amount_;
  result.local_collateral_amount = local_collateral_amount_;
  result.remote_input_amount = remote_input_amount_;
  result.remote_collateral_amount = remote_collateral_amount_;
  result.csv_delay = csv_delay_;
  result.refund_locktime = refund_locktime_;
  result.local_inputs = local_inputs_.ConvertToStruct();
  result.local_change_address = local_change_address_;
  result.remote_inputs = remote_inputs_.ConvertToStruct();
  result.remote_change_address = remote_change_address_;
  result.fee_rate = fee_rate_;
  result.maturity_time = maturity_time_;
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
    CreateDlcTransactionsResponse::GetLocalCetsHexString,
    CreateDlcTransactionsResponse::SetLocalCetsHexString,
    CreateDlcTransactionsResponse::GetLocalCetsHexFieldType,
  };
  json_mapper.emplace("localCetsHex", func_table);
  item_list.push_back("localCetsHex");
  func_table = {
    CreateDlcTransactionsResponse::GetRemoteCetsHexString,
    CreateDlcTransactionsResponse::SetRemoteCetsHexString,
    CreateDlcTransactionsResponse::GetRemoteCetsHexFieldType,
  };
  json_mapper.emplace("remoteCetsHex", func_table);
  item_list.push_back("remoteCetsHex");
  func_table = {
    CreateDlcTransactionsResponse::GetRefundTxHexString,
    CreateDlcTransactionsResponse::SetRefundTxHexString,
    CreateDlcTransactionsResponse::GetRefundTxHexFieldType,
  };
  json_mapper.emplace("refundTxHex", func_table);
  item_list.push_back("refundTxHex");
}

void CreateDlcTransactionsResponse::ConvertFromStruct(
    const CreateDlcTransactionsResponseStruct& data) {
  fund_tx_hex_ = data.fund_tx_hex;
  local_cets_hex_.ConvertFromStruct(data.local_cets_hex);
  remote_cets_hex_.ConvertFromStruct(data.remote_cets_hex);
  refund_tx_hex_ = data.refund_tx_hex;
  ignore_items = data.ignore_items;
}

CreateDlcTransactionsResponseStruct CreateDlcTransactionsResponse::ConvertToStruct() const {  // NOLINT
  CreateDlcTransactionsResponseStruct result;
  result.fund_tx_hex = fund_tx_hex_;
  result.local_cets_hex = local_cets_hex_.ConvertToStruct();
  result.remote_cets_hex = remote_cets_hex_.ConvertToStruct();
  result.refund_tx_hex = refund_tx_hex_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// TxOutRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<TxOutRequest>
  TxOutRequest::json_mapper;
std::vector<std::string> TxOutRequest::item_list;

void TxOutRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<TxOutRequest> func_table;  // NOLINT

  func_table = {
    TxOutRequest::GetAmountString,
    TxOutRequest::SetAmountString,
    TxOutRequest::GetAmountFieldType,
  };
  json_mapper.emplace("amount", func_table);
  item_list.push_back("amount");
  func_table = {
    TxOutRequest::GetAddressString,
    TxOutRequest::SetAddressString,
    TxOutRequest::GetAddressFieldType,
  };
  json_mapper.emplace("address", func_table);
  item_list.push_back("address");
}

void TxOutRequest::ConvertFromStruct(
    const TxOutRequestStruct& data) {
  amount_ = data.amount;
  address_ = data.address;
  ignore_items = data.ignore_items;
}

TxOutRequestStruct TxOutRequest::ConvertToStruct() const {  // NOLINT
  TxOutRequestStruct result;
  result.amount = amount_;
  result.address = address_;
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
    CreateFundTransactionRequest::GetLocalPubkeyString,
    CreateFundTransactionRequest::SetLocalPubkeyString,
    CreateFundTransactionRequest::GetLocalPubkeyFieldType,
  };
  json_mapper.emplace("localPubkey", func_table);
  item_list.push_back("localPubkey");
  func_table = {
    CreateFundTransactionRequest::GetRemotePubkeyString,
    CreateFundTransactionRequest::SetRemotePubkeyString,
    CreateFundTransactionRequest::GetRemotePubkeyFieldType,
  };
  json_mapper.emplace("remotePubkey", func_table);
  item_list.push_back("remotePubkey");
  func_table = {
    CreateFundTransactionRequest::GetOutputAmountString,
    CreateFundTransactionRequest::SetOutputAmountString,
    CreateFundTransactionRequest::GetOutputAmountFieldType,
  };
  json_mapper.emplace("outputAmount", func_table);
  item_list.push_back("outputAmount");
  func_table = {
    CreateFundTransactionRequest::GetLocalInputsString,
    CreateFundTransactionRequest::SetLocalInputsString,
    CreateFundTransactionRequest::GetLocalInputsFieldType,
  };
  json_mapper.emplace("localInputs", func_table);
  item_list.push_back("localInputs");
  func_table = {
    CreateFundTransactionRequest::GetLocalChangeString,
    CreateFundTransactionRequest::SetLocalChangeString,
    CreateFundTransactionRequest::GetLocalChangeFieldType,
  };
  json_mapper.emplace("localChange", func_table);
  item_list.push_back("localChange");
  func_table = {
    CreateFundTransactionRequest::GetRemoteInputsString,
    CreateFundTransactionRequest::SetRemoteInputsString,
    CreateFundTransactionRequest::GetRemoteInputsFieldType,
  };
  json_mapper.emplace("remoteInputs", func_table);
  item_list.push_back("remoteInputs");
  func_table = {
    CreateFundTransactionRequest::GetRemoteChangeString,
    CreateFundTransactionRequest::SetRemoteChangeString,
    CreateFundTransactionRequest::GetRemoteChangeFieldType,
  };
  json_mapper.emplace("remoteChange", func_table);
  item_list.push_back("remoteChange");
  func_table = {
    CreateFundTransactionRequest::GetFeeRateString,
    CreateFundTransactionRequest::SetFeeRateString,
    CreateFundTransactionRequest::GetFeeRateFieldType,
  };
  json_mapper.emplace("feeRate", func_table);
  item_list.push_back("feeRate");
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
  local_pubkey_ = data.local_pubkey;
  remote_pubkey_ = data.remote_pubkey;
  output_amount_ = data.output_amount;
  local_inputs_.ConvertFromStruct(data.local_inputs);
  local_change_.ConvertFromStruct(data.local_change);
  remote_inputs_.ConvertFromStruct(data.remote_inputs);
  remote_change_.ConvertFromStruct(data.remote_change);
  fee_rate_ = data.fee_rate;
  option_dest_ = data.option_dest;
  option_premium_ = data.option_premium;
  ignore_items = data.ignore_items;
}

CreateFundTransactionRequestStruct CreateFundTransactionRequest::ConvertToStruct() const {  // NOLINT
  CreateFundTransactionRequestStruct result;
  result.local_pubkey = local_pubkey_;
  result.remote_pubkey = remote_pubkey_;
  result.output_amount = output_amount_;
  result.local_inputs = local_inputs_.ConvertToStruct();
  result.local_change = local_change_.ConvertToStruct();
  result.remote_inputs = remote_inputs_.ConvertToStruct();
  result.remote_change = remote_change_.ConvertToStruct();
  result.fee_rate = fee_rate_;
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
// CreateMutualClosingTransactionRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateMutualClosingTransactionRequest>
  CreateMutualClosingTransactionRequest::json_mapper;
std::vector<std::string> CreateMutualClosingTransactionRequest::item_list;

void CreateMutualClosingTransactionRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateMutualClosingTransactionRequest> func_table;  // NOLINT

  func_table = {
    CreateMutualClosingTransactionRequest::GetLocalFinalAddressString,
    CreateMutualClosingTransactionRequest::SetLocalFinalAddressString,
    CreateMutualClosingTransactionRequest::GetLocalFinalAddressFieldType,
  };
  json_mapper.emplace("localFinalAddress", func_table);
  item_list.push_back("localFinalAddress");
  func_table = {
    CreateMutualClosingTransactionRequest::GetRemoteFinalAddressString,
    CreateMutualClosingTransactionRequest::SetRemoteFinalAddressString,
    CreateMutualClosingTransactionRequest::GetRemoteFinalAddressFieldType,
  };
  json_mapper.emplace("remoteFinalAddress", func_table);
  item_list.push_back("remoteFinalAddress");
  func_table = {
    CreateMutualClosingTransactionRequest::GetLocalAmountString,
    CreateMutualClosingTransactionRequest::SetLocalAmountString,
    CreateMutualClosingTransactionRequest::GetLocalAmountFieldType,
  };
  json_mapper.emplace("localAmount", func_table);
  item_list.push_back("localAmount");
  func_table = {
    CreateMutualClosingTransactionRequest::GetRemoteAmountString,
    CreateMutualClosingTransactionRequest::SetRemoteAmountString,
    CreateMutualClosingTransactionRequest::GetRemoteAmountFieldType,
  };
  json_mapper.emplace("remoteAmount", func_table);
  item_list.push_back("remoteAmount");
  func_table = {
    CreateMutualClosingTransactionRequest::GetFeeRateString,
    CreateMutualClosingTransactionRequest::SetFeeRateString,
    CreateMutualClosingTransactionRequest::GetFeeRateFieldType,
  };
  json_mapper.emplace("feeRate", func_table);
  item_list.push_back("feeRate");
  func_table = {
    CreateMutualClosingTransactionRequest::GetFundTxIdString,
    CreateMutualClosingTransactionRequest::SetFundTxIdString,
    CreateMutualClosingTransactionRequest::GetFundTxIdFieldType,
  };
  json_mapper.emplace("fundTxId", func_table);
  item_list.push_back("fundTxId");
  func_table = {
    CreateMutualClosingTransactionRequest::GetFundVoutString,
    CreateMutualClosingTransactionRequest::SetFundVoutString,
    CreateMutualClosingTransactionRequest::GetFundVoutFieldType,
  };
  json_mapper.emplace("fundVout", func_table);
  item_list.push_back("fundVout");
}

void CreateMutualClosingTransactionRequest::ConvertFromStruct(
    const CreateMutualClosingTransactionRequestStruct& data) {
  local_final_address_ = data.local_final_address;
  remote_final_address_ = data.remote_final_address;
  local_amount_ = data.local_amount;
  remote_amount_ = data.remote_amount;
  fee_rate_ = data.fee_rate;
  fund_tx_id_ = data.fund_tx_id;
  fund_vout_ = data.fund_vout;
  ignore_items = data.ignore_items;
}

CreateMutualClosingTransactionRequestStruct CreateMutualClosingTransactionRequest::ConvertToStruct() const {  // NOLINT
  CreateMutualClosingTransactionRequestStruct result;
  result.local_final_address = local_final_address_;
  result.remote_final_address = remote_final_address_;
  result.local_amount = local_amount_;
  result.remote_amount = remote_amount_;
  result.fee_rate = fee_rate_;
  result.fund_tx_id = fund_tx_id_;
  result.fund_vout = fund_vout_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateMutualClosingTransactionResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateMutualClosingTransactionResponse>
  CreateMutualClosingTransactionResponse::json_mapper;
std::vector<std::string> CreateMutualClosingTransactionResponse::item_list;

void CreateMutualClosingTransactionResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateMutualClosingTransactionResponse> func_table;  // NOLINT

  func_table = {
    CreateMutualClosingTransactionResponse::GetHexString,
    CreateMutualClosingTransactionResponse::SetHexString,
    CreateMutualClosingTransactionResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
}

void CreateMutualClosingTransactionResponse::ConvertFromStruct(
    const CreateMutualClosingTransactionResponseStruct& data) {
  hex_ = data.hex;
  ignore_items = data.ignore_items;
}

CreateMutualClosingTransactionResponseStruct CreateMutualClosingTransactionResponse::ConvertToStruct() const {  // NOLINT
  CreateMutualClosingTransactionResponseStruct result;
  result.hex = hex_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreatePenaltyTransactionRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreatePenaltyTransactionRequest>
  CreatePenaltyTransactionRequest::json_mapper;
std::vector<std::string> CreatePenaltyTransactionRequest::item_list;

void CreatePenaltyTransactionRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreatePenaltyTransactionRequest> func_table;  // NOLINT

  func_table = {
    CreatePenaltyTransactionRequest::GetFinalAddressString,
    CreatePenaltyTransactionRequest::SetFinalAddressString,
    CreatePenaltyTransactionRequest::GetFinalAddressFieldType,
  };
  json_mapper.emplace("finalAddress", func_table);
  item_list.push_back("finalAddress");
  func_table = {
    CreatePenaltyTransactionRequest::GetAmountString,
    CreatePenaltyTransactionRequest::SetAmountString,
    CreatePenaltyTransactionRequest::GetAmountFieldType,
  };
  json_mapper.emplace("amount", func_table);
  item_list.push_back("amount");
  func_table = {
    CreatePenaltyTransactionRequest::GetCetTxIdString,
    CreatePenaltyTransactionRequest::SetCetTxIdString,
    CreatePenaltyTransactionRequest::GetCetTxIdFieldType,
  };
  json_mapper.emplace("cetTxId", func_table);
  item_list.push_back("cetTxId");
  func_table = {
    CreatePenaltyTransactionRequest::GetCetVoutString,
    CreatePenaltyTransactionRequest::SetCetVoutString,
    CreatePenaltyTransactionRequest::GetCetVoutFieldType,
  };
  json_mapper.emplace("cetVout", func_table);
  item_list.push_back("cetVout");
}

void CreatePenaltyTransactionRequest::ConvertFromStruct(
    const CreatePenaltyTransactionRequestStruct& data) {
  final_address_ = data.final_address;
  amount_ = data.amount;
  cet_tx_id_ = data.cet_tx_id;
  cet_vout_ = data.cet_vout;
  ignore_items = data.ignore_items;
}

CreatePenaltyTransactionRequestStruct CreatePenaltyTransactionRequest::ConvertToStruct() const {  // NOLINT
  CreatePenaltyTransactionRequestStruct result;
  result.final_address = final_address_;
  result.amount = amount_;
  result.cet_tx_id = cet_tx_id_;
  result.cet_vout = cet_vout_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreatePenaltyTransactionResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreatePenaltyTransactionResponse>
  CreatePenaltyTransactionResponse::json_mapper;
std::vector<std::string> CreatePenaltyTransactionResponse::item_list;

void CreatePenaltyTransactionResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreatePenaltyTransactionResponse> func_table;  // NOLINT

  func_table = {
    CreatePenaltyTransactionResponse::GetHexString,
    CreatePenaltyTransactionResponse::SetHexString,
    CreatePenaltyTransactionResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
}

void CreatePenaltyTransactionResponse::ConvertFromStruct(
    const CreatePenaltyTransactionResponseStruct& data) {
  hex_ = data.hex;
  ignore_items = data.ignore_items;
}

CreatePenaltyTransactionResponseStruct CreatePenaltyTransactionResponse::ConvertToStruct() const {  // NOLINT
  CreatePenaltyTransactionResponseStruct result;
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
    CreateRefundTransactionRequest::GetLocalFinalAddressString,
    CreateRefundTransactionRequest::SetLocalFinalAddressString,
    CreateRefundTransactionRequest::GetLocalFinalAddressFieldType,
  };
  json_mapper.emplace("localFinalAddress", func_table);
  item_list.push_back("localFinalAddress");
  func_table = {
    CreateRefundTransactionRequest::GetRemoteFinalAddressString,
    CreateRefundTransactionRequest::SetRemoteFinalAddressString,
    CreateRefundTransactionRequest::GetRemoteFinalAddressFieldType,
  };
  json_mapper.emplace("remoteFinalAddress", func_table);
  item_list.push_back("remoteFinalAddress");
  func_table = {
    CreateRefundTransactionRequest::GetLocalAmountString,
    CreateRefundTransactionRequest::SetLocalAmountString,
    CreateRefundTransactionRequest::GetLocalAmountFieldType,
  };
  json_mapper.emplace("localAmount", func_table);
  item_list.push_back("localAmount");
  func_table = {
    CreateRefundTransactionRequest::GetRemoteAmountString,
    CreateRefundTransactionRequest::SetRemoteAmountString,
    CreateRefundTransactionRequest::GetRemoteAmountFieldType,
  };
  json_mapper.emplace("remoteAmount", func_table);
  item_list.push_back("remoteAmount");
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
  local_final_address_ = data.local_final_address;
  remote_final_address_ = data.remote_final_address;
  local_amount_ = data.local_amount;
  remote_amount_ = data.remote_amount;
  lock_time_ = data.lock_time;
  fund_tx_id_ = data.fund_tx_id;
  fund_vout_ = data.fund_vout;
  ignore_items = data.ignore_items;
}

CreateRefundTransactionRequestStruct CreateRefundTransactionRequest::ConvertToStruct() const {  // NOLINT
  CreateRefundTransactionRequestStruct result;
  result.local_final_address = local_final_address_;
  result.remote_final_address = remote_final_address_;
  result.local_amount = local_amount_;
  result.remote_amount = remote_amount_;
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
// GetRawCetSignatureRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetRawCetSignatureRequest>
  GetRawCetSignatureRequest::json_mapper;
std::vector<std::string> GetRawCetSignatureRequest::item_list;

void GetRawCetSignatureRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetRawCetSignatureRequest> func_table;  // NOLINT

  func_table = {
    GetRawCetSignatureRequest::GetCetHexString,
    GetRawCetSignatureRequest::SetCetHexString,
    GetRawCetSignatureRequest::GetCetHexFieldType,
  };
  json_mapper.emplace("cetHex", func_table);
  item_list.push_back("cetHex");
  func_table = {
    GetRawCetSignatureRequest::GetPrivkeyString,
    GetRawCetSignatureRequest::SetPrivkeyString,
    GetRawCetSignatureRequest::GetPrivkeyFieldType,
  };
  json_mapper.emplace("privkey", func_table);
  item_list.push_back("privkey");
  func_table = {
    GetRawCetSignatureRequest::GetFundTxIdString,
    GetRawCetSignatureRequest::SetFundTxIdString,
    GetRawCetSignatureRequest::GetFundTxIdFieldType,
  };
  json_mapper.emplace("fundTxId", func_table);
  item_list.push_back("fundTxId");
  func_table = {
    GetRawCetSignatureRequest::GetFundVoutString,
    GetRawCetSignatureRequest::SetFundVoutString,
    GetRawCetSignatureRequest::GetFundVoutFieldType,
  };
  json_mapper.emplace("fundVout", func_table);
  item_list.push_back("fundVout");
  func_table = {
    GetRawCetSignatureRequest::GetLocalFundPubkeyString,
    GetRawCetSignatureRequest::SetLocalFundPubkeyString,
    GetRawCetSignatureRequest::GetLocalFundPubkeyFieldType,
  };
  json_mapper.emplace("localFundPubkey", func_table);
  item_list.push_back("localFundPubkey");
  func_table = {
    GetRawCetSignatureRequest::GetRemoteFundPubkeyString,
    GetRawCetSignatureRequest::SetRemoteFundPubkeyString,
    GetRawCetSignatureRequest::GetRemoteFundPubkeyFieldType,
  };
  json_mapper.emplace("remoteFundPubkey", func_table);
  item_list.push_back("remoteFundPubkey");
  func_table = {
    GetRawCetSignatureRequest::GetFundInputAmountString,
    GetRawCetSignatureRequest::SetFundInputAmountString,
    GetRawCetSignatureRequest::GetFundInputAmountFieldType,
  };
  json_mapper.emplace("fundInputAmount", func_table);
  item_list.push_back("fundInputAmount");
}

void GetRawCetSignatureRequest::ConvertFromStruct(
    const GetRawCetSignatureRequestStruct& data) {
  cet_hex_ = data.cet_hex;
  privkey_ = data.privkey;
  fund_tx_id_ = data.fund_tx_id;
  fund_vout_ = data.fund_vout;
  local_fund_pubkey_ = data.local_fund_pubkey;
  remote_fund_pubkey_ = data.remote_fund_pubkey;
  fund_input_amount_ = data.fund_input_amount;
  ignore_items = data.ignore_items;
}

GetRawCetSignatureRequestStruct GetRawCetSignatureRequest::ConvertToStruct() const {  // NOLINT
  GetRawCetSignatureRequestStruct result;
  result.cet_hex = cet_hex_;
  result.privkey = privkey_;
  result.fund_tx_id = fund_tx_id_;
  result.fund_vout = fund_vout_;
  result.local_fund_pubkey = local_fund_pubkey_;
  result.remote_fund_pubkey = remote_fund_pubkey_;
  result.fund_input_amount = fund_input_amount_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// GetRawCetSignatureResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetRawCetSignatureResponse>
  GetRawCetSignatureResponse::json_mapper;
std::vector<std::string> GetRawCetSignatureResponse::item_list;

void GetRawCetSignatureResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetRawCetSignatureResponse> func_table;  // NOLINT

  func_table = {
    GetRawCetSignatureResponse::GetHexString,
    GetRawCetSignatureResponse::SetHexString,
    GetRawCetSignatureResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
}

void GetRawCetSignatureResponse::ConvertFromStruct(
    const GetRawCetSignatureResponseStruct& data) {
  hex_ = data.hex;
  ignore_items = data.ignore_items;
}

GetRawCetSignatureResponseStruct GetRawCetSignatureResponse::ConvertToStruct() const {  // NOLINT
  GetRawCetSignatureResponseStruct result;
  result.hex = hex_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// GetRawCetSignaturesRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetRawCetSignaturesRequest>
  GetRawCetSignaturesRequest::json_mapper;
std::vector<std::string> GetRawCetSignaturesRequest::item_list;

void GetRawCetSignaturesRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetRawCetSignaturesRequest> func_table;  // NOLINT

  func_table = {
    GetRawCetSignaturesRequest::GetCetsHexString,
    GetRawCetSignaturesRequest::SetCetsHexString,
    GetRawCetSignaturesRequest::GetCetsHexFieldType,
  };
  json_mapper.emplace("cetsHex", func_table);
  item_list.push_back("cetsHex");
  func_table = {
    GetRawCetSignaturesRequest::GetPrivkeyString,
    GetRawCetSignaturesRequest::SetPrivkeyString,
    GetRawCetSignaturesRequest::GetPrivkeyFieldType,
  };
  json_mapper.emplace("privkey", func_table);
  item_list.push_back("privkey");
  func_table = {
    GetRawCetSignaturesRequest::GetFundTxIdString,
    GetRawCetSignaturesRequest::SetFundTxIdString,
    GetRawCetSignaturesRequest::GetFundTxIdFieldType,
  };
  json_mapper.emplace("fundTxId", func_table);
  item_list.push_back("fundTxId");
  func_table = {
    GetRawCetSignaturesRequest::GetFundVoutString,
    GetRawCetSignaturesRequest::SetFundVoutString,
    GetRawCetSignaturesRequest::GetFundVoutFieldType,
  };
  json_mapper.emplace("fundVout", func_table);
  item_list.push_back("fundVout");
  func_table = {
    GetRawCetSignaturesRequest::GetLocalFundPubkeyString,
    GetRawCetSignaturesRequest::SetLocalFundPubkeyString,
    GetRawCetSignaturesRequest::GetLocalFundPubkeyFieldType,
  };
  json_mapper.emplace("localFundPubkey", func_table);
  item_list.push_back("localFundPubkey");
  func_table = {
    GetRawCetSignaturesRequest::GetRemoteFundPubkeyString,
    GetRawCetSignaturesRequest::SetRemoteFundPubkeyString,
    GetRawCetSignaturesRequest::GetRemoteFundPubkeyFieldType,
  };
  json_mapper.emplace("remoteFundPubkey", func_table);
  item_list.push_back("remoteFundPubkey");
  func_table = {
    GetRawCetSignaturesRequest::GetFundInputAmountString,
    GetRawCetSignaturesRequest::SetFundInputAmountString,
    GetRawCetSignaturesRequest::GetFundInputAmountFieldType,
  };
  json_mapper.emplace("fundInputAmount", func_table);
  item_list.push_back("fundInputAmount");
}

void GetRawCetSignaturesRequest::ConvertFromStruct(
    const GetRawCetSignaturesRequestStruct& data) {
  cets_hex_.ConvertFromStruct(data.cets_hex);
  privkey_ = data.privkey;
  fund_tx_id_ = data.fund_tx_id;
  fund_vout_ = data.fund_vout;
  local_fund_pubkey_ = data.local_fund_pubkey;
  remote_fund_pubkey_ = data.remote_fund_pubkey;
  fund_input_amount_ = data.fund_input_amount;
  ignore_items = data.ignore_items;
}

GetRawCetSignaturesRequestStruct GetRawCetSignaturesRequest::ConvertToStruct() const {  // NOLINT
  GetRawCetSignaturesRequestStruct result;
  result.cets_hex = cets_hex_.ConvertToStruct();
  result.privkey = privkey_;
  result.fund_tx_id = fund_tx_id_;
  result.fund_vout = fund_vout_;
  result.local_fund_pubkey = local_fund_pubkey_;
  result.remote_fund_pubkey = remote_fund_pubkey_;
  result.fund_input_amount = fund_input_amount_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// GetRawCetSignaturesResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetRawCetSignaturesResponse>
  GetRawCetSignaturesResponse::json_mapper;
std::vector<std::string> GetRawCetSignaturesResponse::item_list;

void GetRawCetSignaturesResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetRawCetSignaturesResponse> func_table;  // NOLINT

  func_table = {
    GetRawCetSignaturesResponse::GetHexString,
    GetRawCetSignaturesResponse::SetHexString,
    GetRawCetSignaturesResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
}

void GetRawCetSignaturesResponse::ConvertFromStruct(
    const GetRawCetSignaturesResponseStruct& data) {
  hex_.ConvertFromStruct(data.hex);
  ignore_items = data.ignore_items;
}

GetRawCetSignaturesResponseStruct GetRawCetSignaturesResponse::ConvertToStruct() const {  // NOLINT
  GetRawCetSignaturesResponseStruct result;
  result.hex = hex_.ConvertToStruct();
  result.ignore_items = ignore_items;
  return result;
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
// GetRawMutualClosingTxSignatureRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetRawMutualClosingTxSignatureRequest>
  GetRawMutualClosingTxSignatureRequest::json_mapper;
std::vector<std::string> GetRawMutualClosingTxSignatureRequest::item_list;

void GetRawMutualClosingTxSignatureRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetRawMutualClosingTxSignatureRequest> func_table;  // NOLINT

  func_table = {
    GetRawMutualClosingTxSignatureRequest::GetMutualClosingHexString,
    GetRawMutualClosingTxSignatureRequest::SetMutualClosingHexString,
    GetRawMutualClosingTxSignatureRequest::GetMutualClosingHexFieldType,
  };
  json_mapper.emplace("mutualClosingHex", func_table);
  item_list.push_back("mutualClosingHex");
  func_table = {
    GetRawMutualClosingTxSignatureRequest::GetPrivkeyString,
    GetRawMutualClosingTxSignatureRequest::SetPrivkeyString,
    GetRawMutualClosingTxSignatureRequest::GetPrivkeyFieldType,
  };
  json_mapper.emplace("privkey", func_table);
  item_list.push_back("privkey");
  func_table = {
    GetRawMutualClosingTxSignatureRequest::GetFundTxIdString,
    GetRawMutualClosingTxSignatureRequest::SetFundTxIdString,
    GetRawMutualClosingTxSignatureRequest::GetFundTxIdFieldType,
  };
  json_mapper.emplace("fundTxId", func_table);
  item_list.push_back("fundTxId");
  func_table = {
    GetRawMutualClosingTxSignatureRequest::GetFundVoutString,
    GetRawMutualClosingTxSignatureRequest::SetFundVoutString,
    GetRawMutualClosingTxSignatureRequest::GetFundVoutFieldType,
  };
  json_mapper.emplace("fundVout", func_table);
  item_list.push_back("fundVout");
  func_table = {
    GetRawMutualClosingTxSignatureRequest::GetLocalFundPubkeyString,
    GetRawMutualClosingTxSignatureRequest::SetLocalFundPubkeyString,
    GetRawMutualClosingTxSignatureRequest::GetLocalFundPubkeyFieldType,
  };
  json_mapper.emplace("localFundPubkey", func_table);
  item_list.push_back("localFundPubkey");
  func_table = {
    GetRawMutualClosingTxSignatureRequest::GetRemoteFundPubkeyString,
    GetRawMutualClosingTxSignatureRequest::SetRemoteFundPubkeyString,
    GetRawMutualClosingTxSignatureRequest::GetRemoteFundPubkeyFieldType,
  };
  json_mapper.emplace("remoteFundPubkey", func_table);
  item_list.push_back("remoteFundPubkey");
  func_table = {
    GetRawMutualClosingTxSignatureRequest::GetFundInputAmountString,
    GetRawMutualClosingTxSignatureRequest::SetFundInputAmountString,
    GetRawMutualClosingTxSignatureRequest::GetFundInputAmountFieldType,
  };
  json_mapper.emplace("fundInputAmount", func_table);
  item_list.push_back("fundInputAmount");
}

void GetRawMutualClosingTxSignatureRequest::ConvertFromStruct(
    const GetRawMutualClosingTxSignatureRequestStruct& data) {
  mutual_closing_hex_ = data.mutual_closing_hex;
  privkey_ = data.privkey;
  fund_tx_id_ = data.fund_tx_id;
  fund_vout_ = data.fund_vout;
  local_fund_pubkey_ = data.local_fund_pubkey;
  remote_fund_pubkey_ = data.remote_fund_pubkey;
  fund_input_amount_ = data.fund_input_amount;
  ignore_items = data.ignore_items;
}

GetRawMutualClosingTxSignatureRequestStruct GetRawMutualClosingTxSignatureRequest::ConvertToStruct() const {  // NOLINT
  GetRawMutualClosingTxSignatureRequestStruct result;
  result.mutual_closing_hex = mutual_closing_hex_;
  result.privkey = privkey_;
  result.fund_tx_id = fund_tx_id_;
  result.fund_vout = fund_vout_;
  result.local_fund_pubkey = local_fund_pubkey_;
  result.remote_fund_pubkey = remote_fund_pubkey_;
  result.fund_input_amount = fund_input_amount_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// GetRawMutualClosingTxSignatureResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetRawMutualClosingTxSignatureResponse>
  GetRawMutualClosingTxSignatureResponse::json_mapper;
std::vector<std::string> GetRawMutualClosingTxSignatureResponse::item_list;

void GetRawMutualClosingTxSignatureResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetRawMutualClosingTxSignatureResponse> func_table;  // NOLINT

  func_table = {
    GetRawMutualClosingTxSignatureResponse::GetHexString,
    GetRawMutualClosingTxSignatureResponse::SetHexString,
    GetRawMutualClosingTxSignatureResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
}

void GetRawMutualClosingTxSignatureResponse::ConvertFromStruct(
    const GetRawMutualClosingTxSignatureResponseStruct& data) {
  hex_ = data.hex;
  ignore_items = data.ignore_items;
}

GetRawMutualClosingTxSignatureResponseStruct GetRawMutualClosingTxSignatureResponse::ConvertToStruct() const {  // NOLINT
  GetRawMutualClosingTxSignatureResponseStruct result;
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
    GetRawRefundTxSignatureRequest::GetLocalFundPubkeyString,
    GetRawRefundTxSignatureRequest::SetLocalFundPubkeyString,
    GetRawRefundTxSignatureRequest::GetLocalFundPubkeyFieldType,
  };
  json_mapper.emplace("localFundPubkey", func_table);
  item_list.push_back("localFundPubkey");
  func_table = {
    GetRawRefundTxSignatureRequest::GetRemoteFundPubkeyString,
    GetRawRefundTxSignatureRequest::SetRemoteFundPubkeyString,
    GetRawRefundTxSignatureRequest::GetRemoteFundPubkeyFieldType,
  };
  json_mapper.emplace("remoteFundPubkey", func_table);
  item_list.push_back("remoteFundPubkey");
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
  local_fund_pubkey_ = data.local_fund_pubkey;
  remote_fund_pubkey_ = data.remote_fund_pubkey;
  fund_input_amount_ = data.fund_input_amount;
  ignore_items = data.ignore_items;
}

GetRawRefundTxSignatureRequestStruct GetRawRefundTxSignatureRequest::ConvertToStruct() const {  // NOLINT
  GetRawRefundTxSignatureRequestStruct result;
  result.refund_tx_hex = refund_tx_hex_;
  result.privkey = privkey_;
  result.fund_tx_id = fund_tx_id_;
  result.fund_vout = fund_vout_;
  result.local_fund_pubkey = local_fund_pubkey_;
  result.remote_fund_pubkey = remote_fund_pubkey_;
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
// GetSchnorrPublicNonceRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetSchnorrPublicNonceRequest>
  GetSchnorrPublicNonceRequest::json_mapper;
std::vector<std::string> GetSchnorrPublicNonceRequest::item_list;

void GetSchnorrPublicNonceRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetSchnorrPublicNonceRequest> func_table;  // NOLINT

  func_table = {
    GetSchnorrPublicNonceRequest::GetKValueString,
    GetSchnorrPublicNonceRequest::SetKValueString,
    GetSchnorrPublicNonceRequest::GetKValueFieldType,
  };
  json_mapper.emplace("kValue", func_table);
  item_list.push_back("kValue");
}

void GetSchnorrPublicNonceRequest::ConvertFromStruct(
    const GetSchnorrPublicNonceRequestStruct& data) {
  k_value_ = data.k_value;
  ignore_items = data.ignore_items;
}

GetSchnorrPublicNonceRequestStruct GetSchnorrPublicNonceRequest::ConvertToStruct() const {  // NOLINT
  GetSchnorrPublicNonceRequestStruct result;
  result.k_value = k_value_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// GetSchnorrPublicNonceResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<GetSchnorrPublicNonceResponse>
  GetSchnorrPublicNonceResponse::json_mapper;
std::vector<std::string> GetSchnorrPublicNonceResponse::item_list;

void GetSchnorrPublicNonceResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<GetSchnorrPublicNonceResponse> func_table;  // NOLINT

  func_table = {
    GetSchnorrPublicNonceResponse::GetHexString,
    GetSchnorrPublicNonceResponse::SetHexString,
    GetSchnorrPublicNonceResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
}

void GetSchnorrPublicNonceResponse::ConvertFromStruct(
    const GetSchnorrPublicNonceResponseStruct& data) {
  hex_ = data.hex;
  ignore_items = data.ignore_items;
}

GetSchnorrPublicNonceResponseStruct GetSchnorrPublicNonceResponse::ConvertToStruct() const {  // NOLINT
  GetSchnorrPublicNonceResponseStruct result;
  result.hex = hex_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// SchnorrSignRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<SchnorrSignRequest>
  SchnorrSignRequest::json_mapper;
std::vector<std::string> SchnorrSignRequest::item_list;

void SchnorrSignRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<SchnorrSignRequest> func_table;  // NOLINT

  func_table = {
    SchnorrSignRequest::GetPrivkeyString,
    SchnorrSignRequest::SetPrivkeyString,
    SchnorrSignRequest::GetPrivkeyFieldType,
  };
  json_mapper.emplace("privkey", func_table);
  item_list.push_back("privkey");
  func_table = {
    SchnorrSignRequest::GetKValueString,
    SchnorrSignRequest::SetKValueString,
    SchnorrSignRequest::GetKValueFieldType,
  };
  json_mapper.emplace("kValue", func_table);
  item_list.push_back("kValue");
  func_table = {
    SchnorrSignRequest::GetMessageString,
    SchnorrSignRequest::SetMessageString,
    SchnorrSignRequest::GetMessageFieldType,
  };
  json_mapper.emplace("message", func_table);
  item_list.push_back("message");
}

void SchnorrSignRequest::ConvertFromStruct(
    const SchnorrSignRequestStruct& data) {
  privkey_ = data.privkey;
  k_value_ = data.k_value;
  message_ = data.message;
  ignore_items = data.ignore_items;
}

SchnorrSignRequestStruct SchnorrSignRequest::ConvertToStruct() const {  // NOLINT
  SchnorrSignRequestStruct result;
  result.privkey = privkey_;
  result.k_value = k_value_;
  result.message = message_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// SchnorrSignResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<SchnorrSignResponse>
  SchnorrSignResponse::json_mapper;
std::vector<std::string> SchnorrSignResponse::item_list;

void SchnorrSignResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<SchnorrSignResponse> func_table;  // NOLINT

  func_table = {
    SchnorrSignResponse::GetHexString,
    SchnorrSignResponse::SetHexString,
    SchnorrSignResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
}

void SchnorrSignResponse::ConvertFromStruct(
    const SchnorrSignResponseStruct& data) {
  hex_ = data.hex;
  ignore_items = data.ignore_items;
}

SchnorrSignResponseStruct SchnorrSignResponse::ConvertToStruct() const {  // NOLINT
  SchnorrSignResponseStruct result;
  result.hex = hex_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// SignClosingTransactionRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<SignClosingTransactionRequest>
  SignClosingTransactionRequest::json_mapper;
std::vector<std::string> SignClosingTransactionRequest::item_list;

void SignClosingTransactionRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<SignClosingTransactionRequest> func_table;  // NOLINT

  func_table = {
    SignClosingTransactionRequest::GetClosingTxHexString,
    SignClosingTransactionRequest::SetClosingTxHexString,
    SignClosingTransactionRequest::GetClosingTxHexFieldType,
  };
  json_mapper.emplace("closingTxHex", func_table);
  item_list.push_back("closingTxHex");
  func_table = {
    SignClosingTransactionRequest::GetLocalFundPrivkeyString,
    SignClosingTransactionRequest::SetLocalFundPrivkeyString,
    SignClosingTransactionRequest::GetLocalFundPrivkeyFieldType,
  };
  json_mapper.emplace("localFundPrivkey", func_table);
  item_list.push_back("localFundPrivkey");
  func_table = {
    SignClosingTransactionRequest::GetLocalSweepPubkeyString,
    SignClosingTransactionRequest::SetLocalSweepPubkeyString,
    SignClosingTransactionRequest::GetLocalSweepPubkeyFieldType,
  };
  json_mapper.emplace("localSweepPubkey", func_table);
  item_list.push_back("localSweepPubkey");
  func_table = {
    SignClosingTransactionRequest::GetRemoteSweepPubkeyString,
    SignClosingTransactionRequest::SetRemoteSweepPubkeyString,
    SignClosingTransactionRequest::GetRemoteSweepPubkeyFieldType,
  };
  json_mapper.emplace("remoteSweepPubkey", func_table);
  item_list.push_back("remoteSweepPubkey");
  func_table = {
    SignClosingTransactionRequest::GetOraclePubkeyString,
    SignClosingTransactionRequest::SetOraclePubkeyString,
    SignClosingTransactionRequest::GetOraclePubkeyFieldType,
  };
  json_mapper.emplace("oraclePubkey", func_table);
  item_list.push_back("oraclePubkey");
  func_table = {
    SignClosingTransactionRequest::GetOracleRPointsString,
    SignClosingTransactionRequest::SetOracleRPointsString,
    SignClosingTransactionRequest::GetOracleRPointsFieldType,
  };
  json_mapper.emplace("oracleRPoints", func_table);
  item_list.push_back("oracleRPoints");
  func_table = {
    SignClosingTransactionRequest::GetMessagesString,
    SignClosingTransactionRequest::SetMessagesString,
    SignClosingTransactionRequest::GetMessagesFieldType,
  };
  json_mapper.emplace("messages", func_table);
  item_list.push_back("messages");
  func_table = {
    SignClosingTransactionRequest::GetCsvDelayString,
    SignClosingTransactionRequest::SetCsvDelayString,
    SignClosingTransactionRequest::GetCsvDelayFieldType,
  };
  json_mapper.emplace("csvDelay", func_table);
  item_list.push_back("csvDelay");
  func_table = {
    SignClosingTransactionRequest::GetOracleSigsString,
    SignClosingTransactionRequest::SetOracleSigsString,
    SignClosingTransactionRequest::GetOracleSigsFieldType,
  };
  json_mapper.emplace("oracleSigs", func_table);
  item_list.push_back("oracleSigs");
  func_table = {
    SignClosingTransactionRequest::GetCetTxIdString,
    SignClosingTransactionRequest::SetCetTxIdString,
    SignClosingTransactionRequest::GetCetTxIdFieldType,
  };
  json_mapper.emplace("cetTxId", func_table);
  item_list.push_back("cetTxId");
  func_table = {
    SignClosingTransactionRequest::GetCetVoutString,
    SignClosingTransactionRequest::SetCetVoutString,
    SignClosingTransactionRequest::GetCetVoutFieldType,
  };
  json_mapper.emplace("cetVout", func_table);
  item_list.push_back("cetVout");
  func_table = {
    SignClosingTransactionRequest::GetAmountString,
    SignClosingTransactionRequest::SetAmountString,
    SignClosingTransactionRequest::GetAmountFieldType,
  };
  json_mapper.emplace("amount", func_table);
  item_list.push_back("amount");
}

void SignClosingTransactionRequest::ConvertFromStruct(
    const SignClosingTransactionRequestStruct& data) {
  closing_tx_hex_ = data.closing_tx_hex;
  local_fund_privkey_ = data.local_fund_privkey;
  local_sweep_pubkey_ = data.local_sweep_pubkey;
  remote_sweep_pubkey_ = data.remote_sweep_pubkey;
  oracle_pubkey_ = data.oracle_pubkey;
  oracle_r_points_.ConvertFromStruct(data.oracle_r_points);
  messages_.ConvertFromStruct(data.messages);
  csv_delay_ = data.csv_delay;
  oracle_sigs_.ConvertFromStruct(data.oracle_sigs);
  cet_tx_id_ = data.cet_tx_id;
  cet_vout_ = data.cet_vout;
  amount_ = data.amount;
  ignore_items = data.ignore_items;
}

SignClosingTransactionRequestStruct SignClosingTransactionRequest::ConvertToStruct() const {  // NOLINT
  SignClosingTransactionRequestStruct result;
  result.closing_tx_hex = closing_tx_hex_;
  result.local_fund_privkey = local_fund_privkey_;
  result.local_sweep_pubkey = local_sweep_pubkey_;
  result.remote_sweep_pubkey = remote_sweep_pubkey_;
  result.oracle_pubkey = oracle_pubkey_;
  result.oracle_r_points = oracle_r_points_.ConvertToStruct();
  result.messages = messages_.ConvertToStruct();
  result.csv_delay = csv_delay_;
  result.oracle_sigs = oracle_sigs_.ConvertToStruct();
  result.cet_tx_id = cet_tx_id_;
  result.cet_vout = cet_vout_;
  result.amount = amount_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// SignClosingTransactionResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<SignClosingTransactionResponse>
  SignClosingTransactionResponse::json_mapper;
std::vector<std::string> SignClosingTransactionResponse::item_list;

void SignClosingTransactionResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<SignClosingTransactionResponse> func_table;  // NOLINT

  func_table = {
    SignClosingTransactionResponse::GetHexString,
    SignClosingTransactionResponse::SetHexString,
    SignClosingTransactionResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
}

void SignClosingTransactionResponse::ConvertFromStruct(
    const SignClosingTransactionResponseStruct& data) {
  hex_ = data.hex;
  ignore_items = data.ignore_items;
}

SignClosingTransactionResponseStruct SignClosingTransactionResponse::ConvertToStruct() const {  // NOLINT
  SignClosingTransactionResponseStruct result;
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
// VerifyCetSignatureRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<VerifyCetSignatureRequest>
  VerifyCetSignatureRequest::json_mapper;
std::vector<std::string> VerifyCetSignatureRequest::item_list;

void VerifyCetSignatureRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<VerifyCetSignatureRequest> func_table;  // NOLINT

  func_table = {
    VerifyCetSignatureRequest::GetCetHexString,
    VerifyCetSignatureRequest::SetCetHexString,
    VerifyCetSignatureRequest::GetCetHexFieldType,
  };
  json_mapper.emplace("cetHex", func_table);
  item_list.push_back("cetHex");
  func_table = {
    VerifyCetSignatureRequest::GetSignatureString,
    VerifyCetSignatureRequest::SetSignatureString,
    VerifyCetSignatureRequest::GetSignatureFieldType,
  };
  json_mapper.emplace("signature", func_table);
  item_list.push_back("signature");
  func_table = {
    VerifyCetSignatureRequest::GetLocalFundPubkeyString,
    VerifyCetSignatureRequest::SetLocalFundPubkeyString,
    VerifyCetSignatureRequest::GetLocalFundPubkeyFieldType,
  };
  json_mapper.emplace("localFundPubkey", func_table);
  item_list.push_back("localFundPubkey");
  func_table = {
    VerifyCetSignatureRequest::GetRemoteFundPubkeyString,
    VerifyCetSignatureRequest::SetRemoteFundPubkeyString,
    VerifyCetSignatureRequest::GetRemoteFundPubkeyFieldType,
  };
  json_mapper.emplace("remoteFundPubkey", func_table);
  item_list.push_back("remoteFundPubkey");
  func_table = {
    VerifyCetSignatureRequest::GetFundTxIdString,
    VerifyCetSignatureRequest::SetFundTxIdString,
    VerifyCetSignatureRequest::GetFundTxIdFieldType,
  };
  json_mapper.emplace("fundTxId", func_table);
  item_list.push_back("fundTxId");
  func_table = {
    VerifyCetSignatureRequest::GetFundVoutString,
    VerifyCetSignatureRequest::SetFundVoutString,
    VerifyCetSignatureRequest::GetFundVoutFieldType,
  };
  json_mapper.emplace("fundVout", func_table);
  item_list.push_back("fundVout");
  func_table = {
    VerifyCetSignatureRequest::GetFundInputAmountString,
    VerifyCetSignatureRequest::SetFundInputAmountString,
    VerifyCetSignatureRequest::GetFundInputAmountFieldType,
  };
  json_mapper.emplace("fundInputAmount", func_table);
  item_list.push_back("fundInputAmount");
  func_table = {
    VerifyCetSignatureRequest::GetVerifyRemoteString,
    VerifyCetSignatureRequest::SetVerifyRemoteString,
    VerifyCetSignatureRequest::GetVerifyRemoteFieldType,
  };
  json_mapper.emplace("verifyRemote", func_table);
  item_list.push_back("verifyRemote");
}

void VerifyCetSignatureRequest::ConvertFromStruct(
    const VerifyCetSignatureRequestStruct& data) {
  cet_hex_ = data.cet_hex;
  signature_ = data.signature;
  local_fund_pubkey_ = data.local_fund_pubkey;
  remote_fund_pubkey_ = data.remote_fund_pubkey;
  fund_tx_id_ = data.fund_tx_id;
  fund_vout_ = data.fund_vout;
  fund_input_amount_ = data.fund_input_amount;
  verify_remote_ = data.verify_remote;
  ignore_items = data.ignore_items;
}

VerifyCetSignatureRequestStruct VerifyCetSignatureRequest::ConvertToStruct() const {  // NOLINT
  VerifyCetSignatureRequestStruct result;
  result.cet_hex = cet_hex_;
  result.signature = signature_;
  result.local_fund_pubkey = local_fund_pubkey_;
  result.remote_fund_pubkey = remote_fund_pubkey_;
  result.fund_tx_id = fund_tx_id_;
  result.fund_vout = fund_vout_;
  result.fund_input_amount = fund_input_amount_;
  result.verify_remote = verify_remote_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// VerifyCetSignatureResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<VerifyCetSignatureResponse>
  VerifyCetSignatureResponse::json_mapper;
std::vector<std::string> VerifyCetSignatureResponse::item_list;

void VerifyCetSignatureResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<VerifyCetSignatureResponse> func_table;  // NOLINT

  func_table = {
    VerifyCetSignatureResponse::GetValidString,
    VerifyCetSignatureResponse::SetValidString,
    VerifyCetSignatureResponse::GetValidFieldType,
  };
  json_mapper.emplace("valid", func_table);
  item_list.push_back("valid");
}

void VerifyCetSignatureResponse::ConvertFromStruct(
    const VerifyCetSignatureResponseStruct& data) {
  valid_ = data.valid;
  ignore_items = data.ignore_items;
}

VerifyCetSignatureResponseStruct VerifyCetSignatureResponse::ConvertToStruct() const {  // NOLINT
  VerifyCetSignatureResponseStruct result;
  result.valid = valid_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// VerifyCetSignaturesRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<VerifyCetSignaturesRequest>
  VerifyCetSignaturesRequest::json_mapper;
std::vector<std::string> VerifyCetSignaturesRequest::item_list;

void VerifyCetSignaturesRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<VerifyCetSignaturesRequest> func_table;  // NOLINT

  func_table = {
    VerifyCetSignaturesRequest::GetCetsHexString,
    VerifyCetSignaturesRequest::SetCetsHexString,
    VerifyCetSignaturesRequest::GetCetsHexFieldType,
  };
  json_mapper.emplace("cetsHex", func_table);
  item_list.push_back("cetsHex");
  func_table = {
    VerifyCetSignaturesRequest::GetSignaturesString,
    VerifyCetSignaturesRequest::SetSignaturesString,
    VerifyCetSignaturesRequest::GetSignaturesFieldType,
  };
  json_mapper.emplace("signatures", func_table);
  item_list.push_back("signatures");
  func_table = {
    VerifyCetSignaturesRequest::GetLocalFundPubkeyString,
    VerifyCetSignaturesRequest::SetLocalFundPubkeyString,
    VerifyCetSignaturesRequest::GetLocalFundPubkeyFieldType,
  };
  json_mapper.emplace("localFundPubkey", func_table);
  item_list.push_back("localFundPubkey");
  func_table = {
    VerifyCetSignaturesRequest::GetRemoteFundPubkeyString,
    VerifyCetSignaturesRequest::SetRemoteFundPubkeyString,
    VerifyCetSignaturesRequest::GetRemoteFundPubkeyFieldType,
  };
  json_mapper.emplace("remoteFundPubkey", func_table);
  item_list.push_back("remoteFundPubkey");
  func_table = {
    VerifyCetSignaturesRequest::GetFundTxIdString,
    VerifyCetSignaturesRequest::SetFundTxIdString,
    VerifyCetSignaturesRequest::GetFundTxIdFieldType,
  };
  json_mapper.emplace("fundTxId", func_table);
  item_list.push_back("fundTxId");
  func_table = {
    VerifyCetSignaturesRequest::GetFundVoutString,
    VerifyCetSignaturesRequest::SetFundVoutString,
    VerifyCetSignaturesRequest::GetFundVoutFieldType,
  };
  json_mapper.emplace("fundVout", func_table);
  item_list.push_back("fundVout");
  func_table = {
    VerifyCetSignaturesRequest::GetFundInputAmountString,
    VerifyCetSignaturesRequest::SetFundInputAmountString,
    VerifyCetSignaturesRequest::GetFundInputAmountFieldType,
  };
  json_mapper.emplace("fundInputAmount", func_table);
  item_list.push_back("fundInputAmount");
  func_table = {
    VerifyCetSignaturesRequest::GetVerifyRemoteString,
    VerifyCetSignaturesRequest::SetVerifyRemoteString,
    VerifyCetSignaturesRequest::GetVerifyRemoteFieldType,
  };
  json_mapper.emplace("verifyRemote", func_table);
  item_list.push_back("verifyRemote");
}

void VerifyCetSignaturesRequest::ConvertFromStruct(
    const VerifyCetSignaturesRequestStruct& data) {
  cets_hex_.ConvertFromStruct(data.cets_hex);
  signatures_.ConvertFromStruct(data.signatures);
  local_fund_pubkey_ = data.local_fund_pubkey;
  remote_fund_pubkey_ = data.remote_fund_pubkey;
  fund_tx_id_ = data.fund_tx_id;
  fund_vout_ = data.fund_vout;
  fund_input_amount_ = data.fund_input_amount;
  verify_remote_ = data.verify_remote;
  ignore_items = data.ignore_items;
}

VerifyCetSignaturesRequestStruct VerifyCetSignaturesRequest::ConvertToStruct() const {  // NOLINT
  VerifyCetSignaturesRequestStruct result;
  result.cets_hex = cets_hex_.ConvertToStruct();
  result.signatures = signatures_.ConvertToStruct();
  result.local_fund_pubkey = local_fund_pubkey_;
  result.remote_fund_pubkey = remote_fund_pubkey_;
  result.fund_tx_id = fund_tx_id_;
  result.fund_vout = fund_vout_;
  result.fund_input_amount = fund_input_amount_;
  result.verify_remote = verify_remote_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// VerifyCetSignaturesResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<VerifyCetSignaturesResponse>
  VerifyCetSignaturesResponse::json_mapper;
std::vector<std::string> VerifyCetSignaturesResponse::item_list;

void VerifyCetSignaturesResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<VerifyCetSignaturesResponse> func_table;  // NOLINT

  func_table = {
    VerifyCetSignaturesResponse::GetValidString,
    VerifyCetSignaturesResponse::SetValidString,
    VerifyCetSignaturesResponse::GetValidFieldType,
  };
  json_mapper.emplace("valid", func_table);
  item_list.push_back("valid");
}

void VerifyCetSignaturesResponse::ConvertFromStruct(
    const VerifyCetSignaturesResponseStruct& data) {
  valid_ = data.valid;
  ignore_items = data.ignore_items;
}

VerifyCetSignaturesResponseStruct VerifyCetSignaturesResponse::ConvertToStruct() const {  // NOLINT
  VerifyCetSignaturesResponseStruct result;
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
// VerifyMutualClosingTxSignatureRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<VerifyMutualClosingTxSignatureRequest>
  VerifyMutualClosingTxSignatureRequest::json_mapper;
std::vector<std::string> VerifyMutualClosingTxSignatureRequest::item_list;

void VerifyMutualClosingTxSignatureRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<VerifyMutualClosingTxSignatureRequest> func_table;  // NOLINT

  func_table = {
    VerifyMutualClosingTxSignatureRequest::GetMutualClosingHexString,
    VerifyMutualClosingTxSignatureRequest::SetMutualClosingHexString,
    VerifyMutualClosingTxSignatureRequest::GetMutualClosingHexFieldType,
  };
  json_mapper.emplace("mutualClosingHex", func_table);
  item_list.push_back("mutualClosingHex");
  func_table = {
    VerifyMutualClosingTxSignatureRequest::GetSignatureString,
    VerifyMutualClosingTxSignatureRequest::SetSignatureString,
    VerifyMutualClosingTxSignatureRequest::GetSignatureFieldType,
  };
  json_mapper.emplace("signature", func_table);
  item_list.push_back("signature");
  func_table = {
    VerifyMutualClosingTxSignatureRequest::GetLocalFundPubkeyString,
    VerifyMutualClosingTxSignatureRequest::SetLocalFundPubkeyString,
    VerifyMutualClosingTxSignatureRequest::GetLocalFundPubkeyFieldType,
  };
  json_mapper.emplace("localFundPubkey", func_table);
  item_list.push_back("localFundPubkey");
  func_table = {
    VerifyMutualClosingTxSignatureRequest::GetRemoteFundPubkeyString,
    VerifyMutualClosingTxSignatureRequest::SetRemoteFundPubkeyString,
    VerifyMutualClosingTxSignatureRequest::GetRemoteFundPubkeyFieldType,
  };
  json_mapper.emplace("remoteFundPubkey", func_table);
  item_list.push_back("remoteFundPubkey");
  func_table = {
    VerifyMutualClosingTxSignatureRequest::GetFundTxIdString,
    VerifyMutualClosingTxSignatureRequest::SetFundTxIdString,
    VerifyMutualClosingTxSignatureRequest::GetFundTxIdFieldType,
  };
  json_mapper.emplace("fundTxId", func_table);
  item_list.push_back("fundTxId");
  func_table = {
    VerifyMutualClosingTxSignatureRequest::GetFundVoutString,
    VerifyMutualClosingTxSignatureRequest::SetFundVoutString,
    VerifyMutualClosingTxSignatureRequest::GetFundVoutFieldType,
  };
  json_mapper.emplace("fundVout", func_table);
  item_list.push_back("fundVout");
  func_table = {
    VerifyMutualClosingTxSignatureRequest::GetFundInputAmountString,
    VerifyMutualClosingTxSignatureRequest::SetFundInputAmountString,
    VerifyMutualClosingTxSignatureRequest::GetFundInputAmountFieldType,
  };
  json_mapper.emplace("fundInputAmount", func_table);
  item_list.push_back("fundInputAmount");
  func_table = {
    VerifyMutualClosingTxSignatureRequest::GetVerifyRemoteString,
    VerifyMutualClosingTxSignatureRequest::SetVerifyRemoteString,
    VerifyMutualClosingTxSignatureRequest::GetVerifyRemoteFieldType,
  };
  json_mapper.emplace("verifyRemote", func_table);
  item_list.push_back("verifyRemote");
}

void VerifyMutualClosingTxSignatureRequest::ConvertFromStruct(
    const VerifyMutualClosingTxSignatureRequestStruct& data) {
  mutual_closing_hex_ = data.mutual_closing_hex;
  signature_ = data.signature;
  local_fund_pubkey_ = data.local_fund_pubkey;
  remote_fund_pubkey_ = data.remote_fund_pubkey;
  fund_tx_id_ = data.fund_tx_id;
  fund_vout_ = data.fund_vout;
  fund_input_amount_ = data.fund_input_amount;
  verify_remote_ = data.verify_remote;
  ignore_items = data.ignore_items;
}

VerifyMutualClosingTxSignatureRequestStruct VerifyMutualClosingTxSignatureRequest::ConvertToStruct() const {  // NOLINT
  VerifyMutualClosingTxSignatureRequestStruct result;
  result.mutual_closing_hex = mutual_closing_hex_;
  result.signature = signature_;
  result.local_fund_pubkey = local_fund_pubkey_;
  result.remote_fund_pubkey = remote_fund_pubkey_;
  result.fund_tx_id = fund_tx_id_;
  result.fund_vout = fund_vout_;
  result.fund_input_amount = fund_input_amount_;
  result.verify_remote = verify_remote_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// VerifyMutualClosingTxSignatureResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<VerifyMutualClosingTxSignatureResponse>
  VerifyMutualClosingTxSignatureResponse::json_mapper;
std::vector<std::string> VerifyMutualClosingTxSignatureResponse::item_list;

void VerifyMutualClosingTxSignatureResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<VerifyMutualClosingTxSignatureResponse> func_table;  // NOLINT

  func_table = {
    VerifyMutualClosingTxSignatureResponse::GetValidString,
    VerifyMutualClosingTxSignatureResponse::SetValidString,
    VerifyMutualClosingTxSignatureResponse::GetValidFieldType,
  };
  json_mapper.emplace("valid", func_table);
  item_list.push_back("valid");
}

void VerifyMutualClosingTxSignatureResponse::ConvertFromStruct(
    const VerifyMutualClosingTxSignatureResponseStruct& data) {
  valid_ = data.valid;
  ignore_items = data.ignore_items;
}

VerifyMutualClosingTxSignatureResponseStruct VerifyMutualClosingTxSignatureResponse::ConvertToStruct() const {  // NOLINT
  VerifyMutualClosingTxSignatureResponseStruct result;
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
    VerifyRefundTxSignatureRequest::GetLocalFundPubkeyString,
    VerifyRefundTxSignatureRequest::SetLocalFundPubkeyString,
    VerifyRefundTxSignatureRequest::GetLocalFundPubkeyFieldType,
  };
  json_mapper.emplace("localFundPubkey", func_table);
  item_list.push_back("localFundPubkey");
  func_table = {
    VerifyRefundTxSignatureRequest::GetRemoteFundPubkeyString,
    VerifyRefundTxSignatureRequest::SetRemoteFundPubkeyString,
    VerifyRefundTxSignatureRequest::GetRemoteFundPubkeyFieldType,
  };
  json_mapper.emplace("remoteFundPubkey", func_table);
  item_list.push_back("remoteFundPubkey");
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
    VerifyRefundTxSignatureRequest::GetVerifyRemoteString,
    VerifyRefundTxSignatureRequest::SetVerifyRemoteString,
    VerifyRefundTxSignatureRequest::GetVerifyRemoteFieldType,
  };
  json_mapper.emplace("verifyRemote", func_table);
  item_list.push_back("verifyRemote");
}

void VerifyRefundTxSignatureRequest::ConvertFromStruct(
    const VerifyRefundTxSignatureRequestStruct& data) {
  refund_tx_hex_ = data.refund_tx_hex;
  signature_ = data.signature;
  local_fund_pubkey_ = data.local_fund_pubkey;
  remote_fund_pubkey_ = data.remote_fund_pubkey;
  fund_tx_id_ = data.fund_tx_id;
  fund_vout_ = data.fund_vout;
  fund_input_amount_ = data.fund_input_amount;
  verify_remote_ = data.verify_remote;
  ignore_items = data.ignore_items;
}

VerifyRefundTxSignatureRequestStruct VerifyRefundTxSignatureRequest::ConvertToStruct() const {  // NOLINT
  VerifyRefundTxSignatureRequestStruct result;
  result.refund_tx_hex = refund_tx_hex_;
  result.signature = signature_;
  result.local_fund_pubkey = local_fund_pubkey_;
  result.remote_fund_pubkey = remote_fund_pubkey_;
  result.fund_tx_id = fund_tx_id_;
  result.fund_vout = fund_vout_;
  result.fund_input_amount = fund_input_amount_;
  result.verify_remote = verify_remote_;
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
