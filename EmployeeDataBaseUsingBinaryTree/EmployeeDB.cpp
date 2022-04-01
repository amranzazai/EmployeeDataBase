/*
 * EmployeeDB.cpp
 *
 *  Created on: Apr 14, 2021
 *      Author: amranzazai
 */

#include "EmployeeDB.h"
EmployeeDB::EmployeeDB(){

}
void EmployeeDB::insertEmployee(Employee x)
{
	db.insertEmployee(x);
}
bool EmployeeDB::deleteEmployee(Employee x)
{
	if(db.searchEmployee(x))
	{
		db.remove(x);
		return true;
	}
	return false;
}
Employee EmployeeDB::searchEmployee(string y)
{
	return db.getEmployee(y);
}
void EmployeeDB::displayRecords()
{
	db.displayInOrder();
}
