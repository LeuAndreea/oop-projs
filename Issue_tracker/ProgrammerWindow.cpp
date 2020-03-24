#include "ProgrammerWindow.h"

ProgrammerWindow::ProgrammerWindow(Session &s, string user,QWidget *parent)
	: s{ s }, user(user),QWidget(parent)
{
	this->setWindowTitle(QString::fromStdString(this->user));
	this->populateList();

	this->connect(this->ui.resolveButton, &QPushButton::clicked, this, &ProgrammerWindow::solveIssue);
	
	ui.setupUi(this);

	this->s.addObserver(this);
	this->show();
}

ProgrammerWindow::~ProgrammerWindow()
{
}

void ProgrammerWindow::populateList()
{
	this->ui.listWidget->clear();
	IssueRepository  repo = this->s.getRepo();
	//vector < Issue > issues= this->s.getRepo().getIssues();
	///for (auto i : issues)
		//this->ui.listWidget->addItem(QString::fromStdString(i.toString()));
}

void ProgrammerWindow::update()
{
	this->populateList();
}

void ProgrammerWindow::solveIssue()
{
	for (int i=0; i<this->s.getRepo().getIssues().size(); i++)
		if (this->ui.listWidget->item(i)->isSelected()) {
			this->s.updateTask(i);
		}

}
