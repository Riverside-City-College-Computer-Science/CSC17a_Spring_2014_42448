/* 
 * File:   main.cpp
 * Author: Abel Salazar
 * Created on March 14, 2014, 2:28 PM
 */

//system libraries
#include <iostream>
#include <cstdlib>

using namespace std;
//global constants

//function prototypes
int doSomething(int *,int *);

//execution begins here
int main(int argc, char** argv) {
    //variable declaration
    int size=1;
    int *x=new int [size];
    int *y=new int [size];
    int *total = new int [size];
    *total = doSomething(*x,*y);
    cout << "the total is " << total <<endl;
    
    
    //exit stage
    return 0;
}

int doSomething(int *x,int *y){
    int temp1=1;
    int *temp = new int [temp1];
    *temp= *x;
    (*x) = (*y) * 10;
    (*y) = *temp * 10;
    *temp= *x + *y;
    return *temp;
}
