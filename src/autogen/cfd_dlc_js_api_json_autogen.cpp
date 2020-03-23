// Copyright 2019 CryptoGarage
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
    AddSignaturesToCetRequest::GetFundTxVoutString,
    AddSignaturesToCetRequest::SetFundTxVoutString,
    AddSignaturesToCetRequest::GetFundTxVoutFieldType,
  };
  json_mapper.emplace("fundTxVout", func_table);
  item_list.push_back("fundTxVout");
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
  fund_tx_vout_ = data.fund_tx_vout;
  local_fund_pubkey_ = data.local_fund_pubkey;
  remote_fund_pubkey_ = data.remote_fund_pubkey;
  ignore_items = data.ignore_items;
}

AddSignaturesToCetRequestStruct AddSignaturesToCetRequest::ConvertToStruct() const {  // NOLINT
  AddSignaturesToCetRequestStruct result;
  result.cet_hex = cet_hex_;
  result.signatures = signatures_.ConvertToStruct();
  result.fund_tx_id = fund_tx_id_;
  result.fund_tx_vout = fund_tx_vout_;
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
    AddSignaturesToMutualClosingTxRequest::GetFundTxVoutString,
    AddSignaturesToMutualClosingTxRequest::SetFundTxVoutString,
    AddSignaturesToMutualClosingTxRequest::GetFundTxVoutFieldType,
  };
  json_mapper.emplace("fundTxVout", func_table);
  item_list.push_back("fundTxVout");
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
  fund_tx_vout_ = data.fund_tx_vout;
  local_fund_pubkey_ = data.local_fund_pubkey;
  remote_fund_pubkey_ = data.remote_fund_pubkey;
  ignore_items = data.ignore_items;
}

AddSignaturesToMutualClosingTxRequestStruct AddSignaturesToMutualClosingTxRequest::ConvertToStruct() const {  // NOLINT
  AddSignaturesToMutualClosingTxRequestStruct result;
  result.mutual_closing_tx_hex = mutual_closing_tx_hex_;
  result.signatures = signatures_.ConvertToStruct();
  result.fund_tx_id = fund_tx_id_;
  result.fund_tx_vout = fund_tx_vout_;
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
    AddSignaturesToRefundTxRequest::GetFundTxVoutString,
    AddSignaturesToRefundTxRequest::SetFundTxVoutString,
    AddSignaturesToRefundTxRequest::GetFundTxVoutFieldType,
  };
  json_mapper.emplace("fundTxVout", func_table);
  item_list.push_back("fundTxVout");
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
  fund_tx_vout_ = data.fund_tx_vout;
  local_fund_pubkey_ = data.local_fund_pubkey;
  remote_fund_pubkey_ = data.remote_fund_pubkey;
  ignore_items = data.ignore_items;
}

