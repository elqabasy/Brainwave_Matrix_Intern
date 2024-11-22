// source/utils/Logger.cpp 

#include "utils/Logger.hpp"
#include <iostream>
#include <ctime>

Logger::Logger(const string& filename) {
    logFile.open(filename, ios::app);
    if (!logFile.is_open()) {
        cerr << "Failed to open log file!" << endl;
    }
}

Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

void Logger::log(const string& message)  {
    if (logFile.is_open()) {
        time_t now = time(0);
        char* dt = ctime(&now);
        logFile << dt << ": " << message << endl;
    }
}
