#pragma once
#include "Controller.h"

class UI
{
private:
	Controller ctrl;
	/*Prints the main menu.
	IN: -
	OUT: -*/
	static void printMenu();
	/*Prints the menu for administrator mode.
	IN: -
	OUT: -*/
	static void printAdminMenu();
	/*Prints the menu for user mode.
	IN:-
	OUT-*/
	static void printUserMenu();
	/*Prints the events contained in a list.
	IN: the list
	OUT: -*/
	static void printEvents(DynamicVector v);
	/*Reads an integer given by user
	IN:-
	OUT:an integer*/
	int readInteger();
	/*UI for adding an event in the admin repo.
	IN: -
	OUT: 1 if the event was succesfuly added, -1 otherwise.*/
	int addAdminUI();
	/*UI for removing an event from the admin repo.
	IN: -
	OUT: 1 if the event was succesfuly removed, -1 otherwise.*/
	int removeAdminUI();
	/*UI for removing an event from the user repo.
	IN: -
	OUT: 1 if the event was succesfuly removed, -1 otherwise.*/
	int removeUserUI();
	/*UI for updating an event from the admin repo.
	IN: -
	OUT: 1 if the event was succesfuly updated, -1 otherwise.*/
	int updateUI();
	/*A function that runs the UI for the administrator mode.
	IN: -
	OUT: -*/
	void adminModeUI();
	/*A function that runs the UI for the user mode.
	IN: -
	OUT: -*/
	void userModeUI();
	/*A function that runs a subpart of the UI.
	IN: -
	OUT: -*/
	void userUI();

public:
	UI(const Controller& c) : ctrl(c) { }
	/*A function that runs the main UI .
	IN: -
	OUT: -*/
	void run();

};