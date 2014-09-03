//LinkedList LinkedElement.h
//Stefan Sanner
//Implements a one way connected linked list, inherit from this class to get elements which can be stored in LinkedList
#pragma once

class LinkedElement
{
private:
	LinkedElement* next;
public:

	//Constructor Destructor
	LinkedElement	();
	~LinkedElement	();

	//Getter and Setter
	LinkedElement* getNext();
	void setNext	(LinkedElement* newElement);
};
