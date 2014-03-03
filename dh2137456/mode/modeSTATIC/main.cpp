/* 
 * File:   main.cpp
 * Author: David Haro
 * Mode Problem
 * Created on March 3, 2014, 1:09 PM
 */
//Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

//Global Constants: NA

//Function Prototypes
void fillAry(int [],int);
void prntAry(int [],int,int);
void sort(int [],int [],int);
int maxFreq(int [],int);
int nuModes(int [], int,int);

//Execute
int main(int argc, char** argv) {
    //declare
    const int SIZE=105;
    int array[SIZE], brray[SIZE];
    //Fill the array with digits 0-9
    fillAry(array, SIZE);
    //Print the Array
    prntAry(array, SIZE, 10);
    //Sort copied array
    sort(array, brray, SIZE);
    //Print copied array
    prntAry(brray, SIZE, 10);
    //count the numbers
    cout<<"The max freq in the array = "<<maxFreq(brray, SIZE);
    //Exit
    return 0;
}

//Print Array
void prntAry(int a[],int n, int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
}
//Repetitive 
void fillAry(int a[],int n){
        for(int i=0;i<n;i++){
        a[i]=i%10;
    }
}
//sort array
void sort(int a[],int b[],int n){
    cout<<endl;
    //Make a copy
        for(int i=0;i<n;i++){
            b[i]=a[i];
        }
    //Sort copied array
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(b[i]>b[j]){
                    int temp=b[i];
                    b[i]=b[j];
                    b[j]=temp;
                }
            }
        }
}
//requires sorted array for input
int maxFreq(int a[],int n){
    //declare counters
    int count=1,
        max=1;
    //loop an compare
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
//count number of modes
int nuModes(int [], int,int){
    
}