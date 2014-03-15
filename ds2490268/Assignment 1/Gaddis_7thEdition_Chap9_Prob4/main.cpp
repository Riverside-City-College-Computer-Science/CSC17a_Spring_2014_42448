/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on March 14, 2014, 8:15 PM
 * Gaddis, 7th Edition - Chapter 9, Problem 4
 * 
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//Global constants

//Function Prototypes
float *mkAray(int);
string *mkName(int);
void rmAray(float *);
void rmAray(string *);
float avgSco(const float *, int);
void selSort(float *, string *, int);
void shoAray(const float *, const string *,int);

//Execution begins here
int main(int argc, char** argv) {
    //Define local variables & constants
    int iSize, index;
    float iScore,*scores;
    string iName,*names;
    //Get size from user
    cout << "Enter number of scores to be entered (less than 2 to end): ";
    cin >> iSize;
    //If valid # of scores, accept scores from user, checking for negatives.
    if (iSize >= 2) {
        scores = mkAray(iSize);
        names = mkName(iSize);
        for (index = 0; index < iSize; index++) {
            cout << "Enter score(no negative scores): ";
            cin >> iScore;
            cin.ignore();
            cout << "Enter name of person who earned this score: ";
            getline(cin,iName);
            if (iScore >= 0.0) {
                *(scores+index) = iScore;
                *(names+index) = iName;
            } else {
                cout << "Negative score - exiting program." << endl;
                break;
            }
        }
        //If all scores were entered, sort scores, calc. average &
        //display results
        if (index == iSize) {
            selSort(scores,names,iSize);
            cout << "Sorted scores:" << endl;
            shoAray(scores,names,iSize);
            cout << "Average score: " << avgSco(scores, iSize) << endl;
        }
        //Even if a negative score was entered, we still need to clean up
        //after ourselves - return dynamic array memory to memory pool.
        rmAray(scores);
        rmAray(names);
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

string *mkName(int sz) {
    //Check to see if size of array is valid - if not, create it at a set
    //minimum size.
    if (sz<2)
        sz=2;
    //Grab memory from system pool & use for array storage.
    string *arr = new string[sz];
    //Return pointer to allocated memory.
    return arr; 
}

void rmAray(float *arr) {
    //Return allocated memory to system pool (prevents memory leaks).
    delete []arr;
    //Null out pointer to allocated memory (safety measure)
    arr=0;
}

void rmAray(string *arr) {
    //Return allocated memory to system pool (prevents memory leaks).
    delete []arr;
    //Null out pointer to allocated memory (safety measure)
    arr=0;
}

void selSort(float *arr, string *nrr, int size) {
    //Define local variables
    int startScan, minIndex, minValue;
    string ascName;
    
    for (startScan = 0; startScan < (size-1); startScan++) {
        minIndex = startScan;
        minValue = *(arr+startScan);
        ascName = *(nrr+startScan);
        for (int index = startScan + 1; index < size; index ++) {
            if (*(arr+index) < minValue) {
                minValue = *(arr+index);
                ascName = *(nrr+index);
                minIndex = index;
            }
        }
        *(arr+minIndex) = *(arr+startScan);
        *(arr+startScan) = minValue;
        *(nrr+minIndex) = *(nrr+startScan);
        *(nrr+startScan) = ascName;
    }
}

void shoAray(const float *arr, const string *nrr, int size) {
    cout << setprecision(1) << fixed << showpoint;
    for (int count = 0; count < size; count++)
        cout << setw(32) << left << *(nrr+count) << " - "
             << setw(5) << right << *(arr+count) << endl;
    cout << endl;
}

float avgSco(const float *arr, int sz) {
    float totSco = 0;
    for (int count = 0; count < sz; count++)
        totSco += *(arr+count);
    return totSco/static_cast<float>(sz);
}

