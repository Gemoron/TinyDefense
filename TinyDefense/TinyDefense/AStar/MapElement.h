//LinkedList MapElement.h
//Stefan Sanner
//Element to carry all information nessecary for A-Star
#pragma once

#include <string>
using namespace std;

class MapElement 
{
private:

	int currentCost;
	int thisCost;
	int guess;
	string name;
	string previous;

public:

	MapElement();
	MapElement(string newName, int newThisCost, int newGuess);
	~MapElement();

	string getPrevious();
	void setPrevious(MapElement element);
	

	string getName();

	int getTotalCost();
};