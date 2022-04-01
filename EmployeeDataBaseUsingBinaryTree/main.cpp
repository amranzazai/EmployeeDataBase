/*
 * main.cpp
 *
 *  Created on: Apr 21, 2021
 *      Author: amranzazai
 */
#include <iostream>
using namespace std;
#include "EmployeeDB.h"

int main()
{
	EmployeeDB database;
	int search;
	string name;
	do{
		cout << "\nSelect from the following options:\n"
				"Insert a new employee: 1\n"
				"Delete an existing employee: 2\n"
				"Search for an employee: 3\n"
				"Display all employee records: 4\n"
				"-1 to quit\n\n";
		cin >> search;

		switch(search)
		{
			case 1:
			{
				Employee x;
				cout<<"Enter an employee name to insert: ";
				cin>>name;
				x.setName(name);
				database.insertEmployee(x);
				break;
			}
			case 2:
			{
				Employee y;
				cout<<"Enter an employee name to delete: ";
				cin>>name;
				y = database.searchEmployee(name);
				cout<<database.deleteEmployee(y)<<endl;
				break;
			}
			case 3:
			{
				Employee z;
				cout<<"Enter an employee name to search for: ";
				cin>>name;
				z = database.searchEmployee(name);
				break;
			}
			case 4:
			{
				cout<<"Displaying records "<<endl;
				database.displayRecords();
				break;
			}
			default:
			{
				cout<<"Program terminated\n";
				break;
			}
		}


		}while(search != -1);
	return 0;
}



