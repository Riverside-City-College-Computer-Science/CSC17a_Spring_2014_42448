/* 
 * File:   main.cpp
 * Author: Scott Nevin
 * Purpose: play add up to a dollar game
 * Created on March 6, 2014, 8:14 PM
 */

//Libraries
#include <cstdlib>
#include <iostream>
using namespace std;

//Function Prototypes

//Global variables and constants

//Begin execution here
int main(int argc, char** argv) {
    
    //declare variables
                unsigned int pen, nik, dim, qrt, totl;

                //prompt user for amounts
                cout<<"Change for a Dollar Game!"<<endl;
                cout<<"Input a number of each type of coin that will add up to one dollar."<<endl;
                cout<<"Pennies: ";
                cin>>pen;
                cout<<"Nickels: ";
                cin>>nik;
                cout<<"Dimes: ";
                cin>>dim;
                cout<<"Quarters: ";
                cin>>qrt;

                //calculate the total amount of the coins
                totl = pen+(nik*5)+(dim*10)+(qrt*25);

                //output possible victory
                if (totl > 100)
                    cout<<"Sorry, the amount you entered is over one dollar :(\n Try Again!"<<endl;
                else if (totl < 100)
                    cout<<"Sorry, the amount you entered is under one dollar :(\n Try Again!"<<endl;
                else
                    cout<<"Congratulations!!! \nThe amount you entered added up to exactly one dollar!\n",
                            cout<<"Way to go! :)"<<endl;

//Exit stage right
    return 0;
}

