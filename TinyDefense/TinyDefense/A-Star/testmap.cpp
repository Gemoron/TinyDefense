//LinkedList AStar.cpp
//Stefan Sanner
//Implementation of the A-Star pathfinding algorithm
/*
	  1 2 3 4 <- x
	1 X   X
	2 | X   X
	3 X - X X
	4 X   X X
	^
	Y
*/

#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include "testmap.h"
#include "astar.h"

using namespace std;

	testmap::testmap(void)
	{
	}


	testmap::~testmap(void)
	{
	}

	//Please implement: pass all neighbours of the given element to the algorithm using addNeighbourToOpenList(string name, int thisCost, int guess)
	void testmap::analyzeElement(string element, string end)
	{
		if(element =="1|1")
		{
			addNeighbourToOpenList("1|3",4,getGuess("1|3",end));
			addNeighbourToOpenList("1|2",2,getGuess("1|2",end));

		}
		else if(element =="1|3")
		{
			addNeighbourToOpenList("1|1",4,getGuess("1|1",end));
			addNeighbourToOpenList("1|4",3,getGuess("1|4",end));
			addNeighbourToOpenList("2|2",6,getGuess("2|2",end));
			addNeighbourToOpenList("3|3",4,getGuess("3|3",end));
		}
		else if(element =="1|4")
		{
			addNeighbourToOpenList("1|3",3,getGuess("1|3",end));
		}
		else if(element =="2|2")
		{
			addNeighbourToOpenList("1|1",3,getGuess("1|1",end));
			addNeighbourToOpenList("1|3",6,getGuess("1|1",end));
			addNeighbourToOpenList("3|1",4,getGuess("3|1",end));
			addNeighbourToOpenList("3|3",1,getGuess("3|3",end));
		}
		else if(element =="3|1")
		{
			addNeighbourToOpenList("2|2",4,getGuess("3|1",end));
			addNeighbourToOpenList("4|2",1,getGuess("4|2",end));
		}
		else if(element =="3|3")
		{
			addNeighbourToOpenList("1|3",4,getGuess("1|3",end));
			addNeighbourToOpenList("2|2",1,getGuess("2|2",end));
			addNeighbourToOpenList("3|4",1,getGuess("3|4",end));
			addNeighbourToOpenList("4|3",2,getGuess("4|3",end));
		}
		else if(element =="3|4")
		{
			addNeighbourToOpenList("3|3",1,getGuess("3|3",end));
			addNeighbourToOpenList("4|4",1,getGuess("3|4",end));
		}
		else if(element =="4|2")
		{
			addNeighbourToOpenList("3|1",1,getGuess("3|1",end));
			addNeighbourToOpenList("4|3",1,getGuess("4|3",end));
		}
		else if(element =="4|3")
		{
			addNeighbourToOpenList("3|3",2,getGuess("3|3",end));
			addNeighbourToOpenList("4|4",1,getGuess("4|4",end));
			addNeighbourToOpenList("4|2",1,getGuess("4|2",end));
		}
		else if(element =="4|4")
		{
			addNeighbourToOpenList("3|4",1,getGuess("3|4",end));
			addNeighbourToOpenList("4|3",1,getGuess("4|3",end));
		}
	}

	//Please implement: pass the information of the parameter element to the algorithm using addNeighbourToOpenList(string name,int thisCost, int guess)
	void testmap::getElementByName(string name, string end)
	{
		if(name =="1|1")
			addNeighbourToOpenList("1|1",0,getGuess("1|1",end));
		else if(name =="1|3")
			addNeighbourToOpenList("1|3",0,getGuess("1|3",end));
		else if(name =="1|4")
			addNeighbourToOpenList("1|4",0,getGuess("1|4",end));
		else if(name =="2|2")
			addNeighbourToOpenList("2|2",0,getGuess("2|2",end));
		else if(name =="3|1")
			addNeighbourToOpenList("3|1",0,getGuess("2|2",end));
		else if(name =="3|3")
			addNeighbourToOpenList("3|3",0,getGuess("2|2",end));
		else if(name =="3|4")
			addNeighbourToOpenList("3|4",0,getGuess("3|4",end));
		else if(name =="4|2")
			addNeighbourToOpenList("4|2",0,getGuess("4|2",end));
		else if(name =="4|3")
			addNeighbourToOpenList("4|3",0,getGuess("4|3",end));
		else if(name =="4|4")
			addNeighbourToOpenList("4|4",0,getGuess("4|4",end));
	}

	
	int testmap::getGuess(string start, string end)
	{
		// sqrt(delta x² + delta y²) | a²+b²=c²
		return sqrt(pow((double)((start.at(0) - 48)-(end.at(0) - 48)),2)+pow((double)((start.at(2) - 48)-(end.at(2) - 48)),2));
	}

