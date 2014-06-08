/* 
 * File:   Numbers.h
 * Author: Diego
 *
 * Created on May 8, 2014, 3:55 PM
 */
#include <iostream>

using namespace std;

#ifndef NUMBERS_H
#define	NUMBERS_H

class Numbers{
    
    int number;
    public:
    static const string lessThan20[];/*={"zero","one","two","three","four","five","six",
    "seven","eight","nine","ten","eleven","twelve","thirteen","fourteen",
    "fifteen","sixteen","seventeen","eighteen","nineteen"};*/
    static const string moreThan20[];/*={"twenty","thirty","forty","fifty","sixty",
    "seventy","eighty","ninety"};*/
    static const string hundred; //= "hundred ";
    static const string thousand;// = "thousand ";

    Numbers(int);
    void print();
};


#endif	/* NUMBERS_H */

