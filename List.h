#include <iostream>
#ifndef LIST_H
#define LIST_H
#include "Node.h"
using namespace std;

class List
{
	public:
		List(void){head=NULL;}
		~List(void);
		
		bool IsEmpty(){return head==NULL;}
		Node* InsertNode(string x);				//Add new location	
		int FindNode(string x);					//Search for location
		int DeleteNode(string x);				//Delete location
		void DisplayList(void);					//Display all the location available
		void OutputToFile(void);				//Print all the latest location update version into the file
		
	private:
		Node* head;		
};

#endif
