#pragma once
#include <vector>

using namespace std;
class Observer {
public:
	virtual void update() = 0;
	virtual ~Observer(){}
};

class Subject {
private:
	vector<Observer*> observers;
public:
	Subject(){}
	void addObserver(Observer *obs) { this->observers.push_back(obs); }
	void notify() { for (auto obs : this->observers) obs->update(); }
};