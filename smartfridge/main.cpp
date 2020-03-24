#include "QtGuiApplication1.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Controller ctrl = Controller();

	QtGuiApplication1 w{ ctrl };
	w.show();
	return a.exec();
}
