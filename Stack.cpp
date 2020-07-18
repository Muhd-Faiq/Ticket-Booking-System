#include <iostream>
#include "Stack.h"
using namespace std;

void Stack::createStack()
{
	top=-1;
}

bool Stack::isFull()
{
	return (top==size-1);
}

bool Stack::isEmpty()
{
	return (top==-1);
}

void Stack::push(string newitem)
{
	top=top+1;
	data[top]=newitem;
		
}

void Stack::pop()
{
	string item;
	if (isEmpty())
	{
		system("cls");
		cout<<"Sorry, there is no item to be deleted.";
	}
	else
	{
		cout<<"Popped value: "<<data[top];
		top=top-1;
	}
}

string Stack::stackTop()
{
	if (isEmpty())
	{
		system("cls");
		cout<<"Sorry, the flight does not exist.";
	}
	else
	{
		return data[top];
	}
}

string Stack::stackBottom(int num)
{
	if (isEmpty())
	{
		system("cls");
		cout<<"Empty Stack.";
		system("pause");
	}
	else
	{
		return data[num];
	}
}


