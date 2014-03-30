/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on March 14, 2014, 9:46 PM
 * Gaddis, 7th Edition - Chapter 9, Problem 5
 * 
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants

//Function prototypes
int doSomething(int *, int *);

//Execution begins here
int main(int argc, char** argv) {
    //Declare local variables
    int *a, *b;
    //Simple function call to show what you get from the doSomething()
    //function.
    *a = 10;
    *b = 20;
    cout << "Before function call, a = " << *a << " and b = " << *b << "."
         << endl;
    cout << "After function call, a = " << *a << " and b = " << *b
         << " returning " << doSomething(a, b) << "." << endl;
    //Exit, stage right!
    return 0;
}

int doSomething(int *x, int *y) {
    int temp = *x;
    *x = *y * 10;
    *y = temp * 10;
    return *x + *y;
}

