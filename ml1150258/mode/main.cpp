/*
* File: main.cpp
* Author: Dr. Mark E. Lehr
* Created on March 3, 2014, 1:09 PM
*/

//System Libraries
#include <iostream>
using namespace std;

//Global Constants

//Function Prototypes
int * fillAry(int);
void prntAry(int *,int,int);
void sort(int *,int [],int);
int maxFreq(int *,int);
int nuModes(int *,int,int);
int *modes(int *,int,int,int);

void destroy(int *);

int main(int argc, char** argv) {
    //Declare some variables
    const int SIZE=16;
    int brray[SIZE];
    //Fill the array with 0-9
    int *array=fillAry(SIZE);
    //Print the array
    prntAry(array,SIZE,10);
    //Sort a copied array
    sort(array,brray,SIZE);
    //Print the sorted array
    prntAry(brray,SIZE,10);
    //What is the max frequency and number of modes
    int mxFreq=maxFreq(brray,SIZE);
    int nModes=nuModes(brray,SIZE,mxFreq);
    cout<<"The max freq in the array = "<<mxFreq<<endl;
    cout<<"The number of modes in the array = "<<nModes<<endl;
    //Find the modes and print
    int *mode=modes(brray,SIZE,mxFreq,nModes);
    //Print the mode array
    prntAry(mode,nModes,10);
    //Exit stage right!
    destroy(array);
    destroy(mode);
    return 0;
}
int *modes(int *a,int n,int mFreq,int nModes){
    //Declare variables
    int count=1,indx=0;
    int *mArray=new int(nModes);
    //Loop and compare
    for(int i=1;i<n;i++){
        if(a[i-1]==a[i]){
            count++;
            if(count==mFreq)mArray[indx++]=a[i];
        }else{
            count=1;
        }
    }
    return mArray;
}

int nuModes(int *a ,int n ,int mFreq){
    //Declare counters
    int count=1,nModes=0;
    //Loop and compare
    for(int i=1;i<n;i++){
        if(a[i-1]==a[i]){
            count++;
            if(count==mFreq)nModes++;
        }else{
            count=1;
        }
    }
    return nModes;
}

void destroy(int *a){
    delete [] a;
}

//Requires sorted array for an input
int maxFreq(int *a,int n){
    //Declare counters
    int count=1,max=1;
    //Loop and compare
    for(int i=1;i<n;i++){
        if(a[i-1]==a[i]){
            count++;
            if(count>max)max=count;
        }else{
            count=1;
        }
    }
    return max;
}

void sort(int *a,int b[],int n){
    //Make a copy
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    //Sort the copied array
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(b[i]>b[j]){
                int temp=b[i];
                b[i]=b[j];
                b[j]=temp;
            }
        }
    }
}

void prntAry(int *a,int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

//Repetitive Count with 1 digit elements
int *fillAry(int n){
    //Allocate Memory
    int *a=new int[n];
    //Fill the array
    for(int i=0;i<n;i++){
        a[i]=i%10;
    }
    return a;
}