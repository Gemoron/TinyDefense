//LinkedList AStar.h
//Stefan Sanner
//Implementation of the A-Star pathfinding algorithm

#include <string>
#include "MapElement.h"
#include "MapTable.h"
;
using namespace std;

class AStar
{
	MapTable* openList;
	MapTable* closedList;

	AStar();

	~AStar();

	MapTable* getPath(string start, string end);
	void analyzeElement(MapElement* element);
	MapTable* assemblePath();

	//---------------------

	
	int getThisGuess();
	void setPrevious();
	void getNeighbours();
	void addNeighbourToOpenList();

	//------- Virtual classes need to be implemented by A* user
	// Gets the element wanted by map element and returns a map element initialised by 
	virtual MapElement* getElementByName(string name);

	
	//returns guess of the distance between current object and target
	virtual int calcGuess();
}