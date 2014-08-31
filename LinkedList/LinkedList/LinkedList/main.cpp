//LinkedList main.cpp
//Stefan Sanner
//Entwicklung und Testen der LinkedElement Klasse
#include <iostream>
#include "LinkedElement.h"
#include "LinkedList.h"
;
using namespace std;

class val : public LinkedElement
{
	public: 
	int value;

	val()
	{
		value=-1;
	}
	val(int v)
	{
		value=v;
	}
};

void main(void)
{

	locale::global(locale("German_germany"));

	LinkedList Liste = LinkedList();
	val* value= 0;

	Liste.insertAsIndex(new val(1),4);
	Liste.insertAsIndex(new val(2),4);
	Liste.insertAsIndex(new val(3),4);
	Liste.insertAsIndex(new val(4),4);
	Liste.insertAsIndex(new val(5),4);

	value =(val*) Liste.getFirst();
	cout<<value->value<<endl;
	value =(val*) Liste.getIndex(1);
	cout<<value->value<<endl;
	value =(val*) Liste.getIndex(2);
	cout<<value->value<<endl;
	value =(val*) Liste.getIndex(3);
	cout<<value->value<<endl;
	value =(val*) Liste.getLast();
	cout<<value->value<<endl;
	system("pause");
}
