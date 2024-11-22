#ifndef ATM_WITHDRAW_TRANSACTION_HPP
#define ATM_WITHDRAW_TRANSACTION_HPP

#include "atm/ATM.hpp"
#include "transactions/Transaction.hpp"

class WithdrawTransaction : public Transaction {
    private:
        ATM& atm;
        double amount;

    public:
        // Constructor
        WithdrawTransaction(ATM& atm, double amount);

        // Methods
        void execute() override;
};

#endif // ATM_WITHDRAW_TRANSACTION_HPP
