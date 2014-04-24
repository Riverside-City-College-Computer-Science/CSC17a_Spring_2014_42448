/* 
 * File:   main.cpp
 * Author: Scott Nevin
 * Purpose: Demonstrate utilizing structures with arrays
 * Created on March 24, 2014, 1:18 PM
 */

//Libraries
#include <ctime>
#include <iostream>
#include <cstdlib>
using namespace std;

//User defined Libraries
#include "AryStruct.h"

//Global constants and variables

//Function prototypes
void fillAry(AryStruct1 *, int);
AryStruct1 *fillAry(int);//passing back a pointer
AryStruct2 *fillAry(int, int);//filling 2 dimensional
void prntAry(const AryStruct1 *, int);
void prntAry(const AryStruct2 *);
void dstry1A(AryStruct1 *);
void dstry1B(AryStruct1 *);
void dstry2(AryStruct2 *);


//Begin execution here
int main(int argc, char** argv) {
    
    //set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare array structure and variables
    AryStruct1 array1, *ptrAry1;
    AryStruct2 *array2;
    int size1 = 100, records=10, fields=9;
    
    //fill the array
    fillAry(&array1,size1);
    
    //Fill the 2 dimensional array
    array2=fillAry(records, fields);
    
    //set the pointer for the array
    ptrAry1=fillAry(size1);
    
    //print that array (currently using a pointer)
    prntAry(&array1, 10);
    //print the array utilizing pointer
    prntAry(ptrAry1, 10);
    //print 2 dimensional array
    prntAry(array2);
    
    //destroy that memory and exit
    dstry1A(&array1);
    dstry1B(ptrAry1);
    dstry2(array2);

    //Exit stage right
    return 0;
}

//Destroy 2 dimensional array
void dstry2(AryStruct2 *a){
    for(int rec=0;rec<a->records;rec++){
        delete []a->array[rec];
    }
    delete []a->array;
    delete a;
}

//Print 2 dimensional array
void prntAry(const AryStruct2 *a){
    cout<<endl;
    //Print the array
    for(int rec=0;rec<a->records;rec++){
        for(int fld=0;fld<a->fields;fld++){
            cout<<a->array[rec][fld]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

//Fill 2 dimensional array
AryStruct2 *fillAry(int r, int f){
    //allocate memory for the structure
    AryStruct2 *a=new AryStruct2;
    //Declare the size of the array structure
    //using 2 dimensions
    a->records=r;
    a->fields=f;
    //allocate memory
    a->array=new int*[a->records];
    //fill the array
    for(int rec=0;rec<a->records;rec++){
        a->array[rec]=new int[a->fields];
        for(int fld=0;fld<a->fields;fld++){
            a->array[rec][fld]=rand()%90+10;
        }
    }
    return a;
}

void dstry1B(AryStruct1 *a){
    delete[]a->array;
    delete a;
}

void dstry1A(AryStruct1 *a){
    delete[]a->array;
}

void prntAry(const AryStruct1 *a, int perline){
    cout<<endl;
    //Print the array
    for(int i=0;i<a->size;i++){
        cout<<a->array[i]<<" ";
        if(i%perline==(perline-1))cout<<endl;
    }
    cout<<endl;
}

AryStruct1 *fillAry(int n){
    
    //allocate memory for the structure
    AryStruct1 *a=new AryStruct1;
    //Declare the size of the array structure
    a->size=n;
    //allocate memory
    a->array=new int[a->size];
    //fill the array
    for(int i=0;i<a->size;i++){
        a->array[i]=rand()%90+10;
    }
    return a;
}

void fillAry(AryStruct1 *a, int n){
    //Declare the size of the array structure
    a->size=n;
    //allocate memory
    a->array=new int[a->size];
    //fill the array
    for(int i=0;i<a->size;i++){
        a->array[i]=rand()%90+10;
    }
}