AddSignaturesToRefundTxRequestStruct AddSignaturesToRefundTxRequest::ConvertToStruct() const {  // NOLINT
  AddSignaturesToRefundTxRequestStruct result;
  result.refund_tx_hex = refund_tx_hex_;
  result.signatures = signatures_.ConvertToStruct();
  result.fund_tx_id = fund_tx_id_;
  result.fund_tx_vout = fund_tx_vout_;
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
// CreateCETRequest
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateCETRequest>
  CreateCETRequest::json_mapper;
std::vector<std::string> CreateCETRequest::item_list;

void CreateCETRequest::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateCETRequest> func_table;  // NOLINT

  func_table = {
    CreateCETRequest::GetLocalFundPubkeyString,
    CreateCETRequest::SetLocalFundPubkeyString,
    CreateCETRequest::GetLocalFundPubkeyFieldType,
  };
  json_mapper.emplace("localFundPubkey", func_table);
  item_list.push_back("localFundPubkey");
  func_table = {
    CreateCETRequest::GetLocalSweepPubkeyString,
    CreateCETRequest::SetLocalSweepPubkeyString,
    CreateCETRequest::GetLocalSweepPubkeyFieldType,
  };
  json_mapper.emplace("localSweepPubkey", func_table);
  item_list.push_back("localSweepPubkey");
  func_table = {
    CreateCETRequest::GetRemoteSweepPubkeyString,
    CreateCETRequest::SetRemoteSweepPubkeyString,
    CreateCETRequest::GetRemoteSweepPubkeyFieldType,
  };
  json_mapper.emplace("remoteSweepPubkey", func_table);
  item_list.push_back("remoteSweepPubkey");
  func_table = {
    CreateCETRequest::GetRemoteFinalAddressString,
    CreateCETRequest::SetRemoteFinalAddressString,
    CreateCETRequest::GetRemoteFinalAddressFieldType,
  };
  json_mapper.emplace("remoteFinalAddress", func_table);
  item_list.push_back("remoteFinalAddress");
  func_table = {
    CreateCETRequest::GetOraclePubkeyString,
    CreateCETRequest::SetOraclePubkeyString,
    CreateCETRequest::GetOraclePubkeyFieldType,
  };
  json_mapper.emplace("oraclePubkey", func_table);
  item_list.push_back("oraclePubkey");
  func_table = {
    CreateCETRequest::GetOracleRPointsString,
    CreateCETRequest::SetOracleRPointsString,
    CreateCETRequest::GetOracleRPointsFieldType,
  };
  json_mapper.emplace("oracleRPoints", func_table);
  item_list.push_back("oracleRPoints");
  func_table = {
    CreateCETRequest::GetMessagesString,
    CreateCETRequest::SetMessagesString,
    CreateCETRequest::GetMessagesFieldType,
  };
  json_mapper.emplace("messages", func_table);
  item_list.push_back("messages");
  func_table = {
    CreateCETRequest::GetDelayString,
    CreateCETRequest::SetDelayString,
    CreateCETRequest::GetDelayFieldType,
  };
  json_mapper.emplace("delay", func_table);
  item_list.push_back("delay");
  func_table = {
    CreateCETRequest::GetLocalPayoutString,
    CreateCETRequest::SetLocalPayoutString,
    CreateCETRequest::GetLocalPayoutFieldType,
  };
  json_mapper.emplace("localPayout", func_table);
  item_list.push_back("localPayout");
  func_table = {
    CreateCETRequest::GetRemotePayoutString,
    CreateCETRequest::SetRemotePayoutString,
    CreateCETRequest::GetRemotePayoutFieldType,
  };
  json_mapper.emplace("remotePayout", func_table);
  item_list.push_back("remotePayout");
  func_table = {
    CreateCETRequest::GetFundTxidString,
    CreateCETRequest::SetFundTxidString,
    CreateCETRequest::GetFundTxidFieldType,
  };
  json_mapper.emplace("fundTxid", func_table);
  item_list.push_back("fundTxid");
  func_table = {
    CreateCETRequest::GetFundVoutString,
    CreateCETRequest::SetFundVoutString,
    CreateCETRequest::GetFundVoutFieldType,
  };
  json_mapper.emplace("fundVout", func_table);
  item_list.push_back("fundVout");
  func_table = {
    CreateCETRequest::GetMaturityTimeString,
    CreateCETRequest::SetMaturityTimeString,
    CreateCETRequest::GetMaturityTimeFieldType,
  };
  json_mapper.emplace("maturityTime", func_table);
  item_list.push_back("maturityTime");
}

void CreateCETRequest::ConvertFromStruct(
    const CreateCETRequestStruct& data) {
  local_fund_pubkey_ = data.local_fund_pubkey;
  local_sweep_pubkey_ = data.local_sweep_pubkey;
  remote_sweep_pubkey_ = data.remote_sweep_pubkey;
  remote_final_address_ = data.remote_final_address;
  oracle_pubkey_ = data.oracle_pubkey;
  oracle_r_points_.ConvertFromStruct(data.oracle_r_points);
  messages_.ConvertFromStruct(data.messages);
  delay_ = data.delay;
  local_payout_ = data.local_payout;
  remote_payout_ = data.remote_payout;
  fund_txid_ = data.fund_txid;
  fund_vout_ = data.fund_vout;
  maturity_time_ = data.maturity_time;
  ignore_items = data.ignore_items;
}

