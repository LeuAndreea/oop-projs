#include <assert.h>

#include "tests.h"
#include "DynamicVector.h"
#include "Validator.h"
#include "Event.h"
#include "Repository.h"
#include "Controller.h"
using namespace std;

void Test::testDynamicVector() {
	DynamicVector v = DynamicVector(3);
	
	DateAndTime d = DateAndTime();
	Event e1 = Event("a", "b", "c", 23, d);
	Event e2 = Event("aa", "b", "c", 23, d);
	Event e3 = Event("a", "b", "c", 23, d);
	Event e4 = Event("a", "b", "c", 23, d);
	Event e5 = Event("abc", "b", "c", 23, d);
	
	v.add(e1);
	v.add(e2);
	v.add(e3);
	v.add(e4);
	v.deleteElement(0);
	v.modifyElem(1, e4);
	DynamicVector v1 = v;

	DynamicVector v3 = DynamicVector(3);
	v3 = v;
	v = v;
	assert(v3.getSize() == 3);
	assert(v.getElementAtIndex(0).getTitle() == "aa");
	Event* e = v.getAllElems();
	
	//v3 = v3 + &e;
}

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

void Test::testValidator() {
	DateAndTime d = DateAndTime();
	assert(Validator::validateDateAndTime(d) == false);
	d = DateAndTime(43, 4, 21, 00);
	assert(Validator::validateDateAndTime(d) == false);
	d = DateAndTime(27, 14, 21, 00);
	assert(Validator::validateDateAndTime(d) == false);
	d = DateAndTime(27, 4, 25, 00);
	assert(Validator::validateDateAndTime(d) == false);
	d = DateAndTime(27, 2, 12, 00);
	assert(Validator::validateDateAndTime(d) == false);
	d = DateAndTime(12, 4, 12, 00);
	assert(Validator::validateDateAndTime(d) == false);
	d = DateAndTime(27, 4, 21, 78);
	assert(Validator::validateDateAndTime(d) == false);
	Event e1 = Event("Alternosfera concert", "National tour", "www", 23, d);
	assert(Validator::validateEvent(e1) == false);

	d = DateAndTime(27, 5, 21, 00);
	assert(Validator::validateDateAndTime(d) == true);
	e1 = Event("Alternosfera concert", "National tour", "www", 23, d);
	assert(Validator::validateEvent(e1) == true);

	e1 = Event("", "National tour", "www", 23, d);
	assert(Validator::validateEvent(e1) == false);
	e1 = Event("Alternosfera concert", "", "www", 23, d);
	assert(Validator::validateEvent(e1) == false);
	e1 = Event("Alternosfera concert", "National tour", "", 23, d);
	assert(Validator::validateEvent(e1) == false);

	assert(Validator::validateMonth(5) == true);
	assert(Validator::validateMonth(2) == false);
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
	assert(repo.addEvent(e1) == -1);

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
	DynamicVector v = repo.getEvents();
	assert(v.getSize() == 2);
}

void testFilterByMonth() {
	DateAndTime d = DateAndTime();
	Event e1 = Event("Alternosfera in concert", "National tour", "www", 23, d);
	DateAndTime d2 = DateAndTime(12,5,23,30);
	Event e2 = Event("Zdob si zdub", "National tour", "www", 23, d2);
	Repository repo = Repository();
	repo.addEvent(e1);
	repo.addEvent(e2);
	DynamicVector v = repo.filterByMonth(5);
	assert(v.getSize() == 1);
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
	assert(repo3.getEvents().getSize() == 1);
	Repository repo4 = ctrl.getUserRepo();
	assert(repo4.getEvents().getSize() == 0);
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
	assert(ctrl.addEventUser(e) == -1);
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
	assert(ctrl.deleteEventAdmin("Jazz in the park") == 1);
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

	DynamicVector result = ctrl.filterByMonth(7);
	assert(result.getSize() == 2);
	assert(result.getElementAtIndex(0).getTitle() == "Irish pub opening");
	assert(result.getElementAtIndex(1).getTitle() == "Jazz in the park");

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
	testDynamicVector();
	testDateAndTime();
	testEvent();
	testValidator();
	testRepository();
	testController();
	
}