/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on March 7, 2014, 7:25 PM
 * Gaddis, 7th Edition - Chapter 6, Problem 7
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants

//Function Prototypes
float celsius(float);

//Execution Begins Here
int main(int argc, char** argv) {
    //Define local constants & variables
    const int MAX_FAHR = 20;
    //Main processing loop
    for (int i=0; i<=MAX_FAHR; i++)
        cout << "Fahrenheit: " << i << " --- Celsius: " 
             << celsius(static_cast<float>(i)) << "." << endl;
    //Exit, stage right!
    return 0;
}

//Convert Fahrenheit temperature to Celsius
float celsius(float fahr) {
    const float factor = 5.0e0/9.0e0, offset = 3.2e1;
    return factor*(fahr-offset);
}

