#include <iostream>
#include <iomanip>
#include <string>
#include <istream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <stdlib.h>
#include <limits>
#include <ctime>
#include <cctype>
#include "Passenger.h"
#include "Manager.h"
#include "Flight.cpp"
#include "Passenger.cpp"
#include "Manager.cpp"
#include "Node.h"
#include "List.h"
#include "List.cpp"
#define MAXSTREAM numeric_limits<streamsize>::max()
using namespace std;
int SequenceSearch(string,string [],int);									//searching function prototype
void BubbleSort(int [],string [],int [],int [],string [],string [], int, int );  	//sorting function prototype
const int array_size=13;

int main()
{
	bool sign=true, menu=true, searchloc=true;
	Manager manager;
	Passenger passenger;
	Flight flight;
	List list;
	
	string locate;
	fstream file;
	file.open("negeri.txt",ios::in);

	
	while(menu)									//loop for main menu
	{
		if(!file)
		{
			cout<<"\nFile is not open.";
			return 0;
		}
				
		if(file.is_open())
		{
			while(!file.eof())
			{
				getline(file,locate);
				list.InsertNode(locate);
			}
		}
		file.close();
		
		mainmenu:
		system("cls");
		cout<<"===================================================\n"
			<<"     WELCOME TO TICKET ONLINE BOOKING SYSTEM\n"
			<<"===================================================\n\n"
			<<"Please Choose====> \n";
		int choice123;
		cout<<"\n1. Manager";
		cout<<"\n2. Customer";		
		cout<<"\n3. Exit";
		cout<<"\n\nChoice====> ";
		cin>>choice123;							
		
		
		if(choice123==1)
		{
			system("cls");
			cout<<"Login: \n";
			manager.log_in();
			menupoint:
			system("cls");
			cout<<"Menu:  (enter number) ";
			cout<<"\n1. Review flight";
			cout<<"\n2. Register new manager";
			cout<<"\n3. Add location";
			cout<<"\n4. Delete location";
			cout<<"\n5. Review location list";
			cout<<"\n6. Exit";
			cout<<"\n\nChoice =====>";
			int choice1;
			cin>>choice1;
			switch(choice1)
			{				
				case 1:
					{
						system("cls");
						cout<<"Review flight(enter number): ";
						flight.revflight();						//review the passenger of the flight in a plane
						menu=false;
						goto menupoint;
						break;						
					}
				case 2:
					{
						system("cls");
						manager.sign_up();						//sign up new manager
						menu=false;
						goto menupoint;
						break;
					}
				case 3:
					{
						system("cls");
						cout<<"Add location:";
						cout<<"\nLocation to add: ";
						string temploc;
						cin.ignore();
						getline(cin,temploc);						//enter location to add
						fstream outfile;
						outfile.open("negeri.txt",ios::app);
						if(!outfile.is_open())
						{
							cout<<"\nOutfile can't open\n";
							system("pause");
							goto menupoint;
						}
						else
						{
							if(list.FindNode(temploc))					//find location using linked list function
							{
								cout<<"\nLocation written above are already exist in the list\n";
								system("pause");
							}
							else
							{
								outfile<<temploc;
								list.InsertNode(temploc);					//add location using linked list function
							}
						}
						
						outfile.close();
						goto menupoint;
						break;
					}
				case 4:
					{
						deletemenu:
						system("cls");
						cout<<"Delete location: ";
						cout<<endl;
						list.DisplayList();						//display all the location in the list 
						cout<<"\nLocation to delete: ";
						string temploc2;
						cin.ignore();
						getline(cin,temploc2);
						if(!list.FindNode(temploc2))					//Find location and return false if found
						{
							cout<<"\nThe location you write are not in the list";
							goto deletemenu;
						}
						else
						{
							list.DeleteNode(temploc2);				//delete location in the list using linked list function
							list.OutputToFile();					//delete location in the file using linked list function
						}
						goto menupoint;
						break;
						
					}
				case 5:
					{
						system("cls");
						if(list.IsEmpty())						//return true if list is empty
						{
							cout<<"The list is empty\n";
							system("pause");
						}
						else
						{
							list.DisplayList();					//display all the location in the list 
						}
						cout<<endl;
						system("pause");
						goto menupoint;
						break;
					}
				case 6:
					{
						system("cls");
						cout<<"Thank You....";
						system("cls");
						goto mainmenu;
					}
				default:break;
			}
						
		}
		
		else if(choice123==2)
		{
			menu=false;
			while(sign)							//Loop for log in and sign up
			{
				system("cls");
				int choice;
				cout<<"1. Log In";
				cout<<"\n2. Sign Up";
				cout<<"\n3. Exit";
				cout<<"\n\nChoice====> ";
				cin>>choice;
				cin.ignore();
				system("cls");
				if(choice==1)
				{
					cout<<"Login: \n";
					passenger.log_in();
					sign=false;
				}
				else if(choice==2)
				{
					passenger.sign_up();	
				}
				else if(choice==3)
				{
					system("cls");
					sign=false;
				}
				else
				sign=true;
			}									//
			system("cls");
			while(searchloc)
			{
				int j;
				string key,sentence[5],plane[5],category[5],planeNum[5];
				int depart[5],arrive[5],price[5];
				flight.Date_Time();
				system("cls");
				fstream arpt;
				cin.ignore();
				search:
				list.DisplayList();
				cout<<"\nLocation (only airports in Malaysia): ";
				getline(cin,key);
				if(!list.FindNode(key)) 					//where function for searching is called using key as key to search
				{
        			cout << "Sorry....The location is unavailable or your spelling is wrong.....try again" <<endl;
        			system("pause");
        			searchloc=true;        			
        			system("cls");
        			goto search;
    			} 
				else 
				{
					system("cls");
        			string temp=flight.getDate()+".txt";
        			cout << "\t \t \tFlights Found to " <<key<<" on date: "<<flight.getDate()<< endl << endl;
            		arpt.open(temp.c_str(),ios::in);
            		if(!arpt)
					{
						cout<<"\nFile is not open.";
						return 0;
					}
					
					cout << "Airline:\tPlane Num\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
					
					if(arpt.is_open())
					{
						int i=0;
						while(!arpt.eof())
						{
							
							string numchange;
							getline(arpt,plane[i]);
							getline(arpt,planeNum[i]);
							getline(arpt,numchange);
							depart[i]=atoi(numchange.c_str());
							getline(arpt,numchange);
							arrive[i]=atoi(numchange.c_str());
							getline(arpt,numchange);
							price[i]=atoi(numchange.c_str());
							getline(arpt,category[i]);
							i++;
						}
						BubbleSort(depart,plane,price,arrive,category,planeNum,3,3);	//sorting according to time in ascending order
					}
					arpt.close();
					
					
					bool deci=true;
					while(deci)
					{
						int a;
						cout<<"\n\nDo you want to sort menu based on: ";
						cout<<"\n1. Price(from low to high)";
						cout<<"\n2. Price (from high to low)";
						cout<<"\n3. Departure time";
						cout<<"\n4. Choose flight";
						cout<<"\n\nChoice ====>";
						cin>>a;
					
						
						switch(a)
						{
							case 1: system("cls");
									cout << "\t \t \tFlights Found to " <<key<<" on date: "<<flight.getDate()<< endl << endl;
									cout << "Airline:\tPlane Num\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
									BubbleSort(price,plane,depart,arrive,category,planeNum,3,a);				//sorting according to price from low to high
									break;
									
							case 2: system("cls");
									cout << "\t \t \tFlights Found to " <<key<<" on date: "<<flight.getDate()<< endl << endl;
									cout << "Airline:\tPlane Num\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
									BubbleSort(price,plane,depart,arrive,category,planeNum,3,a);				//sorting according to price from high to low
									break;
							
							case 3: system("cls");
									cout << "\t \t \tFlights Found to " <<key<<" on date: "<<flight.getDate()<< endl << endl;
									cout << "Airline:\tPlane Num\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
									BubbleSort(depart,plane,price,arrive,category,planeNum,3,a);			//sorting according to time in ascending order
									break;	
									
							case 4: deci=false;
									break;
							
							default:break;
						}
					}
					
					int choice;
					cout<<"\n\nChoose flight =====> ";
					cin>>choice;
					choice-=1;
					system("cls");
					flight.No_Ticket_Buy();
					system("cls");
					int num=price[choice];
					string pla=planeNum[choice];
					string temp1=flight.getDate()+" "+key+" "+pla+".txt";
					system("cls");
					flight.TicketDetail(num,temp1,key,pla);								
					cout<<"\nThank You....";	
					goto mainmenu;
            	}
				
            	
			}	
		}
		else if(choice123==3)
		{
			system("cls");
			cout<<"Thank You....";
			menu=false;
		}
		else 
		{
			system("cls");
			cout<<"Thank You....";
			menu=false;
		}
	}
	
	return 0;
}

