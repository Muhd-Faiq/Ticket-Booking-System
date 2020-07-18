#include <iostream>
#include <iomanip>
#include <string>
#include <istream>
#include <fstream>
#include<stdlib.h>
#include<limits>
#include "Passenger.h"
#define MAXSTREAM numeric_limits<streamsize>::max()
using namespace std;


Passenger::Passenger()
{
	name="";
	password="";
}

void Passenger::sign_up()
{
	ofstream didi;
	didi.open("passenger.txt",ios::app);
	cout << "Please enter your email >> ";
	getline(cin,name);
			
	didi << name << "\t";
	cout << "Please enter your password >> " ;
			
	getline(cin,password);
			
	didi << password<<endl;
	didi.close();
			
}


void Passenger::log_in()
{
	string w,y;
	bool a=true;
	fstream didi;
	int b=0;
		
	while(a)
	{
		if(b>1)
		{
			cout << "Wrong password or email. Please retry "<< endl;
		}
		cout << "Enter your email : ";
	    cin >> w;
	    cin.ignore();
		cout << "Enter your password : ";
		cin >> y;
		cin.ignore();
		didi.open("passenger.txt",ios::in);
		while(getline(didi,name,'\t'))
		{
			didi >>password;
			
			if(name.find(w,0)!=string::npos)
			{
				if(password.find(y,0)!=string::npos)
				{
		        cout << "\n\nWelcome !" << endl;
		        a=false;
		        continue;
				}
				else 
				{
					b++;
				}
			}
			else
			b++;
		}
		didi.close();
		   
	}
}


