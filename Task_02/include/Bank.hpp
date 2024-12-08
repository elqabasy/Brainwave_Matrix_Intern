#ifndef BANK_HPP
#define BANK_HPP

#include <vector>
#include <string>
#include "User.hpp"
#include <iostream>
#include "Account.hpp"
#include "Transaction.hpp"
using namespace std;

class Bank {
    private:
        vector<User> users;
        vector<Account> accounts;
        vector<Transaction> transactions;

    public:
        // Constructor
        Bank();
        
        // Data
        void loadData();
        void saveData();

        // Operations
        void createUser(const string& name, const string& email);
        void createAccount(int userId, double initialDeposit);
        void transferMoney(int fromAccountId, int toAccountId, double amount);
        void deposit(int accountId, double amount);
        void withdraw(int accountId, double amount);

        // display methods
        void listAllAccounts();
        void showUserDetails(int userId);
        void listTransactionHistory(int accountId);
};

#endif // BANK_HPP
