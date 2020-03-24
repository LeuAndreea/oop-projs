#include "TextFile.h"


void CSVFile::writeToFile(vector<Event> events)
{
	ofstream file("out.csv", ofstream::out);
	for (auto e : events)
		file << e;
	file.close();
}

void HTMLFile::writeToFile(vector<Event> events)
{
	ofstream file("out.html", ofstream::out);
	file << "<!DOCTYPE html><html><head><title>Event list</title></head><bobdy><table border=1>";
	for (auto e : events) {
		file << "<tr>";
		file << "<td>" << e.getTitle() << "</td>";
		file << "<td>" << e.getDescription() << "</td>";
		file << "<td>" << e.getLink() << "</td>";
		file << "<td>" << e.getNbOfPeople() << "</td>";
		file << "<td>" << e.getDateAndTime().toStringDateAndTime() << "</td>";
		file << "</tr>";
	}
	file << "</table></body></html>";
}