CreateCETRequestStruct CreateCETRequest::ConvertToStruct() const {  // NOLINT
  CreateCETRequestStruct result;
  result.local_fund_pubkey = local_fund_pubkey_;
  result.local_sweep_pubkey = local_sweep_pubkey_;
  result.remote_sweep_pubkey = remote_sweep_pubkey_;
  result.remote_final_address = remote_final_address_;
  result.oracle_pubkey = oracle_pubkey_;
  result.oracle_r_points = oracle_r_points_.ConvertToStruct();
  result.messages = messages_.ConvertToStruct();
  result.delay = delay_;
  result.local_payout = local_payout_;
  result.remote_payout = remote_payout_;
  result.fund_txid = fund_txid_;
  result.fund_vout = fund_vout_;
  result.maturity_time = maturity_time_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// CreateCETResponse
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<CreateCETResponse>
  CreateCETResponse::json_mapper;
std::vector<std::string> CreateCETResponse::item_list;

void CreateCETResponse::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<CreateCETResponse> func_table;  // NOLINT

  func_table = {
    CreateCETResponse::GetHexString,
    CreateCETResponse::SetHexString,
    CreateCETResponse::GetHexFieldType,
  };
  json_mapper.emplace("hex", func_table);
  item_list.push_back("hex");
}

void CreateCETResponse::ConvertFromStruct(
    const CreateCETResponseStruct& data) {
  hex_ = data.hex;
  ignore_items = data.ignore_items;
}

CreateCETResponseStruct CreateCETResponse::ConvertToStruct() const {  // NOLINT
  CreateCETResponseStruct result;
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
    CreateClosingTransactionRequest::GetCetTxidString,
    CreateClosingTransactionRequest::SetCetTxidString,
    CreateClosingTransactionRequest::GetCetTxidFieldType,
  };
  json_mapper.emplace("cetTxid", func_table);
  item_list.push_back("cetTxid");
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
  cet_txid_ = data.cet_txid;
  cet_vout_ = data.cet_vout;
  ignore_items = data.ignore_items;
}

CreateClosingTransactionRequestStruct CreateClosingTransactionRequest::ConvertToStruct() const {  // NOLINT
  CreateClosingTransactionRequestStruct result;
  result.address = address_;
  result.amount = amount_;
  result.cet_txid = cet_txid_;
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
    CreateDlcTransactionsRequest::GetTimeoutString,
    CreateDlcTransactionsRequest::SetTimeoutString,
    CreateDlcTransactionsRequest::GetTimeoutFieldType,
  };
  json_mapper.emplace("timeout", func_table);
  item_list.push_back("timeout");
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
  timeout_ = data.timeout;
  local_inputs_.ConvertFromStruct(data.local_inputs);
  local_change_address_ = data.local_change_address;
  remote_inputs_.ConvertFromStruct(data.remote_inputs);
  remote_change_address_ = data.remote_change_address;
  fee_rate_ = data.fee_rate;
  maturity_time_ = data.maturity_time;
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
  result.timeout = timeout_;
  result.local_inputs = local_inputs_.ConvertToStruct();
  result.local_change_address = local_change_address_;
  result.remote_inputs = remote_inputs_.ConvertToStruct();
  result.remote_change_address = remote_change_address_;
  result.fee_rate = fee_rate_;
  result.maturity_time = maturity_time_;
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
    CreateDlcTransactionsResponse::GetClosingCetsHexString,
    CreateDlcTransactionsResponse::SetClosingCetsHexString,
    CreateDlcTransactionsResponse::GetClosingCetsHexFieldType,
  };
  json_mapper.emplace("closingCetsHex", func_table);
  item_list.push_back("closingCetsHex");
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
  closing_cets_hex_.ConvertFromStruct(data.closing_cets_hex);
  refund_tx_hex_ = data.refund_tx_hex;
  ignore_items = data.ignore_items;
}

CreateDlcTransactionsResponseStruct CreateDlcTransactionsResponse::ConvertToStruct() const {  // NOLINT
  CreateDlcTransactionsResponseStruct result;
  result.fund_tx_hex = fund_tx_hex_;
  result.closing_cets_hex = closing_cets_hex_.ConvertToStruct();
  result.refund_tx_hex = refund_tx_hex_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// TxInRequestA
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<TxInRequestA>
  TxInRequestA::json_mapper;
std::vector<std::string> TxInRequestA::item_list;

void TxInRequestA::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<TxInRequestA> func_table;  // NOLINT

  func_table = {
    TxInRequestA::GetTxidString,
    TxInRequestA::SetTxidString,
    TxInRequestA::GetTxidFieldType,
  };
  json_mapper.emplace("txid", func_table);
  item_list.push_back("txid");
  func_table = {
    TxInRequestA::GetVoutString,
    TxInRequestA::SetVoutString,
    TxInRequestA::GetVoutFieldType,
  };
  json_mapper.emplace("vout", func_table);
  item_list.push_back("vout");
}

