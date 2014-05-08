
#include "Date.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Date::Date(int m, int d, int y)
{
    month=m;
    day=d;
    year=y;
}
void Date::printDateDashes()
{
    cout << month << "/" << day << "/" << year << endl;
}
void Date::printDateDayFirst()
{
    cout << day << " ";
    switch(month){
        case 1:
            cout << "January ";
            break;
            case 2:
            cout << "February ";
            break;
            case 3:
            cout << "March ";
            break;
            case 4:
            cout << "April ";
            break;
            case 5:
            cout << "May ";
            break;
            case 6:
            cout << "June ";
            break;
            case 7:
            cout << "July ";
            break;
            case 8:
            cout << "August ";
            break;
            case 9:
            cout << "September ";
            break;
            case 10:
            cout << "October ";
            break;
            case 11:
            cout << "November ";
            break;
            case 12:
            cout << "December ";
            break;
        default:
            break;
    };
    cout << year << endl;;
}
void Date::printDateMonthFirst()
{
        switch(month){
        case 1:
            cout << "January ";
            break;
            case 2:
            cout << "February ";
            break;
            case 3:
            cout << "March ";
            break;
            case 4:
            cout << "April ";
            break;
            case 5:
            cout << "May ";
            break;
            case 6:
            cout << "June ";
            break;
            case 7:
            cout << "July ";
            break;
            case 8:
            cout << "August ";
            break;
            case 9:
            cout << "September ";
            break;
            case 10:
            cout << "October ";
            break;
            case 11:
            cout << "November ";
            break;
            case 12:
            cout << "December ";
            break;
        default:
            break;
    };
    cout << " " << day << ", " << year;
}