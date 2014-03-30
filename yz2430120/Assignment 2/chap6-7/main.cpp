/* 
 * File:   main.cpp
 * Author: Zhang, Yi
 *
 * Created on March 2, 2014, 8:02 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

float temperature(int);
int main(int argc, char** argv) {
   cout<<"F"<<"             "<<"C"<<endl;
    for(int a=1;a<=20;a++){
        
        float C=  temperature(a);
        cout<<a<<"             "<<C<<endl;
    }
    return 0;
}

float temperature(int a){
    float b=static_cast<float>(a);
    
    
    return 5*(b-32)/9;
    
}