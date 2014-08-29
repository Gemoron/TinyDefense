//LinkedList main.cpp
//Stefan Sanner
//Entwicklung und Testen der LinkedElement Klasse
#include <iostream>
#include "LinkedElement.h"

using namespace std;

void main(void){
	LinkedElement* node = &LinkedElement();

	node = node->prepend(&LinkedElement());
	node = node->prepend(&LinkedElement());
	node = node->prepend(&LinkedElement());
	node = node->prepend(&LinkedElement());
	node = node->prepend(&LinkedElement());
	
	system("pause");
}