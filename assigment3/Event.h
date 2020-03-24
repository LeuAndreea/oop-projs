#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class DateAndTime {
private:
	 int day, month,  hours, minutes;
public:
	DateAndTime() : day(0), month(0), hours(0), minutes(0) { }
	DateAndTime(int day, int month, int hours, int minutes)
		: day(day), month(month), hours(hours), minutes(minutes) { }
	int getDay() const { return this->day; }
	int getMonth() const { return this->month; }
	int getHours() const { return this->hours; }
	int getMinutes() const { return this->minutes; }
	
	void setDay(int day) { this->day = day; }
	void setMonth(int month) { this->month = month; }
	void setHours(int hours) { this->hours = hours; }
	void setMinutes(int minutes) { this->minutes = minutes; }

	string toStringDateAndTime();
};

class Event {
	private:
		string  title, description, link;
		int nbOfPeople;
		DateAndTime dateAndTime;
	public:
		Event(): title(""),description(""),link(""),nbOfPeople(0), dateAndTime(DateAndTime()) { }
		Event(const string& title, const string& description, const string& link, int nbofpeople, DateAndTime dateAndTime) :
			title(title), description(description), link(link), nbOfPeople(nbofpeople), dateAndTime(dateAndTime) { }
		
		string getTitle()  { return this->title; }
		string getDescription() const { return this->description; }
		string getLink() const { return this->link; }
		int getNbOfPeople() const { return this->nbOfPeople; }
		DateAndTime getDateAndTime() const { return this->dateAndTime; }

		void setTitle(const string &title) { this->title = title; }
		void setDescription(const string& description) { this->description = description; }
		void setLink(const string& link) { this->link = link; }
		void setNbOfPeople(int nbOfPeople) { this->nbOfPeople = nbOfPeople; }
		void updateDateAndTime(int day, int month, int hours, int minutes);
		Event& operator=(Event& v);
		string toStringEvent();

		friend std::istream& operator>>(std::istream& is, Event& s);
		friend std::ostream& operator<<(std::ostream& os, const Event& s);

};

