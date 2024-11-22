#ifndef VAULT_HPP
#define VAULT_HPP

class Vault {
    private:
        double money;

    public:
        // Constructor
        Vault();

        // Methods
        double checkBalance() const;
        void addMoney(double amount);
        bool withdrawMoney(double amount);
};

#endif // VAULT_HPP
