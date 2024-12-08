#include "User.hpp"
#include<iostream>
using namespace std;


User::User(int id, const string& name, const string& email) : _id(id), _name(name), _email(email) {}

int User::getId() const { return _id; }

string User::getName() const { return _name; }

string User::getEmail() const { return _email; }
