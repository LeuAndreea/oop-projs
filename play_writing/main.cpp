#include "finalexam.h"
#include <QtWidgets/QApplication>
#include "Repository.h"
#include "WriterWindow.h"
#include "SeinorWWindow.h"
#include <iostream>
#include <assert.h>
void testadd() {
	Repository r;
	assert(r.getIdea().size() == 3);
	Idea d{ "dwqdq", "proposed","andreea",4 };
	r.addIdea(d);
	assert(r.getIdea().size() == 4);
}

void testremove() {
	Repository r;
	assert(r.getIdea().size() == 3);
	Idea d{ "dwqdq", "proposed","andreea",4 };
	r.addIdea(d);
	assert(r.getIdea().size() == 4);
	r.removeIdea(1);
	assert(r.getIdea().size() == 3);
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//finalexam w;
	//w.show();
	Repository r;
	//testadd();
	//testremove();
	
	vector<Writer> wr = r.getWriters();
	for (auto w : wr) {
		//if (w.getExp() == "senior")
		//	SeinorWWindow *b = new SeinorWWindow{ r, w.getName() };
		//else
			WriterWindow *a = new WriterWindow{ r,w.getName(),w.getExp()};
	}

	
	
	
	return a.exec();
}
