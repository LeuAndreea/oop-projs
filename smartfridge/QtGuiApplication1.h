#pragma once
#include "Controller.h"
#include "ui_QtGuiApplication1.h"
#include <QtWidgets/QMainWindow>


class QtGuiApplication1 : public QMainWindow
{
	Q_OBJECT

public:
	QtGuiApplication1(Controller ctrl,QWidget *parent = Q_NULLPTR);
	void populateList();
	void deleteItem();
	void filterItems();
private:
	Ui::QtGuiApplication1Class ui;
	Controller ctrl;
};
