// Copyright 2020 CryptoGarage
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
// AdaptorPair
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (AdaptorPair) class
 */
class AdaptorPair
  : public cfd::core::JsonClassBase<AdaptorPair> {
 public:
  AdaptorPair() {
    CollectFieldName();
  }
  virtual ~AdaptorPair() {
    // do nothing
  }
  /**
   * @brief collect field name.
   */
  static void CollectFieldName();

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
      const AdaptorPair& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.signature_);
  }
  /**
   * @brief Set json object to signature field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetSignatureString(  // line separate
      AdaptorPair& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.signature_, json_value);
  }

  /**
   * @brief Get of proof
   * @return proof
   */
  std::string GetProof() const {
    return proof_;
  }
  /**
   * @brief Set to proof
   * @param[in] proof    setting value.
   */
  void SetProof(  // line separate
    const std::string& proof) {  // NOLINT
    this->proof_ = proof;
  }
  /**
   * @brief Get data type of proof
   * @return Data type of proof
   */
  static std::string GetProofFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of proof field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetProofString(  // line separate
      const AdaptorPair& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.proof_);
  }
  /**
   * @brief Set json object to proof field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetProofString(  // line separate
      AdaptorPair& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.proof_, json_value);
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
      const AdaptorPairStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  AdaptorPairStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using AdaptorPairMapTable =
    cfd::core::JsonTableMap<AdaptorPair>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const AdaptorPairMapTable& GetJsonMapper() const {  // NOLINT
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
   * @brief Get ignore item lists of JSON mapping.
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
  static AdaptorPairMapTable json_mapper;
  /**
   * @brief field name list.
   */
  static std::vector<std::string> item_list;
  /**
   * @brief ignore item list.
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(signature) value
   */
  std::string signature_ = "";
  /**
   * @brief JsonAPI(proof) value
   */
  std::string proof_ = "";
};

// ------------------------------------------------------------------------
// Messages
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (Messages) class
 */
class Messages
  : public cfd::core::JsonClassBase<Messages> {
 public:
  Messages() {
    CollectFieldName();
  }
  virtual ~Messages() {
    // do nothing
  }
  /**
   * @brief collect field name.
   */
  static void CollectFieldName();

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
      const Messages& obj) {  // NOLINT
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
      Messages& obj,  // NOLINT
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
      const MessagesStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  MessagesStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using MessagesMapTable =
    cfd::core::JsonTableMap<Messages>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const MessagesMapTable& GetJsonMapper() const {  // NOLINT
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
   * @brief Get ignore item lists of JSON mapping.
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
  static MessagesMapTable json_mapper;
  /**
   * @brief field name list.
   */
  static std::vector<std::string> item_list;
  /**
   * @brief ignore item list.
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(messages) value
   */
  JsonValueVector<std::string> messages_;  // NOLINT
};

// ------------------------------------------------------------------------
// AddSignatureToFundTransactionRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (AddSignatureToFundTransactionRequest) class
 */
class AddSignatureToFundTransactionRequest
  : public cfd::core::JsonClassBase<AddSignatureToFundTransactionRequest> {
 public:
  AddSignatureToFundTransactionRequest() {
    CollectFieldName();
  }
  virtual ~AddSignatureToFundTransactionRequest() {
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
      const AddSignatureToFundTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fund_tx_hex_);
  }
  /**
   * @brief Set json object to fundTxHex field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFundTxHexString(  // line separate
      AddSignatureToFundTransactionRequest& obj,  // NOLINT
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
      const AddSignatureToFundTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.signature_);
  }
  /**
   * @brief Set json object to signature field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetSignatureString(  // line separate
      AddSignatureToFundTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.signature_, json_value);
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
      const AddSignatureToFundTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.prev_tx_id_);
  }
  /**
   * @brief Set json object to prevTxId field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetPrevTxIdString(  // line separate
      AddSignatureToFundTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.prev_tx_id_, json_value);
  }

  /**
   * @brief Get of prevVout
   * @return prevVout
   */
  uint32_t GetPrevVout() const {
    return prev_vout_;
  }
  /**
   * @brief Set to prevVout
   * @param[in] prev_vout    setting value.
   */
  void SetPrevVout(  // line separate
    const uint32_t& prev_vout) {  // NOLINT
    this->prev_vout_ = prev_vout;
  }
  /**
   * @brief Get data type of prevVout
   * @return Data type of prevVout
   */
  static std::string GetPrevVoutFieldType() {
    return "uint32_t";
  }
  /**
   * @brief Get json string of prevVout field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetPrevVoutString(  // line separate
      const AddSignatureToFundTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.prev_vout_);
  }
  /**
   * @brief Set json object to prevVout field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetPrevVoutString(  // line separate
      AddSignatureToFundTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.prev_vout_, json_value);
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
      const AddSignatureToFundTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.pubkey_);
  }
  /**
   * @brief Set json object to pubkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetPubkeyString(  // line separate
      AddSignatureToFundTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.pubkey_, json_value);
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
      const AddSignatureToFundTransactionRequestStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  AddSignatureToFundTransactionRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using AddSignatureToFundTransactionRequestMapTable =
    cfd::core::JsonTableMap<AddSignatureToFundTransactionRequest>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const AddSignatureToFundTransactionRequestMapTable& GetJsonMapper() const {  // NOLINT
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
   * @brief Get ignore item lists of JSON mapping.
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
  static AddSignatureToFundTransactionRequestMapTable json_mapper;
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
   * @brief JsonAPI(prevTxId) value
   */
  std::string prev_tx_id_ = "";
  /**
   * @brief JsonAPI(prevVout) value
   */
  uint32_t prev_vout_ = 0;
  /**
   * @brief JsonAPI(pubkey) value
   */
  std::string pubkey_ = "";
};

// ------------------------------------------------------------------------
// AddSignatureToFundTransactionResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (AddSignatureToFundTransactionResponse) class
 */
class AddSignatureToFundTransactionResponse
  : public cfd::core::JsonClassBase<AddSignatureToFundTransactionResponse> {
 public:
  AddSignatureToFundTransactionResponse() {
    CollectFieldName();
  }
  virtual ~AddSignatureToFundTransactionResponse() {
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
      const AddSignatureToFundTransactionResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.hex_);
  }
  /**
   * @brief Set json object to hex field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetHexString(  // line separate
      AddSignatureToFundTransactionResponse& obj,  // NOLINT
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
      const AddSignatureToFundTransactionResponseStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  AddSignatureToFundTransactionResponseStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using AddSignatureToFundTransactionResponseMapTable =
    cfd::core::JsonTableMap<AddSignatureToFundTransactionResponse>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const AddSignatureToFundTransactionResponseMapTable& GetJsonMapper() const {  // NOLINT
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
   * @brief Get ignore item lists of JSON mapping.
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
  static AddSignatureToFundTransactionResponseMapTable json_mapper;
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
      const AddSignaturesToRefundTxRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fund_vout_);
  }
  /**
   * @brief Set json object to fundVout field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFundVoutString(  // line separate
      AddSignaturesToRefundTxRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.fund_vout_, json_value);
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
   * @brief Get ignore item lists of JSON mapping.
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
   * @brief JsonAPI(fundVout) value
   */
  uint32_t fund_vout_ = 0;
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
   * @brief Get ignore item lists of JSON mapping.
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
// CreateCetRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (CreateCetRequest) class
 */
class CreateCetRequest
  : public cfd::core::JsonClassBase<CreateCetRequest> {
 public:
  CreateCetRequest() {
    CollectFieldName();
  }
  virtual ~CreateCetRequest() {
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
      const CreateCetRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.local_fund_pubkey_);
  }
  /**
   * @brief Set json object to localFundPubkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetLocalFundPubkeyString(  // line separate
      CreateCetRequest& obj,  // NOLINT
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
      const CreateCetRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.remote_fund_pubkey_);
  }
  /**
   * @brief Set json object to remoteFundPubkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetRemoteFundPubkeyString(  // line separate
      CreateCetRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.remote_fund_pubkey_, json_value);
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
      const CreateCetRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.local_final_address_);
  }
  /**
   * @brief Set json object to localFinalAddress field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetLocalFinalAddressString(  // line separate
      CreateCetRequest& obj,  // NOLINT
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
      const CreateCetRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.remote_final_address_);
  }
  /**
   * @brief Set json object to remoteFinalAddress field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetRemoteFinalAddressString(  // line separate
      CreateCetRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.remote_final_address_, json_value);
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
      const CreateCetRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.local_payout_);
  }
  /**
   * @brief Set json object to localPayout field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetLocalPayoutString(  // line separate
      CreateCetRequest& obj,  // NOLINT
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
      const CreateCetRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.remote_payout_);
  }
  /**
   * @brief Set json object to remotePayout field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetRemotePayoutString(  // line separate
      CreateCetRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.remote_payout_, json_value);
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
      const CreateCetRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fund_tx_id_);
  }
  /**
   * @brief Set json object to fundTxId field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFundTxIdString(  // line separate
      CreateCetRequest& obj,  // NOLINT
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
      const CreateCetRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fund_vout_);
  }
  /**
   * @brief Set json object to fundVout field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFundVoutString(  // line separate
      CreateCetRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.fund_vout_, json_value);
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
      const CreateCetRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.lock_time_);
  }
  /**
   * @brief Set json object to lockTime field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetLockTimeString(  // line separate
      CreateCetRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.lock_time_, json_value);
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
      const CreateCetRequestStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  CreateCetRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using CreateCetRequestMapTable =
    cfd::core::JsonTableMap<CreateCetRequest>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const CreateCetRequestMapTable& GetJsonMapper() const {  // NOLINT
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
   * @brief Get ignore item lists of JSON mapping.
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
  static CreateCetRequestMapTable json_mapper;
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
   * @brief JsonAPI(remoteFundPubkey) value
   */
  std::string remote_fund_pubkey_ = "";
  /**
   * @brief JsonAPI(localFinalAddress) value
   */
  std::string local_final_address_ = "";
  /**
   * @brief JsonAPI(remoteFinalAddress) value
   */
  std::string remote_final_address_ = "";
  /**
   * @brief JsonAPI(localPayout) value
   */
  uint64_t local_payout_ = 0;
  /**
   * @brief JsonAPI(remotePayout) value
   */
  uint64_t remote_payout_ = 0;
  /**
   * @brief JsonAPI(fundTxId) value
   */
  std::string fund_tx_id_ = "";
  /**
   * @brief JsonAPI(fundVout) value
   */
  uint32_t fund_vout_ = 0;
  /**
   * @brief JsonAPI(lockTime) value
   */
  uint64_t lock_time_ = 0;
};

// ------------------------------------------------------------------------
// CreateCetResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (CreateCetResponse) class
 */
class CreateCetResponse
  : public cfd::core::JsonClassBase<CreateCetResponse> {
 public:
  CreateCetResponse() {
    CollectFieldName();
  }
  virtual ~CreateCetResponse() {
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
      const CreateCetResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.hex_);
  }
  /**
   * @brief Set json object to hex field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetHexString(  // line separate
      CreateCetResponse& obj,  // NOLINT
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
      const CreateCetResponseStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  CreateCetResponseStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using CreateCetResponseMapTable =
    cfd::core::JsonTableMap<CreateCetResponse>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const CreateCetResponseMapTable& GetJsonMapper() const {  // NOLINT
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
   * @brief Get ignore item lists of JSON mapping.
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
  static CreateCetResponseMapTable json_mapper;
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
// CreateCetAdaptorSignatureRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (CreateCetAdaptorSignatureRequest) class
 */
