#pragma once
#include <string>

using namespace std;

class Writer {
private:
	string name, exp;
public:
	Writer(string name, string exp) : name(name), exp(exp) {}
	string getName() { return this->name; }
	string getExp() { return this->exp; }
	~Writer() {}
};