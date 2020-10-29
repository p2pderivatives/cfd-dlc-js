import inquirer from "inquirer";

export enum InitialInputNames {
  LocalCollateral = "Local Collateral",
  RemoteCollateral = "Remote Collateral",
  Refund = "RefundTime",
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
    name: InitialInputNames.Refund,
    message: "Choose refund date and time",
  },
  {
    type: "number",
    name: InitialInputNames.FeeRate,
    message: "Enter fee rate",
    default: 2,
  },
];
