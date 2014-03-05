/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on March 3, 2014, 1:09 PM
 */

#include <iostream>
#include <cstdlib>
using namespace std;

//Global Constants

//Function Prototypes
int *filAray(int);
void prntAray(const int *,int,int);
void sort(const int *,int *,int);
int maxFreq(const int *,int);
int numMode(const int *,int,int);
void destroy(int *);

//Execution Begins Here
int main(int argc, char** argv) {
    //declare variables
    const int SIZE=105;
    int b[SIZE];
    //Fill the array with whole numbers 0-9
    int *a=filAray(SIZE);
    //Make copy and sort the array
    sort(a,b,SIZE);
    //print the array
    prntAray(a,SIZE,10);
    prntAray(b,SIZE,10);
    cout<<endl<<"max frequency is = "<<maxFreq(b,SIZE)<<endl;
    destroy(a);

    return 0;
}

//requires a sorted array for an input
int maxFreq(const int *b,int n){
    //declare counters
    int count=1,max=1;
    //loop and compare
    for(int i=0;i<n;i++){
        if(*(b+i)==*(b+(i+1))){
            count++;
        if(count>max)max=count;
        }
        else
            count=1;
    }
    return max;
}

//repetitive count with one digit only
int *filAray(int n){
    //allocate memory then fill the array
    int *a=new int [n];
    for(int i=0;i<n;i++){
        *(a+i)=i%10;
    }
    return a;
}

void prntAray(const int *a,int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%10==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void sort(const int *a,int *b,int n){
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
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

void destroy(int *a){
    delete[]a;
}

