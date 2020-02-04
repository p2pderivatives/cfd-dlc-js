// Copyright 2019 CryptoGarage
/**
 * @file cfd_dlc_js_api_json_autogen.h
 *
 * @brief JSON mapping file. (auto generate)
 */
#ifndef CFD_DLC_JS_SRC_AUTOGEN_CFD_DLC_JS_API_JSON_AUTOGEN_H_
#define CFD_DLC_JS_SRC_AUTOGEN_CFD_DLC_JS_API_JSON_AUTOGEN_H_

#include <set>
#include <string>
#include <vector>

#include "cfdcore/cfdcore_json_mapping_base.h"

#include "cfddlcjs/cfddlcjs_struct.h"

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
/**
 * @brief JSON-API (AddSignaturesToCetRequest) class
 */
class AddSignaturesToCetRequest
  : public cfd::core::JsonClassBase<AddSignaturesToCetRequest> {
 public:
  AddSignaturesToCetRequest() {
    CollectFieldName();
  }
  virtual ~AddSignaturesToCetRequest() {
    // do nothing
  }
  /**
   * @brief collect field name.
   */
  static void CollectFieldName();

  /**
   * @brief Get of cetHex
   * @return cetHex
   */
  std::string GetCetHex() const {
    return cet_hex_;
  }
  /**
   * @brief Set to cetHex
   * @param[in] cet_hex    setting value.
   */
  void SetCetHex(  // line separate
    const std::string& cet_hex) {  // NOLINT
    this->cet_hex_ = cet_hex;
  }
  /**
   * @brief Get data type of cetHex
   * @return Data type of cetHex
   */
  static std::string GetCetHexFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of cetHex field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetCetHexString(  // line separate
      const AddSignaturesToCetRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.cet_hex_);
  }
  /**
   * @brief Set json object to cetHex field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetCetHexString(  // line separate
      AddSignaturesToCetRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.cet_hex_, json_value);
  }

  /**
   * @brief Get of signatures.
   * @return signatures
   */
  JsonValueVector<std::string>& GetSignatures() {  // NOLINT
    return signatures_;
  }
  /**
   * @brief Set to signatures.
   * @param[in] signatures    setting value.
   */
  void SetSignatures(  // line separate
      const JsonValueVector<std::string>& signatures) {  // NOLINT
    this->signatures_ = signatures;
  }
  /**
   * @brief Get data type of signatures.
   * @return Data type of signatures.
   */
  static std::string GetSignaturesFieldType() {
    return "JsonValueVector<std::string>";  // NOLINT
  }
  /**
   * @brief Get json string of signatures field.
   * @param[in,out] obj     class object
   * @return JSON string.
   */
  static std::string GetSignaturesString(  // line separate
      const AddSignaturesToCetRequest& obj) {  // NOLINT
    // Do not set to const, because substitution of member variables
    // may occur in pre / post processing inside Serialize
    return obj.signatures_.Serialize();
  }
  /**
   * @brief Set json object to signatures field.
   * @param[in,out] obj     class object
   * @param[in] json_value  JSON object
   */
  static void SetSignaturesString(  // line separate
      AddSignaturesToCetRequest& obj,  // NOLINT
      const UniValue& json_value) {
    obj.signatures_.DeserializeUniValue(json_value);
  }

  /**
   * @brief Get of fundTxId
   * @return fundTxId
   */
  std::string GetFundTxId() const {
    return fund_tx_id_;
  }
  /**
   * @brief Set to fundTxId
   * @param[in] fund_tx_id    setting value.
   */
  void SetFundTxId(  // line separate
    const std::string& fund_tx_id) {  // NOLINT
    this->fund_tx_id_ = fund_tx_id;
  }
  /**
   * @brief Get data type of fundTxId
   * @return Data type of fundTxId
   */
  static std::string GetFundTxIdFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of fundTxId field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetFundTxIdString(  // line separate
      const AddSignaturesToCetRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fund_tx_id_);
  }
  /**
   * @brief Set json object to fundTxId field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFundTxIdString(  // line separate
      AddSignaturesToCetRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.fund_tx_id_, json_value);
  }

  /**
   * @brief Get of fundTxVout
   * @return fundTxVout
   */
  uint32_t GetFundTxVout() const {
    return fund_tx_vout_;
  }
  /**
   * @brief Set to fundTxVout
   * @param[in] fund_tx_vout    setting value.
   */
  void SetFundTxVout(  // line separate
    const uint32_t& fund_tx_vout) {  // NOLINT
    this->fund_tx_vout_ = fund_tx_vout;
  }
  /**
   * @brief Get data type of fundTxVout
   * @return Data type of fundTxVout
   */
  static std::string GetFundTxVoutFieldType() {
    return "uint32_t";
  }
  /**
   * @brief Get json string of fundTxVout field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetFundTxVoutString(  // line separate
      const AddSignaturesToCetRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fund_tx_vout_);
  }
  /**
   * @brief Set json object to fundTxVout field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFundTxVoutString(  // line separate
      AddSignaturesToCetRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.fund_tx_vout_, json_value);
  }

  /**
   * @brief Get of localFundPubkey
   * @return localFundPubkey
   */
  std::string GetLocalFundPubkey() const {
    return local_fund_pubkey_;
  }
  /**
   * @brief Set to localFundPubkey
   * @param[in] local_fund_pubkey    setting value.
   */
  void SetLocalFundPubkey(  // line separate
    const std::string& local_fund_pubkey) {  // NOLINT
    this->local_fund_pubkey_ = local_fund_pubkey;
  }
  /**
   * @brief Get data type of localFundPubkey
   * @return Data type of localFundPubkey
   */
  static std::string GetLocalFundPubkeyFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of localFundPubkey field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetLocalFundPubkeyString(  // line separate
      const AddSignaturesToCetRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.local_fund_pubkey_);
  }
  /**
   * @brief Set json object to localFundPubkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetLocalFundPubkeyString(  // line separate
      AddSignaturesToCetRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.local_fund_pubkey_, json_value);
  }

  /**
   * @brief Get of remoteFundPubkey
   * @return remoteFundPubkey
   */
  std::string GetRemoteFundPubkey() const {
    return remote_fund_pubkey_;
  }
  /**
   * @brief Set to remoteFundPubkey
   * @param[in] remote_fund_pubkey    setting value.
   */
  void SetRemoteFundPubkey(  // line separate
    const std::string& remote_fund_pubkey) {  // NOLINT
    this->remote_fund_pubkey_ = remote_fund_pubkey;
  }
  /**
   * @brief Get data type of remoteFundPubkey
   * @return Data type of remoteFundPubkey
   */
  static std::string GetRemoteFundPubkeyFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of remoteFundPubkey field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetRemoteFundPubkeyString(  // line separate
      const AddSignaturesToCetRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.remote_fund_pubkey_);
  }
  /**
   * @brief Set json object to remoteFundPubkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetRemoteFundPubkeyString(  // line separate
      AddSignaturesToCetRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.remote_fund_pubkey_, json_value);
  }

  /**
   * @brief Set ignore item.
   * @param[in] key   ignore target key name.
   */
  void SetIgnoreItem(const std::string& key) {
    ignore_items.insert(key);
  }

  /**
   * @brief Convert struct to class.
   * @param[in] data   struct data.
   */
  void ConvertFromStruct(
      const AddSignaturesToCetRequestStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  AddSignaturesToCetRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using AddSignaturesToCetRequestMapTable =
    cfd::core::JsonTableMap<AddSignaturesToCetRequest>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const AddSignaturesToCetRequestMapTable& GetJsonMapper() const {  // NOLINT
    return json_mapper;
  }
  /**
   * @brief Get item lists of JSON mapping.
   * Fetch a list of target variable names in the order of definition.
   * @return Item lists of JSON mapping.
   * @see cfd::core::JsonClassBase::GetJsonItemList()
   */
  virtual const std::vector<std::string>& GetJsonItemList() const {
    return item_list;
  }
  /**
   * @brief Get ignore item lists of JSON mnapping.
   * Ignore the target variable at Serialize.
   * @return Item list of JSON mapping.
   * @see cfd::core::JsonClassBase::GetIgnoreItem()
   */
  virtual const std::set<std::string>& GetIgnoreItem() const {
    return ignore_items;
  }

 private:
 /**
  * @brief JsonFunctionMap table
  */
  static AddSignaturesToCetRequestMapTable json_mapper;
  /**
   * @brief field name list.
   */
  static std::vector<std::string> item_list;
  /**
   * @brief ignore item list.
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(cetHex) value
   */
  std::string cet_hex_ = "";
  /**
   * @brief JsonAPI(signatures) value
   */
  JsonValueVector<std::string> signatures_;  // NOLINT
  /**
   * @brief JsonAPI(fundTxId) value
   */
  std::string fund_tx_id_ = "";
  /**
   * @brief JsonAPI(fundTxVout) value
   */
  uint32_t fund_tx_vout_ = 0;
  /**
   * @brief JsonAPI(localFundPubkey) value
   */
  std::string local_fund_pubkey_ = "";
  /**
   * @brief JsonAPI(remoteFundPubkey) value
   */
  std::string remote_fund_pubkey_ = "";
};

// ------------------------------------------------------------------------
// AddSignaturesToCetResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (AddSignaturesToCetResponse) class
 */
class AddSignaturesToCetResponse
  : public cfd::core::JsonClassBase<AddSignaturesToCetResponse> {
 public:
  AddSignaturesToCetResponse() {
    CollectFieldName();
  }
  virtual ~AddSignaturesToCetResponse() {
    // do nothing
  }
  /**
   * @brief collect field name.
   */
  static void CollectFieldName();

  /**
   * @brief Get of hex
   * @return hex
   */
  std::string GetHex() const {
    return hex_;
  }
  /**
   * @brief Set to hex
   * @param[in] hex    setting value.
   */
  void SetHex(  // line separate
    const std::string& hex) {  // NOLINT
    this->hex_ = hex;
  }
  /**
   * @brief Get data type of hex
   * @return Data type of hex
   */
  static std::string GetHexFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of hex field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetHexString(  // line separate
      const AddSignaturesToCetResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.hex_);
  }
  /**
   * @brief Set json object to hex field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetHexString(  // line separate
      AddSignaturesToCetResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.hex_, json_value);
  }

  /**
   * @brief Set ignore item.
   * @param[in] key   ignore target key name.
   */
  void SetIgnoreItem(const std::string& key) {
    ignore_items.insert(key);
  }

  /**
   * @brief Convert struct to class.
   * @param[in] data   struct data.
   */
  void ConvertFromStruct(
      const AddSignaturesToCetResponseStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  AddSignaturesToCetResponseStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using AddSignaturesToCetResponseMapTable =
    cfd::core::JsonTableMap<AddSignaturesToCetResponse>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const AddSignaturesToCetResponseMapTable& GetJsonMapper() const {  // NOLINT
    return json_mapper;
  }
  /**
   * @brief Get item lists of JSON mapping.
   * Fetch a list of target variable names in the order of definition.
   * @return Item lists of JSON mapping.
   * @see cfd::core::JsonClassBase::GetJsonItemList()
   */
  virtual const std::vector<std::string>& GetJsonItemList() const {
    return item_list;
  }
  /**
   * @brief Get ignore item lists of JSON mnapping.
   * Ignore the target variable at Serialize.
   * @return Item list of JSON mapping.
   * @see cfd::core::JsonClassBase::GetIgnoreItem()
   */
  virtual const std::set<std::string>& GetIgnoreItem() const {
    return ignore_items;
  }

 private:
 /**
  * @brief JsonFunctionMap table
  */
  static AddSignaturesToCetResponseMapTable json_mapper;
  /**
   * @brief field name list.
   */
  static std::vector<std::string> item_list;
  /**
   * @brief ignore item list.
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(hex) value
   */
  std::string hex_ = "";
};

// ------------------------------------------------------------------------
// AddSignaturesToMutualClosingTxRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (AddSignaturesToMutualClosingTxRequest) class
 */
class AddSignaturesToMutualClosingTxRequest
  : public cfd::core::JsonClassBase<AddSignaturesToMutualClosingTxRequest> {
 public:
  AddSignaturesToMutualClosingTxRequest() {
    CollectFieldName();
  }
  virtual ~AddSignaturesToMutualClosingTxRequest() {
    // do nothing
  }
  /**
   * @brief collect field name.
   */
  static void CollectFieldName();

  /**
   * @brief Get of mutualClosingTxHex
   * @return mutualClosingTxHex
   */
  std::string GetMutualClosingTxHex() const {
    return mutual_closing_tx_hex_;
  }
  /**
   * @brief Set to mutualClosingTxHex
   * @param[in] mutual_closing_tx_hex    setting value.
   */
  void SetMutualClosingTxHex(  // line separate
    const std::string& mutual_closing_tx_hex) {  // NOLINT
    this->mutual_closing_tx_hex_ = mutual_closing_tx_hex;
  }
  /**
   * @brief Get data type of mutualClosingTxHex
   * @return Data type of mutualClosingTxHex
   */
  static std::string GetMutualClosingTxHexFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of mutualClosingTxHex field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetMutualClosingTxHexString(  // line separate
      const AddSignaturesToMutualClosingTxRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.mutual_closing_tx_hex_);
  }
  /**
   * @brief Set json object to mutualClosingTxHex field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetMutualClosingTxHexString(  // line separate
      AddSignaturesToMutualClosingTxRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.mutual_closing_tx_hex_, json_value);
  }

  /**
   * @brief Get of signatures.
   * @return signatures
   */
  JsonValueVector<std::string>& GetSignatures() {  // NOLINT
    return signatures_;
  }
  /**
   * @brief Set to signatures.
   * @param[in] signatures    setting value.
   */
  void SetSignatures(  // line separate
      const JsonValueVector<std::string>& signatures) {  // NOLINT
    this->signatures_ = signatures;
  }
  /**
   * @brief Get data type of signatures.
   * @return Data type of signatures.
   */
  static std::string GetSignaturesFieldType() {
    return "JsonValueVector<std::string>";  // NOLINT
  }
  /**
   * @brief Get json string of signatures field.
   * @param[in,out] obj     class object
   * @return JSON string.
   */
  static std::string GetSignaturesString(  // line separate
      const AddSignaturesToMutualClosingTxRequest& obj) {  // NOLINT
    // Do not set to const, because substitution of member variables
    // may occur in pre / post processing inside Serialize
    return obj.signatures_.Serialize();
  }
  /**
   * @brief Set json object to signatures field.
   * @param[in,out] obj     class object
   * @param[in] json_value  JSON object
   */
  static void SetSignaturesString(  // line separate
      AddSignaturesToMutualClosingTxRequest& obj,  // NOLINT
      const UniValue& json_value) {
    obj.signatures_.DeserializeUniValue(json_value);
  }

  /**
   * @brief Get of fundTxId
   * @return fundTxId
   */
  std::string GetFundTxId() const {
    return fund_tx_id_;
  }
  /**
   * @brief Set to fundTxId
   * @param[in] fund_tx_id    setting value.
   */
  void SetFundTxId(  // line separate
    const std::string& fund_tx_id) {  // NOLINT
    this->fund_tx_id_ = fund_tx_id;
  }
  /**
   * @brief Get data type of fundTxId
   * @return Data type of fundTxId
   */
  static std::string GetFundTxIdFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of fundTxId field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetFundTxIdString(  // line separate
      const AddSignaturesToMutualClosingTxRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fund_tx_id_);
  }
  /**
   * @brief Set json object to fundTxId field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFundTxIdString(  // line separate
      AddSignaturesToMutualClosingTxRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.fund_tx_id_, json_value);
  }

  /**
   * @brief Get of fundTxVout
   * @return fundTxVout
   */
  uint32_t GetFundTxVout() const {
    return fund_tx_vout_;
  }
  /**
   * @brief Set to fundTxVout
   * @param[in] fund_tx_vout    setting value.
   */
  void SetFundTxVout(  // line separate
    const uint32_t& fund_tx_vout) {  // NOLINT
    this->fund_tx_vout_ = fund_tx_vout;
  }
  /**
   * @brief Get data type of fundTxVout
   * @return Data type of fundTxVout
   */
  static std::string GetFundTxVoutFieldType() {
    return "uint32_t";
  }
  /**
   * @brief Get json string of fundTxVout field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetFundTxVoutString(  // line separate
      const AddSignaturesToMutualClosingTxRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fund_tx_vout_);
  }
  /**
   * @brief Set json object to fundTxVout field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFundTxVoutString(  // line separate
      AddSignaturesToMutualClosingTxRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.fund_tx_vout_, json_value);
  }

  /**
   * @brief Get of localFundPubkey
   * @return localFundPubkey
   */
  std::string GetLocalFundPubkey() const {
    return local_fund_pubkey_;
  }
  /**
   * @brief Set to localFundPubkey
   * @param[in] local_fund_pubkey    setting value.
   */
  void SetLocalFundPubkey(  // line separate
    const std::string& local_fund_pubkey) {  // NOLINT
    this->local_fund_pubkey_ = local_fund_pubkey;
  }
  /**
   * @brief Get data type of localFundPubkey
   * @return Data type of localFundPubkey
   */
  static std::string GetLocalFundPubkeyFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of localFundPubkey field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetLocalFundPubkeyString(  // line separate
      const AddSignaturesToMutualClosingTxRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.local_fund_pubkey_);
  }
  /**
   * @brief Set json object to localFundPubkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetLocalFundPubkeyString(  // line separate
      AddSignaturesToMutualClosingTxRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.local_fund_pubkey_, json_value);
  }

  /**
   * @brief Get of remoteFundPubkey
   * @return remoteFundPubkey
   */
  std::string GetRemoteFundPubkey() const {
    return remote_fund_pubkey_;
  }
  /**
   * @brief Set to remoteFundPubkey
   * @param[in] remote_fund_pubkey    setting value.
   */
  void SetRemoteFundPubkey(  // line separate
    const std::string& remote_fund_pubkey) {  // NOLINT
    this->remote_fund_pubkey_ = remote_fund_pubkey;
  }
  /**
   * @brief Get data type of remoteFundPubkey
   * @return Data type of remoteFundPubkey
   */
  static std::string GetRemoteFundPubkeyFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of remoteFundPubkey field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetRemoteFundPubkeyString(  // line separate
      const AddSignaturesToMutualClosingTxRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.remote_fund_pubkey_);
  }
  /**
   * @brief Set json object to remoteFundPubkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetRemoteFundPubkeyString(  // line separate
      AddSignaturesToMutualClosingTxRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.remote_fund_pubkey_, json_value);
  }

  /**
   * @brief Set ignore item.
   * @param[in] key   ignore target key name.
   */
  void SetIgnoreItem(const std::string& key) {
    ignore_items.insert(key);
  }

  /**
   * @brief Convert struct to class.
   * @param[in] data   struct data.
   */
  void ConvertFromStruct(
      const AddSignaturesToMutualClosingTxRequestStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  AddSignaturesToMutualClosingTxRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using AddSignaturesToMutualClosingTxRequestMapTable =
    cfd::core::JsonTableMap<AddSignaturesToMutualClosingTxRequest>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const AddSignaturesToMutualClosingTxRequestMapTable& GetJsonMapper() const {  // NOLINT
    return json_mapper;
  }
  /**
   * @brief Get item lists of JSON mapping.
   * Fetch a list of target variable names in the order of definition.
   * @return Item lists of JSON mapping.
   * @see cfd::core::JsonClassBase::GetJsonItemList()
   */
  virtual const std::vector<std::string>& GetJsonItemList() const {
    return item_list;
  }
  /**
   * @brief Get ignore item lists of JSON mnapping.
   * Ignore the target variable at Serialize.
   * @return Item list of JSON mapping.
   * @see cfd::core::JsonClassBase::GetIgnoreItem()
   */
  virtual const std::set<std::string>& GetIgnoreItem() const {
    return ignore_items;
  }

 private:
 /**
  * @brief JsonFunctionMap table
  */
  static AddSignaturesToMutualClosingTxRequestMapTable json_mapper;
  /**
   * @brief field name list.
   */
  static std::vector<std::string> item_list;
  /**
   * @brief ignore item list.
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(mutualClosingTxHex) value
   */
  std::string mutual_closing_tx_hex_ = "";
  /**
   * @brief JsonAPI(signatures) value
   */
  JsonValueVector<std::string> signatures_;  // NOLINT
  /**
   * @brief JsonAPI(fundTxId) value
   */
  std::string fund_tx_id_ = "";
  /**
   * @brief JsonAPI(fundTxVout) value
   */
  uint32_t fund_tx_vout_ = 0;
  /**
   * @brief JsonAPI(localFundPubkey) value
   */
  std::string local_fund_pubkey_ = "";
  /**
   * @brief JsonAPI(remoteFundPubkey) value
   */
  std::string remote_fund_pubkey_ = "";
};

// ------------------------------------------------------------------------
// AddSignaturesToMutualClosingTxResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (AddSignaturesToMutualClosingTxResponse) class
 */
class AddSignaturesToMutualClosingTxResponse
  : public cfd::core::JsonClassBase<AddSignaturesToMutualClosingTxResponse> {
 public:
  AddSignaturesToMutualClosingTxResponse() {
    CollectFieldName();
  }
  virtual ~AddSignaturesToMutualClosingTxResponse() {
    // do nothing
  }
  /**
   * @brief collect field name.
   */
  static void CollectFieldName();

  /**
   * @brief Get of hex
   * @return hex
   */
  std::string GetHex() const {
    return hex_;
  }
  /**
   * @brief Set to hex
   * @param[in] hex    setting value.
   */
  void SetHex(  // line separate
    const std::string& hex) {  // NOLINT
    this->hex_ = hex;
  }
  /**
   * @brief Get data type of hex
   * @return Data type of hex
   */
  static std::string GetHexFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of hex field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetHexString(  // line separate
      const AddSignaturesToMutualClosingTxResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.hex_);
  }
  /**
   * @brief Set json object to hex field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetHexString(  // line separate
      AddSignaturesToMutualClosingTxResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.hex_, json_value);
  }

  /**
   * @brief Set ignore item.
   * @param[in] key   ignore target key name.
   */
  void SetIgnoreItem(const std::string& key) {
    ignore_items.insert(key);
  }

  /**
   * @brief Convert struct to class.
   * @param[in] data   struct data.
   */
  void ConvertFromStruct(
      const AddSignaturesToMutualClosingTxResponseStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  AddSignaturesToMutualClosingTxResponseStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using AddSignaturesToMutualClosingTxResponseMapTable =
    cfd::core::JsonTableMap<AddSignaturesToMutualClosingTxResponse>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const AddSignaturesToMutualClosingTxResponseMapTable& GetJsonMapper() const {  // NOLINT
    return json_mapper;
  }
  /**
   * @brief Get item lists of JSON mapping.
   * Fetch a list of target variable names in the order of definition.
   * @return Item lists of JSON mapping.
   * @see cfd::core::JsonClassBase::GetJsonItemList()
   */
  virtual const std::vector<std::string>& GetJsonItemList() const {
    return item_list;
  }
  /**
   * @brief Get ignore item lists of JSON mnapping.
   * Ignore the target variable at Serialize.
   * @return Item list of JSON mapping.
   * @see cfd::core::JsonClassBase::GetIgnoreItem()
   */
  virtual const std::set<std::string>& GetIgnoreItem() const {
    return ignore_items;
  }

 private:
 /**
  * @brief JsonFunctionMap table
  */
  static AddSignaturesToMutualClosingTxResponseMapTable json_mapper;
  /**
   * @brief field name list.
   */
  static std::vector<std::string> item_list;
  /**
   * @brief ignore item list.
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(hex) value
   */
  std::string hex_ = "";
};

// ------------------------------------------------------------------------
// AddSignaturesToRefundTxRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (AddSignaturesToRefundTxRequest) class
 */
class AddSignaturesToRefundTxRequest
  : public cfd::core::JsonClassBase<AddSignaturesToRefundTxRequest> {
 public:
  AddSignaturesToRefundTxRequest() {
    CollectFieldName();
  }
  virtual ~AddSignaturesToRefundTxRequest() {
    // do nothing
  }
  /**
   * @brief collect field name.
   */
  static void CollectFieldName();

  /**
   * @brief Get of refundTxHex
   * @return refundTxHex
   */
  std::string GetRefundTxHex() const {
    return refund_tx_hex_;
  }
  /**
   * @brief Set to refundTxHex
   * @param[in] refund_tx_hex    setting value.
   */
  void SetRefundTxHex(  // line separate
    const std::string& refund_tx_hex) {  // NOLINT
    this->refund_tx_hex_ = refund_tx_hex;
  }
  /**
   * @brief Get data type of refundTxHex
   * @return Data type of refundTxHex
   */
  static std::string GetRefundTxHexFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of refundTxHex field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetRefundTxHexString(  // line separate
      const AddSignaturesToRefundTxRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.refund_tx_hex_);
  }
  /**
   * @brief Set json object to refundTxHex field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetRefundTxHexString(  // line separate
      AddSignaturesToRefundTxRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.refund_tx_hex_, json_value);
  }

  /**
   * @brief Get of signatures.
   * @return signatures
   */
  JsonValueVector<std::string>& GetSignatures() {  // NOLINT
    return signatures_;
  }
  /**
   * @brief Set to signatures.
   * @param[in] signatures    setting value.
   */
  void SetSignatures(  // line separate
      const JsonValueVector<std::string>& signatures) {  // NOLINT
    this->signatures_ = signatures;
  }
  /**
   * @brief Get data type of signatures.
   * @return Data type of signatures.
   */
  static std::string GetSignaturesFieldType() {
    return "JsonValueVector<std::string>";  // NOLINT
  }
  /**
   * @brief Get json string of signatures field.
   * @param[in,out] obj     class object
   * @return JSON string.
   */
  static std::string GetSignaturesString(  // line separate
      const AddSignaturesToRefundTxRequest& obj) {  // NOLINT
    // Do not set to const, because substitution of member variables
    // may occur in pre / post processing inside Serialize
    return obj.signatures_.Serialize();
  }
  /**
   * @brief Set json object to signatures field.
   * @param[in,out] obj     class object
   * @param[in] json_value  JSON object
   */
  static void SetSignaturesString(  // line separate
      AddSignaturesToRefundTxRequest& obj,  // NOLINT
      const UniValue& json_value) {
    obj.signatures_.DeserializeUniValue(json_value);
  }

  /**
   * @brief Get of fundTxId
   * @return fundTxId
   */
  std::string GetFundTxId() const {
    return fund_tx_id_;
  }
  /**
   * @brief Set to fundTxId
   * @param[in] fund_tx_id    setting value.
   */
  void SetFundTxId(  // line separate
    const std::string& fund_tx_id) {  // NOLINT
    this->fund_tx_id_ = fund_tx_id;
  }
  /**
   * @brief Get data type of fundTxId
   * @return Data type of fundTxId
   */
  static std::string GetFundTxIdFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of fundTxId field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetFundTxIdString(  // line separate
      const AddSignaturesToRefundTxRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fund_tx_id_);
  }
  /**
   * @brief Set json object to fundTxId field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFundTxIdString(  // line separate
      AddSignaturesToRefundTxRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.fund_tx_id_, json_value);
  }

  /**
   * @brief Get of fundTxVout
   * @return fundTxVout
   */
  uint32_t GetFundTxVout() const {
    return fund_tx_vout_;
  }
  /**
   * @brief Set to fundTxVout
   * @param[in] fund_tx_vout    setting value.
   */
  void SetFundTxVout(  // line separate
    const uint32_t& fund_tx_vout) {  // NOLINT
    this->fund_tx_vout_ = fund_tx_vout;
  }
  /**
   * @brief Get data type of fundTxVout
   * @return Data type of fundTxVout
   */
  static std::string GetFundTxVoutFieldType() {
    return "uint32_t";
  }
  /**
   * @brief Get json string of fundTxVout field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetFundTxVoutString(  // line separate
      const AddSignaturesToRefundTxRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fund_tx_vout_);
  }
  /**
   * @brief Set json object to fundTxVout field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFundTxVoutString(  // line separate
      AddSignaturesToRefundTxRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.fund_tx_vout_, json_value);
  }

  /**
   * @brief Get of localFundPubkey
   * @return localFundPubkey
   */
  std::string GetLocalFundPubkey() const {
    return local_fund_pubkey_;
  }
  /**
   * @brief Set to localFundPubkey
   * @param[in] local_fund_pubkey    setting value.
   */
  void SetLocalFundPubkey(  // line separate
    const std::string& local_fund_pubkey) {  // NOLINT
    this->local_fund_pubkey_ = local_fund_pubkey;
  }
  /**
   * @brief Get data type of localFundPubkey
   * @return Data type of localFundPubkey
   */
  static std::string GetLocalFundPubkeyFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of localFundPubkey field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetLocalFundPubkeyString(  // line separate
      const AddSignaturesToRefundTxRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.local_fund_pubkey_);
  }
  /**
   * @brief Set json object to localFundPubkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetLocalFundPubkeyString(  // line separate
      AddSignaturesToRefundTxRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.local_fund_pubkey_, json_value);
  }

  /**
   * @brief Get of remoteFundPubkey
   * @return remoteFundPubkey
   */
  std::string GetRemoteFundPubkey() const {
    return remote_fund_pubkey_;
  }
  /**
   * @brief Set to remoteFundPubkey
   * @param[in] remote_fund_pubkey    setting value.
   */
  void SetRemoteFundPubkey(  // line separate
    const std::string& remote_fund_pubkey) {  // NOLINT
    this->remote_fund_pubkey_ = remote_fund_pubkey;
  }
  /**
   * @brief Get data type of remoteFundPubkey
   * @return Data type of remoteFundPubkey
   */
  static std::string GetRemoteFundPubkeyFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of remoteFundPubkey field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetRemoteFundPubkeyString(  // line separate
      const AddSignaturesToRefundTxRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.remote_fund_pubkey_);
  }
  /**
   * @brief Set json object to remoteFundPubkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetRemoteFundPubkeyString(  // line separate
      AddSignaturesToRefundTxRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.remote_fund_pubkey_, json_value);
  }

  /**
   * @brief Set ignore item.
   * @param[in] key   ignore target key name.
   */
  void SetIgnoreItem(const std::string& key) {
    ignore_items.insert(key);
  }

  /**
   * @brief Convert struct to class.
   * @param[in] data   struct data.
   */
  void ConvertFromStruct(
      const AddSignaturesToRefundTxRequestStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  AddSignaturesToRefundTxRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using AddSignaturesToRefundTxRequestMapTable =
    cfd::core::JsonTableMap<AddSignaturesToRefundTxRequest>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const AddSignaturesToRefundTxRequestMapTable& GetJsonMapper() const {  // NOLINT
    return json_mapper;
  }
  /**
   * @brief Get item lists of JSON mapping.
   * Fetch a list of target variable names in the order of definition.
   * @return Item lists of JSON mapping.
   * @see cfd::core::JsonClassBase::GetJsonItemList()
   */
  virtual const std::vector<std::string>& GetJsonItemList() const {
    return item_list;
  }
  /**
   * @brief Get ignore item lists of JSON mnapping.
   * Ignore the target variable at Serialize.
   * @return Item list of JSON mapping.
   * @see cfd::core::JsonClassBase::GetIgnoreItem()
   */
  virtual const std::set<std::string>& GetIgnoreItem() const {
    return ignore_items;
  }

 private:
 /**
  * @brief JsonFunctionMap table
  */
  static AddSignaturesToRefundTxRequestMapTable json_mapper;
  /**
   * @brief field name list.
   */
  static std::vector<std::string> item_list;
  /**
   * @brief ignore item list.
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(refundTxHex) value
   */
  std::string refund_tx_hex_ = "";
  /**
   * @brief JsonAPI(signatures) value
   */
  JsonValueVector<std::string> signatures_;  // NOLINT
  /**
   * @brief JsonAPI(fundTxId) value
   */
  std::string fund_tx_id_ = "";
  /**
   * @brief JsonAPI(fundTxVout) value
   */
  uint32_t fund_tx_vout_ = 0;
  /**
   * @brief JsonAPI(localFundPubkey) value
   */
  std::string local_fund_pubkey_ = "";
  /**
   * @brief JsonAPI(remoteFundPubkey) value
   */
  std::string remote_fund_pubkey_ = "";
};

// ------------------------------------------------------------------------
// AddSignaturesToRefundTxResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (AddSignaturesToRefundTxResponse) class
 */
