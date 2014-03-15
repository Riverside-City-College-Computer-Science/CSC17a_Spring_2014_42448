/* 
 * File:   main.cpp
 * Author: David
 * Created on March 14, 2014, 11:52 PM
 * Gaddis, 7th Edition - Chapter 9, Problem 11
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants

//Function Prototypes
void filAray(int [],int);
int *dblAray(int [],int);
void prtAray(int [], int, int);
void rmAray(int *);

//Execution begins here
int main(int argc, char** argv) {
    //Define local variables & constants
    const int SIZE = 100;
    int array[SIZE],*brray;
    //Fill source array with ascending integers & display it
    filAray(array,SIZE);
    cout << "Source array:" << endl;
    prtAray(array, SIZE, 10);
    //Create destination array twice the source array's size,
    //copy integers from source array with every other number
    //being 0, and display that as well 
    brray = dblAray(array, SIZE);
    cout << "Doubled array:" << endl;
    prtAray(brray, SIZE*2, 10);
    //Return dynamic array to system memory pool
    rmAray(brray);
    //Exit, stage right!
    return 0;
}

void rmAray(int *arr) {
    //Return allocated memory to system pool (prevents memory leaks).
    delete []arr;
    //Null out pointer to allocated memory (safety measure)
    arr=0;
}

int *dblAray(int arr[],int sz) {
    int size = sz*2;
    //Check to see if size of array is valid - if not, create it at a set
    //minimum size.
    if (size<2)
        size=2;
    //Grab memory from system pool & use for array storage.
    int *drr = new int[size];
    //Copy values from source array into destination array in reverse order.
    for (int i=0; i<sz; i++) {
        *(drr+(i*2))=arr[i];
        *(drr+((i*2)+1))=0;
    }
    //Return pointer to allocated memory.
    return drr;
}

void prtAray(int arr[], int sz, int brkOn) {
    for (int i=0; i<sz; i++) {
        cout << setw(3) << arr[i];
        if ((i%brkOn)==(brkOn-1))
            cout << endl;
    }
    cout << endl;
}

void filAray(int arr[],int sz) {
    for (int i=0; i<sz; i++)
        arr[i] = i;
}


