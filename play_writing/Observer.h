#pragma once
#include <vector>
using namespace std;
class Observer {
public:
	virtual void update() = 0;

};

class Subject {
private:
	vector<Observer*> obs;
public:
	void addObs(Observer *o) { this->obs.push_back(o); }
	void notify() { for (auto o : this->obs) o->update(); }
};
