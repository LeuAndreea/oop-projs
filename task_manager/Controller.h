#pragma once
#include "Task.h"

#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
class Controller {
private:
	vector<Task> tasks; 
public:
	Controller() { this->readFromFile(); this->sortByPriority(); };
	void readFromFile();
	vector<Task> getTasks(){ return this->tasks; }
	void sortByPriority();

};