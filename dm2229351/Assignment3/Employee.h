/* 
 * File:   Employee.h
 * Author: diegomontelongo
 *
 * Created on May 6, 2014, 11:07 PM
 */
#include <iostream>
using namespace std;
#ifndef EMPLOYEE_H
#define	EMPLOYEE_H

class Employee{
private:
    string name;
    int idNumber;
    string department;
    string position;
public:
    Employee(string,int,string,string);
    Employee(string,int);
    Employee();
    void setName(string);
    void setID(int);
    void setDepartment(string);
    void setPosition(string);
    string getName();
    int getID();
    string getDepartment();
    string getPosition();
    void printEmployee();
};



#endif	/* EMPLOYEE_H */

