//LinkedList LinkedElement.cpp
//Stefan Sanner
//Implements a one way connected linked list, inherit from this class to get elements which can be stored in LinkedList

#include "LinkedElement.h"

	//Constructor
	LinkedElement::LinkedElement()
	{
		next=0;
	}

	//Destructor
	LinkedElement::~LinkedElement(){
	
	}

	//Getter
	LinkedElement* LinkedElement::getNext()
	{
		return this->next;
	}
	//Setter
	void LinkedElement::setNext(LinkedElement* newElement)
	{
		this->next = newElement;
	}