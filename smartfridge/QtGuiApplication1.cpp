#include "QtGuiApplication1.h"
#include "Item.h"

QtGuiApplication1::QtGuiApplication1(Controller ctrl,QWidget *parent)
	: QMainWindow(parent), ctrl(ctrl)
{
	ui.setupUi(this);
	this->populateList();
	
	this->connect(this->ui.deleteButton, &QPushButton::clicked, this, &QtGuiApplication1::deleteItem);
	this->connect(this->ui.filterButton, &QPushButton::clicked, this, &QtGuiApplication1::filterItems);
}

void QtGuiApplication1::populateList() {
	this->ui.ShoppingList->clear();
	vector<Item> items = this->ctrl.getItems();
	for (auto el : items)
		this->ui.ShoppingList->addItem(QString::fromStdString(el.toStringItem()));
}

void QtGuiApplication1::deleteItem()
{
	QString str = this->ui.deleteLine->text();
	this->ctrl.deleteItem(str.toStdString());

	this->ui.ShoppingList->clear();
	this->populateList();
}

void QtGuiApplication1::filterItems()
{
	QString str = this->ui.filterLine->text();
	vector<Item> items = ctrl.filterItems(str.toStdString());

	this->ui.ShoppingList->clear();
	for (auto el : items)
		this->ui.ShoppingList->addItem(QString::fromStdString(el.toStringItem()));
}
