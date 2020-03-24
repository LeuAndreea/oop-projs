#include "TesterWindow.h"

TesterWindow::TesterWindow(Session &s, string user,QWidget *parent)
	: s(s),user(user),QWidget(parent)
{
	this->s.addObserver(this);
	this->setWindowTitle(QString::fromStdString(user));
	this->show();
	ui.setupUi(this);
}

TesterWindow::~TesterWindow()
{
}
