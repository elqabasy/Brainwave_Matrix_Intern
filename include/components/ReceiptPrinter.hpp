#ifndef ATM_RECEIPT_PRINTER_HPP
#define ATM_RECEIPT_PRINTER_HPP

#include <iostream>
using namespace std;

class ReceiptPrinter {
    public:
        void printReceipt(const string& transactionDetails) const;
};

#endif // ATM_RECEIPT_PRINTER_HPP
