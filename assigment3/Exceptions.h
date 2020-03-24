#pragma once
#include "Event.h"
#include <vector>
#include <ctime>


/*class FileException {
private:
	vector<string> errors;
public:
	
};

class FileValidator {

}; */

class Exception {
private: 
	string message;
public:
	Exception(const string& message): message(message) { }
	string getError() { return this->message; }

};

class EventException {
private:
	vector<string> errors;
public:
	EventException(vector<string> errors): errors(errors) { }
	vector<string> getErrors() { return this->errors; }

};


class EventValidator {
public:
	EventValidator() { }
	void validate(Event e);


};

