#include "Controller.h"
#pragma once

void Controller::readFromFile()
{
	ifstream f("in.txt");
	string name, category, quantity;
	while (f >> name >> category >> quantity) {
		Item i=Item(name, category, stoi(quantity));
		this->items.push_back(i);
	}
}

void Controller::deleteItem(const string & name)
{
	vector<Item>::iterator it = find_if(this->items.begin(), this->items.end(), [name](Item item) { return item.getName() == name; });
	if (it != this->items.end())
		this->items.erase(it);
}

vector<Item> Controller::filterItems(const string & category)
{
	vector<Item> result;

	for (auto el : this->items)
		if (el.getCategory() == category)
			result.push_back(el);
	return result;
}
