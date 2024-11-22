#ifndef ATM_DEPOSIT_TRANSACTION_HPP
#define ATM_DEPOSIT_TRANSACTION_HPP

#include "transactions/Transaction.hpp"
#include "atm/ATM.hpp"

class DepositTransaction : public Transaction {
    private:
        ATM& atm;
        double amount;

    public:
        // Constructor
        DepositTransaction(ATM& atm, double amount);

        // Methods
        void execute() override;
};

#endif // ATM_DEPOSIT_TRANSACTION_HPP
