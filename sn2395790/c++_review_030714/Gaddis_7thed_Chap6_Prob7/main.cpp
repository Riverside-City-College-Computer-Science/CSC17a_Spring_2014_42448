/* 
 * File:   main.cpp
 * Author: Scott Nevin
 * Purpose: convert degrees farenheit to degrees celsius
 * Created on March 6, 2014
 */


//Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

//Function Prototypes
    float celsius(int);

//Global Variables and constants

//Execution begins here
int main(int argc, char** argv) {

    //Declare variables
        int count;

        //display table
        cout<<"Degrees Farenheit"<<setw(20)<<"Degrees Celsius"<<endl;

        //initiate loop
        for(count=0; count<21; count++){

            cout<<setw(5)<<count;
            //call conversion function
          float cel = celsius(count);
            cout<<setw(25)<<cel<<endl;
        }


    return 0;
}

float celsius(int f){

        float c;
        c = (5/9.0)*(f-32);
        return c;
    }

