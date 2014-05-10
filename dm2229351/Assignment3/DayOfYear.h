/* 
 * File:   DayOfYear.h
 * Author: Diego
 *
 * Created on May 8, 2014, 10:47 PM
 */

#include <iostream>

using namespace std;

#ifndef DAYOFYEAR_H
#define	DAYOFYEAR_H

class DayOfYear{
private:
    int day;
    const static string month[];
public:
    DayOfYear(int);
    DayOfYear(int,string);
    int getDay();
    void print();
    DayOfYear operator++(int);
    DayOfYear operator--(int);
    
};

#endif	/* DAYOFYEAR_H */

