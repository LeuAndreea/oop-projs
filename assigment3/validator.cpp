
#include "Validator.h"



bool Validator::validateDateAndTime(DateAndTime d) {
	

	return true;
}
bool Validator::validateEvent(Event e) {
	if (e.getTitle() == "") {
		return false;
	}
	if (e.getDescription() == "") {
		return false;
	}
	if (e.getLink() == "") {
		return false;
	}
	if (!(validateDateAndTime(e.getDateAndTime()))) {
		return false;
	}
	return true;
}

bool Validator::validateMonth(int month)
{
	time_t t = time(0);
	tm* now = localtime(&t);
	
	if (month < now->tm_mon + 1)
		return false;
	return true;
}
