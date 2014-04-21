/* 
 * File:   main.cpp
 * Author: Scott Nevin
 * Purpose: 
 * Created on March 10, 2014
 */

//Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

//Global constants and variables - NONE

//Function prototypes
void filStat(int [], int);//fill static array
void prntStat(int [], int, int);//print static array
int * filDyn(int);//fill dynamic
void prntDyn(int [], int, int);
void destroy(int []);//delete memory
void filVect(vector<int> &, int);
void prntVect(vector<int> &, int);

//Begin execution here
int main(int argc, char** argv) {
    
    //set random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int SIZE=100;
    int sArray[SIZE];
    
        //fill the static array
        filStat(sArray, SIZE);

        //print the static array
        prntStat(sArray, SIZE, 10);

            //Declare dynamic array and fill
            int size = SIZE;
            int *dArray = filDyn(size);

            //print dynamic
            prntDyn(dArray, size, 10);

            //Destroy memory
            destroy(dArray);

                //Declare and fill vector
                vector<int> vArray;

                //Fill the Vector 
                filVect(vArray, size);

                //Print the vector
                prntVect(vArray, 10);
    
    //Exit stage right
    return 0;
}

//Fill vector with 2 digit numbers
void filVect(vector<int> &a, int n){
    
    for(int i=0;i<n;i++){
        a.push_back(rand()%90+10);
    }
    
}

void prntVect(vector<int> &a, int perLine){
    
    cout<<"Vector Array"<<endl;
    cout<<endl;
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    } 
    cout<<endl;
    
}

void destroy(int a[]){
    
    delete []a;
    a=0;
}

int * filDyn(int n){
    //declare and allocate array
    if(n<=2)n=2;
    int *a=new int[n];
    
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10;
    } 
    //return allocated array
    return a;
}

void prntDyn(int a[], int n, int perLine){
    cout<<"Dynamic Array"<<endl;
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    } 
    cout<<endl;
}

//Fill array with 2 digit numbers
void filStat(int a[], int n){
    
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10;
    }  
}

void prntStat(int a[], int n, int perLine){
    cout<<"Static Array"<<endl;
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    } 
    cout<<endl;
}