class CreateCetAdaptorSignatureRequest
  : public cfd::core::JsonClassBase<CreateCetAdaptorSignatureRequest> {
 public:
  CreateCetAdaptorSignatureRequest() {
    CollectFieldName();
  }
  virtual ~CreateCetAdaptorSignatureRequest() {
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
      const CreateCetAdaptorSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.cet_hex_);
  }
  /**
   * @brief Set json object to cetHex field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetCetHexString(  // line separate
      CreateCetAdaptorSignatureRequest& obj,  // NOLINT
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
      const CreateCetAdaptorSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.privkey_);
  }
  /**
   * @brief Set json object to privkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetPrivkeyString(  // line separate
      CreateCetAdaptorSignatureRequest& obj,  // NOLINT
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
      const CreateCetAdaptorSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fund_tx_id_);
  }
  /**
   * @brief Set json object to fundTxId field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFundTxIdString(  // line separate
      CreateCetAdaptorSignatureRequest& obj,  // NOLINT
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
      const CreateCetAdaptorSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fund_vout_);
  }
  /**
   * @brief Set json object to fundVout field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFundVoutString(  // line separate
      CreateCetAdaptorSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.fund_vout_, json_value);
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
      const CreateCetAdaptorSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.local_fund_pubkey_);
  }
  /**
   * @brief Set json object to localFundPubkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetLocalFundPubkeyString(  // line separate
      CreateCetAdaptorSignatureRequest& obj,  // NOLINT
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
      const CreateCetAdaptorSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.remote_fund_pubkey_);
  }
  /**
   * @brief Set json object to remoteFundPubkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetRemoteFundPubkeyString(  // line separate
      CreateCetAdaptorSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.remote_fund_pubkey_, json_value);
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
      const CreateCetAdaptorSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.oracle_pubkey_);
  }
  /**
   * @brief Set json object to oraclePubkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetOraclePubkeyString(  // line separate
      CreateCetAdaptorSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.oracle_pubkey_, json_value);
  }

  /**
   * @brief Get of oracleRValues.
   * @return oracleRValues
   */
  JsonValueVector<std::string>& GetOracleRValues() {  // NOLINT
    return oracle_r_values_;
  }
  /**
   * @brief Set to oracleRValues.
   * @param[in] oracle_r_values    setting value.
   */
  void SetOracleRValues(  // line separate
      const JsonValueVector<std::string>& oracle_r_values) {  // NOLINT
    this->oracle_r_values_ = oracle_r_values;
  }
  /**
   * @brief Get data type of oracleRValues.
   * @return Data type of oracleRValues.
   */
  static std::string GetOracleRValuesFieldType() {
    return "JsonValueVector<std::string>";  // NOLINT
  }
  /**
   * @brief Get json string of oracleRValues field.
   * @param[in,out] obj     class object
   * @return JSON string.
   */
  static std::string GetOracleRValuesString(  // line separate
      const CreateCetAdaptorSignatureRequest& obj) {  // NOLINT
    // Do not set to const, because substitution of member variables
    // may occur in pre / post processing inside Serialize
    return obj.oracle_r_values_.Serialize();
  }
  /**
   * @brief Set json object to oracleRValues field.
   * @param[in,out] obj     class object
   * @param[in] json_value  JSON object
   */
  static void SetOracleRValuesString(  // line separate
      CreateCetAdaptorSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    obj.oracle_r_values_.DeserializeUniValue(json_value);
  }

  /**
   * @brief Get of fundInputAmount
   * @return fundInputAmount
   */
  uint64_t GetFundInputAmount() const {
    return fund_input_amount_;
  }
  /**
   * @brief Set to fundInputAmount
   * @param[in] fund_input_amount    setting value.
   */
  void SetFundInputAmount(  // line separate
    const uint64_t& fund_input_amount) {  // NOLINT
    this->fund_input_amount_ = fund_input_amount;
  }
  /**
   * @brief Get data type of fundInputAmount
   * @return Data type of fundInputAmount
   */
  static std::string GetFundInputAmountFieldType() {
    return "uint64_t";
  }
  /**
   * @brief Get json string of fundInputAmount field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetFundInputAmountString(  // line separate
      const CreateCetAdaptorSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fund_input_amount_);
  }
  /**
   * @brief Set json object to fundInputAmount field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFundInputAmountString(  // line separate
      CreateCetAdaptorSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.fund_input_amount_, json_value);
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
      const CreateCetAdaptorSignatureRequest& obj) {  // NOLINT
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
      CreateCetAdaptorSignatureRequest& obj,  // NOLINT
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
      const CreateCetAdaptorSignatureRequestStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  CreateCetAdaptorSignatureRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using CreateCetAdaptorSignatureRequestMapTable =
    cfd::core::JsonTableMap<CreateCetAdaptorSignatureRequest>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const CreateCetAdaptorSignatureRequestMapTable& GetJsonMapper() const {  // NOLINT
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
   * @brief Get ignore item lists of JSON mapping.
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
  static CreateCetAdaptorSignatureRequestMapTable json_mapper;
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
   * @brief JsonAPI(fundVout) value
   */
  uint32_t fund_vout_ = 0;
  /**
   * @brief JsonAPI(localFundPubkey) value
   */
  std::string local_fund_pubkey_ = "";
  /**
   * @brief JsonAPI(remoteFundPubkey) value
   */
  std::string remote_fund_pubkey_ = "";
  /**
   * @brief JsonAPI(oraclePubkey) value
   */
  std::string oracle_pubkey_ = "";
  /**
   * @brief JsonAPI(oracleRValues) value
   */
  JsonValueVector<std::string> oracle_r_values_;  // NOLINT
  /**
   * @brief JsonAPI(fundInputAmount) value
   */
  uint64_t fund_input_amount_ = 0;
  /**
   * @brief JsonAPI(messages) value
   */
  JsonValueVector<std::string> messages_;  // NOLINT
};

// ------------------------------------------------------------------------
// CreateCetAdaptorSignatureResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (CreateCetAdaptorSignatureResponse) class
 */
class CreateCetAdaptorSignatureResponse
  : public cfd::core::JsonClassBase<CreateCetAdaptorSignatureResponse> {
 public:
  CreateCetAdaptorSignatureResponse() {
    CollectFieldName();
  }
  virtual ~CreateCetAdaptorSignatureResponse() {
    // do nothing
  }
  /**
   * @brief collect field name.
   */
  static void CollectFieldName();

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
      const CreateCetAdaptorSignatureResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.signature_);
  }
  /**
   * @brief Set json object to signature field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetSignatureString(  // line separate
      CreateCetAdaptorSignatureResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.signature_, json_value);
  }

  /**
   * @brief Get of proof
   * @return proof
   */
  std::string GetProof() const {
    return proof_;
  }
  /**
   * @brief Set to proof
   * @param[in] proof    setting value.
   */
  void SetProof(  // line separate
    const std::string& proof) {  // NOLINT
    this->proof_ = proof;
  }
  /**
   * @brief Get data type of proof
   * @return Data type of proof
   */
  static std::string GetProofFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of proof field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetProofString(  // line separate
      const CreateCetAdaptorSignatureResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.proof_);
  }
  /**
   * @brief Set json object to proof field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetProofString(  // line separate
      CreateCetAdaptorSignatureResponse& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.proof_, json_value);
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
      const CreateCetAdaptorSignatureResponseStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  CreateCetAdaptorSignatureResponseStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using CreateCetAdaptorSignatureResponseMapTable =
    cfd::core::JsonTableMap<CreateCetAdaptorSignatureResponse>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const CreateCetAdaptorSignatureResponseMapTable& GetJsonMapper() const {  // NOLINT
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
   * @brief Get ignore item lists of JSON mapping.
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
  static CreateCetAdaptorSignatureResponseMapTable json_mapper;
  /**
   * @brief field name list.
   */
  static std::vector<std::string> item_list;
  /**
   * @brief ignore item list.
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(signature) value
   */
  std::string signature_ = "";
  /**
   * @brief JsonAPI(proof) value
   */
  std::string proof_ = "";
};

// ------------------------------------------------------------------------
// CreateCetAdaptorSignaturesRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (CreateCetAdaptorSignaturesRequest) class
 */