void TxInRequestA::ConvertFromStruct(
    const TxInRequestAStruct& data) {
  txid_ = data.txid;
  vout_ = data.vout;
  ignore_items = data.ignore_items;
}

TxInRequestAStruct TxInRequestA::ConvertToStruct() const {  // NOLINT
  TxInRequestAStruct result;
  result.txid = txid_;
  result.vout = vout_;
  result.ignore_items = ignore_items;
  return result;
}

// ------------------------------------------------------------------------
// TxOutRequestA
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<TxOutRequestA>
  TxOutRequestA::json_mapper;
std::vector<std::string> TxOutRequestA::item_list;

void TxOutRequestA::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<TxOutRequestA> func_table;  // NOLINT

  func_table = {
    TxOutRequestA::GetAmountString,
    TxOutRequestA::SetAmountString,
    TxOutRequestA::GetAmountFieldType,
  };
  json_mapper.emplace("amount", func_table);
  item_list.push_back("amount");
  func_table = {
    TxOutRequestA::GetAddressString,
    TxOutRequestA::SetAddressString,
    TxOutRequestA::GetAddressFieldType,
  };
  json_mapper.emplace("address", func_table);
  item_list.push_back("address");
}

void TxOutRequestA::ConvertFromStruct(
    const TxOutRequestAStruct& data) {
  amount_ = data.amount;
  address_ = data.address;
  ignore_items = data.ignore_items;
}

TxOutRequestAStruct TxOutRequestA::ConvertToStruct() const {  // NOLINT
  TxOutRequestAStruct result;
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
    CreateFundTransactionRequest::GetNLockTimeString,
    CreateFundTransactionRequest::SetNLockTimeString,
    CreateFundTransactionRequest::GetNLockTimeFieldType,
  };
  json_mapper.emplace("nLockTime", func_table);
  item_list.push_back("nLockTime");
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
  n_lock_time_ = data.n_lock_time;
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
  result.n_lock_time = n_lock_time_;
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
    CreateMutualClosingTransactionRequest::GetFundTxidString,
    CreateMutualClosingTransactionRequest::SetFundTxidString,
    CreateMutualClosingTransactionRequest::GetFundTxidFieldType,
  };
  json_mapper.emplace("fundTxid", func_table);
  item_list.push_back("fundTxid");
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
  fund_txid_ = data.fund_txid;
  fund_vout_ = data.fund_vout;
  ignore_items = data.ignore_items;
}

CreateMutualClosingTransactionRequestStruct CreateMutualClosingTransactionRequest::ConvertToStruct() const {  // NOLINT
  CreateMutualClosingTransactionRequestStruct result;
  result.local_final_address = local_final_address_;
  result.remote_final_address = remote_final_address_;
  result.local_amount = local_amount_;
  result.remote_amount = remote_amount_;
  result.fund_txid = fund_txid_;
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
    CreatePenaltyTransactionRequest::GetCetIdString,
    CreatePenaltyTransactionRequest::SetCetIdString,
    CreatePenaltyTransactionRequest::GetCetIdFieldType,
  };
  json_mapper.emplace("cetId", func_table);
  item_list.push_back("cetId");
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
  cet_id_ = data.cet_id;
  cet_vout_ = data.cet_vout;
  ignore_items = data.ignore_items;
}

CreatePenaltyTransactionRequestStruct CreatePenaltyTransactionRequest::ConvertToStruct() const {  // NOLINT
  CreatePenaltyTransactionRequestStruct result;
  result.final_address = final_address_;
  result.amount = amount_;
  result.cet_id = cet_id_;
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
    CreateRefundTransactionRequest::GetFundTxidString,
    CreateRefundTransactionRequest::SetFundTxidString,
    CreateRefundTransactionRequest::GetFundTxidFieldType,
  };
  json_mapper.emplace("fundTxid", func_table);
  item_list.push_back("fundTxid");
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
  fund_txid_ = data.fund_txid;
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
  result.fund_txid = fund_txid_;
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
    GetRawCetSignatureRequest::GetFundTxVoutString,
    GetRawCetSignatureRequest::SetFundTxVoutString,
    GetRawCetSignatureRequest::GetFundTxVoutFieldType,
  };
  json_mapper.emplace("fundTxVout", func_table);
  item_list.push_back("fundTxVout");
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
    GetRawCetSignatureRequest::GetFundAmountString,
    GetRawCetSignatureRequest::SetFundAmountString,
    GetRawCetSignatureRequest::GetFundAmountFieldType,
  };
  json_mapper.emplace("fundAmount", func_table);
  item_list.push_back("fundAmount");
}

