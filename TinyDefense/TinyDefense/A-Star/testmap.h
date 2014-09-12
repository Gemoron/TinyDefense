//LinkedList AStar.cpp
//Stefan Sanner
//Implementation of the A-Star pathfinding algorithm
/*
	  1 2 3 4
	1 X   X
	2 | X   X
	3 X - X X
	4 X   X X
*/
#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include "astar.h"

using namespace std;
class testmap :public AStar
{
public:
	testmap(void);
	~testmap(void);

	//Please implement: pass all neighbours of the given element to the algorithm using addNeighbourToOpenList(string name, int thisCost, int guess)
	void analyzeElement(string element, string end);

	//Please implement: pass the information of the parameter element to the algorithm using addNeighbourToOpenList(string name, 0 , int guess)
	void getElementByName(string name, string end);
	int getGuess(string start, string end);
};

