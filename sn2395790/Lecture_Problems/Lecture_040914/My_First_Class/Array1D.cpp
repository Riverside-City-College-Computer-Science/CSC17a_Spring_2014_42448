/* 
 * File:   Array1D.cpp
 * Author: Scott Nevin
 * Created on April 9, 2014, 1:26 PM
 */

//Include system Libraries
#include <iostream>
#include <cstdlib>
using namespace std;

//Include user libraries
#include "Array1D.h"

//constructor
Array1D::Array1D(int n){
    //First set the size
    setsize(n);
    //Fill the array
    fillArray();
}

void Array1D::setsize(int n){
    //Validate the size
    if(n<=2)size=2;
    else size=n;   
}

void Array1D::fillArray(){
    //Allocate memory
    data=new int[size];
    //fill array randomly
    for(int i=0;i<size;i++){
        data[i]=rand()%90+10;      
    }
}

void Array1D::prntArray(int perLine){
    //print array
    cout<<endl;
    for(int i=0;i<size;i++){
        cout<<data[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}