class AddSignaturesToRefundTxResponse
  : public cfd::core::JsonClassBase<AddSignaturesToRefundTxResponse> {
 public:
  AddSignaturesToRefundTxResponse() {
    CollectFieldName();
  }
  virtual ~AddSignaturesToRefundTxResponse() {
    // do nothing
  }
  /**
   * @brief collect field name.
   */
  static void CollectFieldName();

  /**
   * @brief Get of hex
   * @return hex
   */
  std::string GetHex() const {
    return hex_;
  }
  /**
   * @brief Set to hex
   * @param[in] hex    setting value.
   */
  void SetHex(  // line separate
    const std::string& hex) {  // NOLINT
    this->hex_ = hex;
  }
  /**
   * @brief Get data type of hex
   * @return Data type of hex
   */
  static std::string GetHexFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of hex field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetHexString(  // line separate
      const AddSignaturesToRefundTxResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.hex_);
  }
  /**
   * @brief Set json object to hex field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetHexString(  // line separate
      AddSignaturesToRefundTxResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.hex_, json_value);
  }

  /**
   * @brief Set ignore item.
   * @param[in] key   ignore target key name.
   */
  void SetIgnoreItem(const std::string& key) {
    ignore_items.insert(key);
  }

  /**
   * @brief Convert struct to class.
   * @param[in] data   struct data.
   */
  void ConvertFromStruct(
      const AddSignaturesToRefundTxResponseStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  AddSignaturesToRefundTxResponseStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using AddSignaturesToRefundTxResponseMapTable =
    cfd::core::JsonTableMap<AddSignaturesToRefundTxResponse>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const AddSignaturesToRefundTxResponseMapTable& GetJsonMapper() const {  // NOLINT
    return json_mapper;
  }
  /**
   * @brief Get item lists of JSON mapping.
   * Fetch a list of target variable names in the order of definition.
   * @return Item lists of JSON mapping.
   * @see cfd::core::JsonClassBase::GetJsonItemList()
   */
  virtual const std::vector<std::string>& GetJsonItemList() const {
    return item_list;
  }
  /**
   * @brief Get ignore item lists of JSON mnapping.
   * Ignore the target variable at Serialize.
   * @return Item list of JSON mapping.
   * @see cfd::core::JsonClassBase::GetIgnoreItem()
   */
  virtual const std::set<std::string>& GetIgnoreItem() const {
    return ignore_items;
  }

 private:
 /**
  * @brief JsonFunctionMap table
  */
  static AddSignaturesToRefundTxResponseMapTable json_mapper;
  /**
   * @brief field name list.
   */
  static std::vector<std::string> item_list;
  /**
   * @brief ignore item list.
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(hex) value
   */
  std::string hex_ = "";
};

// ------------------------------------------------------------------------
// CreateCETRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (CreateCETRequest) class
 */
class CreateCETRequest
  : public cfd::core::JsonClassBase<CreateCETRequest> {
 public:
  CreateCETRequest() {
    CollectFieldName();
  }
  virtual ~CreateCETRequest() {
    // do nothing
  }
  /**
   * @brief collect field name.
   */
  static void CollectFieldName();

  /**
   * @brief Get of localFundPubkey
   * @return localFundPubkey
   */
  std::string GetLocalFundPubkey() const {
    return local_fund_pubkey_;
  }
  /**
   * @brief Set to localFundPubkey
   * @param[in] local_fund_pubkey    setting value.
   */
  void SetLocalFundPubkey(  // line separate
    const std::string& local_fund_pubkey) {  // NOLINT
    this->local_fund_pubkey_ = local_fund_pubkey;
  }
  /**
   * @brief Get data type of localFundPubkey
   * @return Data type of localFundPubkey
   */
  static std::string GetLocalFundPubkeyFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of localFundPubkey field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetLocalFundPubkeyString(  // line separate
      const CreateCETRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.local_fund_pubkey_);
  }
  /**
   * @brief Set json object to localFundPubkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetLocalFundPubkeyString(  // line separate
      CreateCETRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.local_fund_pubkey_, json_value);
  }

  /**
   * @brief Get of localSweepPubkey
   * @return localSweepPubkey
   */
  std::string GetLocalSweepPubkey() const {
    return local_sweep_pubkey_;
  }
  /**
   * @brief Set to localSweepPubkey
   * @param[in] local_sweep_pubkey    setting value.
   */
  void SetLocalSweepPubkey(  // line separate
    const std::string& local_sweep_pubkey) {  // NOLINT
    this->local_sweep_pubkey_ = local_sweep_pubkey;
  }
  /**
   * @brief Get data type of localSweepPubkey
   * @return Data type of localSweepPubkey
   */
  static std::string GetLocalSweepPubkeyFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of localSweepPubkey field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetLocalSweepPubkeyString(  // line separate
      const CreateCETRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.local_sweep_pubkey_);
  }
  /**
   * @brief Set json object to localSweepPubkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetLocalSweepPubkeyString(  // line separate
      CreateCETRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.local_sweep_pubkey_, json_value);
  }

  /**
   * @brief Get of remoteSweepPubkey
   * @return remoteSweepPubkey
   */
  std::string GetRemoteSweepPubkey() const {
    return remote_sweep_pubkey_;
  }
  /**
   * @brief Set to remoteSweepPubkey
   * @param[in] remote_sweep_pubkey    setting value.
   */
  void SetRemoteSweepPubkey(  // line separate
    const std::string& remote_sweep_pubkey) {  // NOLINT
    this->remote_sweep_pubkey_ = remote_sweep_pubkey;
  }
  /**
   * @brief Get data type of remoteSweepPubkey
   * @return Data type of remoteSweepPubkey
   */
  static std::string GetRemoteSweepPubkeyFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of remoteSweepPubkey field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetRemoteSweepPubkeyString(  // line separate
      const CreateCETRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.remote_sweep_pubkey_);
  }
  /**
   * @brief Set json object to remoteSweepPubkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetRemoteSweepPubkeyString(  // line separate
      CreateCETRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.remote_sweep_pubkey_, json_value);
  }

  /**
   * @brief Get of remoteFinalAddress
   * @return remoteFinalAddress
   */
  std::string GetRemoteFinalAddress() const {
    return remote_final_address_;
  }
  /**
   * @brief Set to remoteFinalAddress
   * @param[in] remote_final_address    setting value.
   */
  void SetRemoteFinalAddress(  // line separate
    const std::string& remote_final_address) {  // NOLINT
    this->remote_final_address_ = remote_final_address;
  }
  /**
   * @brief Get data type of remoteFinalAddress
   * @return Data type of remoteFinalAddress
   */
  static std::string GetRemoteFinalAddressFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of remoteFinalAddress field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetRemoteFinalAddressString(  // line separate
      const CreateCETRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.remote_final_address_);
  }
  /**
   * @brief Set json object to remoteFinalAddress field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetRemoteFinalAddressString(  // line separate
      CreateCETRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.remote_final_address_, json_value);
  }

  /**
   * @brief Get of oraclePubkey
   * @return oraclePubkey
   */
  std::string GetOraclePubkey() const {
    return oracle_pubkey_;
  }
  /**
   * @brief Set to oraclePubkey
   * @param[in] oracle_pubkey    setting value.
   */
  void SetOraclePubkey(  // line separate
    const std::string& oracle_pubkey) {  // NOLINT
    this->oracle_pubkey_ = oracle_pubkey;
  }
  /**
   * @brief Get data type of oraclePubkey
   * @return Data type of oraclePubkey
   */
  static std::string GetOraclePubkeyFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of oraclePubkey field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetOraclePubkeyString(  // line separate
      const CreateCETRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.oracle_pubkey_);
  }
  /**
   * @brief Set json object to oraclePubkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetOraclePubkeyString(  // line separate
      CreateCETRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.oracle_pubkey_, json_value);
  }

  /**
   * @brief Get of oracleRPoints.
   * @return oracleRPoints
   */
  JsonValueVector<std::string>& GetOracleRPoints() {  // NOLINT
    return oracle_r_points_;
  }
  /**
   * @brief Set to oracleRPoints.
   * @param[in] oracle_r_points    setting value.
   */
  void SetOracleRPoints(  // line separate
      const JsonValueVector<std::string>& oracle_r_points) {  // NOLINT
    this->oracle_r_points_ = oracle_r_points;
  }
  /**
   * @brief Get data type of oracleRPoints.
   * @return Data type of oracleRPoints.
   */
  static std::string GetOracleRPointsFieldType() {
    return "JsonValueVector<std::string>";  // NOLINT
  }
  /**
   * @brief Get json string of oracleRPoints field.
   * @param[in,out] obj     class object
   * @return JSON string.
   */
  static std::string GetOracleRPointsString(  // line separate
      const CreateCETRequest& obj) {  // NOLINT
    // Do not set to const, because substitution of member variables
    // may occur in pre / post processing inside Serialize
    return obj.oracle_r_points_.Serialize();
  }
  /**
   * @brief Set json object to oracleRPoints field.
   * @param[in,out] obj     class object
   * @param[in] json_value  JSON object
   */
  static void SetOracleRPointsString(  // line separate
      CreateCETRequest& obj,  // NOLINT
      const UniValue& json_value) {
    obj.oracle_r_points_.DeserializeUniValue(json_value);
  }

  /**
   * @brief Get of messages.
   * @return messages
   */
  JsonValueVector<std::string>& GetMessages() {  // NOLINT
    return messages_;
  }
  /**
   * @brief Set to messages.
   * @param[in] messages    setting value.
   */
  void SetMessages(  // line separate
      const JsonValueVector<std::string>& messages) {  // NOLINT
    this->messages_ = messages;
  }
  /**
   * @brief Get data type of messages.
   * @return Data type of messages.
   */
  static std::string GetMessagesFieldType() {
    return "JsonValueVector<std::string>";  // NOLINT
  }
  /**
   * @brief Get json string of messages field.
   * @param[in,out] obj     class object
   * @return JSON string.
   */
  static std::string GetMessagesString(  // line separate
      const CreateCETRequest& obj) {  // NOLINT
    // Do not set to const, because substitution of member variables
    // may occur in pre / post processing inside Serialize
    return obj.messages_.Serialize();
  }
  /**
   * @brief Set json object to messages field.
   * @param[in,out] obj     class object
   * @param[in] json_value  JSON object
   */
  static void SetMessagesString(  // line separate
      CreateCETRequest& obj,  // NOLINT
      const UniValue& json_value) {
    obj.messages_.DeserializeUniValue(json_value);
  }

  /**
   * @brief Get of delay
   * @return delay
   */
  uint32_t GetDelay() const {
    return delay_;
  }
  /**
   * @brief Set to delay
   * @param[in] delay    setting value.
   */
  void SetDelay(  // line separate
    const uint32_t& delay) {  // NOLINT
    this->delay_ = delay;
  }
  /**
   * @brief Get data type of delay
   * @return Data type of delay
   */
  static std::string GetDelayFieldType() {
    return "uint32_t";
  }
  /**
   * @brief Get json string of delay field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetDelayString(  // line separate
      const CreateCETRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.delay_);
  }
  /**
   * @brief Set json object to delay field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetDelayString(  // line separate
      CreateCETRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.delay_, json_value);
  }

  /**
   * @brief Get of localPayout
   * @return localPayout
   */
  uint64_t GetLocalPayout() const {
    return local_payout_;
  }
  /**
   * @brief Set to localPayout
   * @param[in] local_payout    setting value.
   */
  void SetLocalPayout(  // line separate
    const uint64_t& local_payout) {  // NOLINT
    this->local_payout_ = local_payout;
  }
  /**
   * @brief Get data type of localPayout
   * @return Data type of localPayout
   */
  static std::string GetLocalPayoutFieldType() {
    return "uint64_t";
  }
  /**
   * @brief Get json string of localPayout field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetLocalPayoutString(  // line separate
      const CreateCETRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.local_payout_);
  }
  /**
   * @brief Set json object to localPayout field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetLocalPayoutString(  // line separate
      CreateCETRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.local_payout_, json_value);
  }

  /**
   * @brief Get of remotePayout
   * @return remotePayout
   */
  uint64_t GetRemotePayout() const {
    return remote_payout_;
  }
  /**
   * @brief Set to remotePayout
   * @param[in] remote_payout    setting value.
   */
  void SetRemotePayout(  // line separate
    const uint64_t& remote_payout) {  // NOLINT
    this->remote_payout_ = remote_payout;
  }
  /**
   * @brief Get data type of remotePayout
   * @return Data type of remotePayout
   */
  static std::string GetRemotePayoutFieldType() {
    return "uint64_t";
  }
  /**
   * @brief Get json string of remotePayout field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetRemotePayoutString(  // line separate
      const CreateCETRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.remote_payout_);
  }
  /**
   * @brief Set json object to remotePayout field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetRemotePayoutString(  // line separate
      CreateCETRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.remote_payout_, json_value);
  }

  /**
   * @brief Get of fundTxid
   * @return fundTxid
   */
  std::string GetFundTxid() const {
    return fund_txid_;
  }
  /**
   * @brief Set to fundTxid
   * @param[in] fund_txid    setting value.
   */
  void SetFundTxid(  // line separate
    const std::string& fund_txid) {  // NOLINT
    this->fund_txid_ = fund_txid;
  }
  /**
   * @brief Get data type of fundTxid
   * @return Data type of fundTxid
   */
  static std::string GetFundTxidFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of fundTxid field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetFundTxidString(  // line separate
      const CreateCETRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fund_txid_);
  }
  /**
   * @brief Set json object to fundTxid field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFundTxidString(  // line separate
      CreateCETRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.fund_txid_, json_value);
  }

  /**
   * @brief Get of fundVout
   * @return fundVout
   */
  uint32_t GetFundVout() const {
    return fund_vout_;
  }
  /**
   * @brief Set to fundVout
   * @param[in] fund_vout    setting value.
   */
  void SetFundVout(  // line separate
    const uint32_t& fund_vout) {  // NOLINT
    this->fund_vout_ = fund_vout;
  }
  /**
   * @brief Get data type of fundVout
   * @return Data type of fundVout
   */
  static std::string GetFundVoutFieldType() {
    return "uint32_t";
  }
  /**
   * @brief Get json string of fundVout field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetFundVoutString(  // line separate
      const CreateCETRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fund_vout_);
  }
  /**
   * @brief Set json object to fundVout field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFundVoutString(  // line separate
      CreateCETRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.fund_vout_, json_value);
  }

  /**
   * @brief Get of maturityTime
   * @return maturityTime
   */
  uint64_t GetMaturityTime() const {
    return maturity_time_;
  }
  /**
   * @brief Set to maturityTime
   * @param[in] maturity_time    setting value.
   */
  void SetMaturityTime(  // line separate
    const uint64_t& maturity_time) {  // NOLINT
    this->maturity_time_ = maturity_time;
  }
  /**
   * @brief Get data type of maturityTime
   * @return Data type of maturityTime
   */
  static std::string GetMaturityTimeFieldType() {
    return "uint64_t";
  }
  /**
   * @brief Get json string of maturityTime field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetMaturityTimeString(  // line separate
      const CreateCETRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.maturity_time_);
  }
  /**
   * @brief Set json object to maturityTime field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetMaturityTimeString(  // line separate
      CreateCETRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.maturity_time_, json_value);
  }

  /**
   * @brief Set ignore item.
   * @param[in] key   ignore target key name.
   */
  void SetIgnoreItem(const std::string& key) {
    ignore_items.insert(key);
  }

  /**
   * @brief Convert struct to class.
   * @param[in] data   struct data.
   */
  void ConvertFromStruct(
      const CreateCETRequestStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  CreateCETRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using CreateCETRequestMapTable =
    cfd::core::JsonTableMap<CreateCETRequest>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const CreateCETRequestMapTable& GetJsonMapper() const {  // NOLINT
    return json_mapper;
  }
  /**
   * @brief Get item lists of JSON mapping.
   * Fetch a list of target variable names in the order of definition.
   * @return Item lists of JSON mapping.
   * @see cfd::core::JsonClassBase::GetJsonItemList()
   */
  virtual const std::vector<std::string>& GetJsonItemList() const {
    return item_list;
  }
  /**
   * @brief Get ignore item lists of JSON mnapping.
   * Ignore the target variable at Serialize.
   * @return Item list of JSON mapping.
   * @see cfd::core::JsonClassBase::GetIgnoreItem()
   */
  virtual const std::set<std::string>& GetIgnoreItem() const {
    return ignore_items;
  }

 private:
 /**
  * @brief JsonFunctionMap table
  */
  static CreateCETRequestMapTable json_mapper;
  /**
   * @brief field name list.
   */
  static std::vector<std::string> item_list;
  /**
   * @brief ignore item list.
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(localFundPubkey) value
   */
  std::string local_fund_pubkey_ = "";
  /**
   * @brief JsonAPI(localSweepPubkey) value
   */
  std::string local_sweep_pubkey_ = "";
  /**
   * @brief JsonAPI(remoteSweepPubkey) value
   */
  std::string remote_sweep_pubkey_ = "";
  /**
   * @brief JsonAPI(remoteFinalAddress) value
   */
  std::string remote_final_address_ = "";
  /**
   * @brief JsonAPI(oraclePubkey) value
   */
  std::string oracle_pubkey_ = "";
  /**
   * @brief JsonAPI(oracleRPoints) value
   */
  JsonValueVector<std::string> oracle_r_points_;  // NOLINT
  /**
   * @brief JsonAPI(messages) value
   */
  JsonValueVector<std::string> messages_;  // NOLINT
  /**
   * @brief JsonAPI(delay) value
   */
  uint32_t delay_ = 0;
  /**
   * @brief JsonAPI(localPayout) value
   */
  uint64_t local_payout_ = 0;
  /**
   * @brief JsonAPI(remotePayout) value
   */
  uint64_t remote_payout_ = 0;
  /**
   * @brief JsonAPI(fundTxid) value
   */
  std::string fund_txid_ = "";
  /**
   * @brief JsonAPI(fundVout) value
   */
  uint32_t fund_vout_ = 0;
  /**
   * @brief JsonAPI(maturityTime) value
   */
  uint64_t maturity_time_ = 0;
};

// ------------------------------------------------------------------------
// CreateCETResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (CreateCETResponse) class
 */
class CreateCETResponse
  : public cfd::core::JsonClassBase<CreateCETResponse> {
 public:
  CreateCETResponse() {
    CollectFieldName();
  }
  virtual ~CreateCETResponse() {
    // do nothing
  }
  /**
   * @brief collect field name.
   */
  static void CollectFieldName();

  /**
   * @brief Get of hex
   * @return hex
   */
  std::string GetHex() const {
    return hex_;
  }
  /**
   * @brief Set to hex
   * @param[in] hex    setting value.
   */
  void SetHex(  // line separate
    const std::string& hex) {  // NOLINT
    this->hex_ = hex;
  }
  /**
   * @brief Get data type of hex
   * @return Data type of hex
   */
  static std::string GetHexFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of hex field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetHexString(  // line separate
      const CreateCETResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.hex_);
  }
  /**
   * @brief Set json object to hex field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetHexString(  // line separate
      CreateCETResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.hex_, json_value);
  }

  /**
   * @brief Set ignore item.
   * @param[in] key   ignore target key name.
   */
  void SetIgnoreItem(const std::string& key) {
    ignore_items.insert(key);
  }

  /**
   * @brief Convert struct to class.
   * @param[in] data   struct data.
   */
  void ConvertFromStruct(
      const CreateCETResponseStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  CreateCETResponseStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using CreateCETResponseMapTable =
    cfd::core::JsonTableMap<CreateCETResponse>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const CreateCETResponseMapTable& GetJsonMapper() const {  // NOLINT
    return json_mapper;
  }
  /**
   * @brief Get item lists of JSON mapping.
   * Fetch a list of target variable names in the order of definition.
   * @return Item lists of JSON mapping.
   * @see cfd::core::JsonClassBase::GetJsonItemList()
   */
  virtual const std::vector<std::string>& GetJsonItemList() const {
    return item_list;
  }
  /**
   * @brief Get ignore item lists of JSON mnapping.
   * Ignore the target variable at Serialize.
   * @return Item list of JSON mapping.
   * @see cfd::core::JsonClassBase::GetIgnoreItem()
   */
  virtual const std::set<std::string>& GetIgnoreItem() const {
    return ignore_items;
  }

 private:
 /**
  * @brief JsonFunctionMap table
  */
  static CreateCETResponseMapTable json_mapper;
  /**
   * @brief field name list.
   */
  static std::vector<std::string> item_list;
  /**
   * @brief ignore item list.
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(hex) value
   */
  std::string hex_ = "";
};

// ------------------------------------------------------------------------
// CreateClosingTransactionRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (CreateClosingTransactionRequest) class
 */
class CreateClosingTransactionRequest
  : public cfd::core::JsonClassBase<CreateClosingTransactionRequest> {
 public:
  CreateClosingTransactionRequest() {
    CollectFieldName();
  }
  virtual ~CreateClosingTransactionRequest() {
    // do nothing
  }
  /**
   * @brief collect field name.
   */
  static void CollectFieldName();

  /**
   * @brief Get of address
   * @return address
   */
  std::string GetAddress() const {
    return address_;
  }
  /**
   * @brief Set to address
   * @param[in] address    setting value.
   */
  void SetAddress(  // line separate
    const std::string& address) {  // NOLINT
    this->address_ = address;
  }
  /**
   * @brief Get data type of address
   * @return Data type of address
   */
  static std::string GetAddressFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of address field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetAddressString(  // line separate
      const CreateClosingTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.address_);
  }
  /**
   * @brief Set json object to address field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetAddressString(  // line separate
      CreateClosingTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.address_, json_value);
  }

  /**
   * @brief Get of amount
   * @return amount
   */
  uint64_t GetAmount() const {
    return amount_;
  }
  /**
   * @brief Set to amount
   * @param[in] amount    setting value.
   */
  void SetAmount(  // line separate
    const uint64_t& amount) {  // NOLINT
    this->amount_ = amount;
  }
  /**
   * @brief Get data type of amount
   * @return Data type of amount
   */
  static std::string GetAmountFieldType() {
    return "uint64_t";
  }
  /**
   * @brief Get json string of amount field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetAmountString(  // line separate
      const CreateClosingTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.amount_);
  }
  /**
   * @brief Set json object to amount field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetAmountString(  // line separate
      CreateClosingTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.amount_, json_value);
  }

  /**
   * @brief Get of cetTxid
   * @return cetTxid
   */
  std::string GetCetTxid() const {
    return cet_txid_;
  }
  /**
   * @brief Set to cetTxid
   * @param[in] cet_txid    setting value.
   */
  void SetCetTxid(  // line separate
    const std::string& cet_txid) {  // NOLINT
    this->cet_txid_ = cet_txid;
  }
  /**
   * @brief Get data type of cetTxid
   * @return Data type of cetTxid
   */
  static std::string GetCetTxidFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of cetTxid field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetCetTxidString(  // line separate
      const CreateClosingTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.cet_txid_);
  }
  /**
   * @brief Set json object to cetTxid field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetCetTxidString(  // line separate
      CreateClosingTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.cet_txid_, json_value);
  }

  /**
   * @brief Get of cetVout
   * @return cetVout
   */
  uint32_t GetCetVout() const {
    return cet_vout_;
  }
  /**
   * @brief Set to cetVout
   * @param[in] cet_vout    setting value.
   */
  void SetCetVout(  // line separate
    const uint32_t& cet_vout) {  // NOLINT
    this->cet_vout_ = cet_vout;
  }
  /**
   * @brief Get data type of cetVout
   * @return Data type of cetVout
   */
  static std::string GetCetVoutFieldType() {
    return "uint32_t";
  }
  /**
   * @brief Get json string of cetVout field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetCetVoutString(  // line separate
      const CreateClosingTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.cet_vout_);
  }
  /**
   * @brief Set json object to cetVout field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetCetVoutString(  // line separate
      CreateClosingTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.cet_vout_, json_value);
  }

  /**
   * @brief Set ignore item.
   * @param[in] key   ignore target key name.
   */
  void SetIgnoreItem(const std::string& key) {
    ignore_items.insert(key);
  }

  /**
   * @brief Convert struct to class.
   * @param[in] data   struct data.
   */
  void ConvertFromStruct(
      const CreateClosingTransactionRequestStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  CreateClosingTransactionRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using CreateClosingTransactionRequestMapTable =
    cfd::core::JsonTableMap<CreateClosingTransactionRequest>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const CreateClosingTransactionRequestMapTable& GetJsonMapper() const {  // NOLINT
    return json_mapper;
  }
  /**
   * @brief Get item lists of JSON mapping.
   * Fetch a list of target variable names in the order of definition.
   * @return Item lists of JSON mapping.
   * @see cfd::core::JsonClassBase::GetJsonItemList()
   */
  virtual const std::vector<std::string>& GetJsonItemList() const {
    return item_list;
  }
  /**
   * @brief Get ignore item lists of JSON mnapping.
   * Ignore the target variable at Serialize.
   * @return Item list of JSON mapping.
   * @see cfd::core::JsonClassBase::GetIgnoreItem()
   */
  virtual const std::set<std::string>& GetIgnoreItem() const {
    return ignore_items;
  }

 private:
 /**
  * @brief JsonFunctionMap table
  */
  static CreateClosingTransactionRequestMapTable json_mapper;
  /**
   * @brief field name list.
   */
  static std::vector<std::string> item_list;
  /**
   * @brief ignore item list.
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(address) value
   */
  std::string address_ = "";
  /**
   * @brief JsonAPI(amount) value
   */
  uint64_t amount_ = 0;
  /**
   * @brief JsonAPI(cetTxid) value
   */
  std::string cet_txid_ = "";
  /**
   * @brief JsonAPI(cetVout) value
   */
  uint32_t cet_vout_ = 0;
};

// ------------------------------------------------------------------------
// CreateClosingTransactionResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (CreateClosingTransactionResponse) class
 */
class CreateClosingTransactionResponse
  : public cfd::core::JsonClassBase<CreateClosingTransactionResponse> {
 public:
  CreateClosingTransactionResponse() {
    CollectFieldName();
  }
  virtual ~CreateClosingTransactionResponse() {
    // do nothing
  }
  /**
   * @brief collect field name.
   */
  static void CollectFieldName();

  /**
   * @brief Get of hex
   * @return hex
   */
  std::string GetHex() const {
    return hex_;
  }
  /**
   * @brief Set to hex
   * @param[in] hex    setting value.
   */
  void SetHex(  // line separate
    const std::string& hex) {  // NOLINT
    this->hex_ = hex;
  }
  /**
   * @brief Get data type of hex
   * @return Data type of hex
   */
  static std::string GetHexFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of hex field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetHexString(  // line separate
      const CreateClosingTransactionResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.hex_);
  }
  /**
   * @brief Set json object to hex field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetHexString(  // line separate
      CreateClosingTransactionResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.hex_, json_value);
  }

  /**
   * @brief Set ignore item.
   * @param[in] key   ignore target key name.
   */
  void SetIgnoreItem(const std::string& key) {
    ignore_items.insert(key);
  }

  /**
   * @brief Convert struct to class.
   * @param[in] data   struct data.
   */
  void ConvertFromStruct(
      const CreateClosingTransactionResponseStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  CreateClosingTransactionResponseStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using CreateClosingTransactionResponseMapTable =
    cfd::core::JsonTableMap<CreateClosingTransactionResponse>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const CreateClosingTransactionResponseMapTable& GetJsonMapper() const {  // NOLINT
    return json_mapper;
  }
  /**
   * @brief Get item lists of JSON mapping.
   * Fetch a list of target variable names in the order of definition.
   * @return Item lists of JSON mapping.
   * @see cfd::core::JsonClassBase::GetJsonItemList()
   */
  virtual const std::vector<std::string>& GetJsonItemList() const {
    return item_list;
  }
  /**
   * @brief Get ignore item lists of JSON mnapping.
   * Ignore the target variable at Serialize.
   * @return Item list of JSON mapping.
   * @see cfd::core::JsonClassBase::GetIgnoreItem()
   */
  virtual const std::set<std::string>& GetIgnoreItem() const {
    return ignore_items;
  }

 private:
 /**
  * @brief JsonFunctionMap table
  */
  static CreateClosingTransactionResponseMapTable json_mapper;
  /**
   * @brief field name list.
   */
  static std::vector<std::string> item_list;
  /**
   * @brief ignore item list.
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(hex) value
   */
  std::string hex_ = "";
};

// ------------------------------------------------------------------------
// PayoutRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (PayoutRequest) class
 */
