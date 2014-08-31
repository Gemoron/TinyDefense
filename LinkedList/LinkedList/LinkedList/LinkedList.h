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
	LinkedList();

	int Length();

	void calcLength();

	void append			(LinkedElement* newElement);
	void prepend		(LinkedElement* newElement);
	bool insertAsIndex	(LinkedElement* newElement, int index);
	
	LinkedElement* getFirst		();
	LinkedElement* getLast		();
	LinkedElement* getIndex		(int index);

	LinkedElement* popFirst		();
	LinkedElement* popLast		();
	LinkedElement* popIndex		(int index);
	
	void removeFirst	();
	void removeLast		();
	void removeIndex	(int index);
};