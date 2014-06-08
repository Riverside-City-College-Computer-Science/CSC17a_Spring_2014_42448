/* 
 * File:   ShiftSupervisor.h
 * Author: Diego
 *
 * Created on May 17, 2014, 11:14 PM
 */
#include <iostream>
#include "Employee.h"

using namespace std;

#ifndef SHIFTSUPERVISOR_H
#define	SHIFTSUPERVISOR_H

class ShiftSupervisor : public Employee
{
private:
    int salary;
    int production;
public:
    ShiftSupervisor(string name, int num, string date, int salary, int production)
    :  Employee( name,  num,  date){this->salary=salary;this->production=production;}
    int getSalary(){return salary;}
    int getProduction(){return production;}
    void setSalary(int s){salary=s;}
    void setProduction(int p){production=p;}
};


#endif	/* SHIFTSUPERVISOR_H */

