/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on February 19, 2014, 1:50 PM
 * Homework #1 - Bubble Sort with Pointers, and Binary Search too!
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

//Global Constants

//Structures

//Function Prototypes
int *fillAry(int);
void fillAry(int [], const int);
void prtAry(int *,int,int);
void bblSort(int *,int);
int binSrch(int *,int,int);

//Execution begins here
int main(int argc, char** argv) {
    //Define local variables & constants
    int NUM = 100, NUM_COLS = 10, FIND_IT = 50;
    int *array,brray[NUM];
    //Seed random number generator
    srand(static_cast<unsigned int>(time(0)));
    //Create arrays with random elements
    array = fillAry(NUM);
    fillAry(brray,NUM);
    //Print array
    cout << "Pointer...";
    prtAry(array,NUM,NUM_COLS);
    //call again with static array, demonstrating that the difference
    //between arrays and pointers is largely syntactic.
    cout << "Array...";
    prtAry(brray,NUM,NUM_COLS);
    //Sort using Bubble Sort
    cout << "Sorting both structures..." << endl;
    bblSort(array,NUM);
    bblSort(brray,NUM);
    cout << endl;
    //Print sorted array
    cout << "Pointer...";
    prtAry(array,NUM,NUM_COLS);
    cout << "Array...";
    prtAry(brray,NUM,NUM_COLS);
    //Search for element in sorted array
    cout << "Search for number (" << FIND_IT << ") in array returned ("
         << binSrch(array,NUM,FIND_IT) << ")." << endl;
    cout << "Search for number (" << FIND_IT << ") in brray returned ("
         << binSrch(brray,NUM,FIND_IT) << ")." << endl;
    //Release array memory back to system (prevents memory leaks)
    delete []array;
    //Exit, stage right.
    return 0;
}

int binSrch(int *a,int n,int findIt) {
    //Define local variables
    char ch;
    int min=0, max=n-1, mid;
    bool isFound = false;
    //Pick element in middle of search area & compare to see if it's a match.
    //If it is, stop - otherwise, subdivide search area based on whether the
    //element found is greater than or less than what you're looking for.
    do {
        mid = ((max-min)/2)+min;
        if (*(a+mid) > findIt)
            max = mid;
        else if(*(a+mid) < findIt)
            min = mid;
        else if(*(a+mid) == findIt) {
            isFound = true;
        }
        //Keep searching until element is found or the search area has nothing
        //left to look at.
    } while (((max-min) > 1) && (!isFound));
    //If the element is found, return the position in the array to the calling
    //program, else return a -1, indicating not found (-1 is an invalid index).
    if (isFound)
        return mid;
    else
        return -1;
}

void bblSort(int *array,int size) {
    //Define local variables
    bool swap;
    int temp;
    //Perform bubble sort
    do {
        swap = false; //If there were no swaps, you're done.
        //Repeatedly pass through array, swapping elements over & over
        //until all elements are swapped into ascending order.
        for (int count = 0; count < (size-1); count++) {
            if (*(array + count) > *(array + count + 1)) {
                temp = *(array + count);
                *(array + count) = *(array + count + 1);
                *(array + count + 1) = temp;
                swap = true;
            }
        }
    } while(swap);
    return;
}

void fillAry(int a[], const int elemnts){
    //Fill array with random 2-digit numbers
    for(int i = 0; i < elemnts; i++) {
        a[i] = rand() % 90 + 10;
    }
    //arrays are passed by reference, so no need to return anything
    return;
}

int *fillAry(int elemnts){
    //Create array & assign address to variable
    int *aray = new int[elemnts];
    //Fill array with random 2-digit numbers
    for(int i = 0; i < elemnts; i++) {
        *(aray+i) = rand() % 90 + 10;
    }
    //pass pointer back to calling program
    return aray;
}

void prtAry(int *a,int elemnts,int brkOn){
    //Print elements in a 3 character field (right-justified), with a line
    //break at each brkOn element.
    cout << endl;
    for(int i = 0; i < elemnts; i++){
        cout << setw(3) << *(a + i);
        if((i % 10) == (brkOn - 1))
            cout << endl;
    }
    cout << endl;
}