// source/components/BankDB.cpp

#include "components/BankDB.hpp"

BankDB::BankDB() {
    // Simulate some bank accounts
    accounts["DC123"] = {"1234", 1000.0}; // Card number, PIN, Balance
}

bool BankDB::validateCard(const std::string& cardNumber) {
    return accounts.find(cardNumber) != accounts.end();
}

bool BankDB::validatePIN(const std::string& cardNumber, const std::string& pin) {
    return accounts[cardNumber].first == pin;
}

double BankDB::getBalance(const std::string& cardNumber) {
    return accounts[cardNumber].second;
}

void BankDB::updateBalance(const std::string& cardNumber, double amount) {
    accounts[cardNumber].second = amount;
}