class CreateCetAdaptorSignaturesRequest
  : public cfd::core::JsonClassBase<CreateCetAdaptorSignaturesRequest> {
 public:
  CreateCetAdaptorSignaturesRequest() {
    CollectFieldName();
  }
  virtual ~CreateCetAdaptorSignaturesRequest() {
    // do nothing
  }
  /**
   * @brief collect field name.
   */
  static void CollectFieldName();

  /**
   * @brief Get of cetsHex.
   * @return cetsHex
   */
  JsonValueVector<std::string>& GetCetsHex() {  // NOLINT
    return cets_hex_;
  }
  /**
   * @brief Set to cetsHex.
   * @param[in] cets_hex    setting value.
   */
  void SetCetsHex(  // line separate
      const JsonValueVector<std::string>& cets_hex) {  // NOLINT
    this->cets_hex_ = cets_hex;
  }
  /**
   * @brief Get data type of cetsHex.
   * @return Data type of cetsHex.
   */
  static std::string GetCetsHexFieldType() {
    return "JsonValueVector<std::string>";  // NOLINT
  }
  /**
   * @brief Get json string of cetsHex field.
   * @param[in,out] obj     class object
   * @return JSON string.
   */
  static std::string GetCetsHexString(  // line separate
      const CreateCetAdaptorSignaturesRequest& obj) {  // NOLINT
    // Do not set to const, because substitution of member variables
    // may occur in pre / post processing inside Serialize
    return obj.cets_hex_.Serialize();
  }
  /**
   * @brief Set json object to cetsHex field.
   * @param[in,out] obj     class object
   * @param[in] json_value  JSON object
   */
  static void SetCetsHexString(  // line separate
      CreateCetAdaptorSignaturesRequest& obj,  // NOLINT
      const UniValue& json_value) {
    obj.cets_hex_.DeserializeUniValue(json_value);
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
      const CreateCetAdaptorSignaturesRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.privkey_);
  }
  /**
   * @brief Set json object to privkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetPrivkeyString(  // line separate
      CreateCetAdaptorSignaturesRequest& obj,  // NOLINT
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
      const CreateCetAdaptorSignaturesRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fund_tx_id_);
  }
  /**
   * @brief Set json object to fundTxId field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFundTxIdString(  // line separate
      CreateCetAdaptorSignaturesRequest& obj,  // NOLINT
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
      const CreateCetAdaptorSignaturesRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fund_vout_);
  }
  /**
   * @brief Set json object to fundVout field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFundVoutString(  // line separate
      CreateCetAdaptorSignaturesRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.fund_vout_, json_value);
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
      const CreateCetAdaptorSignaturesRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.local_fund_pubkey_);
  }
  /**
   * @brief Set json object to localFundPubkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetLocalFundPubkeyString(  // line separate
      CreateCetAdaptorSignaturesRequest& obj,  // NOLINT
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
      const CreateCetAdaptorSignaturesRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.remote_fund_pubkey_);
  }
  /**
   * @brief Set json object to remoteFundPubkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetRemoteFundPubkeyString(  // line separate
      CreateCetAdaptorSignaturesRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.remote_fund_pubkey_, json_value);
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
      const CreateCetAdaptorSignaturesRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.oracle_pubkey_);
  }
  /**
   * @brief Set json object to oraclePubkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetOraclePubkeyString(  // line separate
      CreateCetAdaptorSignaturesRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.oracle_pubkey_, json_value);
  }

  /**
   * @brief Get of oracleRValues.
   * @return oracleRValues
   */
  JsonValueVector<std::string>& GetOracleRValues() {  // NOLINT
    return oracle_r_values_;
  }
  /**
   * @brief Set to oracleRValues.
   * @param[in] oracle_r_values    setting value.
   */
  void SetOracleRValues(  // line separate
      const JsonValueVector<std::string>& oracle_r_values) {  // NOLINT
    this->oracle_r_values_ = oracle_r_values;
  }
  /**
   * @brief Get data type of oracleRValues.
   * @return Data type of oracleRValues.
   */
  static std::string GetOracleRValuesFieldType() {
    return "JsonValueVector<std::string>";  // NOLINT
  }
  /**
   * @brief Get json string of oracleRValues field.
   * @param[in,out] obj     class object
   * @return JSON string.
   */
  static std::string GetOracleRValuesString(  // line separate
      const CreateCetAdaptorSignaturesRequest& obj) {  // NOLINT
    // Do not set to const, because substitution of member variables
    // may occur in pre / post processing inside Serialize
    return obj.oracle_r_values_.Serialize();
  }
  /**
   * @brief Set json object to oracleRValues field.
   * @param[in,out] obj     class object
   * @param[in] json_value  JSON object
   */
  static void SetOracleRValuesString(  // line separate
      CreateCetAdaptorSignaturesRequest& obj,  // NOLINT
      const UniValue& json_value) {
    obj.oracle_r_values_.DeserializeUniValue(json_value);
  }

  /**
   * @brief Get of fundInputAmount
   * @return fundInputAmount
   */
  uint64_t GetFundInputAmount() const {
    return fund_input_amount_;
  }
  /**
   * @brief Set to fundInputAmount
   * @param[in] fund_input_amount    setting value.
   */
  void SetFundInputAmount(  // line separate
    const uint64_t& fund_input_amount) {  // NOLINT
    this->fund_input_amount_ = fund_input_amount;
  }
  /**
   * @brief Get data type of fundInputAmount
   * @return Data type of fundInputAmount
   */
  static std::string GetFundInputAmountFieldType() {
    return "uint64_t";
  }
  /**
   * @brief Get json string of fundInputAmount field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetFundInputAmountString(  // line separate
      const CreateCetAdaptorSignaturesRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fund_input_amount_);
  }
  /**
   * @brief Set json object to fundInputAmount field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFundInputAmountString(  // line separate
      CreateCetAdaptorSignaturesRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.fund_input_amount_, json_value);
  }

  /**
   * @brief Get of messagesList.
   * @return messagesList
   */
  JsonObjectVector<Messages, MessagesStruct>& GetMessagesList() {  // NOLINT
    return messages_list_;
  }
  /**
   * @brief Set to messagesList.
   * @param[in] messages_list    setting value.
   */
  void SetMessagesList(  // line separate
      const JsonObjectVector<Messages, MessagesStruct>& messages_list) {  // NOLINT
    this->messages_list_ = messages_list;
  }
  /**
   * @brief Get data type of messagesList.
   * @return Data type of messagesList.
   */
  static std::string GetMessagesListFieldType() {
    return "JsonObjectVector<Messages, MessagesStruct>";  // NOLINT
  }
  /**
   * @brief Get json string of messagesList field.
   * @param[in,out] obj     class object
   * @return JSON string.
   */
  static std::string GetMessagesListString(  // line separate
      const CreateCetAdaptorSignaturesRequest& obj) {  // NOLINT
    // Do not set to const, because substitution of member variables
    // may occur in pre / post processing inside Serialize
    return obj.messages_list_.Serialize();
  }
  /**
   * @brief Set json object to messagesList field.
   * @param[in,out] obj     class object
   * @param[in] json_value  JSON object
   */
  static void SetMessagesListString(  // line separate
      CreateCetAdaptorSignaturesRequest& obj,  // NOLINT
      const UniValue& json_value) {
    obj.messages_list_.DeserializeUniValue(json_value);
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
      const CreateCetAdaptorSignaturesRequestStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  CreateCetAdaptorSignaturesRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using CreateCetAdaptorSignaturesRequestMapTable =
    cfd::core::JsonTableMap<CreateCetAdaptorSignaturesRequest>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const CreateCetAdaptorSignaturesRequestMapTable& GetJsonMapper() const {  // NOLINT
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
   * @brief Get ignore item lists of JSON mapping.
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
  static CreateCetAdaptorSignaturesRequestMapTable json_mapper;
  /**
   * @brief field name list.
   */
  static std::vector<std::string> item_list;
  /**
   * @brief ignore item list.
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(cetsHex) value
   */
  JsonValueVector<std::string> cets_hex_;  // NOLINT
  /**
   * @brief JsonAPI(privkey) value
   */
  std::string privkey_ = "";
  /**
   * @brief JsonAPI(fundTxId) value
   */
  std::string fund_tx_id_ = "";
  /**
   * @brief JsonAPI(fundVout) value
   */
  uint32_t fund_vout_ = 0;
  /**
   * @brief JsonAPI(localFundPubkey) value
   */
  std::string local_fund_pubkey_ = "";
  /**
   * @brief JsonAPI(remoteFundPubkey) value
   */
  std::string remote_fund_pubkey_ = "";
  /**
   * @brief JsonAPI(oraclePubkey) value
   */
  std::string oracle_pubkey_ = "";
  /**
   * @brief JsonAPI(oracleRValues) value
   */
  JsonValueVector<std::string> oracle_r_values_;  // NOLINT
  /**
   * @brief JsonAPI(fundInputAmount) value
   */
  uint64_t fund_input_amount_ = 0;
  /**
   * @brief JsonAPI(messagesList) value
   */
  JsonObjectVector<Messages, MessagesStruct> messages_list_;  // NOLINT
};

// ------------------------------------------------------------------------
// CreateCetAdaptorSignaturesResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (CreateCetAdaptorSignaturesResponse) class
 */
class CreateCetAdaptorSignaturesResponse
  : public cfd::core::JsonClassBase<CreateCetAdaptorSignaturesResponse> {
 public:
  CreateCetAdaptorSignaturesResponse() {
    CollectFieldName();
  }
  virtual ~CreateCetAdaptorSignaturesResponse() {
    // do nothing
  }
  /**
   * @brief collect field name.
   */
  static void CollectFieldName();

  /**
   * @brief Get of adaptorPairs.
   * @return adaptorPairs
   */
  JsonObjectVector<AdaptorPair, AdaptorPairStruct>& GetAdaptorPairs() {  // NOLINT
    return adaptor_pairs_;
  }
  /**
   * @brief Set to adaptorPairs.
   * @param[in] adaptor_pairs    setting value.
   */
  void SetAdaptorPairs(  // line separate
      const JsonObjectVector<AdaptorPair, AdaptorPairStruct>& adaptor_pairs) {  // NOLINT
    this->adaptor_pairs_ = adaptor_pairs;
  }
  /**
   * @brief Get data type of adaptorPairs.
   * @return Data type of adaptorPairs.
   */
  static std::string GetAdaptorPairsFieldType() {
    return "JsonObjectVector<AdaptorPair, AdaptorPairStruct>";  // NOLINT
  }
  /**
   * @brief Get json string of adaptorPairs field.
   * @param[in,out] obj     class object
   * @return JSON string.
   */
  static std::string GetAdaptorPairsString(  // line separate
      const CreateCetAdaptorSignaturesResponse& obj) {  // NOLINT
    // Do not set to const, because substitution of member variables
    // may occur in pre / post processing inside Serialize
    return obj.adaptor_pairs_.Serialize();
  }
  /**
   * @brief Set json object to adaptorPairs field.
   * @param[in,out] obj     class object
   * @param[in] json_value  JSON object
   */
  static void SetAdaptorPairsString(  // line separate
      CreateCetAdaptorSignaturesResponse& obj,  // NOLINT
      const UniValue& json_value) {
    obj.adaptor_pairs_.DeserializeUniValue(json_value);
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
      const CreateCetAdaptorSignaturesResponseStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  CreateCetAdaptorSignaturesResponseStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using CreateCetAdaptorSignaturesResponseMapTable =
    cfd::core::JsonTableMap<CreateCetAdaptorSignaturesResponse>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const CreateCetAdaptorSignaturesResponseMapTable& GetJsonMapper() const {  // NOLINT
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
   * @brief Get ignore item lists of JSON mapping.
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
  static CreateCetAdaptorSignaturesResponseMapTable json_mapper;
  /**
   * @brief field name list.
   */
  static std::vector<std::string> item_list;
  /**
   * @brief ignore item list.
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(adaptorPairs) value
   */
  JsonObjectVector<AdaptorPair, AdaptorPairStruct> adaptor_pairs_;  // NOLINT
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
   * @brief Get ignore item lists of JSON mapping.
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
};

// ------------------------------------------------------------------------
// TxInInfoRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (TxInInfoRequest) class
 */
class TxInInfoRequest
  : public cfd::core::JsonClassBase<TxInInfoRequest> {
 public:
  TxInInfoRequest() {
    CollectFieldName();
  }
  virtual ~TxInInfoRequest() {
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
      const TxInInfoRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.txid_);
  }
  /**
   * @brief Set json object to txid field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetTxidString(  // line separate
      TxInInfoRequest& obj,  // NOLINT
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
      const TxInInfoRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.vout_);
  }
  /**
   * @brief Set json object to vout field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetVoutString(  // line separate
      TxInInfoRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.vout_, json_value);
  }

  /**
   * @brief Get of redeemScript
   * @return redeemScript
   */
  std::string GetRedeemScript() const {
    return redeem_script_;
  }
  /**
   * @brief Set to redeemScript
   * @param[in] redeem_script    setting value.
   */
  void SetRedeemScript(  // line separate
    const std::string& redeem_script) {  // NOLINT
    this->redeem_script_ = redeem_script;
  }
  /**
   * @brief Get data type of redeemScript
   * @return Data type of redeemScript
   */
  static std::string GetRedeemScriptFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of redeemScript field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetRedeemScriptString(  // line separate
      const TxInInfoRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.redeem_script_);
  }
  /**
   * @brief Set json object to redeemScript field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetRedeemScriptString(  // line separate
      TxInInfoRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.redeem_script_, json_value);
  }

  /**
   * @brief Get of maxWitnessLength
   * @return maxWitnessLength
   */
  uint32_t GetMaxWitnessLength() const {
    return max_witness_length_;
  }
  /**
   * @brief Set to maxWitnessLength
   * @param[in] max_witness_length    setting value.
   */
  void SetMaxWitnessLength(  // line separate
    const uint32_t& max_witness_length) {  // NOLINT
    this->max_witness_length_ = max_witness_length;
  }
  /**
   * @brief Get data type of maxWitnessLength
   * @return Data type of maxWitnessLength
   */
  static std::string GetMaxWitnessLengthFieldType() {
    return "uint32_t";
  }
  /**
   * @brief Get json string of maxWitnessLength field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetMaxWitnessLengthString(  // line separate
      const TxInInfoRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.max_witness_length_);
  }
  /**
   * @brief Set json object to maxWitnessLength field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetMaxWitnessLengthString(  // line separate
      TxInInfoRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.max_witness_length_, json_value);
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
      const TxInInfoRequestStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  TxInInfoRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using TxInInfoRequestMapTable =
    cfd::core::JsonTableMap<TxInInfoRequest>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const TxInInfoRequestMapTable& GetJsonMapper() const {  // NOLINT
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
   * @brief Get ignore item lists of JSON mapping.
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
  static TxInInfoRequestMapTable json_mapper;
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
  /**
   * @brief JsonAPI(redeemScript) value
   */
  std::string redeem_script_ = "";
  /**
   * @brief JsonAPI(maxWitnessLength) value
   */
  uint32_t max_witness_length_ = 108;
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
   * @brief Get of payouts.
   * @return payouts
   */
  JsonObjectVector<PayoutRequest, PayoutRequestStruct>& GetPayouts() {  // NOLINT
    return payouts_;
  }
  /**
   * @brief Set to payouts.
   * @param[in] payouts    setting value.
   */
  void SetPayouts(  // line separate
      const JsonObjectVector<PayoutRequest, PayoutRequestStruct>& payouts) {  // NOLINT
    this->payouts_ = payouts;
  }
  /**
   * @brief Get data type of payouts.
   * @return Data type of payouts.
   */
  static std::string GetPayoutsFieldType() {
    return "JsonObjectVector<PayoutRequest, PayoutRequestStruct>";  // NOLINT
  }
  /**
   * @brief Get json string of payouts field.
   * @param[in,out] obj     class object
   * @return JSON string.
   */
  static std::string GetPayoutsString(  // line separate
      const CreateDlcTransactionsRequest& obj) {  // NOLINT
    // Do not set to const, because substitution of member variables
    // may occur in pre / post processing inside Serialize
    return obj.payouts_.Serialize();
  }
  /**
   * @brief Set json object to payouts field.
   * @param[in,out] obj     class object
   * @param[in] json_value  JSON object
   */
  static void SetPayoutsString(  // line separate
      CreateDlcTransactionsRequest& obj,  // NOLINT
      const UniValue& json_value) {
    obj.payouts_.DeserializeUniValue(json_value);
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
   * @brief Get of localFinalScriptPubkey
   * @return localFinalScriptPubkey
   */
  std::string GetLocalFinalScriptPubkey() const {
    return local_final_script_pubkey_;
  }
  /**
   * @brief Set to localFinalScriptPubkey
   * @param[in] local_final_script_pubkey    setting value.
   */
  void SetLocalFinalScriptPubkey(  // line separate
    const std::string& local_final_script_pubkey) {  // NOLINT
    this->local_final_script_pubkey_ = local_final_script_pubkey;
  }
  /**
   * @brief Get data type of localFinalScriptPubkey
   * @return Data type of localFinalScriptPubkey
   */
  static std::string GetLocalFinalScriptPubkeyFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of localFinalScriptPubkey field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetLocalFinalScriptPubkeyString(  // line separate
      const CreateDlcTransactionsRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.local_final_script_pubkey_);
  }
  /**
   * @brief Set json object to localFinalScriptPubkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetLocalFinalScriptPubkeyString(  // line separate
      CreateDlcTransactionsRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.local_final_script_pubkey_, json_value);
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
   * @brief Get of remoteFinalScriptPubkey
   * @return remoteFinalScriptPubkey
   */
  std::string GetRemoteFinalScriptPubkey() const {
    return remote_final_script_pubkey_;
  }
  /**
   * @brief Set to remoteFinalScriptPubkey
   * @param[in] remote_final_script_pubkey    setting value.
   */
  void SetRemoteFinalScriptPubkey(  // line separate
    const std::string& remote_final_script_pubkey) {  // NOLINT
    this->remote_final_script_pubkey_ = remote_final_script_pubkey;
  }
  /**
   * @brief Get data type of remoteFinalScriptPubkey
   * @return Data type of remoteFinalScriptPubkey
   */
  static std::string GetRemoteFinalScriptPubkeyFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of remoteFinalScriptPubkey field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetRemoteFinalScriptPubkeyString(  // line separate
      const CreateDlcTransactionsRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.remote_final_script_pubkey_);
  }
  /**
   * @brief Set json object to remoteFinalScriptPubkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetRemoteFinalScriptPubkeyString(  // line separate
      CreateDlcTransactionsRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.remote_final_script_pubkey_, json_value);
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
   * @brief Get of refundLocktime
   * @return refundLocktime
   */
  uint64_t GetRefundLocktime() const {
    return refund_locktime_;
  }
  /**
   * @brief Set to refundLocktime
   * @param[in] refund_locktime    setting value.
   */
  void SetRefundLocktime(  // line separate
    const uint64_t& refund_locktime) {  // NOLINT
    this->refund_locktime_ = refund_locktime;
  }
  /**
   * @brief Get data type of refundLocktime
   * @return Data type of refundLocktime
   */
  static std::string GetRefundLocktimeFieldType() {
    return "uint64_t";
  }
  /**
   * @brief Get json string of refundLocktime field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetRefundLocktimeString(  // line separate
      const CreateDlcTransactionsRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.refund_locktime_);
  }
  /**
   * @brief Set json object to refundLocktime field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetRefundLocktimeString(  // line separate
      CreateDlcTransactionsRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.refund_locktime_, json_value);
  }

  /**
   * @brief Get of localInputs.
   * @return localInputs
   */
  JsonObjectVector<TxInInfoRequest, TxInInfoRequestStruct>& GetLocalInputs() {  // NOLINT
    return local_inputs_;
  }
  /**
   * @brief Set to localInputs.
   * @param[in] local_inputs    setting value.
   */
  void SetLocalInputs(  // line separate
      const JsonObjectVector<TxInInfoRequest, TxInInfoRequestStruct>& local_inputs) {  // NOLINT
    this->local_inputs_ = local_inputs;
  }
  /**
   * @brief Get data type of localInputs.
   * @return Data type of localInputs.
   */
  static std::string GetLocalInputsFieldType() {
    return "JsonObjectVector<TxInInfoRequest, TxInInfoRequestStruct>";  // NOLINT
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
   * @brief Get of localChangeScriptPubkey
   * @return localChangeScriptPubkey
   */
  std::string GetLocalChangeScriptPubkey() const {
    return local_change_script_pubkey_;
  }
  /**
   * @brief Set to localChangeScriptPubkey
   * @param[in] local_change_script_pubkey    setting value.
   */
  void SetLocalChangeScriptPubkey(  // line separate
    const std::string& local_change_script_pubkey) {  // NOLINT
    this->local_change_script_pubkey_ = local_change_script_pubkey;
  }
  /**
   * @brief Get data type of localChangeScriptPubkey
   * @return Data type of localChangeScriptPubkey
   */
  static std::string GetLocalChangeScriptPubkeyFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of localChangeScriptPubkey field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetLocalChangeScriptPubkeyString(  // line separate
      const CreateDlcTransactionsRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.local_change_script_pubkey_);
  }
  /**
   * @brief Set json object to localChangeScriptPubkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetLocalChangeScriptPubkeyString(  // line separate
      CreateDlcTransactionsRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.local_change_script_pubkey_, json_value);
  }

  /**
   * @brief Get of remoteInputs.
   * @return remoteInputs
   */
  JsonObjectVector<TxInInfoRequest, TxInInfoRequestStruct>& GetRemoteInputs() {  // NOLINT
    return remote_inputs_;
  }
  /**
   * @brief Set to remoteInputs.
   * @param[in] remote_inputs    setting value.
   */
  void SetRemoteInputs(  // line separate
      const JsonObjectVector<TxInInfoRequest, TxInInfoRequestStruct>& remote_inputs) {  // NOLINT
    this->remote_inputs_ = remote_inputs;
  }
  /**
   * @brief Get data type of remoteInputs.
   * @return Data type of remoteInputs.
   */
  static std::string GetRemoteInputsFieldType() {
    return "JsonObjectVector<TxInInfoRequest, TxInInfoRequestStruct>";  // NOLINT
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
   * @brief Get of remoteChangeScriptPubkey
   * @return remoteChangeScriptPubkey
   */
  std::string GetRemoteChangeScriptPubkey() const {
    return remote_change_script_pubkey_;
  }
  /**
   * @brief Set to remoteChangeScriptPubkey
   * @param[in] remote_change_script_pubkey    setting value.
   */
  void SetRemoteChangeScriptPubkey(  // line separate
    const std::string& remote_change_script_pubkey) {  // NOLINT
    this->remote_change_script_pubkey_ = remote_change_script_pubkey;
  }
  /**
   * @brief Get data type of remoteChangeScriptPubkey
   * @return Data type of remoteChangeScriptPubkey
   */
  static std::string GetRemoteChangeScriptPubkeyFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of remoteChangeScriptPubkey field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetRemoteChangeScriptPubkeyString(  // line separate
      const CreateDlcTransactionsRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.remote_change_script_pubkey_);
  }
  /**
   * @brief Set json object to remoteChangeScriptPubkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetRemoteChangeScriptPubkeyString(  // line separate
      CreateDlcTransactionsRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.remote_change_script_pubkey_, json_value);
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
   * @brief Get of cetLockTime
   * @return cetLockTime
   */
  uint64_t GetCetLockTime() const {
    return cet_lock_time_;
  }
  /**
   * @brief Set to cetLockTime
   * @param[in] cet_lock_time    setting value.
   */
  void SetCetLockTime(  // line separate
    const uint64_t& cet_lock_time) {  // NOLINT
    this->cet_lock_time_ = cet_lock_time;
  }
  /**
   * @brief Get data type of cetLockTime
   * @return Data type of cetLockTime
   */
  static std::string GetCetLockTimeFieldType() {
    return "uint64_t";
  }
  /**
   * @brief Get json string of cetLockTime field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetCetLockTimeString(  // line separate
      const CreateDlcTransactionsRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.cet_lock_time_);
  }
  /**
   * @brief Set json object to cetLockTime field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetCetLockTimeString(  // line separate
      CreateDlcTransactionsRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.cet_lock_time_, json_value);
  }

  /**
   * @brief Get of fundLockTime
   * @return fundLockTime
   */
  uint64_t GetFundLockTime() const {
    return fund_lock_time_;
  }
  /**
   * @brief Set to fundLockTime
   * @param[in] fund_lock_time    setting value.
   */
  void SetFundLockTime(  // line separate
    const uint64_t& fund_lock_time) {  // NOLINT
    this->fund_lock_time_ = fund_lock_time;
  }
  /**
   * @brief Get data type of fundLockTime
   * @return Data type of fundLockTime
   */
  static std::string GetFundLockTimeFieldType() {
    return "uint64_t";
  }
  /**
   * @brief Get json string of fundLockTime field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetFundLockTimeString(  // line separate
      const CreateDlcTransactionsRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fund_lock_time_);
  }
  /**
   * @brief Set json object to fundLockTime field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFundLockTimeString(  // line separate
      CreateDlcTransactionsRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.fund_lock_time_, json_value);
  }

  /**
   * @brief Get of optionDest
   * @return optionDest
   */
  std::string GetOptionDest() const {
    return option_dest_;
  }
  /**
   * @brief Set to optionDest
   * @param[in] option_dest    setting value.
   */
  void SetOptionDest(  // line separate
    const std::string& option_dest) {  // NOLINT
    this->option_dest_ = option_dest;
  }
  /**
   * @brief Get data type of optionDest
   * @return Data type of optionDest
   */
  static std::string GetOptionDestFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of optionDest field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetOptionDestString(  // line separate
      const CreateDlcTransactionsRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.option_dest_);
  }
  /**
   * @brief Set json object to optionDest field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetOptionDestString(  // line separate
      CreateDlcTransactionsRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.option_dest_, json_value);
  }

  /**
   * @brief Get of optionPremium
   * @return optionPremium
   */
  uint64_t GetOptionPremium() const {
    return option_premium_;
  }
  /**
   * @brief Set to optionPremium
   * @param[in] option_premium    setting value.
   */
  void SetOptionPremium(  // line separate
    const uint64_t& option_premium) {  // NOLINT
    this->option_premium_ = option_premium;
  }
  /**
   * @brief Get data type of optionPremium
   * @return Data type of optionPremium
   */
  static std::string GetOptionPremiumFieldType() {
    return "uint64_t";
  }
  /**
   * @brief Get json string of optionPremium field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetOptionPremiumString(  // line separate
      const CreateDlcTransactionsRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.option_premium_);
  }
  /**
   * @brief Set json object to optionPremium field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetOptionPremiumString(  // line separate
      CreateDlcTransactionsRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.option_premium_, json_value);
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
   * @brief Get ignore item lists of JSON mapping.
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
   * @brief JsonAPI(payouts) value
   */
  JsonObjectVector<PayoutRequest, PayoutRequestStruct> payouts_;  // NOLINT
  /**
   * @brief JsonAPI(localFundPubkey) value
   */
  std::string local_fund_pubkey_ = "";
  /**
   * @brief JsonAPI(localFinalScriptPubkey) value
   */
  std::string local_final_script_pubkey_ = "";
  /**
   * @brief JsonAPI(remoteFundPubkey) value
   */
  std::string remote_fund_pubkey_ = "";
  /**
   * @brief JsonAPI(remoteFinalScriptPubkey) value
   */
  std::string remote_final_script_pubkey_ = "";
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
   * @brief JsonAPI(refundLocktime) value
   */
  uint64_t refund_locktime_ = 0;
  /**
   * @brief JsonAPI(localInputs) value
   */
  JsonObjectVector<TxInInfoRequest, TxInInfoRequestStruct> local_inputs_;  // NOLINT
  /**
   * @brief JsonAPI(localChangeScriptPubkey) value
   */
  std::string local_change_script_pubkey_ = "";
  /**
   * @brief JsonAPI(remoteInputs) value
   */
  JsonObjectVector<TxInInfoRequest, TxInInfoRequestStruct> remote_inputs_;  // NOLINT
  /**
   * @brief JsonAPI(remoteChangeScriptPubkey) value
   */
  std::string remote_change_script_pubkey_ = "";
  /**
   * @brief JsonAPI(feeRate) value
   */
  uint32_t fee_rate_ = 0;
  /**
   * @brief JsonAPI(cetLockTime) value
   */
  uint64_t cet_lock_time_ = 0;
  /**
   * @brief JsonAPI(fundLockTime) value
   */
  uint64_t fund_lock_time_ = 0;
  /**
   * @brief JsonAPI(optionDest) value
   */
  std::string option_dest_ = "";
  /**
   * @brief JsonAPI(optionPremium) value
   */
  uint64_t option_premium_ = 0;
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
   * @brief Get of cetsHex.
   * @return cetsHex
   */
  JsonValueVector<std::string>& GetCetsHex() {  // NOLINT
    return cets_hex_;
  }
  /**
   * @brief Set to cetsHex.
   * @param[in] cets_hex    setting value.
   */
  void SetCetsHex(  // line separate
      const JsonValueVector<std::string>& cets_hex) {  // NOLINT
    this->cets_hex_ = cets_hex;
  }
  /**
   * @brief Get data type of cetsHex.
   * @return Data type of cetsHex.
   */
  static std::string GetCetsHexFieldType() {
    return "JsonValueVector<std::string>";  // NOLINT
  }
  /**
   * @brief Get json string of cetsHex field.
   * @param[in,out] obj     class object
   * @return JSON string.
   */
  static std::string GetCetsHexString(  // line separate
      const CreateDlcTransactionsResponse& obj) {  // NOLINT
    // Do not set to const, because substitution of member variables
    // may occur in pre / post processing inside Serialize
    return obj.cets_hex_.Serialize();
  }
  /**
   * @brief Set json object to cetsHex field.
   * @param[in,out] obj     class object
   * @param[in] json_value  JSON object
   */
  static void SetCetsHexString(  // line separate
      CreateDlcTransactionsResponse& obj,  // NOLINT
      const UniValue& json_value) {
    obj.cets_hex_.DeserializeUniValue(json_value);
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
   * @brief Get ignore item lists of JSON mapping.
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
   * @brief JsonAPI(cetsHex) value
   */
  JsonValueVector<std::string> cets_hex_;  // NOLINT
  /**
   * @brief JsonAPI(refundTxHex) value
   */
  std::string refund_tx_hex_ = "";
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
   * @brief Get ignore item lists of JSON mapping.
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
// TxOutRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (TxOutRequest) class
 */
class TxOutRequest
  : public cfd::core::JsonClassBase<TxOutRequest> {
 public:
  TxOutRequest() {
    CollectFieldName();
  }
  virtual ~TxOutRequest() {
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
      const TxOutRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.amount_);
  }
  /**
   * @brief Set json object to amount field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetAmountString(  // line separate
      TxOutRequest& obj,  // NOLINT
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
      const TxOutRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.address_);
  }
  /**
   * @brief Set json object to address field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetAddressString(  // line separate
      TxOutRequest& obj,  // NOLINT
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
      const TxOutRequestStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  TxOutRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using TxOutRequestMapTable =
    cfd::core::JsonTableMap<TxOutRequest>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const TxOutRequestMapTable& GetJsonMapper() const {  // NOLINT
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
   * @brief Get ignore item lists of JSON mapping.
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
  static TxOutRequestMapTable json_mapper;
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
  TxOutRequest& GetLocalChange() {  // NOLINT
    return local_change_;
  }
  /**
   * @brief Set to localChange.
   * @param[in] local_change    setting value.
   */
  void SetLocalChange(  // line separate
      const TxOutRequest& local_change) {  // NOLINT
    this->local_change_ = local_change;
  }
  /**
   * @brief Get data type of localChange.
   * @return Data type of localChange.
   */
  static std::string GetLocalChangeFieldType() {
    return "TxOutRequest";  // NOLINT
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
  TxOutRequest& GetRemoteChange() {  // NOLINT
    return remote_change_;
  }
  /**
   * @brief Set to remoteChange.
   * @param[in] remote_change    setting value.
   */
  void SetRemoteChange(  // line separate
      const TxOutRequest& remote_change) {  // NOLINT
    this->remote_change_ = remote_change;
  }
  /**
   * @brief Get data type of remoteChange.
   * @return Data type of remoteChange.
   */
  static std::string GetRemoteChangeFieldType() {
    return "TxOutRequest";  // NOLINT
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
   * @brief Get of feeRate
   * @return feeRate
   */
  int64_t GetFeeRate() const {
    return fee_rate_;
  }
  /**
   * @brief Set to feeRate
   * @param[in] fee_rate    setting value.
   */
  void SetFeeRate(  // line separate
    const int64_t& fee_rate) {  // NOLINT
    this->fee_rate_ = fee_rate;
  }
  /**
   * @brief Get data type of feeRate
   * @return Data type of feeRate
   */
  static std::string GetFeeRateFieldType() {
    return "int64_t";
  }
  /**
   * @brief Get json string of feeRate field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetFeeRateString(  // line separate
      const CreateFundTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fee_rate_);
  }
  /**
   * @brief Set json object to feeRate field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFeeRateString(  // line separate
      CreateFundTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.fee_rate_, json_value);
  }

  /**
   * @brief Get of optionDest
   * @return optionDest
   */
  std::string GetOptionDest() const {
    return option_dest_;
  }
  /**
   * @brief Set to optionDest
   * @param[in] option_dest    setting value.
   */
  void SetOptionDest(  // line separate
    const std::string& option_dest) {  // NOLINT
    this->option_dest_ = option_dest;
  }
  /**
   * @brief Get data type of optionDest
   * @return Data type of optionDest
   */
  static std::string GetOptionDestFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of optionDest field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetOptionDestString(  // line separate
      const CreateFundTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.option_dest_);
  }
  /**
   * @brief Set json object to optionDest field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetOptionDestString(  // line separate
      CreateFundTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.option_dest_, json_value);
  }

  /**
   * @brief Get of optionPremium
   * @return optionPremium
   */
  uint64_t GetOptionPremium() const {
    return option_premium_;
  }
  /**
   * @brief Set to optionPremium
   * @param[in] option_premium    setting value.
   */
  void SetOptionPremium(  // line separate
    const uint64_t& option_premium) {  // NOLINT
    this->option_premium_ = option_premium;
  }
  /**
   * @brief Get data type of optionPremium
   * @return Data type of optionPremium
   */
  static std::string GetOptionPremiumFieldType() {
    return "uint64_t";
  }
  /**
   * @brief Get json string of optionPremium field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetOptionPremiumString(  // line separate
      const CreateFundTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.option_premium_);
  }
  /**
   * @brief Set json object to optionPremium field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetOptionPremiumString(  // line separate
      CreateFundTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.option_premium_, json_value);
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
   * @brief Get ignore item lists of JSON mapping.
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
  JsonObjectVector<TxInRequest, TxInRequestStruct> local_inputs_;  // NOLINT
  /**
   * @brief JsonAPI(localChange) value
   */
  TxOutRequest local_change_;  // NOLINT
  /**
   * @brief JsonAPI(remoteInputs) value
   */
  JsonObjectVector<TxInRequest, TxInRequestStruct> remote_inputs_;  // NOLINT
  /**
   * @brief JsonAPI(remoteChange) value
   */
  TxOutRequest remote_change_;  // NOLINT
  /**
   * @brief JsonAPI(feeRate) value
   */
  int64_t fee_rate_ = 1;
  /**
   * @brief JsonAPI(optionDest) value
   */
  std::string option_dest_ = "";
  /**
   * @brief JsonAPI(optionPremium) value
   */
  uint64_t option_premium_ = 0;
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
   * @brief Get ignore item lists of JSON mapping.
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
   * @brief Get of localFinalScriptPubkey
   * @return localFinalScriptPubkey
   */
  std::string GetLocalFinalScriptPubkey() const {
    return local_final_script_pubkey_;
  }
  /**
   * @brief Set to localFinalScriptPubkey
   * @param[in] local_final_script_pubkey    setting value.
   */
  void SetLocalFinalScriptPubkey(  // line separate
    const std::string& local_final_script_pubkey) {  // NOLINT
    this->local_final_script_pubkey_ = local_final_script_pubkey;
  }
  /**
   * @brief Get data type of localFinalScriptPubkey
   * @return Data type of localFinalScriptPubkey
   */
  static std::string GetLocalFinalScriptPubkeyFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of localFinalScriptPubkey field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetLocalFinalScriptPubkeyString(  // line separate
      const CreateRefundTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.local_final_script_pubkey_);
  }
  /**
   * @brief Set json object to localFinalScriptPubkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetLocalFinalScriptPubkeyString(  // line separate
      CreateRefundTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.local_final_script_pubkey_, json_value);
  }

  /**
   * @brief Get of remoteFinalScriptPubkey
   * @return remoteFinalScriptPubkey
   */
  std::string GetRemoteFinalScriptPubkey() const {
    return remote_final_script_pubkey_;
  }
  /**
   * @brief Set to remoteFinalScriptPubkey
   * @param[in] remote_final_script_pubkey    setting value.
   */
  void SetRemoteFinalScriptPubkey(  // line separate
    const std::string& remote_final_script_pubkey) {  // NOLINT
    this->remote_final_script_pubkey_ = remote_final_script_pubkey;
  }
  /**
   * @brief Get data type of remoteFinalScriptPubkey
   * @return Data type of remoteFinalScriptPubkey
   */
  static std::string GetRemoteFinalScriptPubkeyFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of remoteFinalScriptPubkey field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetRemoteFinalScriptPubkeyString(  // line separate
      const CreateRefundTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.remote_final_script_pubkey_);
  }
  /**
   * @brief Set json object to remoteFinalScriptPubkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetRemoteFinalScriptPubkeyString(  // line separate
      CreateRefundTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.remote_final_script_pubkey_, json_value);
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
      const CreateRefundTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fund_tx_id_);
  }
  /**
   * @brief Set json object to fundTxId field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFundTxIdString(  // line separate
      CreateRefundTransactionRequest& obj,  // NOLINT
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
   * @brief Get ignore item lists of JSON mapping.
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
   * @brief JsonAPI(localFinalScriptPubkey) value
   */
  std::string local_final_script_pubkey_ = "";
  /**
   * @brief JsonAPI(remoteFinalScriptPubkey) value
   */
  std::string remote_final_script_pubkey_ = "";
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
   * @brief JsonAPI(fundTxId) value
   */
  std::string fund_tx_id_ = "";
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
   * @brief Get ignore item lists of JSON mapping.
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
   * @brief Get ignore item lists of JSON mapping.
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
   * @brief Get ignore item lists of JSON mapping.
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
// GetRawFundTxSignatureRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (GetRawFundTxSignatureRequest) class
 */
