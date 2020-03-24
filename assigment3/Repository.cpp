#include "Repository.h"


using namespace std;


void Repository::addEvent(Event& event) {
	
	string title = event.getTitle();
	vector<Event>::iterator it = find_if(this->events.begin(), this->events.end(), [title](Event event) {return event.getTitle() == title; });
	if (it != this->events.end())
		throw Exception("Event already exists.");
	this->events.push_back(event);

}

void Repository::deleteEvent(const string& title) {
	vector<Event>::iterator it = find_if(this->events.begin(), this->events.end(), [title](Event event) {return event.getTitle() == title; });
	if (it == this->events.end())
		throw Exception("Event does not exist.");
	this->events.erase(it);
}

void Repository:: updateEvent(const string &title, const const string &description, const string &link, const int nbOfPeople,  int day, int month, int hours, int minutes ){
	vector<Event>::iterator it = find_if(this->events.begin(), this->events.end(), [title](Event event) {return event.getTitle() == title; });
	if (it == this->events.end())
		throw Exception("Event does not exist.");
	if (title != "")
		(*it).setTitle(title);
	if (description != "")
		(*it).setDescription(description);
	if (nbOfPeople != -1)
		(*it).setNbOfPeople(nbOfPeople);
	if (link != "")
		(*it).setLink(link);
	(*it).updateDateAndTime(day, month, hours, minutes);
}

int Repository::decreaseNbOfPeople(const string & title)
{
	vector<Event>::iterator it = find_if(this->events.begin(), this->events.end(), [title](Event event) {return event.getTitle() == title; });
	if (it == events.end())
		return -1;
	int nb = (*it).getNbOfPeople();
	this->updateEvent(title, "","",nb - 1,-1,-1,-1,-1);
	return 1;
}

vector<Event> Repository::filterByMonth(int month) {
	vector<Event> result(this->events.size());
	vector<Event>::iterator it=copy_if(this->events.begin(), this->events.end(), result.begin(),[month](Event event) {return event.getDateAndTime().getMonth() == month; });
	result.resize(distance(result.begin(), it));
	
	return result;
}