#pragma once

class LinkedElement{
private:
	LinkedElement* next;
public:
	LinkedElement();

	LinkedElement* getNext();
	void setNext(LinkedElement* newElement);

	void append(LinkedElement* newElement);
	LinkedElement* prepend(LinkedElement* newElement);
};