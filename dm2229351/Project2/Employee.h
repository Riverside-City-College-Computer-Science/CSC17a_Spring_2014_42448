/* 
 * File:   Employee.h
 * Author: Diego
 * Outline for employee class
 * Created on May 23, 2014, 11:13 PM
 */
#include <iostream>

using namespace std;

#ifndef EMPLOYEE_H
#define	EMPLOYEE_H

class Employee
{
protected:
    string name;
    string address;
    string city;
    string state;
    int zip;
    int employee_id;
    string password;
    float wage;
public:
    string getName();
    string getAddress();
    string getCity();
    string getState();
    int getZip();
    int getEmpID();
    bool checkPassword(string);
    void setPassword(string);
};

#endif	/* EMPLOYEE_H */