class PayoutRequest
  : public cfd::core::JsonClassBase<PayoutRequest> {
 public:
  PayoutRequest() {
    CollectFieldName();
  }
  virtual ~PayoutRequest() {
    // do nothing
  }
  /**
   * @brief collect field name.
   */
  static void CollectFieldName();

  /**
   * @brief Get of local
   * @return local
   */
  uint64_t GetLocal() const {
    return local_;
  }
  /**
   * @brief Set to local
   * @param[in] local    setting value.
   */
  void SetLocal(  // line separate
    const uint64_t& local) {  // NOLINT
    this->local_ = local;
  }
  /**
   * @brief Get data type of local
   * @return Data type of local
   */
  static std::string GetLocalFieldType() {
    return "uint64_t";
  }
  /**
   * @brief Get json string of local field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetLocalString(  // line separate
      const PayoutRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.local_);
  }
  /**
   * @brief Set json object to local field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetLocalString(  // line separate
      PayoutRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.local_, json_value);
  }

  /**
   * @brief Get of remote
   * @return remote
   */
  uint64_t GetRemote() const {
    return remote_;
  }
  /**
   * @brief Set to remote
   * @param[in] remote    setting value.
   */
  void SetRemote(  // line separate
    const uint64_t& remote) {  // NOLINT
    this->remote_ = remote;
  }
  /**
   * @brief Get data type of remote
   * @return Data type of remote
   */
  static std::string GetRemoteFieldType() {
    return "uint64_t";
  }
  /**
   * @brief Get json string of remote field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetRemoteString(  // line separate
      const PayoutRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.remote_);
  }
  /**
   * @brief Set json object to remote field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetRemoteString(  // line separate
      PayoutRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.remote_, json_value);
  }

  /**
   * @brief Get of messages.
   * @return messages
   */
  JsonValueVector<std::string>& GetMessages() {  // NOLINT
    return messages_;
  }
  /**
   * @brief Set to messages.
   * @param[in] messages    setting value.
   */
  void SetMessages(  // line separate
      const JsonValueVector<std::string>& messages) {  // NOLINT
    this->messages_ = messages;
  }
  /**
   * @brief Get data type of messages.
   * @return Data type of messages.
   */
  static std::string GetMessagesFieldType() {
    return "JsonValueVector<std::string>";  // NOLINT
  }
  /**
   * @brief Get json string of messages field.
   * @param[in,out] obj     class object
   * @return JSON string.
   */
  static std::string GetMessagesString(  // line separate
      const PayoutRequest& obj) {  // NOLINT
    // Do not set to const, because substitution of member variables
    // may occur in pre / post processing inside Serialize
    return obj.messages_.Serialize();
  }
  /**
   * @brief Set json object to messages field.
   * @param[in,out] obj     class object
   * @param[in] json_value  JSON object
   */
  static void SetMessagesString(  // line separate
      PayoutRequest& obj,  // NOLINT
      const UniValue& json_value) {
    obj.messages_.DeserializeUniValue(json_value);
  }

  /**
   * @brief Set ignore item.
   * @param[in] key   ignore target key name.
   */
  void SetIgnoreItem(const std::string& key) {
    ignore_items.insert(key);
  }

  /**
   * @brief Convert struct to class.
   * @param[in] data   struct data.
   */
  void ConvertFromStruct(
      const PayoutRequestStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  PayoutRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using PayoutRequestMapTable =
    cfd::core::JsonTableMap<PayoutRequest>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const PayoutRequestMapTable& GetJsonMapper() const {  // NOLINT
    return json_mapper;
  }
  /**
   * @brief Get item lists of JSON mapping.
   * Fetch a list of target variable names in the order of definition.
   * @return Item lists of JSON mapping.
   * @see cfd::core::JsonClassBase::GetJsonItemList()
   */
  virtual const std::vector<std::string>& GetJsonItemList() const {
    return item_list;
  }
  /**
   * @brief Get ignore item lists of JSON mnapping.
   * Ignore the target variable at Serialize.
   * @return Item list of JSON mapping.
   * @see cfd::core::JsonClassBase::GetIgnoreItem()
   */
  virtual const std::set<std::string>& GetIgnoreItem() const {
    return ignore_items;
  }

 private:
 /**
  * @brief JsonFunctionMap table
  */
  static PayoutRequestMapTable json_mapper;
  /**
   * @brief field name list.
   */
  static std::vector<std::string> item_list;
  /**
   * @brief ignore item list.
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(local) value
   */
  uint64_t local_ = 0;
  /**
   * @brief JsonAPI(remote) value
   */
  uint64_t remote_ = 0;
  /**
   * @brief JsonAPI(messages) value
   */
  JsonValueVector<std::string> messages_;  // NOLINT
};

// ------------------------------------------------------------------------
// TxInRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (TxInRequest) class
 */
class TxInRequest
  : public cfd::core::JsonClassBase<TxInRequest> {
 public:
  TxInRequest() {
    CollectFieldName();
  }
  virtual ~TxInRequest() {
    // do nothing
  }
  /**
   * @brief collect field name.
   */
  static void CollectFieldName();

  /**
   * @brief Get of txid
   * @return txid
   */
  std::string GetTxid() const {
    return txid_;
  }
  /**
   * @brief Set to txid
   * @param[in] txid    setting value.
   */
  void SetTxid(  // line separate
    const std::string& txid) {  // NOLINT
    this->txid_ = txid;
  }
  /**
   * @brief Get data type of txid
   * @return Data type of txid
   */
  static std::string GetTxidFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of txid field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetTxidString(  // line separate
      const TxInRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.txid_);
  }
  /**
   * @brief Set json object to txid field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetTxidString(  // line separate
      TxInRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.txid_, json_value);
  }

  /**
   * @brief Get of vout
   * @return vout
   */
  uint32_t GetVout() const {
    return vout_;
  }
  /**
   * @brief Set to vout
   * @param[in] vout    setting value.
   */
  void SetVout(  // line separate
    const uint32_t& vout) {  // NOLINT
    this->vout_ = vout;
  }
  /**
   * @brief Get data type of vout
   * @return Data type of vout
   */
  static std::string GetVoutFieldType() {
    return "uint32_t";
  }
  /**
   * @brief Get json string of vout field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetVoutString(  // line separate
      const TxInRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.vout_);
  }
  /**
   * @brief Set json object to vout field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetVoutString(  // line separate
      TxInRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.vout_, json_value);
  }

  /**
   * @brief Set ignore item.
   * @param[in] key   ignore target key name.
   */
  void SetIgnoreItem(const std::string& key) {
    ignore_items.insert(key);
  }

  /**
   * @brief Convert struct to class.
   * @param[in] data   struct data.
   */
  void ConvertFromStruct(
      const TxInRequestStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  TxInRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using TxInRequestMapTable =
    cfd::core::JsonTableMap<TxInRequest>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const TxInRequestMapTable& GetJsonMapper() const {  // NOLINT
    return json_mapper;
  }
  /**
   * @brief Get item lists of JSON mapping.
   * Fetch a list of target variable names in the order of definition.
   * @return Item lists of JSON mapping.
   * @see cfd::core::JsonClassBase::GetJsonItemList()
   */
  virtual const std::vector<std::string>& GetJsonItemList() const {
    return item_list;
  }
  /**
   * @brief Get ignore item lists of JSON mnapping.
   * Ignore the target variable at Serialize.
   * @return Item list of JSON mapping.
   * @see cfd::core::JsonClassBase::GetIgnoreItem()
   */
  virtual const std::set<std::string>& GetIgnoreItem() const {
    return ignore_items;
  }

 private:
 /**
  * @brief JsonFunctionMap table
  */
  static TxInRequestMapTable json_mapper;
  /**
   * @brief field name list.
   */
  static std::vector<std::string> item_list;
  /**
   * @brief ignore item list.
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(txid) value
   */
  std::string txid_ = "";
  /**
   * @brief JsonAPI(vout) value
   */
  uint32_t vout_ = 0;
};

// ------------------------------------------------------------------------
// CreateDlcTransactionsRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (CreateDlcTransactionsRequest) class
 */
class CreateDlcTransactionsRequest
  : public cfd::core::JsonClassBase<CreateDlcTransactionsRequest> {
 public:
  CreateDlcTransactionsRequest() {
    CollectFieldName();
  }
  virtual ~CreateDlcTransactionsRequest() {
    // do nothing
  }
  /**
   * @brief collect field name.
   */
  static void CollectFieldName();

  /**
   * @brief Get of outcomes.
   * @return outcomes
   */
  JsonObjectVector<PayoutRequest, PayoutRequestStruct>& GetOutcomes() {  // NOLINT
    return outcomes_;
  }
  /**
   * @brief Set to outcomes.
   * @param[in] outcomes    setting value.
   */
  void SetOutcomes(  // line separate
      const JsonObjectVector<PayoutRequest, PayoutRequestStruct>& outcomes) {  // NOLINT
    this->outcomes_ = outcomes;
  }
  /**
   * @brief Get data type of outcomes.
   * @return Data type of outcomes.
   */
  static std::string GetOutcomesFieldType() {
    return "JsonObjectVector<PayoutRequest, PayoutRequestStruct>";  // NOLINT
  }
  /**
   * @brief Get json string of outcomes field.
   * @param[in,out] obj     class object
   * @return JSON string.
   */
  static std::string GetOutcomesString(  // line separate
      const CreateDlcTransactionsRequest& obj) {  // NOLINT
    // Do not set to const, because substitution of member variables
    // may occur in pre / post processing inside Serialize
    return obj.outcomes_.Serialize();
  }
  /**
   * @brief Set json object to outcomes field.
   * @param[in,out] obj     class object
   * @param[in] json_value  JSON object
   */
  static void SetOutcomesString(  // line separate
      CreateDlcTransactionsRequest& obj,  // NOLINT
      const UniValue& json_value) {
    obj.outcomes_.DeserializeUniValue(json_value);
  }

  /**
   * @brief Get of oracleRPoints.
   * @return oracleRPoints
   */
  JsonValueVector<std::string>& GetOracleRPoints() {  // NOLINT
    return oracle_r_points_;
  }
  /**
   * @brief Set to oracleRPoints.
   * @param[in] oracle_r_points    setting value.
   */
  void SetOracleRPoints(  // line separate
      const JsonValueVector<std::string>& oracle_r_points) {  // NOLINT
    this->oracle_r_points_ = oracle_r_points;
  }
  /**
   * @brief Get data type of oracleRPoints.
   * @return Data type of oracleRPoints.
   */
  static std::string GetOracleRPointsFieldType() {
    return "JsonValueVector<std::string>";  // NOLINT
  }
  /**
   * @brief Get json string of oracleRPoints field.
   * @param[in,out] obj     class object
   * @return JSON string.
   */
  static std::string GetOracleRPointsString(  // line separate
      const CreateDlcTransactionsRequest& obj) {  // NOLINT
    // Do not set to const, because substitution of member variables
    // may occur in pre / post processing inside Serialize
    return obj.oracle_r_points_.Serialize();
  }
  /**
   * @brief Set json object to oracleRPoints field.
   * @param[in,out] obj     class object
   * @param[in] json_value  JSON object
   */
  static void SetOracleRPointsString(  // line separate
      CreateDlcTransactionsRequest& obj,  // NOLINT
      const UniValue& json_value) {
    obj.oracle_r_points_.DeserializeUniValue(json_value);
  }

  /**
   * @brief Get of oraclePubkey
   * @return oraclePubkey
   */
  std::string GetOraclePubkey() const {
    return oracle_pubkey_;
  }
  /**
   * @brief Set to oraclePubkey
   * @param[in] oracle_pubkey    setting value.
   */
  void SetOraclePubkey(  // line separate
    const std::string& oracle_pubkey) {  // NOLINT
    this->oracle_pubkey_ = oracle_pubkey;
  }
  /**
   * @brief Get data type of oraclePubkey
   * @return Data type of oraclePubkey
   */
  static std::string GetOraclePubkeyFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of oraclePubkey field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetOraclePubkeyString(  // line separate
      const CreateDlcTransactionsRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.oracle_pubkey_);
  }
  /**
   * @brief Set json object to oraclePubkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetOraclePubkeyString(  // line separate
      CreateDlcTransactionsRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.oracle_pubkey_, json_value);
  }

  /**
   * @brief Get of localFundPubkey
   * @return localFundPubkey
   */
  std::string GetLocalFundPubkey() const {
    return local_fund_pubkey_;
  }
  /**
   * @brief Set to localFundPubkey
   * @param[in] local_fund_pubkey    setting value.
   */
  void SetLocalFundPubkey(  // line separate
    const std::string& local_fund_pubkey) {  // NOLINT
    this->local_fund_pubkey_ = local_fund_pubkey;
  }
  /**
   * @brief Get data type of localFundPubkey
   * @return Data type of localFundPubkey
   */
  static std::string GetLocalFundPubkeyFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of localFundPubkey field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetLocalFundPubkeyString(  // line separate
      const CreateDlcTransactionsRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.local_fund_pubkey_);
  }
  /**
   * @brief Set json object to localFundPubkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetLocalFundPubkeyString(  // line separate
      CreateDlcTransactionsRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.local_fund_pubkey_, json_value);
  }

  /**
   * @brief Get of localSweepPubkey
   * @return localSweepPubkey
   */
  std::string GetLocalSweepPubkey() const {
    return local_sweep_pubkey_;
  }
  /**
   * @brief Set to localSweepPubkey
   * @param[in] local_sweep_pubkey    setting value.
   */
  void SetLocalSweepPubkey(  // line separate
    const std::string& local_sweep_pubkey) {  // NOLINT
    this->local_sweep_pubkey_ = local_sweep_pubkey;
  }
  /**
   * @brief Get data type of localSweepPubkey
   * @return Data type of localSweepPubkey
   */
  static std::string GetLocalSweepPubkeyFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of localSweepPubkey field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetLocalSweepPubkeyString(  // line separate
      const CreateDlcTransactionsRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.local_sweep_pubkey_);
  }
  /**
   * @brief Set json object to localSweepPubkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetLocalSweepPubkeyString(  // line separate
      CreateDlcTransactionsRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.local_sweep_pubkey_, json_value);
  }

  /**
   * @brief Get of localFinalAddress
   * @return localFinalAddress
   */
  std::string GetLocalFinalAddress() const {
    return local_final_address_;
  }
  /**
   * @brief Set to localFinalAddress
   * @param[in] local_final_address    setting value.
   */
  void SetLocalFinalAddress(  // line separate
    const std::string& local_final_address) {  // NOLINT
    this->local_final_address_ = local_final_address;
  }
  /**
   * @brief Get data type of localFinalAddress
   * @return Data type of localFinalAddress
   */
  static std::string GetLocalFinalAddressFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of localFinalAddress field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetLocalFinalAddressString(  // line separate
      const CreateDlcTransactionsRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.local_final_address_);
  }
  /**
   * @brief Set json object to localFinalAddress field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetLocalFinalAddressString(  // line separate
      CreateDlcTransactionsRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.local_final_address_, json_value);
  }

  /**
   * @brief Get of remoteFundPubkey
   * @return remoteFundPubkey
   */
  std::string GetRemoteFundPubkey() const {
    return remote_fund_pubkey_;
  }
  /**
   * @brief Set to remoteFundPubkey
   * @param[in] remote_fund_pubkey    setting value.
   */
  void SetRemoteFundPubkey(  // line separate
    const std::string& remote_fund_pubkey) {  // NOLINT
    this->remote_fund_pubkey_ = remote_fund_pubkey;
  }
  /**
   * @brief Get data type of remoteFundPubkey
   * @return Data type of remoteFundPubkey
   */
  static std::string GetRemoteFundPubkeyFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of remoteFundPubkey field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetRemoteFundPubkeyString(  // line separate
      const CreateDlcTransactionsRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.remote_fund_pubkey_);
  }
  /**
   * @brief Set json object to remoteFundPubkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetRemoteFundPubkeyString(  // line separate
      CreateDlcTransactionsRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.remote_fund_pubkey_, json_value);
  }

  /**
   * @brief Get of remoteSweepPubkey
   * @return remoteSweepPubkey
   */
  std::string GetRemoteSweepPubkey() const {
    return remote_sweep_pubkey_;
  }
  /**
   * @brief Set to remoteSweepPubkey
   * @param[in] remote_sweep_pubkey    setting value.
   */
  void SetRemoteSweepPubkey(  // line separate
    const std::string& remote_sweep_pubkey) {  // NOLINT
    this->remote_sweep_pubkey_ = remote_sweep_pubkey;
  }
  /**
   * @brief Get data type of remoteSweepPubkey
   * @return Data type of remoteSweepPubkey
   */
  static std::string GetRemoteSweepPubkeyFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of remoteSweepPubkey field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetRemoteSweepPubkeyString(  // line separate
      const CreateDlcTransactionsRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.remote_sweep_pubkey_);
  }
  /**
   * @brief Set json object to remoteSweepPubkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetRemoteSweepPubkeyString(  // line separate
      CreateDlcTransactionsRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.remote_sweep_pubkey_, json_value);
  }

  /**
   * @brief Get of remoteFinalAddress
   * @return remoteFinalAddress
   */
  std::string GetRemoteFinalAddress() const {
    return remote_final_address_;
  }
  /**
   * @brief Set to remoteFinalAddress
   * @param[in] remote_final_address    setting value.
   */
  void SetRemoteFinalAddress(  // line separate
    const std::string& remote_final_address) {  // NOLINT
    this->remote_final_address_ = remote_final_address;
  }
  /**
   * @brief Get data type of remoteFinalAddress
   * @return Data type of remoteFinalAddress
   */
  static std::string GetRemoteFinalAddressFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of remoteFinalAddress field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetRemoteFinalAddressString(  // line separate
      const CreateDlcTransactionsRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.remote_final_address_);
  }
  /**
   * @brief Set json object to remoteFinalAddress field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetRemoteFinalAddressString(  // line separate
      CreateDlcTransactionsRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.remote_final_address_, json_value);
  }

  /**
   * @brief Get of localInputAmount
   * @return localInputAmount
   */
  uint64_t GetLocalInputAmount() const {
    return local_input_amount_;
  }
  /**
   * @brief Set to localInputAmount
   * @param[in] local_input_amount    setting value.
   */
  void SetLocalInputAmount(  // line separate
    const uint64_t& local_input_amount) {  // NOLINT
    this->local_input_amount_ = local_input_amount;
  }
  /**
   * @brief Get data type of localInputAmount
   * @return Data type of localInputAmount
   */
  static std::string GetLocalInputAmountFieldType() {
    return "uint64_t";
  }
  /**
   * @brief Get json string of localInputAmount field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetLocalInputAmountString(  // line separate
      const CreateDlcTransactionsRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.local_input_amount_);
  }
  /**
   * @brief Set json object to localInputAmount field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetLocalInputAmountString(  // line separate
      CreateDlcTransactionsRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.local_input_amount_, json_value);
  }

  /**
   * @brief Get of localCollateralAmount
   * @return localCollateralAmount
   */
  uint64_t GetLocalCollateralAmount() const {
    return local_collateral_amount_;
  }
  /**
   * @brief Set to localCollateralAmount
   * @param[in] local_collateral_amount    setting value.
   */
  void SetLocalCollateralAmount(  // line separate
    const uint64_t& local_collateral_amount) {  // NOLINT
    this->local_collateral_amount_ = local_collateral_amount;
  }
  /**
   * @brief Get data type of localCollateralAmount
   * @return Data type of localCollateralAmount
   */
  static std::string GetLocalCollateralAmountFieldType() {
    return "uint64_t";
  }
  /**
   * @brief Get json string of localCollateralAmount field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetLocalCollateralAmountString(  // line separate
      const CreateDlcTransactionsRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.local_collateral_amount_);
  }
  /**
   * @brief Set json object to localCollateralAmount field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetLocalCollateralAmountString(  // line separate
      CreateDlcTransactionsRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.local_collateral_amount_, json_value);
  }

  /**
   * @brief Get of remoteInputAmount
   * @return remoteInputAmount
   */
  uint64_t GetRemoteInputAmount() const {
    return remote_input_amount_;
  }
  /**
   * @brief Set to remoteInputAmount
   * @param[in] remote_input_amount    setting value.
   */
  void SetRemoteInputAmount(  // line separate
    const uint64_t& remote_input_amount) {  // NOLINT
    this->remote_input_amount_ = remote_input_amount;
  }
  /**
   * @brief Get data type of remoteInputAmount
   * @return Data type of remoteInputAmount
   */
  static std::string GetRemoteInputAmountFieldType() {
    return "uint64_t";
  }
  /**
   * @brief Get json string of remoteInputAmount field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetRemoteInputAmountString(  // line separate
      const CreateDlcTransactionsRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.remote_input_amount_);
  }
  /**
   * @brief Set json object to remoteInputAmount field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetRemoteInputAmountString(  // line separate
      CreateDlcTransactionsRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.remote_input_amount_, json_value);
  }

  /**
   * @brief Get of remoteCollateralAmount
   * @return remoteCollateralAmount
   */
  uint64_t GetRemoteCollateralAmount() const {
    return remote_collateral_amount_;
  }
  /**
   * @brief Set to remoteCollateralAmount
   * @param[in] remote_collateral_amount    setting value.
   */
  void SetRemoteCollateralAmount(  // line separate
    const uint64_t& remote_collateral_amount) {  // NOLINT
    this->remote_collateral_amount_ = remote_collateral_amount;
  }
  /**
   * @brief Get data type of remoteCollateralAmount
   * @return Data type of remoteCollateralAmount
   */
  static std::string GetRemoteCollateralAmountFieldType() {
    return "uint64_t";
  }
  /**
   * @brief Get json string of remoteCollateralAmount field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetRemoteCollateralAmountString(  // line separate
      const CreateDlcTransactionsRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.remote_collateral_amount_);
  }
  /**
   * @brief Set json object to remoteCollateralAmount field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetRemoteCollateralAmountString(  // line separate
      CreateDlcTransactionsRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.remote_collateral_amount_, json_value);
  }

  /**
   * @brief Get of timeout
   * @return timeout
   */
  uint32_t GetTimeout() const {
    return timeout_;
  }
  /**
   * @brief Set to timeout
   * @param[in] timeout    setting value.
   */
  void SetTimeout(  // line separate
    const uint32_t& timeout) {  // NOLINT
    this->timeout_ = timeout;
  }
  /**
   * @brief Get data type of timeout
   * @return Data type of timeout
   */
  static std::string GetTimeoutFieldType() {
    return "uint32_t";
  }
  /**
   * @brief Get json string of timeout field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetTimeoutString(  // line separate
      const CreateDlcTransactionsRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.timeout_);
  }
  /**
   * @brief Set json object to timeout field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetTimeoutString(  // line separate
      CreateDlcTransactionsRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.timeout_, json_value);
  }

  /**
   * @brief Get of localInputs.
   * @return localInputs
   */
  JsonObjectVector<TxInRequest, TxInRequestStruct>& GetLocalInputs() {  // NOLINT
    return local_inputs_;
  }
  /**
   * @brief Set to localInputs.
   * @param[in] local_inputs    setting value.
   */
  void SetLocalInputs(  // line separate
      const JsonObjectVector<TxInRequest, TxInRequestStruct>& local_inputs) {  // NOLINT
    this->local_inputs_ = local_inputs;
  }
  /**
   * @brief Get data type of localInputs.
   * @return Data type of localInputs.
   */
  static std::string GetLocalInputsFieldType() {
    return "JsonObjectVector<TxInRequest, TxInRequestStruct>";  // NOLINT
  }
  /**
   * @brief Get json string of localInputs field.
   * @param[in,out] obj     class object
   * @return JSON string.
   */
  static std::string GetLocalInputsString(  // line separate
      const CreateDlcTransactionsRequest& obj) {  // NOLINT
    // Do not set to const, because substitution of member variables
    // may occur in pre / post processing inside Serialize
    return obj.local_inputs_.Serialize();
  }
  /**
   * @brief Set json object to localInputs field.
   * @param[in,out] obj     class object
   * @param[in] json_value  JSON object
   */
  static void SetLocalInputsString(  // line separate
      CreateDlcTransactionsRequest& obj,  // NOLINT
      const UniValue& json_value) {
    obj.local_inputs_.DeserializeUniValue(json_value);
  }

  /**
   * @brief Get of localChangeAddress
   * @return localChangeAddress
   */
  std::string GetLocalChangeAddress() const {
    return local_change_address_;
  }
  /**
   * @brief Set to localChangeAddress
   * @param[in] local_change_address    setting value.
   */
  void SetLocalChangeAddress(  // line separate
    const std::string& local_change_address) {  // NOLINT
    this->local_change_address_ = local_change_address;
  }
  /**
   * @brief Get data type of localChangeAddress
   * @return Data type of localChangeAddress
   */
  static std::string GetLocalChangeAddressFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of localChangeAddress field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetLocalChangeAddressString(  // line separate
      const CreateDlcTransactionsRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.local_change_address_);
  }
  /**
   * @brief Set json object to localChangeAddress field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetLocalChangeAddressString(  // line separate
      CreateDlcTransactionsRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.local_change_address_, json_value);
  }

  /**
   * @brief Get of remoteInputs.
   * @return remoteInputs
   */
  JsonObjectVector<TxInRequest, TxInRequestStruct>& GetRemoteInputs() {  // NOLINT
    return remote_inputs_;
  }
  /**
   * @brief Set to remoteInputs.
   * @param[in] remote_inputs    setting value.
   */
  void SetRemoteInputs(  // line separate
      const JsonObjectVector<TxInRequest, TxInRequestStruct>& remote_inputs) {  // NOLINT
    this->remote_inputs_ = remote_inputs;
  }
  /**
   * @brief Get data type of remoteInputs.
   * @return Data type of remoteInputs.
   */
  static std::string GetRemoteInputsFieldType() {
    return "JsonObjectVector<TxInRequest, TxInRequestStruct>";  // NOLINT
  }
  /**
   * @brief Get json string of remoteInputs field.
   * @param[in,out] obj     class object
   * @return JSON string.
   */
  static std::string GetRemoteInputsString(  // line separate
      const CreateDlcTransactionsRequest& obj) {  // NOLINT
    // Do not set to const, because substitution of member variables
    // may occur in pre / post processing inside Serialize
    return obj.remote_inputs_.Serialize();
  }
  /**
   * @brief Set json object to remoteInputs field.
   * @param[in,out] obj     class object
   * @param[in] json_value  JSON object
   */
  static void SetRemoteInputsString(  // line separate
      CreateDlcTransactionsRequest& obj,  // NOLINT
      const UniValue& json_value) {
    obj.remote_inputs_.DeserializeUniValue(json_value);
  }

  /**
   * @brief Get of remoteChangeAddress
   * @return remoteChangeAddress
   */
  std::string GetRemoteChangeAddress() const {
    return remote_change_address_;
  }
  /**
   * @brief Set to remoteChangeAddress
   * @param[in] remote_change_address    setting value.
   */
  void SetRemoteChangeAddress(  // line separate
    const std::string& remote_change_address) {  // NOLINT
    this->remote_change_address_ = remote_change_address;
  }
  /**
   * @brief Get data type of remoteChangeAddress
   * @return Data type of remoteChangeAddress
   */
  static std::string GetRemoteChangeAddressFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of remoteChangeAddress field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetRemoteChangeAddressString(  // line separate
      const CreateDlcTransactionsRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.remote_change_address_);
  }
  /**
   * @brief Set json object to remoteChangeAddress field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetRemoteChangeAddressString(  // line separate
      CreateDlcTransactionsRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.remote_change_address_, json_value);
  }

  /**
   * @brief Get of feeRate
   * @return feeRate
   */
  uint32_t GetFeeRate() const {
    return fee_rate_;
  }
  /**
   * @brief Set to feeRate
   * @param[in] fee_rate    setting value.
   */
  void SetFeeRate(  // line separate
    const uint32_t& fee_rate) {  // NOLINT
    this->fee_rate_ = fee_rate;
  }
  /**
   * @brief Get data type of feeRate
   * @return Data type of feeRate
   */
  static std::string GetFeeRateFieldType() {
    return "uint32_t";
  }
  /**
   * @brief Get json string of feeRate field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetFeeRateString(  // line separate
      const CreateDlcTransactionsRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fee_rate_);
  }
  /**
   * @brief Set json object to feeRate field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFeeRateString(  // line separate
      CreateDlcTransactionsRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.fee_rate_, json_value);
  }

  /**
   * @brief Get of maturityTime
   * @return maturityTime
   */
  uint64_t GetMaturityTime() const {
    return maturity_time_;
  }
  /**
   * @brief Set to maturityTime
   * @param[in] maturity_time    setting value.
   */
  void SetMaturityTime(  // line separate
    const uint64_t& maturity_time) {  // NOLINT
    this->maturity_time_ = maturity_time;
  }
  /**
   * @brief Get data type of maturityTime
   * @return Data type of maturityTime
   */
  static std::string GetMaturityTimeFieldType() {
    return "uint64_t";
  }
  /**
   * @brief Get json string of maturityTime field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetMaturityTimeString(  // line separate
      const CreateDlcTransactionsRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.maturity_time_);
  }
  /**
   * @brief Set json object to maturityTime field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetMaturityTimeString(  // line separate
      CreateDlcTransactionsRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.maturity_time_, json_value);
  }

  /**
   * @brief Set ignore item.
   * @param[in] key   ignore target key name.
   */
  void SetIgnoreItem(const std::string& key) {
    ignore_items.insert(key);
  }

  /**
   * @brief Convert struct to class.
   * @param[in] data   struct data.
   */
  void ConvertFromStruct(
      const CreateDlcTransactionsRequestStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  CreateDlcTransactionsRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using CreateDlcTransactionsRequestMapTable =
    cfd::core::JsonTableMap<CreateDlcTransactionsRequest>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const CreateDlcTransactionsRequestMapTable& GetJsonMapper() const {  // NOLINT
    return json_mapper;
  }
  /**
   * @brief Get item lists of JSON mapping.
   * Fetch a list of target variable names in the order of definition.
   * @return Item lists of JSON mapping.
   * @see cfd::core::JsonClassBase::GetJsonItemList()
   */
  virtual const std::vector<std::string>& GetJsonItemList() const {
    return item_list;
  }
  /**
   * @brief Get ignore item lists of JSON mnapping.
   * Ignore the target variable at Serialize.
   * @return Item list of JSON mapping.
   * @see cfd::core::JsonClassBase::GetIgnoreItem()
   */
  virtual const std::set<std::string>& GetIgnoreItem() const {
    return ignore_items;
  }

 private:
 /**
  * @brief JsonFunctionMap table
  */
  static CreateDlcTransactionsRequestMapTable json_mapper;
  /**
   * @brief field name list.
   */
  static std::vector<std::string> item_list;
  /**
   * @brief ignore item list.
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(outcomes) value
   */
  JsonObjectVector<PayoutRequest, PayoutRequestStruct> outcomes_;  // NOLINT
  /**
   * @brief JsonAPI(oracleRPoints) value
   */
  JsonValueVector<std::string> oracle_r_points_;  // NOLINT
  /**
   * @brief JsonAPI(oraclePubkey) value
   */
  std::string oracle_pubkey_ = "";
  /**
   * @brief JsonAPI(localFundPubkey) value
   */
  std::string local_fund_pubkey_ = "";
  /**
   * @brief JsonAPI(localSweepPubkey) value
   */
  std::string local_sweep_pubkey_ = "";
  /**
   * @brief JsonAPI(localFinalAddress) value
   */
  std::string local_final_address_ = "";
  /**
   * @brief JsonAPI(remoteFundPubkey) value
   */
  std::string remote_fund_pubkey_ = "";
  /**
   * @brief JsonAPI(remoteSweepPubkey) value
   */
  std::string remote_sweep_pubkey_ = "";
  /**
   * @brief JsonAPI(remoteFinalAddress) value
   */
  std::string remote_final_address_ = "";
  /**
   * @brief JsonAPI(localInputAmount) value
   */
  uint64_t local_input_amount_ = 0;
  /**
   * @brief JsonAPI(localCollateralAmount) value
   */
  uint64_t local_collateral_amount_ = 0;
  /**
   * @brief JsonAPI(remoteInputAmount) value
   */
  uint64_t remote_input_amount_ = 0;
  /**
   * @brief JsonAPI(remoteCollateralAmount) value
   */
  uint64_t remote_collateral_amount_ = 0;
  /**
   * @brief JsonAPI(timeout) value
   */
  uint32_t timeout_ = 0;
  /**
   * @brief JsonAPI(localInputs) value
   */
  JsonObjectVector<TxInRequest, TxInRequestStruct> local_inputs_;  // NOLINT
  /**
   * @brief JsonAPI(localChangeAddress) value
   */
  std::string local_change_address_ = "";
  /**
   * @brief JsonAPI(remoteInputs) value
   */
  JsonObjectVector<TxInRequest, TxInRequestStruct> remote_inputs_;  // NOLINT
  /**
   * @brief JsonAPI(remoteChangeAddress) value
   */
  std::string remote_change_address_ = "";
  /**
   * @brief JsonAPI(feeRate) value
   */
  uint32_t fee_rate_ = 0;
  /**
   * @brief JsonAPI(maturityTime) value
   */
  uint64_t maturity_time_ = 0;
};

// ------------------------------------------------------------------------
// CreateDlcTransactionsResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (CreateDlcTransactionsResponse) class
 */
class CreateDlcTransactionsResponse
  : public cfd::core::JsonClassBase<CreateDlcTransactionsResponse> {
 public:
  CreateDlcTransactionsResponse() {
    CollectFieldName();
  }
  virtual ~CreateDlcTransactionsResponse() {
    // do nothing
  }
  /**
   * @brief collect field name.
   */
  static void CollectFieldName();

  /**
   * @brief Get of fundTxHex
   * @return fundTxHex
   */
  std::string GetFundTxHex() const {
    return fund_tx_hex_;
  }
  /**
   * @brief Set to fundTxHex
   * @param[in] fund_tx_hex    setting value.
   */
  void SetFundTxHex(  // line separate
    const std::string& fund_tx_hex) {  // NOLINT
    this->fund_tx_hex_ = fund_tx_hex;
  }
  /**
   * @brief Get data type of fundTxHex
   * @return Data type of fundTxHex
   */
  static std::string GetFundTxHexFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of fundTxHex field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetFundTxHexString(  // line separate
      const CreateDlcTransactionsResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fund_tx_hex_);
  }
  /**
   * @brief Set json object to fundTxHex field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFundTxHexString(  // line separate
      CreateDlcTransactionsResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.fund_tx_hex_, json_value);
  }

  /**
   * @brief Get of closingCetsHex.
   * @return closingCetsHex
   */
  JsonValueVector<std::string>& GetClosingCetsHex() {  // NOLINT
    return closing_cets_hex_;
  }
  /**
   * @brief Set to closingCetsHex.
   * @param[in] closing_cets_hex    setting value.
   */
  void SetClosingCetsHex(  // line separate
      const JsonValueVector<std::string>& closing_cets_hex) {  // NOLINT
    this->closing_cets_hex_ = closing_cets_hex;
  }
  /**
   * @brief Get data type of closingCetsHex.
   * @return Data type of closingCetsHex.
   */
  static std::string GetClosingCetsHexFieldType() {
    return "JsonValueVector<std::string>";  // NOLINT
  }
  /**
   * @brief Get json string of closingCetsHex field.
   * @param[in,out] obj     class object
   * @return JSON string.
   */
  static std::string GetClosingCetsHexString(  // line separate
      const CreateDlcTransactionsResponse& obj) {  // NOLINT
    // Do not set to const, because substitution of member variables
    // may occur in pre / post processing inside Serialize
    return obj.closing_cets_hex_.Serialize();
  }
  /**
   * @brief Set json object to closingCetsHex field.
   * @param[in,out] obj     class object
   * @param[in] json_value  JSON object
   */
  static void SetClosingCetsHexString(  // line separate
      CreateDlcTransactionsResponse& obj,  // NOLINT
      const UniValue& json_value) {
    obj.closing_cets_hex_.DeserializeUniValue(json_value);
  }

  /**
   * @brief Get of refundTxHex
   * @return refundTxHex
   */
  std::string GetRefundTxHex() const {
    return refund_tx_hex_;
  }
  /**
   * @brief Set to refundTxHex
   * @param[in] refund_tx_hex    setting value.
   */
  void SetRefundTxHex(  // line separate
    const std::string& refund_tx_hex) {  // NOLINT
    this->refund_tx_hex_ = refund_tx_hex;
  }
  /**
   * @brief Get data type of refundTxHex
   * @return Data type of refundTxHex
   */
  static std::string GetRefundTxHexFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of refundTxHex field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetRefundTxHexString(  // line separate
      const CreateDlcTransactionsResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.refund_tx_hex_);
  }
  /**
   * @brief Set json object to refundTxHex field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetRefundTxHexString(  // line separate
      CreateDlcTransactionsResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.refund_tx_hex_, json_value);
  }

  /**
   * @brief Set ignore item.
   * @param[in] key   ignore target key name.
   */
  void SetIgnoreItem(const std::string& key) {
    ignore_items.insert(key);
  }

  /**
   * @brief Convert struct to class.
   * @param[in] data   struct data.
   */
  void ConvertFromStruct(
      const CreateDlcTransactionsResponseStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  CreateDlcTransactionsResponseStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using CreateDlcTransactionsResponseMapTable =
    cfd::core::JsonTableMap<CreateDlcTransactionsResponse>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const CreateDlcTransactionsResponseMapTable& GetJsonMapper() const {  // NOLINT
    return json_mapper;
  }
  /**
   * @brief Get item lists of JSON mapping.
   * Fetch a list of target variable names in the order of definition.
   * @return Item lists of JSON mapping.
   * @see cfd::core::JsonClassBase::GetJsonItemList()
   */
  virtual const std::vector<std::string>& GetJsonItemList() const {
    return item_list;
  }
  /**
   * @brief Get ignore item lists of JSON mnapping.
   * Ignore the target variable at Serialize.
   * @return Item list of JSON mapping.
   * @see cfd::core::JsonClassBase::GetIgnoreItem()
   */
  virtual const std::set<std::string>& GetIgnoreItem() const {
    return ignore_items;
  }

 private:
 /**
  * @brief JsonFunctionMap table
  */
  static CreateDlcTransactionsResponseMapTable json_mapper;
  /**
   * @brief field name list.
   */
  static std::vector<std::string> item_list;
  /**
   * @brief ignore item list.
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(fundTxHex) value
   */
  std::string fund_tx_hex_ = "";
  /**
   * @brief JsonAPI(closingCetsHex) value
   */
  JsonValueVector<std::string> closing_cets_hex_;  // NOLINT
  /**
   * @brief JsonAPI(refundTxHex) value
   */
  std::string refund_tx_hex_ = "";
};

// ------------------------------------------------------------------------
// TxInRequestA
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (TxInRequestA) class
 */
