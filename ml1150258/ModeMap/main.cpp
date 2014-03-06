/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on March 5, 2014
 */

//System Libraries
#include <iostream>
#include <map>
using namespace std;

//Global Constants

//Function Prototypes
void fillAry(int [],int);
void prntAry(int [],int,int);
int maxFreq(int [],int,map<int,int>&);
int nuModes(map<int,int>&);

int main(int argc, char** argv) {
    //Declare some variables
    const int SIZE=105;
    int array[SIZE];
    map<int,int> freq;
    //Fill the array with 0-9
    fillAry(array,SIZE);
    //Print the array
    prntAry(array,SIZE,10);
    //What is the max frequency
    cout<<"The max freq in the array = "<<maxFreq(array,SIZE,freq)<<endl;
    //Exit stage right!
    return 0;
}

//No Sorting Required
//Which means no array copy as well
int maxFreq(int a[],int n,map<int,int>&m){
    //Declare max
    int max=0;
    //Loop and compare
    for(int i=0;i<n;i++){
        if(max<m[a[i]]++)max=m[a[i]];
    }
    return max+1;
}

void prntAry(int a[],int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

//Repetitive Count with 1 digit elements 
void fillAry(int a[],int n){
    for(int i=0;i<n;i++){
        a[i]=i%10;
    }
}

