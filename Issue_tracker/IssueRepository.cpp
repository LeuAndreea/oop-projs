#include "IssueRepository.h"

void IssueRepository::readUsers()
{
	ifstream in;
	in.open("users.txt");

	string name, type;
	while (in >> name >> type) {
		User *u = new User(name, type);
		this->users.push_back(*u);
	}
	in.close();
}

void IssueRepository::readIssues()
{
	ifstream in;
	in.open("issues.txt");
	
	string descr, status, reporter;
	while (in >> descr >> status >> reporter) {
		Issue *i = new Issue(descr, status, reporter, "");
		this->issues.push_back(*i);
	}
}

void IssueRepository::updateTask(int i)
{
	if (this->issues.at(i).getStatus() == "closed")
		QMessageBox::critical(0, "Error", "You cannot close this task");
}
