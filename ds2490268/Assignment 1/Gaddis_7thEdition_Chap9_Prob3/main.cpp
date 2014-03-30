/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on March 14, 2014, 8:02 PM
 * Gaddis, 7th Edition - Chapter 9, Problem 3
 * 
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global constants

//Function Prototypes
float *mkAray(int);
void rmAray(float *);
float avgSco(const float *, int);
void selSort(float *, int);
void shoAray(const float *, int, int);

//Execution begins here
int main(int argc, char** argv) {
    //Define local variables & constants
    int iSize, index;
    float iScore,*scores;
    //Get size from user
    cout << "Enter number of scores to be entered (less than 2 to end): ";
    cin >> iSize;
    //If valid # of scores, accept scores from user, checking for negatives.
    if (iSize >= 2) {
        scores = mkAray(iSize);
        for (index = 0; index < iSize; index++) {
            cout << "Enter score (no negatives) : ";
            cin >> iScore;
            if (iScore >= 0.0) {
                *(scores+index) = iScore;
            } else {
                cout << "Negative score - exiting program." << endl;
                break;
            }
        }
        //If all scores were entered, sort scores, calc. average &
        //display results
        if (index == iSize) {
            selSort(scores,iSize);
            cout << "Sorted scores:" << endl;
            shoAray(scores,iSize,10);
            cout << "Average score (lowest dropped): " << avgSco(scores, iSize)
                 << endl;
        }
        //Even if a negative score was entered, we still need to clean up
        //after ourselves - return dynamic array memory to memory pool.
        rmAray(scores);
    }
    //Exit, stage right!
    return 0;
}

float *mkAray(int sz) {
    //Check to see if size of array is valid - if not, create it at a set
    //minimum size.
    if (sz<2)
        sz=2;
    //Grab memory from system pool & use for array storage.
    float *arr = new float[sz];
    //Return pointer to allocated memory.
    return arr; 
}

void rmAray(float *arr) {
    //Return allocated memory to system pool (prevents memory leaks).
    delete []arr;
    //Null out pointer to allocated memory (safety measure)
    arr=0;
}

void selSort(float *arr, int size) {
    //Define local variables
    int startScan, minIndex, minValue;
    
    for (startScan = 0; startScan < (size-1); startScan++) {
        minIndex = startScan;
        minValue = *(arr+startScan);
        for (int index = startScan + 1; index < size; index ++) {
            if (*(arr+index) < minValue) {
                minValue = *(arr+index);
                minIndex = index;
            }
        }
        *(arr+minIndex) = *(arr+startScan);
        *(arr+startScan) = minValue;
    }
}

void shoAray(const float *arr, int size, int brkOn) {
    cout << setprecision(1) << fixed << showpoint;
    for (int count = 0; count < size; count++) {
        cout << arr[count] << " ";
        if ((count % brkOn)== (brkOn-1))
            cout << endl;
    }
    cout << endl;
}

float avgSco(const float *arr, int sz) {
    //Modified to exclude lowest score
    float totSco = 0.0,minSco=999.0;
    for (int count = 0; count < sz; count++) {
        if (*(arr+count) < minSco)
            minSco = *(arr+count);
        totSco += *(arr+count);
    }
    return (totSco-minSco)/static_cast<float>(sz-1);
}
