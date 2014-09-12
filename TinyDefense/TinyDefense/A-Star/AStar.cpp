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
		vector<string> returner;
		openList->clearList();
		closedList->clearList();
		
		//get start elenent
		getElementByName(start, end);
		
		currentElement = (MapElement*) openList->popFirst();

		//put start element in open list
		openList->prepend(currentElement);

		//untill target element is found or map is empty.
		while(openList->Length() > 0 && currentElement->getName() != end)
		{
			analyzeElement(currentElement->getName(), end);
			//move element into closed list
			closedList->prepend(currentElement);
			//pop first element of open list for next iteration
			currentElement = (MapElement*) openList->popFirst();
		}
		//Make sure last element popped has been added to closedList
		closedList->prepend(currentElement);

		//construct path
		if(currentElement->getName() == end)
		{
			returner = assemblePath();
		}
		//clear lists to prepare for next run and save memory
		openList->clearList();
		closedList->clearList();

		return returner;
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
		//get first element fromclosed list
		if(closedList->getIndexByName(name)<0)
		{
			int openListIndex = openList->getIndexByName(name);
			//create new Element
			MapElement* element = new MapElement(name, thisCost,guess);
			element->setPrevious(currentElement);

			if(openListIndex<0)
			{
				openList->smartInsertMapElement(element);
			}
			else{
				MapElement* openListElement =0;
				openListElement = (MapElement*) openList->getIndex(openListIndex);
				//if exists, check if if faster/cheaper than existing path
				if(element->getTotalCost() < openListElement->getTotalCost() )
				{
					//if faster, then replace
					openList->removeIndex(openListIndex);
					openList->insertAsIndex(element, openListIndex);
				}
				else
				{
					//if not, forget element and continue
					delete element;
				}
			}
		}	
	}
	
	//------- Virtual classes need to be implemented by A* user
	//Please implement: pass all neighbours of the given element to the algorithm using addNeighbourToOpenList(string name, int thisCost, int guess)
	void AStar::analyzeElement(string element, string end)
	{
	
	}

	//Please implement: pass the information of the parameter element to the algorithm using addNeighbourToOpenList(string name,int thisCost, int guess)
	void AStar::getElementByName(string name, string end)
	{
	
	}

