// source/components/vault.cpp
#include "components/Vault.hpp"




Vault::Vault() : _money(100000.0) {}

void Vault::addMoney(double amount) {
    _money += amount;
}

bool Vault::withdrawMoney(double amount) {
    if (_money >= amount) {
        _money -= amount;
        return true;
    } else {
        return false;
    }
}

double Vault::checkBalance() const {
    return _money;
}
