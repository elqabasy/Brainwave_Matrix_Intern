#ifndef ATM_TRANSACTION_HPP
#define ATM_TRANSACTION_HPP

class Transaction {
    public:
        virtual void execute() = 0;
        virtual ~Transaction() = default;
};

#endif // ATM_TRANSACTION_HPP
