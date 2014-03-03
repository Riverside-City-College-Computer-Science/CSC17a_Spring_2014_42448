/* 
 * File:   main.cpp
 * Author: Joe Reimbold
 *
 * Created on March 3, 2014, 1:11 PM
 */

//Libraries
#include <cstdlib>
#include <iostream>
using namespace std;

//Global Constants

//Function Prototypes
void fillAry(int [],int);
void prntAry(int [],int,int);
void sort(int [],int [],int);
int maxFreq(int [],int);
int nuModes(int [],int,int);

//Begin Main
int main(int argc, char** argv) {
    //Declare variables
    const int SIZE=105;
    int array[SIZE],brray[SIZE];
    
    //Fill the array with 0-9
    fillAry(array,SIZE);
    
    //Print array
    prntAry(array,SIZE,10);
    
    //Sort a copied array
    sort(array,brray,SIZE);
    
    //Print the sorted array
    prntAry(brray,SIZE,10);
    
    //What is the max frequency?
    cout<<"The max freq in the array = "<<maxFreq(brray,SIZE)<<endl;
    
    //Exit Stage Right
    return 0;
}

//
int nuModes(int [],int,int){
    
}

//Requires sorted array for an input
int maxFreq(int a[],int n){
    //Declare Counters
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
    //make a copy of array
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    
    //sort the copied array
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

void prntAry(int a[],int n, int perLine){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl<<endl;
}

//Repetitive Count with 1 digit elements
void fillAry(int a[],int n){
    for(int i=0;i<n;i++){
        a[i]=i%10;
    }
}