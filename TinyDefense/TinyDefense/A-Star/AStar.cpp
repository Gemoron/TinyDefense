//LinkedList AStar.cpp
//Stefan Sanner
//Implementation of the A-Star pathfinding algorithm

#include <string>
#include "MapElement.h"
#include "MapTable.h"
#include "AStar.h"
;
using namespace std;


	AStar::AStar()
	{
		
		openList = new MapTable();
		closedList = new MapTable();
	}
	AStar::~AStar()
	{
		openList->~MapTable();
		closedList->~MapTable();
	}

	MapTable* AStar::getPath(string start, string end)
	{

		openList->clearList();
		closedList->clearList();

		
		//get start elenent
		MapElement* currentElement = getElementByName(start);

		//put start element in open list
		openList->prepend(currentElement);

		//untill target element is found or map is empty.
		while(openList->Length() > 0 && currentElement->getName() != end)
		{
			//pop first element of open list
			currentElement = (MapElement*) openList->popFirst();
			//analyze element
			analyzeElement(currentElement);
			//move element into closed list
			closedList->prepend(currentElement);
		}

		//construct and return path
		return assemblePath();
	}

	//adds all neighbouring elements to the openList
	void AStar::analyzeElement(MapElement* element)
	{}
	//assembles the list of map elements
	MapTable* AStar::assemblePath()
	{}

	//-------------------------------

	int AStar::getThisGuess()
	{}
	
	void AStar::setPrevious()
	{}
	void AStar::getNeighbours()
	{}
	void AStar::addNeighbourToOpenList()
	{}
	
	//------- Virtual classes need to be implemented by A* user
	// Gets the element wanted by map element and returns a map element initialised by 
	MapElement* AStar::getElementByName(string name)
	{}

	//returns guess of the distance between current object and target
	int AStar::calcGuess()
	{}
