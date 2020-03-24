#include "UI.h"
#include "Validator.h"

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
	cout << "4.Generate file of events.\n";
	cout << endl;
}

void UI::printUserMenu() {
	cout << "0.Exit.\n";
	cout << "1.List events happening in a specific month.\n";
	cout << "2.Remove event from list.\n";
	cout << "3.View list of events.\n";
}

void UI::printEvents(vector<Event> v) {

	if (v.size() == 0)
		cout << "There are no events to display." << endl;
	string s;
	for (auto ev : v)
		cout << ev.toStringEvent() << endl;
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

void UI::readFromFile()
{
	try {
		this->ctrl.readFromFile();
	}
	catch (Exception &ex) {
		cout << ex.getError();
	}
}

void UI::addAdminUI() {
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

	this->ctrl.addEventAdmin(title, description, link, nbOfPeople, day, month, hours, minutes);
	
}
void UI::removeAdminUI() {
	string title;
	cout << "Give the title of the event you want to delete.";
	getline(cin, title);
	this->ctrl.deleteEventAdmin(title);
	
}

void UI::removeUserUI() {
	string title;
	cout << "Give the title of the event you want to remove." << endl;
	getline(cin, title);

	 this->ctrl.deleteEventUser(title);

}
void UI::updateUI() {
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

	this->ctrl.updateEventAdmin(title, description, link, nbOfPeople, day, month, hours, minutes);
}

void UI :: adminModeUI() {
	int command;
	while (true) {
		cout << "Give the type of file you want: " << endl;
		cout << "1.csv" << endl;
		cout << "2.html" << endl;
		command = readInteger();
		this->ctrl.setFileHandler(command);
		printAdminMenu();
		cout << "Give the command:";
		command = readInteger();

		switch (command) {
		case 0:
			return;
		case 1: {
			this->addAdminUI();
			break;
		}
		case 2: {
			this->removeAdminUI();
			break;
		}
		case 3: {
			this->updateUI();
			break;
		}
		case 4: {
			this->ctrl.printToFile();
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
			removeUserUI();
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

	vector<Event> v = this->ctrl.filterByMonth(month);
	int command;
	Event event;
	if (v.size() == 0) {
		cout << "There are no events to display." << endl;
		return;
	}
		while (true) {
		for (auto event: v){
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
				ctrl.addEventUser(event);
				cout << "Event succesfuly added!";
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