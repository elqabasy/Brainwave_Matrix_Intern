// source/components/vault.cpp
#include "components/Vault.hpp"




Vault::Vault() : money(100000.0) {}

void Vault::addMoney(double amount) {
    money += amount;
}

bool Vault::withdrawMoney(double amount) {
    if (money >= amount) {
        money -= amount;
        return true;
    } else {
        return false;
    }
}

double Vault::checkBalance() const {
    return money;
}
