#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QA.h"

class QA : public QMainWindow
{
	Q_OBJECT

public:
	QA(QWidget *parent = Q_NULLPTR);

private:
	Ui::QAClass ui;
};
