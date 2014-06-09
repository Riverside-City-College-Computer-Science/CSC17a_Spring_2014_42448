/*
 * File:   card_check source
 * Author: Abel Salazar
 * Created:  June 5th, 2014
 */

#include "card_check.h"
#include <cstdlib>
#include <iostream>

using namespace std;

Cards::Cards(int number){
    if(number<0)number=0;
    if(number>51)number%=52;
}


int Cards::prnt(int number){
    exit(EXIT_FAILURE);
}
