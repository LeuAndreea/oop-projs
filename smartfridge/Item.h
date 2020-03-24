
#pragma once
#include <string>

using namespace std;

class Item {
private:
	string name;
	string category;
	int quantity;

public:
	Item() {};
	Item(string name, string category, int quantity) : name(name), category(category), quantity(quantity) {}
	string getName() { return this->name; }
	string getCategory() { return this->category; }
	int getQuantity() { return this->quantity; }
	string toStringItem();
	~Item() {}
};
