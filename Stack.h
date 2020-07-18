#include <iostream>
#ifndef STACK_H
#define STACK_H
using namespace std;
const int size=90;

class Stack
{
	private:
		int top;
		string data[size];
		
	public:
		void createStack();
		void push(string);
		void pop();
		string stackTop();
		string stackBottom(int);
		bool isFull();
		bool isEmpty();
	
};

#endif
