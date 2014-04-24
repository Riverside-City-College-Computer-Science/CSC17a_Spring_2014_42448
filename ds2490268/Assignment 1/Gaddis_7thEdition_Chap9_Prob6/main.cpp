/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on March 14, 2014, 10:09 PM
 * Gaddis, 7th Edition - Chapter 9, Problem 6
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants

//Function Prototypes
void arrSelectSort(int *[],int);
void showArray(const int [],int);
void showArrPtr(int *[],int);
int *mkAray(int);
int **mkPtr(int);
void rmAray(int *);
void rmPtr(int **);

//Execution begins here
int main(int argc, char** argv) {
    //Define local variables & constants
    //const int NUM_DONATIONS = 15;  //Number of donations
    
    // An array containing the donation amounts
    //int donations[NUM_DONATIONS] = { 5,  100, 5, 25, 10,
    //                                 5,  25,  5,  5, 100,
    //                                 10, 15, 10,  5, 10 };
    
    //An array of pointers to int
    //int *arrPtr[NUM_DONATIONS];
    
    //Define local variables
    int index, iSize, iDon, **arrPtr, *donations;
    
    //Get size from user
    cout << "Enter number of donations to be entered (less than 2 to end): ";
    cin >> iSize;
    //If valid # of scores, accept scores from user, checking for negatives.
    if (iSize >= 2) {
        donations = mkAray(iSize);
        for (index = 0; index < iSize; index++) {
            cout << "Enter donation (more than 0) : ";
            cin >> iDon;
            if (iDon >= 0) {
                *(donations+index) = iDon;
            } else {
                cout << "Invalid donation - exiting program." << endl;
                break;
            }
        }
        //If all scores were entered, sort scores, calc. average &
        //display results
        if (index == iSize) {
            //Each element of arrptr is a pointer to int. Make each
            //element point to an element in the donations array.
            arrPtr = mkPtr(iSize);
            for (int count = 0; count < iSize; count ++)
                 arrPtr[count] = &donations[count];
            
            //Sort the elements of the array of pointers
            arrSelectSort(arrPtr, iSize);
    
            //Display the donations using the array of pointers. This
            //will display them in sorted order.
            cout << "The donations, sorted in ascending order, are:" << endl;
            showArrPtr(arrPtr, iSize);
    
            //Display the donations in their original order
            cout << "The donations, in their original order, are:" << endl;
            showArray(donations, iSize);
            //Return memory used by the array of pointers back to memory pool
            rmPtr(arrPtr);
        }
        //Even if an invalid donation was entered, we still need to clean up
        //after ourselves - return dynamic array memory to memory pool.
        rmAray(donations);
    }
    //Exit, stage right!
    return 0;
}

//***************************************************************
// Definition of function arrSelectSort.                        *
// This function performs an ascending order selection sort on  *
// arr, whicH is an array of pointers. Each element of arr      *
// points to an element of a second array. After the sort,      *
// arr will point to the elements of the sencond array          *
// in ascending order.                                          *
//***************************************************************

void arrSelectSort(int *arr[], int size) {
    //Define local variables
    int startScan, minIndex;
    int *minElem;
    
    for (startScan = 0; startScan < (size-1); startScan++) {
        minIndex = startScan;
        minElem = arr[startScan];
        for (int index = startScan + 1; index < size; index ++) {
            if (*(arr[index]) < *minElem) {
                minElem = arr[index];
                minIndex = index;
            }
        }
        arr[minIndex] = arr[startScan];
        arr[startScan] = minElem;
    }
}

//**********************************************************
// Definition of function showArray.                       *
// This function displays the contents of arr. size is the *
// number of elements.                                     *
//**********************************************************

void showArray(const int arr[], int size) {
    for (int count = 0; count < size; count++)
        cout << arr[count] << " ";
    cout << endl;
}

//**************************************************************
// Definition of function showArrPtr.                          *
// This function displays the contents of the array pointed to *
// by arr. size is the number of elements.                     *
//**************************************************************

void showArrPtr(int *arr[], int size) {
    for (int count = 0; count < size; count++)
        cout << *(arr[count]) << " ";
    cout << endl;
}

int *mkAray(int sz) {
    //Check to see if size of array is valid - if not, create it at a set
    //minimum size.
    if (sz<2)
        sz=2;
    //Grab memory from system pool & use for array storage.
    int *arr = new int[sz];
    //Return pointer to allocated memory.
    return arr; 
}

int **mkPtr(int sz) {
    //Check to see if size of array is valid - if not, create it at a set
    //minimum size.
    if (sz<2)
        sz=2;
    //Grab memory from system pool & use for array storage.
    int **arr = new int*[sz];
    //Return pointer to allocated memory.
    return arr; 
}

void rmAray(int *arr) {
    //Return allocated memory to system pool (prevents memory leaks).
    delete []arr;
    //Null out pointer to allocated memory (safety measure)
    arr=0;
}

void rmPtr(int **arr) {
    //Return allocated memory to system pool (prevents memory leaks).
    delete []arr;
    //Null out pointer to allocated memory (safety measure)
    arr=0;
}
