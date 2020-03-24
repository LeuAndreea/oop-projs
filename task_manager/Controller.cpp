#include "Controller.h"

void Controller::readFromFile()
{
	ifstream f("in.txt");
	string description;
	int duration, priority;
	while (f >> description >> duration >> priority) {
		Task t=Task(description, duration, priority);
		this->tasks.push_back(t);
	}
}

void Controller::sortByPriority()
{
	sort(this->tasks.begin(), this->tasks.end(), [](Task t1, Task t2) {return t1.getPriority() < t2.getPriority(); });
}
