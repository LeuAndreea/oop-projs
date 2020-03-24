#pragma once
#include "Observer.h"
#include "Session.h"
#include <QWidget>
#include "ui_ProgrammerWindow.h"

class ProgrammerWindow : public QWidget, public Observer
{
	Q_OBJECT

public:
	ProgrammerWindow(Session &s, string user,QWidget *parent = Q_NULLPTR);
	~ProgrammerWindow();
	
	string getUser() { return this->user; }
	void populateList();
	void update() override;

	void solveIssue();
private:
	Ui::ProgrammerWindow ui;
	Session &s;
	string user;
};
