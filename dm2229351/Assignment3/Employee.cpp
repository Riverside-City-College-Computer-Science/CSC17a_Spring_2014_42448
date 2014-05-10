#include "Employee.h"
#include <iostream>

using namespace std;

Employee::Employee(string name,int id,string dept,string pos)
{
    this->name=name;
    idNumber=id;
    department=dept;
    position=pos;
}
Employee::Employee(string name,int id)
{
    this->name=name;
    idNumber=id;
    department="";
    position="";
}
Employee::Employee()
{
    name="";
    idNumber=0;
    department="";
    position="";
}
void Employee::setName(string name)
{
    this->name=name;
}
void Employee::setID(int id)
{
    idNumber=id;
}
void Employee::setDepartment(string dept)
{
    department=dept;
}
void Employee::setPosition(string pos)
{
    position=pos;
}
string Employee::getName()
{
    return name;
}
int Employee::getID()
{
    return idNumber;
}
string Employee::getDepartment()
{
    return department;
}
string Employee::getPosition()
{
    return position;
}
void Employee::printEmployee()
{
    cout << name << endl;
    cout << idNumber << endl;
    cout << department << endl;
    cout << position << endl;
}
