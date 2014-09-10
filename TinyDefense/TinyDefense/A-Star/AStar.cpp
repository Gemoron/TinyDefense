//LinkedList AStar.cpp
//Stefan Sanner
//Implementation of the A-Star pathfinding algorithm

#include <string>
#include <vector>
#include "MapElement.h"
#include "MapTable.h"
#include "AStar.h"
;
using namespace std;


	AStar::AStar()
	{
		
		openList = new MapTable();
		closedList = new MapTable();
		MapElement* currentElement =0;
	}
	AStar::~AStar()
	{
		delete openList;
		delete closedList;
	}

	//returns vector of Gamemap names to get from param start to param end. first pop_end returns start if successful
	vector<string> AStar::getPath(string start, string end)
	{
		openList->clearList();
		closedList->clearList();
		
		//get start elenent
		currentElement = getElementByName(start);

		//put start element in open list
		openList->prepend(currentElement);

		//untill target element is found or map is empty.
		while(openList->Length() > 0 && currentElement->getName() != end)
		{
			analyzeElement(currentElement->getName());
			//move element into closed list
			closedList->prepend(currentElement);
			//pop first element of open list for next iteration
			currentElement = (MapElement*) openList->popFirst();
		}

		//construct and return path

		vector<string> returner ;

		openList->clearList();
		closedList->clearList();

		return assemblePath();
	}

	

	//assembles the list of map elements
	vector<string> AStar::assemblePath()
	{
		vector<string> returner;
		MapElement* element= (MapElement*) closedList->popFirst();

		while(element!=0)
		{
			returner.push_back(element->getName());
			element = element->getPrevious();
		}
		return returner;
	}

	//Use to add neighbour elements to A* algorithm, !use in analyzeElement!
	void AStar::addNeighbourToOpenList(string name,int thisCost, int guess)
	{
		//Test if element exists already
		if(closedList->getIndexByName(name)<0 && openList->getIndexByName(name)<0)
		{
			//create new Element
			MapElement* element = new MapElement(name, thisCost,guess);
			//get previous (and set current cost)
			element->setPrevious(currentElement);

			openList->smartInsertMapElement(element);
		}
	}
	
	//------- Virtual classes need to be implemented by A* user
	//Please add
	void AStar::analyzeElement(string element)
	{}

	// Gets the element wanted by map element and returns a map element initialised by 
	MapElement* AStar::getElementByName(string name)
	{}

	//returns guess of the distance between current object and target
	int AStar::calcGuess( )
	{}