class GetRawFundTxSignatureRequest
  : public cfd::core::JsonClassBase<GetRawFundTxSignatureRequest> {
 public:
  GetRawFundTxSignatureRequest() {
    CollectFieldName();
  }
  virtual ~GetRawFundTxSignatureRequest() {
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
      const GetRawFundTxSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fund_tx_hex_);
  }
  /**
   * @brief Set json object to fundTxHex field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFundTxHexString(  // line separate
      GetRawFundTxSignatureRequest& obj,  // NOLINT
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
      const GetRawFundTxSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.privkey_);
  }
  /**
   * @brief Set json object to privkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetPrivkeyString(  // line separate
      GetRawFundTxSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.privkey_, json_value);
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
      const GetRawFundTxSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.prev_tx_id_);
  }
  /**
   * @brief Set json object to prevTxId field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetPrevTxIdString(  // line separate
      GetRawFundTxSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.prev_tx_id_, json_value);
  }

  /**
   * @brief Get of prevVout
   * @return prevVout
   */
  uint32_t GetPrevVout() const {
    return prev_vout_;
  }
  /**
   * @brief Set to prevVout
   * @param[in] prev_vout    setting value.
   */
  void SetPrevVout(  // line separate
    const uint32_t& prev_vout) {  // NOLINT
    this->prev_vout_ = prev_vout;
  }
  /**
   * @brief Get data type of prevVout
   * @return Data type of prevVout
   */
  static std::string GetPrevVoutFieldType() {
    return "uint32_t";
  }
  /**
   * @brief Get json string of prevVout field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetPrevVoutString(  // line separate
      const GetRawFundTxSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.prev_vout_);
  }
  /**
   * @brief Set json object to prevVout field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetPrevVoutString(  // line separate
      GetRawFundTxSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.prev_vout_, json_value);
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
      const GetRawFundTxSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.amount_);
  }
  /**
   * @brief Set json object to amount field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetAmountString(  // line separate
      GetRawFundTxSignatureRequest& obj,  // NOLINT
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
      const GetRawFundTxSignatureRequestStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  GetRawFundTxSignatureRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using GetRawFundTxSignatureRequestMapTable =
    cfd::core::JsonTableMap<GetRawFundTxSignatureRequest>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const GetRawFundTxSignatureRequestMapTable& GetJsonMapper() const {  // NOLINT
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
   * @brief Get ignore item lists of JSON mapping.
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
  static GetRawFundTxSignatureRequestMapTable json_mapper;
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
   * @brief JsonAPI(prevTxId) value
   */
  std::string prev_tx_id_ = "";
  /**
   * @brief JsonAPI(prevVout) value
   */
  uint32_t prev_vout_ = 0;
  /**
   * @brief JsonAPI(amount) value
   */
  uint64_t amount_ = 0;
};

