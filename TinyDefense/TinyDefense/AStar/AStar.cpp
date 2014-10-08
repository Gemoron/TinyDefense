//LinkedList AStar.cpp
//Stefan Sanner
//Implementation of the A-Star pathfinding algorithm

#include <string>
#include <vector>
#include "MapElement.h"
#include "AStar.h"
;
using namespace std;


	AStar::AStar()
	{
		currentElement = MapElement("",0,0);
	}
	AStar::~AStar()
	{
	}

	//returns vector of Gamemap names to get from param start to param end. first pop_end returns start if successful
	vector<string> AStar::getPath(string start, string end)
	{
		vector<string> returner;
		
		//get start elenent
		getElementByName(start, end);

		//put start element in open list

		//untill target element is found or map is empty.
		do
		{
			//pop first element of open list for next iteration
			currentElement = openList.front();
			openList.erase(openList.begin());
			analyzeElement(currentElement.getName(), end);
			//move element into closed list
			closedList.push_back(currentElement);
		}while((openList.size() > 0) && (currentElement.getName() != end));

		//construct path
		if(currentElement.getName() == end)
		{
			returner = assemblePath();
		}
		//clear lists to prepare for next run and save memory
		openList.clear();
		closedList.clear();

		return returner;
	}
	
	//assembles the list of map elements
	vector<string> AStar::assemblePath()
	{
		vector<string> returner;
		string next = closedList.back().getName();
		

		for(vector<MapElement>::reverse_iterator i = closedList.rbegin(); i != closedList.rend(); i++)
		{
			if((*i).getName() == next)
			{
				returner.push_back(next);
				next = (*i).getPrevious();
			}
		}
		return returner;
	}
	
	//checks if name already exists in vector
	bool AStar::isNameInVector(vector<MapElement> Vector, string name)
	{
		bool returner = false;

		for(vector<MapElement>::iterator i = Vector.begin(); i != Vector.end(); i++)
		{
			if((*i).getName()== name)
			{
				returner = true;
			}
		}

		return returner;
	}

	//Use to add neighbour elements to A* algorithm, !use in analyzeElement!
	void AStar::addNeighbourToOpenList(string name,int thisCost, int guess)
	{
		//get first element fromclosed list, check if element exists in closed List
		if(isNameInVector(closedList, name) == false)
		{
			int openListIndex = getIndexByName(openList, name);
			//create new Element
			MapElement element = MapElement(name, thisCost,guess);
			element.setPrevious(currentElement);
			//Element doesn't exist in list, add according to cost
			if(openListIndex<0)
			{
				smartInsertMapElement( element);
			}
			else{
				MapElement openListElement = openList.at(openListIndex);
				//if exists, check if if faster/cheaper than existing path
				if(element.getTotalCost() < openListElement.getTotalCost() )
				{
					//if faster, then replace
					openList.erase(openList.begin()+openListIndex);
					smartInsertMapElement( element);
				}
					//if not, forget element and continue
			}
		}	
	}
	
	int AStar::getIndexByName(vector<MapElement> Vector, string wantedString)
	{
		int index=0;
		int returnIndex=-1;

		for(vector<MapElement>::iterator i = Vector.begin(); i != Vector.end(); i++)
		{
			if((*i).getName()== wantedString)
			{
				returnIndex = index;
			}
			index++;
		}
		return returnIndex;
	}

	void AStar::smartInsertMapElement( MapElement newElement)
	{
		int index = 0;
		int newCost = newElement.getTotalCost();

		//untill right position is found or append
		for(vector<MapElement>::iterator i = openList.begin(); i != openList.end() && newCost >= (*i).getTotalCost();	i++)
		{
			index++;
		}
		//add to wanted position
		openList.insert(openList.begin() + index,newElement);
	}

	//------- Virtual classes need to be implemented by A* user
	//Please implement: pass all neighbours of the given element to the algorithm using addNeighbourToOpenList(string name, int thisCost, int guess)
	//void AStar::analyzeElement(string element, string end){}

	//Please implement: pass the information of the parameter element to the algorithm using addNeighbourToOpenList(string name,int thisCost, int guess)
	//void AStar::getElementByName(string name, string end){}

