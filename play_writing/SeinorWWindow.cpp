#include "SeinorWWindow.h"

SeinorWWindow::SeinorWWindow(Repository &repo, string name,QWidget *parent)
	: repo(repo),name(name),QWidget(parent)
{
	ui.setupUi(this);
	
	this->QWidget::setWindowTitle(QString::fromStdString(this->name));
	this->populateList();
	this->show();

	this->repo.addObs(this);

	this->connect(this->ui.addButton, &QPushButton::clicked, this, &SeinorWWindow::addIdea);
	this->connect(this->ui.saveButton, &QPushButton::clicked, this, &SeinorWWindow::savePlot);
	
	ui.setupUi(this);
}

SeinorWWindow::~SeinorWWindow()
{
}

void SeinorWWindow::populateList()
{
	this->ui.listWidget->clear();

	vector<Writer> writers = this->repo.getWriters();
	vector <Idea> ideas = this->repo.getIdea();


	for (auto i : ideas)
		this->ui.listWidget->addItem(QString::fromStdString(i.toString()));

}

void SeinorWWindow::update()
{
	this->populateList();
}

void SeinorWWindow::addIdea()
{
	QString descr = this->ui.descrline->text();
	QString act = this->ui.actline->text();

	Idea i{ descr.toStdString(),"proposed",this->name, stoi((act.toStdString())) };
	this->repo.addIdea(i);
}