// ------------------------------------------------------------------------
// GetRawFundTxSignatureResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (GetRawFundTxSignatureResponse) class
 */
class GetRawFundTxSignatureResponse
  : public cfd::core::JsonClassBase<GetRawFundTxSignatureResponse> {
 public:
  GetRawFundTxSignatureResponse() {
    CollectFieldName();
  }
  virtual ~GetRawFundTxSignatureResponse() {
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
      const GetRawFundTxSignatureResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.hex_);
  }
  /**
   * @brief Set json object to hex field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetHexString(  // line separate
      GetRawFundTxSignatureResponse& obj,  // NOLINT
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
      const GetRawFundTxSignatureResponseStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  GetRawFundTxSignatureResponseStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using GetRawFundTxSignatureResponseMapTable =
    cfd::core::JsonTableMap<GetRawFundTxSignatureResponse>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const GetRawFundTxSignatureResponseMapTable& GetJsonMapper() const {  // NOLINT
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
   * @brief Get ignore item lists of JSON mapping.
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
  static GetRawFundTxSignatureResponseMapTable json_mapper;
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
      const GetRawRefundTxSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fund_vout_);
  }
  /**
   * @brief Set json object to fundVout field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFundVoutString(  // line separate
      GetRawRefundTxSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.fund_vout_, json_value);
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
   * @brief Get of fundInputAmount
   * @return fundInputAmount
   */
  uint64_t GetFundInputAmount() const {
    return fund_input_amount_;
  }
  /**
   * @brief Set to fundInputAmount
   * @param[in] fund_input_amount    setting value.
   */
  void SetFundInputAmount(  // line separate
    const uint64_t& fund_input_amount) {  // NOLINT
    this->fund_input_amount_ = fund_input_amount;
  }
  /**
   * @brief Get data type of fundInputAmount
   * @return Data type of fundInputAmount
   */
  static std::string GetFundInputAmountFieldType() {
    return "uint64_t";
  }
  /**
   * @brief Get json string of fundInputAmount field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetFundInputAmountString(  // line separate
      const GetRawRefundTxSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fund_input_amount_);
  }
  /**
   * @brief Set json object to fundInputAmount field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFundInputAmountString(  // line separate
      GetRawRefundTxSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.fund_input_amount_, json_value);
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
   * @brief Get ignore item lists of JSON mapping.
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
   * @brief JsonAPI(fundVout) value
   */
  uint32_t fund_vout_ = 0;
  /**
   * @brief JsonAPI(localFundPubkey) value
   */
  std::string local_fund_pubkey_ = "";
  /**
   * @brief JsonAPI(remoteFundPubkey) value
   */
  std::string remote_fund_pubkey_ = "";
  /**
   * @brief JsonAPI(fundInputAmount) value
   */
  uint64_t fund_input_amount_ = 0;
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
   * @brief Get ignore item lists of JSON mapping.
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
// SignCetRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (SignCetRequest) class
 */
