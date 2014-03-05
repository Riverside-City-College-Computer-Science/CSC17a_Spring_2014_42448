/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on March 3, 2014, 1:44 PM
 * Mode dynamic
 */

//System Libaries
#include <iostream>
using namespace std;

//Global Constants

//Function Prototypes
int *fillAry(int);
void prntAry(int*,int,int);
int *sort(const int*,int);
int maxFreq(int*,int);
int nModes(int*,int);
void destroy(int*);

//Execution
int main(int argc, char** argv) {
    //Declare variables
    const int SIZE=105;
    //Fill the array with 0-9
    int *array = fillAry(SIZE);
    //Print the array
    prntAry(array,SIZE,10);
    //Sort array
    int *brray = sort(array,SIZE);
    //Print sorted array
    prntAry(brray,SIZE,10);
    //What is the max frequency?
    cout << endl;
    cout << "The max frequency in the array: " 
            << maxFreq(brray,SIZE) << endl;
    //Exit
    destroy(array);
    destroy(brray);
    return 0;
}

//Repetitive count with 1 digit elements
int *fillAry(int size){
    int *a = new int[size];
    for(int i=0;i<size;i++){
        a[i]=i%10;
    }
    return a;
}

void prntAry(int *a,int size,int perLine){
    cout<<endl;
    for(int i=0;i<size;i++){
        cout << a[i] << " ";
        if (i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

int *sort(const int *a,int size){
    //Make a copy
    int *b = new int[size];
    for(int i=0;i<size;i++){
        b[i]=a[i];
    }
    //Sort the copied array
    for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            if(b[i]>b[j]){
                int temp = b[i];
                b[i]=b[j];
                b[j]=temp;
            }
        }
    }
    return b;
}

//Requires sorted array for an input
int maxFreq(int *a,int size){
    //Declare counters
    int count=1,max=1;
    //Loop and compare
    for(int i=1;i<size;i++){
        if(a[i-1]==a[i]){
            count++;
            if(count>max)max=count;
        }else{
            count = 1;
        }
    }
    return max;
}

int nModes(int *a,int size){
    int freq = maxFreq(a,size);
    int modes = 0;
}

void destroy(int *a){
    delete [] a;
}