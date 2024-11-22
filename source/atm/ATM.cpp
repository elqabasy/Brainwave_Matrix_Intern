// source/atm/atm.cpp


#include "atm/ATM.hpp"
#include "utils/ATMConstants.hpp"



ATM::ATM(const std::string& loc, const std::string& pref, const std::string& logFilename)
    : ATMInfo(loc, pref), _isAuthenticated(false), _isTechAuthenticated(false), _logger(logFilename) {}

void ATM::displayInfo()  {
    _screen.display("ATM Location: " + _location + "\nPreferences: " + _preferences);
    _logger.log("Displayed ATM info");
}

void ATM::insertCard() {
    _currentCard = _cardReader.readCard();
    if (_bankDB.validateCard(_currentCard)) {
        _screen.display(ATMConstants::CARD_INSERT_PROMPT);
        _soundUnit.playSound("Enter PIN sound");
        _logger.log("Card inserted: " + _currentCard);
    } else {
        _screen.display(ATMConstants::INVALID_CARD_MESSAGE);
        _soundUnit.playSound("Error sound");
        _logger.log("Invalid card inserted");
        _currentCard = "";
    }
}

void ATM::enterPIN(const std::string& pin) {
    if (_bankDB.validatePIN(_currentCard, pin)) {
        _isAuthenticated = true;
        _screen.display(ATMConstants::PIN_VERIFIED_MESSAGE);
        _soundUnit.playSound("PIN verified sound");
        _logger.log("PIN verified for card: " + _currentCard);
    } else {
        _screen.display(ATMConstants::INVALID_PIN_MESSAGE);
        _soundUnit.playSound("Error sound");
        _logger.log("Invalid PIN entered for card: " + _currentCard);
    }
}

void ATM::techLogin(const std::string& password) {
    if (password == ATMConstants::TECH_PASSWORD) {
        _isTechAuthenticated = true;
        _screen.display("Technical support access granted. Choose an option: 1) Report Issue 2) Schedule Maintenance 3) Check ATM Status");
        _soundUnit.playSound("Access granted sound");
        _logger.log("Technical support access granted");
    } else {
        _screen.display("Invalid password. Access denied.");
        _soundUnit.playSound("Error sound");
        _logger.log("Invalid technical support password entered");
    }
}

void ATM::executeTransaction(Transaction& transaction) {
    transaction.execute();
}

void ATM::reportIssue(const std::string& issue) {
    if (_isTechAuthenticated) {
        _techSupport.reportIssue(issue);
        _screen.display(ATMConstants::ISSUE_REPORTED_MESSAGE);
        _soundUnit.playSound("Issue reported sound");
        _logger.log("Issue reported: " + issue);
    } else {
        _screen.display("Please authenticate as technical support first.");
        _soundUnit.playSound("Error sound");
        _logger.log("Unauthorized issue report attempt");
    }
}

void ATM::scheduleMaintenance(const std::string& date) {
    if (_isTechAuthenticated) {
        _techSupport.scheduleMaintenance(date);
        _screen.display(ATMConstants::MAINTENANCE_SCHEDULED_MESSAGE + date);
        _soundUnit.playSound("Maintenance scheduled sound");
        _logger.log("Maintenance scheduled on: " + date);
    } else {
        _screen.display("Please authenticate as technical support first.");
        _soundUnit.playSound("Error sound");
        _logger.log("Unauthorized maintenance scheduling attempt");
    }
}

void ATM::checkATMStatus() {
    if (_isTechAuthenticated) {
        _techSupport.checkATMStatus();
        _screen.display(ATMConstants::STATUS_CHECKED_MESSAGE);
        _soundUnit.playSound("Status checked sound");
        _logger.log("ATM status checked");
    } else {
        _screen.display("Please authenticate as technical support first.");
        _soundUnit.playSound("Error sound");
        _logger.log("Unauthorized status check attempt");
    }
}

bool ATM::isAuthenticated() const {
    return _isAuthenticated;
}

bool ATM::isTechAuthenticated() const {
    return _isTechAuthenticated;
}

// Getters for components
BankDB& ATM::getBankDB() { return _bankDB; }
Vault& ATM::getVault() { return _vault; }
CardReader& ATM::getCardReader() { return _cardReader; }
CashDispenser& ATM::getCashDispenser() { return _cashDispenser; }
ReceiptPrinter& ATM::getReceiptPrinter() { return _receiptPrinter; }
ATMScreen& ATM::getScreen() { return _screen; }
SoundUnit& ATM::getSoundUnit() { return _soundUnit; }
Logger& ATM::getLogger() { return _logger; }
std::string& ATM::getCurrentCard() { return _currentCard; }