class TxInRequestA
  : public cfd::core::JsonClassBase<TxInRequestA> {
 public:
  TxInRequestA() {
    CollectFieldName();
  }
  virtual ~TxInRequestA() {
    // do nothing
  }
  /**
   * @brief collect field name.
   */
  static void CollectFieldName();

  /**
   * @brief Get of txid
   * @return txid
   */
  std::string GetTxid() const {
    return txid_;
  }
  /**
   * @brief Set to txid
   * @param[in] txid    setting value.
   */
  void SetTxid(  // line separate
    const std::string& txid) {  // NOLINT
    this->txid_ = txid;
  }
  /**
   * @brief Get data type of txid
   * @return Data type of txid
   */
  static std::string GetTxidFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of txid field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetTxidString(  // line separate
      const TxInRequestA& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.txid_);
  }
  /**
   * @brief Set json object to txid field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetTxidString(  // line separate
      TxInRequestA& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.txid_, json_value);
  }

  /**
   * @brief Get of vout
   * @return vout
   */
  uint32_t GetVout() const {
    return vout_;
  }
  /**
   * @brief Set to vout
   * @param[in] vout    setting value.
   */
  void SetVout(  // line separate
    const uint32_t& vout) {  // NOLINT
    this->vout_ = vout;
  }
  /**
   * @brief Get data type of vout
   * @return Data type of vout
   */
  static std::string GetVoutFieldType() {
    return "uint32_t";
  }
  /**
   * @brief Get json string of vout field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetVoutString(  // line separate
      const TxInRequestA& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.vout_);
  }
  /**
   * @brief Set json object to vout field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetVoutString(  // line separate
      TxInRequestA& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.vout_, json_value);
  }

  /**
   * @brief Set ignore item.
   * @param[in] key   ignore target key name.
   */
  void SetIgnoreItem(const std::string& key) {
    ignore_items.insert(key);
  }

  /**
   * @brief Convert struct to class.
   * @param[in] data   struct data.
   */
  void ConvertFromStruct(
      const TxInRequestAStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  TxInRequestAStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using TxInRequestAMapTable =
    cfd::core::JsonTableMap<TxInRequestA>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const TxInRequestAMapTable& GetJsonMapper() const {  // NOLINT
    return json_mapper;
  }
  /**
   * @brief Get item lists of JSON mapping.
   * Fetch a list of target variable names in the order of definition.
   * @return Item lists of JSON mapping.
   * @see cfd::core::JsonClassBase::GetJsonItemList()
   */
  virtual const std::vector<std::string>& GetJsonItemList() const {
    return item_list;
  }
  /**
   * @brief Get ignore item lists of JSON mnapping.
   * Ignore the target variable at Serialize.
   * @return Item list of JSON mapping.
   * @see cfd::core::JsonClassBase::GetIgnoreItem()
   */
  virtual const std::set<std::string>& GetIgnoreItem() const {
    return ignore_items;
  }

 private:
 /**
  * @brief JsonFunctionMap table
  */
  static TxInRequestAMapTable json_mapper;
  /**
   * @brief field name list.
   */
  static std::vector<std::string> item_list;
  /**
   * @brief ignore item list.
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(txid) value
   */
  std::string txid_ = "";
  /**
   * @brief JsonAPI(vout) value
   */
  uint32_t vout_ = 0;
};

// ------------------------------------------------------------------------
// TxOutRequestA
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (TxOutRequestA) class
 */
class TxOutRequestA
  : public cfd::core::JsonClassBase<TxOutRequestA> {
 public:
  TxOutRequestA() {
    CollectFieldName();
  }
  virtual ~TxOutRequestA() {
    // do nothing
  }
  /**
   * @brief collect field name.
   */
  static void CollectFieldName();

  /**
   * @brief Get of amount
   * @return amount
   */
  uint64_t GetAmount() const {
    return amount_;
  }
  /**
   * @brief Set to amount
   * @param[in] amount    setting value.
   */
  void SetAmount(  // line separate
    const uint64_t& amount) {  // NOLINT
    this->amount_ = amount;
  }
  /**
   * @brief Get data type of amount
   * @return Data type of amount
   */
  static std::string GetAmountFieldType() {
    return "uint64_t";
  }
  /**
   * @brief Get json string of amount field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetAmountString(  // line separate
      const TxOutRequestA& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.amount_);
  }
  /**
   * @brief Set json object to amount field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetAmountString(  // line separate
      TxOutRequestA& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.amount_, json_value);
  }

  /**
   * @brief Get of address
   * @return address
   */
  std::string GetAddress() const {
    return address_;
  }
  /**
   * @brief Set to address
   * @param[in] address    setting value.
   */
  void SetAddress(  // line separate
    const std::string& address) {  // NOLINT
    this->address_ = address;
  }
  /**
   * @brief Get data type of address
   * @return Data type of address
   */
  static std::string GetAddressFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of address field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetAddressString(  // line separate
      const TxOutRequestA& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.address_);
  }
  /**
   * @brief Set json object to address field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetAddressString(  // line separate
      TxOutRequestA& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.address_, json_value);
  }

  /**
   * @brief Set ignore item.
   * @param[in] key   ignore target key name.
   */
  void SetIgnoreItem(const std::string& key) {
    ignore_items.insert(key);
  }

  /**
   * @brief Convert struct to class.
   * @param[in] data   struct data.
   */
  void ConvertFromStruct(
      const TxOutRequestAStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  TxOutRequestAStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using TxOutRequestAMapTable =
    cfd::core::JsonTableMap<TxOutRequestA>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const TxOutRequestAMapTable& GetJsonMapper() const {  // NOLINT
    return json_mapper;
  }
  /**
   * @brief Get item lists of JSON mapping.
   * Fetch a list of target variable names in the order of definition.
   * @return Item lists of JSON mapping.
   * @see cfd::core::JsonClassBase::GetJsonItemList()
   */
  virtual const std::vector<std::string>& GetJsonItemList() const {
    return item_list;
  }
  /**
   * @brief Get ignore item lists of JSON mnapping.
   * Ignore the target variable at Serialize.
   * @return Item list of JSON mapping.
   * @see cfd::core::JsonClassBase::GetIgnoreItem()
   */
  virtual const std::set<std::string>& GetIgnoreItem() const {
    return ignore_items;
  }

 private:
 /**
  * @brief JsonFunctionMap table
  */
  static TxOutRequestAMapTable json_mapper;
  /**
   * @brief field name list.
   */
  static std::vector<std::string> item_list;
  /**
   * @brief ignore item list.
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(amount) value
   */
  uint64_t amount_ = 0;
  /**
   * @brief JsonAPI(address) value
   */
  std::string address_ = "";
};

// ------------------------------------------------------------------------
// CreateFundTransactionRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (CreateFundTransactionRequest) class
 */
class CreateFundTransactionRequest
  : public cfd::core::JsonClassBase<CreateFundTransactionRequest> {
 public:
  CreateFundTransactionRequest() {
    CollectFieldName();
  }
  virtual ~CreateFundTransactionRequest() {
    // do nothing
  }
  /**
   * @brief collect field name.
   */
  static void CollectFieldName();

  /**
   * @brief Get of localPubkey
   * @return localPubkey
   */
  std::string GetLocalPubkey() const {
    return local_pubkey_;
  }
  /**
   * @brief Set to localPubkey
   * @param[in] local_pubkey    setting value.
   */
  void SetLocalPubkey(  // line separate
    const std::string& local_pubkey) {  // NOLINT
    this->local_pubkey_ = local_pubkey;
  }
  /**
   * @brief Get data type of localPubkey
   * @return Data type of localPubkey
   */
  static std::string GetLocalPubkeyFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of localPubkey field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetLocalPubkeyString(  // line separate
      const CreateFundTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.local_pubkey_);
  }
  /**
   * @brief Set json object to localPubkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetLocalPubkeyString(  // line separate
      CreateFundTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.local_pubkey_, json_value);
  }

  /**
   * @brief Get of remotePubkey
   * @return remotePubkey
   */
  std::string GetRemotePubkey() const {
    return remote_pubkey_;
  }
  /**
   * @brief Set to remotePubkey
   * @param[in] remote_pubkey    setting value.
   */
  void SetRemotePubkey(  // line separate
    const std::string& remote_pubkey) {  // NOLINT
    this->remote_pubkey_ = remote_pubkey;
  }
  /**
   * @brief Get data type of remotePubkey
   * @return Data type of remotePubkey
   */
  static std::string GetRemotePubkeyFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of remotePubkey field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetRemotePubkeyString(  // line separate
      const CreateFundTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.remote_pubkey_);
  }
  /**
   * @brief Set json object to remotePubkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetRemotePubkeyString(  // line separate
      CreateFundTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.remote_pubkey_, json_value);
  }

  /**
   * @brief Get of outputAmount
   * @return outputAmount
   */
  uint64_t GetOutputAmount() const {
    return output_amount_;
  }
  /**
   * @brief Set to outputAmount
   * @param[in] output_amount    setting value.
   */
  void SetOutputAmount(  // line separate
    const uint64_t& output_amount) {  // NOLINT
    this->output_amount_ = output_amount;
  }
  /**
   * @brief Get data type of outputAmount
   * @return Data type of outputAmount
   */
  static std::string GetOutputAmountFieldType() {
    return "uint64_t";
  }
  /**
   * @brief Get json string of outputAmount field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetOutputAmountString(  // line separate
      const CreateFundTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.output_amount_);
  }
  /**
   * @brief Set json object to outputAmount field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetOutputAmountString(  // line separate
      CreateFundTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.output_amount_, json_value);
  }

  /**
   * @brief Get of localInputs.
   * @return localInputs
   */
  JsonObjectVector<TxInRequestA, TxInRequestAStruct>& GetLocalInputs() {  // NOLINT
    return local_inputs_;
  }
  /**
   * @brief Set to localInputs.
   * @param[in] local_inputs    setting value.
   */
  void SetLocalInputs(  // line separate
      const JsonObjectVector<TxInRequestA, TxInRequestAStruct>& local_inputs) {  // NOLINT
    this->local_inputs_ = local_inputs;
  }
  /**
   * @brief Get data type of localInputs.
   * @return Data type of localInputs.
   */
  static std::string GetLocalInputsFieldType() {
    return "JsonObjectVector<TxInRequestA, TxInRequestAStruct>";  // NOLINT
  }
  /**
   * @brief Get json string of localInputs field.
   * @param[in,out] obj     class object
   * @return JSON string.
   */
  static std::string GetLocalInputsString(  // line separate
      const CreateFundTransactionRequest& obj) {  // NOLINT
    // Do not set to const, because substitution of member variables
    // may occur in pre / post processing inside Serialize
    return obj.local_inputs_.Serialize();
  }
  /**
   * @brief Set json object to localInputs field.
   * @param[in,out] obj     class object
   * @param[in] json_value  JSON object
   */
  static void SetLocalInputsString(  // line separate
      CreateFundTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    obj.local_inputs_.DeserializeUniValue(json_value);
  }

  /**
   * @brief Get of localChange.
   * @return localChange
   */
  TxOutRequestA& GetLocalChange() {  // NOLINT
    return local_change_;
  }
  /**
   * @brief Set to localChange.
   * @param[in] local_change    setting value.
   */
  void SetLocalChange(  // line separate
      const TxOutRequestA& local_change) {  // NOLINT
    this->local_change_ = local_change;
  }
  /**
   * @brief Get data type of localChange.
   * @return Data type of localChange.
   */
  static std::string GetLocalChangeFieldType() {
    return "TxOutRequestA";  // NOLINT
  }
  /**
   * @brief Get json string of localChange field.
   * @param[in,out] obj     class object
   * @return JSON string.
   */
  static std::string GetLocalChangeString(  // line separate
      const CreateFundTransactionRequest& obj) {  // NOLINT
    // Do not set to const, because substitution of member variables
    // may occur in pre / post processing inside Serialize
    return obj.local_change_.Serialize();
  }
  /**
   * @brief Set json object to localChange field.
   * @param[in,out] obj     class object
   * @param[in] json_value  JSON object
   */
  static void SetLocalChangeString(  // line separate
      CreateFundTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    obj.local_change_.DeserializeUniValue(json_value);
  }

  /**
   * @brief Get of remoteInputs.
   * @return remoteInputs
   */
  JsonObjectVector<TxInRequestA, TxInRequestAStruct>& GetRemoteInputs() {  // NOLINT
    return remote_inputs_;
  }
  /**
   * @brief Set to remoteInputs.
   * @param[in] remote_inputs    setting value.
   */
  void SetRemoteInputs(  // line separate
      const JsonObjectVector<TxInRequestA, TxInRequestAStruct>& remote_inputs) {  // NOLINT
    this->remote_inputs_ = remote_inputs;
  }
  /**
   * @brief Get data type of remoteInputs.
   * @return Data type of remoteInputs.
   */
  static std::string GetRemoteInputsFieldType() {
    return "JsonObjectVector<TxInRequestA, TxInRequestAStruct>";  // NOLINT
  }
  /**
   * @brief Get json string of remoteInputs field.
   * @param[in,out] obj     class object
   * @return JSON string.
   */
  static std::string GetRemoteInputsString(  // line separate
      const CreateFundTransactionRequest& obj) {  // NOLINT
    // Do not set to const, because substitution of member variables
    // may occur in pre / post processing inside Serialize
    return obj.remote_inputs_.Serialize();
  }
  /**
   * @brief Set json object to remoteInputs field.
   * @param[in,out] obj     class object
   * @param[in] json_value  JSON object
   */
  static void SetRemoteInputsString(  // line separate
      CreateFundTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    obj.remote_inputs_.DeserializeUniValue(json_value);
  }

  /**
   * @brief Get of remoteChange.
   * @return remoteChange
   */
  TxOutRequestA& GetRemoteChange() {  // NOLINT
    return remote_change_;
  }
  /**
   * @brief Set to remoteChange.
   * @param[in] remote_change    setting value.
   */
  void SetRemoteChange(  // line separate
      const TxOutRequestA& remote_change) {  // NOLINT
    this->remote_change_ = remote_change;
  }
  /**
   * @brief Get data type of remoteChange.
   * @return Data type of remoteChange.
   */
  static std::string GetRemoteChangeFieldType() {
    return "TxOutRequestA";  // NOLINT
  }
  /**
   * @brief Get json string of remoteChange field.
   * @param[in,out] obj     class object
   * @return JSON string.
   */
  static std::string GetRemoteChangeString(  // line separate
      const CreateFundTransactionRequest& obj) {  // NOLINT
    // Do not set to const, because substitution of member variables
    // may occur in pre / post processing inside Serialize
    return obj.remote_change_.Serialize();
  }
  /**
   * @brief Set json object to remoteChange field.
   * @param[in,out] obj     class object
   * @param[in] json_value  JSON object
   */
  static void SetRemoteChangeString(  // line separate
      CreateFundTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    obj.remote_change_.DeserializeUniValue(json_value);
  }

  /**
   * @brief Get of nLockTime
   * @return nLockTime
   */
  uint64_t GetNLockTime() const {
    return n_lock_time_;
  }
  /**
   * @brief Set to nLockTime
   * @param[in] n_lock_time    setting value.
   */
  void SetNLockTime(  // line separate
    const uint64_t& n_lock_time) {  // NOLINT
    this->n_lock_time_ = n_lock_time;
  }
  /**
   * @brief Get data type of nLockTime
   * @return Data type of nLockTime
   */
  static std::string GetNLockTimeFieldType() {
    return "uint64_t";
  }
  /**
   * @brief Get json string of nLockTime field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetNLockTimeString(  // line separate
      const CreateFundTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.n_lock_time_);
  }
  /**
   * @brief Set json object to nLockTime field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetNLockTimeString(  // line separate
      CreateFundTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.n_lock_time_, json_value);
  }

  /**
   * @brief Set ignore item.
   * @param[in] key   ignore target key name.
   */
  void SetIgnoreItem(const std::string& key) {
    ignore_items.insert(key);
  }

  /**
   * @brief Convert struct to class.
   * @param[in] data   struct data.
   */
  void ConvertFromStruct(
      const CreateFundTransactionRequestStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  CreateFundTransactionRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using CreateFundTransactionRequestMapTable =
    cfd::core::JsonTableMap<CreateFundTransactionRequest>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const CreateFundTransactionRequestMapTable& GetJsonMapper() const {  // NOLINT
    return json_mapper;
  }
  /**
   * @brief Get item lists of JSON mapping.
   * Fetch a list of target variable names in the order of definition.
   * @return Item lists of JSON mapping.
   * @see cfd::core::JsonClassBase::GetJsonItemList()
   */
  virtual const std::vector<std::string>& GetJsonItemList() const {
    return item_list;
  }
  /**
   * @brief Get ignore item lists of JSON mnapping.
   * Ignore the target variable at Serialize.
   * @return Item list of JSON mapping.
   * @see cfd::core::JsonClassBase::GetIgnoreItem()
   */
  virtual const std::set<std::string>& GetIgnoreItem() const {
    return ignore_items;
  }

 private:
 /**
  * @brief JsonFunctionMap table
  */
  static CreateFundTransactionRequestMapTable json_mapper;
  /**
   * @brief field name list.
   */
  static std::vector<std::string> item_list;
  /**
   * @brief ignore item list.
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(localPubkey) value
   */
  std::string local_pubkey_ = "";
  /**
   * @brief JsonAPI(remotePubkey) value
   */
  std::string remote_pubkey_ = "";
  /**
   * @brief JsonAPI(outputAmount) value
   */
  uint64_t output_amount_ = 0;
  /**
   * @brief JsonAPI(localInputs) value
   */
  JsonObjectVector<TxInRequestA, TxInRequestAStruct> local_inputs_;  // NOLINT
  /**
   * @brief JsonAPI(localChange) value
   */
  TxOutRequestA local_change_;  // NOLINT
  /**
   * @brief JsonAPI(remoteInputs) value
   */
  JsonObjectVector<TxInRequestA, TxInRequestAStruct> remote_inputs_;  // NOLINT
  /**
   * @brief JsonAPI(remoteChange) value
   */
  TxOutRequestA remote_change_;  // NOLINT
  /**
   * @brief JsonAPI(nLockTime) value
   */
  uint64_t n_lock_time_ = 0;
};

// ------------------------------------------------------------------------
// CreateFundTransactionResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (CreateFundTransactionResponse) class
 */
class CreateFundTransactionResponse
  : public cfd::core::JsonClassBase<CreateFundTransactionResponse> {
 public:
  CreateFundTransactionResponse() {
    CollectFieldName();
  }
  virtual ~CreateFundTransactionResponse() {
    // do nothing
  }
  /**
   * @brief collect field name.
   */
  static void CollectFieldName();

  /**
   * @brief Get of hex
   * @return hex
   */
  std::string GetHex() const {
    return hex_;
  }
  /**
   * @brief Set to hex
   * @param[in] hex    setting value.
   */
  void SetHex(  // line separate
    const std::string& hex) {  // NOLINT
    this->hex_ = hex;
  }
  /**
   * @brief Get data type of hex
   * @return Data type of hex
   */
  static std::string GetHexFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of hex field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetHexString(  // line separate
      const CreateFundTransactionResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.hex_);
  }
  /**
   * @brief Set json object to hex field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetHexString(  // line separate
      CreateFundTransactionResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.hex_, json_value);
  }

  /**
   * @brief Set ignore item.
   * @param[in] key   ignore target key name.
   */
  void SetIgnoreItem(const std::string& key) {
    ignore_items.insert(key);
  }

  /**
   * @brief Convert struct to class.
   * @param[in] data   struct data.
   */
  void ConvertFromStruct(
      const CreateFundTransactionResponseStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  CreateFundTransactionResponseStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using CreateFundTransactionResponseMapTable =
    cfd::core::JsonTableMap<CreateFundTransactionResponse>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const CreateFundTransactionResponseMapTable& GetJsonMapper() const {  // NOLINT
    return json_mapper;
  }
  /**
   * @brief Get item lists of JSON mapping.
   * Fetch a list of target variable names in the order of definition.
   * @return Item lists of JSON mapping.
   * @see cfd::core::JsonClassBase::GetJsonItemList()
   */
  virtual const std::vector<std::string>& GetJsonItemList() const {
    return item_list;
  }
  /**
   * @brief Get ignore item lists of JSON mnapping.
   * Ignore the target variable at Serialize.
   * @return Item list of JSON mapping.
   * @see cfd::core::JsonClassBase::GetIgnoreItem()
   */
  virtual const std::set<std::string>& GetIgnoreItem() const {
    return ignore_items;
  }

 private:
 /**
  * @brief JsonFunctionMap table
  */
  static CreateFundTransactionResponseMapTable json_mapper;
  /**
   * @brief field name list.
   */
  static std::vector<std::string> item_list;
  /**
   * @brief ignore item list.
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(hex) value
   */
  std::string hex_ = "";
};

// ------------------------------------------------------------------------
// CreateMutualClosingTransactionRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (CreateMutualClosingTransactionRequest) class
 */
class CreateMutualClosingTransactionRequest
  : public cfd::core::JsonClassBase<CreateMutualClosingTransactionRequest> {
 public:
  CreateMutualClosingTransactionRequest() {
    CollectFieldName();
  }
  virtual ~CreateMutualClosingTransactionRequest() {
    // do nothing
  }
  /**
   * @brief collect field name.
   */
  static void CollectFieldName();

  /**
   * @brief Get of localFinalAddress
   * @return localFinalAddress
   */
  std::string GetLocalFinalAddress() const {
    return local_final_address_;
  }
  /**
   * @brief Set to localFinalAddress
   * @param[in] local_final_address    setting value.
   */
  void SetLocalFinalAddress(  // line separate
    const std::string& local_final_address) {  // NOLINT
    this->local_final_address_ = local_final_address;
  }
  /**
   * @brief Get data type of localFinalAddress
   * @return Data type of localFinalAddress
   */
  static std::string GetLocalFinalAddressFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of localFinalAddress field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetLocalFinalAddressString(  // line separate
      const CreateMutualClosingTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.local_final_address_);
  }
  /**
   * @brief Set json object to localFinalAddress field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetLocalFinalAddressString(  // line separate
      CreateMutualClosingTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.local_final_address_, json_value);
  }

  /**
   * @brief Get of remoteFinalAddress
   * @return remoteFinalAddress
   */
  std::string GetRemoteFinalAddress() const {
    return remote_final_address_;
  }
  /**
   * @brief Set to remoteFinalAddress
   * @param[in] remote_final_address    setting value.
   */
  void SetRemoteFinalAddress(  // line separate
    const std::string& remote_final_address) {  // NOLINT
    this->remote_final_address_ = remote_final_address;
  }
  /**
   * @brief Get data type of remoteFinalAddress
   * @return Data type of remoteFinalAddress
   */
  static std::string GetRemoteFinalAddressFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of remoteFinalAddress field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetRemoteFinalAddressString(  // line separate
      const CreateMutualClosingTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.remote_final_address_);
  }
  /**
   * @brief Set json object to remoteFinalAddress field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetRemoteFinalAddressString(  // line separate
      CreateMutualClosingTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.remote_final_address_, json_value);
  }

  /**
   * @brief Get of localAmount
   * @return localAmount
   */
  uint64_t GetLocalAmount() const {
    return local_amount_;
  }
  /**
   * @brief Set to localAmount
   * @param[in] local_amount    setting value.
   */
  void SetLocalAmount(  // line separate
    const uint64_t& local_amount) {  // NOLINT
    this->local_amount_ = local_amount;
  }
  /**
   * @brief Get data type of localAmount
   * @return Data type of localAmount
   */
  static std::string GetLocalAmountFieldType() {
    return "uint64_t";
  }
  /**
   * @brief Get json string of localAmount field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetLocalAmountString(  // line separate
      const CreateMutualClosingTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.local_amount_);
  }
  /**
   * @brief Set json object to localAmount field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetLocalAmountString(  // line separate
      CreateMutualClosingTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.local_amount_, json_value);
  }

  /**
   * @brief Get of remoteAmount
   * @return remoteAmount
   */
  uint64_t GetRemoteAmount() const {
    return remote_amount_;
  }
  /**
   * @brief Set to remoteAmount
   * @param[in] remote_amount    setting value.
   */
  void SetRemoteAmount(  // line separate
    const uint64_t& remote_amount) {  // NOLINT
    this->remote_amount_ = remote_amount;
  }
  /**
   * @brief Get data type of remoteAmount
   * @return Data type of remoteAmount
   */
  static std::string GetRemoteAmountFieldType() {
    return "uint64_t";
  }
  /**
   * @brief Get json string of remoteAmount field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetRemoteAmountString(  // line separate
      const CreateMutualClosingTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.remote_amount_);
  }
  /**
   * @brief Set json object to remoteAmount field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetRemoteAmountString(  // line separate
      CreateMutualClosingTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.remote_amount_, json_value);
  }

  /**
   * @brief Get of fundTxid
   * @return fundTxid
   */
  std::string GetFundTxid() const {
    return fund_txid_;
  }
  /**
   * @brief Set to fundTxid
   * @param[in] fund_txid    setting value.
   */
  void SetFundTxid(  // line separate
    const std::string& fund_txid) {  // NOLINT
    this->fund_txid_ = fund_txid;
  }
  /**
   * @brief Get data type of fundTxid
   * @return Data type of fundTxid
   */
  static std::string GetFundTxidFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of fundTxid field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetFundTxidString(  // line separate
      const CreateMutualClosingTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fund_txid_);
  }
  /**
   * @brief Set json object to fundTxid field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFundTxidString(  // line separate
      CreateMutualClosingTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.fund_txid_, json_value);
  }

  /**
   * @brief Get of fundVout
   * @return fundVout
   */
  uint32_t GetFundVout() const {
    return fund_vout_;
  }
  /**
   * @brief Set to fundVout
   * @param[in] fund_vout    setting value.
   */
  void SetFundVout(  // line separate
    const uint32_t& fund_vout) {  // NOLINT
    this->fund_vout_ = fund_vout;
  }
  /**
   * @brief Get data type of fundVout
   * @return Data type of fundVout
   */
  static std::string GetFundVoutFieldType() {
    return "uint32_t";
  }
  /**
   * @brief Get json string of fundVout field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetFundVoutString(  // line separate
      const CreateMutualClosingTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fund_vout_);
  }
  /**
   * @brief Set json object to fundVout field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFundVoutString(  // line separate
      CreateMutualClosingTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.fund_vout_, json_value);
  }

  /**
   * @brief Set ignore item.
   * @param[in] key   ignore target key name.
   */
  void SetIgnoreItem(const std::string& key) {
    ignore_items.insert(key);
  }

  /**
   * @brief Convert struct to class.
   * @param[in] data   struct data.
   */
  void ConvertFromStruct(
      const CreateMutualClosingTransactionRequestStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  CreateMutualClosingTransactionRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using CreateMutualClosingTransactionRequestMapTable =
    cfd::core::JsonTableMap<CreateMutualClosingTransactionRequest>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const CreateMutualClosingTransactionRequestMapTable& GetJsonMapper() const {  // NOLINT
    return json_mapper;
  }
  /**
   * @brief Get item lists of JSON mapping.
   * Fetch a list of target variable names in the order of definition.
   * @return Item lists of JSON mapping.
   * @see cfd::core::JsonClassBase::GetJsonItemList()
   */
  virtual const std::vector<std::string>& GetJsonItemList() const {
    return item_list;
  }
  /**
   * @brief Get ignore item lists of JSON mnapping.
   * Ignore the target variable at Serialize.
   * @return Item list of JSON mapping.
   * @see cfd::core::JsonClassBase::GetIgnoreItem()
   */
  virtual const std::set<std::string>& GetIgnoreItem() const {
    return ignore_items;
  }

 private:
 /**
  * @brief JsonFunctionMap table
  */
  static CreateMutualClosingTransactionRequestMapTable json_mapper;
  /**
   * @brief field name list.
   */
  static std::vector<std::string> item_list;
  /**
   * @brief ignore item list.
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(localFinalAddress) value
   */
  std::string local_final_address_ = "";
  /**
   * @brief JsonAPI(remoteFinalAddress) value
   */
  std::string remote_final_address_ = "";
  /**
   * @brief JsonAPI(localAmount) value
   */
  uint64_t local_amount_ = 0;
  /**
   * @brief JsonAPI(remoteAmount) value
   */
  uint64_t remote_amount_ = 0;
  /**
   * @brief JsonAPI(fundTxid) value
   */
  std::string fund_txid_ = "";
  /**
   * @brief JsonAPI(fundVout) value
   */
  uint32_t fund_vout_ = 0;
};

// ------------------------------------------------------------------------
// CreateMutualClosingTransactionResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (CreateMutualClosingTransactionResponse) class
 */
class CreateMutualClosingTransactionResponse
  : public cfd::core::JsonClassBase<CreateMutualClosingTransactionResponse> {
 public:
  CreateMutualClosingTransactionResponse() {
    CollectFieldName();
  }
  virtual ~CreateMutualClosingTransactionResponse() {
    // do nothing
  }
  /**
   * @brief collect field name.
   */
  static void CollectFieldName();

  /**
   * @brief Get of hex
   * @return hex
   */
  std::string GetHex() const {
    return hex_;
  }
  /**
   * @brief Set to hex
   * @param[in] hex    setting value.
   */
  void SetHex(  // line separate
    const std::string& hex) {  // NOLINT
    this->hex_ = hex;
  }
  /**
   * @brief Get data type of hex
   * @return Data type of hex
   */
  static std::string GetHexFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of hex field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetHexString(  // line separate
      const CreateMutualClosingTransactionResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.hex_);
  }
  /**
   * @brief Set json object to hex field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetHexString(  // line separate
      CreateMutualClosingTransactionResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.hex_, json_value);
  }

  /**
   * @brief Set ignore item.
   * @param[in] key   ignore target key name.
   */
  void SetIgnoreItem(const std::string& key) {
    ignore_items.insert(key);
  }

  /**
   * @brief Convert struct to class.
   * @param[in] data   struct data.
   */
  void ConvertFromStruct(
      const CreateMutualClosingTransactionResponseStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  CreateMutualClosingTransactionResponseStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using CreateMutualClosingTransactionResponseMapTable =
    cfd::core::JsonTableMap<CreateMutualClosingTransactionResponse>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const CreateMutualClosingTransactionResponseMapTable& GetJsonMapper() const {  // NOLINT
    return json_mapper;
  }
  /**
   * @brief Get item lists of JSON mapping.
   * Fetch a list of target variable names in the order of definition.
   * @return Item lists of JSON mapping.
   * @see cfd::core::JsonClassBase::GetJsonItemList()
   */
  virtual const std::vector<std::string>& GetJsonItemList() const {
    return item_list;
  }
  /**
   * @brief Get ignore item lists of JSON mnapping.
   * Ignore the target variable at Serialize.
   * @return Item list of JSON mapping.
   * @see cfd::core::JsonClassBase::GetIgnoreItem()
   */
  virtual const std::set<std::string>& GetIgnoreItem() const {
    return ignore_items;
  }

 private:
 /**
  * @brief JsonFunctionMap table
  */
  static CreateMutualClosingTransactionResponseMapTable json_mapper;
  /**
   * @brief field name list.
   */
  static std::vector<std::string> item_list;
  /**
   * @brief ignore item list.
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(hex) value
   */
  std::string hex_ = "";
};

// ------------------------------------------------------------------------
// CreatePenaltyTransactionRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (CreatePenaltyTransactionRequest) class
 */
