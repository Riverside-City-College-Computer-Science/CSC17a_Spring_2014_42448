/* 
 * File:   Employee.h
 * Author: Diego
 * Outline for employee class
 * Created on May 23, 2014, 11:13 PM
 */

#include <iostream>
#include "Employee.h"

using namespace std;

string Employee::getName()
{
    return name;
}
string Employee::getAddress()
{
    return address;
}
string Employee::getCity()
{
    return city;
}
string Employee::getState()
{
    return state;
}
int Employee::getZip()
{
    return zip;
}
int Employee::getEmpID()
{
    return employee_id;
}
bool Employee::checkPassword(string pass)
{
    return pass==password;
}
void Employee::setPassword(string pass)
{
    password=pass;
}