#include "Exceptions.h"

void EventValidator::validate(Event e)
{
	vector<string> errors;
	if (e.getTitle().length() == 0)
		errors.push_back("You can't leave title blank!");
	if (e.getDescription().length() == 0)
		errors.push_back("You can't leave description blank!");
	if (e.getLink().length() == 0)
		errors.push_back("You can't leave link blank!");
	if (e.getNbOfPeople()< 0)
		errors.push_back("Number of people must be a positive number.");
	if (e.getDateAndTime().getDay() <= 0 || e.getDateAndTime().getDay() > 31)
		errors.push_back("Invalid day.");
	if (e.getDateAndTime().getMonth() <= 0 || e.getDateAndTime().getMonth() > 12)
		errors.push_back("Invalid month");
	if (e.getDateAndTime().getHours() < 0 || e.getDateAndTime().getHours() > 23)
		errors.push_back("Invalid hour");
	if (e.getDateAndTime().getMinutes() < 0 || e.getDateAndTime().getMinutes() > 59)
		errors.push_back("Invalid minute.");

	time_t t = time(0);
	tm* now = localtime(&t);

	if (now->tm_mon + 1 > e.getDateAndTime().getMonth())
		errors.push_back("You inserted a past date!");
	if (now->tm_mon + 1 == e.getDateAndTime().getMonth())
		if (now->tm_mday > e.getDateAndTime().getDay())
			errors.push_back("You inserted a past date!");

	if (errors.size() > 0)
		throw EventException(errors);
}
