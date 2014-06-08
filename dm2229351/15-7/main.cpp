/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on May 18, 2014, 8:59 PM
 */

#include <cstdlib>
#include <iostream>
#include "CustomerData.h"
using namespace std;
void custMailingList(bool);
/*
 * 
 */
int main(int argc, char** argv) {

    CustomerData cust("Diego", "Montelongo", "12533 Black Horse","Eastvale",
            "CA",91752,"909-524-8487",1,true);
    cout << cust.getFirstName() << " " << cust.getLastName() << endl;
    cout << cust.getAddress() << " " << cust.getCity() << ", " << cust.getZip() << endl;
    cout << cust.getPhone() << " Customer Unique ID: " << cust.getCustNum() << endl;
    custMailingList(cust.getMailingList());
    
    CustomerData cust1("Julie", "Montelongo", "12533 Black Horse","Eastvale",
            "CA",91752,"909-524-8487",2,true);
    cout << cust1.getFirstName() << " " << cust1.getLastName() << endl;
    cout << cust1.getAddress() << " " << cust1.getCity() << ", " << cust1.getZip() << endl;
    cout << cust1.getPhone() << " Customer Unique ID: " << cust1.getCustNum() << endl;
    custMailingList(cust1.getMailingList());
    
    CustomerData cust2("George", "Lopez", "48654 Engle Ase","Charlieville",
            "CA",95554,"909-524-1300",3,false);
    cout << cust2.getFirstName() << " " << cust2.getLastName() << endl;
    cout << cust2.getAddress() << " " << cust2.getCity() << ", " << cust2.getZip() << endl;
    cout << cust2.getPhone() << " Customer Unique ID: " << cust2.getCustNum() << endl;
    custMailingList(cust2.getMailingList());
    return 0;
}
void custMailingList(bool m)
{
    if(m)
    {
        cout << "Customer is in our mailing list" << endl;
    }
    else
        cout << "Customer is not on our mailing list" << endl;
}
