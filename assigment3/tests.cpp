/*
#include <assert.h>

#include "tests.h"
#include "Validator.h"
#include "Event.h"
#include "Repository.h"
#include "Controller.h"
using namespace std;



void Test::testDateAndTime() {
	DateAndTime d = DateAndTime();
	d = DateAndTime(7, 9, 3, 3);
	assert(d.getDay() == 7);
	assert(d.getMonth() == 9);
	assert(d.getHours() == 3);
	assert(d.getMinutes() == 3);

	assert(d.toStringDateAndTime() == "07/09  03:03");
	
	d.setDay(18);
	d.setMonth(10);
	d.setHours(22);
	d.setMinutes(30);

	assert(d.getDay() == 18);
	assert(d.getMonth() == 10);
	assert(d.getHours() == 22);
	assert(d.getMinutes() == 30);

	assert(d.toStringDateAndTime() == "18/10  22:30");
}

void Test::testEvent() {
	DateAndTime d = DateAndTime();
	Event e1 = Event("Alternosfera concert", "National tour", "www", 23, d);
	assert(e1.getTitle() == "Alternosfera concert");
	assert(e1.getDescription() == "National tour");
	assert(e1.getLink() == "www");
	assert(e1.getNbOfPeople() == 23);
	assert(e1.getDateAndTime().getDay() == 0);

	e1 = e1;
	e1 = Event();

	e1.setTitle("a");
	e1.setDescription("b");
	e1.setLink("c");
	e1.setNbOfPeople(14);
	e1.updateDateAndTime(27, 4, 21, 00);
	assert(e1.getTitle() == "a");
	assert(e1.getDescription() == "b");
	assert(e1.getLink() == "c");
	assert(e1.getNbOfPeople() == 14);
	assert(e1.getDateAndTime().getDay() == 27);

	//assert(e1.toStringEvent() == "a \nb c\nNumber of people attending: 14\n 27/04 21:00");
}


void testAddRepoOK() {
	DateAndTime d = DateAndTime();
	Event e1 = Event("Alternosfera in concert", "National tour", "www", 23, d);
	Repository repo = Repository();
	assert(repo.addEvent(e1) == 1);

}

void testAddRepoNOTOK() {
	DateAndTime d = DateAndTime();
	Event e1 = Event("Alternosfera concert", "National tour", "www", 23, d);
	Repository repo = Repository();
	repo.addEvent(e1);
	assert(repo.addEvent(e1) == 0);

}

void testDeleteRepoOK() {
	DateAndTime d = DateAndTime();
	Event e1 = Event("Alternosfera concert", "National tour", "www", 23, d);
	Repository repo = Repository();
	repo.addEvent(e1);
	assert(repo.deleteEvent("Alternosfera concert") == 1);
}
void testDeleteRepoNOTOK() {
	DateAndTime d = DateAndTime();
	Event e1 = Event("Alternosfera concert", "National tour", "www", 23, d);
	Repository repo = Repository();
	repo.addEvent(e1);
	assert(repo.deleteEvent("Jazz in the park") == -1);
}

void testUpdateRepoOK() {
	DateAndTime d = DateAndTime();
	Event e1 = Event("Alternosfera concert", "National tour", "www", 23, d);
	Repository repo = Repository();
	repo.addEvent(e1);
	assert(repo.updateEvent("Alternosfera concert", "Works of art students", "www.", 34, 1,1,1,1) == 1);
	
}
void testUpdateRepoNOTOK() {
	DateAndTime d = DateAndTime();
	Event e1 = Event("Alternosfera concert", "National tour", "www", 23, d);
	Repository repo = Repository();
	repo.addEvent(e1);
	assert(repo.updateEvent("Jazz in the park", "Works of art students", "www.", 34, 1, 1, 1, 1) == -1);
}

void testGetEvents() {
	DateAndTime d = DateAndTime();
	Event e1 = Event("Alternosfera concert", "National tour", "www", 23, d);
	Repository repo = Repository();
	repo.addEvent(e1);
	Event e2 = Event("Art gallery", "Works of art students", "www", 3, d);
	repo.addEvent(e2);
	vector<Event> v = repo.getEvents();
	assert(v.size() == 2);
}

void testFilterByMonth() {
	DateAndTime d = DateAndTime();
	Event e1 = Event("Alternosfera in concert", "National tour", "www", 23, d);
	DateAndTime d2 = DateAndTime(12,10,23,30);
	Event e2 = Event("Zdob si zdub", "National tour", "www", 23, d2);
	Repository repo = Repository();
	repo.addEvent(e1);
	repo.addEvent(e2);
	vector<Event> v = repo.filterByMonth(10);
	assert(v.size() == 1);
}
void Test::testRepository() {
	testAddRepoOK();
	testAddRepoNOTOK();
	testDeleteRepoOK();
	testDeleteRepoNOTOK();
	testUpdateRepoOK();
	testUpdateRepoNOTOK();
	testGetEvents();
	testFilterByMonth();
}
void testGetRepo() {
	DateAndTime d = DateAndTime();
	Repository repo1 = Repository();
	Event e1 = Event("Alternosfera concert", "National tour", "www", 23, d);
	repo1.addEvent(e1);
	Repository repo2 = Repository();
	Controller ctrl = Controller(repo1, repo2);
	Repository repo3 = ctrl.getAdminRepo();
	assert(repo3.getEvents().size() == 1);
	Repository repo4 = ctrl.getUserRepo();
	assert(repo4.getEvents().size() == 0);
}


void testAddEventCtrlOK() {
	Repository repo1 = Repository();
	Repository repo2 = Repository();
	Controller ctrl = Controller(repo1,repo2);
	assert(ctrl.addEventAdmin("Alternosfera concert", "National tour", "www", 23, 12,10, 0, 0) == 1);

}

void testAddEventCtrlNOTOK() {
	Repository repo1 = Repository();
	Repository repo2 = Repository();
	Controller ctrl = Controller(repo1,repo2);
	ctrl.addEventAdmin("Alternosfera concert", "National tour", "www", 23, 0, 0, 0, 0);
	assert(ctrl.addEventAdmin("Alternosfera concert", "There will be free beer!", "www", 40, 0, 0, 0, 0) == -1);
	assert(ctrl.addEventAdmin("", "National tour", "www", 23, 0, 0, 0, 0) == -1);
}
void testAddEventCtrlUserOK() {
	Repository repo1 = Repository();
	Repository repo2 = Repository();
	Controller ctrl = Controller(repo1, repo2);
	DateAndTime d = DateAndTime();
	Event e = Event("Alternosfera concert", "National tour", "www", 23, d);
	assert(ctrl.addEventUser(e) == 1);
}

void testAddEventCtrlUserNOTOK() {
	Repository repo1 = Repository();
	Repository repo2 = Repository();
	Controller ctrl = Controller(repo1, repo2);
	DateAndTime d = DateAndTime();
	Event e = Event("Alternosfera concert", "National tour", "www", 23, d);
	ctrl.addEventUser(e);
	assert(ctrl.addEventUser(e) == 0);
}

void testDeleteCtrlOK() {
	Repository repo1 = Repository();
	Repository repo2 = Repository();
	Controller ctrl = Controller(repo1, repo2);
	ctrl.addEventAdmin("Alternosfera concert", "National tour", "www", 23, 6, 6, 0, 0);
	assert(ctrl.deleteEventAdmin("Alternosfera concert") == 1);
}
void testDeleteCtrlNOTOK() {
	Repository repo1 = Repository();
	Repository repo2 = Repository();
	Controller ctrl = Controller(repo1, repo2);
	ctrl.addEventAdmin("Jazz in the park", "National tour", "www", 23, 6, 6, 0, 0);
	assert(ctrl.deleteEventAdmin("Alternosfera concert") == -1);
}

void testDeleteCtrlUserOK() {
	Repository repo1 = Repository();
	Repository repo2 = Repository();
	Controller ctrl = Controller(repo1, repo2);
	DateAndTime d = DateAndTime();
	Event e = Event("Jazz in the park", "National tour", "www", 23, d);
	ctrl.addEventUser(e);
	assert(ctrl.deleteEventUser("Jazz in the park") == 1);
}

void testDeleteCtrlUserNOTOK() {
	Repository repo1 = Repository();
	Repository repo2 = Repository();
	Controller ctrl = Controller(repo1, repo2);
	DateAndTime d= DateAndTime();
	Event e = Event("Jazz in the park", "National tour", "www", 23, d);
	ctrl.addEventUser(e);
	assert(ctrl.deleteEventAdmin("Alternosfera concert") == -1);
}
void testUpdateCtrlOK() {
	Repository repo1 = Repository();
	Repository repo2 = Repository();
	Controller ctrl = Controller(repo1, repo2);
	ctrl.addEventAdmin("Jazz in the park", "National tour", "www", 23, 6, 6, 0, 0);
	assert(ctrl.updateEventAdmin("Jazz in the park", "Good music, good vibes", "www", 100, 1,5,1,1) == 1);
}

void testUpdateCtrlNOTOK() {
	Repository repo1 = Repository();
	Repository repo2 = Repository();
	Controller ctrl = Controller(repo1, repo2);
	ctrl.addEventAdmin("Jazz in the park", "National tour", "www", 23, 0, 0, 0, 0);
	assert(ctrl.updateEventAdmin("Alternosfera in concert", "Good music, good vibes", "www", 100, 1, 1, 1, 1) == -1);
}

void testFilterByMonthOK() {
	Repository repo1 = Repository();
	Repository repo2 = Repository();
	DateAndTime d = DateAndTime();
	Controller ctrl = Controller(repo1, repo2);


	ctrl.addEventAdmin("Alternosfera concert", "National tour", "www", 23, 2, 5, 0, 0);
	ctrl.addEventAdmin("Irish pub opening", "There will be free beer!", "www", 40, 7, 7, 0, 0);
	ctrl.addEventAdmin("Art gallery", "Works of art students", "www", 3, 15, 6, 0, 0);
	ctrl.addEventAdmin("Jazz in the park", "Good music, good vibes", "www", 100, 28, 7, 0, 0);
	ctrl.addEventAdmin("Free Java Script course", "Limited places, complete online formular", "www", 16, 14, 5, 0, 0);

	vector<Event> result = ctrl.filterByMonth(7);
	assert(result.size() == 2);
	assert(result.at(0).getTitle() == "Irish pub opening");
	assert(result.at(1).getTitle() == "Jazz in the park");

}
void Test::testController() {
	testGetRepo();
	testAddEventCtrlOK();
	testAddEventCtrlNOTOK();
	testAddEventCtrlUserOK();
	testAddEventCtrlUserNOTOK();
	testDeleteCtrlOK();
	testDeleteCtrlNOTOK();
	testDeleteCtrlUserOK();
	testDeleteCtrlUserNOTOK();
	testUpdateCtrlOK();
	testUpdateCtrlNOTOK();
	testFilterByMonthOK();
}
void Test::testAll() {
	testDateAndTime();
	testEvent();
	testRepository();
	testController();
	
}
*/