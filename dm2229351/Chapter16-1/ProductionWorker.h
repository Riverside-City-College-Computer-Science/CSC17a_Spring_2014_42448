/* 
 * File:   ProductionWorker.h
 * Author: Diego
 *
 * Created on May 17, 2014, 10:34 PM
 */

#include <iostream>
#include "Employee.h"

using namespace std;

#ifndef PRODUCTIONWORKER_H
#define	PRODUCTIONWORKER_H

class ProductionWorker : public Employee
{
private:
    int shift;
    double rate;
public:
    ProductionWorker(string name, int num, string date, int time_shift, double hourly)
    :  Employee( name,  num,  date){shift=time_shift;rate=hourly;}
    int getShift(){return shift;}
    double getRate(){return rate;}
    void setShift(int s){shift=s;}
    void setRate(double r){rate=r;}
};


#endif	/* PRODUCTIONWORKER_H */

