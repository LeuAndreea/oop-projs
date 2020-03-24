#pragma once

#include <QWidget>
#include "ui_SeinorWWindow.h"
#include "Repository.h"

class SeinorWWindow : public QWidget, public Observer
{
	Q_OBJECT

public:
	SeinorWWindow(Repository &repo, string name,QWidget *parent = Q_NULLPTR);
	~SeinorWWindow();
	void populateList();
	void update() override;
	void addIdea();
	void savePlot() { this->repo.savePlot(); }

private:
	Ui::SeinorWWindow ui;
	Repository &repo;
	string name;
};
