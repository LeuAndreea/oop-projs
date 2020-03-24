#include <string>

using namespace std;

class Task {
private:
	string description;
	int duration, priority;
public:
	Task(string description, int duration, int priority) : description(description), duration(duration), priority(priority) {}
	string getDescription() { return this->description; }
	int getDuration() { return this -> duration; }
	int getPriority() { return this->priority; }
	string toStringItem();

};