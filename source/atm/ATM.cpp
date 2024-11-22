// source/atm/atm.cpp


#include "atm/ATM.hpp"
#include "utils/ATMConstants.hpp"



ATM::ATM(const std::string& loc, const std::string& pref, const std::string& logFilename)
    : ATMInfo(loc, pref), authenticated(false), techAuthenticated(false), logger(logFilename) {}

void ATM::displayInfo()  {
    screen.display("ATM Location: " + location + "\nPreferences: " + preferences);
    logger.log("Displayed ATM info");
}

void ATM::insertCard() {
    currentCard = cardReader.readCard();
    if (bankDB.validateCard(currentCard)) {
        screen.display(ATMConstants::CARD_INSERT_PROMPT);
        soundUnit.playSound("Enter PIN sound");
        logger.log("Card inserted: " + currentCard);
    } else {
        screen.display(ATMConstants::INVALID_CARD_MESSAGE);
        soundUnit.playSound("Error sound");
        logger.log("Invalid card inserted");
        currentCard = "";
    }
}

void ATM::enterPIN(const std::string& pin) {
    if (bankDB.validatePIN(currentCard, pin)) {
        authenticated = true;
        screen.display(ATMConstants::PIN_VERIFIED_MESSAGE);
        soundUnit.playSound("PIN verified sound");
        logger.log("PIN verified for card: " + currentCard);
    } else {
        screen.display(ATMConstants::INVALID_PIN_MESSAGE);
        soundUnit.playSound("Error sound");
        logger.log("Invalid PIN entered for card: " + currentCard);
    }
}

void ATM::techLogin(const std::string& password) {
    if (password == ATMConstants::TECH_PASSWORD) {
        techAuthenticated = true;
        screen.display("Technical support access granted. Choose an option: 1) Report Issue 2) Schedule Maintenance 3) Check ATM Status");
        soundUnit.playSound("Access granted sound");
        logger.log("Technical support access granted");
    } else {
        screen.display("Invalid password. Access denied.");
        soundUnit.playSound("Error sound");
        logger.log("Invalid technical support password entered");
    }
}

void ATM::executeTransaction(Transaction& transaction) {
    transaction.execute();
}

void ATM::reportIssue(const std::string& issue) {
    if (techAuthenticated) {
        techSupport.reportIssue(issue);
        screen.display(ATMConstants::ISSUE_REPORTED_MESSAGE);
        soundUnit.playSound("Issue reported sound");
        logger.log("Issue reported: " + issue);
    } else {
        screen.display("Please authenticate as technical support first.");
        soundUnit.playSound("Error sound");
        logger.log("Unauthorized issue report attempt");
    }
}

void ATM::scheduleMaintenance(const std::string& date) {
    if (techAuthenticated) {
        techSupport.scheduleMaintenance(date);
        screen.display(ATMConstants::MAINTENANCE_SCHEDULED_MESSAGE + date);
        soundUnit.playSound("Maintenance scheduled sound");
        logger.log("Maintenance scheduled on: " + date);
    } else {
        screen.display("Please authenticate as technical support first.");
        soundUnit.playSound("Error sound");
        logger.log("Unauthorized maintenance scheduling attempt");
    }
}

void ATM::checkATMStatus() {
    if (techAuthenticated) {
        techSupport.checkATMStatus();
        screen.display(ATMConstants::STATUS_CHECKED_MESSAGE);
        soundUnit.playSound("Status checked sound");
        logger.log("ATM status checked");
    } else {
        screen.display("Please authenticate as technical support first.");
        soundUnit.playSound("Error sound");
        logger.log("Unauthorized status check attempt");
    }
}

bool ATM::isAuthenticated() const {
    return authenticated;
}

bool ATM::isTechAuthenticated() const {
    return techAuthenticated;
}

// Getters for components
BankDB& ATM::getBankDB() { return bankDB; }
Vault& ATM::getVault() { return vault; }
CardReader& ATM::getCardReader() { return cardReader; }
CashDispenser& ATM::getCashDispenser() { return cashDispenser; }
ReceiptPrinter& ATM::getReceiptPrinter() { return receiptPrinter; }
ATMScreen& ATM::getScreen() { return screen; }
SoundUnit& ATM::getSoundUnit() { return soundUnit; }
Logger& ATM::getLogger() { return logger; }
std::string& ATM::getCurrentCard() { return currentCard; }
