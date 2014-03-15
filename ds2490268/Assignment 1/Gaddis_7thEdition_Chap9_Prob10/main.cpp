/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on March 14, 2014, 11:19 PM
 * Gaddis, 7th Edition - Chapter 9, Program 10
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants

//Function Prototypes
void filAray(int [],int);
int *revAray(int [],int);
void prtAray(int [], int, int);
void rmAray(int *);

//Execution begins here
int main(int argc, char** argv) {
    //Define local variables & constants
    const int SIZE = 100;
    int array[SIZE],*brray;
    filAray(array,SIZE);
    cout << "Source array:" << endl;
    prtAray(array, SIZE, 10);
    brray = revAray(array, SIZE);
    cout << "Reversed array:" << endl;
    prtAray(brray, SIZE, 10);
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

int *revAray(int arr[],int sz) {
    //Check to see if size of array is valid - if not, create it at a set
    //minimum size.
    if (sz<2)
        sz=2;
    //Grab memory from system pool & use for array storage.
    int *rra = new int[sz];
    //Copy values from source array into destination array in reverse order.
    for (int i=0; i<sz; i++)
        *(rra+(sz-i-1)) = arr[i];
    //Return pointer to allocated memory.
    return rra;
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
