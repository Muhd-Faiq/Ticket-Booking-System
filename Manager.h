#include <iostream>
#ifndef MANAGER_H
#define MANAGER_H
using namespace std;

class Manager
{
	
	private:
		string name;
		string password;
	
	public:
		Manager();
		void sign_up();			//function for sign up for manager
		void log_in();			//function for log in for manager
	
};

#endif
