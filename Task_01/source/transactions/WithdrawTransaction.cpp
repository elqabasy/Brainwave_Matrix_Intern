// source/transactions/WithdrawalTransactions.cpp

#include "transactions/WithdrawTransaction.hpp"



WithdrawTransaction::WithdrawTransaction(ATM& atm, double amount) : atm(atm), amount(amount) {}

void WithdrawTransaction::execute() {
    double balance = atm.getBankDB().getBalance(atm.getCurrentCard());
    if (balance >= amount) {
        if (atm.getVault().withdrawMoney(amount)) {
            atm.getBankDB().updateBalance(atm.getCurrentCard(), balance - amount);
            atm.getCashDispenser().dispenseCash(amount);
            atm.getReceiptPrinter().printReceipt("Withdrawn: " + to_string(amount) + "\nRemaining Balance: " + to_string(atm.getBankDB().getBalance(atm.getCurrentCard())));
            atm.getScreen().display("Withdrawal successful.");
            atm.getSoundUnit().playSound("Withdrawal successful sound");
            atm.getLogger().log("Withdrawal successful for card: " + atm.getCurrentCard() + ", amount: " + to_string(amount));
        } else {
            atm.getScreen().display("Vault has insufficient funds.");
            atm.getSoundUnit().playSound("Error sound");
            atm.getLogger().log("Vault has insufficient funds for withdrawal");
        }
    } else {
        atm.getScreen().display("Insufficient funds.");
        atm.getSoundUnit().playSound("Error sound");
        atm.getLogger().log("Insufficient funds for withdrawal");
    }
}
