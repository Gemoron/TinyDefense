//LinkedList LinkedList.h
//Stefan Sanner
//Call to manage and use a Linked List consisting of LinkedElements

#include "LinkedList.h"
#include "LinkedElement.h"

	//Constructor
	LinkedList::LinkedList()
	{
		node = 0;
		len = 0;
	}

	//Destructor, destroys all LinkedElements held
	LinkedList::~LinkedList(){
		while(node!=0){
			this->popFirst();
		}
	}

	//returns current length
	int LinkedList::Length()
	{
		return len;
	}

	//recalculates current length, use if LinkedList has been changed without the use of LinkedList methods
	void LinkedList::calcLength()
	{
		int length=0;

		if(node!=0)
		{
			length=1;
			LinkedElement* indexElement=node;
			//Iterates through all elements and increases len untill next element is a NULL-pointer
			while(indexElement->getNext()!=0)
			{
				indexElement= indexElement->getNext();
				length++;
			}
		}
		len=length;
	}

	//Adds Elements to front, end or to the index. appends if list is shorther than index aims for
	void LinkedList::append(LinkedElement* newElement)
	{
		//If Element exists
		if(newElement != 0)
		{
			//If array is empty
			if(len==0){
				node= newElement;
			}
			else{
				LinkedElement* index=node;
				//Go to last element in list
				while(index->getNext()!=0)
				{
					index = index->getNext();
				}
				//Append
				index->setNext(newElement);
			}
			len++;
		}
	}
	void LinkedList::prepend(LinkedElement* newElement)
	{
		//If Element exists
		if(newElement != 0)
		{
			//If List is empty
			if(len==0)
			{
				node= newElement;
			}
			//Prepend
			else
			{
				//Put Element in front of node
				newElement->setNext(node);
				//Make Element new nodeelement
				node = newElement;
			}
			len++;
		}
	}
	bool LinkedList::insertAsIndex(LinkedElement* newElement, int index)
	{
		bool isInsertedInIndexPosition = false;
		//If valid element
		if(newElement !=0 && index >=0 )
		{
			//If list is empty
			if(len==0)
			{
				node = newElement;
				//Add to List
				if(index==0)
				{
					isInsertedInIndexPosition = true;
				}
			}
			//prepend if target is node
			else if(index==0)
			{
				prepend(newElement);
				isInsertedInIndexPosition = true;
			}
			else
			{
				index--;
				LinkedElement* indexNode = node;
				//Search for index
				while(index > 0 && indexNode->getNext()!=0)
				{
					indexNode = indexNode->getNext();
					index--;
				}
				//insert element to position
				if(index== 0)
				{
					newElement->setNext(indexNode->getNext());
					isInsertedInIndexPosition = true;
				}
				indexNode->setNext(newElement);
			}
			len++;
		}
		return isInsertedInIndexPosition;
	}
	
	//Returns a pointer of the wanted ListElement, Returns null if element doesn't exist
	LinkedElement* LinkedList::getFirst()
	{
		return len == 0 ? 0 : node;
	}
	LinkedElement* LinkedList::getLast()
	{
		//If List contains elements
		if(len!=0)
		{
			LinkedElement* indexElement=node;
			//Go to last element
			while(indexElement->getNext() !=0)
			{
				indexElement = indexElement->getNext();
			}
			return indexElement;
		}
		return 0;
	}
	LinkedElement* LinkedList::getIndex(int index)
	{
		//Searching valid index
		if(index<len && index >=0 && len !=0)
		{
			LinkedElement* indexElement=node;
			//Find Item
			while(index>0)
			{
				indexElement= indexElement->getNext();
				index--;
			}
			return indexElement;
		}
		return 0;
	}

	//Returns wanted ListeElement, removes Element from List, Returns null if element doesn't exist
	LinkedElement* LinkedList::popFirst()
	{
		if(len!=0)
		{
			//Remove first Element from List and set 2nd Element as new node 
			LinkedElement* returnElement = node;
			node= node->getNext();
			len--;
			//Element shouldn't be linked to other linkelements
			returnElement->setNext(0);
			return returnElement;
		}
		return 0;
	}
	LinkedElement* LinkedList::popLast()
	{
		LinkedElement* returnElement=0;
		//if there are 2 or more elements in the list
		if(len>1)
		{
			LinkedElement* indexElement=node;
			//find second but last element
			while(indexElement->getNext()->getNext()!=0)
			{
				indexElement = indexElement->getNext();    
			}
			//get last element
			returnElement = indexElement->getNext();
			//make second but last element to last element
			indexElement->setNext(0);
			len--;
		}
		//If Last element is the Only element
		else if(len==1)
		{
			returnElement = node;
			node = 0;
			len--;
		}
		return returnElement;
	}	
	LinkedElement* LinkedList::popIndex(int index)
	{
		LinkedElement* returnElement=0;
		//If Index is valid
		if(index<len && index >=0 && len !=0)
		{
			//Get the first item
			if(index == 0)
			{
				returnElement = popFirst();
			}
			else
			{
				index--;
				LinkedElement* indexNode = node;
				//get wanted index
				while(index > 0)
				{
					indexNode = indexNode->getNext();
					index--;
				}
				//remove wanted Element from List and return it
				returnElement = indexNode->getNext();
				indexNode->setNext(returnElement->getNext());
				returnElement->setNext(0);
			}
			len--;
		}
		return returnElement;
	}
	
	//Removes Element from list without returning it, calls destructor of that element.
	void LinkedList::removeFirst()
	{
		if(node!=0)
		{
			//save pointer to element
			LinkedElement* toDelete=node;
			//lets node point to next element in list or 0 if the only element
			node = node->getNext();
			len--;
			//Delete element forever
			delete toDelete;
		}
	}
	void LinkedList::removeLast()
	{
		//If last Element is the Only element
		if(len==1)
		{
			removeFirst();
		}

		else if(len>1)
		{
			LinkedElement* indexElement=node;
			//get to second but last element
			while(indexElement->getNext()->getNext()!=0)
			{
				indexElement = indexElement->getNext();    
			}
			//delete element, compare to removeFirst
			LinkedElement* toDelete =  indexElement->getNext();
			indexElement->setNext(0);
			len--;
			delete toDelete;
		}
	}
	void LinkedList::removeIndex(int index)
	{
		//Is the index a valis element
		if(index<len && index >=0 && len !=0)
		{
			//First and only element
			if(index == 0)
			{
				removeFirst();
			}
			else
			{
				index--;
				LinkedElement* indexNode = node;
				//Get wanted Element
				while(index > 0)
				{
					indexNode = indexNode->getNext();
					index--;
				}
				//Remove Element from List.
				LinkedElement* toDelete = indexNode->getNext();
				indexNode->setNext(toDelete->getNext());
				delete toDelete;
			}
			len--;
		}
	}
