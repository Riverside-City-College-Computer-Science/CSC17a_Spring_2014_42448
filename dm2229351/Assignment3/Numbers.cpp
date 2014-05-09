#include "Numbers.h"
#include <iostream>

using namespace std;

const string Numbers::lessThan20[]={"zero ","one ","two ","three ","four ","five ","six ",
    "seven ","eight ","nine ","ten ","eleven ","twelve ","thirteen ","fourteen ",
    "fifteen ","sixteen ","seventeen ","eighteen ","nineteen "};
const string Numbers::moreThan20[]={"twenty ","thirty ","forty ","fifty ","sixty ",
    "seventy","eighty","ninety"};
const string Numbers::hundred="hundred ";
const string Numbers::thousand = "thousand ";

Numbers::Numbers(int x)
{
    number=x;
}

void Numbers::print()
{
    int a,b,c,d,temp;
        a=(number/1000)%10;
        b=((number%1000)/100);
        c=((number%100)/10);
        temp=number%100;
        d=((number%10));
    if(number>999)
    {
        cout << lessThan20[a];
        cout << thousand;
        if(b!=0)
            cout << lessThan20[b] << hundred;
        if (temp>20){
            cout << moreThan20[(temp/10)-2];
            cout << lessThan20[d];
        }
        else if(temp<20)
        {
            cout << lessThan20[temp];
        }
    }
    else if(number <1000 && number>99)
    {
        if(b!=0)
            cout << lessThan20[b] << hundred;
        if (temp>20){
            cout << moreThan20[(temp/10)-2];
            cout << lessThan20[d];
        }
        else if(temp<20)
        {
            cout << lessThan20[temp];
        }
    }
    else if(number < 99 && number>19)
    {
        cout << moreThan20[(temp/10)-2];
        cout << lessThan20[d];
    }
    else if(number <20)
    {
        cout << lessThan20[temp]; 
    }
        cout << endl;
};
