#include "Task.h"

string Task::toStringItem()
{
	return this->getDescription() + " " + to_string(this->getDuration()) + " " +to_string(this->getPriority());

}
