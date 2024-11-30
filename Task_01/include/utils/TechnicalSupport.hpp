#ifndef ATM_TECHNICAL_SUPPORT_HPP
#define ATM_TECHNICAL_SUPPORT_HPP

#include <iostream>
using namespace std;


class TechnicalSupport {
    public:
        void checkATMStatus() const;
        void reportIssue(const string& issue) const;
        void scheduleMaintenance(const string& date) const;
};

#endif // ATM_TECHNICAL_SUPPORT_HPP
