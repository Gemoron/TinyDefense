//A* main.cpp
//Stefan Sanner
//Entwicklung und Testen der LinkedElement Klasse

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

#include "testmap.h"

;
using namespace std;


void main(void)
{
	locale::global(locale("German_germany"));

	vector<string> path;

	testmap* map = new testmap();

	path = map->getPath("1|4","3|1");

	while(path.size()>0)
	{
		cout<< (string) path.back()<<endl;
		path.pop_back();
	}

	system("PAUSE");

	delete map;
};