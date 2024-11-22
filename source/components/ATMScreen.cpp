// source/components/ATMScreen.cpp

#include "components/ATMScreen.hpp"
#include <iostream>
using namespace std;

void ATMScreen::display(const string& message) const {
    cout << "ATM Screen: " << message << endl;
}
