#include <iostream>
#include <iomanip>
#include <string>
#include <istream>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <limits>
#include <ctime>
#include "Flight.h"

#define MAXSTREAM numeric_limits<streamsize>::max()
using namespace std;

Flight::Flight()
{
	matrix[numberOfRow][numberOfCol]='#';
	num_passenger=1;
}


void Flight::revflight()
{
	string date,plane,location,temp1;
	cout<<"\nEnter date (dd-mm-yyyy): ";
	cin.ignore();
	getline(cin,date);
	cout<<"Enter plane's name: ";
	getline(cin,plane);
	cout<<"Enter arrival location: ";
	getline(cin,location);
	
	temp1=date+" "+location+" "+plane+".txt";
	string name[90],gender[90],contact[90],email[90],phone[90],tempsitnum[90];
	ifstream placefile;
	cout<<"\n\n\n";
	cout <<left<<setw(30)<<"Name:"<<setw(10)<<"Gender:"<<setw(30)<<"Contacts:"<<setw(18)<<"Email:"<<setw(14)<<"Phone:"<<setw(12)<<"Seat Num:";
	cout<<"\n";
	placefile.open(temp1.c_str());
	int i=0;
	if(placefile.is_open())
	{
		while(!placefile.eof())
		{
			getline(placefile,name[i]);
			
			getline(placefile,gender[i]);
			
			getline(placefile,contact[i]);
			
			getline(placefile,email[i]);
			
			getline(placefile,phone[i]);
			
			getline(placefile,tempsitnum[i]);
			i++;
		}
		placefile.close();
	}
	
	else
	{
		cout<<"No file.";
	}	
	
	for (int j=0;j<=i;j++)
	{
		cout<<setw(30)<<name[j];
		cout<<setw(10)<<gender[j];
		cout<<setw(30)<<contact[j];
		cout<<setw(18)<<email[j];
		cout<<setw(14)<<phone[j];
		cout<<setw(12)<<tempsitnum[j]<<endl;
	}
	system("pause");
	cout<<right;
	
}


void Flight::TicketDetail(int num,string temp1,string key,string planeNum)		//kena pass value untuk number of ticket to order ke dalam void ini
{
	int tempnum=1;
	fstream seat;
	seat.open("Seat.txt",ios::in);
	string tempseat,tempstack;
	if(!seat.is_open())
	{
		system("cls");
		cout<<"File Seat.txt does not exist. ";
		system("pause");
		system("cls");
	}
	while(!seat.eof())
	{
		getline(seat,tempstack);
		sit.push(tempstack);
	}
	seat.close();	
	int num_ticket=get_numticket();
	fstream file,filein;
	string name[num_ticket],namecon[num_ticket],email[num_ticket],phone[num_ticket],gender[num_ticket],seatnum[num_ticket];
	file.open(temp1.c_str(),ios::app);
	filein.open(temp1.c_str(),ios::in);
	cout<<"GUEST DETAIL";
	cin.ignore();
	for (int i=0; i<num_ticket;i++)
	{
		cout<<"\nAdult "<<i+1;
		cout<<"\nName: ";
		
		getline(cin,name[i]);
		file<<name[i]<<endl;
		cout<<"\nGender (M/F): ";
		getline(cin,gender[i]);
		file<<gender[i]<<endl;
		cout<<"\n\nContact Details";
		cout<<"\nName: ";
		getline(cin,namecon[i]);
		file<<namecon[i]<<endl;
		cout<<"\nEmail Address: ";
		getline(cin,email[i]);
		file<<email[i]<<endl;
		cout<<"\nPhone Number: ";
		getline(cin,phone[i]);
		file<<phone[i]<<endl;
		

		int linenum=0;
		for(linenum;linenum<6; linenum++)
		{
			getline(filein,tempseat);
			if(linenum==5)
			{
				if(tempseat==sit.stackBottom(tempnum))
				{
					linenum=-1;
					tempnum++;
				}
				else if(tempseat!=sit.stackBottom(tempnum))
				{
					file<<sit.stackBottom(tempnum)<<endl;
					seatnum[i]=sit.stackBottom(tempnum);
					tempnum++;
				}
			}
		}		

	}
	system("cls");
	Flight::payment_method(num);
	
	file.close();
	filein.close();
	system("cls");
	for (int i=0; i<num_ticket;i++)
	{
		cout<<"============================================================";
		cout<<"\n				       TICKET";
		cout<<"\nName        : "<<name[i]; 
		cout<<"\nGender      : "<<gender[i];
		cout<<"\nLocation    : "<<key;
		cout<<"\nPlane Number: "<<planeNum;	
		cout<<"\nSeat Number : "<<seatnum[i];	
		cout<<"\n=============================================================";
		cout<<endl;
	}
	
} 




