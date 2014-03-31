/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on March 7, 2014, 6:14 PM
 * Purpose: Populate a file with random numbers. Number of values and filename
 *          to be input by user
 */

//System Libraries
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Define local constants & variables
    const int SIZE = 500;
    int iNum, num;
    ofstream outf;
    //Seed random number generator
    srand(static_cast<unsigned int>(time(0)));
    //Get user input
    cout << "Number of elements: ";
    cin >> iNum;
    //Open file
    outf.open("numbers.txt");
    //Main processing loop
    for (int i=0; i<iNum; i++) {
        num = rand()%90+10;
        outf << num << endl;
    }
    //Close file
    outf.close();
    //Exit, stage right!
    return 0;
}

