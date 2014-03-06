/* 
 * File:   main.cpp
 * Author: Abel Salazar
 * Created on March 6, 2014, 3:13 PM
 */

#include <iostream>
#include <cstdlib>

using namespace std;

//global constants
const float cvnLiter = 0.264179;

//function prototypes
void mpg(float,float,float &);

//execution begins here
int main(int argc, char** argv) {
    //variable declaration
    float miles, fuel;
    float total = 0;
    
    cout << "Enter the amount of miles you traveled" <<endl;
    cin >> miles;
    cout << "Enter the amount of liters of fuel you used" <<endl;
    cin >> fuel;
    mpg(miles, fuel, total);
    cout << "Your car got " << total << " miles per gallon" <<endl;
    
    //exit stage right
    return 0;
}

void mpg(float m,float f, float& t){
    t=m/f/cvnLiter;
}