class CreatePenaltyTransactionRequest
  : public cfd::core::JsonClassBase<CreatePenaltyTransactionRequest> {
 public:
  CreatePenaltyTransactionRequest() {
    CollectFieldName();
  }
  virtual ~CreatePenaltyTransactionRequest() {
    // do nothing
  }
  /**
   * @brief collect field name.
   */
  static void CollectFieldName();

  /**
   * @brief Get of finalAddress
   * @return finalAddress
   */
  std::string GetFinalAddress() const {
    return final_address_;
  }
  /**
   * @brief Set to finalAddress
   * @param[in] final_address    setting value.
   */
  void SetFinalAddress(  // line separate
    const std::string& final_address) {  // NOLINT
    this->final_address_ = final_address;
  }
  /**
   * @brief Get data type of finalAddress
   * @return Data type of finalAddress
   */
  static std::string GetFinalAddressFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of finalAddress field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetFinalAddressString(  // line separate
      const CreatePenaltyTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.final_address_);
  }
  /**
   * @brief Set json object to finalAddress field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFinalAddressString(  // line separate
      CreatePenaltyTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.final_address_, json_value);
  }

  /**
   * @brief Get of amount
   * @return amount
   */
  uint64_t GetAmount() const {
    return amount_;
  }
  /**
   * @brief Set to amount
   * @param[in] amount    setting value.
   */
  void SetAmount(  // line separate
    const uint64_t& amount) {  // NOLINT
    this->amount_ = amount;
  }
  /**
   * @brief Get data type of amount
   * @return Data type of amount
   */
  static std::string GetAmountFieldType() {
    return "uint64_t";
  }
  /**
   * @brief Get json string of amount field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetAmountString(  // line separate
      const CreatePenaltyTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.amount_);
  }
  /**
   * @brief Set json object to amount field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetAmountString(  // line separate
      CreatePenaltyTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.amount_, json_value);
  }

  /**
   * @brief Get of cetId
   * @return cetId
   */
  std::string GetCetId() const {
    return cet_id_;
  }
  /**
   * @brief Set to cetId
   * @param[in] cet_id    setting value.
   */
  void SetCetId(  // line separate
    const std::string& cet_id) {  // NOLINT
    this->cet_id_ = cet_id;
  }
  /**
   * @brief Get data type of cetId
   * @return Data type of cetId
   */
  static std::string GetCetIdFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of cetId field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetCetIdString(  // line separate
      const CreatePenaltyTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.cet_id_);
  }
  /**
   * @brief Set json object to cetId field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetCetIdString(  // line separate
      CreatePenaltyTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.cet_id_, json_value);
  }

  /**
   * @brief Get of cetVout
   * @return cetVout
   */
  uint64_t GetCetVout() const {
    return cet_vout_;
  }
  /**
   * @brief Set to cetVout
   * @param[in] cet_vout    setting value.
   */
  void SetCetVout(  // line separate
    const uint64_t& cet_vout) {  // NOLINT
    this->cet_vout_ = cet_vout;
  }
  /**
   * @brief Get data type of cetVout
   * @return Data type of cetVout
   */
  static std::string GetCetVoutFieldType() {
    return "uint64_t";
  }
  /**
   * @brief Get json string of cetVout field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetCetVoutString(  // line separate
      const CreatePenaltyTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.cet_vout_);
  }
  /**
   * @brief Set json object to cetVout field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetCetVoutString(  // line separate
      CreatePenaltyTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.cet_vout_, json_value);
  }

  /**
   * @brief Set ignore item.
   * @param[in] key   ignore target key name.
   */
  void SetIgnoreItem(const std::string& key) {
    ignore_items.insert(key);
  }

  /**
   * @brief Convert struct to class.
   * @param[in] data   struct data.
   */
  void ConvertFromStruct(
      const CreatePenaltyTransactionRequestStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  CreatePenaltyTransactionRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using CreatePenaltyTransactionRequestMapTable =
    cfd::core::JsonTableMap<CreatePenaltyTransactionRequest>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const CreatePenaltyTransactionRequestMapTable& GetJsonMapper() const {  // NOLINT
    return json_mapper;
  }
  /**
   * @brief Get item lists of JSON mapping.
   * Fetch a list of target variable names in the order of definition.
   * @return Item lists of JSON mapping.
   * @see cfd::core::JsonClassBase::GetJsonItemList()
   */
  virtual const std::vector<std::string>& GetJsonItemList() const {
    return item_list;
  }
  /**
   * @brief Get ignore item lists of JSON mnapping.
   * Ignore the target variable at Serialize.
   * @return Item list of JSON mapping.
   * @see cfd::core::JsonClassBase::GetIgnoreItem()
   */
  virtual const std::set<std::string>& GetIgnoreItem() const {
    return ignore_items;
  }

 private:
 /**
  * @brief JsonFunctionMap table
  */
  static CreatePenaltyTransactionRequestMapTable json_mapper;
  /**
   * @brief field name list.
   */
  static std::vector<std::string> item_list;
  /**
   * @brief ignore item list.
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(finalAddress) value
   */
  std::string final_address_ = "";
  /**
   * @brief JsonAPI(amount) value
   */
  uint64_t amount_ = 0;
  /**
   * @brief JsonAPI(cetId) value
   */
  std::string cet_id_ = "";
  /**
   * @brief JsonAPI(cetVout) value
   */
  uint64_t cet_vout_ = 0;
};

// ------------------------------------------------------------------------
// CreatePenaltyTransactionResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (CreatePenaltyTransactionResponse) class
 */
class CreatePenaltyTransactionResponse
  : public cfd::core::JsonClassBase<CreatePenaltyTransactionResponse> {
 public:
  CreatePenaltyTransactionResponse() {
    CollectFieldName();
  }
  virtual ~CreatePenaltyTransactionResponse() {
    // do nothing
  }
  /**
   * @brief collect field name.
   */
  static void CollectFieldName();

  /**
   * @brief Get of hex
   * @return hex
   */
  std::string GetHex() const {
    return hex_;
  }
  /**
   * @brief Set to hex
   * @param[in] hex    setting value.
   */
  void SetHex(  // line separate
    const std::string& hex) {  // NOLINT
    this->hex_ = hex;
  }
  /**
   * @brief Get data type of hex
   * @return Data type of hex
   */
  static std::string GetHexFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of hex field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetHexString(  // line separate
      const CreatePenaltyTransactionResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.hex_);
  }
  /**
   * @brief Set json object to hex field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetHexString(  // line separate
      CreatePenaltyTransactionResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.hex_, json_value);
  }

  /**
   * @brief Set ignore item.
   * @param[in] key   ignore target key name.
   */
  void SetIgnoreItem(const std::string& key) {
    ignore_items.insert(key);
  }

  /**
   * @brief Convert struct to class.
   * @param[in] data   struct data.
   */
  void ConvertFromStruct(
      const CreatePenaltyTransactionResponseStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  CreatePenaltyTransactionResponseStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using CreatePenaltyTransactionResponseMapTable =
    cfd::core::JsonTableMap<CreatePenaltyTransactionResponse>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const CreatePenaltyTransactionResponseMapTable& GetJsonMapper() const {  // NOLINT
    return json_mapper;
  }
  /**
   * @brief Get item lists of JSON mapping.
   * Fetch a list of target variable names in the order of definition.
   * @return Item lists of JSON mapping.
   * @see cfd::core::JsonClassBase::GetJsonItemList()
   */
  virtual const std::vector<std::string>& GetJsonItemList() const {
    return item_list;
  }
  /**
   * @brief Get ignore item lists of JSON mnapping.
   * Ignore the target variable at Serialize.
   * @return Item list of JSON mapping.
   * @see cfd::core::JsonClassBase::GetIgnoreItem()
   */
  virtual const std::set<std::string>& GetIgnoreItem() const {
    return ignore_items;
  }

 private:
 /**
  * @brief JsonFunctionMap table
  */
  static CreatePenaltyTransactionResponseMapTable json_mapper;
  /**
   * @brief field name list.
   */
  static std::vector<std::string> item_list;
  /**
   * @brief ignore item list.
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(hex) value
   */
  std::string hex_ = "";
};

// ------------------------------------------------------------------------
// CreateRefundTransactionRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (CreateRefundTransactionRequest) class
 */
class CreateRefundTransactionRequest
  : public cfd::core::JsonClassBase<CreateRefundTransactionRequest> {
 public:
  CreateRefundTransactionRequest() {
    CollectFieldName();
  }
  virtual ~CreateRefundTransactionRequest() {
    // do nothing
  }
  /**
   * @brief collect field name.
   */
  static void CollectFieldName();

  /**
   * @brief Get of localFinalAddress
   * @return localFinalAddress
   */
  std::string GetLocalFinalAddress() const {
    return local_final_address_;
  }
  /**
   * @brief Set to localFinalAddress
   * @param[in] local_final_address    setting value.
   */
  void SetLocalFinalAddress(  // line separate
    const std::string& local_final_address) {  // NOLINT
    this->local_final_address_ = local_final_address;
  }
  /**
   * @brief Get data type of localFinalAddress
   * @return Data type of localFinalAddress
   */
  static std::string GetLocalFinalAddressFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of localFinalAddress field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetLocalFinalAddressString(  // line separate
      const CreateRefundTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.local_final_address_);
  }
  /**
   * @brief Set json object to localFinalAddress field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetLocalFinalAddressString(  // line separate
      CreateRefundTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.local_final_address_, json_value);
  }

  /**
   * @brief Get of remoteFinalAddress
   * @return remoteFinalAddress
   */
  std::string GetRemoteFinalAddress() const {
    return remote_final_address_;
  }
  /**
   * @brief Set to remoteFinalAddress
   * @param[in] remote_final_address    setting value.
   */
  void SetRemoteFinalAddress(  // line separate
    const std::string& remote_final_address) {  // NOLINT
    this->remote_final_address_ = remote_final_address;
  }
  /**
   * @brief Get data type of remoteFinalAddress
   * @return Data type of remoteFinalAddress
   */
  static std::string GetRemoteFinalAddressFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of remoteFinalAddress field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetRemoteFinalAddressString(  // line separate
      const CreateRefundTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.remote_final_address_);
  }
  /**
   * @brief Set json object to remoteFinalAddress field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetRemoteFinalAddressString(  // line separate
      CreateRefundTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.remote_final_address_, json_value);
  }

  /**
   * @brief Get of localAmount
   * @return localAmount
   */
  uint64_t GetLocalAmount() const {
    return local_amount_;
  }
  /**
   * @brief Set to localAmount
   * @param[in] local_amount    setting value.
   */
  void SetLocalAmount(  // line separate
    const uint64_t& local_amount) {  // NOLINT
    this->local_amount_ = local_amount;
  }
  /**
   * @brief Get data type of localAmount
   * @return Data type of localAmount
   */
  static std::string GetLocalAmountFieldType() {
    return "uint64_t";
  }
  /**
   * @brief Get json string of localAmount field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetLocalAmountString(  // line separate
      const CreateRefundTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.local_amount_);
  }
  /**
   * @brief Set json object to localAmount field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetLocalAmountString(  // line separate
      CreateRefundTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.local_amount_, json_value);
  }

  /**
   * @brief Get of remoteAmount
   * @return remoteAmount
   */
  uint64_t GetRemoteAmount() const {
    return remote_amount_;
  }
  /**
   * @brief Set to remoteAmount
   * @param[in] remote_amount    setting value.
   */
  void SetRemoteAmount(  // line separate
    const uint64_t& remote_amount) {  // NOLINT
    this->remote_amount_ = remote_amount;
  }
  /**
   * @brief Get data type of remoteAmount
   * @return Data type of remoteAmount
   */
  static std::string GetRemoteAmountFieldType() {
    return "uint64_t";
  }
  /**
   * @brief Get json string of remoteAmount field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetRemoteAmountString(  // line separate
      const CreateRefundTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.remote_amount_);
  }
  /**
   * @brief Set json object to remoteAmount field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetRemoteAmountString(  // line separate
      CreateRefundTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.remote_amount_, json_value);
  }

  /**
   * @brief Get of lockTime
   * @return lockTime
   */
  uint64_t GetLockTime() const {
    return lock_time_;
  }
  /**
   * @brief Set to lockTime
   * @param[in] lock_time    setting value.
   */
  void SetLockTime(  // line separate
    const uint64_t& lock_time) {  // NOLINT
    this->lock_time_ = lock_time;
  }
  /**
   * @brief Get data type of lockTime
   * @return Data type of lockTime
   */
  static std::string GetLockTimeFieldType() {
    return "uint64_t";
  }
  /**
   * @brief Get json string of lockTime field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetLockTimeString(  // line separate
      const CreateRefundTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.lock_time_);
  }
  /**
   * @brief Set json object to lockTime field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetLockTimeString(  // line separate
      CreateRefundTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.lock_time_, json_value);
  }

  /**
   * @brief Get of fundTxid
   * @return fundTxid
   */
  std::string GetFundTxid() const {
    return fund_txid_;
  }
  /**
   * @brief Set to fundTxid
   * @param[in] fund_txid    setting value.
   */
  void SetFundTxid(  // line separate
    const std::string& fund_txid) {  // NOLINT
    this->fund_txid_ = fund_txid;
  }
  /**
   * @brief Get data type of fundTxid
   * @return Data type of fundTxid
   */
  static std::string GetFundTxidFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of fundTxid field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetFundTxidString(  // line separate
      const CreateRefundTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fund_txid_);
  }
  /**
   * @brief Set json object to fundTxid field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFundTxidString(  // line separate
      CreateRefundTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.fund_txid_, json_value);
  }

  /**
   * @brief Get of fundVout
   * @return fundVout
   */
  uint32_t GetFundVout() const {
    return fund_vout_;
  }
  /**
   * @brief Set to fundVout
   * @param[in] fund_vout    setting value.
   */
  void SetFundVout(  // line separate
    const uint32_t& fund_vout) {  // NOLINT
    this->fund_vout_ = fund_vout;
  }
  /**
   * @brief Get data type of fundVout
   * @return Data type of fundVout
   */
  static std::string GetFundVoutFieldType() {
    return "uint32_t";
  }
  /**
   * @brief Get json string of fundVout field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetFundVoutString(  // line separate
      const CreateRefundTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fund_vout_);
  }
  /**
   * @brief Set json object to fundVout field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFundVoutString(  // line separate
      CreateRefundTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.fund_vout_, json_value);
  }

  /**
   * @brief Set ignore item.
   * @param[in] key   ignore target key name.
   */
  void SetIgnoreItem(const std::string& key) {
    ignore_items.insert(key);
  }

  /**
   * @brief Convert struct to class.
   * @param[in] data   struct data.
   */
  void ConvertFromStruct(
      const CreateRefundTransactionRequestStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  CreateRefundTransactionRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using CreateRefundTransactionRequestMapTable =
    cfd::core::JsonTableMap<CreateRefundTransactionRequest>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const CreateRefundTransactionRequestMapTable& GetJsonMapper() const {  // NOLINT
    return json_mapper;
  }
  /**
   * @brief Get item lists of JSON mapping.
   * Fetch a list of target variable names in the order of definition.
   * @return Item lists of JSON mapping.
   * @see cfd::core::JsonClassBase::GetJsonItemList()
   */
  virtual const std::vector<std::string>& GetJsonItemList() const {
    return item_list;
  }
  /**
   * @brief Get ignore item lists of JSON mnapping.
   * Ignore the target variable at Serialize.
   * @return Item list of JSON mapping.
   * @see cfd::core::JsonClassBase::GetIgnoreItem()
   */
  virtual const std::set<std::string>& GetIgnoreItem() const {
    return ignore_items;
  }

 private:
 /**
  * @brief JsonFunctionMap table
  */
  static CreateRefundTransactionRequestMapTable json_mapper;
  /**
   * @brief field name list.
   */
  static std::vector<std::string> item_list;
  /**
   * @brief ignore item list.
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(localFinalAddress) value
   */
  std::string local_final_address_ = "";
  /**
   * @brief JsonAPI(remoteFinalAddress) value
   */
  std::string remote_final_address_ = "";
  /**
   * @brief JsonAPI(localAmount) value
   */
  uint64_t local_amount_ = 0;
  /**
   * @brief JsonAPI(remoteAmount) value
   */
  uint64_t remote_amount_ = 0;
  /**
   * @brief JsonAPI(lockTime) value
   */
  uint64_t lock_time_ = 0;
  /**
   * @brief JsonAPI(fundTxid) value
   */
  std::string fund_txid_ = "";
  /**
   * @brief JsonAPI(fundVout) value
   */
  uint32_t fund_vout_ = 0;
};

// ------------------------------------------------------------------------
// CreateRefundTransactionResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (CreateRefundTransactionResponse) class
 */
class CreateRefundTransactionResponse
  : public cfd::core::JsonClassBase<CreateRefundTransactionResponse> {
 public:
  CreateRefundTransactionResponse() {
    CollectFieldName();
  }
  virtual ~CreateRefundTransactionResponse() {
    // do nothing
  }
  /**
   * @brief collect field name.
   */
  static void CollectFieldName();

  /**
   * @brief Get of hex
   * @return hex
   */
  std::string GetHex() const {
    return hex_;
  }
  /**
   * @brief Set to hex
   * @param[in] hex    setting value.
   */
  void SetHex(  // line separate
    const std::string& hex) {  // NOLINT
    this->hex_ = hex;
  }
  /**
   * @brief Get data type of hex
   * @return Data type of hex
   */
  static std::string GetHexFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of hex field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetHexString(  // line separate
      const CreateRefundTransactionResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.hex_);
  }
  /**
   * @brief Set json object to hex field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetHexString(  // line separate
      CreateRefundTransactionResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.hex_, json_value);
  }

  /**
   * @brief Set ignore item.
   * @param[in] key   ignore target key name.
   */
  void SetIgnoreItem(const std::string& key) {
    ignore_items.insert(key);
  }

  /**
   * @brief Convert struct to class.
   * @param[in] data   struct data.
   */
  void ConvertFromStruct(
      const CreateRefundTransactionResponseStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  CreateRefundTransactionResponseStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using CreateRefundTransactionResponseMapTable =
    cfd::core::JsonTableMap<CreateRefundTransactionResponse>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const CreateRefundTransactionResponseMapTable& GetJsonMapper() const {  // NOLINT
    return json_mapper;
  }
  /**
   * @brief Get item lists of JSON mapping.
   * Fetch a list of target variable names in the order of definition.
   * @return Item lists of JSON mapping.
   * @see cfd::core::JsonClassBase::GetJsonItemList()
   */
  virtual const std::vector<std::string>& GetJsonItemList() const {
    return item_list;
  }
  /**
   * @brief Get ignore item lists of JSON mnapping.
   * Ignore the target variable at Serialize.
   * @return Item list of JSON mapping.
   * @see cfd::core::JsonClassBase::GetIgnoreItem()
   */
  virtual const std::set<std::string>& GetIgnoreItem() const {
    return ignore_items;
  }

 private:
 /**
  * @brief JsonFunctionMap table
  */
  static CreateRefundTransactionResponseMapTable json_mapper;
  /**
   * @brief field name list.
   */
  static std::vector<std::string> item_list;
  /**
   * @brief ignore item list.
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(hex) value
   */
  std::string hex_ = "";
};

// ------------------------------------------------------------------------
// InnerErrorResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (InnerErrorResponse) class
 */
class InnerErrorResponse
  : public cfd::core::JsonClassBase<InnerErrorResponse> {
 public:
  InnerErrorResponse() {
    CollectFieldName();
  }
  virtual ~InnerErrorResponse() {
    // do nothing
  }
  /**
   * @brief collect field name.
   */
  static void CollectFieldName();

  /**
   * @brief Get of code
   * @return code
   */
  uint32_t GetCode() const {
    return code_;
  }
  /**
   * @brief Set to code
   * @param[in] code    setting value.
   */
  void SetCode(  // line separate
    const uint32_t& code) {  // NOLINT
    this->code_ = code;
  }
  /**
   * @brief Get data type of code
   * @return Data type of code
   */
  static std::string GetCodeFieldType() {
    return "uint32_t";
  }
  /**
   * @brief Get json string of code field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetCodeString(  // line separate
      const InnerErrorResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.code_);
  }
  /**
   * @brief Set json object to code field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetCodeString(  // line separate
      InnerErrorResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.code_, json_value);
  }

  /**
   * @brief Get of type
   * @return type
   */
  std::string GetType() const {
    return type_;
  }
  /**
   * @brief Set to type
   * @param[in] type    setting value.
   */
  void SetType(  // line separate
    const std::string& type) {  // NOLINT
    this->type_ = type;
  }
  /**
   * @brief Get data type of type
   * @return Data type of type
   */
  static std::string GetTypeFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of type field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetTypeString(  // line separate
      const InnerErrorResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.type_);
  }
  /**
   * @brief Set json object to type field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetTypeString(  // line separate
      InnerErrorResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.type_, json_value);
  }

  /**
   * @brief Get of message
   * @return message
   */
  std::string GetMessage() const {
    return message_;
  }
  /**
   * @brief Set to message
   * @param[in] message    setting value.
   */
  void SetMessage(  // line separate
    const std::string& message) {  // NOLINT
    this->message_ = message;
  }
  /**
   * @brief Get data type of message
   * @return Data type of message
   */
  static std::string GetMessageFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of message field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetMessageString(  // line separate
      const InnerErrorResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.message_);
  }
  /**
   * @brief Set json object to message field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetMessageString(  // line separate
      InnerErrorResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.message_, json_value);
  }

  /**
   * @brief Set ignore item.
   * @param[in] key   ignore target key name.
   */
  void SetIgnoreItem(const std::string& key) {
    ignore_items.insert(key);
  }

  /**
   * @brief Convert struct to class.
   * @param[in] data   struct data.
   */
  void ConvertFromStruct(
      const InnerErrorResponseStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  InnerErrorResponseStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using InnerErrorResponseMapTable =
    cfd::core::JsonTableMap<InnerErrorResponse>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const InnerErrorResponseMapTable& GetJsonMapper() const {  // NOLINT
    return json_mapper;
  }
  /**
   * @brief Get item lists of JSON mapping.
   * Fetch a list of target variable names in the order of definition.
   * @return Item lists of JSON mapping.
   * @see cfd::core::JsonClassBase::GetJsonItemList()
   */
  virtual const std::vector<std::string>& GetJsonItemList() const {
    return item_list;
  }
  /**
   * @brief Get ignore item lists of JSON mnapping.
   * Ignore the target variable at Serialize.
   * @return Item list of JSON mapping.
   * @see cfd::core::JsonClassBase::GetIgnoreItem()
   */
  virtual const std::set<std::string>& GetIgnoreItem() const {
    return ignore_items;
  }

 private:
 /**
  * @brief JsonFunctionMap table
  */
  static InnerErrorResponseMapTable json_mapper;
  /**
   * @brief field name list.
   */
  static std::vector<std::string> item_list;
  /**
   * @brief ignore item list.
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(code) value
   */
  uint32_t code_ = 0;
  /**
   * @brief JsonAPI(type) value
   */
  std::string type_ = "";
  /**
   * @brief JsonAPI(message) value
   */
  std::string message_ = "";
};

// ------------------------------------------------------------------------
// ErrorResponseBase
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (ErrorResponseBase) class
 */
class ErrorResponseBase
  : public cfd::core::JsonClassBase<ErrorResponseBase> {
 public:
  ErrorResponseBase() {
    CollectFieldName();
  }
  virtual ~ErrorResponseBase() {
    // do nothing
  }
  /**
   * @brief collect field name.
   */
  static void CollectFieldName();

  /**
   * @brief Get of error.
   * @return error
   */
  InnerErrorResponse& GetError() {  // NOLINT
    return error_;
  }
  /**
   * @brief Set to error.
   * @param[in] error    setting value.
   */
  void SetError(  // line separate
      const InnerErrorResponse& error) {  // NOLINT
    this->error_ = error;
  }
  /**
   * @brief Get data type of error.
   * @return Data type of error.
   */
  static std::string GetErrorFieldType() {
    return "InnerErrorResponse";  // NOLINT
  }
  /**
   * @brief Get json string of error field.
   * @param[in,out] obj     class object
   * @return JSON string.
   */
  static std::string GetErrorString(  // line separate
      const ErrorResponseBase& obj) {  // NOLINT
    // Do not set to const, because substitution of member variables
    // may occur in pre / post processing inside Serialize
    return obj.error_.Serialize();
  }
  /**
   * @brief Set json object to error field.
   * @param[in,out] obj     class object
   * @param[in] json_value  JSON object
   */
  static void SetErrorString(  // line separate
      ErrorResponseBase& obj,  // NOLINT
      const UniValue& json_value) {
    obj.error_.DeserializeUniValue(json_value);
  }

  /**
   * @brief Set ignore item.
   * @param[in] key   ignore target key name.
   */
  void SetIgnoreItem(const std::string& key) {
    ignore_items.insert(key);
  }



 protected:
  /**
   * @brief definition type of Map table.
   */
  using ErrorResponseBaseMapTable =
    cfd::core::JsonTableMap<ErrorResponseBase>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const ErrorResponseBaseMapTable& GetJsonMapper() const {  // NOLINT
    return json_mapper;
  }
  /**
   * @brief Get item lists of JSON mapping.
   * Fetch a list of target variable names in the order of definition.
   * @return Item lists of JSON mapping.
   * @see cfd::core::JsonClassBase::GetJsonItemList()
   */
  virtual const std::vector<std::string>& GetJsonItemList() const {
    return item_list;
  }
  /**
   * @brief Get ignore item lists of JSON mnapping.
   * Ignore the target variable at Serialize.
   * @return Item list of JSON mapping.
   * @see cfd::core::JsonClassBase::GetIgnoreItem()
   */
  virtual const std::set<std::string>& GetIgnoreItem() const {
    return ignore_items;
  }

 private:
 /**
  * @brief JsonFunctionMap table
  */
  static ErrorResponseBaseMapTable json_mapper;
  /**
   * @brief field name list.
   */
  static std::vector<std::string> item_list;
  /**
   * @brief ignore item list.
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(error) value
   */
  InnerErrorResponse error_;  // NOLINT
};

// ------------------------------------------------------------------------
// GetRawCetSignatureRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (GetRawCetSignatureRequest) class
 */
class GetRawCetSignatureRequest
  : public cfd::core::JsonClassBase<GetRawCetSignatureRequest> {
 public:
  GetRawCetSignatureRequest() {
    CollectFieldName();
  }
  virtual ~GetRawCetSignatureRequest() {
    // do nothing
  }
  /**
   * @brief collect field name.
   */
  static void CollectFieldName();

  /**
   * @brief Get of cetHex
   * @return cetHex
   */
  std::string GetCetHex() const {
    return cet_hex_;
  }
  /**
   * @brief Set to cetHex
   * @param[in] cet_hex    setting value.
   */
  void SetCetHex(  // line separate
    const std::string& cet_hex) {  // NOLINT
    this->cet_hex_ = cet_hex;
  }
  /**
   * @brief Get data type of cetHex
   * @return Data type of cetHex
   */
  static std::string GetCetHexFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of cetHex field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetCetHexString(  // line separate
      const GetRawCetSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.cet_hex_);
  }
  /**
   * @brief Set json object to cetHex field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetCetHexString(  // line separate
      GetRawCetSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.cet_hex_, json_value);
  }

  /**
   * @brief Get of privkey
   * @return privkey
   */
  std::string GetPrivkey() const {
    return privkey_;
  }
  /**
   * @brief Set to privkey
   * @param[in] privkey    setting value.
   */
  void SetPrivkey(  // line separate
    const std::string& privkey) {  // NOLINT
    this->privkey_ = privkey;
  }
  /**
   * @brief Get data type of privkey
   * @return Data type of privkey
   */
  static std::string GetPrivkeyFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of privkey field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetPrivkeyString(  // line separate
      const GetRawCetSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.privkey_);
  }
  /**
   * @brief Set json object to privkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetPrivkeyString(  // line separate
      GetRawCetSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.privkey_, json_value);
  }

  /**
   * @brief Get of fundTxId
   * @return fundTxId
   */
  std::string GetFundTxId() const {
    return fund_tx_id_;
  }
  /**
   * @brief Set to fundTxId
   * @param[in] fund_tx_id    setting value.
   */
  void SetFundTxId(  // line separate
    const std::string& fund_tx_id) {  // NOLINT
    this->fund_tx_id_ = fund_tx_id;
  }
  /**
   * @brief Get data type of fundTxId
   * @return Data type of fundTxId
   */
  static std::string GetFundTxIdFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of fundTxId field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetFundTxIdString(  // line separate
      const GetRawCetSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fund_tx_id_);
  }
  /**
   * @brief Set json object to fundTxId field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFundTxIdString(  // line separate
      GetRawCetSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.fund_tx_id_, json_value);
  }

  /**
   * @brief Get of fundTxVout
   * @return fundTxVout
   */
  uint32_t GetFundTxVout() const {
    return fund_tx_vout_;
  }
  /**
   * @brief Set to fundTxVout
   * @param[in] fund_tx_vout    setting value.
   */
  void SetFundTxVout(  // line separate
    const uint32_t& fund_tx_vout) {  // NOLINT
    this->fund_tx_vout_ = fund_tx_vout;
  }
  /**
   * @brief Get data type of fundTxVout
   * @return Data type of fundTxVout
   */
  static std::string GetFundTxVoutFieldType() {
    return "uint32_t";
  }
  /**
   * @brief Get json string of fundTxVout field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetFundTxVoutString(  // line separate
      const GetRawCetSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fund_tx_vout_);
  }
  /**
   * @brief Set json object to fundTxVout field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFundTxVoutString(  // line separate
      GetRawCetSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.fund_tx_vout_, json_value);
  }

  /**
   * @brief Get of localFundPubkey
   * @return localFundPubkey
   */
  std::string GetLocalFundPubkey() const {
    return local_fund_pubkey_;
  }
  /**
   * @brief Set to localFundPubkey
   * @param[in] local_fund_pubkey    setting value.
   */
  void SetLocalFundPubkey(  // line separate
    const std::string& local_fund_pubkey) {  // NOLINT
    this->local_fund_pubkey_ = local_fund_pubkey;
  }
  /**
   * @brief Get data type of localFundPubkey
   * @return Data type of localFundPubkey
   */
  static std::string GetLocalFundPubkeyFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of localFundPubkey field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetLocalFundPubkeyString(  // line separate
      const GetRawCetSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.local_fund_pubkey_);
  }
  /**
   * @brief Set json object to localFundPubkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetLocalFundPubkeyString(  // line separate
      GetRawCetSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.local_fund_pubkey_, json_value);
  }

  /**
   * @brief Get of remoteFundPubkey
   * @return remoteFundPubkey
   */
  std::string GetRemoteFundPubkey() const {
    return remote_fund_pubkey_;
  }
  /**
   * @brief Set to remoteFundPubkey
   * @param[in] remote_fund_pubkey    setting value.
   */
  void SetRemoteFundPubkey(  // line separate
    const std::string& remote_fund_pubkey) {  // NOLINT
    this->remote_fund_pubkey_ = remote_fund_pubkey;
  }
  /**
   * @brief Get data type of remoteFundPubkey
   * @return Data type of remoteFundPubkey
   */
  static std::string GetRemoteFundPubkeyFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of remoteFundPubkey field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetRemoteFundPubkeyString(  // line separate
      const GetRawCetSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.remote_fund_pubkey_);
  }
  /**
   * @brief Set json object to remoteFundPubkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetRemoteFundPubkeyString(  // line separate
      GetRawCetSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.remote_fund_pubkey_, json_value);
  }

  /**
   * @brief Get of fundAmount
   * @return fundAmount
   */
  uint64_t GetFundAmount() const {
    return fund_amount_;
  }
  /**
   * @brief Set to fundAmount
   * @param[in] fund_amount    setting value.
   */
  void SetFundAmount(  // line separate
    const uint64_t& fund_amount) {  // NOLINT
    this->fund_amount_ = fund_amount;
  }
  /**
   * @brief Get data type of fundAmount
   * @return Data type of fundAmount
   */
  static std::string GetFundAmountFieldType() {
    return "uint64_t";
  }
  /**
   * @brief Get json string of fundAmount field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetFundAmountString(  // line separate
      const GetRawCetSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fund_amount_);
  }
  /**
   * @brief Set json object to fundAmount field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFundAmountString(  // line separate
      GetRawCetSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.fund_amount_, json_value);
  }

  /**
   * @brief Set ignore item.
   * @param[in] key   ignore target key name.
   */
  void SetIgnoreItem(const std::string& key) {
    ignore_items.insert(key);
  }

  /**
   * @brief Convert struct to class.
   * @param[in] data   struct data.
   */
  void ConvertFromStruct(
      const GetRawCetSignatureRequestStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  GetRawCetSignatureRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using GetRawCetSignatureRequestMapTable =
    cfd::core::JsonTableMap<GetRawCetSignatureRequest>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const GetRawCetSignatureRequestMapTable& GetJsonMapper() const {  // NOLINT
    return json_mapper;
  }
  /**
   * @brief Get item lists of JSON mapping.
   * Fetch a list of target variable names in the order of definition.
   * @return Item lists of JSON mapping.
   * @see cfd::core::JsonClassBase::GetJsonItemList()
   */
  virtual const std::vector<std::string>& GetJsonItemList() const {
    return item_list;
  }
  /**
   * @brief Get ignore item lists of JSON mnapping.
   * Ignore the target variable at Serialize.
   * @return Item list of JSON mapping.
   * @see cfd::core::JsonClassBase::GetIgnoreItem()
   */
  virtual const std::set<std::string>& GetIgnoreItem() const {
    return ignore_items;
  }

 private:
 /**
  * @brief JsonFunctionMap table
  */
  static GetRawCetSignatureRequestMapTable json_mapper;
  /**
   * @brief field name list.
   */
  static std::vector<std::string> item_list;
  /**
   * @brief ignore item list.
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(cetHex) value
   */
  std::string cet_hex_ = "";
  /**
   * @brief JsonAPI(privkey) value
   */
  std::string privkey_ = "";
  /**
   * @brief JsonAPI(fundTxId) value
   */
  std::string fund_tx_id_ = "";
  /**
   * @brief JsonAPI(fundTxVout) value
   */
  uint32_t fund_tx_vout_ = 0;
  /**
   * @brief JsonAPI(localFundPubkey) value
   */
  std::string local_fund_pubkey_ = "";
  /**
   * @brief JsonAPI(remoteFundPubkey) value
   */
  std::string remote_fund_pubkey_ = "";
  /**
   * @brief JsonAPI(fundAmount) value
   */
  uint64_t fund_amount_ = 0;
};

// ------------------------------------------------------------------------
// GetRawCetSignatureResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (GetRawCetSignatureResponse) class
 */
