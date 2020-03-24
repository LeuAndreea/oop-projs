#include "TaskManager.h"

TaskManager::TaskManager(Controller ctrl,QWidget *parent)
	: ctrl(ctrl), QMainWindow(parent)
{
	ui.setupUi(this);
	this->populateList();

	this->connect(this->ui.pushButton, &QPushButton::clicked, this, &TaskManager::computeDuration);
}

void TaskManager::populateList()
{
	
	vector<Task> aux = this->ctrl.getTasks();
	for (auto el : aux)
		this->ui.listWidget->addItem(QString::fromStdString(el.toStringItem()));
}

void TaskManager::computeDuration()
{
	QString str= this->ui.lineEdit->text();
	int priority = stoi(str.toStdString());
	int result = 0;
	for (auto el : this->ctrl.getTasks())
		if (el.getPriority() == priority)
			result += el.getDuration();
	this->ui.label->setText(QString::fromStdString(to_string(result)));
	
}
