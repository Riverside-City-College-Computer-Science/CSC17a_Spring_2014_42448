/* 
 * File:   Card.h
 * Author: Scott Nevin
 * card specification file
 * Created on April 30, 2014, 12:56 PM
 */

#ifndef CARD_H
#define	CARD_H

class Card{
   private:
       char number;
   public:
       Card(int);
       char suit();
       char name();
       char value();
       char getNumber(){return number;}
};

#endif	/* CARD_H */

