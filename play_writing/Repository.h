#pragma once
#include <vector>
#include "Observer.h"
#include "Writer.h"
#include "Idea.h"

using namespace std;
class Repository : public Subject{
private:
	vector<Writer> writers;
	vector<Idea> ideas;
public:
	Repository() { this->readIdeas(); this->readWriters(); this->sortIdeas(); }
	
	vector<Writer> getWriters() { return this->writers; }
	vector<Idea> getIdea() { return this->ideas; }
	
	void readWriters();
	void readIdeas();
	void sortIdeas();
	//In: idea
	//Out:-
	//Descr:adds idea to repo
	void addIdea(Idea d) { this->ideas.push_back(d);  this->notify(); }
	void savePlot();
	//In: int i
	//Out:-
	//Descr:removes idea at position i
	void removeIdea(int i);
	void acceptIdea(int i);


};