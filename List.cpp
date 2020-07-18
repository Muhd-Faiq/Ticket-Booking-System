#include <iostream>
#include <fstream>
#include "Node.h"
#include "List.h"
using namespace std;

Node* List::InsertNode(string x)		//insert a new location
{
	int currIndex=0;
	Node* currNode=head;
	Node* prevNode=NULL;
	
	Node* newNode=new Node;
	newNode->data=x;
	if(currIndex==0)
	{
		newNode->next=head;
		head=newNode;
	}
	else
	{
		newNode->next=prevNode->next;
		prevNode->next=newNode;
	}
	return newNode;
}												//


int List::FindNode(string x)					//find location
{
	Node* currNode=head;
	int currIndex=1;
	while(currNode && currNode->data!=x)
	{
		currNode=currNode->next;
		currIndex++;
	}
	if(currNode)
	{
		if(currNode->data!="")
		{
			return currIndex;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}											//


int List::DeleteNode(string x)				//delete location
{
	Node* prevNode=NULL;
	Node* currNode=head;
	int currIndex=1;
	while(currNode && currNode->data!=x)
	{
		prevNode=currNode;
		currNode=currNode->next;
		currIndex++;		
	}
	if(currNode)
	{
		if(prevNode)
		{
			prevNode->next=currNode->next;
			delete currNode;
		}
		else
		{
			head=currNode->next;
			delete currNode;
		}
		return currIndex;
	}
	return 0;
}														//

void List::DisplayList()					//display all the location in the list
{
	int num=0;
	Node* currNode=head;
	while(currNode!=NULL)
	{
		cout<<currNode->data<<endl;
		currNode=currNode->next;
		num++;
	}
}

void List::OutputToFile()					//delete the location that want to be deleted in the file
{
	int num=0;
	fstream outfile;
	outfile.open("negeri.txt",ios::out);
	Node* currNode=head;
	while(currNode!=NULL)
	{
		outfile<<currNode->data<<endl;
		currNode=currNode->next;
		num++;
	}
	outfile.close();
}

List::~List()
{
	Node* currNode=head, *nextNode=NULL;
	while(currNode!=NULL)
	{
		nextNode=currNode->next;
		delete currNode;
		currNode=nextNode;
	}
	head=NULL;
}										//

