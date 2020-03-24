#include "Item.h"

string Item::toStringItem()
{
	string s = this->getName() + "," + this->getCategory() + "," +to_string(this->getQuantity());
	return s;
}
