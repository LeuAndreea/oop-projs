#include "UI.h"
#include "Validator.h"

#include <iostream>
#include <string>


using namespace std;
void UI :: printMenu() {
	cout << "0.Exit\n";
	cout << "1.Administrator mode.\n";
	cout << "2.User mode.\n";
	cout << endl;
}

void UI::printAdminMenu() {
	cout << "0.Exit\n";
	cout << "1.Add event\n";
	cout << "2.Delete event\n";
	cout << "3.Update event\n";
	cout << "4.List all events.\n";
	cout << endl;
}

void UI::printUserMenu() {
	cout << "0.Exit.\n";
	cout << "1.List events happening in a specific month.\n";
	cout << "2.Remove event from list.\n";
	cout << "3.View list of events.\n";
}

void UI::printEvents(DynamicVector v) {

	if (v.getSize() == 0)
		cout << "There are no events to display." << endl;
	string s;
	for (int i = 0; i < v.getSize(); i++) {
		s = v.getElementAtIndex(i).toStringEvent();
		cout << s << endl;
	}
}
int UI::readInteger( ) {

	int nb, valid;
	char s[20];

	while (1) {
		valid = 1;
		fgets(s, 20, stdin);
		s[strlen(s) - 1] = '\0';
		for (int i = 0; i < strlen(s); i++) {
			if (!isdigit(s[i])) {
				valid = 0;
				break;
			}

		}
		if (valid) {
			nb = atoi(s);
			return nb;
		}
		else
			cout << "Error reading number, try again!" << endl;
	}
}

int UI::addAdminUI() {
	string title, description, link;
	int nbOfPeople,minutes, hours, month,day;
	cout << "Give title: ";
	getline(cin, title);
	
	cout << "Give description: ";
	getline(cin, description);
	
	cout << "Give link: ";
	getline(cin, link);
	
	cout << "Give nb of people: "<<endl;
	nbOfPeople = readInteger();
	cout << "Give day: " << endl;
	day= readInteger();
	cout << "Give month: " << endl;
	month = readInteger();
	cout << "Give hour: " << endl;
	hours= readInteger();
	cout << "Give minute: " << endl;
	minutes= readInteger();

	return this->ctrl.addEventAdmin(title, description, link, nbOfPeople, day, month, hours, minutes);
	
}
int UI::removeAdminUI() {
	string title;
	cout << "Give the title of the event you want to delete.";
	getline(cin, title);
	return this->ctrl.deleteEventAdmin(title);
	
	return 0;
}

int UI::removeUserUI() {
	string title;
	cout << "Give the title of the event you want to remove." << endl;
	getline(cin, title);

	return this->ctrl.deleteEventUser(title);

}
int UI::updateUI() {
	string title, description, link;
	int nbOfPeople, day, month, hours, minutes;
	cout << "Give the title of the product you want to update.";
	getline(cin, title);
	cout << "If you don't want to update a field, leave the space blank." << endl;
	cout << "Give description: ";
	getline(cin, description);

	cout << "Give link: ";
	getline(cin, link);

	cout << "Give nb of people: " << endl;
	nbOfPeople = readInteger();
	cout << "Give day: " << endl;
	day = readInteger();
	cout << "Give month: " << endl;
	month = readInteger();
	cout << "Give hour: " << endl;
	hours = readInteger();
	cout << "Give minute: " << endl;
	minutes = readInteger();

	return this->ctrl.updateEventAdmin(title, description, link, nbOfPeople, day, month, hours, minutes);
	return 0;
}

void UI :: adminModeUI() {
	int command;
	while (true) {
		printAdminMenu();
		cout << "Give the command:";
		command = readInteger();

		switch (command) {
		case 0:
			return;
		case 1: {
			int i = this->addAdminUI();
			if (i == 1)
				cout << "Event succesfully added";
			else if (i == 0)
				cout << "Event already registered!";
			else
				cout << "Some data was invalid.";
			break;
		}
		case 2: {
			int i = this->removeAdminUI();
			if (i == 1)
				cout << "Event deleted.";
			else
				cout << "Event not registered";
			break;
		}
		case 3: {
			int i = this->updateUI();
			if (i == 1)
				cout << "Event updated.";
			else
				cout << "Event not registered.";
			break;
		}
		case 4: {
			printEvents(this->ctrl.getAdminRepo().getEvents());
			break;
		}

	}
}

}

void UI::userModeUI() {
	int command;
	while (1) {
		printUserMenu();
		cout << "Give the command:";
		command = readInteger();

		switch (command) {
		case 0:
			return;
		case 1: {
			userUI();
			break;
		}
		case 2: {
			int i = removeUserUI();
			if (i == 1)
				cout << "Event succesfully deleted.";
			else
				cout << "Event not found in the list";
			break;
		}
		case 3: {
			printEvents(this->ctrl.getUserRepo().getEvents());
			break;
		}
		}
	}
}

void UI::userUI()
{
	int month;
	cout << "Please enter the month from which you want to see events:";
	month = readInteger();

	while (!Validator::validateMonth(month)) {
		cout << "Invalid month! Please try again!" << endl;
		month = readInteger();
	}

	DynamicVector v = this->ctrl.filterByMonth(month);
	int command;
	Event event;
	if (v.getSize() == 0)
		cout << "There are no events to display." << endl;
	while (true) {
		for (int i = 0; i < v.getSize(); i++) {
			event = v.getElementAtIndex(i);
			cout << event.toStringEvent() << endl;
			cout << "1.Add event" << endl;
			cout << "2.Show next event" << endl;
			cout << "0.Exit" << endl;
			command = readInteger();
			while (command < 0 || command>2) {
				cout << "Invalid command! Try again." << endl;
				command = readInteger();
			}
			if (command == 1) {
				int i = this->ctrl.addEventUser(event);
				if (i == 1)
					cout << "Event succesfuly added!";
				else
					cout << "Event already added!";
			}
			if (command == 0)
				return;
		}
	}
}

void UI::run() {
	while (1) {
		printMenu();
		int command = 0;
		cout << "Give the comand:";
		cin >> command;
		cin.ignore();
		if (command == 0)
			return;
		if (command == 1)
			adminModeUI();
		if (command == 2)
			userModeUI();
	}
}