void GetRawCetSignatureRequest::ConvertFromStruct(
    const GetRawCetSignatureRequestStruct& data) {
  cet_hex_ = data.cet_hex;
  privkey_ = data.privkey;
  fund_tx_id_ = data.fund_tx_id;
  fund_tx_vout_ = data.fund_tx_vout;
  local_fund_pubkey_ = data.local_fund_pubkey;
  remote_fund_pubkey_ = data.remote_fund_pubkey;
  fund_amount_ = data.fund_amount;
  ignore_items = data.ignore_items;
}

GetRawCetSignatureRequestStruct GetRawCetSignatureRequest::ConvertToStruct() const {  // NOLINT
  GetRawCetSignatureRequestStruct result;
  result.cet_hex = cet_hex_;
  result.privkey = privkey_;
  result.fund_tx_id = fund_tx_id_;
  result.fund_tx_vout = fund_tx_vout_;
  result.local_fund_pubkey = local_fund_pubkey_;
  result.remote_fund_pubkey = remote_fund_pubkey_;
  result.fund_amount = fund_amount_;
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
    GetRawMutualClosingTxSignatureRequest::GetFundTxVoutString,
    GetRawMutualClosingTxSignatureRequest::SetFundTxVoutString,
    GetRawMutualClosingTxSignatureRequest::GetFundTxVoutFieldType,
  };
  json_mapper.emplace("fundTxVout", func_table);
  item_list.push_back("fundTxVout");
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
    GetRawMutualClosingTxSignatureRequest::GetFundAmountString,
    GetRawMutualClosingTxSignatureRequest::SetFundAmountString,
    GetRawMutualClosingTxSignatureRequest::GetFundAmountFieldType,
  };
  json_mapper.emplace("fundAmount", func_table);
  item_list.push_back("fundAmount");
}

void GetRawMutualClosingTxSignatureRequest::ConvertFromStruct(
    const GetRawMutualClosingTxSignatureRequestStruct& data) {
  mutual_closing_hex_ = data.mutual_closing_hex;
  privkey_ = data.privkey;
  fund_tx_id_ = data.fund_tx_id;
  fund_tx_vout_ = data.fund_tx_vout;
  local_fund_pubkey_ = data.local_fund_pubkey;
  remote_fund_pubkey_ = data.remote_fund_pubkey;
  fund_amount_ = data.fund_amount;
  ignore_items = data.ignore_items;
}

GetRawMutualClosingTxSignatureRequestStruct GetRawMutualClosingTxSignatureRequest::ConvertToStruct() const {  // NOLINT
  GetRawMutualClosingTxSignatureRequestStruct result;
  result.mutual_closing_hex = mutual_closing_hex_;
  result.privkey = privkey_;
  result.fund_tx_id = fund_tx_id_;
  result.fund_tx_vout = fund_tx_vout_;
  result.local_fund_pubkey = local_fund_pubkey_;
  result.remote_fund_pubkey = remote_fund_pubkey_;
  result.fund_amount = fund_amount_;
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
    GetRawFundTxSignatureRequest::GetPrevTxVoutString,
    GetRawFundTxSignatureRequest::SetPrevTxVoutString,
    GetRawFundTxSignatureRequest::GetPrevTxVoutFieldType,
  };
  json_mapper.emplace("prevTxVout", func_table);
  item_list.push_back("prevTxVout");
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
  prev_tx_vout_ = data.prev_tx_vout;
  amount_ = data.amount;
  ignore_items = data.ignore_items;
}

GetRawFundTxSignatureRequestStruct GetRawFundTxSignatureRequest::ConvertToStruct() const {  // NOLINT
  GetRawFundTxSignatureRequestStruct result;
  result.fund_tx_hex = fund_tx_hex_;
  result.privkey = privkey_;
  result.prev_tx_id = prev_tx_id_;
  result.prev_tx_vout = prev_tx_vout_;
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
    GetRawRefundTxSignatureRequest::GetFundTxVoutString,
    GetRawRefundTxSignatureRequest::SetFundTxVoutString,
    GetRawRefundTxSignatureRequest::GetFundTxVoutFieldType,
  };
  json_mapper.emplace("fundTxVout", func_table);
  item_list.push_back("fundTxVout");
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
    GetRawRefundTxSignatureRequest::GetFundAmountString,
    GetRawRefundTxSignatureRequest::SetFundAmountString,
    GetRawRefundTxSignatureRequest::GetFundAmountFieldType,
  };
  json_mapper.emplace("fundAmount", func_table);
  item_list.push_back("fundAmount");
}

