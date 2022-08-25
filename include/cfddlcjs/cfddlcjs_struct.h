// Copyright 2020 CryptoGarage
/**
 * @file cfddlcjs_struct.h
 *
 * @brief Struct mapping file. (auto generate)
 */
#ifndef CFD_DLC_JS_INCLUDE_CFDDLCJS_CFDDLCJS_STRUCT_H_
#define CFD_DLC_JS_INCLUDE_CFDDLCJS_CFDDLCJS_STRUCT_H_

#include <cstdint>
#include <set>
#include <string>
#include <vector>

// clang-format off
// @formatter:off
namespace cfd {
namespace dlc {
namespace js {
namespace api {

// ------------------------------------------------------------------------
// InnerErrorResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief InnerErrorResponseStruct struct
 */
struct InnerErrorResponseStruct {
  uint32_t code = 0;         //!< code  // NOLINT
  std::string type = "";     //!< type  // NOLINT
  std::string message = "";  //!< message  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// MessagesStruct
// ------------------------------------------------------------------------
/**
 * @brief MessagesStruct struct
 */
struct MessagesStruct {
  std::vector<std::string> messages;  //!< messages  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// TxInInfoRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief TxInInfoRequestStruct struct
 */
struct TxInInfoRequestStruct {
  std::string txid = "";              //!< txid  // NOLINT
  uint32_t vout = 0;                  //!< vout  // NOLINT
  std::string redeem_script = "";     //!< redeem_script  // NOLINT
  uint32_t max_witness_length = 108;  //!< max_witness_length  // NOLINT
  uint64_t serial_id = 0;             //!< serial_id  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// AddSignatureToFundTransactionRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief AddSignatureToFundTransactionRequestStruct struct
 */
struct AddSignatureToFundTransactionRequestStruct {
  std::string fund_tx_hex = "";  //!< fund_tx_hex  // NOLINT
  std::string signature = "";    //!< signature  // NOLINT
  std::string prev_tx_id = "";   //!< prev_tx_id  // NOLINT
  uint32_t prev_vout = 0;        //!< prev_vout  // NOLINT
  std::string pubkey = "";       //!< pubkey  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// AddSignatureToFundTransactionResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief AddSignatureToFundTransactionResponseStruct struct
 */
struct AddSignatureToFundTransactionResponseStruct {
  std::string hex = "";  //!< hex  // NOLINT
  cfd::dlc::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// AddSignaturesToRefundTxRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief AddSignaturesToRefundTxRequestStruct struct
 */
struct AddSignaturesToRefundTxRequestStruct {
  std::string refund_tx_hex = "";       //!< refund_tx_hex  // NOLINT
  std::vector<std::string> signatures;  //!< signatures  // NOLINT
  std::string fund_tx_id = "";          //!< fund_tx_id  // NOLINT
  uint32_t fund_vout = 0;               //!< fund_vout  // NOLINT
  std::string offer_fund_pubkey = "";   //!< offer_fund_pubkey  // NOLINT
  std::string accept_fund_pubkey = "";  //!< accept_fund_pubkey  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// AddSignaturesToRefundTxResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief AddSignaturesToRefundTxResponseStruct struct
 */
struct AddSignaturesToRefundTxResponseStruct {
  std::string hex = "";  //!< hex  // NOLINT
  cfd::dlc::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// CreateCetRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief CreateCetRequestStruct struct
 */
struct CreateCetRequestStruct {
  std::string offer_fund_pubkey = "";     //!< offer_fund_pubkey  // NOLINT
  std::string accept_fund_pubkey = "";    //!< accept_fund_pubkey  // NOLINT
  std::string offer_final_address = "";   //!< offer_final_address  // NOLINT
  std::string accept_final_address = "";  //!< accept_final_address  // NOLINT
  uint64_t offer_payout = 0;              //!< offer_payout  // NOLINT
  uint64_t accept_payout = 0;             //!< accept_payout  // NOLINT
  uint64_t offer_payout_serial_id = 0;    //!< offer_payout_serial_id  // NOLINT
  uint64_t accept_payout_serial_id = 0;   //!< accept_payout_serial_id  // NOLINT
  std::string fund_tx_id = "";            //!< fund_tx_id  // NOLINT
  uint32_t fund_vout = 0;                 //!< fund_vout  // NOLINT
  uint64_t lock_time = 0;                 //!< lock_time  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// CreateCetResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief CreateCetResponseStruct struct
 */
struct CreateCetResponseStruct {
  std::string hex = "";  //!< hex  // NOLINT
  cfd::dlc::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// CreateCetAdaptorSignatureRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief CreateCetAdaptorSignatureRequestStruct struct
 */
struct CreateCetAdaptorSignatureRequestStruct {
  std::string cet_hex = "";                  //!< cet_hex  // NOLINT
  std::string privkey = "";                  //!< privkey  // NOLINT
  std::string fund_tx_id = "";               //!< fund_tx_id  // NOLINT
  uint32_t fund_vout = 0;                    //!< fund_vout  // NOLINT
  std::string offer_fund_pubkey = "";        //!< offer_fund_pubkey  // NOLINT
  std::string accept_fund_pubkey = "";       //!< accept_fund_pubkey  // NOLINT
  std::string oracle_pubkey = "";            //!< oracle_pubkey  // NOLINT
  std::vector<std::string> oracle_r_values;  //!< oracle_r_values  // NOLINT
  uint64_t fund_input_amount = 0;            //!< fund_input_amount  // NOLINT
  std::vector<std::string> messages;         //!< messages  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// CreateCetAdaptorSignatureResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief CreateCetAdaptorSignatureResponseStruct struct
 */
struct CreateCetAdaptorSignatureResponseStruct {
  std::string signature = "";  //!< signature  // NOLINT
  cfd::dlc::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// CreateCetAdaptorSignaturesRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief CreateCetAdaptorSignaturesRequestStruct struct
 */
struct CreateCetAdaptorSignaturesRequestStruct {
  std::vector<std::string> cets_hex;          //!< cets_hex  // NOLINT
  std::string privkey = "";                   //!< privkey  // NOLINT
  std::string fund_tx_id = "";                //!< fund_tx_id  // NOLINT
  uint32_t fund_vout = 0;                     //!< fund_vout  // NOLINT
  std::string offer_fund_pubkey = "";         //!< offer_fund_pubkey  // NOLINT
  std::string accept_fund_pubkey = "";        //!< accept_fund_pubkey  // NOLINT
  std::string oracle_pubkey = "";             //!< oracle_pubkey  // NOLINT
  std::vector<std::string> oracle_r_values;   //!< oracle_r_values  // NOLINT
  uint64_t fund_input_amount = 0;             //!< fund_input_amount  // NOLINT
  std::vector<MessagesStruct> messages_list;  //!< messages_list  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// CreateCetAdaptorSignaturesResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief CreateCetAdaptorSignaturesResponseStruct struct
 */
struct CreateCetAdaptorSignaturesResponseStruct {
  std::vector<std::string> adaptor_signatures;  //!< adaptor_signatures  // NOLINT
  cfd::dlc::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// PayoutRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief PayoutRequestStruct struct
 */
struct PayoutRequestStruct {
  uint64_t offer = 0;   //!< offer  // NOLINT
  uint64_t accept = 0;  //!< accept  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// CreateDlcTransactionsRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief CreateDlcTransactionsRequestStruct struct
 */
struct CreateDlcTransactionsRequestStruct {
  std::vector<PayoutRequestStruct> payouts;          //!< payouts  // NOLINT
  std::string offer_fund_pubkey = "";                //!< offer_fund_pubkey  // NOLINT
  std::string offer_payout_script_pubkey = "";       //!< offer_payout_script_pubkey  // NOLINT
  uint64_t offer_payout_serial_id = 0;               //!< offer_payout_serial_id  // NOLINT
  std::string accept_fund_pubkey = "";               //!< accept_fund_pubkey  // NOLINT
  std::string accept_payout_script_pubkey = "";      //!< accept_payout_script_pubkey  // NOLINT
  uint64_t accept_payout_serial_id = 0;              //!< accept_payout_serial_id  // NOLINT
  uint64_t offer_input_amount = 0;                   //!< offer_input_amount  // NOLINT
  uint64_t offer_collateral_amount = 0;              //!< offer_collateral_amount  // NOLINT
  uint64_t accept_input_amount = 0;                  //!< accept_input_amount  // NOLINT
  uint64_t accept_collateral_amount = 0;             //!< accept_collateral_amount  // NOLINT
  uint64_t refund_locktime = 0;                      //!< refund_locktime  // NOLINT
  std::vector<TxInInfoRequestStruct> offer_inputs;   //!< offer_inputs  // NOLINT
  std::string offer_change_script_pubkey = "";       //!< offer_change_script_pubkey  // NOLINT
  uint64_t offer_change_serial_id = 0;               //!< offer_change_serial_id  // NOLINT
  std::vector<TxInInfoRequestStruct> accept_inputs;  //!< accept_inputs  // NOLINT
  std::string accept_change_script_pubkey = "";      //!< accept_change_script_pubkey  // NOLINT
  uint64_t accept_change_serial_id = 0;              //!< accept_change_serial_id  // NOLINT
  uint32_t fee_rate = 0;                             //!< fee_rate  // NOLINT
  uint64_t fund_output_serial_id = 0;                //!< fund_output_serial_id  // NOLINT
  uint64_t cet_lock_time = 0;                        //!< cet_lock_time  // NOLINT
  uint64_t fund_lock_time = 0;                       //!< fund_lock_time  // NOLINT
  std::string option_dest = "";                      //!< option_dest  // NOLINT
  uint64_t option_premium = 0;                       //!< option_premium  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// CreateDlcTransactionsResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief CreateDlcTransactionsResponseStruct struct
 */
struct CreateDlcTransactionsResponseStruct {
  std::string fund_tx_hex = "";            //!< fund_tx_hex  // NOLINT
  std::vector<std::string> cets_hex;       //!< cets_hex  // NOLINT
  std::string refund_tx_hex = "";          //!< refund_tx_hex  // NOLINT
  std::string funding_script_pubkey = "";  //!< funding_script_pubkey  // NOLINT
  uint32_t fund_vout = 0;                  //!< fund_vout  // NOLINT
  cfd::dlc::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// CreateFundTransactionRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief CreateFundTransactionRequestStruct struct
 */
struct CreateFundTransactionRequestStruct {
  std::string offer_pubkey = "";                     //!< offer_pubkey  // NOLINT
  std::string accept_pubkey = "";                    //!< accept_pubkey  // NOLINT
  uint64_t offer_collateral_amount = 0;              //!< offer_collateral_amount  // NOLINT
  uint64_t accept_collateral_amount = 0;             //!< accept_collateral_amount  // NOLINT
  std::vector<TxInInfoRequestStruct> offer_inputs;   //!< offer_inputs  // NOLINT
  std::vector<TxInInfoRequestStruct> accept_inputs;  //!< accept_inputs  // NOLINT
  std::string offer_change_script_pubkey = "";       //!< offer_change_script_pubkey  // NOLINT
  uint64_t offer_change_serial_id = 0;               //!< offer_change_serial_id  // NOLINT
  std::string accept_change_script_pubkey = "";      //!< accept_change_script_pubkey  // NOLINT
  uint64_t accept_change_serial_id = 0;              //!< accept_change_serial_id  // NOLINT
  std::string offer_payout_script_pubkey = "";       //!< offer_payout_script_pubkey  // NOLINT
  uint64_t offer_payout_serial_id = 0;               //!< offer_payout_serial_id  // NOLINT
  std::string accept_payout_script_pubkey = "";      //!< accept_payout_script_pubkey  // NOLINT
  uint64_t accept_payout_serial_id = 0;              //!< accept_payout_serial_id  // NOLINT
  int64_t fee_rate = 1;                              //!< fee_rate  // NOLINT
  uint64_t fund_output_serial_id = 0;                //!< fund_output_serial_id  // NOLINT
  std::string option_dest = "";                      //!< option_dest  // NOLINT
  uint64_t option_premium = 0;                       //!< option_premium  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// CreateFundTransactionResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief CreateFundTransactionResponseStruct struct
 */
struct CreateFundTransactionResponseStruct {
  std::string hex = "";  //!< hex  // NOLINT
  cfd::dlc::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// CreateRefundTransactionRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief CreateRefundTransactionRequestStruct struct
 */
struct CreateRefundTransactionRequestStruct {
  std::string offer_final_script_pubkey = "";   //!< offer_final_script_pubkey  // NOLINT
  std::string accept_final_script_pubkey = "";  //!< accept_final_script_pubkey  // NOLINT
  uint64_t offer_amount = 0;                    //!< offer_amount  // NOLINT
  uint64_t accept_amount = 0;                   //!< accept_amount  // NOLINT
  uint64_t lock_time = 0;                       //!< lock_time  // NOLINT
  std::string fund_tx_id = "";                  //!< fund_tx_id  // NOLINT
  uint32_t fund_vout = 0;                       //!< fund_vout  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// CreateRefundTransactionResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief CreateRefundTransactionResponseStruct struct
 */
struct CreateRefundTransactionResponseStruct {
  std::string hex = "";  //!< hex  // NOLINT
  cfd::dlc::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// GetRawFundTxSignatureRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief GetRawFundTxSignatureRequestStruct struct
 */
struct GetRawFundTxSignatureRequestStruct {
  std::string fund_tx_hex = "";  //!< fund_tx_hex  // NOLINT
  std::string privkey = "";      //!< privkey  // NOLINT
  std::string prev_tx_id = "";   //!< prev_tx_id  // NOLINT
  uint32_t prev_vout = 0;        //!< prev_vout  // NOLINT
  uint64_t amount = 0;           //!< amount  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// GetRawFundTxSignatureResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief GetRawFundTxSignatureResponseStruct struct
 */
struct GetRawFundTxSignatureResponseStruct {
  std::string hex = "";  //!< hex  // NOLINT
  cfd::dlc::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// GetRawRefundTxSignatureRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief GetRawRefundTxSignatureRequestStruct struct
 */
struct GetRawRefundTxSignatureRequestStruct {
  std::string refund_tx_hex = "";       //!< refund_tx_hex  // NOLINT
  std::string privkey = "";             //!< privkey  // NOLINT
  std::string fund_tx_id = "";          //!< fund_tx_id  // NOLINT
  uint32_t fund_vout = 0;               //!< fund_vout  // NOLINT
  std::string offer_fund_pubkey = "";   //!< offer_fund_pubkey  // NOLINT
  std::string accept_fund_pubkey = "";  //!< accept_fund_pubkey  // NOLINT
  uint64_t fund_input_amount = 0;       //!< fund_input_amount  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// GetRawRefundTxSignatureResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief GetRawRefundTxSignatureResponseStruct struct
 */
struct GetRawRefundTxSignatureResponseStruct {
  std::string hex = "";  //!< hex  // NOLINT
  cfd::dlc::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// SignCetRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief SignCetRequestStruct struct
 */
struct SignCetRequestStruct {
  std::string cet_hex = "";                    //!< cet_hex  // NOLINT
  std::string fund_privkey = "";               //!< fund_privkey  // NOLINT
  std::string fund_tx_id = "";                 //!< fund_tx_id  // NOLINT
  uint32_t fund_vout = 0;                      //!< fund_vout  // NOLINT
  std::string offer_fund_pubkey = "";          //!< offer_fund_pubkey  // NOLINT
  std::string accept_fund_pubkey = "";         //!< accept_fund_pubkey  // NOLINT
  uint64_t fund_input_amount = 0;              //!< fund_input_amount  // NOLINT
  std::string adaptor_signature = "";          //!< adaptor_signature  // NOLINT
  std::vector<std::string> oracle_signatures;  //!< oracle_signatures  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// SignCetResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief SignCetResponseStruct struct
 */
struct SignCetResponseStruct {
  std::string hex = "";  //!< hex  // NOLINT
  cfd::dlc::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// SignFundTransactionRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief SignFundTransactionRequestStruct struct
 */
struct SignFundTransactionRequestStruct {
  std::string fund_tx_hex = "";  //!< fund_tx_hex  // NOLINT
  std::string privkey = "";      //!< privkey  // NOLINT
  std::string prev_tx_id = "";   //!< prev_tx_id  // NOLINT
  uint32_t prev_vout = 0;        //!< prev_vout  // NOLINT
  uint64_t amount = 0;           //!< amount  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// SignFundTransactionResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief SignFundTransactionResponseStruct struct
 */
struct SignFundTransactionResponseStruct {
  std::string hex = "";  //!< hex  // NOLINT
  cfd::dlc::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// VerifyCetAdaptorSignatureRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief VerifyCetAdaptorSignatureRequestStruct struct
 */
struct VerifyCetAdaptorSignatureRequestStruct {
  std::string cet_hex = "";                  //!< cet_hex  // NOLINT
  std::string adaptor_signature = "";        //!< adaptor_signature  // NOLINT
  std::vector<std::string> messages;         //!< messages  // NOLINT
  std::string offer_fund_pubkey = "";        //!< offer_fund_pubkey  // NOLINT
  std::string accept_fund_pubkey = "";       //!< accept_fund_pubkey  // NOLINT
  std::string oracle_pubkey = "";            //!< oracle_pubkey  // NOLINT
  std::vector<std::string> oracle_r_values;  //!< oracle_r_values  // NOLINT
  std::string fund_tx_id = "";               //!< fund_tx_id  // NOLINT
  uint32_t fund_vout = 0;                    //!< fund_vout  // NOLINT
  uint64_t fund_input_amount = 0;            //!< fund_input_amount  // NOLINT
  bool verify_accept = true;                 //!< verify_accept  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// VerifyCetAdaptorSignatureResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief VerifyCetAdaptorSignatureResponseStruct struct
 */
struct VerifyCetAdaptorSignatureResponseStruct {
  bool valid = false;  //!< valid  // NOLINT
  cfd::dlc::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// VerifyCetAdaptorSignaturesRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief VerifyCetAdaptorSignaturesRequestStruct struct
 */
struct VerifyCetAdaptorSignaturesRequestStruct {
  std::vector<std::string> cets_hex;            //!< cets_hex  // NOLINT
  std::vector<std::string> adaptor_signatures;  //!< adaptor_signatures  // NOLINT
  std::vector<MessagesStruct> messages_list;    //!< messages_list  // NOLINT
  std::string offer_fund_pubkey = "";           //!< offer_fund_pubkey  // NOLINT
  std::string accept_fund_pubkey = "";          //!< accept_fund_pubkey  // NOLINT
  std::string oracle_pubkey = "";               //!< oracle_pubkey  // NOLINT
  std::vector<std::string> oracle_r_values;     //!< oracle_r_values  // NOLINT
  std::string fund_tx_id = "";                  //!< fund_tx_id  // NOLINT
  uint32_t fund_vout = 0;                       //!< fund_vout  // NOLINT
  uint64_t fund_input_amount = 0;               //!< fund_input_amount  // NOLINT
  bool verify_accept = true;                    //!< verify_accept  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// VerifyCetAdaptorSignaturesResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief VerifyCetAdaptorSignaturesResponseStruct struct
 */
struct VerifyCetAdaptorSignaturesResponseStruct {
  bool valid = false;  //!< valid  // NOLINT
  cfd::dlc::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// VerifyFundTxSignatureRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief VerifyFundTxSignatureRequestStruct struct
 */
struct VerifyFundTxSignatureRequestStruct {
  std::string fund_tx_hex = "";    //!< fund_tx_hex  // NOLINT
  std::string signature = "";      //!< signature  // NOLINT
  std::string pubkey = "";         //!< pubkey  // NOLINT
  std::string prev_tx_id = "";     //!< prev_tx_id  // NOLINT
  uint32_t prev_vout = 0;          //!< prev_vout  // NOLINT
  uint64_t fund_input_amount = 0;  //!< fund_input_amount  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// VerifyFundTxSignatureResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief VerifyFundTxSignatureResponseStruct struct
 */
struct VerifyFundTxSignatureResponseStruct {
  bool valid = false;  //!< valid  // NOLINT
  cfd::dlc::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// VerifyRefundTxSignatureRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief VerifyRefundTxSignatureRequestStruct struct
 */
struct VerifyRefundTxSignatureRequestStruct {
  std::string refund_tx_hex = "";       //!< refund_tx_hex  // NOLINT
  std::string signature = "";           //!< signature  // NOLINT
  std::string offer_fund_pubkey = "";   //!< offer_fund_pubkey  // NOLINT
  std::string accept_fund_pubkey = "";  //!< accept_fund_pubkey  // NOLINT
  std::string fund_tx_id = "";          //!< fund_tx_id  // NOLINT
  uint32_t fund_vout = 0;               //!< fund_vout  // NOLINT
  uint64_t fund_input_amount = 0;       //!< fund_input_amount  // NOLINT
  bool verify_accept = true;            //!< verify_accept  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// VerifyRefundTxSignatureResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief VerifyRefundTxSignatureResponseStruct struct
 */
struct VerifyRefundTxSignatureResponseStruct {
  bool valid = false;  //!< valid  // NOLINT
  cfd::dlc::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

}  // namespace api
}  // namespace js
}  // namespace dlc
}  // namespace cfd

// @formatter:on
// clang-format on

#endif  // CFD_DLC_JS_INCLUDE_CFDDLCJS_CFDDLCJS_STRUCT_H_
