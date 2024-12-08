#ifndef TRANSACTION_HPP
#define TRANSACTION_HPP

#include <string>
#include <iostream>
using namespace std;

class Transaction {
    private:
        int _id;
        string _type;
        double _amount;
        int _toAccountId;
        int _fromAccountId;

    public:
        // Constructor
        Transaction(int id, int fromAccountId, int toAccountId, double amount, const string& type);

        // getters
        int getId() const;
        int getFromAccountId() const;
        int getToAccountId() const; 

        // methods
        string toString() const;
};

#endif // TRANSACTION_HPP
