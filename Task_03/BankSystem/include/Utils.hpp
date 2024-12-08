#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;
class Utils {
    public:
        static int generateId();
        static void logEvent(const string& message);
};

#endif // UTILS_HPP
