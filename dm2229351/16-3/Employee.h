/* 
 * File:   Employee.h
 * Author: Diego
 *
 * Created on May 17, 2014, 10:27 PM
 */
#include <iostream>

using namespace std;

#ifndef EMPLOYEE_H
#define	EMPLOYEE_H

class Employee{
protected:
    string emp_name;
    int emp_num;
    string hire_date;
public:
    Employee(string name, int num, string date){
        emp_name=name; emp_num=num; hire_date=date;}
    string getName(){return emp_name;}
    int getNum(){return emp_num;}
    string getHireDate(){return hire_date;}
    void setName(string name){emp_name=name;}
    void setNum(int num){emp_num=num;}
    void setHireDate(string date){hire_date=date;}
};



#endif	/* EMPLOYEE_H */

