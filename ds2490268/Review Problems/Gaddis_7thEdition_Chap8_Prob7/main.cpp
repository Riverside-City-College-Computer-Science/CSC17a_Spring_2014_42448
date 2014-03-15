/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on March 7, 2014, 4:55 PM
 * Gaddis, 7th Edition - Chapter 8 Problem 7
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//Global Constants

//Function Prototypes
void prtAry(const string [],int,int);
void selSort(string [],int);
int binSrch(const string [],const int,const string);

//Execution begins here
int main(int argc, char** argv) {
    //Define local constants & variables
    const int NUM_NMS = 20;
    const string inNames = "Pike, Gordon";
    const string noInNms = "Smith, David";
    string names[NUM_NMS] = {"Collins, Bill","Smith, Bart","Allen, Jim",
                             "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
                             "Taylor, Terri", "Johnson, Jill",
                             "Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
                             "James, Jean","Weaver, Jim","Pore, Bob",
                             "Rutherford, Greg","Javens, Renee",
                             "Harrison, Rose","Setzer, Cathy",
                             "Pike, Gordon","Holland, Beth"};
    //Print unsorted array
    prtAry(names,NUM_NMS,3);
    //Sort that puppy
    selSort(names,NUM_NMS);
    //Print the sorted array
    prtAry(names,NUM_NMS,3);
    //Example of a binary search for a name not in the list
    cout << "Found name (" << noInNms << ") at position "
         << binSrch(names, NUM_NMS, noInNms) << "." << endl;
    //Example of a binary search for a name in the list
    cout << "Found name (" << inNames << ") at position "
         << binSrch(names, NUM_NMS, inNames) << "." << endl;
    //Exit, stage right!
    return 0;
}

int binSrch(const string a[],const int n,const string findIt) {
    //Define local variables
    int min=0, max=n-1, mid;
    bool isFound = false;
    //Pick element in middle of search area & compare to see if it's a match.
    //If it is, stop - otherwise, subdivide search area based on whether the
    //element found is greater than or less than what you're looking for.
    do {
        mid = ((max-min)/2)+min;
        if (a[mid] > findIt)
            max = mid;
        else if(a[mid] < findIt)
            min = mid;
        else if(a[mid] == findIt) {
            isFound = true;
        }
        //Keep searching until element is found or the search area has nothing
        //left to look at.
    } while (((max-min) > 1) && (!isFound));
    //If the element is found, return the position in the array to the calling
    //program, else return a -1, indicating not found.
    if (isFound)
        return mid;
    else
        return -1;
}

void selSort(string array[],int size) {
    int strtScn, minIdx;
    string minVal;
    
    for (strtScn = 0; strtScn < (size-1); strtScn++) {
        minIdx = strtScn;
        minVal = array[strtScn];
        for (int idx=strtScn+1;idx < size;idx++) {
            if (array[idx] < minVal) {
                minVal = array[idx];
                minIdx = idx;
            }
        }
        array[minIdx] = array[strtScn];
        array[strtScn] = minVal;
    }
    
    return;
}

void prtAry(const string a[],int elemnts,int brkOn){
    //Print elements in a 32 character field (left-justified), with a line
    //break at each brkOn element.
    cout << endl;
    for(int i = 0; i < elemnts; i++){
        cout << setw(32) << left << a[i];
        if((i % brkOn) == (brkOn - 1))
            cout << endl;
    }
    cout << endl;
}
