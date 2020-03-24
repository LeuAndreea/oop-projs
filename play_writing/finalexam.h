#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_finalexam.h"

class finalexam : public QMainWindow
{
	Q_OBJECT

public:
	finalexam(QWidget *parent = Q_NULLPTR);

private:
	Ui::finalexamClass ui;
};
