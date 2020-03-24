#include "qmessagebox.h"
#include "Repository.h"
#include <fstream>
#include <iostream>
#include <qalgorithms.h>
using namespace std;
void Repository::readWriters()
{
	ifstream in;
	in.open("writers.txt");
	string name, expr;

	while (in >> name >> expr) {
		Writer w { name, expr };
		this->writers.push_back(w);
	}
	in.close();
}

void Repository::readIdeas()
{
	ifstream in;
	in.open("ideas.txt");
	string descr,status,creator;

	int act;

	while (in >> descr >> status >> creator >> act) {
		Idea *i=new Idea { descr, status, creator, act };
		this->ideas.push_back(*i);
	}
	in.close();
	for (auto i : this->getIdea())
		cout << i.toString() << endl;
}

void Repository::sortIdeas()
{
	sort(this->ideas.begin(), this->ideas.end(), [](Idea a, Idea b) {return a.getAct() <= b.getAct(); });
	//sort(this->ideas.begin(), this->ideas.end(), [](Idea a, Idea b) {return (a.getAct() <= b.getAct()) && (a.getDescr()<=b.getDescr()); });
	//sort(this->ideas.begin(), this->ideas.end(), [](Idea a, Idea b) {return a.getDescr() <= b.getDescr(); });

}

void Repository::savePlot()
{
	vector<Idea> res;

	for (auto i : this->getIdea())
		if (i.getStatus() == "accepted")
			res.push_back(i);

	ofstream out;
	out.open("plot.txt");
	for (auto i : res)
		out << i.toString() << endl;
	
	out.close();
}

void Repository::removeIdea(int i)
{
	if (this->ideas.at(i).getStatus() == "proposed")
		this->ideas.erase(this->ideas.begin() + i);
	else
		QMessageBox::critical(0, "Error", "idea is accepted.");

	this->notify();
}

void Repository::acceptIdea(int i)
{
	this->ideas.at(i).setStatus("accepted");
	this->notify();
}
