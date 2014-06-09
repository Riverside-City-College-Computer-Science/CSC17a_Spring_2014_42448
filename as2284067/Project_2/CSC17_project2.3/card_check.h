/* 
 * File:   card_check.h
 * Author: Abel Salazar
 * Created on June 4, 2014, 5:41 PM
 */

#ifndef CARD_CHECK_H
#define	CARD_CHECK_H

class Cards{
private:
    int Deck;
public:
    Cards (int);
    void fillDeck(int x){
        Deck = x;  
    }
    int prnt(int);
};

#endif	/* CARD_CHECK_H */

