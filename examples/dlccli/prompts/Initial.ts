import inquirer from "inquirer";

export enum InitialInputNames {
  LocalCollateral = "Local Collateral",
  RemoteCollateral = "Remote Collateral",
  Maturity = "Maturity time",
  Refund = "RefundTime",
  CsvDelay = "CSV delay",
  FeeRate = "Fee Rate",
}

export const InitialInputs: inquirer.Question[] = [
  {
    type: "number",
    name: InitialInputNames.LocalCollateral,
    message: "Enter local collateral",
    default: 1,
  },
  {
    type: "number",
    name: InitialInputNames.RemoteCollateral,
    message: "Enter remote collateral",
    default: 1,
  },
  {
    type: "datepicker",
    name: InitialInputNames.Maturity,
    message: "Choose contract maturity date and time",
  },
  {
    type: "datepicker",
    name: InitialInputNames.Refund,
    message: "Choose refund date and time",
  },
  {
    type: "number",
    name: InitialInputNames.CsvDelay,
    message: "Enter CSV delay",
    default: 1,
  },
  {
    type: "number",
    name: InitialInputNames.FeeRate,
    message: "Enter fee rate",
    default: 2,
  },
];
