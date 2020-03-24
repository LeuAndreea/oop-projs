#pragma once

#include "Repository.h"
#include <fstream>
class FileRepository : public Repository {
private:
	string filename;
public:
	FileRepository(const string& filename) :filename(filename) { }
	void writeToFile();
	void readFromFile();
	void add(const Event event);
};
