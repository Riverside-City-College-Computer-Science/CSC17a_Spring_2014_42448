/* 
 * File:   main.cpp
 * Author: Luis Pow Sang
 * Created on March 10, 2014, 1:12 PM
 */

//Libraries
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

//No global constants

//Function prototypes
void fillStat(int [], int);//fill static array
void prntStat(int [], int, int);//print static
int *fillDyn(int);//fill dynamic array
void prntDyn(int [], int, int);//Print dynamic
void destroy(int[]);
void fillVec(vector<int> &,int);
void prntVec(vector<int> &,int);

//Execution begins here
int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Declare out static variables
    const int SIZE=100;
    int sArray[SIZE];
    fillStat(sArray,SIZE);
    prntStat(sArray,SIZE,10);
    //Declare out dynamic variables
    int size=SIZE;
    int *dArray=fillDyn(size);
    prntDyn(dArray,size,10);
    destroy(dArray);
    //Declare vector variable
    vector<int> vArray;
    fillVec(vArray,size);
    prntVec(vArray,10);
    
    //Exit Stage Right
    return 0;
}

void destroy(int a[]){
    delete[]a;
    a=0;
}

void prntVec(vector<int> &a,int perLine){
    cout<<endl;
    cout<<"This is the Vector Array!!!!"<<endl;
    for(int i=0;i<a.size();i++){
         cout<<a[i]<<" ";
         if(i%perLine==(perLine-1))cout<<endl;
        
    }
    cout<<endl;
}

void prntDyn(int a[], int n, int perLine){
    cout<<endl;
    cout<<"This is the Dynamic Array!!!!"<<endl;
    for(int i=0;i<n;i++){
         cout<<a[i]<<" ";
         if(i%perLine==(perLine-1))cout<<endl;
        
    }
    cout<<endl;
}

void prntStat(int a[], int n, int perLine){
    cout<<endl;
     cout<<"This is the Static Array!!!!"<<endl;
    for(int i=0;i<n;i++){
         cout<<a[i]<<" ";
         if(i%perLine==(perLine-1))cout<<endl;
        
    }
    cout<<endl;
}

//Fill a dynamic array i.e. Vector
//2 digit number
void fillVec(vector<int> &a,int n){
     for(int i=0;i<n;i++){
        a.push_back(rand()%90+10);
        
    }
}

//Fill a dynamic array
//2 digit number
int *fillDyn(int n){
    //Declare and allocate the dynamic array
    if(n<2)n=2;
    //Allocate memory
    int *a=new int[n];
    //Fill with data
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10;
        
    }
    //Return and exit with memory allocated array
    return a;
}

//Fill a static array
//2 Digit numbers
void fillStat(int a[], int n){
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10;
        
    }
    
    
}