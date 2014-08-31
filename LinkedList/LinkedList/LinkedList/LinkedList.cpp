//LinkedList LinkedList.h
//Stefan Sanner
//Call to manage and use a Linked List consisting of LinkedElements

#include "LinkedList.h"
#include "LinkedElement.h"
	LinkedList::LinkedList()
	{
		node = 0;
		len = 0;
	}

	int LinkedList::Length()
	{
		return len;
	}

	void LinkedList::calcLength()
	{
		int length=0;

		if(node!=0)
		{
			length=1;
			LinkedElement* indexElement=node;
			while(indexElement->getNext()!=0)
			{
				indexElement= indexElement->getNext();
				length++;
			}
		}
		len=length;
	}

	void LinkedList::append(LinkedElement* newElement)
	{
		if(len==0){
			node= newElement;
		}
		else{
			LinkedElement* index=node;
			while(index->getNext()!=0)
			{
				index = index->getNext();
			}
			index->setNext(newElement);
		}
		len++;
	}
	void LinkedList::prepend(LinkedElement* newElement)
	{
		if(len==0)
		{
			node= newElement;
		}
		else
		{
			newElement->setNext(node);
			node = newElement;
		}
		len++;
	}
	bool LinkedList::insertAsIndex(LinkedElement* newElement, int index)
	{
		bool isInsertedInIndexPosition = false;
		if(len==0)
		{
			node = newElement;
			if(index==0)
			{
				isInsertedInIndexPosition = true;
			}
		}
		else if(index==0)
		{
			prepend(newElement);
			isInsertedInIndexPosition = true;
		}
		else
		{
			index--;
			LinkedElement* indexNode = node;
			while(index > 0 && indexNode->getNext()!=0)
			{
				indexNode = indexNode->getNext();
				index--;
			}
			if(index== 0)
			{
				newElement->setNext(indexNode->getNext());
				isInsertedInIndexPosition = true;
			}
			indexNode->setNext(newElement);
		}
		len++;
		return isInsertedInIndexPosition;
	}
	
	LinkedElement* LinkedList::getFirst()
	{
		return len == 0 ? 0 : node;
	}
	LinkedElement* LinkedList::getLast()
	{
		if(len>0)
		{
			LinkedElement* indexElement=node;
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
		if(index<len)
		{
			LinkedElement* indexElement=node;
			while(index>0)
			{
				indexElement= indexElement->getNext();
				index--;
			}
			return indexElement;
		}
		return 0;
	}

	LinkedElement* LinkedList::popFirst()
	{
		if(len>0)
		{
			LinkedElement* returnElement = node;
			node= node->getNext();
			len--;
			return returnElement;
		}
		return 0;
	}
	LinkedElement* LinkedList::popLast()
	{
		LinkedElement* returnElement=0;
		if(len>1)
		{
			LinkedElement* indexElement=node;
			while(indexElement->getNext()->getNext()!=0)
			{
				indexElement = indexElement->getNext();    
			}
			returnElement = indexElement->getNext();
			indexElement->setNext(0);
			len--;
		}
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
		if(index<len)
		{
			if(index == 0)
			{
				returnElement = popFirst();
			}
			else
			{
				index--;
				LinkedElement* indexNode = node;
				while(index > 0)
				{
					indexNode = indexNode->getNext();
					index--;
				}
				returnElement = indexNode->getNext();
				indexNode->setNext(returnElement->getNext());
			}
			len--;
		}
		return returnElement;
	}
	
	void LinkedList::removeFirst()
	{
		if(node!=0)
		{
			LinkedElement* toDelete=node;
			node = node->getNext();
			len--;
			delete toDelete;
		}
	}
	void LinkedList::removeLast()
	{
		if(len==1)
		{
			removeFirst();
		}
		else if(len>1)
		{
			LinkedElement* indexElement=node;
			while(indexElement->getNext()->getNext()!=0)
			{
				indexElement = indexElement->getNext();    
			}
			LinkedElement* toDelete =  indexElement->getNext();
			indexElement->setNext(0);
			len--;
			delete toDelete;
		}
	}
	void LinkedList::removeIndex(int index)
	{
		if(index<len)
		{
			if(index == 1)
			{
				removeFirst();
			}
			else
			{
				index--;
				LinkedElement* indexNode = node;
				while(index > 0)
				{
					indexNode = indexNode->getNext();
					index--;
				}
				LinkedElement* toDelete = indexNode->getNext();
				indexNode->setNext(toDelete->getNext());
				delete toDelete;
			}
			len--;
		}
	}
