#include "Controller.h"
#include "Validator.h"
void Controller::setFileHandler(int i)
{
	if (i==1)
		this->fileHandler = "csv";
	if (i == 2) 
		this->fileHandler = "html";
}
void Controller::readFromFile()
{
	this->adminRepo.readFromFile();
}
void Controller::addEventAdmin(const string& title, const string& description, const string& link, int nbofpeople, int day, int month, int hours, int minutes) {
	DateAndTime dateAndTime{ day, month, hours, minutes };
	Event event{ title, description, link, nbofpeople, dateAndTime };
	this->validator.validate(event);
	this->adminRepo.add(event);
	
}

void Controller::addEventUser(Event event) {
	int nb = event.getNbOfPeople() + 1;
	this->adminRepo.updateEvent("", "", "", nb , -1, -1, -1, -1);
	event.setNbOfPeople(nb);
	this->userRepo.addEvent(event);
}

void Controller::deleteEventAdmin(const string &title) {
	return this->adminRepo.deleteEvent(title);
}

void Controller::deleteEventUser(const string & title)
{
	this->adminRepo.decreaseNbOfPeople(title);
	return this->userRepo.deleteEvent(title);
}

void Controller::updateEventAdmin(const string &title, const const string &description, const string &link, const int nbOfPeople, int day, int month, int hours, int minutes){
	return this->adminRepo.updateEvent(title,  description, link, nbOfPeople,  day, month,  hours,  minutes);
}

vector<Event> Controller::filterByMonth(int month) {
	return this->adminRepo.filterByMonth(month);
}

void Controller::printToFile() {
	if (this->fileHandler == "html") {
		HTMLFile file;
		file.writeToFile(this->adminRepo.getEvents());
	}
		if (this->fileHandler == "csv") {
		CSVFile file;
		file.writeToFile(this->adminRepo.getEvents());
	}
}
