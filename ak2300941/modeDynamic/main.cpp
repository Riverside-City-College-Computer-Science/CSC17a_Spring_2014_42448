/* 
 * File:   main.cpp
 * Author: Andrew Kim
 * Created on March 3, 2014, 1:09 PM
 * Mode with Dynamic Array
 */

//System Libraries
#include <iostream>
#include <cstdlib>
using namespace std;

//Global Constants

//Function Prototypes
int *filAray(int);
void prntAray(int *,int,int);
void sort(int *,int *,int);
int maxFreq(int *,int);
int nuModes(int *,int,int);
void destroy(int *);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    const int SIZE=105;
    int brray[SIZE];
    int maxF;
    //Fill the array with 0-9
    int *array=filAray(SIZE);
    //Print the array
    prntAray(array,SIZE,10);
    //Copy and Sort the copied array
    sort(array,brray,SIZE);
    //Print the array
    prntAray(brray,SIZE,10);
    //What is the max frequency
    maxF=maxFreq(brray,SIZE);
    cout<<"The max frequency in the array = "<<maxF<<endl;
    destroy(array);
    //Exit Stage Right
    return 0;
}

void destroy(int *a){
    delete [] a;
}

//Requires sorted array for an input
int maxFreq(int *b,int n){
    //Declare counters
    int count=1,max=1;
    //Loop and compare
    for(int i=1;i<n;i++){
        if(b[i-1]==b[i]){
            count++;
            if(count>max)max=count;
        }else{
            count=1;
        }
    }
    return max;
}

void sort(int *a,int *b,int n){
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

void prntAray(int *a,int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

//Repetitive Count with 1 digit elements
int *filAray(int n){
    //Allocate memory
    int *a=new int[n];
    //Fill array
    for(int i=0;i<n;i++){
        *(a+i)=i%10;
    }
    return a;
}