class GetRawCetSignatureResponse
  : public cfd::core::JsonClassBase<GetRawCetSignatureResponse> {
 public:
  GetRawCetSignatureResponse() {
    CollectFieldName();
  }
  virtual ~GetRawCetSignatureResponse() {
    // do nothing
  }
  /**
   * @brief collect field name.
   */
  static void CollectFieldName();

  /**
   * @brief Get of hex
   * @return hex
   */
  std::string GetHex() const {
    return hex_;
  }
  /**
   * @brief Set to hex
   * @param[in] hex    setting value.
   */
  void SetHex(  // line separate
    const std::string& hex) {  // NOLINT
    this->hex_ = hex;
  }
  /**
   * @brief Get data type of hex
   * @return Data type of hex
   */
  static std::string GetHexFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of hex field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetHexString(  // line separate
      const GetRawCetSignatureResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.hex_);
  }
  /**
   * @brief Set json object to hex field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetHexString(  // line separate
      GetRawCetSignatureResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.hex_, json_value);
  }

  /**
   * @brief Set ignore item.
   * @param[in] key   ignore target key name.
   */
  void SetIgnoreItem(const std::string& key) {
    ignore_items.insert(key);
  }

  /**
   * @brief Convert struct to class.
   * @param[in] data   struct data.
   */
  void ConvertFromStruct(
      const GetRawCetSignatureResponseStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  GetRawCetSignatureResponseStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using GetRawCetSignatureResponseMapTable =
    cfd::core::JsonTableMap<GetRawCetSignatureResponse>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const GetRawCetSignatureResponseMapTable& GetJsonMapper() const {  // NOLINT
    return json_mapper;
  }
  /**
   * @brief Get item lists of JSON mapping.
   * Fetch a list of target variable names in the order of definition.
   * @return Item lists of JSON mapping.
   * @see cfd::core::JsonClassBase::GetJsonItemList()
   */
  virtual const std::vector<std::string>& GetJsonItemList() const {
    return item_list;
  }
  /**
   * @brief Get ignore item lists of JSON mnapping.
   * Ignore the target variable at Serialize.
   * @return Item list of JSON mapping.
   * @see cfd::core::JsonClassBase::GetIgnoreItem()
   */
  virtual const std::set<std::string>& GetIgnoreItem() const {
    return ignore_items;
  }

 private:
 /**
  * @brief JsonFunctionMap table
  */
  static GetRawCetSignatureResponseMapTable json_mapper;
  /**
   * @brief field name list.
   */
  static std::vector<std::string> item_list;
  /**
   * @brief ignore item list.
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(hex) value
   */
  std::string hex_ = "";
};

// ------------------------------------------------------------------------
// GetRawMutualClosingTxSignatureRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (GetRawMutualClosingTxSignatureRequest) class
 */
class GetRawMutualClosingTxSignatureRequest
  : public cfd::core::JsonClassBase<GetRawMutualClosingTxSignatureRequest> {
 public:
  GetRawMutualClosingTxSignatureRequest() {
    CollectFieldName();
  }
  virtual ~GetRawMutualClosingTxSignatureRequest() {
    // do nothing
  }
  /**
   * @brief collect field name.
   */
  static void CollectFieldName();

  /**
   * @brief Get of mutualClosingHex
   * @return mutualClosingHex
   */
  std::string GetMutualClosingHex() const {
    return mutual_closing_hex_;
  }
  /**
   * @brief Set to mutualClosingHex
   * @param[in] mutual_closing_hex    setting value.
   */
  void SetMutualClosingHex(  // line separate
    const std::string& mutual_closing_hex) {  // NOLINT
    this->mutual_closing_hex_ = mutual_closing_hex;
  }
  /**
   * @brief Get data type of mutualClosingHex
   * @return Data type of mutualClosingHex
   */
  static std::string GetMutualClosingHexFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of mutualClosingHex field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetMutualClosingHexString(  // line separate
      const GetRawMutualClosingTxSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.mutual_closing_hex_);
  }
  /**
   * @brief Set json object to mutualClosingHex field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetMutualClosingHexString(  // line separate
      GetRawMutualClosingTxSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.mutual_closing_hex_, json_value);
  }

  /**
   * @brief Get of privkey
   * @return privkey
   */
  std::string GetPrivkey() const {
    return privkey_;
  }
  /**
   * @brief Set to privkey
   * @param[in] privkey    setting value.
   */
  void SetPrivkey(  // line separate
    const std::string& privkey) {  // NOLINT
    this->privkey_ = privkey;
  }
  /**
   * @brief Get data type of privkey
   * @return Data type of privkey
   */
  static std::string GetPrivkeyFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of privkey field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetPrivkeyString(  // line separate
      const GetRawMutualClosingTxSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.privkey_);
  }
  /**
   * @brief Set json object to privkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetPrivkeyString(  // line separate
      GetRawMutualClosingTxSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.privkey_, json_value);
  }

  /**
   * @brief Get of fundTxId
   * @return fundTxId
   */
  std::string GetFundTxId() const {
    return fund_tx_id_;
  }
  /**
   * @brief Set to fundTxId
   * @param[in] fund_tx_id    setting value.
   */
  void SetFundTxId(  // line separate
    const std::string& fund_tx_id) {  // NOLINT
    this->fund_tx_id_ = fund_tx_id;
  }
  /**
   * @brief Get data type of fundTxId
   * @return Data type of fundTxId
   */
  static std::string GetFundTxIdFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of fundTxId field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetFundTxIdString(  // line separate
      const GetRawMutualClosingTxSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fund_tx_id_);
  }
  /**
   * @brief Set json object to fundTxId field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFundTxIdString(  // line separate
      GetRawMutualClosingTxSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.fund_tx_id_, json_value);
  }

  /**
   * @brief Get of fundTxVout
   * @return fundTxVout
   */
  uint32_t GetFundTxVout() const {
    return fund_tx_vout_;
  }
  /**
   * @brief Set to fundTxVout
   * @param[in] fund_tx_vout    setting value.
   */
  void SetFundTxVout(  // line separate
    const uint32_t& fund_tx_vout) {  // NOLINT
    this->fund_tx_vout_ = fund_tx_vout;
  }
  /**
   * @brief Get data type of fundTxVout
   * @return Data type of fundTxVout
   */
  static std::string GetFundTxVoutFieldType() {
    return "uint32_t";
  }
  /**
   * @brief Get json string of fundTxVout field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetFundTxVoutString(  // line separate
      const GetRawMutualClosingTxSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fund_tx_vout_);
  }
  /**
   * @brief Set json object to fundTxVout field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFundTxVoutString(  // line separate
      GetRawMutualClosingTxSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.fund_tx_vout_, json_value);
  }

  /**
   * @brief Get of localFundPubkey
   * @return localFundPubkey
   */
  std::string GetLocalFundPubkey() const {
    return local_fund_pubkey_;
  }
  /**
   * @brief Set to localFundPubkey
   * @param[in] local_fund_pubkey    setting value.
   */
  void SetLocalFundPubkey(  // line separate
    const std::string& local_fund_pubkey) {  // NOLINT
    this->local_fund_pubkey_ = local_fund_pubkey;
  }
  /**
   * @brief Get data type of localFundPubkey
   * @return Data type of localFundPubkey
   */
  static std::string GetLocalFundPubkeyFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of localFundPubkey field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetLocalFundPubkeyString(  // line separate
      const GetRawMutualClosingTxSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.local_fund_pubkey_);
  }
  /**
   * @brief Set json object to localFundPubkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetLocalFundPubkeyString(  // line separate
      GetRawMutualClosingTxSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.local_fund_pubkey_, json_value);
  }

  /**
   * @brief Get of remoteFundPubkey
   * @return remoteFundPubkey
   */
  std::string GetRemoteFundPubkey() const {
    return remote_fund_pubkey_;
  }
  /**
   * @brief Set to remoteFundPubkey
   * @param[in] remote_fund_pubkey    setting value.
   */
  void SetRemoteFundPubkey(  // line separate
    const std::string& remote_fund_pubkey) {  // NOLINT
    this->remote_fund_pubkey_ = remote_fund_pubkey;
  }
  /**
   * @brief Get data type of remoteFundPubkey
   * @return Data type of remoteFundPubkey
   */
  static std::string GetRemoteFundPubkeyFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of remoteFundPubkey field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetRemoteFundPubkeyString(  // line separate
      const GetRawMutualClosingTxSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.remote_fund_pubkey_);
  }
  /**
   * @brief Set json object to remoteFundPubkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetRemoteFundPubkeyString(  // line separate
      GetRawMutualClosingTxSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.remote_fund_pubkey_, json_value);
  }

  /**
   * @brief Get of fundAmount
   * @return fundAmount
   */
  uint64_t GetFundAmount() const {
    return fund_amount_;
  }
  /**
   * @brief Set to fundAmount
   * @param[in] fund_amount    setting value.
   */
  void SetFundAmount(  // line separate
    const uint64_t& fund_amount) {  // NOLINT
    this->fund_amount_ = fund_amount;
  }
  /**
   * @brief Get data type of fundAmount
   * @return Data type of fundAmount
   */
  static std::string GetFundAmountFieldType() {
    return "uint64_t";
  }
  /**
   * @brief Get json string of fundAmount field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetFundAmountString(  // line separate
      const GetRawMutualClosingTxSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fund_amount_);
  }
  /**
   * @brief Set json object to fundAmount field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFundAmountString(  // line separate
      GetRawMutualClosingTxSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.fund_amount_, json_value);
  }

  /**
   * @brief Set ignore item.
   * @param[in] key   ignore target key name.
   */
  void SetIgnoreItem(const std::string& key) {
    ignore_items.insert(key);
  }

  /**
   * @brief Convert struct to class.
   * @param[in] data   struct data.
   */
  void ConvertFromStruct(
      const GetRawMutualClosingTxSignatureRequestStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  GetRawMutualClosingTxSignatureRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using GetRawMutualClosingTxSignatureRequestMapTable =
    cfd::core::JsonTableMap<GetRawMutualClosingTxSignatureRequest>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const GetRawMutualClosingTxSignatureRequestMapTable& GetJsonMapper() const {  // NOLINT
    return json_mapper;
  }
  /**
   * @brief Get item lists of JSON mapping.
   * Fetch a list of target variable names in the order of definition.
   * @return Item lists of JSON mapping.
   * @see cfd::core::JsonClassBase::GetJsonItemList()
   */
  virtual const std::vector<std::string>& GetJsonItemList() const {
    return item_list;
  }
  /**
   * @brief Get ignore item lists of JSON mnapping.
   * Ignore the target variable at Serialize.
   * @return Item list of JSON mapping.
   * @see cfd::core::JsonClassBase::GetIgnoreItem()
   */
  virtual const std::set<std::string>& GetIgnoreItem() const {
    return ignore_items;
  }

 private:
 /**
  * @brief JsonFunctionMap table
  */
  static GetRawMutualClosingTxSignatureRequestMapTable json_mapper;
  /**
   * @brief field name list.
   */
  static std::vector<std::string> item_list;
  /**
   * @brief ignore item list.
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(mutualClosingHex) value
   */
  std::string mutual_closing_hex_ = "";
  /**
   * @brief JsonAPI(privkey) value
   */
  std::string privkey_ = "";
  /**
   * @brief JsonAPI(fundTxId) value
   */
  std::string fund_tx_id_ = "";
  /**
   * @brief JsonAPI(fundTxVout) value
   */
  uint32_t fund_tx_vout_ = 0;
  /**
   * @brief JsonAPI(localFundPubkey) value
   */
  std::string local_fund_pubkey_ = "";
  /**
   * @brief JsonAPI(remoteFundPubkey) value
   */
  std::string remote_fund_pubkey_ = "";
  /**
   * @brief JsonAPI(fundAmount) value
   */
  uint64_t fund_amount_ = 0;
};

// ------------------------------------------------------------------------
// GetRawMutualClosingTxSignatureResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (GetRawMutualClosingTxSignatureResponse) class
 */
class GetRawMutualClosingTxSignatureResponse
  : public cfd::core::JsonClassBase<GetRawMutualClosingTxSignatureResponse> {
 public:
  GetRawMutualClosingTxSignatureResponse() {
    CollectFieldName();
  }
  virtual ~GetRawMutualClosingTxSignatureResponse() {
    // do nothing
  }
  /**
   * @brief collect field name.
   */
  static void CollectFieldName();

  /**
   * @brief Get of hex
   * @return hex
   */
  std::string GetHex() const {
    return hex_;
  }
  /**
   * @brief Set to hex
   * @param[in] hex    setting value.
   */
  void SetHex(  // line separate
    const std::string& hex) {  // NOLINT
    this->hex_ = hex;
  }
  /**
   * @brief Get data type of hex
   * @return Data type of hex
   */
  static std::string GetHexFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of hex field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetHexString(  // line separate
      const GetRawMutualClosingTxSignatureResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.hex_);
  }
  /**
   * @brief Set json object to hex field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetHexString(  // line separate
      GetRawMutualClosingTxSignatureResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.hex_, json_value);
  }

  /**
   * @brief Set ignore item.
   * @param[in] key   ignore target key name.
   */
  void SetIgnoreItem(const std::string& key) {
    ignore_items.insert(key);
  }

  /**
   * @brief Convert struct to class.
   * @param[in] data   struct data.
   */
  void ConvertFromStruct(
      const GetRawMutualClosingTxSignatureResponseStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  GetRawMutualClosingTxSignatureResponseStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using GetRawMutualClosingTxSignatureResponseMapTable =
    cfd::core::JsonTableMap<GetRawMutualClosingTxSignatureResponse>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const GetRawMutualClosingTxSignatureResponseMapTable& GetJsonMapper() const {  // NOLINT
    return json_mapper;
  }
  /**
   * @brief Get item lists of JSON mapping.
   * Fetch a list of target variable names in the order of definition.
   * @return Item lists of JSON mapping.
   * @see cfd::core::JsonClassBase::GetJsonItemList()
   */
  virtual const std::vector<std::string>& GetJsonItemList() const {
    return item_list;
  }
  /**
   * @brief Get ignore item lists of JSON mnapping.
   * Ignore the target variable at Serialize.
   * @return Item list of JSON mapping.
   * @see cfd::core::JsonClassBase::GetIgnoreItem()
   */
  virtual const std::set<std::string>& GetIgnoreItem() const {
    return ignore_items;
  }

 private:
 /**
  * @brief JsonFunctionMap table
  */
  static GetRawMutualClosingTxSignatureResponseMapTable json_mapper;
  /**
   * @brief field name list.
   */
  static std::vector<std::string> item_list;
  /**
   * @brief ignore item list.
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(hex) value
   */
  std::string hex_ = "";
};

// ------------------------------------------------------------------------
// GetRawRefundTxSignatureRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (GetRawRefundTxSignatureRequest) class
 */
class GetRawRefundTxSignatureRequest
  : public cfd::core::JsonClassBase<GetRawRefundTxSignatureRequest> {
 public:
  GetRawRefundTxSignatureRequest() {
    CollectFieldName();
  }
  virtual ~GetRawRefundTxSignatureRequest() {
    // do nothing
  }
  /**
   * @brief collect field name.
   */
  static void CollectFieldName();

  /**
   * @brief Get of refundTxHex
   * @return refundTxHex
   */
  std::string GetRefundTxHex() const {
    return refund_tx_hex_;
  }
  /**
   * @brief Set to refundTxHex
   * @param[in] refund_tx_hex    setting value.
   */
  void SetRefundTxHex(  // line separate
    const std::string& refund_tx_hex) {  // NOLINT
    this->refund_tx_hex_ = refund_tx_hex;
  }
  /**
   * @brief Get data type of refundTxHex
   * @return Data type of refundTxHex
   */
  static std::string GetRefundTxHexFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of refundTxHex field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetRefundTxHexString(  // line separate
      const GetRawRefundTxSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.refund_tx_hex_);
  }
  /**
   * @brief Set json object to refundTxHex field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetRefundTxHexString(  // line separate
      GetRawRefundTxSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.refund_tx_hex_, json_value);
  }

  /**
   * @brief Get of privkey
   * @return privkey
   */
  std::string GetPrivkey() const {
    return privkey_;
  }
  /**
   * @brief Set to privkey
   * @param[in] privkey    setting value.
   */
  void SetPrivkey(  // line separate
    const std::string& privkey) {  // NOLINT
    this->privkey_ = privkey;
  }
  /**
   * @brief Get data type of privkey
   * @return Data type of privkey
   */
  static std::string GetPrivkeyFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of privkey field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetPrivkeyString(  // line separate
      const GetRawRefundTxSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.privkey_);
  }
  /**
   * @brief Set json object to privkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetPrivkeyString(  // line separate
      GetRawRefundTxSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.privkey_, json_value);
  }

  /**
   * @brief Get of fundTxId
   * @return fundTxId
   */
  std::string GetFundTxId() const {
    return fund_tx_id_;
  }
  /**
   * @brief Set to fundTxId
   * @param[in] fund_tx_id    setting value.
   */
  void SetFundTxId(  // line separate
    const std::string& fund_tx_id) {  // NOLINT
    this->fund_tx_id_ = fund_tx_id;
  }
  /**
   * @brief Get data type of fundTxId
   * @return Data type of fundTxId
   */
  static std::string GetFundTxIdFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of fundTxId field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetFundTxIdString(  // line separate
      const GetRawRefundTxSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fund_tx_id_);
  }
  /**
   * @brief Set json object to fundTxId field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFundTxIdString(  // line separate
      GetRawRefundTxSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.fund_tx_id_, json_value);
  }

  /**
   * @brief Get of fundTxVout
   * @return fundTxVout
   */
  uint32_t GetFundTxVout() const {
    return fund_tx_vout_;
  }
  /**
   * @brief Set to fundTxVout
   * @param[in] fund_tx_vout    setting value.
   */
  void SetFundTxVout(  // line separate
    const uint32_t& fund_tx_vout) {  // NOLINT
    this->fund_tx_vout_ = fund_tx_vout;
  }
  /**
   * @brief Get data type of fundTxVout
   * @return Data type of fundTxVout
   */
  static std::string GetFundTxVoutFieldType() {
    return "uint32_t";
  }
  /**
   * @brief Get json string of fundTxVout field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetFundTxVoutString(  // line separate
      const GetRawRefundTxSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fund_tx_vout_);
  }
  /**
   * @brief Set json object to fundTxVout field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFundTxVoutString(  // line separate
      GetRawRefundTxSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.fund_tx_vout_, json_value);
  }

  /**
   * @brief Get of localFundPubkey
   * @return localFundPubkey
   */
  std::string GetLocalFundPubkey() const {
    return local_fund_pubkey_;
  }
  /**
   * @brief Set to localFundPubkey
   * @param[in] local_fund_pubkey    setting value.
   */
  void SetLocalFundPubkey(  // line separate
    const std::string& local_fund_pubkey) {  // NOLINT
    this->local_fund_pubkey_ = local_fund_pubkey;
  }
  /**
   * @brief Get data type of localFundPubkey
   * @return Data type of localFundPubkey
   */
  static std::string GetLocalFundPubkeyFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of localFundPubkey field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetLocalFundPubkeyString(  // line separate
      const GetRawRefundTxSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.local_fund_pubkey_);
  }
  /**
   * @brief Set json object to localFundPubkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetLocalFundPubkeyString(  // line separate
      GetRawRefundTxSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.local_fund_pubkey_, json_value);
  }

  /**
   * @brief Get of remoteFundPubkey
   * @return remoteFundPubkey
   */
  std::string GetRemoteFundPubkey() const {
    return remote_fund_pubkey_;
  }
  /**
   * @brief Set to remoteFundPubkey
   * @param[in] remote_fund_pubkey    setting value.
   */
  void SetRemoteFundPubkey(  // line separate
    const std::string& remote_fund_pubkey) {  // NOLINT
    this->remote_fund_pubkey_ = remote_fund_pubkey;
  }
  /**
   * @brief Get data type of remoteFundPubkey
   * @return Data type of remoteFundPubkey
   */
  static std::string GetRemoteFundPubkeyFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of remoteFundPubkey field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetRemoteFundPubkeyString(  // line separate
      const GetRawRefundTxSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.remote_fund_pubkey_);
  }
  /**
   * @brief Set json object to remoteFundPubkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetRemoteFundPubkeyString(  // line separate
      GetRawRefundTxSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.remote_fund_pubkey_, json_value);
  }

  /**
   * @brief Get of fundAmount
   * @return fundAmount
   */
  uint64_t GetFundAmount() const {
    return fund_amount_;
  }
  /**
   * @brief Set to fundAmount
   * @param[in] fund_amount    setting value.
   */
  void SetFundAmount(  // line separate
    const uint64_t& fund_amount) {  // NOLINT
    this->fund_amount_ = fund_amount;
  }
  /**
   * @brief Get data type of fundAmount
   * @return Data type of fundAmount
   */
  static std::string GetFundAmountFieldType() {
    return "uint64_t";
  }
  /**
   * @brief Get json string of fundAmount field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetFundAmountString(  // line separate
      const GetRawRefundTxSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fund_amount_);
  }
  /**
   * @brief Set json object to fundAmount field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFundAmountString(  // line separate
      GetRawRefundTxSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.fund_amount_, json_value);
  }

  /**
   * @brief Set ignore item.
   * @param[in] key   ignore target key name.
   */
  void SetIgnoreItem(const std::string& key) {
    ignore_items.insert(key);
  }

  /**
   * @brief Convert struct to class.
   * @param[in] data   struct data.
   */
  void ConvertFromStruct(
      const GetRawRefundTxSignatureRequestStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  GetRawRefundTxSignatureRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using GetRawRefundTxSignatureRequestMapTable =
    cfd::core::JsonTableMap<GetRawRefundTxSignatureRequest>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const GetRawRefundTxSignatureRequestMapTable& GetJsonMapper() const {  // NOLINT
    return json_mapper;
  }
  /**
   * @brief Get item lists of JSON mapping.
   * Fetch a list of target variable names in the order of definition.
   * @return Item lists of JSON mapping.
   * @see cfd::core::JsonClassBase::GetJsonItemList()
   */
  virtual const std::vector<std::string>& GetJsonItemList() const {
    return item_list;
  }
  /**
   * @brief Get ignore item lists of JSON mnapping.
   * Ignore the target variable at Serialize.
   * @return Item list of JSON mapping.
   * @see cfd::core::JsonClassBase::GetIgnoreItem()
   */
  virtual const std::set<std::string>& GetIgnoreItem() const {
    return ignore_items;
  }

 private:
 /**
  * @brief JsonFunctionMap table
  */
  static GetRawRefundTxSignatureRequestMapTable json_mapper;
  /**
   * @brief field name list.
   */
  static std::vector<std::string> item_list;
  /**
   * @brief ignore item list.
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(refundTxHex) value
   */
  std::string refund_tx_hex_ = "";
  /**
   * @brief JsonAPI(privkey) value
   */
  std::string privkey_ = "";
  /**
   * @brief JsonAPI(fundTxId) value
   */
  std::string fund_tx_id_ = "";
  /**
   * @brief JsonAPI(fundTxVout) value
   */
  uint32_t fund_tx_vout_ = 0;
  /**
   * @brief JsonAPI(localFundPubkey) value
   */
  std::string local_fund_pubkey_ = "";
  /**
   * @brief JsonAPI(remoteFundPubkey) value
   */
  std::string remote_fund_pubkey_ = "";
  /**
   * @brief JsonAPI(fundAmount) value
   */
  uint64_t fund_amount_ = 0;
};

// ------------------------------------------------------------------------
// GetRawRefundTxSignatureResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (GetRawRefundTxSignatureResponse) class
 */
class GetRawRefundTxSignatureResponse
  : public cfd::core::JsonClassBase<GetRawRefundTxSignatureResponse> {
 public:
  GetRawRefundTxSignatureResponse() {
    CollectFieldName();
  }
  virtual ~GetRawRefundTxSignatureResponse() {
    // do nothing
  }
  /**
   * @brief collect field name.
   */
  static void CollectFieldName();

  /**
   * @brief Get of hex
   * @return hex
   */
  std::string GetHex() const {
    return hex_;
  }
  /**
   * @brief Set to hex
   * @param[in] hex    setting value.
   */
  void SetHex(  // line separate
    const std::string& hex) {  // NOLINT
    this->hex_ = hex;
  }
  /**
   * @brief Get data type of hex
   * @return Data type of hex
   */
  static std::string GetHexFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of hex field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetHexString(  // line separate
      const GetRawRefundTxSignatureResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.hex_);
  }
  /**
   * @brief Set json object to hex field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetHexString(  // line separate
      GetRawRefundTxSignatureResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.hex_, json_value);
  }

  /**
   * @brief Set ignore item.
   * @param[in] key   ignore target key name.
   */
  void SetIgnoreItem(const std::string& key) {
    ignore_items.insert(key);
  }

  /**
   * @brief Convert struct to class.
   * @param[in] data   struct data.
   */
  void ConvertFromStruct(
      const GetRawRefundTxSignatureResponseStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  GetRawRefundTxSignatureResponseStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using GetRawRefundTxSignatureResponseMapTable =
    cfd::core::JsonTableMap<GetRawRefundTxSignatureResponse>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const GetRawRefundTxSignatureResponseMapTable& GetJsonMapper() const {  // NOLINT
    return json_mapper;
  }
  /**
   * @brief Get item lists of JSON mapping.
   * Fetch a list of target variable names in the order of definition.
   * @return Item lists of JSON mapping.
   * @see cfd::core::JsonClassBase::GetJsonItemList()
   */
  virtual const std::vector<std::string>& GetJsonItemList() const {
    return item_list;
  }
  /**
   * @brief Get ignore item lists of JSON mnapping.
   * Ignore the target variable at Serialize.
   * @return Item list of JSON mapping.
   * @see cfd::core::JsonClassBase::GetIgnoreItem()
   */
  virtual const std::set<std::string>& GetIgnoreItem() const {
    return ignore_items;
  }

 private:
 /**
  * @brief JsonFunctionMap table
  */
  static GetRawRefundTxSignatureResponseMapTable json_mapper;
  /**
   * @brief field name list.
   */
  static std::vector<std::string> item_list;
  /**
   * @brief ignore item list.
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(hex) value
   */
  std::string hex_ = "";
};

// ------------------------------------------------------------------------
// SignClosingTransactionRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (SignClosingTransactionRequest) class
 */
class SignClosingTransactionRequest
  : public cfd::core::JsonClassBase<SignClosingTransactionRequest> {
 public:
  SignClosingTransactionRequest() {
    CollectFieldName();
  }
  virtual ~SignClosingTransactionRequest() {
    // do nothing
  }
  /**
   * @brief collect field name.
   */
  static void CollectFieldName();

  /**
   * @brief Get of closingTxHex
   * @return closingTxHex
   */
  std::string GetClosingTxHex() const {
    return closing_tx_hex_;
  }
  /**
   * @brief Set to closingTxHex
   * @param[in] closing_tx_hex    setting value.
   */
  void SetClosingTxHex(  // line separate
    const std::string& closing_tx_hex) {  // NOLINT
    this->closing_tx_hex_ = closing_tx_hex;
  }
  /**
   * @brief Get data type of closingTxHex
   * @return Data type of closingTxHex
   */
  static std::string GetClosingTxHexFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of closingTxHex field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetClosingTxHexString(  // line separate
      const SignClosingTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.closing_tx_hex_);
  }
  /**
   * @brief Set json object to closingTxHex field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetClosingTxHexString(  // line separate
      SignClosingTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.closing_tx_hex_, json_value);
  }

  /**
   * @brief Get of localFundPrivkey
   * @return localFundPrivkey
   */
  std::string GetLocalFundPrivkey() const {
    return local_fund_privkey_;
  }
  /**
   * @brief Set to localFundPrivkey
   * @param[in] local_fund_privkey    setting value.
   */
  void SetLocalFundPrivkey(  // line separate
    const std::string& local_fund_privkey) {  // NOLINT
    this->local_fund_privkey_ = local_fund_privkey;
  }
  /**
   * @brief Get data type of localFundPrivkey
   * @return Data type of localFundPrivkey
   */
  static std::string GetLocalFundPrivkeyFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of localFundPrivkey field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetLocalFundPrivkeyString(  // line separate
      const SignClosingTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.local_fund_privkey_);
  }
  /**
   * @brief Set json object to localFundPrivkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetLocalFundPrivkeyString(  // line separate
      SignClosingTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.local_fund_privkey_, json_value);
  }

  /**
   * @brief Get of localSweepPubkey
   * @return localSweepPubkey
   */
  std::string GetLocalSweepPubkey() const {
    return local_sweep_pubkey_;
  }
  /**
   * @brief Set to localSweepPubkey
   * @param[in] local_sweep_pubkey    setting value.
   */
  void SetLocalSweepPubkey(  // line separate
    const std::string& local_sweep_pubkey) {  // NOLINT
    this->local_sweep_pubkey_ = local_sweep_pubkey;
  }
  /**
   * @brief Get data type of localSweepPubkey
   * @return Data type of localSweepPubkey
   */
  static std::string GetLocalSweepPubkeyFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of localSweepPubkey field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetLocalSweepPubkeyString(  // line separate
      const SignClosingTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.local_sweep_pubkey_);
  }
  /**
   * @brief Set json object to localSweepPubkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetLocalSweepPubkeyString(  // line separate
      SignClosingTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.local_sweep_pubkey_, json_value);
  }

  /**
   * @brief Get of remoteSweepPubkey
   * @return remoteSweepPubkey
   */
  std::string GetRemoteSweepPubkey() const {
    return remote_sweep_pubkey_;
  }
  /**
   * @brief Set to remoteSweepPubkey
   * @param[in] remote_sweep_pubkey    setting value.
   */
  void SetRemoteSweepPubkey(  // line separate
    const std::string& remote_sweep_pubkey) {  // NOLINT
    this->remote_sweep_pubkey_ = remote_sweep_pubkey;
  }
  /**
   * @brief Get data type of remoteSweepPubkey
   * @return Data type of remoteSweepPubkey
   */
  static std::string GetRemoteSweepPubkeyFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of remoteSweepPubkey field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetRemoteSweepPubkeyString(  // line separate
      const SignClosingTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.remote_sweep_pubkey_);
  }
  /**
   * @brief Set json object to remoteSweepPubkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetRemoteSweepPubkeyString(  // line separate
      SignClosingTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.remote_sweep_pubkey_, json_value);
  }

  /**
   * @brief Get of oraclePubkey
   * @return oraclePubkey
   */
  std::string GetOraclePubkey() const {
    return oracle_pubkey_;
  }
  /**
   * @brief Set to oraclePubkey
   * @param[in] oracle_pubkey    setting value.
   */
  void SetOraclePubkey(  // line separate
    const std::string& oracle_pubkey) {  // NOLINT
    this->oracle_pubkey_ = oracle_pubkey;
  }
  /**
   * @brief Get data type of oraclePubkey
   * @return Data type of oraclePubkey
   */
  static std::string GetOraclePubkeyFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of oraclePubkey field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetOraclePubkeyString(  // line separate
      const SignClosingTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.oracle_pubkey_);
  }
  /**
   * @brief Set json object to oraclePubkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetOraclePubkeyString(  // line separate
      SignClosingTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.oracle_pubkey_, json_value);
  }

  /**
   * @brief Get of oracleRPoints.
   * @return oracleRPoints
   */
  JsonValueVector<std::string>& GetOracleRPoints() {  // NOLINT
    return oracle_r_points_;
  }
  /**
   * @brief Set to oracleRPoints.
   * @param[in] oracle_r_points    setting value.
   */
  void SetOracleRPoints(  // line separate
      const JsonValueVector<std::string>& oracle_r_points) {  // NOLINT
    this->oracle_r_points_ = oracle_r_points;
  }
  /**
   * @brief Get data type of oracleRPoints.
   * @return Data type of oracleRPoints.
   */
  static std::string GetOracleRPointsFieldType() {
    return "JsonValueVector<std::string>";  // NOLINT
  }
  /**
   * @brief Get json string of oracleRPoints field.
   * @param[in,out] obj     class object
   * @return JSON string.
   */
  static std::string GetOracleRPointsString(  // line separate
      const SignClosingTransactionRequest& obj) {  // NOLINT
    // Do not set to const, because substitution of member variables
    // may occur in pre / post processing inside Serialize
    return obj.oracle_r_points_.Serialize();
  }
  /**
   * @brief Set json object to oracleRPoints field.
   * @param[in,out] obj     class object
   * @param[in] json_value  JSON object
   */
  static void SetOracleRPointsString(  // line separate
      SignClosingTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    obj.oracle_r_points_.DeserializeUniValue(json_value);
  }

  /**
   * @brief Get of messages.
   * @return messages
   */
  JsonValueVector<std::string>& GetMessages() {  // NOLINT
    return messages_;
  }
  /**
   * @brief Set to messages.
   * @param[in] messages    setting value.
   */
  void SetMessages(  // line separate
      const JsonValueVector<std::string>& messages) {  // NOLINT
    this->messages_ = messages;
  }
  /**
   * @brief Get data type of messages.
   * @return Data type of messages.
   */
  static std::string GetMessagesFieldType() {
    return "JsonValueVector<std::string>";  // NOLINT
  }
  /**
   * @brief Get json string of messages field.
   * @param[in,out] obj     class object
   * @return JSON string.
   */
  static std::string GetMessagesString(  // line separate
      const SignClosingTransactionRequest& obj) {  // NOLINT
    // Do not set to const, because substitution of member variables
    // may occur in pre / post processing inside Serialize
    return obj.messages_.Serialize();
  }
  /**
   * @brief Set json object to messages field.
   * @param[in,out] obj     class object
   * @param[in] json_value  JSON object
   */
  static void SetMessagesString(  // line separate
      SignClosingTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    obj.messages_.DeserializeUniValue(json_value);
  }

  /**
   * @brief Get of delay
   * @return delay
   */
  uint64_t GetDelay() const {
    return delay_;
  }
  /**
   * @brief Set to delay
   * @param[in] delay    setting value.
   */
  void SetDelay(  // line separate
    const uint64_t& delay) {  // NOLINT
    this->delay_ = delay;
  }
  /**
   * @brief Get data type of delay
   * @return Data type of delay
   */
  static std::string GetDelayFieldType() {
    return "uint64_t";
  }
  /**
   * @brief Get json string of delay field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetDelayString(  // line separate
      const SignClosingTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.delay_);
  }
  /**
   * @brief Set json object to delay field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetDelayString(  // line separate
      SignClosingTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.delay_, json_value);
  }

  /**
   * @brief Get of oracleSig
   * @return oracleSig
   */
  std::string GetOracleSig() const {
    return oracle_sig_;
  }
  /**
   * @brief Set to oracleSig
   * @param[in] oracle_sig    setting value.
   */
  void SetOracleSig(  // line separate
    const std::string& oracle_sig) {  // NOLINT
    this->oracle_sig_ = oracle_sig;
  }
  /**
   * @brief Get data type of oracleSig
   * @return Data type of oracleSig
   */
  static std::string GetOracleSigFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of oracleSig field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetOracleSigString(  // line separate
      const SignClosingTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.oracle_sig_);
  }
  /**
   * @brief Set json object to oracleSig field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetOracleSigString(  // line separate
      SignClosingTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.oracle_sig_, json_value);
  }

  /**
   * @brief Get of cetTxid
   * @return cetTxid
   */
  std::string GetCetTxid() const {
    return cet_txid_;
  }
  /**
   * @brief Set to cetTxid
   * @param[in] cet_txid    setting value.
   */
  void SetCetTxid(  // line separate
    const std::string& cet_txid) {  // NOLINT
    this->cet_txid_ = cet_txid;
  }
  /**
   * @brief Get data type of cetTxid
   * @return Data type of cetTxid
   */
  static std::string GetCetTxidFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of cetTxid field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetCetTxidString(  // line separate
      const SignClosingTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.cet_txid_);
  }
  /**
   * @brief Set json object to cetTxid field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetCetTxidString(  // line separate
      SignClosingTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.cet_txid_, json_value);
  }

  /**
   * @brief Get of cetVout
   * @return cetVout
   */
  uint32_t GetCetVout() const {
    return cet_vout_;
  }
  /**
   * @brief Set to cetVout
   * @param[in] cet_vout    setting value.
   */
  void SetCetVout(  // line separate
    const uint32_t& cet_vout) {  // NOLINT
    this->cet_vout_ = cet_vout;
  }
  /**
   * @brief Get data type of cetVout
   * @return Data type of cetVout
   */
  static std::string GetCetVoutFieldType() {
    return "uint32_t";
  }
  /**
   * @brief Get json string of cetVout field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetCetVoutString(  // line separate
      const SignClosingTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.cet_vout_);
  }
  /**
   * @brief Set json object to cetVout field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetCetVoutString(  // line separate
      SignClosingTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.cet_vout_, json_value);
  }

  /**
   * @brief Get of cetScript
   * @return cetScript
   */
  std::string GetCetScript() const {
    return cet_script_;
  }
  /**
   * @brief Set to cetScript
   * @param[in] cet_script    setting value.
   */
  void SetCetScript(  // line separate
    const std::string& cet_script) {  // NOLINT
    this->cet_script_ = cet_script;
  }
  /**
   * @brief Get data type of cetScript
   * @return Data type of cetScript
   */
  static std::string GetCetScriptFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of cetScript field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetCetScriptString(  // line separate
      const SignClosingTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.cet_script_);
  }
  /**
   * @brief Set json object to cetScript field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetCetScriptString(  // line separate
      SignClosingTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.cet_script_, json_value);
  }

  /**
   * @brief Get of amount
   * @return amount
   */
  uint64_t GetAmount() const {
    return amount_;
  }
  /**
   * @brief Set to amount
   * @param[in] amount    setting value.
   */
  void SetAmount(  // line separate
    const uint64_t& amount) {  // NOLINT
    this->amount_ = amount;
  }
  /**
   * @brief Get data type of amount
   * @return Data type of amount
   */
  static std::string GetAmountFieldType() {
    return "uint64_t";
  }
  /**
   * @brief Get json string of amount field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetAmountString(  // line separate
      const SignClosingTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.amount_);
  }
  /**
   * @brief Set json object to amount field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetAmountString(  // line separate
      SignClosingTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.amount_, json_value);
  }

  /**
   * @brief Set ignore item.
   * @param[in] key   ignore target key name.
   */
  void SetIgnoreItem(const std::string& key) {
    ignore_items.insert(key);
  }

  /**
   * @brief Convert struct to class.
   * @param[in] data   struct data.
   */
  void ConvertFromStruct(
      const SignClosingTransactionRequestStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  SignClosingTransactionRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using SignClosingTransactionRequestMapTable =
    cfd::core::JsonTableMap<SignClosingTransactionRequest>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const SignClosingTransactionRequestMapTable& GetJsonMapper() const {  // NOLINT
    return json_mapper;
  }
  /**
   * @brief Get item lists of JSON mapping.
   * Fetch a list of target variable names in the order of definition.
   * @return Item lists of JSON mapping.
   * @see cfd::core::JsonClassBase::GetJsonItemList()
   */
  virtual const std::vector<std::string>& GetJsonItemList() const {
    return item_list;
  }
  /**
   * @brief Get ignore item lists of JSON mnapping.
   * Ignore the target variable at Serialize.
   * @return Item list of JSON mapping.
   * @see cfd::core::JsonClassBase::GetIgnoreItem()
   */
  virtual const std::set<std::string>& GetIgnoreItem() const {
    return ignore_items;
  }

 private:
 /**
  * @brief JsonFunctionMap table
  */
  static SignClosingTransactionRequestMapTable json_mapper;
  /**
   * @brief field name list.
   */
  static std::vector<std::string> item_list;
  /**
   * @brief ignore item list.
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(closingTxHex) value
   */
  std::string closing_tx_hex_ = "";
  /**
   * @brief JsonAPI(localFundPrivkey) value
   */
  std::string local_fund_privkey_ = "";
  /**
   * @brief JsonAPI(localSweepPubkey) value
   */
  std::string local_sweep_pubkey_ = "";
  /**
   * @brief JsonAPI(remoteSweepPubkey) value
   */
  std::string remote_sweep_pubkey_ = "";
  /**
   * @brief JsonAPI(oraclePubkey) value
   */
  std::string oracle_pubkey_ = "";
  /**
   * @brief JsonAPI(oracleRPoints) value
   */
  JsonValueVector<std::string> oracle_r_points_;  // NOLINT
  /**
   * @brief JsonAPI(messages) value
   */
  JsonValueVector<std::string> messages_;  // NOLINT
  /**
   * @brief JsonAPI(delay) value
   */
  uint64_t delay_ = 0;
  /**
   * @brief JsonAPI(oracleSig) value
   */
  std::string oracle_sig_ = "";
  /**
   * @brief JsonAPI(cetTxid) value
   */
  std::string cet_txid_ = "";
  /**
   * @brief JsonAPI(cetVout) value
   */
  uint32_t cet_vout_ = 0;
  /**
   * @brief JsonAPI(cetScript) value
   */
  std::string cet_script_ = "";
  /**
   * @brief JsonAPI(amount) value
   */
  uint64_t amount_ = 0;
};

