/* 
 * File:   main.cpp
 * Author: Zhang, Yi
 * Professor: Dr. Mark E. Lehr
 * CSC-17A
 * Created on March 2, 2014, 7:23 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;


int main(int argc, char** argv) {
    int quantity;
    float money;
    cout<<"How many do you want?"<<endl;
    cin>>quantity;
    while (quantity<=0){ cout<<"Please enter a number which is greater than 0,"<<endl;
    cin>>quantity;}
    if(quantity<10)money=quantity*99;
    else if (quantity>=10&&quantity<=19)money=quantity*99*0.8;
   
    else if(quantity>=20&&quantity<=49)money=quantity*99*0.7;
    
    else if (quantity>=50&&quantity<=99)money=quantity*99*0.6;

    else if (quantity>=100)money=quantity*99*0.5;
   cout<<"You need "<<money<<" dollars.";
    return 0;
}