void Flight::Date_Time()
{
	
	int option;
	bool a=true,b=true;
	
    while(a)
	{
		
	
		time_t t = time(NULL);	
        tm* tPtr = localtime(&t);
 
        cout << "----------------------------------------\n";
        cout << " Current Date: " <<(tPtr->tm_mday)<<"/"<< (tPtr->tm_mon)+1 <<"/"<< (tPtr->tm_year)+1900<< endl;
        cout << " Current Time: " << (tPtr->tm_hour)<<":"<< (tPtr->tm_min)<<":"<< (tPtr->tm_sec) << endl;
	
		cout<<"Pick a departure date in 2019 'DD/MM/YY' format : ";
		cout<<"\nDay: ";
		cin>>d1;
		cout<<"\nMonth: ";
		cin>>m1;
		cout<<"\nYear: ";
		cin>>y1;
		
		
		if(y1>=((tPtr->tm_year)+1900))
		{
			if(((d1<(tPtr->tm_mday))&&(m1<=(tPtr->tm_mon)+1)) && (y1<=((tPtr->tm_year)+1900)))
			{
				a=true;
				cout<<"Invalid date. Please re-enter.\n\n";
				continue;
			}
			
	
			if((d1>=1 && d1<=31) && (m1==1||m1==3||m1==5||m1==7||m1==8||m1==10||m1==12))
			break;
		
			else if((d1>=1 && d1<=30) && (m1==4||m1==6||m1==9||m1==11))
			break;
		
			else if((d1>=1 && d1<=28) && (m1==2))
			break;
		}
		else 
		{
			cout<<"Invalid date. Please re-enter.\n\n";
		} 
	} 

}

string Flight::getDate()
{
	ostringstream output;
	output<<d1<<"-"<<m1<<"-"<<y1;
	return output.str();
}

void Flight::No_Ticket_Buy()
{
	
	cout<<"Number of passsenger: ";
	cin>>num_passenger;
}

void Flight::payment_method(int num)
{
	bool a=true;
	while(a)
	{
		int choice1,wallet;
		string password,card,date,cvv,user_id;
		cout << "\nHow would you like to pay?";
        cout << "\n1.Debit Card(1) \n2.Credit Card(2) \n3.E-Wallet(3)";
        cout << "\nEnter your choice :";
        cin >> choice1;
        switch(choice1)
        {
        case 1:
            cout << "\nEnter card no.:";
            cin >> card;
            cout << "\nEnter expiry date:";
            cin >> date;
            cout << "\nEnter CVV no.:";
            cin >> cvv;
            cout<< "\nTransaction Successful!\n";
            cout<<"RM "<<num*get_numticket();
            a=false;
            break;
        case 2:
            cout << "\nEnter user id:";
            cin >> card;
            cout << "\nEnter password:";
            cin >> password;
            cout << "\nTransaction Successful!\n";
            cout<<"RM "<<num*get_numticket();
            a=false;
            break;
        case 3:
            cout << "\nE-Wallet Available: \n1.Boost(1) \n2.Grab-Pay(2) \n3.Alipay(3) \n4.Touch n Go(4) \n5.Others(5)";
            cout << "\n\nSelect your E-Wallet:";
            cin >> wallet;
            cout << "\nYou have selected:" << wallet;
            cout << "\nEnter user id:";
            cin >> user_id;
            cout << "\nEnter password:";
            cin >> password;
            cout << "\nTransaction Successful!\n";
            cout<<"RM "<<num*get_numticket();
            a=false;
            break;
        default:
            cout << "\nWrong input entered!\nTry again!";
        }
    }

}


int Flight::get_numticket()
{
	return num_passenger;
}

char Flight::getMatrix()
{
	return matrix[numberOfRow][numberOfCol];
}


