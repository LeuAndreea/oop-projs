#include "IssueTracker.h"
#include <QtWidgets/QApplication>
#include "Session.h"
#include "ProgrammerWindow.h"
#include "TesterWindow.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//IssueTracker w;
	//w.show();
	IssueRepository repo;
	Session s=Session(repo);
	
	for (auto u : s.getRepo().getUsers()) {
		if (u.getType() == "programmer")
			ProgrammerWindow *w = new ProgrammerWindow(s, u.getName());
		if (u.getType() == "tester")
			TesterWindow *w = new TesterWindow(s, u.getName());
	}
		
	return a.exec();
}
