#pragma once
#include "Event.h"
#include <vector>
#include <fstream>
class TextFile{
public:
	virtual void writeToFile(vector<Event> events)=0;
};

class HTMLFile : public TextFile {
public:
	void writeToFile(vector<Event> events) override;
};

class CSVFile : public TextFile {
public:
	void writeToFile(vector<Event> events) override;
};

