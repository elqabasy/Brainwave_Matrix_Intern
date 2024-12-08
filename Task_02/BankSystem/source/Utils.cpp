#include "Utils.hpp"
#include <ctime>
#include<iostream>
using namespace std;

int Utils::generateId() {
    static int counter = 1000;
    return counter++;
}

void Utils::logEvent(const string& message) {
    ofstream logFile("bank_system.log", ios::app);
    if (logFile.is_open()) {
        logFile << "[" << time(0) << "] " << message << "\n";
        logFile.close();
    }
}
