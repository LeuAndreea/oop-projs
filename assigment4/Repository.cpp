#include "Repository.h"
#include <cstring>
#include <string>
#include <string.h>

using namespace std;
Event Repository::getEventAtIndex(int index) {
	return this->events.getElementAtIndex(index);
}

int Repository::getIndex(const string& title) {
	int length = this->events.getSize();
	Event event;
	for (int i = 0; i < length; i++) {
		event = events.getElementAtIndex(i);
		if (event.getTitle() == title)
			return i;}
	return -1;

}

int Repository::addEvent(Event& event) {
	int i = getIndex(event.getTitle());
	if (i == -1) {
		this->events.add(event);
		return 1;
	}
	return -1;
}

int Repository::deleteEvent(const string& title) {
	int i = getIndex(title);
	Event event;
	if (i != -1) {
		event = getEventAtIndex(i);
		this->events.deleteElement(i);
		return 1;
	}
	return -1;
}

int Repository:: updateEvent(const string &title, const const string &description, const string &link, const int nbOfPeople,  int day, int month, int hours, int minutes ){
	int i = getIndex(title);
	if (i != -1) {
		Event event = getEventAtIndex(i);
		if (title != "")
			event.setTitle(title);
		if (description != "")
			event.setDescription(description);
		if (nbOfPeople != -1)
			event.setNbOfPeople(nbOfPeople);
		if (link != "")
			event.setLink(link);
		event.updateDateAndTime(day,month,hours,minutes);
		
		this->events.modifyElem(i, event);
		return 1;
	}
	return -1;
	
}

int Repository::decreaseNbOfPeople(const string & title)
{
	int i = this->getIndex(title);
	if (i == -1)
		return -1;
	int nb = this->getEventAtIndex(i).getNbOfPeople();
	this->updateEvent(title, "","",nb - 1,-1,-1,-1,-1);
}

DynamicVector Repository::filterByMonth(int month) {
	DynamicVector result;
	Event event;
	for (int i = 0; i < this->events.getSize(); i++) {
		event = this->events.getElementAtIndex(i);
		if (event.getDateAndTime().getMonth() == month) 
			result.add(event);
	}
	return result;
}