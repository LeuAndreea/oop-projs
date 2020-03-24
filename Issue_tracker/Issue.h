#pragma once

#include <string>

using namespace std;
class Issue {
private:
	string descr, status, reporter, solver;
public:
	Issue(string desc, string status, string reporter, string solver) :descr(desc), status(status), reporter(reporter), solver(solver) {}
	string getDescr() { return this->descr; }
	string getStatus() { return this->status; }
	string getReporter() { return this->reporter;  }
	string getResolver() { return this->solver;  }

	string toString() { return this->descr +" "+ this->status +" "+ this->reporter +" "+ this->solver; }
};