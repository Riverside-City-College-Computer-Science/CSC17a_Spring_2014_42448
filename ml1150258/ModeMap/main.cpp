/*
* File: main.cpp
* Author: Dr. Mark E. Lehr
* Created on March 5, 2014
*/

//System Libraries
#include <iostream>
#include <map>
#include <set>
using namespace std;

//Global Constants

//Function Prototypes
void fillAry(int [], int);
void prntAry(int [], int, int);
int maxFreq(int [], int, map<int,int> &);
int nmModes(int, map<int,int> &, set<int> &);
void prntMds(int,int,set<int> &);
void fndMods(int [],int,int &,int &,set<int> &);

int main(int argc, char** argv) {
    //Declare some variables
    const int SIZE=106;
    int array[SIZE];
    set<int> modes;
    int mxFreq,nModes;
    //Fill the array with 0-9
    fillAry(array,SIZE);
    //Print the array
    prntAry(array,SIZE,10);
    //Find the modes
    fndMods(array,SIZE,mxFreq,nModes,modes);
    //Print the Mode Set
    prntMds(mxFreq,nModes,modes);
    //Exit stage right!
    return 0;
}

void fndMods(int a[],int n,int &mFreq,int &nModes,set<int> &modes){
    //Declare the map
    map<int,int> freq;
    //What is the max frequency
    mFreq=maxFreq(a,n,freq);
    //How many modes?
    if(mFreq>1)nModes=nmModes(mFreq,freq,modes);
    else nModes=0;
}

void prntMds(int mxFreq,int nModes,set<int> &s){
    //Print the max frequency
    cout<<"The max frequency in the array = "<<mxFreq<<endl;
    //Print the number of modes
    cout<<"The number of modes = "<<nModes<<endl;
    //Start a counter for a proper
    if(nModes>0){
        typedef set<int>::iterator its;
        cout<<"The mode set = {";
        for(its iterator = s.begin(); iterator != s.end(); iterator++) {
                if(nModes-->1)cout<<*iterator<<",";
                else cout<<*iterator;
        }
        cout<<"}"<<endl;
    }
}

//Count the modes by utilize the map and max frequency
int nmModes(int max, map<int,int> &m, set<int> &s){
    //Set counter for the modes
    max;//frequency in map is 1 less
    int nModes=0;
    //For each element in the map, see if it matches the max frequency
    typedef map<int,int>::iterator itm;
    for(itm iterator = m.begin(); iterator != m.end(); iterator++) {
        if(iterator->second==max){
            s.insert(iterator->first);
            nModes++;
        }
    }
    return nModes;
}

//No Sorting Required
//Which means no array copy as well
int maxFreq(int a[],int n,map<int,int>&m){
    //Declare max
    int max=0;
    //Loop and compare
    for(int i=0;i<n;i++){
        if(++m[a[i]]>max)max=m[a[i]];
    }
    return max;
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