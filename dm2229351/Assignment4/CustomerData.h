/* 
 * File:   CustomerData.h
 * Author: Diego
 *
 * Created on May 18, 2014, 9:08 PM
 */
#include <iostream>
#include "PersonData.h"
using namespace std;

#ifndef CUSTOMERDATA_H
#define	CUSTOMERDATA_H

class CustomerData : public PersonData{
private:
    int customerNumber;
    bool mailingList;
public:
    CustomerData(string l, string f, string a, string c, string s, int z, string p, int cust, bool mail):
    PersonData( l,  f,  a,  c,  s,  z,  p)
    {customerNumber=cust; mailingList=mail;}
    int getCustNum(){return customerNumber;}
    bool getMailingList(){return mailingList;}
    void setCustNum(int x){customerNumber=x;}
    void setMailingList(bool m){mailingList=m;}
};



#endif	/* CUSTOMERDATA_H */

