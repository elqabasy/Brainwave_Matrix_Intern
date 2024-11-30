#ifndef ATM_BANK_DB_HPP
#define ATM_BANK_DB_HPP

#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class BankDB {
    public:
        // Constructor
        BankDB();
        
        // Methods
        bool validateCard(const string& cardNumber);
        double getBalance(const string& cardNumber);
        unordered_map<string, pair<string, double>> accounts;
        void updateBalance(const string& cardNumber, double amount);
        bool validatePIN(const string& cardNumber, const string& pin);
};

#endif // ATM_BANK_DB_HPP
