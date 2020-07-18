#include <iostream>
#include "Stack.h"
#include "Stack.cpp"
#ifndef FLIGHT_H
#define FLIGHT_H
using namespace std;
const int numberOfRow = 15;
const int numberOfCol = 8;

class Flight
{
	protected:
		char matrix[numberOfRow][numberOfCol];
		int num_passenger;			
		int d1,m1,y1;
		Stack sit;
		
	public:
		Flight();
		void revflight();								//function for listing passenger list for manager
		void Date_Time();								//function to input and check time
		void seat();									//function to choose seat
		void print();									//function to print seat
		void No_Ticket_Buy();							//function to input number of ticket to buy
		void TicketDetail(int,string,string,string);	//function to input passenger detail
		void payment_method(int);						//function for payment of ticket
		int get_numticket();							//return num_passenger
		char getMatrix();								//return matrix[][] for seat
		string getDate();								//return date in string
		
		
};

#endif
