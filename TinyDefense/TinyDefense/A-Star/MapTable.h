//LinkedList MapElement.h
//Stefan Sanner
//Element to carry all information nessecary for A-Star
#pragma once

#include "LinkedList.h"
#include "MapElement.h"
#include <string>
using namespace std;

class MapTable : public LinkedList
{

public:
	MapTable();
	~MapTable();

	//Returns index of searched element, -1 if not found
	int getIndexByName(string wantedString);
	//Inserts element according to total cost.
	void smartInsertMapElement(MapElement* newElement);
	//Deletes all MapElements
	void clearList();

	void print();

}