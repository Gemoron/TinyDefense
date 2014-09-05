//LinkedList MapElement.h
//Stefan Sanner
//Element to carry all information nessecary for A-Star
#pragma once

#include "LinkedELement.h"
#include <string>
using namespace std;

class MapElement : public LinkedElement
{
private:

	int currentCost;
	int thisCost;
	int guess;
	string name;
	MapElement* previous;

public:

	MapElement();
	MapElement(string newName, int newCurrentCost, int newThisCost, int newGuess);

	~MapElement();

	MapElement* getPrevious();
	void setPrevious(MapElement* element);
	

	string getName();

	int getTotalCost();
};