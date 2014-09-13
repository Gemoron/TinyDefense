//LinkedList AStar.h
//Stefan Sanner
//Implementation of the A-Star pathfinding algorithm
#pragma once
#include <string>
#include <vector>
#include "MapElement.h"
#include "MapTable.h"
;
using namespace std;

class AStar
{
public:
	AStar();
	~AStar();
private:


	MapTable* openList;
	MapTable* closedList;
	MapElement* currentElement;
//assembles the list of map elements
	vector<string> assemblePath();
	


	//returns vector of Gamemap names to get from param start to param end. first pop_end returns start if successful
public: vector<string> getPath(string start, string end);

protected:
	//Use to add neighbour elements to A* algorithm, !use in analyzeElement!
	void addNeighbourToOpenList(string name, int thisCost, int guess);

	//------- Virtual classes need to be implemented by A* user
	//Please implement: pass all neighbours of the given element to the algorithm using addNeighbourToOpenList(string name, int thisCost, int guess)
	virtual void analyzeElement(string element, string end) = 0;

	//Please 
	virtual void getElementByName(string name, string end) = 0;

};