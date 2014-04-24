/* 
 * File:   main.cpp
 * Author: Scott Nevin
 *
 * Created on April 9, 2014, 1:25 PM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

//User Libraries
#include "Array1D.h"

//No Global variables or constants

//Function prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Declare variables
    Array1D myArray(100), yourArray(100);
    //print the array
    myArray.prntArray(10);
    yourArray.prntArray(10);
    //Exit the program
    return 0;
}

