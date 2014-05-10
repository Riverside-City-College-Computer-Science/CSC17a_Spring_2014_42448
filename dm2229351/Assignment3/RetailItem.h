/* 
 * File:   RetailItem.h
 * Author: Diego
 *
 * Created on May 8, 2014, 10:43 AM
 */

#include <iostream>

using namespace std;

#ifndef RETAILITEM_H
#define	RETAILITEM_H

class RetailItem{
private:
    string description;
    int unitsOnHand;
    double price;
public:
    RetailItem(string,int,double);
    void setDesc(string);
    void setUnits(int);
    void setPrice(double);
    string getDesc(){return description;}
    int getUnits(){return unitsOnHand;}
    double getPrice(){return price;}
    void print(int);
};



#endif	/* RETAILITEM_H */

