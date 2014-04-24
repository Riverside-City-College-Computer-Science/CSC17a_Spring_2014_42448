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
int * filAray(int);
void prntAry(int *, int, int);
void sort(const int *,int [],int);
int maxFreq(int *,int);
void numModes(int [], int, int);
void destroy(int *);
//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    srand(static_cast<unsigned int>(time(0)));
    const int SIZE=100;
    int *array=filAray(SIZE);
    int brray[SIZE];
    int max;
    //print array
    prntAry(array,SIZE,10); 
    //sort
    sort(array,brray,SIZE);
    //print
    prntAry(brray,SIZE,10);
    //frequency
    max=maxFreq(brray,SIZE);
    cout<<"\nThe max frequency is "<<max<<endl;
    numModes(brray,SIZE,max);    
    
    destroy(array);   
    return 0;
}
void destroy(int *a){
    delete [] a;
}
void numModes(int a[], int n, int m){
    int count=1;
    cout<<"Number(s): ";
    for(int i=1;i<n;i++){
         if(a[i-1]==a[i]){
             count++;
             if(count==m) cout<<a[i]<<" ";
         }else{
                 count=1;
         }   
       }
    cout<<endl;
}

//requires sorted array (binary search)
int maxFreq(int *a,int n){
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
void sort(const int *a,int b[], int n){
    //make copy
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    //sort copied array
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
void prntAry(int *a ,int n, int perLine){
    cout<<endl;
    for(int i=0; i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==perLine-1)cout<<endl;
    }
    cout<<endl;
}
//repetitive count w/ 1 digit elements
int * filAray(int n){
    //Declare and allocate the dynamic array
    if(n<1)n=1;
    //Allocate memory
    int *a=new int[n];
    //Fill with data
    for(int i=0;i<n;i++){
        a[i]=rand()%10;
    }
    //Return and exit with memory allocated array
    return a;
}
