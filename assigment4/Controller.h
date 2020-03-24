#pragma once
#include "Repository.h"
#include <iostream>

using namespace std;

class Controller
{
private:
	Repository adminRepo,userRepo;

public:
	/*Creates an empty controller
	IN: -
	OUT - a controller*/
	Controller(const Repository& adminRepo, const Repository& userRepo) : adminRepo(adminRepo), userRepo(userRepo){}
	/*Returns one of the repositories contained in the controller
	IN: -
	OUT : the administrator repository.*/
	Repository getAdminRepo()const { return this->adminRepo; }
	/*Returns one of the repositories contained in the controller
	IN: -
	OUT : the administrator repository.*/
	Repository getUserRepo()const { return this->userRepo; }
	
	/*Adds a new event to the admin repository:
	IN: the atributes of the event
	OUT: 1 if it was succesfully added,-1 otherwise.*/
	int addEventAdmin(const string& title, const string& description, const string& link, int nbofpeople, int day, int month, int hours, int minutes);
	/*Adds a new event to the user repository:
	IN: an event
	OUT: 1 if it was succesfully added,-1 otherwise.*/
	int addEventUser(Event event);
	/*Deletes an event from the admin repository
	IN: the title of the event one wishes to delete
	OUT: 1 if it was succesfully deleted, -1 otherwise*/
	int deleteEventAdmin(const string &title);
	/*Removes an event fromm the user list
	IN: the title of the event
	OUT: 1 if the event was succesfully added, -1 if the event was not found.*/
	int deleteEventUser(const string &title);
	/*Updates a product from the admin repositort
	IN: the title of the product the user wishes to update.
	OUT: 1 if it was succesfully updated, otherwise.*/
	int updateEventAdmin(const string &title, const const string &description, const string &link, const int nbOfPeople, int day, int month, int hours, int minutes);
	/*Filters the event by the requested month.
	IN: -
	OUT : a list of all the events of the month*/
	DynamicVector filterByMonth(int month);
	
};

