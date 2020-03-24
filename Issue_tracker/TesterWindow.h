#pragma once

#include "Observer.h"
#include <QWidget>
#include "ui_TesterWindow.h"
#include "Session.h"

class TesterWindow : public QWidget, public Observer
{
	Q_OBJECT

public:
	TesterWindow(Session &s,string user,QWidget *parent = Q_NULLPTR);
	~TesterWindow();
	string getUser() { return this->user; }
	void update() override {}
private:
	Ui::TesterWindow ui;
	Session &s;
	string user;
};
