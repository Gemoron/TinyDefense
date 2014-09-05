//LinkedList MapElement.h
//Stefan Sanner
//Element to carry all information nessecary for A-Star

#include <iostream>
#include "LinkedList.h"
#include "MapElement.h"
#include <string>
#include "MapTable.h"
;
using namespace std;


	MapTable::MapTable()
	{
	}
	MapTable::~MapTable()
	{
	}

	//Returns index of searched element, -1 if not found
	int MapTable::getIndexByName(string wantedString)
	{
		int index=0;
		int returnIndex=-1;

		MapElement* element= (MapElement*) node;
		//Iterate through the list
		while(returnIndex !=0 && element!=0)
		{
			if(element->getName()== wantedString)
			{
				returnIndex = index;
			}
			//Next Element
			index++;
			element->setNext(element->getNext());
		}
		return returnIndex;
	}
	//Inserts element according to total cost.
	void MapTable::smartInsertMapElement(MapElement* newElement)
	{
		MapElement* indexElement = (MapElement*) node;
		int index = 0;

		int newCost = newElement->getTotalCost();

		//untill right position is found or append
		while(indexElement != 0 && newCost >= indexElement->getTotalCost())
		{
			indexElement= (MapElement*) indexElement->getNext();
			index++;
		}
		//add to wanted position
		this->insertAsIndex(newElement, index);
	}
	//Deletes all MapElements
	void MapTable::clearList()
	{
		removeall();
	}

	void MapTable::print()
	{
		MapElement* element = (MapElement*) node;

		while(element != 0)
		{
			cout<< element->getName()<<" "<<element->getTotalCost() <<endl;
			element =(MapElement*) element->getNext();
		}
	}