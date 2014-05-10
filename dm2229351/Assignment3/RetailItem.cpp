
#include "RetailItem.h"
#include <iostream>
using namespace std;

RetailItem::RetailItem(string d,int u,double p)
{
    description=d;
    unitsOnHand=u;
    price=p;
}
void RetailItem::setDesc(string d)
{
    description=d;
}
void RetailItem::setUnits(int u)
{
    unitsOnHand=u;
}
void RetailItem::setPrice(double p)
{
    price=p;
}
void RetailItem::print(int x)
{
    cout << "Item #" << x << "\t\t" << description << "\t\t"
            << unitsOnHand << "\t\t" << price << endl;
}
