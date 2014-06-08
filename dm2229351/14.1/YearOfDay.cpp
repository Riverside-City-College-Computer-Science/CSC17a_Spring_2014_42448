#include "YearOfDay.h"

#include <iostream>

using namespace std;

YearOfDay::YearOfDay(string m, int d)
{
    if(m=="January" && d<0 || d>31){
        cout << "Invalid date for " << m;
        exit(0);
    }
    else if(m=="February"
        
    month=m;
    day=d;
}

