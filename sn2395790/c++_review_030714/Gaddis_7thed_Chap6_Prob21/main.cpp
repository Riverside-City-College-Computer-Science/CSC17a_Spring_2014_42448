/* 
 * File:   main.cpp
 * Author: Scott Nevin
 * Purpose: Determine prime numbers
 * Created on March 6, 2014
 */

//Libraries
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

//Function prototypes
bool isPrime(int);

//Global variables and constants

//Begin execution here
int main(int argc, char** argv) {

    //Declare variables
        int val;

        //Prompt user for input
        cout<<"Enter a number and I will tell you all numbers "<<endl;
        cout<<"less than or equal to that are prime."<<endl;
        cin>>val;

        //Indicate whether the number is prime or not
        for (int i=2; i<=val;i++){
            cout<<"The number "<<i<<" is"<<
        (isPrime(i)?"":" not ")<<
              " prime"<<endl;
        }

    //Exit stage right
    return 0;
}

bool isPrime(int num){

        for (int i=2; i<=sqrt(1.0*num); i++){

            if(!(num%i))
                return false;

        }
        return true;
}