/* 
 * File:   main.cpp
 * Author: Scott Nevin
 * Purpose: Create deck of cards
 * Created on April 30, 2014, 12:54 PM
 */

//Libraries
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

//our Libraries
#include "card.h"

//Global variables and constants

//Function Prototypes

//Begin execution here
int main(int argc, char** argv) {
    
    //declare variables
    int nCards=52;
    Card **card=new Card*[nCards];
    
    //Check out all the cards
    //ouput name, suit, value, then number
    for(int i=0;i<nCards;i++){
        card[i]=new Card(i);
        cout<<setw(1)<<card[i]->name()<<setw(3)<<left<<card[i]->suit()<<" ";
        cout<<setw(4)<<left<<static_cast<int>(card[i]->value())<<" ";
        cout<<setw(4)<<left<<static_cast<int>(card[i]->getNumber())<<endl;
    }
    
    //delete card array
    for(int i=0;i<nCards;i++){
        delete card[i];
    }
    delete []card;
    //Exit stage right
    return 0;
}

