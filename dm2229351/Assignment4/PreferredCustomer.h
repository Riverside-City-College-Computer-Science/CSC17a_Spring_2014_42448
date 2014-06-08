/* 
 * File:   PreferredCustomer.h
 * Author: Diego
 *
 * Created on May 19, 2014, 12:01 AM
 */
#include <iostream>
#include "CustomerData.h"

using namespace std;
#ifndef PREFERREDCUSTOMER_H
#define	PREFERREDCUSTOMER_H

class PreferredCustomer : public CustomerData{
private:
    double purchaseAmount;
    double discountLevel;
public:
    PreferredCustomer(string l, string f, string a, string c, string s, int z, string p, int cust, bool mail)
    : CustomerData( l,  f,  a,  c,  s,  z,  p,  cust,  mail){purchaseAmount=0;discountLevel=0;}
    double getPurchaseAmount(){return purchaseAmount;}
    double getDiscountLevel(){return discountLevel;}
    void addPurchaseAmount(double purchase){purchaseAmount+=purchase-purchase*discountLevel;}
    void setDiscountLevel(double disc){discountLevel=disc;}
};

#endif	/* PREFERREDCUSTOMER_H */