void GetRawRefundTxSignatureRequest::ConvertFromStruct(
    const GetRawRefundTxSignatureRequestStruct& data) {
  refund_tx_hex_ = data.refund_tx_hex;
  privkey_ = data.privkey;
  fund_tx_id_ = data.fund_tx_id;
  fund_tx_vout_ = data.fund_tx_vout;
  local_fund_pubkey_ = data.local_fund_pubkey;
  remote_fund_pubkey_ = data.remote_fund_pubkey;
  fund_amount_ = data.fund_amount;
  ignore_items = data.ignore_items;
}

GetRawRefundTxSignatureRequestStruct GetRawRefundTxSignatureRequest::ConvertToStruct() const {  // NOLINT
  GetRawRefundTxSignatureRequestStruct result;
  result.refund_tx_hex = refund_tx_hex_;
  result.privkey = privkey_;
  result.fund_tx_id = fund_tx_id_;
  result.fund_tx_vout = fund_tx_vout_;
  result.local_fund_pubkey = local_fund_pubkey_;
  result.remote_fund_pubkey = remote_fund_pubkey_;
  result.fund_amount = fund_amount_;
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
    SignClosingTransactionRequest::GetDelayString,
    SignClosingTransactionRequest::SetDelayString,
    SignClosingTransactionRequest::GetDelayFieldType,
  };
  json_mapper.emplace("delay", func_table);
  item_list.push_back("delay");
  func_table = {
    SignClosingTransactionRequest::GetOracleSigString,
    SignClosingTransactionRequest::SetOracleSigString,
    SignClosingTransactionRequest::GetOracleSigFieldType,
  };
  json_mapper.emplace("oracleSig", func_table);
  item_list.push_back("oracleSig");
  func_table = {
    SignClosingTransactionRequest::GetCetTxidString,
    SignClosingTransactionRequest::SetCetTxidString,
    SignClosingTransactionRequest::GetCetTxidFieldType,
  };
  json_mapper.emplace("cetTxid", func_table);
  item_list.push_back("cetTxid");
  func_table = {
    SignClosingTransactionRequest::GetCetVoutString,
    SignClosingTransactionRequest::SetCetVoutString,
    SignClosingTransactionRequest::GetCetVoutFieldType,
  };
  json_mapper.emplace("cetVout", func_table);
  item_list.push_back("cetVout");
  func_table = {
    SignClosingTransactionRequest::GetCetScriptString,
    SignClosingTransactionRequest::SetCetScriptString,
    SignClosingTransactionRequest::GetCetScriptFieldType,
  };
  json_mapper.emplace("cetScript", func_table);
  item_list.push_back("cetScript");
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
  delay_ = data.delay;
  oracle_sig_ = data.oracle_sig;
  cet_txid_ = data.cet_txid;
  cet_vout_ = data.cet_vout;
  cet_script_ = data.cet_script;
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
  result.delay = delay_;
  result.oracle_sig = oracle_sig_;
  result.cet_txid = cet_txid_;
  result.cet_vout = cet_vout_;
  result.cet_script = cet_script_;
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
    SignFundTransactionRequest::GetPrevTxidString,
    SignFundTransactionRequest::SetPrevTxidString,
    SignFundTransactionRequest::GetPrevTxidFieldType,
  };
  json_mapper.emplace("prevTxid", func_table);
  item_list.push_back("prevTxid");
  func_table = {
    SignFundTransactionRequest::GetPrevTxVoutString,
    SignFundTransactionRequest::SetPrevTxVoutString,
    SignFundTransactionRequest::GetPrevTxVoutFieldType,
  };
  json_mapper.emplace("prevTxVout", func_table);
  item_list.push_back("prevTxVout");
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
  prev_txid_ = data.prev_txid;
  prev_tx_vout_ = data.prev_tx_vout;
  amount_ = data.amount;
  ignore_items = data.ignore_items;
}

