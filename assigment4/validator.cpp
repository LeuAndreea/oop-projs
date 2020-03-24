
#include "Validator.h"

#include <ctime>

bool Validator::validateDateAndTime(DateAndTime d) {
	if(d.getDay()<=0 || d.getDay()>31)
		return false;
	if (d.getMonth() <= 0 || d.getMonth() > 12)
		return false;
	if (d.getHours() < 0 || d.getHours() > 23)
		return false;
	if (d.getMinutes() < 0 || d.getMinutes() > 59)
		return false;

	time_t t = time(0);
	tm* now = localtime(&t);

	if (now->tm_mon + 1 > d.getMonth())
		return false;
	if (now->tm_mon + 1 == d.getMonth())
		if (now->tm_mday > d.getDay())
			return false;

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
