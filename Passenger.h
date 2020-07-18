#include <iostream>
#ifndef PASSENGER_H
#define PASSENGER_H
using namespace std;

class Passenger
{
	
	private:
		string name;
		string password;
	
	public:
		Passenger();
		void sign_up();				//function for sign up for passenger
		void log_in();				//function for log in for passenger
	
};

#endif
