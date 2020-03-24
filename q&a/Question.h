#pragma once
#include <string>

using namespace std;
class Question {
private:
	string id, text, user;
public:
	Question() {}
	Question(string id, string text, string user) : id(id), text(text), user(user) {}
	string getId() { return this->id;  }
	string getText() { return this->text; }
	string getUser() { return this->user; }
	string toString() { return this->user + ": " + this->text; }

};	

class Answer {
private:
	string id, text, user, questionId;
	int nbOfVotes;
public:
	Answer(string id, string text, string user, string questionId, int nbOfVotes) :id(id), text(text), user(user), questionId(questionId), nbOfVotes(nbOfVotes) {}
	string getId() { return this->id; }
	string getText() { return this->text; }
	string getUser() { return this->user; }
	string getQuestionId() { return this->questionId; }
	int getNbOfVotes() { return this->nbOfVotes; }
	string toString() { return this->user + ": " + this->text + " " + to_string(this->nbOfVotes); }
};