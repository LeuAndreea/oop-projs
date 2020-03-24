#pragma once

#include <string>
using namespace std;
class User {
private:
	string name, type;
public:
	User(string name, string type) : name(name), type(type) {}
	string getName() { return this->name; }
	string getType() { return this->type; }

	string toString() { return this->name + "  " + this->type; }
};