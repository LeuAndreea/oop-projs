#pragma once
#include "Item.h"
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;
class Controller {
private:
	vector<Item> items;
public:
	Controller() { this->readFromFile(); };
	Controller(vector<Item> items) : items(items) { }
	vector<Item> getItems() { return this->items; }
	void readFromFile();
	void deleteItem(const string &name);
	vector<Item> filterItems(const string &category);
};
