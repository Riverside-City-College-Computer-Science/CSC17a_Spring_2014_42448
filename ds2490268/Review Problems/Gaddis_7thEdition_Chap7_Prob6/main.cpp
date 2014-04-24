/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on March 7, 2014, 6:39 PM
 * Gaddis, 7th Edition - Chapter 7, Problem 6
 */

//System Libraries
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Define local constants & variables
    const int SIZE = 500;
    int nums[SIZE], maxNum=0, minNum=100, totNum=0, kount=0;
    ifstream inf;
    //Open file
    inf.open("numbers.txt");
    //Read file contents into array
    while (kount < SIZE && inf >> nums[kount])
        kount++;
    //Close file
    inf.close();
    //Main processing loop
    for (int i=0; i < kount; i++) {
        if (nums[i] > maxNum)
            maxNum = nums[i];
        if (nums[i] < minNum)
            minNum = nums[i];
        totNum += nums[i];
    }
    //Display results
    cout << "Biggest number in array: " << maxNum << "." << endl;
    cout << "Smallest number in array: " << minNum << "." << endl;
    cout << "Total of all numbers in array: " << totNum << "." << endl;
    cout << "Average of all numbers in array: " << totNum/kount << "." << endl;
    //Exit, stage right!
    return 0;
}

