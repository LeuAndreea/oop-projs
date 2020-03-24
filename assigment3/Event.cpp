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
	string s="";
	if (day > 9)
		s += to_string(day);
	else
		s += "0" + to_string(day);
	s+="/" ;
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

vector<string> tokenize(string str, char delimiter)
{
	vector <string> result;
	stringstream ss(str);
	string token;
	while (getline(ss, token, delimiter))
		result.push_back(token);

	return result;
}

std::istream & operator>>(std::istream & is, Event & s)
{
	string line;
	getline(is, line);

	vector<string> tokens = tokenize(line, ',');
	if (tokens.size() != 8)
		return is;
	s.title = tokens[0];
	s.description = tokens[1];
	s.link = tokens[2];
	s.nbOfPeople = stoi(tokens[3]);
	s.dateAndTime.setDay(stoi(tokens[4]));
	s.dateAndTime.setMonth(stoi(tokens[5]));
	s.dateAndTime.setHours(stoi(tokens[6]));
	s.dateAndTime.setMinutes(stoi(tokens[7]));

	return is;
}

std::ostream & operator<<(std::ostream & os, const Event & ev)
{
	
	os << ev.title + " " + '\n' + ev.description + '\n' + ev.getLink() + '\n';
	os<< "Number of people attending: " + to_string(ev.nbOfPeople) + '\n';
	os<< ev.getDateAndTime().toStringDateAndTime();
	return os;
}