/* 
 * File:   main.cpp
 * Author: Andrew Kim
 * Created on March 10, 2014, 1:12 PM
 */

#include <ctime>
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

//Global Constants

//Function Prototypes
void filStat(int [],int);               //Fill a static array
void prnStat(int [],int,int);           //Print a static array
int *fillDyn(int);                      //Fill a dynamic array
void prnDyn(int [],int,int);            //Print a dynamic array
void destroy(int []);
void fillVec(vector<int> &,int);
void prntVec(vector<int> &,int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Declare our static variables
        const int SIZE=100;
        int sArray[SIZE];
        //Fill the static array
         filStat(sArray,SIZE);
        //Print the static array
        prnStat(sArray,SIZE,10);
    //Declare our dynamic array and fill
        int size=SIZE;
        int *dArray=fillDyn(size);
        //Print the dynamic array
        prnDyn(dArray,size,10);
        //Destroy the memory allocated
        destroy(dArray);
    //Declare the vector
        vector<int> vArray;
        //Fill the vector
        fillVec(vArray,size);
        //Print the vector
        prntVec(vArray,10);
    //Exit Stage Right
    return 0;
}

//Print a dynamic array (Vector)
void prntVec(vector<int> &a,int perLine){
    cout<<endl;
    cout<<"Vector Array"<<endl;
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

//Fill a dynamic array (Vector)
//2 Digit Numbers
void fillVec(vector<int> &a,int n){
    for(int i=0;i<n;i++){
        a.push_back(rand()%90+10);
    }
}

//Destroy the memory allocated
void destroy(int a[]){
    delete []a;
    a=0;
}

//Print a dynamic array
void prnDyn(int a[],int n,int perLine){
    cout<<endl;
    cout<<"Dynamic Array"<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

//Fill a dynamic array
//2 Digit Numbers
int *fillDyn(int n){
    //Declare and allocate the dynamic array
    if(n<2)n=2;
    //Allocate memory
    int *a=new int[n];
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10;
    }
    //Return and exit with memory allocated array
    return a;
}

//Print a static array
void prnStat(int a[],int n,int perLine){
    cout<<endl;
    cout<<"Static Array"<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

//Fill a static array
//2 Digit Numbers
void filStat(int a[],int n){
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10;
    }
}