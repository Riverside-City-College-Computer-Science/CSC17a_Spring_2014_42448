/* 
 * File:   main.cpp
 * Author: David Ballantyne
 * Created on March 3, 2014, 1:09 PM
 * purpose: Mode Array
 */
//Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

//Global Constants

//function prototypes
void filAray(int [], int);
void prntAry(int [], int, int);
void sort(const int [],int [],int);
int maxFreq(int [],int);
void numModes(int [], int, int);
//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    const int SIZE=105;
    int array[SIZE],brray[SIZE],max;
    //fill array
    filAray(array,SIZE);
    //print array
    prntAry(array,SIZE,10);
    //sort
    sort(array,brray,SIZE);
    //print
    prntAry(brray,SIZE,10);
    //exit stage right
    max=maxFreq(brray,SIZE);
    cout<<"The max frequency is "<<max<<endl;
    numModes(brray,SIZE,max);
    return 0;
}
void numModes(int a[], int n, int m){
    int count=1;
    for(int i=1;i<n;i++){
         if(a[i-1]==a[i]){
             count++;
             if(count==m) cout<<a[i]<<endl;
         }else{
                 count=1;
         }   
       }
}

//requires sorted array (binary search)
int maxFreq(int a[],int n){
    //declare counters
    int count=1, max=1;
    //loop compare
     for(int i=1; i<n;i++){
         if(a[i-1]==a[i]){
             count++;
             if(count>max)max=count;
         }else{
             count=1;
         }
     }
    return max;
}
void sort(const int a[],int b[],int n){
    //make copy
    for(int i=0; i<n;i++){
        b[i]=a[i];
    }
    //sort copied array
    for(int i=0; i<n-1;i++){
        for(int j=i+1; j<n;j++){
            if (b[i]>b[j]){
                int temp=b[i];
                b[i]=b[j];
                b[j]=temp;
                }
         }
    }
}
void prntAry(int a[], int n, int perLine){
    cout<<endl;
    for(int i=0; i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==perLine-1)cout<<endl;
    }
    cout<<endl;
}
//repetitive count w/ 1 digit elements
void filAray(int a[], int n){
    for(int i=0; i<n;i++){
        a[i]=i%10;

    }
}
