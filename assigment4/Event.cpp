#include "Event.h"

Event& Event::operator=(Event& event) {
	if (this == &event)
		return *this;

	this->title = event.title;
	this->description = event.description;
	this->dateAndTime = event.dateAndTime;
	this->link = event.link;
	this->nbOfPeople = event.nbOfPeople;

	return *this;
}

string DateAndTime::toStringDateAndTime() {
	string s = "";
	if (day > 9)
		s += to_string(day);
	else
		s += "0" + to_string(day);
	s += "/";
	if (month > 9)
		s += to_string(month);
	else
		s += "0" + to_string(month);
	s += "  ";
	if (hours > 9)
		s += to_string(hours);
	else
		s += "0" + to_string(hours);
	s += ":";
	if (minutes > 9)
		s += to_string(minutes);
	else
		s += "0" + to_string(minutes);

	return s;

}

void Event::updateDateAndTime(int day, int  month, int hours, int minutes) {
	if (day != -1)
		this->dateAndTime.setDay(day);
	if (month != -1)
		this->dateAndTime.setMonth(month);
	if (hours != -1)
		this->dateAndTime.setHours(hours);
	if (minutes != -1)
		this->dateAndTime.setMinutes(minutes);
}

string Event::toStringEvent() {
	string s = this->title + " " + '\n' + this->description + '\n' + this->link + '\n';
	s += "Number of people attending: " + to_string(nbOfPeople) + '\n';
	s += this->dateAndTime.toStringDateAndTime();

	return s;
}
