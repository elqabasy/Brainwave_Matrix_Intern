#include "Bank.hpp"
#include "Utils.hpp"
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <fstream>
using namespace std;




Bank::Bank() {
    loadData();
}

void Bank::loadData() {
    // TODO: Load users, accounts, and transactions from files
    cout << "Data loaded successfully!" << endl;
}

void Bank::saveData() {
    // TODO: Save users, accounts, and transactions to files
    cout << "Data saved successfully!" << endl;
}

void Bank::createUser(const string& name, const string& email) {
    int id = Utils::generateId();
    users.emplace_back(id, name, email);
    Utils::logEvent("Created User: " + name);
}

void Bank::createAccount(int userId, double initialDeposit) {
    int accountId = Utils::generateId();
    accounts.emplace_back(accountId, userId, initialDeposit);
    Utils::logEvent("Created Account: " + to_string(accountId));
}

void Bank::deposit(int accountId, double amount) {
    for (auto& acc : accounts) {
        if (acc.getId() == accountId) {
            acc.deposit(amount);
            Utils::logEvent("Deposited " + to_string(amount) + " to Account " + to_string(accountId));
            return;
        }
    }
    throw runtime_error("Account not found");
}

void Bank::withdraw(int accountId, double amount) {
    for (auto& acc : accounts) {
        if (acc.getId() == accountId) {
            acc.withdraw(amount);
            Utils::logEvent("Withdrew " + to_string(amount) + " from Account " + to_string(accountId));
            return;
        }
    }
    throw runtime_error("Account not found");
}

void Bank::transferMoney(int fromAccountId, int toAccountId, double amount) {
    auto fromAccount = find_if(accounts.begin(), accounts.end(), [&](const Account& acc) {
        return acc.getId() == fromAccountId;
    });

    auto toAccount = find_if(accounts.begin(), accounts.end(), [&](const Account& acc) {
        return acc.getId() == toAccountId;
    });

    if (fromAccount == accounts.end() || toAccount == accounts.end()) {
        throw runtime_error("Account not found");
    }

    fromAccount->withdraw(amount);
    toAccount->deposit(amount);

    transactions.emplace_back(Utils::generateId(), fromAccountId, toAccountId, amount, "Transfer");
    Utils::logEvent("Transferred " + to_string(amount) + " from Account " + to_string(fromAccountId) + " to Account " + to_string(toAccountId));
}



#include "Bank.hpp"
#include <iostream>
#include <iomanip>

void Bank::showUserDetails(int userId) {
    auto it = find_if(users.begin(), users.end(), [=](const User& user) {
        return user.getId() == userId;
    });

    if (it == users.end()) {
        throw runtime_error("User not found.");
    }

    cout << "User ID: " << it->getId() << "\n"
              << "Name: " << it->getName() << "\n"
              << "Email: " << it->getEmail() << "\n";

    cout << "Accounts:\n";
    for (const auto& account : accounts) {
        if (account.getOwnerId() == userId) {
            cout << "  Account ID: " << account.getId()
                      << ", Balance: " << fixed << setprecision(2)
                      << account.getBalance() << "\n";
        }
    }
}

void Bank::listAllAccounts() {
    cout << "All Accounts:\n";
    for (const auto& account : accounts) {
        cout << "  Account ID: " << account.getId()
                  << ", Owner ID: " << account.getOwnerId()
                  << ", Balance: " << fixed << setprecision(2)
                  << account.getBalance() << "\n";
    }
}

void Bank::listTransactionHistory(int accountId) {
    cout << "Transaction History for Account ID: " << accountId << "\n";
    for (const auto& transaction : transactions) {
        if (transaction.getFromAccountId() == accountId || transaction.getToAccountId() == accountId) {
            cout << transaction.toString() << "\n";
        }
    }
}
