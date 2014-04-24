/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on March 7, 2014, 3:19 PM
 * Gaddis, 7th Edition: Chapter 3, Problem 13
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Define local constants
    const float ASSESS = 6.0e-1;  //Assessed value = 60% of actual value
    const float PRP_TAX = 6.4e-3; //Property tax = $0.64 per $100 of assessment
    //Define local variables
    float iActual, dAssess, dPrpTax;
    //Get user input
    cout << "Enter Actual value of property: $";
    cin >> iActual;
    //Calculate assessed value & tax
    dAssess = iActual * ASSESS;
    dPrpTax = dAssess * PRP_TAX;
    //Output results
    cout << setprecision(2) << fixed << showpoint;
    cout << left << "For property valued at: $" 
         << setw(12) << right << iActual << endl;
    cout << left << "Assessed value is:      $"
         << setw(12) << right << dAssess << endl;
    cout << left <<  "With property taxes of: $" 
         << setw(12) << right << dPrpTax << endl;
    //Exit, stage right
    return 0;
}

