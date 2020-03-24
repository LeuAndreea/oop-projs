#include "WriterWindow.h"
#include "qmessagebox.h"


WriterWindow::WriterWindow(Repository &repo, string name,string status,QWidget *parent)
	: repo{ repo }, name(name),status(status), QWidget(parent)
{

	ui.setupUi(this);
	this->QWidget::setWindowTitle(QString::fromStdString(this->name));
	this->populateList();
	this->show();

	this->repo.addObs(this);

	this->connect(this->ui.addButton, &QPushButton::clicked, this, &WriterWindow::addIdea);
	this->connect(this->ui.savebutton, &QPushButton::clicked, this, &WriterWindow::savePlot);
	this->connect(this->ui.deleteButton, &QPushButton::clicked, this, &WriterWindow::removeIdea);
	this->connect(this->ui.acceptButton, &QPushButton::clicked, this, &WriterWindow::acceptIdea);

}

WriterWindow::~WriterWindow()
{

}

void WriterWindow::populateList()
{
	this->ui.listWidget->clear();
	
	vector<Writer> writers = this->repo.getWriters();
	vector <Idea> ideas = this->repo.getIdea();
	
	
	for (auto i : ideas)
		this->ui.listWidget->addItem(QString::fromStdString(i.toString()));

}

void WriterWindow::update()
{
	this->populateList();
}

void WriterWindow::addIdea()
{
	QString descr = this->ui.descrline->text();
	if (descr.toStdString().size() == 0) {
		QMessageBox::critical(0, "Error", "Input not good.");
		return;
	}
	QString act = this->ui.actline->text();
	int a = stoi((act.toStdString()));
	if (a < 0 || a>3) {
		QMessageBox::critical(0, "Error", "Input not good.");
		return;
	}
	Idea i{ descr.toStdString(),"proposed",this->name, a };
	this->repo.addIdea(i);
}

void WriterWindow::removeIdea()
{
	if (this->status != "senior") {
		QMessageBox::critical(0, "Error", "You can.t do that!");
		return;
	}
	for (int i = 0; i <= this->repo.getIdea().size(); i++)
		if (this->ui.listWidget->item(i)->isSelected())
			this->repo.removeIdea(i);
}

void WriterWindow::acceptIdea()
{
	if (this->status != "senior")
		QMessageBox::critical(0, "Error", "You can.t do that!");
	for (int i = 0; i <= this->repo.getIdea().size(); i++)
		if (this->ui.listWidget->item(i)->isSelected())
			this->repo.removeIdea(i);
}
