#ifndef USER_HPP
#define USER_HPP

#include <iostream>
using namespace std;

class User {
    private:
        int _id;
        string _name;
        string _email;

    public:
        // Constructor
        User(int id, const string& name, const string& email);

        // getters
        int getId() const;
        string getName() const;
        string getEmail() const;
};

#endif // USER_HPP
