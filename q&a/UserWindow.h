#pragma once

#include <QWidget>
#include "ui_UserWindow.h"
#include "QASession.h"
#include "Observer.h"

using namespace std;

class UserWindow : public QWidget, public Observer
{
	

private:
	Ui::UserWindow ui;
	Session &session;
	string user;

	Q_OBJECT

public:
	
	UserWindow(Session &session,string user,QWidget *parent = Q_NULLPTR);
	~UserWindow();
	string getUser(){ return this->user; }
	void populateList();
	void showAnswers();
	void addQuestion();
	void addAnswer();
	void update() override { this->showAnswers(); this->populateList(); }
};
