/* 
 * File:   Employee.h
 * Author: Joe
 *
 * Created on May 9, 2014, 2:53 PM
 */

#include <string>
using namespace std;

#ifndef EMPLOYEE_H
#define	EMPLOYEE_H

class Employee
{
private:
    string name;
    int idNumber;
    string department;
    string position;
public:
    //Constructors
    Employee();
    Employee(string,int,string,string);
    Employee(string ,int);
    //Mutators
    void setName(string);
    void setId(int);
    void setDept(string);
    void setPos(string);
    //Accessors
    string getName() const;
    int getId() const;
    string getDept() const;
    string getPos() const;
    void outEmp() const;
};
#endif	/* EMPLOYEE_H */

