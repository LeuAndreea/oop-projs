#pragma once

#include "Question.h"
#include "Observer.h"

#include <vector>
#include <fstream>
#include <iostream>


using namespace std;
class Session: public Subject {
private:
	vector<string> users;
	vector<Question> questions;
	vector<Answer> answers;
public:
	Session();
	vector<string> getUsers() { return this->users; }
	vector<Question> getQuestions() { return this->questions; }
	vector<Answer> getAnswers() { return this->answers; }
	
	void readUsers();
	void readQuestions();
	void readAnswers();
	void addQuestion(string name, string text);
	void addAnswer(string name, string text, string questionId);
};

