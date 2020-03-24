#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TaskManager.h"
#include "Controller.h"

using namespace std;
class TaskManager : public QMainWindow
{
	Q_OBJECT
private:
	Controller ctrl;
public:
	TaskManager(Controller ctrl, QWidget *parent = Q_NULLPTR);
	void populateList();
	void computeDuration();
private:
	Ui::TaskManagerClass ui;
	

};
