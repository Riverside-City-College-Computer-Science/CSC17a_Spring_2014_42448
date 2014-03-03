/* 
 * File:   main.cpp
 * Author: Luis Pow Sang
 * Created on March 3, 2014, 1:09 PM
 */

//Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

//Global constants

//Function Prototypes
int *fillArray(int);
void prntArray(int *, int, int);
void sort(int *, int [],int);
int maxFreq(int *, int);
int nuModes(int *, int, int);
void destroy(int *);

//Execution begins here
int main(int argc, char** argv) {
    //Declare Variables
    const int SIZE=105;
    int brray[SIZE];
    //Fill the array with 0-9
    int *array=fillArray(SIZE);
    //Print array
    prntArray(array,SIZE,10);
    //Sort a copied array
    sort(array,brray, SIZE);
    //Print the sorted array
    cout<<endl;
    prntArray(brray,SIZE,10);
    //What is the max freq
    cout<<endl<<"The max freq of the array = "<<maxFreq(brray,SIZE)<<endl;
    //Exit Stage Right
    destroy(array);
    return 0;
}

void destroy(int *a){
    delete[] a;
}

//Requires sorted array for an input
int maxFreq(int *a, int n){
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

void sort(int *a, int b[],int n){
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

void prntArray(int *a, int n, int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
}

//Repetitive count with 1 digit elements
int *fillArray(int n){
    //Allocate memory
    int *a=new int[n];
    //Fill the array
    for(int i=0;i<n;i++){
        a[i]=i%10;
    }
    return a;
    
    
}
