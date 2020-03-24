#pragma once
#include "Observer.h"
#include <QWidget>
#include "ui_WriterWindow.h"
#include "Repository.h"
#include <string>
#include <qalgorithms.h>
using namespace std;
class WriterWindow : public QWidget, public Observer
{
	Q_OBJECT

private:
	Ui::WriterWindow ui;
	Repository &repo;
	string name;
	string status;
public:
	WriterWindow(Repository &repo, string name,string status,QWidget *parent = Q_NULLPTR);
	~WriterWindow();
	void populateList();
	void update() override;
	void addIdea();
	void savePlot() { this->repo.savePlot(); }
	void removeIdea();
	void acceptIdea();

};
