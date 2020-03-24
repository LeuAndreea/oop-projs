#pragma once
#include "Event.h"
#include "Exceptions.h"
#include <vector>
#include <cstring>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;
class Repository {
	protected:
		vector<Event> events;
	public:
		/*Creates an empty repository.
		IN: -
		OUT: -*/
		Repository() { }		
		/*Adds a new event to the repository
		IN: an event.
		OUT: 1 if it was succesfully added, -1 if it could not be added*/
		void addEvent(Event& event);
		/*Deletes an event.
		IN: a title 
		OUT: 1 if the event was found and deleted, -1 otherwise.*/
		void deleteEvent(const string& title);
		/*Updates an event.
		IN: the title fo the event, the fields which must be updates
		-if the string is empty or an int -1, it means the field will not be updates
		OUT: 1 if the event was found and updates, -1 otherwise.*/
		void updateEvent(const string &title, const const string &description, const string &link, const int nbOfPeople, int day, int month, int hours, int minutes);
		/*Returns all the events from the repository.
		IN:-
		OUT: dynamic vector of the events.*/
		int decreaseNbOfPeople(const string &title);
		vector<Event> getEvents() { return this->events; }
		/*Gets events happening in a given month
		IN: a month
		OUT: a vector containing events happening in a month.*/
		vector<Event> filterByMonth(int month);
};