SignFundTransactionRequestStruct SignFundTransactionRequest::ConvertToStruct() const {  // NOLINT
  SignFundTransactionRequestStruct result;
  result.fund_tx_hex = fund_tx_hex_;
  result.privkey = privkey_;
  result.prev_txid = prev_txid_;
  result.prev_tx_vout = prev_tx_vout_;
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
    VerifyCetSignatureRequest::GetInputAmountString,
    VerifyCetSignatureRequest::SetInputAmountString,
    VerifyCetSignatureRequest::GetInputAmountFieldType,
  };
  json_mapper.emplace("inputAmount", func_table);
  item_list.push_back("inputAmount");
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
  input_amount_ = data.input_amount;
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
  result.input_amount = input_amount_;
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
    VerifyFundTxSignatureRequest::GetPrevTxVoutString,
    VerifyFundTxSignatureRequest::SetPrevTxVoutString,
    VerifyFundTxSignatureRequest::GetPrevTxVoutFieldType,
  };
  json_mapper.emplace("prevTxVout", func_table);
  item_list.push_back("prevTxVout");
  func_table = {
    VerifyFundTxSignatureRequest::GetInputAmountString,
    VerifyFundTxSignatureRequest::SetInputAmountString,
    VerifyFundTxSignatureRequest::GetInputAmountFieldType,
  };
  json_mapper.emplace("inputAmount", func_table);
  item_list.push_back("inputAmount");
}

void VerifyFundTxSignatureRequest::ConvertFromStruct(
    const VerifyFundTxSignatureRequestStruct& data) {
  fund_tx_hex_ = data.fund_tx_hex;
  signature_ = data.signature;
  pubkey_ = data.pubkey;
  prev_tx_id_ = data.prev_tx_id;
  prev_tx_vout_ = data.prev_tx_vout;
  input_amount_ = data.input_amount;
  ignore_items = data.ignore_items;
}

VerifyFundTxSignatureRequestStruct VerifyFundTxSignatureRequest::ConvertToStruct() const {  // NOLINT
  VerifyFundTxSignatureRequestStruct result;
  result.fund_tx_hex = fund_tx_hex_;
  result.signature = signature_;
  result.pubkey = pubkey_;
  result.prev_tx_id = prev_tx_id_;
  result.prev_tx_vout = prev_tx_vout_;
  result.input_amount = input_amount_;
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
    VerifyMutualClosingTxSignatureRequest::GetCetHexString,
    VerifyMutualClosingTxSignatureRequest::SetCetHexString,
    VerifyMutualClosingTxSignatureRequest::GetCetHexFieldType,
  };
  json_mapper.emplace("cetHex", func_table);
  item_list.push_back("cetHex");
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
    VerifyMutualClosingTxSignatureRequest::GetInputAmountString,
    VerifyMutualClosingTxSignatureRequest::SetInputAmountString,
    VerifyMutualClosingTxSignatureRequest::GetInputAmountFieldType,
  };
  json_mapper.emplace("inputAmount", func_table);
  item_list.push_back("inputAmount");
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
  cet_hex_ = data.cet_hex;
  signature_ = data.signature;
  local_fund_pubkey_ = data.local_fund_pubkey;
  remote_fund_pubkey_ = data.remote_fund_pubkey;
  fund_tx_id_ = data.fund_tx_id;
  fund_vout_ = data.fund_vout;
  input_amount_ = data.input_amount;
  verify_remote_ = data.verify_remote;
  ignore_items = data.ignore_items;
}

VerifyMutualClosingTxSignatureRequestStruct VerifyMutualClosingTxSignatureRequest::ConvertToStruct() const {  // NOLINT
  VerifyMutualClosingTxSignatureRequestStruct result;
  result.cet_hex = cet_hex_;
  result.signature = signature_;
  result.local_fund_pubkey = local_fund_pubkey_;
  result.remote_fund_pubkey = remote_fund_pubkey_;
  result.fund_tx_id = fund_tx_id_;
  result.fund_vout = fund_vout_;
  result.input_amount = input_amount_;
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
    VerifyRefundTxSignatureRequest::GetInputAmountString,
    VerifyRefundTxSignatureRequest::SetInputAmountString,
    VerifyRefundTxSignatureRequest::GetInputAmountFieldType,
  };
  json_mapper.emplace("inputAmount", func_table);
  item_list.push_back("inputAmount");
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
  input_amount_ = data.input_amount;
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
  result.input_amount = input_amount_;
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
