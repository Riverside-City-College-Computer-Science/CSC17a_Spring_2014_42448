/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on March 3, 2014, 1:09 PM
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants

//Function Prototypes
void fillAry(int [],int);
void prntAry(int [],int,int);
void sort(int [],int [],int);
int maxFreq(int [],int);
int nuModes(int [],int,int);

int main(int argc, char** argv) {
    //Declare some variables
    const int SIZE=105;
    int array[SIZE],brray[SIZE];
    //Fill the array with 0-9
    fillAry(array,SIZE);
    //Print the array
    prntAry(array,SIZE,10);
    //Sort a copied array
    sort(array,brray,SIZE);
    //Print the sorted array
    prntAry(brray,SIZE,10);
    //What is the max frequency
    cout<<"The max freq in the array = "<<maxFreq(brray,SIZE)<<endl;
    //Exit stage right!
    return 0;
}

//Requires sorted array for an input
int maxFreq(int a[],int n){
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

void sort(int a[],int b[],int n){
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

