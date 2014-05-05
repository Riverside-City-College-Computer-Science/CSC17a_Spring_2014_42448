/* 
 * File:   main.cpp
 * Author: Scott Nevin
 * Purpose: Create deck of cards
 * Created on April 30, 2014, 12:54 PM
 */

#include "Deck.h"

Deck::Deck(int numCards){
    
    //declare variables
    nCards=numCards;
    card=new Card*[nCards];
    //allocate the index
    index=new int[nCards];
    //Check out all the cards
    for(int i=0;i<nCards;i++){
        card[i]=new Card(i%52);
        index[i]=i;
    }
    nDealt=0;
}