class SignCetRequest
  : public cfd::core::JsonClassBase<SignCetRequest> {
 public:
  SignCetRequest() {
    CollectFieldName();
  }
  virtual ~SignCetRequest() {
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
      const SignCetRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.cet_hex_);
  }
  /**
   * @brief Set json object to cetHex field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetCetHexString(  // line separate
      SignCetRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.cet_hex_, json_value);
  }

  /**
   * @brief Get of fundPrivkey
   * @return fundPrivkey
   */
  std::string GetFundPrivkey() const {
    return fund_privkey_;
  }
  /**
   * @brief Set to fundPrivkey
   * @param[in] fund_privkey    setting value.
   */
  void SetFundPrivkey(  // line separate
    const std::string& fund_privkey) {  // NOLINT
    this->fund_privkey_ = fund_privkey;
  }
  /**
   * @brief Get data type of fundPrivkey
   * @return Data type of fundPrivkey
   */
  static std::string GetFundPrivkeyFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of fundPrivkey field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetFundPrivkeyString(  // line separate
      const SignCetRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fund_privkey_);
  }
  /**
   * @brief Set json object to fundPrivkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFundPrivkeyString(  // line separate
      SignCetRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.fund_privkey_, json_value);
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
      const SignCetRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fund_tx_id_);
  }
  /**
   * @brief Set json object to fundTxId field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFundTxIdString(  // line separate
      SignCetRequest& obj,  // NOLINT
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
      const SignCetRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fund_vout_);
  }
  /**
   * @brief Set json object to fundVout field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFundVoutString(  // line separate
      SignCetRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.fund_vout_, json_value);
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
      const SignCetRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.local_fund_pubkey_);
  }
  /**
   * @brief Set json object to localFundPubkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetLocalFundPubkeyString(  // line separate
      SignCetRequest& obj,  // NOLINT
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
      const SignCetRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.remote_fund_pubkey_);
  }
  /**
   * @brief Set json object to remoteFundPubkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetRemoteFundPubkeyString(  // line separate
      SignCetRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.remote_fund_pubkey_, json_value);
  }

  /**
   * @brief Get of fundInputAmount
   * @return fundInputAmount
   */
  uint64_t GetFundInputAmount() const {
    return fund_input_amount_;
  }
  /**
   * @brief Set to fundInputAmount
   * @param[in] fund_input_amount    setting value.
   */
  void SetFundInputAmount(  // line separate
    const uint64_t& fund_input_amount) {  // NOLINT
    this->fund_input_amount_ = fund_input_amount;
  }
  /**
   * @brief Get data type of fundInputAmount
   * @return Data type of fundInputAmount
   */
  static std::string GetFundInputAmountFieldType() {
    return "uint64_t";
  }
  /**
   * @brief Get json string of fundInputAmount field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetFundInputAmountString(  // line separate
      const SignCetRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fund_input_amount_);
  }
  /**
   * @brief Set json object to fundInputAmount field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFundInputAmountString(  // line separate
      SignCetRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.fund_input_amount_, json_value);
  }

  /**
   * @brief Get of adaptorSignature
   * @return adaptorSignature
   */
  std::string GetAdaptorSignature() const {
    return adaptor_signature_;
  }
  /**
   * @brief Set to adaptorSignature
   * @param[in] adaptor_signature    setting value.
   */
  void SetAdaptorSignature(  // line separate
    const std::string& adaptor_signature) {  // NOLINT
    this->adaptor_signature_ = adaptor_signature;
  }
  /**
   * @brief Get data type of adaptorSignature
   * @return Data type of adaptorSignature
   */
  static std::string GetAdaptorSignatureFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of adaptorSignature field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetAdaptorSignatureString(  // line separate
      const SignCetRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.adaptor_signature_);
  }
  /**
   * @brief Set json object to adaptorSignature field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetAdaptorSignatureString(  // line separate
      SignCetRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.adaptor_signature_, json_value);
  }

  /**
   * @brief Get of oracleSignatures.
   * @return oracleSignatures
   */
  JsonValueVector<std::string>& GetOracleSignatures() {  // NOLINT
    return oracle_signatures_;
  }
  /**
   * @brief Set to oracleSignatures.
   * @param[in] oracle_signatures    setting value.
   */
  void SetOracleSignatures(  // line separate
      const JsonValueVector<std::string>& oracle_signatures) {  // NOLINT
    this->oracle_signatures_ = oracle_signatures;
  }
  /**
   * @brief Get data type of oracleSignatures.
   * @return Data type of oracleSignatures.
   */
  static std::string GetOracleSignaturesFieldType() {
    return "JsonValueVector<std::string>";  // NOLINT
  }
  /**
   * @brief Get json string of oracleSignatures field.
   * @param[in,out] obj     class object
   * @return JSON string.
   */
  static std::string GetOracleSignaturesString(  // line separate
      const SignCetRequest& obj) {  // NOLINT
    // Do not set to const, because substitution of member variables
    // may occur in pre / post processing inside Serialize
    return obj.oracle_signatures_.Serialize();
  }
  /**
   * @brief Set json object to oracleSignatures field.
   * @param[in,out] obj     class object
   * @param[in] json_value  JSON object
   */
  static void SetOracleSignaturesString(  // line separate
      SignCetRequest& obj,  // NOLINT
      const UniValue& json_value) {
    obj.oracle_signatures_.DeserializeUniValue(json_value);
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
      const SignCetRequestStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  SignCetRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using SignCetRequestMapTable =
    cfd::core::JsonTableMap<SignCetRequest>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const SignCetRequestMapTable& GetJsonMapper() const {  // NOLINT
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
   * @brief Get ignore item lists of JSON mapping.
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
  static SignCetRequestMapTable json_mapper;
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
   * @brief JsonAPI(fundPrivkey) value
   */
  std::string fund_privkey_ = "";
  /**
   * @brief JsonAPI(fundTxId) value
   */
  std::string fund_tx_id_ = "";
  /**
   * @brief JsonAPI(fundVout) value
   */
  uint32_t fund_vout_ = 0;
  /**
   * @brief JsonAPI(localFundPubkey) value
   */
  std::string local_fund_pubkey_ = "";
  /**
   * @brief JsonAPI(remoteFundPubkey) value
   */
  std::string remote_fund_pubkey_ = "";
  /**
   * @brief JsonAPI(fundInputAmount) value
   */
  uint64_t fund_input_amount_ = 0;
  /**
   * @brief JsonAPI(adaptorSignature) value
   */
  std::string adaptor_signature_ = "";
  /**
   * @brief JsonAPI(oracleSignatures) value
   */
  JsonValueVector<std::string> oracle_signatures_;  // NOLINT
};

// ------------------------------------------------------------------------
// SignCetResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (SignCetResponse) class
 */
class SignCetResponse
  : public cfd::core::JsonClassBase<SignCetResponse> {
 public:
  SignCetResponse() {
    CollectFieldName();
  }
  virtual ~SignCetResponse() {
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
      const SignCetResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.hex_);
  }
  /**
   * @brief Set json object to hex field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetHexString(  // line separate
      SignCetResponse& obj,  // NOLINT
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
      const SignCetResponseStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  SignCetResponseStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using SignCetResponseMapTable =
    cfd::core::JsonTableMap<SignCetResponse>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const SignCetResponseMapTable& GetJsonMapper() const {  // NOLINT
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
   * @brief Get ignore item lists of JSON mapping.
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
  static SignCetResponseMapTable json_mapper;
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
      const SignFundTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.prev_tx_id_);
  }
  /**
   * @brief Set json object to prevTxId field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetPrevTxIdString(  // line separate
      SignFundTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.prev_tx_id_, json_value);
  }

  /**
   * @brief Get of prevVout
   * @return prevVout
   */
  uint32_t GetPrevVout() const {
    return prev_vout_;
  }
  /**
   * @brief Set to prevVout
   * @param[in] prev_vout    setting value.
   */
  void SetPrevVout(  // line separate
    const uint32_t& prev_vout) {  // NOLINT
    this->prev_vout_ = prev_vout;
  }
  /**
   * @brief Get data type of prevVout
   * @return Data type of prevVout
   */
  static std::string GetPrevVoutFieldType() {
    return "uint32_t";
  }
  /**
   * @brief Get json string of prevVout field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetPrevVoutString(  // line separate
      const SignFundTransactionRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.prev_vout_);
  }
  /**
   * @brief Set json object to prevVout field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetPrevVoutString(  // line separate
      SignFundTransactionRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.prev_vout_, json_value);
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
   * @brief Get ignore item lists of JSON mapping.
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
   * @brief JsonAPI(prevTxId) value
   */
  std::string prev_tx_id_ = "";
  /**
   * @brief JsonAPI(prevVout) value
   */
  uint32_t prev_vout_ = 0;
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
   * @brief Get ignore item lists of JSON mapping.
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
// VerifyCetAdaptorSignatureRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (VerifyCetAdaptorSignatureRequest) class
 */
class VerifyCetAdaptorSignatureRequest
  : public cfd::core::JsonClassBase<VerifyCetAdaptorSignatureRequest> {
 public:
  VerifyCetAdaptorSignatureRequest() {
    CollectFieldName();
  }
  virtual ~VerifyCetAdaptorSignatureRequest() {
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
      const VerifyCetAdaptorSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.cet_hex_);
  }
  /**
   * @brief Set json object to cetHex field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetCetHexString(  // line separate
      VerifyCetAdaptorSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.cet_hex_, json_value);
  }

  /**
   * @brief Get of adaptorSignature
   * @return adaptorSignature
   */
  std::string GetAdaptorSignature() const {
    return adaptor_signature_;
  }
  /**
   * @brief Set to adaptorSignature
   * @param[in] adaptor_signature    setting value.
   */
  void SetAdaptorSignature(  // line separate
    const std::string& adaptor_signature) {  // NOLINT
    this->adaptor_signature_ = adaptor_signature;
  }
  /**
   * @brief Get data type of adaptorSignature
   * @return Data type of adaptorSignature
   */
  static std::string GetAdaptorSignatureFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of adaptorSignature field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetAdaptorSignatureString(  // line separate
      const VerifyCetAdaptorSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.adaptor_signature_);
  }
  /**
   * @brief Set json object to adaptorSignature field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetAdaptorSignatureString(  // line separate
      VerifyCetAdaptorSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.adaptor_signature_, json_value);
  }

  /**
   * @brief Get of adaptorProof
   * @return adaptorProof
   */
  std::string GetAdaptorProof() const {
    return adaptor_proof_;
  }
  /**
   * @brief Set to adaptorProof
   * @param[in] adaptor_proof    setting value.
   */
  void SetAdaptorProof(  // line separate
    const std::string& adaptor_proof) {  // NOLINT
    this->adaptor_proof_ = adaptor_proof;
  }
  /**
   * @brief Get data type of adaptorProof
   * @return Data type of adaptorProof
   */
  static std::string GetAdaptorProofFieldType() {
    return "std::string";
  }
  /**
   * @brief Get json string of adaptorProof field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetAdaptorProofString(  // line separate
      const VerifyCetAdaptorSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.adaptor_proof_);
  }
  /**
   * @brief Set json object to adaptorProof field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetAdaptorProofString(  // line separate
      VerifyCetAdaptorSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.adaptor_proof_, json_value);
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
      const VerifyCetAdaptorSignatureRequest& obj) {  // NOLINT
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
      VerifyCetAdaptorSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    obj.messages_.DeserializeUniValue(json_value);
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
      const VerifyCetAdaptorSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.local_fund_pubkey_);
  }
  /**
   * @brief Set json object to localFundPubkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetLocalFundPubkeyString(  // line separate
      VerifyCetAdaptorSignatureRequest& obj,  // NOLINT
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
      const VerifyCetAdaptorSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.remote_fund_pubkey_);
  }
  /**
   * @brief Set json object to remoteFundPubkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetRemoteFundPubkeyString(  // line separate
      VerifyCetAdaptorSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.remote_fund_pubkey_, json_value);
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
      const VerifyCetAdaptorSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.oracle_pubkey_);
  }
  /**
   * @brief Set json object to oraclePubkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetOraclePubkeyString(  // line separate
      VerifyCetAdaptorSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.oracle_pubkey_, json_value);
  }

  /**
   * @brief Get of oracleRValues.
   * @return oracleRValues
   */
  JsonValueVector<std::string>& GetOracleRValues() {  // NOLINT
    return oracle_r_values_;
  }
  /**
   * @brief Set to oracleRValues.
   * @param[in] oracle_r_values    setting value.
   */
  void SetOracleRValues(  // line separate
      const JsonValueVector<std::string>& oracle_r_values) {  // NOLINT
    this->oracle_r_values_ = oracle_r_values;
  }
  /**
   * @brief Get data type of oracleRValues.
   * @return Data type of oracleRValues.
   */
  static std::string GetOracleRValuesFieldType() {
    return "JsonValueVector<std::string>";  // NOLINT
  }
  /**
   * @brief Get json string of oracleRValues field.
   * @param[in,out] obj     class object
   * @return JSON string.
   */
  static std::string GetOracleRValuesString(  // line separate
      const VerifyCetAdaptorSignatureRequest& obj) {  // NOLINT
    // Do not set to const, because substitution of member variables
    // may occur in pre / post processing inside Serialize
    return obj.oracle_r_values_.Serialize();
  }
  /**
   * @brief Set json object to oracleRValues field.
   * @param[in,out] obj     class object
   * @param[in] json_value  JSON object
   */
  static void SetOracleRValuesString(  // line separate
      VerifyCetAdaptorSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    obj.oracle_r_values_.DeserializeUniValue(json_value);
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
      const VerifyCetAdaptorSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fund_tx_id_);
  }
  /**
   * @brief Set json object to fundTxId field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFundTxIdString(  // line separate
      VerifyCetAdaptorSignatureRequest& obj,  // NOLINT
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
      const VerifyCetAdaptorSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fund_vout_);
  }
  /**
   * @brief Set json object to fundVout field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFundVoutString(  // line separate
      VerifyCetAdaptorSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.fund_vout_, json_value);
  }

  /**
   * @brief Get of fundInputAmount
   * @return fundInputAmount
   */
  uint64_t GetFundInputAmount() const {
    return fund_input_amount_;
  }
  /**
   * @brief Set to fundInputAmount
   * @param[in] fund_input_amount    setting value.
   */
  void SetFundInputAmount(  // line separate
    const uint64_t& fund_input_amount) {  // NOLINT
    this->fund_input_amount_ = fund_input_amount;
  }
  /**
   * @brief Get data type of fundInputAmount
   * @return Data type of fundInputAmount
   */
  static std::string GetFundInputAmountFieldType() {
    return "uint64_t";
  }
  /**
   * @brief Get json string of fundInputAmount field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetFundInputAmountString(  // line separate
      const VerifyCetAdaptorSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fund_input_amount_);
  }
  /**
   * @brief Set json object to fundInputAmount field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFundInputAmountString(  // line separate
      VerifyCetAdaptorSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.fund_input_amount_, json_value);
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
      const VerifyCetAdaptorSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.verify_remote_);
  }
  /**
   * @brief Set json object to verifyRemote field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetVerifyRemoteString(  // line separate
      VerifyCetAdaptorSignatureRequest& obj,  // NOLINT
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
      const VerifyCetAdaptorSignatureRequestStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  VerifyCetAdaptorSignatureRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using VerifyCetAdaptorSignatureRequestMapTable =
    cfd::core::JsonTableMap<VerifyCetAdaptorSignatureRequest>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const VerifyCetAdaptorSignatureRequestMapTable& GetJsonMapper() const {  // NOLINT
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
   * @brief Get ignore item lists of JSON mapping.
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
  static VerifyCetAdaptorSignatureRequestMapTable json_mapper;
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
   * @brief JsonAPI(adaptorSignature) value
   */
  std::string adaptor_signature_ = "";
  /**
   * @brief JsonAPI(adaptorProof) value
   */
  std::string adaptor_proof_ = "";
  /**
   * @brief JsonAPI(messages) value
   */
  JsonValueVector<std::string> messages_;  // NOLINT
  /**
   * @brief JsonAPI(localFundPubkey) value
   */
  std::string local_fund_pubkey_ = "";
  /**
   * @brief JsonAPI(remoteFundPubkey) value
   */
  std::string remote_fund_pubkey_ = "";
  /**
   * @brief JsonAPI(oraclePubkey) value
   */
  std::string oracle_pubkey_ = "";
  /**
   * @brief JsonAPI(oracleRValues) value
   */
  JsonValueVector<std::string> oracle_r_values_;  // NOLINT
  /**
   * @brief JsonAPI(fundTxId) value
   */
  std::string fund_tx_id_ = "";
  /**
   * @brief JsonAPI(fundVout) value
   */
  uint32_t fund_vout_ = 0;
  /**
   * @brief JsonAPI(fundInputAmount) value
   */
  uint64_t fund_input_amount_ = 0;
  /**
   * @brief JsonAPI(verifyRemote) value
   */
  bool verify_remote_ = true;
};

