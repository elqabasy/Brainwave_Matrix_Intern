#include "components/ReceiptPrinter.hpp"
#include <iostream>
using namespace std;

#include <string>

void ReceiptPrinter::printReceipt(const string& transactionDetails) const {
    cout << "Receipt: " << transactionDetails << endl;
}
