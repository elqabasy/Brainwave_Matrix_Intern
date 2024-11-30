#ifndef ATM_CONSTANTS_HPP
#define ATM_CONSTANTS_HPP

#include <iostream>
using namespace std;

namespace ATMConstants {
    const string TECH_PASSWORD = "tech123";
    const string ISSUE_REPORTED_MESSAGE = "Issue reported.";
    const string CARD_INSERT_PROMPT = "Please enter your PIN:";
    const string STATUS_CHECKED_MESSAGE = "ATM status checked.";
    const string DEPOSIT_SUCCESS_MESSAGE = "Deposit successful.";
    const string INSUFFICIENT_FUNDS_MESSAGE = "Insufficient funds.";
    const string WITHDRAW_SUCCESS_MESSAGE = "Withdrawal successful.";
    const string INVALID_PIN_MESSAGE = "Invalid PIN. Please try again.";
    const string INVALID_CARD_MESSAGE = "Invalid card. Please try again.";
    const string MAINTENANCE_SCHEDULED_MESSAGE = "Maintenance scheduled on: ";
    const string VAULT_INSUFFICIENT_FUNDS_MESSAGE = "Vault has insufficient funds.";
    const string PIN_VERIFIED_MESSAGE = "PIN Verified. Choose an option: 1) Withdraw 2) Deposit 3) Transfer 4) Change PIN";
}

#endif // ATM_CONSTANTS_HPP
