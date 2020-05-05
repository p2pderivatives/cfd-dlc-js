import inquirer from "inquirer";

export enum OutcomeInputNames {
  Message = "Message",
  LocalPayout = "Local Payout",
  RemotePayout = "Remote Payout",
  AddMore = "Add more",
}

export const OutcomeInputs: inquirer.Question[] = [
  {
    name: OutcomeInputNames.Message,
    message: "Enter the outcome message",
  },
  {
    name: OutcomeInputNames.LocalPayout,
    message: "Enter the local payout",
    type: "number",
  },
  {
    name: OutcomeInputNames.RemotePayout,
    message: "Enter the remote payout",
    type: "number",
  },
  {
    name: OutcomeInputNames.AddMore,
    message: "Enter another outcome?",
    type: "confirm",
    default: false,
  },
];
