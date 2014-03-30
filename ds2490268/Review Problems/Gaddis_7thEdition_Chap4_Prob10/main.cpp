/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on March 7, 2014, 8:31 PM
 * Gaddis, 7th Edition - Chapter 4, Problem 10
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants

//Function Prototypes

int main(int argc, char** argv) {
    //Defile local constants & variables
    const float LVL1 = 2.0e-1;  //20% Discount
    const float LVL2 = 3.0e-1;  //30% Discount
    const float LVL3 = 4.0e-1;  //40% Discount
    const float LVL4 = 5.0e-1;  //50% Discount
    const float BASE = 9.9e1;   //Base price = $99.00 per unit
    int iUnits;
    float discAmt = 0.0, totSold = 0.0;
    //Get user input
    cout << "Number of units sold: ";
    cin >> iUnits;
    //Determine discount, validate input
    if (iUnits > 0) {
        totSold = iUnits * BASE;
        if (iUnits < 10) {
            cout << "No discount applied." << endl;
        } else if (iUnits >= 10 && iUnits <= 19) {
            cout << "Good for a 20% discount." << endl;
            discAmt = totSold * LVL1;
        } else if (iUnits >= 20 && iUnits <= 49) {
            cout << "Good for a 30% discount." << endl;
            discAmt = totSold * LVL2;
        } else if (iUnits >= 50 && iUnits <= 99) {
            cout << "Good for a 40% discount." << endl;
            discAmt = totSold * LVL3;
        } else if (iUnits >= 100) {
            cout << "Good for a 50% discount." << endl;
            discAmt = totSold * LVL4;
        }
        //Apply discount & display results
        cout << fixed << showpoint << setprecision(2);
        cout << "Total before discount: $" << totSold << endl;
        cout << "Total discount: $" << discAmt << endl;
        cout << "Total after discount: $" << totSold - discAmt << endl;
    } else
        cout << "Invalid # of units.";
    //Exit, stage right!
    return 0;
}

