#include "Transaction.hpp"
#include <sstream>

#include "Transaction.hpp"
#include <sstream>
using namespace std;


Transaction::Transaction(int id, int fromAccountId, int toAccountId, double amount, const string& type)
    : _id(id), _fromAccountId(fromAccountId), _toAccountId(toAccountId), _amount(amount), _type(type) {}

int Transaction::getId() const { return _id; }

int Transaction::getFromAccountId() const { return _fromAccountId; }

int Transaction::getToAccountId() const { return _toAccountId; }

string Transaction::toString() const {
    stringstream ss;
    ss << "Transaction ID: " << _id << ", Type: " << _type
       << ", From: " << (_fromAccountId == -1 ? "N/A" : to_string(_fromAccountId))
       << ", To: " << (_toAccountId == -1 ? "N/A" : to_string(_toAccountId))
       << ", Amount: " << _amount;
    return ss.str();
}
