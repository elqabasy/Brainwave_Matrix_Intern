// source/utils/TechnicalSupport.cpp

#include "utils/TechnicalSupport.hpp"
#include <iostream>

void TechnicalSupport::reportIssue(const string& issue) const {
    cout << "Issue reported: " << issue << endl;
}

void TechnicalSupport::scheduleMaintenance(const string& date) const {
    cout << "Maintenance scheduled on: " << date << endl;
}

void TechnicalSupport::checkATMStatus() const {
    cout << "ATM status checked." << endl;
}
