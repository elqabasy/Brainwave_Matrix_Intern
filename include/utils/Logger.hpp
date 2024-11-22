#ifndef ATM_LOGGER_HPP
#define ATM_LOGGER_HPP

#include <string>
#include <fstream>
#include <iostream>
using namespace std;


class Logger {
    private:
        ofstream logFile;

    public:
        // Constructor
        Logger(const string& filename);

        // Methods
        void log(const string& message) ;

        // Destructor
        ~Logger();
};

#endif // ATM_LOGGER_HPP
