/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on September 23, 2013, 8:22 PM
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Our Libraries
#include "Array.h"
#include "Array2d.h"

//Global Constants

//Function Prototypes
Array *filStrct(int);
void   prntStrc(Array *,int);
void   dstrStr(Array *);
//Create and implement
Array2d *filStrc2(int,int);
void   prntStrc(Array2d *,int);
void   dstrStr(Array2d *);

int main(int argc, char** argv) {
    //Initialize random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Allocate the array structure
    Array *array1=filStrct(75);
    Array *array2=filStrct(25);
    Array2d *array3=filStrc2(10,10);
    Array2d *array4=filStrc2(25,25);
    //Print the structure
    prntStrc(array1,10);
    prntStrc(array2,10);
    prntStrc(array3,10);
    prntStrc(array4,10);
    //Deallocate memory
    dstrStr(array1);
    dstrStr(array2);
    dstrStr(array3);
    dstrStr(array4);
    //Exit stage right
    return 0;
}

Array2d *filStrc2 (int r, int c)
{
    //Allocate memory for the structure
    Array2d *a=new Array2d;
    //Declare the size of the Array Structure
    a->row=r;
    a->col=c;
    //Allocate memory
    a->data=new int*[a->row];
    //Fill the array
    for(int rec=0;rec<a->row;rec++){
        a->data[rec]=new int[a->col];
        for(int fld=0;fld<a->col;fld++){
            a->data[rec][fld]=rand()%90+10;
        }
    }
    return a;
}
void   prntStrc(Array2d *a,int perLine)
{
    cout<<endl;
    //Print the array
    for(int rec=0;rec<a->row;rec++){
        for(int fld=0;fld<a->col;fld++){
            cout<<a->data[rec][fld]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void   dstrStr(Array2d *a)
{
    for(int rec=0;rec<a->row;rec++){
        delete []a->data[rec];
    }
    delete []a->data;
    delete a;
}
void   dstrStr(Array *a){
    //Deallocate the data first
    delete [] a->data;
    //Deallocate the array structure
    delete a;
}

void   prntStrc(Array *a,int colPRow){
    //Output the array
    cout<<endl;
    for(int i=0;i<a->size;i++){
        cout<<a->data[i]<<" ";
        if(i%colPRow==(colPRow-1))
            cout<<endl;
    }
    cout<<endl;
}

Array *filStrct(int n){
    //Create the pointer to a structure
    Array *a=new Array;
    //Set the size of the array in the structure
    a->size=n;
    //Allocate the array
    a->data=new int[n];
    //Fill the array
    for(int i=0;i<n;i++){
        a->data[i]=rand()%90+10;
    }
    //Return the structure
    return a;
}

