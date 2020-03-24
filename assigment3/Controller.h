#pragma once
#include "Exceptions.h"
#include "FileRepository.h"
#include <iostream>
#include "TextFile.h"
using namespace std;

class Controller
{
private:
	FileRepository adminRepo;
	Repository userRepo;
	EventValidator validator;
	string fileHandler;
public:
	/*Creates an empty controller
	IN: -
	OUT - a controller*/
	Controller(const FileRepository& adminRepo, const Repository& userRepo, EventValidator validator) : adminRepo(adminRepo), userRepo(userRepo),validator(validator), fileHandler("") {}
	/*Returns one of the repositories contained in the controller
	IN: -
	OUT : the administrator repository.*/
	void setFileHandler(int i);
	Repository getAdminRepo()const { return this->adminRepo; }
	/*Returns one of the repositories contained in the controller
	IN: -
	OUT : the administrator repository.*/
	Repository getUserRepo()const { return this->userRepo; }
	void readFromFile();
	/*Adds a new event to the admin repository:
	IN: the atributes of the event
	OUT: */
	void addEventAdmin(const string& title, const string& description, const string& link, int nbofpeople, int day, int month, int hours, int minutes);
	/*Adds a new event to the user repository:
	IN: an event
	OUT: 1 if it was succesfully added,-1 otherwise.*/
	void addEventUser(Event event);
	/*Deletes an event from the admin repository
	IN: the title of the event one wishes to delete
	OUT: */
	void deleteEventAdmin(const string &title);
	/*Removes an event fromm the user list
	IN: the title of the event
	OUT: */
	void deleteEventUser(const string &title);
	/*Updates a product from the admin repository
	IN: the title of the product the user wishes to update.
	OUT:*/
	void updateEventAdmin(const string &title, const const string &description, const string &link, const int nbOfPeople, int day, int month, int hours, int minutes);
	/*Filters the event by the requested month.
	IN: -
	OUT : a list of all the events of the month*/
	vector<Event> filterByMonth(int month);
	void printToFile();
};

