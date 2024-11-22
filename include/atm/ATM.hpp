#ifndef ATM_ATM_HPP
#define ATM_ATM_HPP

#include <iostream>
using namespace std;




#include "atm/ATMInfo.hpp"
#include "utils/Logger.hpp"
#include "components/Vault.hpp"
#include "components/BankDB.hpp"
#include "utils/ATMConstants.hpp"
#include "components/SoundUnit.hpp"
#include "components/CardReader.hpp"
#include "components/ATMScreen.hpp"
#include "utils/TechnicalSupport.hpp"
#include "transactions/Transaction.hpp"
#include "components/CashDispenser.hpp"
#include "components/ReceiptPrinter.hpp"

class ATM : public ATMInfo {
    private:
        // Private data
        string managedBy;
        string currentCard;
        bool authenticated;
        bool techAuthenticated;
        
        // Integrated Components
        Vault vault;
        Logger logger;
        BankDB bankDB;  
        ATMScreen screen;
        SoundUnit soundUnit;
        CardReader cardReader;
        CashDispenser cashDispenser;
        ReceiptPrinter receiptPrinter;
        TechnicalSupport techSupport;

    public:
        // Constructor
        ATM(const string& loc, const string& pref, const string& logFilename);

        // Methods
        void insertCard();
        void checkATMStatus();
        void displayInfo()  override;
        bool isAuthenticated() const;
        void enterPIN(const string& pin);
        bool isTechAuthenticated() const;
        void techLogin(const string& password);
        void reportIssue(const string& issue);
        void scheduleMaintenance(const string& date);
        void executeTransaction(Transaction& transaction);

        // Components getters
        Vault& getVault();
        Logger& getLogger();
        BankDB& getBankDB();
        ATMScreen& getScreen();
        string& getCurrentCard();
        SoundUnit& getSoundUnit();
        CardReader& getCardReader();
        CashDispenser& getCashDispenser();
        ReceiptPrinter& getReceiptPrinter();

        // Destructor
        ~ATM();
};

#endif // ATM_ATM_HPP
