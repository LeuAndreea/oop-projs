#include "Controller.h"
#include "Validator.h"
int Controller::addEventAdmin(const string& title, const string& description, const string& link, int nbofpeople, int day, int month, int hours, int minutes) {
	DateAndTime dateAndTime{ day, month, hours, minutes };
	Event event{title, description, link, nbofpeople, dateAndTime};
	if (Validator::validateEvent(event)) {
		int i = this->adminRepo.addEvent(event);
		return i;
	}
	else return -1;	}

int Controller::addEventUser(Event event) {
	int nb = event.getNbOfPeople() + 1;
	this->adminRepo.updateEvent("", "", "", nb , -1, -1, -1, -1);
	event.setNbOfPeople(nb);
	return this->userRepo.addEvent(event);
}

int Controller::deleteEventAdmin(const string &title) {
	return this->adminRepo.deleteEvent(title);
}

int Controller::deleteEventUser(const string & title)
{
	this->adminRepo.decreaseNbOfPeople(title);
	return this->userRepo.deleteEvent(title);
}

int Controller::updateEventAdmin(const string &title, const const string &description, const string &link, const int nbOfPeople, int day, int month, int hours, int minutes){
	return this->adminRepo.updateEvent(title,  description, link, nbOfPeople,  day, month,  hours,  minutes);
}

DynamicVector Controller::filterByMonth(int month) {
	return this->adminRepo.filterByMonth(month);
}


