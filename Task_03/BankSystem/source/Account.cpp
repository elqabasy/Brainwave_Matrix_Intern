#include "Account.hpp"
#include <stdexcept>

Account::Account(int id, int ownerId, double balance) : _id(id), _ownerId(ownerId), _balance(balance) {}

int Account::getId() const { return _id; }

int Account::getOwnerId() const { return _ownerId; }

double Account::getBalance() const { return _balance; }

void Account::deposit(double amount) {
    if (amount <= 0) throw std::invalid_argument("Deposit amount must be positive.");
    _balance += amount;
}

void Account::withdraw(double amount) {
    if (amount <= 0) throw std::invalid_argument("Withdrawal amount must be positive.");
    if (amount > _balance) throw std::runtime_error("Insufficient balance.");
    _balance -= amount;
}
