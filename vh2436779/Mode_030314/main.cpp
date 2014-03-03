/* 
 * File:   main.cpp
 * Author: Victoria Hodnett
 * Created on March 3, 2014, 1:09 PM
 * Mode
 */

//System Libaries
#include <iostream>
using namespace std;

//Global Constants

//Function Prototypes
void fillAry(int[],int);
void prntAry(int[],int,int);
void sort(const int[],int[],int);
int maxFreq(int[],int);
int nModes(int[],int);

//Execution
int main(int argc, char** argv) {
    //Declare variables
    const int SIZE=105;
    int array[SIZE],brray[SIZE];
    //Fill the array with 0-9
    fillAry(array,SIZE);
    //Print the array
    prntAry(array,SIZE,10);
    //Sort array
    sort(array,brray,SIZE);
    //Print sorted array
    prntAry(brray,SIZE,10);
    //What is the max frequency?
    cout << endl;
    cout << "The max frequency in the array: " 
            << maxFreq(brray,SIZE) << endl;
    //What is the number of modes?
    cout << endl;
    cout << "The number of modes in the array: " 
            << nModes(brray,SIZE) << endl;
    //Exit
    return 0;
}

//Repetitive count with 1 digit elements
void fillAry(int a[],int size){
    for(int i=0;i<size;i++){
        a[i]=i%10;
    }
}

void prntAry(int a[],int size,int perLine){
    cout<<endl;
    for(int i=0;i<size;i++){
        cout << a[i] << " ";
        if (i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void sort(const int a[],int b[],int size){
    //Make a copy
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
}

//Requires sorted array for an input
int maxFreq(int a[],int size){
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

int nModes(int a[],int size){
    int freq = maxFreq(a,size);
    int modes=0,count=1;
    
    for(int i=1;i<size;i++){
        if(a[i-1]==a[i]){
            count++;
            if(count>max)max=count;
        }else{
            if(count==maxFreq(a,size))modes++;
            count = 1;
        }
    }
    return modes;
}