// ------------------------------------------------------------------------
// VerifyCetAdaptorSignatureResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (VerifyCetAdaptorSignatureResponse) class
 */
class VerifyCetAdaptorSignatureResponse
  : public cfd::core::JsonClassBase<VerifyCetAdaptorSignatureResponse> {
 public:
  VerifyCetAdaptorSignatureResponse() {
    CollectFieldName();
  }
  virtual ~VerifyCetAdaptorSignatureResponse() {
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
      const VerifyCetAdaptorSignatureResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.valid_);
  }
  /**
   * @brief Set json object to valid field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetValidString(  // line separate
      VerifyCetAdaptorSignatureResponse& obj,  // NOLINT
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
      const VerifyCetAdaptorSignatureResponseStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  VerifyCetAdaptorSignatureResponseStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using VerifyCetAdaptorSignatureResponseMapTable =
    cfd::core::JsonTableMap<VerifyCetAdaptorSignatureResponse>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const VerifyCetAdaptorSignatureResponseMapTable& GetJsonMapper() const {  // NOLINT
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
   * @brief Get ignore item lists of JSON mapping.
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
  static VerifyCetAdaptorSignatureResponseMapTable json_mapper;
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
// VerifyCetAdaptorSignaturesRequest
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (VerifyCetAdaptorSignaturesRequest) class
 */
