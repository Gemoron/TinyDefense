//LinkedList AStar.h
//Stefan Sanner
//Implementation of the A-Star pathfinding algorithm

#include <string>
#include <vector>
#include "MapElement.h"
#include "MapTable.h"
;
using namespace std;

class AStar
{
	MapTable* openList;
	MapTable* closedList;
	MapElement* currentElement;

	AStar();

	~AStar();

	vector<string> getPath(string start, string end);
	vector<string> assemblePath();


	void addNeighbourToOpenList(string name, int thisCost, int guess);

	//------- Virtual classes need to be implemented by A* user
	
	void analyzeElement(string element);
	// Gets the element wanted by map element and returns a map element initialised by 
	virtual MapElement* getElementByName(string name);

	
	//returns guess of the distance between current object and target
	virtual int calcGuess();
}