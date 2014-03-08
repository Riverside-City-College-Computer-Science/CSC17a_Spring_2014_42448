/* 
 * File:   main.cpp
 * Author: Scott Nevin
 * Purpose: Display table of distance traveled
 * Created on March 7, 2014, 10:46 PM
 */

//Libraries
#include <iostream>
#include <cstdlib>
using namespace std;

//Global variables and constants

//Function prototypes

//Begin execution here
int main(int argc, char** argv) {
    
    //declare variables
    unsigned short  speed, num, hrs, distance;
               
    cout<<"What is the speed of the vehicle in mph?";
    cin>>speed;
    cout<<"How many hours has it traveled?";
    cin>>hrs;
    cout<<"Table of distance traveled"<<endl;
    cout<<"hour                                          distance traveled"<<endl;
    cout<<"_________________________________________________________"<<endl;

          for (num=1; num<=hrs; num++){
              distance = num * speed;

              cout<<num<<"................................................"<<distance<<" miles"<<endl;

               }

    //Exit stage right
    return 0;
}

