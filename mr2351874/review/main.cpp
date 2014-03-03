/* 
 * File:   main.cpp
 * Author: michael
 *
 * Created on February 24, 2014, 3:08 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

/*
 * 
 */
void p3_12();
void p4_10();

int main( int argc, char** argv ) {
    p4_10();
    return 0;
}

void p3_12(){
    /*
     Write a cout statement so the variable divSales is displayed in a field of 8 spaces, in fixed point notation, with a precision of 2 decimal places. The decimal point should always be displayed.
    */
    float divSales = 1234.567;
    cout << setw(8) << setprecision(2) << fixed << divSales << endl;
}

void p4_10(){
    cout<< "enter a amount to buy ";
    int amt;
    cin >> amt;
    cout << "discount of ";
    if ( amt >= 10 && amt < 20 ) {
        cout << "20%";
    }
    else if ( amt >= 20 && amt < 50 ) {
        cout << "30%";
    }
    else if ( amt >= 50 && amt < 100 ) {
        cout << "40%";
    }
    else if ( amt >= 100 ) {
        cout << "50%";
    }
    else{
        cout << "none";
    }
    cout<<endl;
}
