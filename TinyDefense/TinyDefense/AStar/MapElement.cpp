//LinkedList MapElement.h
//Stefan Sanner
//Element to carry all information nessecary for A-Star

#include "MapElement.h"
#include <string>
using namespace std;

	MapElement::MapElement()
	{
		this->currentCost = 0;
		this->guess = 0;
		this->thisCost = 0;
		this->name= "";
		this->previous="";
	}
	MapElement::MapElement(string newName, int newThisCost, int newGuess)
	{
		this->name= newName;
		this->currentCost = 0;
		this->thisCost = newThisCost;
		this->guess = newGuess;
		this->previous= "";
	}

	MapElement::~MapElement()
	{}
	
	string MapElement::getPrevious()
	{
		return previous;
	}
	void MapElement::setPrevious(MapElement element)
	{
			this->previous = element.getName();
			this->currentCost = element.currentCost + element.thisCost;
	}

	string MapElement::getName()
	{
		return name;
	}

	int MapElement::getTotalCost()
	{
		return currentCost + thisCost + guess ;
	}