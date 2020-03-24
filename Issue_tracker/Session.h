#pragma once
#include "Observer.h"
#include "IssueRepository.h"

class Session : public Subject{
private:
	IssueRepository repo;
public:
	Session(IssueRepository repo):repo(repo){}
	IssueRepository getRepo(){ return this->repo; }
	void updateTask(int i);
};