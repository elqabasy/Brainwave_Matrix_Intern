#ifndef ATM_INFO_HPP
#define ATM_INFO_HPP

#include <iostream>
using namespace std;



class ATMInfo {
    public:
        string location;
        string preferences;

        // Constructor
        ATMInfo(const string& loc, const string& pref) : location(loc), preferences(pref) {}

        // Methods
        virtual void displayInfo() = 0;

        // Destructor
        ~ATMInfo();
};

#endif // ATM_HPP
