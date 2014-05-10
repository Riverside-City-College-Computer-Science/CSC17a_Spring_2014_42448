/* 
 * File:   YearOfDay.h
 * Author: Diego
 *
 * Created on May 8, 2014, 11:33 PM
 */
#include <iostream>

using namespace std;

#ifndef YEAROFDAY_H
#define	YEAROFDAY_H

class YearOfDay{
private:
    int day;
    string month;
public:
    YearOfDay(string,int);
    operator++();
    operator--();
};

#endif	/* YEAROFDAY_H */

