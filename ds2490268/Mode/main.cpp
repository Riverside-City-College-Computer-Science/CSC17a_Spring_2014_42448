/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on March 3, 2014, 1:07 PM
 * Sample of Mode
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

//Global Constants

//Function Prototypes
void fillAry(int [],int);
void prntAry(int [],int,int);
void sort(int [],int [],int);
int maxFreq(int [],int);
int nuModes(int [],int,int);

//Execution begins here
int main(int argc, char** argv) {
    //Define local variables
    const int SIZE=105;
    int array[SIZE],brray[SIZE];
    //Create & populate an array
    fillAry(array,SIZE);
    //Print array contents
    prntAry(array,SIZE,10);
    //Sort array
    sort(array,brray,SIZE);
    //Print sorted array
    prntAry(brray,SIZE,10);
    //find max frequency
    cout << "Max frequency: " << maxFreq(brray,SIZE) << endl;
    //Exit, stage right
    return 0;
}

//Req. sorted array for input
int maxFreq(int a[],int n) {
    //Declare local variable
    int kount=1,max=1;
    //loop and comapre
    for (int i=0; i<n;i++) {
        if (a[i-1]==a[i]) {
            kount++;
            if (kount>max)
                max=kount;
            else
                kount=1;
        }
    }
    return max;
}

void sort(int a[],int b[],int n) {
    for (int i=0; i<n; i++) {
        b[i]=a[i];
    }
    //Sort the copied array
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (b[i]>b[j]) {
                int temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }
}

void prntAry(int a[],int n,int perLine) {
    cout << endl;
    for (int i=0; i<n; i++) {
        cout << a[i] << " ";
        if (i%perLine == (perLine-1))
            cout << endl;
    }
    cout << endl;
}

//Repetitive count with 1-digit elements
void fillAry(int a[],int n) {
    for (int i=0; i<n; i++) {
        a[i]=i%10;
    } 
}