class VerifyCetAdaptorSignaturesRequest
  : public cfd::core::JsonClassBase<VerifyCetAdaptorSignaturesRequest> {
 public:
  VerifyCetAdaptorSignaturesRequest() {
    CollectFieldName();
  }
  virtual ~VerifyCetAdaptorSignaturesRequest() {
    // do nothing
  }
  /**
   * @brief collect field name.
   */
  static void CollectFieldName();

  /**
   * @brief Get of cetsHex.
   * @return cetsHex
   */
  JsonValueVector<std::string>& GetCetsHex() {  // NOLINT
    return cets_hex_;
  }
  /**
   * @brief Set to cetsHex.
   * @param[in] cets_hex    setting value.
   */
  void SetCetsHex(  // line separate
      const JsonValueVector<std::string>& cets_hex) {  // NOLINT
    this->cets_hex_ = cets_hex;
  }
  /**
   * @brief Get data type of cetsHex.
   * @return Data type of cetsHex.
   */
  static std::string GetCetsHexFieldType() {
    return "JsonValueVector<std::string>";  // NOLINT
  }
  /**
   * @brief Get json string of cetsHex field.
   * @param[in,out] obj     class object
   * @return JSON string.
   */
  static std::string GetCetsHexString(  // line separate
      const VerifyCetAdaptorSignaturesRequest& obj) {  // NOLINT
    // Do not set to const, because substitution of member variables
    // may occur in pre / post processing inside Serialize
    return obj.cets_hex_.Serialize();
  }
  /**
   * @brief Set json object to cetsHex field.
   * @param[in,out] obj     class object
   * @param[in] json_value  JSON object
   */
  static void SetCetsHexString(  // line separate
      VerifyCetAdaptorSignaturesRequest& obj,  // NOLINT
      const UniValue& json_value) {
    obj.cets_hex_.DeserializeUniValue(json_value);
  }

  /**
   * @brief Get of adaptorPairs.
   * @return adaptorPairs
   */
  JsonObjectVector<AdaptorPair, AdaptorPairStruct>& GetAdaptorPairs() {  // NOLINT
    return adaptor_pairs_;
  }
  /**
   * @brief Set to adaptorPairs.
   * @param[in] adaptor_pairs    setting value.
   */
  void SetAdaptorPairs(  // line separate
      const JsonObjectVector<AdaptorPair, AdaptorPairStruct>& adaptor_pairs) {  // NOLINT
    this->adaptor_pairs_ = adaptor_pairs;
  }
  /**
   * @brief Get data type of adaptorPairs.
   * @return Data type of adaptorPairs.
   */
  static std::string GetAdaptorPairsFieldType() {
    return "JsonObjectVector<AdaptorPair, AdaptorPairStruct>";  // NOLINT
  }
  /**
   * @brief Get json string of adaptorPairs field.
   * @param[in,out] obj     class object
   * @return JSON string.
   */
  static std::string GetAdaptorPairsString(  // line separate
      const VerifyCetAdaptorSignaturesRequest& obj) {  // NOLINT
    // Do not set to const, because substitution of member variables
    // may occur in pre / post processing inside Serialize
    return obj.adaptor_pairs_.Serialize();
  }
  /**
   * @brief Set json object to adaptorPairs field.
   * @param[in,out] obj     class object
   * @param[in] json_value  JSON object
   */
  static void SetAdaptorPairsString(  // line separate
      VerifyCetAdaptorSignaturesRequest& obj,  // NOLINT
      const UniValue& json_value) {
    obj.adaptor_pairs_.DeserializeUniValue(json_value);
  }

  /**
   * @brief Get of messagesList.
   * @return messagesList
   */
  JsonObjectVector<Messages, MessagesStruct>& GetMessagesList() {  // NOLINT
    return messages_list_;
  }
  /**
   * @brief Set to messagesList.
   * @param[in] messages_list    setting value.
   */
  void SetMessagesList(  // line separate
      const JsonObjectVector<Messages, MessagesStruct>& messages_list) {  // NOLINT
    this->messages_list_ = messages_list;
  }
  /**
   * @brief Get data type of messagesList.
   * @return Data type of messagesList.
   */
  static std::string GetMessagesListFieldType() {
    return "JsonObjectVector<Messages, MessagesStruct>";  // NOLINT
  }
  /**
   * @brief Get json string of messagesList field.
   * @param[in,out] obj     class object
   * @return JSON string.
   */
  static std::string GetMessagesListString(  // line separate
      const VerifyCetAdaptorSignaturesRequest& obj) {  // NOLINT
    // Do not set to const, because substitution of member variables
    // may occur in pre / post processing inside Serialize
    return obj.messages_list_.Serialize();
  }
  /**
   * @brief Set json object to messagesList field.
   * @param[in,out] obj     class object
   * @param[in] json_value  JSON object
   */
  static void SetMessagesListString(  // line separate
      VerifyCetAdaptorSignaturesRequest& obj,  // NOLINT
      const UniValue& json_value) {
    obj.messages_list_.DeserializeUniValue(json_value);
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
      const VerifyCetAdaptorSignaturesRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.local_fund_pubkey_);
  }
  /**
   * @brief Set json object to localFundPubkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetLocalFundPubkeyString(  // line separate
      VerifyCetAdaptorSignaturesRequest& obj,  // NOLINT
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
      const VerifyCetAdaptorSignaturesRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.remote_fund_pubkey_);
  }
  /**
   * @brief Set json object to remoteFundPubkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetRemoteFundPubkeyString(  // line separate
      VerifyCetAdaptorSignaturesRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.remote_fund_pubkey_, json_value);
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
      const VerifyCetAdaptorSignaturesRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.oracle_pubkey_);
  }
  /**
   * @brief Set json object to oraclePubkey field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetOraclePubkeyString(  // line separate
      VerifyCetAdaptorSignaturesRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.oracle_pubkey_, json_value);
  }

  /**
   * @brief Get of oracleRValues.
   * @return oracleRValues
   */
  JsonValueVector<std::string>& GetOracleRValues() {  // NOLINT
    return oracle_r_values_;
  }
  /**
   * @brief Set to oracleRValues.
   * @param[in] oracle_r_values    setting value.
   */
  void SetOracleRValues(  // line separate
      const JsonValueVector<std::string>& oracle_r_values) {  // NOLINT
    this->oracle_r_values_ = oracle_r_values;
  }
  /**
   * @brief Get data type of oracleRValues.
   * @return Data type of oracleRValues.
   */
  static std::string GetOracleRValuesFieldType() {
    return "JsonValueVector<std::string>";  // NOLINT
  }
  /**
   * @brief Get json string of oracleRValues field.
   * @param[in,out] obj     class object
   * @return JSON string.
   */
  static std::string GetOracleRValuesString(  // line separate
      const VerifyCetAdaptorSignaturesRequest& obj) {  // NOLINT
    // Do not set to const, because substitution of member variables
    // may occur in pre / post processing inside Serialize
    return obj.oracle_r_values_.Serialize();
  }
  /**
   * @brief Set json object to oracleRValues field.
   * @param[in,out] obj     class object
   * @param[in] json_value  JSON object
   */
  static void SetOracleRValuesString(  // line separate
      VerifyCetAdaptorSignaturesRequest& obj,  // NOLINT
      const UniValue& json_value) {
    obj.oracle_r_values_.DeserializeUniValue(json_value);
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
      const VerifyCetAdaptorSignaturesRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fund_tx_id_);
  }
  /**
   * @brief Set json object to fundTxId field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFundTxIdString(  // line separate
      VerifyCetAdaptorSignaturesRequest& obj,  // NOLINT
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
      const VerifyCetAdaptorSignaturesRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fund_vout_);
  }
  /**
   * @brief Set json object to fundVout field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFundVoutString(  // line separate
      VerifyCetAdaptorSignaturesRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.fund_vout_, json_value);
  }

  /**
   * @brief Get of fundInputAmount
   * @return fundInputAmount
   */
  uint64_t GetFundInputAmount() const {
    return fund_input_amount_;
  }
  /**
   * @brief Set to fundInputAmount
   * @param[in] fund_input_amount    setting value.
   */
  void SetFundInputAmount(  // line separate
    const uint64_t& fund_input_amount) {  // NOLINT
    this->fund_input_amount_ = fund_input_amount;
  }
  /**
   * @brief Get data type of fundInputAmount
   * @return Data type of fundInputAmount
   */
  static std::string GetFundInputAmountFieldType() {
    return "uint64_t";
  }
  /**
   * @brief Get json string of fundInputAmount field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetFundInputAmountString(  // line separate
      const VerifyCetAdaptorSignaturesRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fund_input_amount_);
  }
  /**
   * @brief Set json object to fundInputAmount field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFundInputAmountString(  // line separate
      VerifyCetAdaptorSignaturesRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.fund_input_amount_, json_value);
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
      const VerifyCetAdaptorSignaturesRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.verify_remote_);
  }
  /**
   * @brief Set json object to verifyRemote field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetVerifyRemoteString(  // line separate
      VerifyCetAdaptorSignaturesRequest& obj,  // NOLINT
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
      const VerifyCetAdaptorSignaturesRequestStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  VerifyCetAdaptorSignaturesRequestStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using VerifyCetAdaptorSignaturesRequestMapTable =
    cfd::core::JsonTableMap<VerifyCetAdaptorSignaturesRequest>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const VerifyCetAdaptorSignaturesRequestMapTable& GetJsonMapper() const {  // NOLINT
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
   * @brief Get ignore item lists of JSON mapping.
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
  static VerifyCetAdaptorSignaturesRequestMapTable json_mapper;
  /**
   * @brief field name list.
   */
  static std::vector<std::string> item_list;
  /**
   * @brief ignore item list.
   */
  std::set<std::string> ignore_items;

  /**
   * @brief JsonAPI(cetsHex) value
   */
  JsonValueVector<std::string> cets_hex_;  // NOLINT
  /**
   * @brief JsonAPI(adaptorPairs) value
   */
  JsonObjectVector<AdaptorPair, AdaptorPairStruct> adaptor_pairs_;  // NOLINT
  /**
   * @brief JsonAPI(messagesList) value
   */
  JsonObjectVector<Messages, MessagesStruct> messages_list_;  // NOLINT
  /**
   * @brief JsonAPI(localFundPubkey) value
   */
  std::string local_fund_pubkey_ = "";
  /**
   * @brief JsonAPI(remoteFundPubkey) value
   */
  std::string remote_fund_pubkey_ = "";
  /**
   * @brief JsonAPI(oraclePubkey) value
   */
  std::string oracle_pubkey_ = "";
  /**
   * @brief JsonAPI(oracleRValues) value
   */
  JsonValueVector<std::string> oracle_r_values_;  // NOLINT
  /**
   * @brief JsonAPI(fundTxId) value
   */
  std::string fund_tx_id_ = "";
  /**
   * @brief JsonAPI(fundVout) value
   */
  uint32_t fund_vout_ = 0;
  /**
   * @brief JsonAPI(fundInputAmount) value
   */
  uint64_t fund_input_amount_ = 0;
  /**
   * @brief JsonAPI(verifyRemote) value
   */
  bool verify_remote_ = true;
};

// ------------------------------------------------------------------------
// VerifyCetAdaptorSignaturesResponse
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (VerifyCetAdaptorSignaturesResponse) class
 */
class VerifyCetAdaptorSignaturesResponse
  : public cfd::core::JsonClassBase<VerifyCetAdaptorSignaturesResponse> {
 public:
  VerifyCetAdaptorSignaturesResponse() {
    CollectFieldName();
  }
  virtual ~VerifyCetAdaptorSignaturesResponse() {
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
      const VerifyCetAdaptorSignaturesResponse& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.valid_);
  }
  /**
   * @brief Set json object to valid field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetValidString(  // line separate
      VerifyCetAdaptorSignaturesResponse& obj,  // NOLINT
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
      const VerifyCetAdaptorSignaturesResponseStruct& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  VerifyCetAdaptorSignaturesResponseStruct ConvertToStruct()  const;

 protected:
  /**
   * @brief definition type of Map table.
   */
  using VerifyCetAdaptorSignaturesResponseMapTable =
    cfd::core::JsonTableMap<VerifyCetAdaptorSignaturesResponse>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const VerifyCetAdaptorSignaturesResponseMapTable& GetJsonMapper() const {  // NOLINT
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
   * @brief Get ignore item lists of JSON mapping.
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
  static VerifyCetAdaptorSignaturesResponseMapTable json_mapper;
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
   * @brief Get of prevVout
   * @return prevVout
   */
  uint32_t GetPrevVout() const {
    return prev_vout_;
  }
  /**
   * @brief Set to prevVout
   * @param[in] prev_vout    setting value.
   */
  void SetPrevVout(  // line separate
    const uint32_t& prev_vout) {  // NOLINT
    this->prev_vout_ = prev_vout;
  }
  /**
   * @brief Get data type of prevVout
   * @return Data type of prevVout
   */
  static std::string GetPrevVoutFieldType() {
    return "uint32_t";
  }
  /**
   * @brief Get json string of prevVout field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetPrevVoutString(  // line separate
      const VerifyFundTxSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.prev_vout_);
  }
  /**
   * @brief Set json object to prevVout field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetPrevVoutString(  // line separate
      VerifyFundTxSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.prev_vout_, json_value);
  }

  /**
   * @brief Get of fundInputAmount
   * @return fundInputAmount
   */
  uint64_t GetFundInputAmount() const {
    return fund_input_amount_;
  }
  /**
   * @brief Set to fundInputAmount
   * @param[in] fund_input_amount    setting value.
   */
  void SetFundInputAmount(  // line separate
    const uint64_t& fund_input_amount) {  // NOLINT
    this->fund_input_amount_ = fund_input_amount;
  }
  /**
   * @brief Get data type of fundInputAmount
   * @return Data type of fundInputAmount
   */
  static std::string GetFundInputAmountFieldType() {
    return "uint64_t";
  }
  /**
   * @brief Get json string of fundInputAmount field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetFundInputAmountString(  // line separate
      const VerifyFundTxSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fund_input_amount_);
  }
  /**
   * @brief Set json object to fundInputAmount field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFundInputAmountString(  // line separate
      VerifyFundTxSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.fund_input_amount_, json_value);
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
   * @brief Get ignore item lists of JSON mapping.
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
   * @brief JsonAPI(prevVout) value
   */
  uint32_t prev_vout_ = 0;
  /**
   * @brief JsonAPI(fundInputAmount) value
   */
  uint64_t fund_input_amount_ = 0;
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
   * @brief Get ignore item lists of JSON mapping.
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
   * @brief Get of fundInputAmount
   * @return fundInputAmount
   */
  uint64_t GetFundInputAmount() const {
    return fund_input_amount_;
  }
  /**
   * @brief Set to fundInputAmount
   * @param[in] fund_input_amount    setting value.
   */
  void SetFundInputAmount(  // line separate
    const uint64_t& fund_input_amount) {  // NOLINT
    this->fund_input_amount_ = fund_input_amount;
  }
  /**
   * @brief Get data type of fundInputAmount
   * @return Data type of fundInputAmount
   */
  static std::string GetFundInputAmountFieldType() {
    return "uint64_t";
  }
  /**
   * @brief Get json string of fundInputAmount field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string GetFundInputAmountString(  // line separate
      const VerifyRefundTxSignatureRequest& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.fund_input_amount_);
  }
  /**
   * @brief Set json object to fundInputAmount field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void SetFundInputAmountString(  // line separate
      VerifyRefundTxSignatureRequest& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.fund_input_amount_, json_value);
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
   * @brief Get ignore item lists of JSON mapping.
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
   * @brief JsonAPI(fundInputAmount) value
   */
  uint64_t fund_input_amount_ = 0;
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
   * @brief Get ignore item lists of JSON mapping.
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
