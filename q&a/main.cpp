#include "QA.h"
#include <QtWidgets/QApplication>
#include "QASession.h"
#include "UserWindow.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//QA w;
	//w.show();
	Session s;
	
	for (auto user : s.getUsers()) {
		UserWindow *window = new UserWindow{ s, user };

	}
	
	return a.exec();
}
