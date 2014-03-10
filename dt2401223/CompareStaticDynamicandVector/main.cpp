/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on March 10, 2014, 1:15 PM
 */

//Libraries
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;
//No Global Constants

//Function Prototypes
void filStat(int [],int);//Fill Static Array
void prnStat(int[],int,int);//Print Static Array
int * fillDyn(int);//Fill Dynamic array
void prntDyn(int[],int,int);//Print Dynamic Array
void destroy(int[]);
void fillVec(vector<int> &,int);
void prntVec(vector<int> &,int);

int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));
    //Declare variables
    const int SIZE=100;
    int sArray[SIZE];
    //Fill the static array
    filStat(sArray,SIZE);
    //Print the static array
    prnStat(sArray,SIZE,10);
    //Declare the dynamic array and fill
    int size=SIZE;
    int *dArray=fillDyn(size);
    //Print Dynamic array
    prntDyn(dArray,size,10);
    //Destroy Dynamic array
    destroy(dArray);
    //Declare the Vector
    vector<int> vArray;
    //Fill Vector
    fillVec(vArray,size);
    //Print Vector
    prntVec(vArray,10);
    //End
    return 0;
}

//Print Vector
void prntVec(vector<int> & a,int perline){
    cout<<endl;
    cout<<"This is a Vector array"<<endl;
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
        if(i%perline==(perline-1))cout<<endl;
    }
    cout<<endl;
}

//Fill a dynamic array i.e. vector
//With 2 digit numbers
void fillVec(vector<int> &a,int n){
    for(int i=0;i<n;i++){
        a.push_back(rand()%90+10);
    }
}

void destroy(int a[]){
    delete []a;
    a=0;
}
//Print Dynamic Array
void prntDyn(int a[],int n,int perline){
     cout<<endl;
    cout<<"This is a Dynamic array"<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perline==(perline-1))cout<<endl;
    }
    cout<<endl;
}

int * fillDyn(int n){
    //Declare and allocate the dynamic array
    if(n<2)n=2;
    //Allocate memory
    int *a=new int[n];
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10;
    }
    return a;
}

void filStat(int a[],int n){
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10;
    }
}

void prnStat(int a[],int n,int perline){
    cout<<endl;
    cout<<"This is a Static array"<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perline==(perline-1))cout<<endl;
    }
    cout<<endl;
}