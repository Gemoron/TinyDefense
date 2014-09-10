//A* main.cpp
//Stefan Sanner
//Entwicklung und Testen der LinkedElement Klasse
#include <iostream>
#include "MapElement.h"
#include "MapTable.h"
;
using namespace std;


void main(void)
{

	locale::global(locale("German_germany"));

	MapTable* openList = new MapTable();
	MapTable* closedList = new MapTable();

	openList->smartInsertMapElement(new MapElement("1", 0, 5));
	openList->smartInsertMapElement(new MapElement("2", 1, 5));
	openList->smartInsertMapElement(new MapElement("3", 1, 5));
	openList->smartInsertMapElement(new MapElement("4", 1, 5));
	openList->smartInsertMapElement(new MapElement("5", 1, 5));
	openList->smartInsertMapElement(new MapElement("6", 1, 5));
	openList->smartInsertMapElement(new MapElement("7", 1, 5));
	openList->smartInsertMapElement(new MapElement("8", 1, 5));
	openList->smartInsertMapElement(new MapElement("9", 1, 5));
	openList->smartInsertMapElement(new MapElement("10", 1, 5));

	
	cout<<"OpenList"<<endl;
	openList->print();

	while(openList->Length() >0 )
	{
		closedList->prepend(openList->popFirst());
	}

	cout<<"OpenList"<<endl;
	
	openList->print();
	
	cout<<"closedList"<<endl;
	closedList->print();

	system("pause");

	delete openList;
	delete closedList;
}