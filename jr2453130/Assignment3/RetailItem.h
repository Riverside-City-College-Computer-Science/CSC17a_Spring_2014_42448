/* 
 * File:   RetailItem.h
 * Author: Joe
 *
 * Created on May 9, 2014, 4:46 PM
 */

#include <string>
using namespace std;

#ifndef RETAILITEM_H
#define	RETAILITEM_H

class RetailItem{
private:
    string desc;
    int units;
    float price;
public:
    //Constructor
    RetailItem(string,int,float);
    //Mutators
    void setDesc(string);
    void setUnits(int);
    void setPrice(float);
    //Accessors
    string getDesc() const;
    int getUnits() const;
    double getPrice() const;
    void prnt() const;
};
#endif	/* RETAILITEM_H */

