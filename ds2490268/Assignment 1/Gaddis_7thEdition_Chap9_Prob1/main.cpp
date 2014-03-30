/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on March 14, 2014, 5:38 PM
 * Gaddis, 7th Edition - Chapter 9, Problem 1
 */

//System Libraries
#include <iostream>
using namespace std;

//Global variables
const float PI = 3.14159e0;  //In honor of National Pi day - not used in code.

//Function prototypes
int *mkArray(int);
void rmArray(int *);

//Execution begins here
int main(int argc, char** argv) {
    //Define local variables & constants
    const int SIZE = 100;
    int *dArray;
    
    //Create dynamic array
    cout << "Allocating dynamic array - size = " << SIZE << "." << endl;
    dArray = mkArray(SIZE);
    //Return array to system pool
    cout << "Deallocating array." << endl;
    rmArray(dArray);
    //Exit, stage right!
    return 0;
}

int *mkArray(int sz) {
    //Check to see if size of array is valid - if not, create it at a set
    //minimum size.
    if (sz<2)
        sz=2;
    //Grab memory from system pool & use for array storage.
    int *arr = new int[sz];
    //Return pointer to allocated memory.
    return arr; 
}

void rmArray(int *arr) {
    //Return allocated memory to system pool (prevents memory leaks).
    delete []arr;
    //Null out pointer to allocated memory (safety measure)
    arr=0;
}

