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
// TxInRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief TxInRequestStruct struct
 */
struct TxInRequestStruct {
  std::string txid = "";  //!< txid  // NOLINT
  uint32_t vout = 0;      //!< vout  // NOLINT
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
// AddSignaturesToCetRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief AddSignaturesToCetRequestStruct struct
 */
struct AddSignaturesToCetRequestStruct {
  std::string cet_hex = "";             //!< cet_hex  // NOLINT
  std::vector<std::string> signatures;  //!< signatures  // NOLINT
  std::string fund_tx_id = "";          //!< fund_tx_id  // NOLINT
  uint32_t fund_vout = 0;               //!< fund_vout  // NOLINT
  std::string local_fund_pubkey = "";   //!< local_fund_pubkey  // NOLINT
  std::string remote_fund_pubkey = "";  //!< remote_fund_pubkey  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// AddSignaturesToCetResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief AddSignaturesToCetResponseStruct struct
 */
struct AddSignaturesToCetResponseStruct {
  std::string hex = "";  //!< hex  // NOLINT
  cfd::dlc::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// AddSignaturesToMutualClosingTxRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief AddSignaturesToMutualClosingTxRequestStruct struct
 */
struct AddSignaturesToMutualClosingTxRequestStruct {
  std::string mutual_closing_tx_hex = "";  //!< mutual_closing_tx_hex  // NOLINT
  std::vector<std::string> signatures;     //!< signatures  // NOLINT
  std::string fund_tx_id = "";             //!< fund_tx_id  // NOLINT
  uint32_t fund_vout = 0;                  //!< fund_vout  // NOLINT
  std::string local_fund_pubkey = "";      //!< local_fund_pubkey  // NOLINT
  std::string remote_fund_pubkey = "";     //!< remote_fund_pubkey  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// AddSignaturesToMutualClosingTxResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief AddSignaturesToMutualClosingTxResponseStruct struct
 */
struct AddSignaturesToMutualClosingTxResponseStruct {
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
  std::string local_fund_pubkey = "";   //!< local_fund_pubkey  // NOLINT
  std::string remote_fund_pubkey = "";  //!< remote_fund_pubkey  // NOLINT
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
  std::string local_fund_pubkey = "";        //!< local_fund_pubkey  // NOLINT
  std::string local_sweep_pubkey = "";       //!< local_sweep_pubkey  // NOLINT
  std::string remote_sweep_pubkey = "";      //!< remote_sweep_pubkey  // NOLINT
  std::string remote_final_address = "";     //!< remote_final_address  // NOLINT
  std::string oracle_pubkey = "";            //!< oracle_pubkey  // NOLINT
  std::vector<std::string> oracle_r_points;  //!< oracle_r_points  // NOLINT
  std::vector<std::string> messages;         //!< messages  // NOLINT
  uint32_t csv_delay = 0;                    //!< csv_delay  // NOLINT
  uint64_t local_payout = 0;                 //!< local_payout  // NOLINT
  uint64_t remote_payout = 0;                //!< remote_payout  // NOLINT
  int64_t fee_rate = 1;                      //!< fee_rate  // NOLINT
  std::string fund_tx_id = "";               //!< fund_tx_id  // NOLINT
  uint32_t fund_vout = 0;                    //!< fund_vout  // NOLINT
  uint64_t maturity_time = 0;                //!< maturity_time  // NOLINT
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
// CreateClosingTransactionRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief CreateClosingTransactionRequestStruct struct
 */
struct CreateClosingTransactionRequestStruct {
  std::string address = "";    //!< address  // NOLINT
  uint64_t amount = 0;         //!< amount  // NOLINT
  std::string cet_tx_id = "";  //!< cet_tx_id  // NOLINT
  uint32_t cet_vout = 0;       //!< cet_vout  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// CreateClosingTransactionResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief CreateClosingTransactionResponseStruct struct
 */
struct CreateClosingTransactionResponseStruct {
  std::string hex = "";  //!< hex  // NOLINT
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
  uint64_t local = 0;                 //!< local  // NOLINT
  uint64_t remote = 0;                //!< remote  // NOLINT
  std::vector<std::string> messages;  //!< messages  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// CreateDlcTransactionsRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief CreateDlcTransactionsRequestStruct struct
 */
struct CreateDlcTransactionsRequestStruct {
  std::vector<PayoutRequestStruct> outcomes;     //!< outcomes  // NOLINT
  std::vector<std::string> oracle_r_points;      //!< oracle_r_points  // NOLINT
  std::string oracle_pubkey = "";                //!< oracle_pubkey  // NOLINT
  std::string local_fund_pubkey = "";            //!< local_fund_pubkey  // NOLINT
  std::string local_sweep_pubkey = "";           //!< local_sweep_pubkey  // NOLINT
  std::string local_final_address = "";          //!< local_final_address  // NOLINT
  std::string remote_fund_pubkey = "";           //!< remote_fund_pubkey  // NOLINT
  std::string remote_sweep_pubkey = "";          //!< remote_sweep_pubkey  // NOLINT
  std::string remote_final_address = "";         //!< remote_final_address  // NOLINT
  uint64_t local_input_amount = 0;               //!< local_input_amount  // NOLINT
  uint64_t local_collateral_amount = 0;          //!< local_collateral_amount  // NOLINT
  uint64_t remote_input_amount = 0;              //!< remote_input_amount  // NOLINT
  uint64_t remote_collateral_amount = 0;         //!< remote_collateral_amount  // NOLINT
  uint64_t csv_delay = 0;                        //!< csv_delay  // NOLINT
  uint64_t refund_locktime = 0;                  //!< refund_locktime  // NOLINT
  std::vector<TxInRequestStruct> local_inputs;   //!< local_inputs  // NOLINT
  std::string local_change_address = "";         //!< local_change_address  // NOLINT
  std::vector<TxInRequestStruct> remote_inputs;  //!< remote_inputs  // NOLINT
  std::string remote_change_address = "";        //!< remote_change_address  // NOLINT
  uint32_t fee_rate = 0;                         //!< fee_rate  // NOLINT
  uint64_t maturity_time = 0;                    //!< maturity_time  // NOLINT
  std::string option_dest = "";                  //!< option_dest  // NOLINT
  uint64_t option_premium = 0;                   //!< option_premium  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// CreateDlcTransactionsResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief CreateDlcTransactionsResponseStruct struct
 */
struct CreateDlcTransactionsResponseStruct {
  std::string fund_tx_hex = "";              //!< fund_tx_hex  // NOLINT
  std::vector<std::string> local_cets_hex;   //!< local_cets_hex  // NOLINT
  std::vector<std::string> remote_cets_hex;  //!< remote_cets_hex  // NOLINT
  std::string refund_tx_hex = "";            //!< refund_tx_hex  // NOLINT
  cfd::dlc::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// TxOutRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief TxOutRequestStruct struct
 */
struct TxOutRequestStruct {
  uint64_t amount = 0;       //!< amount  // NOLINT
  std::string address = "";  //!< address  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// CreateFundTransactionRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief CreateFundTransactionRequestStruct struct
 */
struct CreateFundTransactionRequestStruct {
  std::string local_pubkey = "";                 //!< local_pubkey  // NOLINT
  std::string remote_pubkey = "";                //!< remote_pubkey  // NOLINT
  uint64_t output_amount = 0;                    //!< output_amount  // NOLINT
  std::vector<TxInRequestStruct> local_inputs;   //!< local_inputs  // NOLINT
  TxOutRequestStruct local_change;               //!< local_change  // NOLINT
  std::vector<TxInRequestStruct> remote_inputs;  //!< remote_inputs  // NOLINT
  TxOutRequestStruct remote_change;              //!< remote_change  // NOLINT
  int64_t fee_rate = 1;                          //!< fee_rate  // NOLINT
  std::string option_dest = "";                  //!< option_dest  // NOLINT
  uint64_t option_premium = 0;                   //!< option_premium  // NOLINT
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
// CreateMutualClosingTransactionRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief CreateMutualClosingTransactionRequestStruct struct
 */
struct CreateMutualClosingTransactionRequestStruct {
  std::string local_final_address = "";   //!< local_final_address  // NOLINT
  std::string remote_final_address = "";  //!< remote_final_address  // NOLINT
  uint64_t local_amount = 0;              //!< local_amount  // NOLINT
  uint64_t remote_amount = 0;             //!< remote_amount  // NOLINT
  int64_t fee_rate = 1;                   //!< fee_rate  // NOLINT
  std::string fund_tx_id = "";            //!< fund_tx_id  // NOLINT
  uint32_t fund_vout = 0;                 //!< fund_vout  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// CreateMutualClosingTransactionResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief CreateMutualClosingTransactionResponseStruct struct
 */
struct CreateMutualClosingTransactionResponseStruct {
  std::string hex = "";  //!< hex  // NOLINT
  cfd::dlc::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// CreatePenaltyTransactionRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief CreatePenaltyTransactionRequestStruct struct
 */
struct CreatePenaltyTransactionRequestStruct {
  std::string final_address = "";  //!< final_address  // NOLINT
  uint64_t amount = 0;             //!< amount  // NOLINT
  std::string cet_tx_id = "";      //!< cet_tx_id  // NOLINT
  uint32_t cet_vout = 0;           //!< cet_vout  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// CreatePenaltyTransactionResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief CreatePenaltyTransactionResponseStruct struct
 */
struct CreatePenaltyTransactionResponseStruct {
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
  std::string local_final_address = "";   //!< local_final_address  // NOLINT
  std::string remote_final_address = "";  //!< remote_final_address  // NOLINT
  uint64_t local_amount = 0;              //!< local_amount  // NOLINT
  uint64_t remote_amount = 0;             //!< remote_amount  // NOLINT
  uint64_t lock_time = 0;                 //!< lock_time  // NOLINT
  std::string fund_tx_id = "";            //!< fund_tx_id  // NOLINT
  uint32_t fund_vout = 0;                 //!< fund_vout  // NOLINT
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
// GetRawCetSignatureRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief GetRawCetSignatureRequestStruct struct
 */
struct GetRawCetSignatureRequestStruct {
  std::string cet_hex = "";             //!< cet_hex  // NOLINT
  std::string privkey = "";             //!< privkey  // NOLINT
  std::string fund_tx_id = "";          //!< fund_tx_id  // NOLINT
  uint32_t fund_vout = 0;               //!< fund_vout  // NOLINT
  std::string local_fund_pubkey = "";   //!< local_fund_pubkey  // NOLINT
  std::string remote_fund_pubkey = "";  //!< remote_fund_pubkey  // NOLINT
  uint64_t fund_input_amount = 0;       //!< fund_input_amount  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// GetRawCetSignatureResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief GetRawCetSignatureResponseStruct struct
 */
struct GetRawCetSignatureResponseStruct {
  std::string hex = "";  //!< hex  // NOLINT
  cfd::dlc::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// GetRawCetSignaturesRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief GetRawCetSignaturesRequestStruct struct
 */
struct GetRawCetSignaturesRequestStruct {
  std::vector<std::string> cets_hex;    //!< cets_hex  // NOLINT
  std::string privkey = "";             //!< privkey  // NOLINT
  std::string fund_tx_id = "";          //!< fund_tx_id  // NOLINT
  uint32_t fund_vout = 0;               //!< fund_vout  // NOLINT
  std::string local_fund_pubkey = "";   //!< local_fund_pubkey  // NOLINT
  std::string remote_fund_pubkey = "";  //!< remote_fund_pubkey  // NOLINT
  uint64_t fund_input_amount = 0;       //!< fund_input_amount  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// GetRawCetSignaturesResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief GetRawCetSignaturesResponseStruct struct
 */
struct GetRawCetSignaturesResponseStruct {
  std::vector<std::string> hex;  //!< hex  // NOLINT
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
// GetRawMutualClosingTxSignatureRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief GetRawMutualClosingTxSignatureRequestStruct struct
 */
struct GetRawMutualClosingTxSignatureRequestStruct {
  std::string mutual_closing_hex = "";  //!< mutual_closing_hex  // NOLINT
  std::string privkey = "";             //!< privkey  // NOLINT
  std::string fund_tx_id = "";          //!< fund_tx_id  // NOLINT
  uint32_t fund_vout = 0;               //!< fund_vout  // NOLINT
  std::string local_fund_pubkey = "";   //!< local_fund_pubkey  // NOLINT
  std::string remote_fund_pubkey = "";  //!< remote_fund_pubkey  // NOLINT
  uint64_t fund_input_amount = 0;       //!< fund_input_amount  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// GetRawMutualClosingTxSignatureResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief GetRawMutualClosingTxSignatureResponseStruct struct
 */
struct GetRawMutualClosingTxSignatureResponseStruct {
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
  std::string local_fund_pubkey = "";   //!< local_fund_pubkey  // NOLINT
  std::string remote_fund_pubkey = "";  //!< remote_fund_pubkey  // NOLINT
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
// GetSchnorrPublicNonceRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief GetSchnorrPublicNonceRequestStruct struct
 */
struct GetSchnorrPublicNonceRequestStruct {
  std::string k_value = "";  //!< k_value  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// GetSchnorrPublicNonceResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief GetSchnorrPublicNonceResponseStruct struct
 */
struct GetSchnorrPublicNonceResponseStruct {
  std::string hex = "";  //!< hex  // NOLINT
  cfd::dlc::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// SchnorrSignRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief SchnorrSignRequestStruct struct
 */
struct SchnorrSignRequestStruct {
  std::string privkey = "";  //!< privkey  // NOLINT
  std::string k_value = "";  //!< k_value  // NOLINT
  std::string message = "";  //!< message  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// SchnorrSignResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief SchnorrSignResponseStruct struct
 */
struct SchnorrSignResponseStruct {
  std::string hex = "";  //!< hex  // NOLINT
  cfd::dlc::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// SignClosingTransactionRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief SignClosingTransactionRequestStruct struct
 */
struct SignClosingTransactionRequestStruct {
  std::string closing_tx_hex = "";           //!< closing_tx_hex  // NOLINT
  std::string local_fund_privkey = "";       //!< local_fund_privkey  // NOLINT
  std::string local_sweep_pubkey = "";       //!< local_sweep_pubkey  // NOLINT
  std::string remote_sweep_pubkey = "";      //!< remote_sweep_pubkey  // NOLINT
  std::string oracle_pubkey = "";            //!< oracle_pubkey  // NOLINT
  std::vector<std::string> oracle_r_points;  //!< oracle_r_points  // NOLINT
  std::vector<std::string> messages;         //!< messages  // NOLINT
  uint64_t csv_delay = 0;                    //!< csv_delay  // NOLINT
  std::vector<std::string> oracle_sigs;      //!< oracle_sigs  // NOLINT
  std::string cet_tx_id = "";                //!< cet_tx_id  // NOLINT
  uint32_t cet_vout = 0;                     //!< cet_vout  // NOLINT
  uint64_t amount = 0;                       //!< amount  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// SignClosingTransactionResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief SignClosingTransactionResponseStruct struct
 */
struct SignClosingTransactionResponseStruct {
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
// VerifyCetSignatureRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief VerifyCetSignatureRequestStruct struct
 */
struct VerifyCetSignatureRequestStruct {
  std::string cet_hex = "";             //!< cet_hex  // NOLINT
  std::string signature = "";           //!< signature  // NOLINT
  std::string local_fund_pubkey = "";   //!< local_fund_pubkey  // NOLINT
  std::string remote_fund_pubkey = "";  //!< remote_fund_pubkey  // NOLINT
  std::string fund_tx_id = "";          //!< fund_tx_id  // NOLINT
  uint32_t fund_vout = 0;               //!< fund_vout  // NOLINT
  uint64_t fund_input_amount = 0;       //!< fund_input_amount  // NOLINT
  bool verify_remote = true;            //!< verify_remote  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// VerifyCetSignatureResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief VerifyCetSignatureResponseStruct struct
 */
struct VerifyCetSignatureResponseStruct {
  bool valid = false;  //!< valid  // NOLINT
  cfd::dlc::js::api::InnerErrorResponseStruct error;   //!< error information
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// VerifyCetSignaturesRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief VerifyCetSignaturesRequestStruct struct
 */
struct VerifyCetSignaturesRequestStruct {
  std::vector<std::string> cets_hex;    //!< cets_hex  // NOLINT
  std::vector<std::string> signatures;  //!< signatures  // NOLINT
  std::string local_fund_pubkey = "";   //!< local_fund_pubkey  // NOLINT
  std::string remote_fund_pubkey = "";  //!< remote_fund_pubkey  // NOLINT
  std::string fund_tx_id = "";          //!< fund_tx_id  // NOLINT
  uint32_t fund_vout = 0;               //!< fund_vout  // NOLINT
  uint64_t fund_input_amount = 0;       //!< fund_input_amount  // NOLINT
  bool verify_remote = true;            //!< verify_remote  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// VerifyCetSignaturesResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief VerifyCetSignaturesResponseStruct struct
 */
struct VerifyCetSignaturesResponseStruct {
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
// VerifyMutualClosingTxSignatureRequestStruct
// ------------------------------------------------------------------------
/**
 * @brief VerifyMutualClosingTxSignatureRequestStruct struct
 */
struct VerifyMutualClosingTxSignatureRequestStruct {
  std::string mutual_closing_hex = "";  //!< mutual_closing_hex  // NOLINT
  std::string signature = "";           //!< signature  // NOLINT
  std::string local_fund_pubkey = "";   //!< local_fund_pubkey  // NOLINT
  std::string remote_fund_pubkey = "";  //!< remote_fund_pubkey  // NOLINT
  std::string fund_tx_id = "";          //!< fund_tx_id  // NOLINT
  uint32_t fund_vout = 0;               //!< fund_vout  // NOLINT
  uint64_t fund_input_amount = 0;       //!< fund_input_amount  // NOLINT
  bool verify_remote = true;            //!< verify_remote  // NOLINT
  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.
};

// ------------------------------------------------------------------------
// VerifyMutualClosingTxSignatureResponseStruct
// ------------------------------------------------------------------------
/**
 * @brief VerifyMutualClosingTxSignatureResponseStruct struct
 */
struct VerifyMutualClosingTxSignatureResponseStruct {
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
  std::string local_fund_pubkey = "";   //!< local_fund_pubkey  // NOLINT
  std::string remote_fund_pubkey = "";  //!< remote_fund_pubkey  // NOLINT
  std::string fund_tx_id = "";          //!< fund_tx_id  // NOLINT
  uint32_t fund_vout = 0;               //!< fund_vout  // NOLINT
  uint64_t fund_input_amount = 0;       //!< fund_input_amount  // NOLINT
  bool verify_remote = true;            //!< verify_remote  // NOLINT
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
