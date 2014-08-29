#include "LinkedElement.h"

	LinkedElement::LinkedElement(){
		next=0;
	}
	LinkedElement* LinkedElement::getNext(){
		return this->next;
	}
	void LinkedElement::setNext(LinkedElement* newElement){
		this->next = newElement;
	}
	void LinkedElement::append(LinkedElement* newElement){
		LinkedElement* index = this;
		
		while(index->getNext() != 0){
			index= index->getNext();
		}
		index->setNext(newElement);
	}

	LinkedElement* LinkedElement::prepend(LinkedElement* newElement){
		newElement->setNext(this);
		return newElement;
	}