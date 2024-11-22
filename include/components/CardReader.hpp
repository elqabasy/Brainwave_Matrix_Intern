#ifndef ATM_CARD_READER_HPP
#define ATM_CARD_READER_HPP

#include <iostream>
using namespace std;

class CardReader {
    public:
        // Constructor
        CardReader();

        // methods
        string readCard() const;

        // Destructor
        ~CardReader();
};

#endif // ATM_CARD_READER
