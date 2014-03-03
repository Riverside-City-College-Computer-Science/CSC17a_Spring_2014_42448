/* 
 * File:   main.cpp
 * Author: Abel Salazar
 * Created on March 3, 2014, 1:11 PM
 */

//system libraries
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//global const

//function prototype
void fillAry(int [], int);
void prntAry(int [],int,int);
void sort(int[],int [], int);
int maxFreq(int [], int);
int numMod(int [],int,int);

//execution begins here
int main(int argc, char** argv) {
    //variable declaration
    const int SIZE=105;
    int array[SIZE], brray[SIZE];
    //fill array with 0-9 
    fillAry(array, SIZE);
    //print array
    prntAry(array, SIZE, 10);
    //sort brray
    sort(array,brray,SIZE);
    //print brray
    prntAry(brray,SIZE,10);
    //find max frequency
    cout <<"The max frequency in the array = "<< maxFreq(brray,SIZE) <<endl;
    //exit stage right
    return 0;
}

int maxFreq(int a[], int n){
    //declare counters
    int count=1;max=1;
    //loop and compare
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

void sort(int a[],int b[], int n){
    //make a copy
    for(int i=0; i<n;i++){
        b[i]=a[i];
    }
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(b[i]>b[j]){
                int temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }
}

void prntAry(int a[],int n,int perLine){
    cout<<endl;
    for(int i=0; i<n;i++){
        cout << a[i] << " ";
        if(i%perLine==(perLine-1))cout <<endl;
    }
    cout<<endl;
}

//repetitive count with 1 digit elements
void fillAry(int a[], int n){
    for(int i=0; i<n;i++){
        a[i]=i%10;
    }
}
