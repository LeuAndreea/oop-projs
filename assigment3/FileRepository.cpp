#include "FileRepository.h"

void FileRepository::readFromFile()
{
	ifstream file(this->filename, ifstream::in);

	if (!file.is_open())
		throw Exception("File could not be opened!");

	Event fileEvent;
	while (file >> fileEvent)
	{
		//vector<Event>::iterator it = find_if(this->events.begin(), this->events.end(), [fileEvent](Event ev) {return fileEvent.getTitle() == ev.getTitle(); })
		this->events.push_back(fileEvent);
	}

	file.close();
		
}

void FileRepository::writeToFile()
{
	ofstream file(this->filename, ofstream::out);

	if (!file.is_open())
		throw Exception("File could not be opened!");

	for (auto song : this->events)
	{
		file << song;
	}
	file.close();
	
}

void FileRepository::add(const Event event){

	//vector<Event>::iterator it = find_if(this->events.begin(), this->events.end(), [event](Event ev) {return event.getTitle() == ev.getTitle(); });
	//if (it != this->events.end())
	//	throw Exception("Event already in repo.");
	this->events.push_back(event);
	this->writeToFile();

}
 