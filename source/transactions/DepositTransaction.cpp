// source/transactions/DepositTransactions.cpp


#include "transactions/DepositTransaction.hpp"

DepositTransaction::DepositTransaction(ATM& atm, double amount) : atm(atm), amount(amount) {}

void DepositTransaction::execute() {
    atm.getVault().addMoney(amount);
    double balance = atm.getBankDB().getBalance(atm.getCurrentCard());
    atm.getBankDB().updateBalance(atm.getCurrentCard(), balance + amount);
    atm.getReceiptPrinter().printReceipt("Deposited: " + to_string(amount) + "\nNew Balance: " + to_string(atm.getBankDB().getBalance(atm.getCurrentCard())));
    atm.getScreen().display("Deposit successful.");
    atm.getSoundUnit().playSound("Deposit successful sound");
    atm.getLogger().log("Deposit successful for card: " + atm.getCurrentCard() + ", amount: " + to_string(amount));
}