// ------------------------------------------------------------------------
// SignClosingTransactionResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (SignClosingTransactionResponse) class
 */
class SignClosingTransactionResponse
  : public cfd::core::JsonClassBase<SignClosingTransactionResponse> {
 public:
  SignClosingTransactionResponse() {
    CollectFieldName();
  }
  virtual ~SignClosingTransactionResponse() {
    // do nothing
  }
  /**
   * @brief collect field name.
   */
  static void CollectFieldName();

  /**
   * @brief Get of hex
   * @return hex
   */
  std::string GetHex() const {
    return hex_;
  }
  /**
   * @brief Set to hex
   * @param[in] hex    setting value.
   */
  void SetHex(  // line separate
    const std::string& hex) {  // NOLINT
    this->hex_ = hex;
  }
  /**
   * @brief Get data type of hex
   * @return Data type of hex
   */
  static std::string GetHexFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of hex field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetHexString(  // line separate
      const SignClosingTransactionResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.hex_);
  }
  /**
   * @brief Set json object to hex field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetHexString(  // line separate
      SignClosingTransactionResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.hex_, json_value);
  }

  /**
   * @brief Set ignore item.
   * @param[in] key   ignore target key name.
   */
  void SetIgnoreItem(const std::string& key) {
    ignore_items.insert(key);
  }

  /**
   * @brief Convert struct to class.
   * @param[in] data   struct data.
   */
  void ConvertFromStruct(
      const SignClosingTransactionResponseStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  SignClosingTransactionResponseStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using SignClosingTransactionResponseMapTable =
    cfd::core::JsonTableMap<SignClosingTransactionResponse>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const SignClosingTransactionResponseMapTable& GetJsonMapper() const {  // NOLINT
    return json_mapper;
  }
  /**
   * @brief Get item lists of JSON mapping.
   * Fetch a list of target variable names in the order of definition.
   * @return Item lists of JSON mapping.
   * @see cfd::core::JsonClassBase::GetJsonItemList()
   */
  virtual const std::vector<std::string>& GetJsonItemList() const {
    return item_list;
  }
  /**
   * @brief Get ignore item lists of JSON mnapping.
   * Ignore the target variable at Serialize.
   * @return Item list of JSON mapping.
   * @see cfd::core::JsonClassBase::GetIgnoreItem()
   */
  virtual const std::set<std::string>& GetIgnoreItem() const {
    return ignore_items;
  }

 private:
 /**
  * @brief JsonFunctionMap table
  */
  static SignClosingTransactionResponseMapTable json_mapper;
  /**
   * @brief field name list.
   */
  static std::vector<std::string> item_list;
  /**
   * @brief ignore item list.
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(hex) value
   */
  std::string hex_ = "";
};

// ------------------------------------------------------------------------
// SignFundTransactionRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (SignFundTransactionRequest) class
 */
class SignFundTransactionRequest
  : public cfd::core::JsonClassBase<SignFundTransactionRequest> {
 public:
  SignFundTransactionRequest() {
    CollectFieldName();
  }
  virtual ~SignFundTransactionRequest() {
    // do nothing
  }
  /**
   * @brief collect field name.
   */
  static void CollectFieldName();

  /**
   * @brief Get of fundTxHex
   * @return fundTxHex
   */
  std::string GetFundTxHex() const {
    return fund_tx_hex_;
  }
  /**
   * @brief Set to fundTxHex
   * @param[in] fund_tx_hex    setting value.
   */
  void SetFundTxHex(  // line separate
    const std::string& fund_tx_hex) {  // NOLINT
    this->fund_tx_hex_ = fund_tx_hex;
  }
  /**
   * @brief Get data type of fundTxHex
   * @return Data type of fundTxHex
   */
  static std::string GetFundTxHexFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of fundTxHex field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetFundTxHexString(  // line separate
      const SignFundTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fund_tx_hex_);
  }
  /**
   * @brief Set json object to fundTxHex field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFundTxHexString(  // line separate
      SignFundTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.fund_tx_hex_, json_value);
  }

  /**
   * @brief Get of privkey
   * @return privkey
   */
  std::string GetPrivkey() const {
    return privkey_;
  }
  /**
   * @brief Set to privkey
   * @param[in] privkey    setting value.
   */
  void SetPrivkey(  // line separate
    const std::string& privkey) {  // NOLINT
    this->privkey_ = privkey;
  }
  /**
   * @brief Get data type of privkey
   * @return Data type of privkey
   */
  static std::string GetPrivkeyFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of privkey field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetPrivkeyString(  // line separate
      const SignFundTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.privkey_);
  }
  /**
   * @brief Set json object to privkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetPrivkeyString(  // line separate
      SignFundTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.privkey_, json_value);
  }

  /**
   * @brief Get of prevTxid
   * @return prevTxid
   */
  std::string GetPrevTxid() const {
    return prev_txid_;
  }
  /**
   * @brief Set to prevTxid
   * @param[in] prev_txid    setting value.
   */
  void SetPrevTxid(  // line separate
    const std::string& prev_txid) {  // NOLINT
    this->prev_txid_ = prev_txid;
  }
  /**
   * @brief Get data type of prevTxid
   * @return Data type of prevTxid
   */
  static std::string GetPrevTxidFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of prevTxid field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetPrevTxidString(  // line separate
      const SignFundTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.prev_txid_);
  }
  /**
   * @brief Set json object to prevTxid field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetPrevTxidString(  // line separate
      SignFundTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.prev_txid_, json_value);
  }

  /**
   * @brief Get of prevTxVout
   * @return prevTxVout
   */
  uint32_t GetPrevTxVout() const {
    return prev_tx_vout_;
  }
  /**
   * @brief Set to prevTxVout
   * @param[in] prev_tx_vout    setting value.
   */
  void SetPrevTxVout(  // line separate
    const uint32_t& prev_tx_vout) {  // NOLINT
    this->prev_tx_vout_ = prev_tx_vout;
  }
  /**
   * @brief Get data type of prevTxVout
   * @return Data type of prevTxVout
   */
  static std::string GetPrevTxVoutFieldType() {
    return "uint32_t";
  }
  /**
   * @brief Get json string of prevTxVout field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetPrevTxVoutString(  // line separate
      const SignFundTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.prev_tx_vout_);
  }
  /**
   * @brief Set json object to prevTxVout field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetPrevTxVoutString(  // line separate
      SignFundTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.prev_tx_vout_, json_value);
  }

  /**
   * @brief Get of amount
   * @return amount
   */
  uint64_t GetAmount() const {
    return amount_;
  }
  /**
   * @brief Set to amount
   * @param[in] amount    setting value.
   */
  void SetAmount(  // line separate
    const uint64_t& amount) {  // NOLINT
    this->amount_ = amount;
  }
  /**
   * @brief Get data type of amount
   * @return Data type of amount
   */
  static std::string GetAmountFieldType() {
    return "uint64_t";
  }
  /**
   * @brief Get json string of amount field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetAmountString(  // line separate
      const SignFundTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.amount_);
  }
  /**
   * @brief Set json object to amount field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetAmountString(  // line separate
      SignFundTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.amount_, json_value);
  }

  /**
   * @brief Set ignore item.
   * @param[in] key   ignore target key name.
   */
  void SetIgnoreItem(const std::string& key) {
    ignore_items.insert(key);
  }

  /**
   * @brief Convert struct to class.
   * @param[in] data   struct data.
   */
  void ConvertFromStruct(
      const SignFundTransactionRequestStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  SignFundTransactionRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using SignFundTransactionRequestMapTable =
    cfd::core::JsonTableMap<SignFundTransactionRequest>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const SignFundTransactionRequestMapTable& GetJsonMapper() const {  // NOLINT
    return json_mapper;
  }
  /**
   * @brief Get item lists of JSON mapping.
   * Fetch a list of target variable names in the order of definition.
   * @return Item lists of JSON mapping.
   * @see cfd::core::JsonClassBase::GetJsonItemList()
   */
  virtual const std::vector<std::string>& GetJsonItemList() const {
    return item_list;
  }
  /**
   * @brief Get ignore item lists of JSON mnapping.
   * Ignore the target variable at Serialize.
   * @return Item list of JSON mapping.
   * @see cfd::core::JsonClassBase::GetIgnoreItem()
   */
  virtual const std::set<std::string>& GetIgnoreItem() const {
    return ignore_items;
  }

 private:
 /**
  * @brief JsonFunctionMap table
  */
  static SignFundTransactionRequestMapTable json_mapper;
  /**
   * @brief field name list.
   */
  static std::vector<std::string> item_list;
  /**
   * @brief ignore item list.
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(fundTxHex) value
   */
  std::string fund_tx_hex_ = "";
  /**
   * @brief JsonAPI(privkey) value
   */
  std::string privkey_ = "";
  /**
   * @brief JsonAPI(prevTxid) value
   */
  std::string prev_txid_ = "";
  /**
   * @brief JsonAPI(prevTxVout) value
   */
  uint32_t prev_tx_vout_ = 0;
  /**
   * @brief JsonAPI(amount) value
   */
  uint64_t amount_ = 0;
};

// ------------------------------------------------------------------------
// SignFundTransactionResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (SignFundTransactionResponse) class
 */
class SignFundTransactionResponse
  : public cfd::core::JsonClassBase<SignFundTransactionResponse> {
 public:
  SignFundTransactionResponse() {
    CollectFieldName();
  }
  virtual ~SignFundTransactionResponse() {
    // do nothing
  }
  /**
   * @brief collect field name.
   */
  static void CollectFieldName();

  /**
   * @brief Get of hex
   * @return hex
   */
  std::string GetHex() const {
    return hex_;
  }
  /**
   * @brief Set to hex
   * @param[in] hex    setting value.
   */
  void SetHex(  // line separate
    const std::string& hex) {  // NOLINT
    this->hex_ = hex;
  }
  /**
   * @brief Get data type of hex
   * @return Data type of hex
   */
  static std::string GetHexFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of hex field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetHexString(  // line separate
      const SignFundTransactionResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.hex_);
  }
  /**
   * @brief Set json object to hex field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetHexString(  // line separate
      SignFundTransactionResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.hex_, json_value);
  }

  /**
   * @brief Set ignore item.
   * @param[in] key   ignore target key name.
   */
  void SetIgnoreItem(const std::string& key) {
    ignore_items.insert(key);
  }

  /**
   * @brief Convert struct to class.
   * @param[in] data   struct data.
   */
  void ConvertFromStruct(
      const SignFundTransactionResponseStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  SignFundTransactionResponseStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using SignFundTransactionResponseMapTable =
    cfd::core::JsonTableMap<SignFundTransactionResponse>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const SignFundTransactionResponseMapTable& GetJsonMapper() const {  // NOLINT
    return json_mapper;
  }
  /**
   * @brief Get item lists of JSON mapping.
   * Fetch a list of target variable names in the order of definition.
   * @return Item lists of JSON mapping.
   * @see cfd::core::JsonClassBase::GetJsonItemList()
   */
  virtual const std::vector<std::string>& GetJsonItemList() const {
    return item_list;
  }
  /**
   * @brief Get ignore item lists of JSON mnapping.
   * Ignore the target variable at Serialize.
   * @return Item list of JSON mapping.
   * @see cfd::core::JsonClassBase::GetIgnoreItem()
   */
  virtual const std::set<std::string>& GetIgnoreItem() const {
    return ignore_items;
  }

 private:
 /**
  * @brief JsonFunctionMap table
  */
  static SignFundTransactionResponseMapTable json_mapper;
  /**
   * @brief field name list.
   */
  static std::vector<std::string> item_list;
  /**
   * @brief ignore item list.
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(hex) value
   */
  std::string hex_ = "";
};

// ------------------------------------------------------------------------
// VerifyCetSignatureRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (VerifyCetSignatureRequest) class
 */
class VerifyCetSignatureRequest
  : public cfd::core::JsonClassBase<VerifyCetSignatureRequest> {
 public:
  VerifyCetSignatureRequest() {
    CollectFieldName();
  }
  virtual ~VerifyCetSignatureRequest() {
    // do nothing
  }
  /**
   * @brief collect field name.
   */
  static void CollectFieldName();

  /**
   * @brief Get of cetHex
   * @return cetHex
   */
  std::string GetCetHex() const {
    return cet_hex_;
  }
  /**
   * @brief Set to cetHex
   * @param[in] cet_hex    setting value.
   */
  void SetCetHex(  // line separate
    const std::string& cet_hex) {  // NOLINT
    this->cet_hex_ = cet_hex;
  }
  /**
   * @brief Get data type of cetHex
   * @return Data type of cetHex
   */
  static std::string GetCetHexFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of cetHex field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetCetHexString(  // line separate
      const VerifyCetSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.cet_hex_);
  }
  /**
   * @brief Set json object to cetHex field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetCetHexString(  // line separate
      VerifyCetSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.cet_hex_, json_value);
  }

  /**
   * @brief Get of signature
   * @return signature
   */
  std::string GetSignature() const {
    return signature_;
  }
  /**
   * @brief Set to signature
   * @param[in] signature    setting value.
   */
  void SetSignature(  // line separate
    const std::string& signature) {  // NOLINT
    this->signature_ = signature;
  }
  /**
   * @brief Get data type of signature
   * @return Data type of signature
   */
  static std::string GetSignatureFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of signature field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetSignatureString(  // line separate
      const VerifyCetSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.signature_);
  }
  /**
   * @brief Set json object to signature field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetSignatureString(  // line separate
      VerifyCetSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.signature_, json_value);
  }

  /**
   * @brief Get of localFundPubkey
   * @return localFundPubkey
   */
  std::string GetLocalFundPubkey() const {
    return local_fund_pubkey_;
  }
  /**
   * @brief Set to localFundPubkey
   * @param[in] local_fund_pubkey    setting value.
   */
  void SetLocalFundPubkey(  // line separate
    const std::string& local_fund_pubkey) {  // NOLINT
    this->local_fund_pubkey_ = local_fund_pubkey;
  }
  /**
   * @brief Get data type of localFundPubkey
   * @return Data type of localFundPubkey
   */
  static std::string GetLocalFundPubkeyFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of localFundPubkey field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetLocalFundPubkeyString(  // line separate
      const VerifyCetSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.local_fund_pubkey_);
  }
  /**
   * @brief Set json object to localFundPubkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetLocalFundPubkeyString(  // line separate
      VerifyCetSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.local_fund_pubkey_, json_value);
  }

  /**
   * @brief Get of remoteFundPubkey
   * @return remoteFundPubkey
   */
  std::string GetRemoteFundPubkey() const {
    return remote_fund_pubkey_;
  }
  /**
   * @brief Set to remoteFundPubkey
   * @param[in] remote_fund_pubkey    setting value.
   */
  void SetRemoteFundPubkey(  // line separate
    const std::string& remote_fund_pubkey) {  // NOLINT
    this->remote_fund_pubkey_ = remote_fund_pubkey;
  }
  /**
   * @brief Get data type of remoteFundPubkey
   * @return Data type of remoteFundPubkey
   */
  static std::string GetRemoteFundPubkeyFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of remoteFundPubkey field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetRemoteFundPubkeyString(  // line separate
      const VerifyCetSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.remote_fund_pubkey_);
  }
  /**
   * @brief Set json object to remoteFundPubkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetRemoteFundPubkeyString(  // line separate
      VerifyCetSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.remote_fund_pubkey_, json_value);
  }

  /**
   * @brief Get of fundTxId
   * @return fundTxId
   */
  std::string GetFundTxId() const {
    return fund_tx_id_;
  }
  /**
   * @brief Set to fundTxId
   * @param[in] fund_tx_id    setting value.
   */
  void SetFundTxId(  // line separate
    const std::string& fund_tx_id) {  // NOLINT
    this->fund_tx_id_ = fund_tx_id;
  }
  /**
   * @brief Get data type of fundTxId
   * @return Data type of fundTxId
   */
  static std::string GetFundTxIdFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of fundTxId field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetFundTxIdString(  // line separate
      const VerifyCetSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fund_tx_id_);
  }
  /**
   * @brief Set json object to fundTxId field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFundTxIdString(  // line separate
      VerifyCetSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.fund_tx_id_, json_value);
  }

  /**
   * @brief Get of fundVout
   * @return fundVout
   */
  uint32_t GetFundVout() const {
    return fund_vout_;
  }
  /**
   * @brief Set to fundVout
   * @param[in] fund_vout    setting value.
   */
  void SetFundVout(  // line separate
    const uint32_t& fund_vout) {  // NOLINT
    this->fund_vout_ = fund_vout;
  }
  /**
   * @brief Get data type of fundVout
   * @return Data type of fundVout
   */
  static std::string GetFundVoutFieldType() {
    return "uint32_t";
  }
  /**
   * @brief Get json string of fundVout field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetFundVoutString(  // line separate
      const VerifyCetSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fund_vout_);
  }
  /**
   * @brief Set json object to fundVout field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFundVoutString(  // line separate
      VerifyCetSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.fund_vout_, json_value);
  }

  /**
   * @brief Get of inputAmount
   * @return inputAmount
   */
  uint64_t GetInputAmount() const {
    return input_amount_;
  }
  /**
   * @brief Set to inputAmount
   * @param[in] input_amount    setting value.
   */
  void SetInputAmount(  // line separate
    const uint64_t& input_amount) {  // NOLINT
    this->input_amount_ = input_amount;
  }
  /**
   * @brief Get data type of inputAmount
   * @return Data type of inputAmount
   */
  static std::string GetInputAmountFieldType() {
    return "uint64_t";
  }
  /**
   * @brief Get json string of inputAmount field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetInputAmountString(  // line separate
      const VerifyCetSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.input_amount_);
  }
  /**
   * @brief Set json object to inputAmount field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetInputAmountString(  // line separate
      VerifyCetSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.input_amount_, json_value);
  }

  /**
   * @brief Get of verifyRemote
   * @return verifyRemote
   */
  bool GetVerifyRemote() const {
    return verify_remote_;
  }
  /**
   * @brief Set to verifyRemote
   * @param[in] verify_remote    setting value.
   */
  void SetVerifyRemote(  // line separate
    const bool& verify_remote) {  // NOLINT
    this->verify_remote_ = verify_remote;
  }
  /**
   * @brief Get data type of verifyRemote
   * @return Data type of verifyRemote
   */
  static std::string GetVerifyRemoteFieldType() {
    return "bool";
  }
  /**
   * @brief Get json string of verifyRemote field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetVerifyRemoteString(  // line separate
      const VerifyCetSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.verify_remote_);
  }
  /**
   * @brief Set json object to verifyRemote field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetVerifyRemoteString(  // line separate
      VerifyCetSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.verify_remote_, json_value);
  }

  /**
   * @brief Set ignore item.
   * @param[in] key   ignore target key name.
   */
  void SetIgnoreItem(const std::string& key) {
    ignore_items.insert(key);
  }

  /**
   * @brief Convert struct to class.
   * @param[in] data   struct data.
   */
  void ConvertFromStruct(
      const VerifyCetSignatureRequestStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  VerifyCetSignatureRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using VerifyCetSignatureRequestMapTable =
    cfd::core::JsonTableMap<VerifyCetSignatureRequest>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const VerifyCetSignatureRequestMapTable& GetJsonMapper() const {  // NOLINT
    return json_mapper;
  }
  /**
   * @brief Get item lists of JSON mapping.
   * Fetch a list of target variable names in the order of definition.
   * @return Item lists of JSON mapping.
   * @see cfd::core::JsonClassBase::GetJsonItemList()
   */
  virtual const std::vector<std::string>& GetJsonItemList() const {
    return item_list;
  }
  /**
   * @brief Get ignore item lists of JSON mnapping.
   * Ignore the target variable at Serialize.
   * @return Item list of JSON mapping.
   * @see cfd::core::JsonClassBase::GetIgnoreItem()
   */
  virtual const std::set<std::string>& GetIgnoreItem() const {
    return ignore_items;
  }

 private:
 /**
  * @brief JsonFunctionMap table
  */
  static VerifyCetSignatureRequestMapTable json_mapper;
  /**
   * @brief field name list.
   */
  static std::vector<std::string> item_list;
  /**
   * @brief ignore item list.
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(cetHex) value
   */
  std::string cet_hex_ = "";
  /**
   * @brief JsonAPI(signature) value
   */
  std::string signature_ = "";
  /**
   * @brief JsonAPI(localFundPubkey) value
   */
  std::string local_fund_pubkey_ = "";
  /**
   * @brief JsonAPI(remoteFundPubkey) value
   */
  std::string remote_fund_pubkey_ = "";
  /**
   * @brief JsonAPI(fundTxId) value
   */
  std::string fund_tx_id_ = "";
  /**
   * @brief JsonAPI(fundVout) value
   */
  uint32_t fund_vout_ = 0;
  /**
   * @brief JsonAPI(inputAmount) value
   */
  uint64_t input_amount_ = 0;
  /**
   * @brief JsonAPI(verifyRemote) value
   */
  bool verify_remote_ = true;
};

// ------------------------------------------------------------------------
// VerifyCetSignatureResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (VerifyCetSignatureResponse) class
 */
