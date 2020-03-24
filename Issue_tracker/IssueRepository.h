#pragma once
#include "User.h"
#include "Issue.h"
#include "qmessagebox.h"
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;
class IssueRepository {
private:
	vector<User> users;
	vector<Issue> issues;
public:
	IssueRepository() { this->readIssues(), this->readUsers(); }
	void readUsers();
	void readIssues();
	vector<User> getUsers() { return this->users; }
	vector<Issue> getIssues() { return this->issues; }
	void updateTask(int i);
};