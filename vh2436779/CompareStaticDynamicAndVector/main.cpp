/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on March 10, 2014, 1:16 PM
 */

//System Libraries
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

//Global Constants

//Function Prototypes
void filStat(int[],int);//Fill Static array
void prnStat(int[],int,int);//Print Static array
int *filDyn(int);//Fill Dynamic array
void prntDyn(int*,int,int);//Print Dynamic array
void destroy(int*);
void filVect(vector<int>&,int);
void prntVec(vector<int>&,int);

//Execution
int main(int argc, char** argv) {
    //Declare variables
    srand(static_cast<unsigned int>(time(0)));
    //Static variables
        const int SIZE=100;
        int sArray[SIZE];
        //Fill static array
        filStat(sArray,SIZE);
        //Print static array
        prnStat(sArray,SIZE,10);
    
    //Declare dynamic array and fill
        int size=SIZE;
        int *dArray=filDyn(size);
        //Print dynamic array
        prntDyn(dArray,size,10);
        //De-allocate memory
        destroy(dArray);
    
    //Declare vector variables
        vector<int> vArray;
        //Fill vector
        filVect(vArray,size);
        //Print vector
        prntVec(vArray,10);
        //Exit
        return 0;
}

//Fill static array
//2 Digit numbers
void filStat(int a[],int n){
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10;
    }
}

//Fill dynamic array
//2 Digit numbers
int *filDyn(int n){
    //Declare and allocate the dynamic array
    if(n<2)n=2;
    //Allocate memory
    int *a = new int[n];
    //Fill with data
    for(int i=0;i<n;i++){
        *(a+i)=rand()%90+10;
    }
    //Return and exit with memory allocated array
    return a;
}

//Fill vector
//2 digit numbers
void filVect(vector<int>&a,int n){
    for(int i=0;i<n;i++){
        a.push_back(rand()%90+10);
    }
}

//Print static array
void prnStat(int a[],int n,int perLine){
    cout << endl;
    cout << "This is a static array " << endl;
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
        if(i%perLine==(perLine-1)) cout << endl;
    }
    cout << endl;
}

//Print dynamic array
void prntDyn(int *a,int n,int perLine){
    cout << endl;
    cout << "This is a dynamic array " << endl;
    for(int i=0;i<n;i++){
        cout << *(a+i) << " ";
        if(i%perLine==(perLine-1)) cout << endl;
    }
    cout << endl;
}

//Print vector
void prntVec(vector<int>&a,int perLine){
    cout << endl;
    cout << "This is a vector " << endl;
    for(int i=0;i<a.size();i++){
        cout << a[i] << " ";
        if(i%perLine==(perLine-1)) cout << endl;
    }
    cout << endl;
}

//De-allocate memory
void destroy(int *a){
    delete [] a;
    a=0;
}