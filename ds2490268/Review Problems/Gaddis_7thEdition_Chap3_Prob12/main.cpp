/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on February 26, 2014, 12:05 PM
 * Gaddis, 7th Edition: Chapter 3, Problem 12
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Define local constants
    const float ST_TAX = 4.0e-2;  //State sales tax = 4%
    const float CTY_TAX = 2.0e-2; //County sales tax = 2%
    const float TTL_TAX = 1.06e0; //Total sales tax = 6%
    //Define local variables
    string iMth;
    int iYr;
    float iSlsTtl,dPreTax;
    //Get user input
    cout << "Enter month (January - December): ";
    cin >> iMth;
    cout << "Enter year (yyyy): ";
    cin >> iYr;
    cout << "Enter total $ collected at this register: $";
    cin >> iSlsTtl;
    //Calculate pre-tax sales
    dPreTax = iSlsTtl / TTL_TAX;
    //Generate output
    cout << "Sales & Tax for " << iMth << ", " << iYr << endl;
    cout << "================================" << endl;
    cout << setprecision(2) << fixed << showpoint;
    cout << setw(21) << left << "Total collected:"
         << "$" << setw(9) << right << iSlsTtl << endl;
    cout << setw(21) << left << "Sales:" 
         << "$" << setw(9) << right << dPreTax << endl;
    cout << setw(21) << left << "County Sales Tax:" 
         << "$" << setw(9) << right << dPreTax * CTY_TAX << endl;
    cout << setw(21) << left << "State Sales Tax:"
         << "$" << setw(9) << right << dPreTax * ST_TAX << endl;
    cout << setw(21) << left << "Total Sales Tax:"
         << "$" << setw(9) << right << dPreTax * (CTY_TAX + ST_TAX) << endl;
    //Exit, stage right.
    return 0;
}