void BubbleSort(int data[],string data2[],int data3[],int data4[],string data5[],string data6[], int listSize,int a)
{
	int pass,tempValue;												//sorting function 
	string tempString;
	if(a==1 )
	{
		for(pass=1;pass<listSize;pass++)								
		{
			for(int x=0;x<listSize-pass;x++)
			{
				if(data[x]>data[x+1])								//sorting function in ascending order for price
				{
					tempValue=data[x];
					data[x]=data[x+1];
					data[x+1]=tempValue;
					
					tempString=data2[x];
					data2[x]=data2[x+1];
					data2[x+1]=tempString;
					
					tempValue=data3[x];
					data3[x]=data3[x+1];
					data3[x+1]=tempValue;
					
					tempValue=data4[x];
					data4[x]=data4[x+1];
					data4[x+1]=tempValue;
					
					tempString=data5[x];
					data5[x]=data5[x+1];
					data5[x+1]=tempString;
					
					tempString=data6[x];
					data6[x]=data6[x+1];
					data6[x+1]=tempString;
				}
			}
		}
		for(int i=0;i<listSize;i++)
		{
			cout<<left<<i+1<<". "<<setw(16)<<data2[i];
			cout<<setw(15)<<data6[i];
			cout<<setw(16)<<data3[i];
			cout<<setw(16)<<data4[i];
			cout<<setw(16)<<data[i];
			cout<<setw(21)<<data5[i];
			cout<<endl;
			cout<<right;
		}
	}
	
	else if(a==2)
	{
		for(pass=1;pass<listSize;pass++)							//sorting function in descending order for price
		{
			for(int x=0;x<listSize-pass;x++)
			{
				if(data[x]<data[x+1])
				{
					tempValue=data[x];
					data[x]=data[x+1];
					data[x+1]=tempValue;
					
					tempString=data2[x];
					data2[x]=data2[x+1];
					data2[x+1]=tempString;
					
					tempValue=data3[x];
					data3[x]=data3[x+1];
					data3[x+1]=tempValue;
					
					tempValue=data4[x];
					data4[x]=data4[x+1];
					data4[x+1]=tempValue;
					
					tempString=data5[x];
					data5[x]=data5[x+1];
					data5[x+1]=tempString;
					
					tempString=data6[x];
					data6[x]=data6[x+1];
					data6[x+1]=tempString;
				}
			}
		}
		for(int i=0;i<listSize;i++)
		{
			cout<<left<<i+1<<". "<<setw(16)<<data2[i];
			cout<<setw(15)<<data6[i];
			cout<<setw(16)<<data3[i];
			cout<<setw(16)<<data4[i];
			cout<<setw(16)<<data[i];
			cout<<setw(21)<<data5[i];
			cout<<endl;
			cout<<right;
		}
	}
	
	else if(a==3)
	{
		for(pass=1;pass<listSize;pass++)										//sorting function in ascending order for departure time
		{
			for(int x=0;x<listSize-pass;x++)
			{
				if(data[x]>data[x+1])
				{
					tempValue=data[x];
					data[x]=data[x+1];
					data[x+1]=tempValue;
					
					tempString=data2[x];
					data2[x]=data2[x+1];
					data2[x+1]=tempString;
					
					tempValue=data3[x];
					data3[x]=data3[x+1];
					data3[x+1]=tempValue;
					
					tempValue=data4[x];
					data4[x]=data4[x+1];
					data4[x+1]=tempValue;
					
					tempString=data5[x];
					data5[x]=data5[x+1];
					data5[x+1]=tempString;
					
					tempString=data6[x];
					data6[x]=data6[x+1];
					data6[x+1]=tempString;
				}
			}
		}
		for(int i=0;i<listSize;i++)
		{
			cout<<left<<i+1<<". "<<setw(16)<<data2[i];
			cout<<setw(15)<<data6[i];
			cout<<setw(16)<<data[i];
			cout<<setw(16)<<data4[i];
			cout<<setw(16)<<data3[i];
			cout<<setw(21)<<data5[i];
			cout<<endl;
			cout<<right;
		}
	}	
	
}

int SequenceSearch(string search_key, string array[],int array_size)		//function for searching 
{
	int p;
	int index=-1;
	for(p=0;p<array_size;p++)
	{
		if(search_key==array[p])
		{
			index=p;
			break;
		}
	}
	return index;
}																			//









