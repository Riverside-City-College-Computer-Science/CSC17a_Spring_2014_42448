/* 
 * File:   Card.cpp
 * Author: Scott Nevin
 * card implementation file
 * Created on April 30, 2014, 12:56 PM
 */

//User libraries
#include "Card.h"

//implement the constructor
Card::Card(int number){
    if(number<0)number=0;
    if(number>51)number%=52;
    this->number=number;
}

char Card::suit(){
    if(number<13)return 'S';
    if(number<26)return 'H';
    if(number<39)return 'C';
    return 'D';
}
//test and find the card name 
char Card::name(){
    //Declare card name array
    char aName[]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
    return aName[number%13];
}
//determine card value, I believe this is for Blackjack
char Card::value(){
    char n=(number)%13+1;
    if(n>10)return 10;
    return n;
}

