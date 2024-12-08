#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

class Account {
    private:
        int _id;
        int _ownerId;
        double _balance;

    public:
        // Constructor
        Account(int id, int ownerId, double balance);

        // getters
        int getId() const;
        int getOwnerId() const;
        double getBalance() const;

        // methods
        void deposit(double amount);
        void withdraw(double amount);
};

#endif // ACCOUNT_HPP
