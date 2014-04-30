/* 
 * File:   Deck.h
 * Author: Scott Nevin
 * Deck specification file
 * Created on April 30, 2014, 1:58 PM
 */

#ifndef DECK_H
#define	DECK_H

#include "Card.h"

class Deck{
   private:
       Card **card;
       int *index;
       int nCards;
       int nDealt;
   public:
       Deck(int);
       ~Deck(){
           for(int i=0;i<nCards;i++){delete card[i];}
           delete []card;
        }
       void shuffle();
       int *deal();
};

#endif	/* DECK_H */

