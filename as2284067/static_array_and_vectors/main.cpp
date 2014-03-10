/* 
 * File:   main.cpp
 * Author: Abel Salazar
 * Created on March 10, 2014, 1:16 PM
 */


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

//global constants

//function prototypes
void fillStat(int [],int);      //fill a static array
void prntStat(int [],int,int);  //print a static array
int *fillDyn(int);              //fill a dynamic array
void prntDyn(int [],int,int);   //print a dynamic array
void fillVec(vector<int> &, int);
void prntVec(vector<int> &,int);
void destroy(int []);

//execution
int main(int argc, char** argv) {
    //seed time
    srand(static_cast<unsigned int>(time(0)));
    //declare variables
    const int SIZE=100;
    int sArray[SIZE];
    
    fillStat(sArray, SIZE);     //fill static array
    prntStat(sArray,SIZE,10);   //print static array
    
    //declare pointer
    int size=SIZE;
    int *dArray=fillDyn(size);  //fill dynamic array
    prntDyn(dArray,size,10);    //print dynamic array
    destroy(dArray);            //destroy memory
    
    //declare vector
    vector<int> vArray;
    fillVec(vArray,size);       //fill vector
    prntVec(vArray,10);         //print vector
    
    //exit stage right
    return 0;
}

//destroys allocated memory
void destroy(int a[]){
    delete []a ;
    a=0;
}

//print a vector array
void prntVec(vector<int> &a,int perLine){
    cout << "This is a vector"<<endl;
    for(int i=0;i<a.size();i++){
        cout << a[i]<<" ";
        if(i%perLine == (perLine-1))cout<<endl;
    }
    cout<<endl;
}

//print a static array
void prntDyn(int a[],int n,int perLine){
    cout << "This is a dynamic array"<<endl;
    for(int i=0;i<n;i++){
        cout << a[i]<<" ";
        if(i%perLine == (perLine-1))cout<<endl;
    }
    cout<<endl;
}

//print a static array
void prntStat(int a[],int n, int perLine){
    cout << "This is a static array"<<endl;
    for(int i=0;i<n;i++){
        cout << a[i]<<" ";
        if(i%perLine == (perLine-1))cout<<endl;
    }
    cout<<endl;
}

//fill vector with 2 digit numbers
void fillVec(vector<int> &a, int n){
    for(int i=0;i<n;i++){
        a.push_back(rand()%90+10);
    }
}

//fill dynamic array with 2 digit numbers
int *fillDyn(int n){
    //declare and allocate dynamic array
    if(n<2)n=2;
    //allocate memory
    int *a = new int [n];
    //fill with data
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10;
    }
    //return and exit with memory
    return a;
} 

//2 digit numbers
void fillStat(int a[],int n){
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10;
    }
}
