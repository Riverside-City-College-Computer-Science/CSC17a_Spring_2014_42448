/* 
 * File:   main.cpp
 * Author: Scott Nevin
 * Purpose: Write the code breaking game, Mastermind 
 * Created on April 8, 2014, 10:53 AM
 */

//Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
using namespace std;

//Global Variables and constants.

//Function Prototypes
#include "functions.h"

//Execution begins here
int main(int argc, char** argv) {
    
    //seed random number generator
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int SIZE=4, ply=0, tries = 12;
    char code[SIZE], index[SIZE], guess[SIZE], symb[SIZE];
    bool win = true;
    
    //generate random code
    prpCode(code, index, SIZE);
    
    //initiate loop for Game
    do{
        //Prompt user for guess
        usrGess(guess, SIZE);

        //test user's guess
        tstGess(guess, index, code, symb, SIZE);

        //output results array
        for(int i=0;i<SIZE;i++){
            cout<<symb[i]<<" ";
        }
        cout<<endl;
        ply++;
        //set win bool variable
        win = tstWin(symb);
        
    }while(ply<tries&&win==true);
    
    //output victory
    if(win==false){
        cout<<"Hooray! you won"<<endl;
    }
    else cout<<"You did not win"<<endl;
    
    //output code
    for(int i=0;i<SIZE;i++){
        cout<<code[i];
    }
    cout<<" was the code"<<endl;
    
    //Exit Stage right
    return 0;
}
