#include "QASession.h"

Session::Session()
{
	this->readUsers();
	this->readQuestions();
	this->readAnswers();
	//this->runWindows();
}


void Session::readUsers()
{
	fstream in;
	in.open("users.txt");
	
	string user;
	while (in >> user)
		this->users.push_back(user);

	in.close();
}

void Session::readQuestions()
{
	fstream in;
	in.open("questions.txt");

	string id, text, user;
	while (in >> id >> text >> user) {
		Question *q = new Question(id, text, user);
		this->questions.push_back(*q);
	}

	in.close();
}

void Session::readAnswers()
{
	fstream in;
	in.open("answers.txt");

	string id, text, user,questionId;
	int nb;
	while (in >> id >> text >> user >> questionId >> nb) {
		Answer *a = new Answer(id, text, user, questionId, nb);
		this->answers.push_back(*a);
	}
	in.close();
}

void Session::addQuestion(string name, string text)
{
	string id = "100";
	Question *q = new Question(id, text, name);
	this->questions.push_back(*q);
	this->notify();
}

void Session::addAnswer(string name, string text, string questionId)
{
	string id = "69";
	Answer *a = new Answer(id, text, name, questionId, 0);
	
	this->answers.push_back(*a);
	this->notify();
}



