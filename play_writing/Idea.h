#pragma once

#include <string>

using namespace std;

class Idea {
private:
	string descr, status, creator;
	int act;
public:
	Idea(string d, string s, string c, int a) :descr(d), status(s), creator(c), act(a){}
	string getDescr() { return this->descr;  }
	string getStatus() { return this->status; }
	string getCreator() { return this->creator; }
	int getAct() { return this->act; }
	void setStatus(string s) { this->status = s; }

	string toString() { return to_string(this->getAct()) + this->getDescr() + " (" + this->getCreator() +")" + this->getStatus(); }
};