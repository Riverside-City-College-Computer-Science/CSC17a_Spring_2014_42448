/* 
 * File:   main.cpp
 * Author: lenovo
 *
 * Created on March 5, 2014, 10:08 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;


int main(int argc, char** argv) {
    string a;
    float b,c,tax,tax1,tax2;
    cout << fixed << showpoint << setprecision(2);
    cout<<"Enter the month"<<endl;
    cin>>a;
    
    cout<<"Enter total collected:"<<endl;
    cin>>b;
    c=b/1.06;
    tax=b-c;
    tax1=tax/3;
    
    tax2=tax*2/3;
    cout<<a<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<"Total Collected: "<<setw(5)<<"$"<<setw(9)<<b<<endl;
    cout<<"Sales:           "<<setw(5)<<"$"<<setw(9)<<c<<endl;
    cout<<"County Sales Tax:"<<setw(5)<<"$"<<setw(9)<<tax1<<endl;
    cout<<"State Sales Tax: "<<setw(5)<<"$"<<setw(9)<<tax2<<endl;
    cout<<"Total Sales Tax: "<<setw(5)<<"$"<<setw(9)<<tax<<endl;
    return 0;
}

