//LinkedList LinkedList.h
//Stefan Sanner
//Call to manage and use a Linked List consisting of LinkedElements

#pragma once
#include "LinkedElement.h"

class LinkedList
{
private:
	LinkedElement* node;
	int len;

public:
	//Constructor
	LinkedList();
	//Destructor, destroys all LinkedElements held
	~LinkedList();

	//returns current length
	int Length();

	//recalculates current length, use if LinkedList has been changed without the use of LinkedList methods
	void calcLength();

	//Adds Elements to front, end or to the index. appends if list is shorther than index aims for
	void append			(LinkedElement* newElement);
	void prepend		(LinkedElement* newElement);
	bool insertAsIndex	(LinkedElement* newElement, int index);
	
	//Returns a pointer of the wanted ListElement, Returns null if element doesn't exist
	LinkedElement* getFirst		();
	LinkedElement* getLast		();
	LinkedElement* getIndex		(int index);

	//Returns wanted ListeElement, removes Element from List, Returns null if element doesn't exist
	LinkedElement* popFirst		();
	LinkedElement* popLast		();
	LinkedElement* popIndex		(int index);

	//Removes Element from list without returning it, calls destructor of that element.
	void removeFirst	();
	void removeLast		();
	void removeIndex	(int index);
};