class VerifyCetSignatureResponse
  : public cfd::core::JsonClassBase<VerifyCetSignatureResponse> {
 public:
  VerifyCetSignatureResponse() {
    CollectFieldName();
  }
  virtual ~VerifyCetSignatureResponse() {
    // do nothing
  }
  /**
   * @brief collect field name.
   */
  static void CollectFieldName();

  /**
   * @brief Get of valid
   * @return valid
   */
  bool GetValid() const {
    return valid_;
  }
  /**
   * @brief Set to valid
   * @param[in] valid    setting value.
   */
  void SetValid(  // line separate
    const bool& valid) {  // NOLINT
    this->valid_ = valid;
  }
  /**
   * @brief Get data type of valid
   * @return Data type of valid
   */
  static std::string GetValidFieldType() {
    return "bool";
  }
  /**
   * @brief Get json string of valid field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetValidString(  // line separate
      const VerifyCetSignatureResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.valid_);
  }
  /**
   * @brief Set json object to valid field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetValidString(  // line separate
      VerifyCetSignatureResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.valid_, json_value);
  }

  /**
   * @brief Set ignore item.
   * @param[in] key   ignore target key name.
   */
  void SetIgnoreItem(const std::string& key) {
    ignore_items.insert(key);
  }

  /**
   * @brief Convert struct to class.
   * @param[in] data   struct data.
   */
  void ConvertFromStruct(
      const VerifyCetSignatureResponseStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  VerifyCetSignatureResponseStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using VerifyCetSignatureResponseMapTable =
    cfd::core::JsonTableMap<VerifyCetSignatureResponse>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const VerifyCetSignatureResponseMapTable& GetJsonMapper() const {  // NOLINT
    return json_mapper;
  }
  /**
   * @brief Get item lists of JSON mapping.
   * Fetch a list of target variable names in the order of definition.
   * @return Item lists of JSON mapping.
   * @see cfd::core::JsonClassBase::GetJsonItemList()
   */
  virtual const std::vector<std::string>& GetJsonItemList() const {
    return item_list;
  }
  /**
   * @brief Get ignore item lists of JSON mnapping.
   * Ignore the target variable at Serialize.
   * @return Item list of JSON mapping.
   * @see cfd::core::JsonClassBase::GetIgnoreItem()
   */
  virtual const std::set<std::string>& GetIgnoreItem() const {
    return ignore_items;
  }

 private:
 /**
  * @brief JsonFunctionMap table
  */
  static VerifyCetSignatureResponseMapTable json_mapper;
  /**
   * @brief field name list.
   */
  static std::vector<std::string> item_list;
  /**
   * @brief ignore item list.
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(valid) value
   */
  bool valid_ = false;
};

// ------------------------------------------------------------------------
// VerifyFundTxSignatureRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (VerifyFundTxSignatureRequest) class
 */
class VerifyFundTxSignatureRequest
  : public cfd::core::JsonClassBase<VerifyFundTxSignatureRequest> {
 public:
  VerifyFundTxSignatureRequest() {
    CollectFieldName();
  }
  virtual ~VerifyFundTxSignatureRequest() {
    // do nothing
  }
  /**
   * @brief collect field name.
   */
  static void CollectFieldName();

  /**
   * @brief Get of fundTxHex
   * @return fundTxHex
   */
  std::string GetFundTxHex() const {
    return fund_tx_hex_;
  }
  /**
   * @brief Set to fundTxHex
   * @param[in] fund_tx_hex    setting value.
   */
  void SetFundTxHex(  // line separate
    const std::string& fund_tx_hex) {  // NOLINT
    this->fund_tx_hex_ = fund_tx_hex;
  }
  /**
   * @brief Get data type of fundTxHex
   * @return Data type of fundTxHex
   */
  static std::string GetFundTxHexFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of fundTxHex field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetFundTxHexString(  // line separate
      const VerifyFundTxSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fund_tx_hex_);
  }
  /**
   * @brief Set json object to fundTxHex field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFundTxHexString(  // line separate
      VerifyFundTxSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.fund_tx_hex_, json_value);
  }

  /**
   * @brief Get of signature
   * @return signature
   */
  std::string GetSignature() const {
    return signature_;
  }
  /**
   * @brief Set to signature
   * @param[in] signature    setting value.
   */
  void SetSignature(  // line separate
    const std::string& signature) {  // NOLINT
    this->signature_ = signature;
  }
  /**
   * @brief Get data type of signature
   * @return Data type of signature
   */
  static std::string GetSignatureFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of signature field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetSignatureString(  // line separate
      const VerifyFundTxSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.signature_);
  }
  /**
   * @brief Set json object to signature field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetSignatureString(  // line separate
      VerifyFundTxSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.signature_, json_value);
  }

  /**
   * @brief Get of pubkey
   * @return pubkey
   */
  std::string GetPubkey() const {
    return pubkey_;
  }
  /**
   * @brief Set to pubkey
   * @param[in] pubkey    setting value.
   */
  void SetPubkey(  // line separate
    const std::string& pubkey) {  // NOLINT
    this->pubkey_ = pubkey;
  }
  /**
   * @brief Get data type of pubkey
   * @return Data type of pubkey
   */
  static std::string GetPubkeyFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of pubkey field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetPubkeyString(  // line separate
      const VerifyFundTxSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.pubkey_);
  }
  /**
   * @brief Set json object to pubkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetPubkeyString(  // line separate
      VerifyFundTxSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.pubkey_, json_value);
  }

  /**
   * @brief Get of prevTxId
   * @return prevTxId
   */
  std::string GetPrevTxId() const {
    return prev_tx_id_;
  }
  /**
   * @brief Set to prevTxId
   * @param[in] prev_tx_id    setting value.
   */
  void SetPrevTxId(  // line separate
    const std::string& prev_tx_id) {  // NOLINT
    this->prev_tx_id_ = prev_tx_id;
  }
  /**
   * @brief Get data type of prevTxId
   * @return Data type of prevTxId
   */
  static std::string GetPrevTxIdFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of prevTxId field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetPrevTxIdString(  // line separate
      const VerifyFundTxSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.prev_tx_id_);
  }
  /**
   * @brief Set json object to prevTxId field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetPrevTxIdString(  // line separate
      VerifyFundTxSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.prev_tx_id_, json_value);
  }

  /**
   * @brief Get of prevTxVout
   * @return prevTxVout
   */
  uint32_t GetPrevTxVout() const {
    return prev_tx_vout_;
  }
  /**
   * @brief Set to prevTxVout
   * @param[in] prev_tx_vout    setting value.
   */
  void SetPrevTxVout(  // line separate
    const uint32_t& prev_tx_vout) {  // NOLINT
    this->prev_tx_vout_ = prev_tx_vout;
  }
  /**
   * @brief Get data type of prevTxVout
   * @return Data type of prevTxVout
   */
  static std::string GetPrevTxVoutFieldType() {
    return "uint32_t";
  }
  /**
   * @brief Get json string of prevTxVout field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetPrevTxVoutString(  // line separate
      const VerifyFundTxSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.prev_tx_vout_);
  }
  /**
   * @brief Set json object to prevTxVout field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetPrevTxVoutString(  // line separate
      VerifyFundTxSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.prev_tx_vout_, json_value);
  }

  /**
   * @brief Get of inputAmount
   * @return inputAmount
   */
  uint64_t GetInputAmount() const {
    return input_amount_;
  }
  /**
   * @brief Set to inputAmount
   * @param[in] input_amount    setting value.
   */
  void SetInputAmount(  // line separate
    const uint64_t& input_amount) {  // NOLINT
    this->input_amount_ = input_amount;
  }
  /**
   * @brief Get data type of inputAmount
   * @return Data type of inputAmount
   */
  static std::string GetInputAmountFieldType() {
    return "uint64_t";
  }
  /**
   * @brief Get json string of inputAmount field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetInputAmountString(  // line separate
      const VerifyFundTxSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.input_amount_);
  }
  /**
   * @brief Set json object to inputAmount field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetInputAmountString(  // line separate
      VerifyFundTxSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.input_amount_, json_value);
  }

  /**
   * @brief Set ignore item.
   * @param[in] key   ignore target key name.
   */
  void SetIgnoreItem(const std::string& key) {
    ignore_items.insert(key);
  }

  /**
   * @brief Convert struct to class.
   * @param[in] data   struct data.
   */
  void ConvertFromStruct(
      const VerifyFundTxSignatureRequestStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  VerifyFundTxSignatureRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using VerifyFundTxSignatureRequestMapTable =
    cfd::core::JsonTableMap<VerifyFundTxSignatureRequest>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const VerifyFundTxSignatureRequestMapTable& GetJsonMapper() const {  // NOLINT
    return json_mapper;
  }
  /**
   * @brief Get item lists of JSON mapping.
   * Fetch a list of target variable names in the order of definition.
   * @return Item lists of JSON mapping.
   * @see cfd::core::JsonClassBase::GetJsonItemList()
   */
  virtual const std::vector<std::string>& GetJsonItemList() const {
    return item_list;
  }
  /**
   * @brief Get ignore item lists of JSON mnapping.
   * Ignore the target variable at Serialize.
   * @return Item list of JSON mapping.
   * @see cfd::core::JsonClassBase::GetIgnoreItem()
   */
  virtual const std::set<std::string>& GetIgnoreItem() const {
    return ignore_items;
  }

 private:
 /**
  * @brief JsonFunctionMap table
  */
  static VerifyFundTxSignatureRequestMapTable json_mapper;
  /**
   * @brief field name list.
   */
  static std::vector<std::string> item_list;
  /**
   * @brief ignore item list.
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(fundTxHex) value
   */
  std::string fund_tx_hex_ = "";
  /**
   * @brief JsonAPI(signature) value
   */
  std::string signature_ = "";
  /**
   * @brief JsonAPI(pubkey) value
   */
  std::string pubkey_ = "";
  /**
   * @brief JsonAPI(prevTxId) value
   */
  std::string prev_tx_id_ = "";
  /**
   * @brief JsonAPI(prevTxVout) value
   */
  uint32_t prev_tx_vout_ = 0;
  /**
   * @brief JsonAPI(inputAmount) value
   */
  uint64_t input_amount_ = 0;
};

// ------------------------------------------------------------------------
// VerifyFundTxSignatureResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (VerifyFundTxSignatureResponse) class
 */
class VerifyFundTxSignatureResponse
  : public cfd::core::JsonClassBase<VerifyFundTxSignatureResponse> {
 public:
  VerifyFundTxSignatureResponse() {
    CollectFieldName();
  }
  virtual ~VerifyFundTxSignatureResponse() {
    // do nothing
  }
  /**
   * @brief collect field name.
   */
  static void CollectFieldName();

  /**
   * @brief Get of valid
   * @return valid
   */
  bool GetValid() const {
    return valid_;
  }
  /**
   * @brief Set to valid
   * @param[in] valid    setting value.
   */
  void SetValid(  // line separate
    const bool& valid) {  // NOLINT
    this->valid_ = valid;
  }
  /**
   * @brief Get data type of valid
   * @return Data type of valid
   */
  static std::string GetValidFieldType() {
    return "bool";
  }
  /**
   * @brief Get json string of valid field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetValidString(  // line separate
      const VerifyFundTxSignatureResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.valid_);
  }
  /**
   * @brief Set json object to valid field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetValidString(  // line separate
      VerifyFundTxSignatureResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.valid_, json_value);
  }

  /**
   * @brief Set ignore item.
   * @param[in] key   ignore target key name.
   */
  void SetIgnoreItem(const std::string& key) {
    ignore_items.insert(key);
  }

  /**
   * @brief Convert struct to class.
   * @param[in] data   struct data.
   */
  void ConvertFromStruct(
      const VerifyFundTxSignatureResponseStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  VerifyFundTxSignatureResponseStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using VerifyFundTxSignatureResponseMapTable =
    cfd::core::JsonTableMap<VerifyFundTxSignatureResponse>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const VerifyFundTxSignatureResponseMapTable& GetJsonMapper() const {  // NOLINT
    return json_mapper;
  }
  /**
   * @brief Get item lists of JSON mapping.
   * Fetch a list of target variable names in the order of definition.
   * @return Item lists of JSON mapping.
   * @see cfd::core::JsonClassBase::GetJsonItemList()
   */
  virtual const std::vector<std::string>& GetJsonItemList() const {
    return item_list;
  }
  /**
   * @brief Get ignore item lists of JSON mnapping.
   * Ignore the target variable at Serialize.
   * @return Item list of JSON mapping.
   * @see cfd::core::JsonClassBase::GetIgnoreItem()
   */
  virtual const std::set<std::string>& GetIgnoreItem() const {
    return ignore_items;
  }

 private:
 /**
  * @brief JsonFunctionMap table
  */
  static VerifyFundTxSignatureResponseMapTable json_mapper;
  /**
   * @brief field name list.
   */
  static std::vector<std::string> item_list;
  /**
   * @brief ignore item list.
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(valid) value
   */
  bool valid_ = false;
};

// ------------------------------------------------------------------------
// VerifyMutualClosingTxSignatureRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (VerifyMutualClosingTxSignatureRequest) class
 */
class VerifyMutualClosingTxSignatureRequest
  : public cfd::core::JsonClassBase<VerifyMutualClosingTxSignatureRequest> {
 public:
  VerifyMutualClosingTxSignatureRequest() {
    CollectFieldName();
  }
  virtual ~VerifyMutualClosingTxSignatureRequest() {
    // do nothing
  }
  /**
   * @brief collect field name.
   */
  static void CollectFieldName();

  /**
   * @brief Get of cetHex
   * @return cetHex
   */
  std::string GetCetHex() const {
    return cet_hex_;
  }
  /**
   * @brief Set to cetHex
   * @param[in] cet_hex    setting value.
   */
  void SetCetHex(  // line separate
    const std::string& cet_hex) {  // NOLINT
    this->cet_hex_ = cet_hex;
  }
  /**
   * @brief Get data type of cetHex
   * @return Data type of cetHex
   */
  static std::string GetCetHexFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of cetHex field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetCetHexString(  // line separate
      const VerifyMutualClosingTxSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.cet_hex_);
  }
  /**
   * @brief Set json object to cetHex field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetCetHexString(  // line separate
      VerifyMutualClosingTxSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.cet_hex_, json_value);
  }

  /**
   * @brief Get of signature
   * @return signature
   */
  std::string GetSignature() const {
    return signature_;
  }
  /**
   * @brief Set to signature
   * @param[in] signature    setting value.
   */
  void SetSignature(  // line separate
    const std::string& signature) {  // NOLINT
    this->signature_ = signature;
  }
  /**
   * @brief Get data type of signature
   * @return Data type of signature
   */
  static std::string GetSignatureFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of signature field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetSignatureString(  // line separate
      const VerifyMutualClosingTxSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.signature_);
  }
  /**
   * @brief Set json object to signature field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetSignatureString(  // line separate
      VerifyMutualClosingTxSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.signature_, json_value);
  }

  /**
   * @brief Get of localFundPubkey
   * @return localFundPubkey
   */
  std::string GetLocalFundPubkey() const {
    return local_fund_pubkey_;
  }
  /**
   * @brief Set to localFundPubkey
   * @param[in] local_fund_pubkey    setting value.
   */
  void SetLocalFundPubkey(  // line separate
    const std::string& local_fund_pubkey) {  // NOLINT
    this->local_fund_pubkey_ = local_fund_pubkey;
  }
  /**
   * @brief Get data type of localFundPubkey
   * @return Data type of localFundPubkey
   */
  static std::string GetLocalFundPubkeyFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of localFundPubkey field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetLocalFundPubkeyString(  // line separate
      const VerifyMutualClosingTxSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.local_fund_pubkey_);
  }
  /**
   * @brief Set json object to localFundPubkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetLocalFundPubkeyString(  // line separate
      VerifyMutualClosingTxSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.local_fund_pubkey_, json_value);
  }

  /**
   * @brief Get of remoteFundPubkey
   * @return remoteFundPubkey
   */
  std::string GetRemoteFundPubkey() const {
    return remote_fund_pubkey_;
  }
  /**
   * @brief Set to remoteFundPubkey
   * @param[in] remote_fund_pubkey    setting value.
   */
  void SetRemoteFundPubkey(  // line separate
    const std::string& remote_fund_pubkey) {  // NOLINT
    this->remote_fund_pubkey_ = remote_fund_pubkey;
  }
  /**
   * @brief Get data type of remoteFundPubkey
   * @return Data type of remoteFundPubkey
   */
  static std::string GetRemoteFundPubkeyFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of remoteFundPubkey field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetRemoteFundPubkeyString(  // line separate
      const VerifyMutualClosingTxSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.remote_fund_pubkey_);
  }
  /**
   * @brief Set json object to remoteFundPubkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetRemoteFundPubkeyString(  // line separate
      VerifyMutualClosingTxSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.remote_fund_pubkey_, json_value);
  }

  /**
   * @brief Get of fundTxId
   * @return fundTxId
   */
  std::string GetFundTxId() const {
    return fund_tx_id_;
  }
  /**
   * @brief Set to fundTxId
   * @param[in] fund_tx_id    setting value.
   */
  void SetFundTxId(  // line separate
    const std::string& fund_tx_id) {  // NOLINT
    this->fund_tx_id_ = fund_tx_id;
  }
  /**
   * @brief Get data type of fundTxId
   * @return Data type of fundTxId
   */
  static std::string GetFundTxIdFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of fundTxId field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetFundTxIdString(  // line separate
      const VerifyMutualClosingTxSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fund_tx_id_);
  }
  /**
   * @brief Set json object to fundTxId field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFundTxIdString(  // line separate
      VerifyMutualClosingTxSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.fund_tx_id_, json_value);
  }

  /**
   * @brief Get of fundVout
   * @return fundVout
   */
  uint32_t GetFundVout() const {
    return fund_vout_;
  }
  /**
   * @brief Set to fundVout
   * @param[in] fund_vout    setting value.
   */
  void SetFundVout(  // line separate
    const uint32_t& fund_vout) {  // NOLINT
    this->fund_vout_ = fund_vout;
  }
  /**
   * @brief Get data type of fundVout
   * @return Data type of fundVout
   */
  static std::string GetFundVoutFieldType() {
    return "uint32_t";
  }
  /**
   * @brief Get json string of fundVout field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetFundVoutString(  // line separate
      const VerifyMutualClosingTxSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fund_vout_);
  }
  /**
   * @brief Set json object to fundVout field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFundVoutString(  // line separate
      VerifyMutualClosingTxSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.fund_vout_, json_value);
  }

  /**
   * @brief Get of inputAmount
   * @return inputAmount
   */
  uint64_t GetInputAmount() const {
    return input_amount_;
  }
  /**
   * @brief Set to inputAmount
   * @param[in] input_amount    setting value.
   */
  void SetInputAmount(  // line separate
    const uint64_t& input_amount) {  // NOLINT
    this->input_amount_ = input_amount;
  }
  /**
   * @brief Get data type of inputAmount
   * @return Data type of inputAmount
   */
  static std::string GetInputAmountFieldType() {
    return "uint64_t";
  }
  /**
   * @brief Get json string of inputAmount field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetInputAmountString(  // line separate
      const VerifyMutualClosingTxSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.input_amount_);
  }
  /**
   * @brief Set json object to inputAmount field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetInputAmountString(  // line separate
      VerifyMutualClosingTxSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.input_amount_, json_value);
  }

  /**
   * @brief Get of verifyRemote
   * @return verifyRemote
   */
  bool GetVerifyRemote() const {
    return verify_remote_;
  }
  /**
   * @brief Set to verifyRemote
   * @param[in] verify_remote    setting value.
   */
  void SetVerifyRemote(  // line separate
    const bool& verify_remote) {  // NOLINT
    this->verify_remote_ = verify_remote;
  }
  /**
   * @brief Get data type of verifyRemote
   * @return Data type of verifyRemote
   */
  static std::string GetVerifyRemoteFieldType() {
    return "bool";
  }
  /**
   * @brief Get json string of verifyRemote field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetVerifyRemoteString(  // line separate
      const VerifyMutualClosingTxSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.verify_remote_);
  }
  /**
   * @brief Set json object to verifyRemote field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetVerifyRemoteString(  // line separate
      VerifyMutualClosingTxSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.verify_remote_, json_value);
  }

  /**
   * @brief Set ignore item.
   * @param[in] key   ignore target key name.
   */
  void SetIgnoreItem(const std::string& key) {
    ignore_items.insert(key);
  }

  /**
   * @brief Convert struct to class.
   * @param[in] data   struct data.
   */
  void ConvertFromStruct(
      const VerifyMutualClosingTxSignatureRequestStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  VerifyMutualClosingTxSignatureRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using VerifyMutualClosingTxSignatureRequestMapTable =
    cfd::core::JsonTableMap<VerifyMutualClosingTxSignatureRequest>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const VerifyMutualClosingTxSignatureRequestMapTable& GetJsonMapper() const {  // NOLINT
    return json_mapper;
  }
  /**
   * @brief Get item lists of JSON mapping.
   * Fetch a list of target variable names in the order of definition.
   * @return Item lists of JSON mapping.
   * @see cfd::core::JsonClassBase::GetJsonItemList()
   */
  virtual const std::vector<std::string>& GetJsonItemList() const {
    return item_list;
  }
  /**
   * @brief Get ignore item lists of JSON mnapping.
   * Ignore the target variable at Serialize.
   * @return Item list of JSON mapping.
   * @see cfd::core::JsonClassBase::GetIgnoreItem()
   */
  virtual const std::set<std::string>& GetIgnoreItem() const {
    return ignore_items;
  }

 private:
 /**
  * @brief JsonFunctionMap table
  */
  static VerifyMutualClosingTxSignatureRequestMapTable json_mapper;
  /**
   * @brief field name list.
   */
  static std::vector<std::string> item_list;
  /**
   * @brief ignore item list.
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(cetHex) value
   */
  std::string cet_hex_ = "";
  /**
   * @brief JsonAPI(signature) value
   */
  std::string signature_ = "";
  /**
   * @brief JsonAPI(localFundPubkey) value
   */
  std::string local_fund_pubkey_ = "";
  /**
   * @brief JsonAPI(remoteFundPubkey) value
   */
  std::string remote_fund_pubkey_ = "";
  /**
   * @brief JsonAPI(fundTxId) value
   */
  std::string fund_tx_id_ = "";
  /**
   * @brief JsonAPI(fundVout) value
   */
  uint32_t fund_vout_ = 0;
  /**
   * @brief JsonAPI(inputAmount) value
   */
  uint64_t input_amount_ = 0;
  /**
   * @brief JsonAPI(verifyRemote) value
   */
  bool verify_remote_ = true;
};

// ------------------------------------------------------------------------
// VerifyMutualClosingTxSignatureResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (VerifyMutualClosingTxSignatureResponse) class
 */
class VerifyMutualClosingTxSignatureResponse
  : public cfd::core::JsonClassBase<VerifyMutualClosingTxSignatureResponse> {
 public:
  VerifyMutualClosingTxSignatureResponse() {
    CollectFieldName();
  }
  virtual ~VerifyMutualClosingTxSignatureResponse() {
    // do nothing
  }
  /**
   * @brief collect field name.
   */
  static void CollectFieldName();

  /**
   * @brief Get of valid
   * @return valid
   */
  bool GetValid() const {
    return valid_;
  }
  /**
   * @brief Set to valid
   * @param[in] valid    setting value.
   */
  void SetValid(  // line separate
    const bool& valid) {  // NOLINT
    this->valid_ = valid;
  }
  /**
   * @brief Get data type of valid
   * @return Data type of valid
   */
  static std::string GetValidFieldType() {
    return "bool";
  }
  /**
   * @brief Get json string of valid field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetValidString(  // line separate
      const VerifyMutualClosingTxSignatureResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.valid_);
  }
  /**
   * @brief Set json object to valid field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetValidString(  // line separate
      VerifyMutualClosingTxSignatureResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.valid_, json_value);
  }

  /**
   * @brief Set ignore item.
   * @param[in] key   ignore target key name.
   */
  void SetIgnoreItem(const std::string& key) {
    ignore_items.insert(key);
  }

  /**
   * @brief Convert struct to class.
   * @param[in] data   struct data.
   */
  void ConvertFromStruct(
      const VerifyMutualClosingTxSignatureResponseStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  VerifyMutualClosingTxSignatureResponseStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using VerifyMutualClosingTxSignatureResponseMapTable =
    cfd::core::JsonTableMap<VerifyMutualClosingTxSignatureResponse>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const VerifyMutualClosingTxSignatureResponseMapTable& GetJsonMapper() const {  // NOLINT
    return json_mapper;
  }
  /**
   * @brief Get item lists of JSON mapping.
   * Fetch a list of target variable names in the order of definition.
   * @return Item lists of JSON mapping.
   * @see cfd::core::JsonClassBase::GetJsonItemList()
   */
  virtual const std::vector<std::string>& GetJsonItemList() const {
    return item_list;
  }
  /**
   * @brief Get ignore item lists of JSON mnapping.
   * Ignore the target variable at Serialize.
   * @return Item list of JSON mapping.
   * @see cfd::core::JsonClassBase::GetIgnoreItem()
   */
  virtual const std::set<std::string>& GetIgnoreItem() const {
    return ignore_items;
  }

 private:
 /**
  * @brief JsonFunctionMap table
  */
  static VerifyMutualClosingTxSignatureResponseMapTable json_mapper;
  /**
   * @brief field name list.
   */
  static std::vector<std::string> item_list;
  /**
   * @brief ignore item list.
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(valid) value
   */
  bool valid_ = false;
};

// ------------------------------------------------------------------------
// VerifyRefundTxSignatureRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (VerifyRefundTxSignatureRequest) class
 */
class VerifyRefundTxSignatureRequest
  : public cfd::core::JsonClassBase<VerifyRefundTxSignatureRequest> {
 public:
  VerifyRefundTxSignatureRequest() {
    CollectFieldName();
  }
  virtual ~VerifyRefundTxSignatureRequest() {
    // do nothing
  }
  /**
   * @brief collect field name.
   */
  static void CollectFieldName();

  /**
   * @brief Get of refundTxHex
   * @return refundTxHex
   */
  std::string GetRefundTxHex() const {
    return refund_tx_hex_;
  }
  /**
   * @brief Set to refundTxHex
   * @param[in] refund_tx_hex    setting value.
   */
  void SetRefundTxHex(  // line separate
    const std::string& refund_tx_hex) {  // NOLINT
    this->refund_tx_hex_ = refund_tx_hex;
  }
  /**
   * @brief Get data type of refundTxHex
   * @return Data type of refundTxHex
   */
  static std::string GetRefundTxHexFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of refundTxHex field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetRefundTxHexString(  // line separate
      const VerifyRefundTxSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.refund_tx_hex_);
  }
  /**
   * @brief Set json object to refundTxHex field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetRefundTxHexString(  // line separate
      VerifyRefundTxSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.refund_tx_hex_, json_value);
  }

  /**
   * @brief Get of signature
   * @return signature
   */
  std::string GetSignature() const {
    return signature_;
  }
  /**
   * @brief Set to signature
   * @param[in] signature    setting value.
   */
  void SetSignature(  // line separate
    const std::string& signature) {  // NOLINT
    this->signature_ = signature;
  }
  /**
   * @brief Get data type of signature
   * @return Data type of signature
   */
  static std::string GetSignatureFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of signature field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetSignatureString(  // line separate
      const VerifyRefundTxSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.signature_);
  }
  /**
   * @brief Set json object to signature field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetSignatureString(  // line separate
      VerifyRefundTxSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.signature_, json_value);
  }

  /**
   * @brief Get of localFundPubkey
   * @return localFundPubkey
   */
  std::string GetLocalFundPubkey() const {
    return local_fund_pubkey_;
  }
  /**
   * @brief Set to localFundPubkey
   * @param[in] local_fund_pubkey    setting value.
   */
  void SetLocalFundPubkey(  // line separate
    const std::string& local_fund_pubkey) {  // NOLINT
    this->local_fund_pubkey_ = local_fund_pubkey;
  }
  /**
   * @brief Get data type of localFundPubkey
   * @return Data type of localFundPubkey
   */
  static std::string GetLocalFundPubkeyFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of localFundPubkey field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetLocalFundPubkeyString(  // line separate
      const VerifyRefundTxSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.local_fund_pubkey_);
  }
  /**
   * @brief Set json object to localFundPubkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetLocalFundPubkeyString(  // line separate
      VerifyRefundTxSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.local_fund_pubkey_, json_value);
  }

  /**
   * @brief Get of remoteFundPubkey
   * @return remoteFundPubkey
   */
  std::string GetRemoteFundPubkey() const {
    return remote_fund_pubkey_;
  }
  /**
   * @brief Set to remoteFundPubkey
   * @param[in] remote_fund_pubkey    setting value.
   */
  void SetRemoteFundPubkey(  // line separate
    const std::string& remote_fund_pubkey) {  // NOLINT
    this->remote_fund_pubkey_ = remote_fund_pubkey;
  }
  /**
   * @brief Get data type of remoteFundPubkey
   * @return Data type of remoteFundPubkey
   */
  static std::string GetRemoteFundPubkeyFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of remoteFundPubkey field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetRemoteFundPubkeyString(  // line separate
      const VerifyRefundTxSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.remote_fund_pubkey_);
  }
  /**
   * @brief Set json object to remoteFundPubkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetRemoteFundPubkeyString(  // line separate
      VerifyRefundTxSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.remote_fund_pubkey_, json_value);
  }

  /**
   * @brief Get of fundTxId
   * @return fundTxId
   */
  std::string GetFundTxId() const {
    return fund_tx_id_;
  }
  /**
   * @brief Set to fundTxId
   * @param[in] fund_tx_id    setting value.
   */
  void SetFundTxId(  // line separate
    const std::string& fund_tx_id) {  // NOLINT
    this->fund_tx_id_ = fund_tx_id;
  }
  /**
   * @brief Get data type of fundTxId
   * @return Data type of fundTxId
   */
  static std::string GetFundTxIdFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of fundTxId field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetFundTxIdString(  // line separate
      const VerifyRefundTxSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fund_tx_id_);
  }
  /**
   * @brief Set json object to fundTxId field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFundTxIdString(  // line separate
      VerifyRefundTxSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.fund_tx_id_, json_value);
  }

  /**
   * @brief Get of fundVout
   * @return fundVout
   */
  uint32_t GetFundVout() const {
    return fund_vout_;
  }
  /**
   * @brief Set to fundVout
   * @param[in] fund_vout    setting value.
   */
  void SetFundVout(  // line separate
    const uint32_t& fund_vout) {  // NOLINT
    this->fund_vout_ = fund_vout;
  }
  /**
   * @brief Get data type of fundVout
   * @return Data type of fundVout
   */
  static std::string GetFundVoutFieldType() {
    return "uint32_t";
  }
  /**
   * @brief Get json string of fundVout field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetFundVoutString(  // line separate
      const VerifyRefundTxSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fund_vout_);
  }
  /**
   * @brief Set json object to fundVout field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFundVoutString(  // line separate
      VerifyRefundTxSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.fund_vout_, json_value);
  }

  /**
   * @brief Get of inputAmount
   * @return inputAmount
   */
  uint64_t GetInputAmount() const {
    return input_amount_;
  }
  /**
   * @brief Set to inputAmount
   * @param[in] input_amount    setting value.
   */
  void SetInputAmount(  // line separate
    const uint64_t& input_amount) {  // NOLINT
    this->input_amount_ = input_amount;
  }
  /**
   * @brief Get data type of inputAmount
   * @return Data type of inputAmount
   */
  static std::string GetInputAmountFieldType() {
    return "uint64_t";
  }
  /**
   * @brief Get json string of inputAmount field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetInputAmountString(  // line separate
      const VerifyRefundTxSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.input_amount_);
  }
  /**
   * @brief Set json object to inputAmount field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetInputAmountString(  // line separate
      VerifyRefundTxSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.input_amount_, json_value);
  }

  /**
   * @brief Get of verifyRemote
   * @return verifyRemote
   */
  bool GetVerifyRemote() const {
    return verify_remote_;
  }
  /**
   * @brief Set to verifyRemote
   * @param[in] verify_remote    setting value.
   */
  void SetVerifyRemote(  // line separate
    const bool& verify_remote) {  // NOLINT
    this->verify_remote_ = verify_remote;
  }
  /**
   * @brief Get data type of verifyRemote
   * @return Data type of verifyRemote
   */
  static std::string GetVerifyRemoteFieldType() {
    return "bool";
  }
  /**
   * @brief Get json string of verifyRemote field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetVerifyRemoteString(  // line separate
      const VerifyRefundTxSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.verify_remote_);
  }
  /**
   * @brief Set json object to verifyRemote field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetVerifyRemoteString(  // line separate
      VerifyRefundTxSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.verify_remote_, json_value);
  }

  /**
   * @brief Set ignore item.
   * @param[in] key   ignore target key name.
   */
  void SetIgnoreItem(const std::string& key) {
    ignore_items.insert(key);
  }

  /**
   * @brief Convert struct to class.
   * @param[in] data   struct data.
   */
  void ConvertFromStruct(
      const VerifyRefundTxSignatureRequestStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  VerifyRefundTxSignatureRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using VerifyRefundTxSignatureRequestMapTable =
    cfd::core::JsonTableMap<VerifyRefundTxSignatureRequest>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const VerifyRefundTxSignatureRequestMapTable& GetJsonMapper() const {  // NOLINT
    return json_mapper;
  }
  /**
   * @brief Get item lists of JSON mapping.
   * Fetch a list of target variable names in the order of definition.
   * @return Item lists of JSON mapping.
   * @see cfd::core::JsonClassBase::GetJsonItemList()
   */
  virtual const std::vector<std::string>& GetJsonItemList() const {
    return item_list;
  }
  /**
   * @brief Get ignore item lists of JSON mnapping.
   * Ignore the target variable at Serialize.
   * @return Item list of JSON mapping.
   * @see cfd::core::JsonClassBase::GetIgnoreItem()
   */
  virtual const std::set<std::string>& GetIgnoreItem() const {
    return ignore_items;
  }

 private:
 /**
  * @brief JsonFunctionMap table
  */
  static VerifyRefundTxSignatureRequestMapTable json_mapper;
  /**
   * @brief field name list.
   */
  static std::vector<std::string> item_list;
  /**
   * @brief ignore item list.
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(refundTxHex) value
   */
  std::string refund_tx_hex_ = "";
  /**
   * @brief JsonAPI(signature) value
   */
  std::string signature_ = "";
  /**
   * @brief JsonAPI(localFundPubkey) value
   */
  std::string local_fund_pubkey_ = "";
  /**
   * @brief JsonAPI(remoteFundPubkey) value
   */
  std::string remote_fund_pubkey_ = "";
  /**
   * @brief JsonAPI(fundTxId) value
   */
  std::string fund_tx_id_ = "";
  /**
   * @brief JsonAPI(fundVout) value
   */
  uint32_t fund_vout_ = 0;
  /**
   * @brief JsonAPI(inputAmount) value
   */
  uint64_t input_amount_ = 0;
  /**
   * @brief JsonAPI(verifyRemote) value
   */
  bool verify_remote_ = true;
};

// ------------------------------------------------------------------------
// VerifyRefundTxSignatureResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (VerifyRefundTxSignatureResponse) class
 */
class VerifyRefundTxSignatureResponse
  : public cfd::core::JsonClassBase<VerifyRefundTxSignatureResponse> {
 public:
  VerifyRefundTxSignatureResponse() {
    CollectFieldName();
  }
  virtual ~VerifyRefundTxSignatureResponse() {
    // do nothing
  }
  /**
   * @brief collect field name.
   */
  static void CollectFieldName();

  /**
   * @brief Get of valid
   * @return valid
   */
  bool GetValid() const {
    return valid_;
  }
  /**
   * @brief Set to valid
   * @param[in] valid    setting value.
   */
  void SetValid(  // line separate
    const bool& valid) {  // NOLINT
    this->valid_ = valid;
  }
  /**
   * @brief Get data type of valid
   * @return Data type of valid
   */
  static std::string GetValidFieldType() {
    return "bool";
  }
  /**
   * @brief Get json string of valid field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetValidString(  // line separate
      const VerifyRefundTxSignatureResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.valid_);
  }
  /**
   * @brief Set json object to valid field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetValidString(  // line separate
      VerifyRefundTxSignatureResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.valid_, json_value);
  }

  /**
   * @brief Set ignore item.
   * @param[in] key   ignore target key name.
   */
  void SetIgnoreItem(const std::string& key) {
    ignore_items.insert(key);
  }

  /**
   * @brief Convert struct to class.
   * @param[in] data   struct data.
   */
  void ConvertFromStruct(
      const VerifyRefundTxSignatureResponseStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  VerifyRefundTxSignatureResponseStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using VerifyRefundTxSignatureResponseMapTable =
    cfd::core::JsonTableMap<VerifyRefundTxSignatureResponse>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const VerifyRefundTxSignatureResponseMapTable& GetJsonMapper() const {  // NOLINT
    return json_mapper;
  }
  /**
   * @brief Get item lists of JSON mapping.
   * Fetch a list of target variable names in the order of definition.
   * @return Item lists of JSON mapping.
   * @see cfd::core::JsonClassBase::GetJsonItemList()
   */
  virtual const std::vector<std::string>& GetJsonItemList() const {
    return item_list;
  }
  /**
   * @brief Get ignore item lists of JSON mnapping.
   * Ignore the target variable at Serialize.
   * @return Item list of JSON mapping.
   * @see cfd::core::JsonClassBase::GetIgnoreItem()
   */
  virtual const std::set<std::string>& GetIgnoreItem() const {
    return ignore_items;
  }

 private:
 /**
  * @brief JsonFunctionMap table
  */
  static VerifyRefundTxSignatureResponseMapTable json_mapper;
  /**
   * @brief field name list.
   */
  static std::vector<std::string> item_list;
  /**
   * @brief ignore item list.
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(valid) value
   */
  bool valid_ = false;
};

// @formatter:on
// clang-format on

}  // namespace json
}  // namespace api
}  // namespace js
}  // namespace dlc
}  // namespace cfd

#endif  // CFD_DLC_JS_SRC_AUTOGEN_CFD_DLC_JS_API_JSON_AUTOGEN_H_
