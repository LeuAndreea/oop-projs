#include "TaskManager.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Controller ctrl;
	TaskManager w{ ctrl };
	w.show();
	return a.exec();
}
