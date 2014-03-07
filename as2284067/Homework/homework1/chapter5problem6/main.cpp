/* 
 * File:   main.cpp
 * Author: Abel Salazar
 * Created on March 6, 2014, 3:27 PM
 */

#include <iostream>
#include <cstdlib>

using namespace std;
//global constants
const float cvnCm=2.54; //centimeters to inch
const int cvnInch=12;

//function prototypes
void inUser(int &, int &);
float cvnInches(int, int);
float cvnCent(float);
void prntLength(float,float);

//execution begins here
int main(int argc, char** argv) {
    //variable declaration
    int feet=0, inches=0;
    float totInch, totCm, totM;
    inUser(feet, inches);
    totInch=cvnInches(feet,inches);
    totCm=cvnCent(totInch);
    totM = totCm/100;
    totCm-=totCm/100;
    prntLength(totM,totCm);
    
    //exit stage right
    return 0;
}


void prntLength(float meters, float centimeter){
    cout << "Total meters = " <<meters<<endl;
    cout << "Total centimeters = "<<centimeter<<endl;
}

float cvnCent(float inches){
    float centi;
    centi=inches*cvnCm;
    return centi;
}

float cvnInches(int feet, int inches){
    float tot = (static_cast<float>(feet)*cvnInch) + inches;
    return tot;
}

void inUser(int & feet, int & inches){
    cout << "Enter length of the object in feet" <<endl;
    cin >> feet;
    cout << "Enter the length of remaining inches" <<endl;
    cin >> inches;
}