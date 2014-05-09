#include <iostream>

#include "DayOfYear.h"
#include <iostream>

using namespace std;

const string months[]={"January","February","March","April","May","June",
"July","August","September","October","November","December"};

DayOfYear::DayOfYear(int x)
{
    day=x;
}

DayOfYear::DayOfYear(int x, string m)
{
    int temp;
    for(int i=0;i<12;i++)
    {
        if(m==months[i]){
            temp=i;
        }
    }
    if(temp==0 || temp==2 || temp==4 || temp==6 || temp==7 || temp==9 || temp==11){
        if(x > 31 || x<0){
            cout << "Invalid day for " << months[temp] << endl;
            throw 1;
        }
    }
    else if(temp==1){
        if(x>28 || x<0){
            cout << "Invalid day for " << months[temp] << endl;
            throw 1;
        }
    }
    else if(temp==3 || temp==5 || temp==8 || temp==10){
        if(x>30 || x<0){
            cout << "Invalid day for " << months[temp] << endl;
            throw 1;
        }
    }
    switch(temp)
    {
        case 0:
            day=x;
            break;
        case 1:
            day=x+31;
            break;
        case 2:
            day=x+59;
            break;
        case 3:
            day=x+90;
            break;
        case 4:
            day=x+120;
            break;
        case 5:
            day=x+151;
            break;
        case 6:
            day=x+181;
            break;
        case 7:
            day=x+212;
            break;
        case 8:
            day=x+243;
            break;
        case 9:
            day=x+273;
            break;
        case 10:
            day=x+304;
            break;
        case 11:
            day=x+334;
            break;            
    }
}

int DayOfYear::getDay()
{
    return day;
}

void DayOfYear::print()
{
    if(day<32)
        cout << months[0] << " " << day%32;
    else if(day>31 && day<60)
        cout << months[1] << " " << (day-31)%29;
    else if(day>59 && day<91)
        cout << months[2] << " " << (day-59)%32;
    else if(day>90 && day<121)
        cout << months[3] << " " << (day-90)%31;
    else if(day>120 && day<152)
        cout << months[4] << " " << (day-120)%32;
    else if(day>151 && day<182)
        cout << months[5] << " " << (day-151)%31;
    else if(day>181 && day<213)
        cout << months[6] << " " << (day-181)%32;
    else if(day>212 && day<244)
        cout << months[7] << " " << (day-212)%32;
    else if(day>243 && day<274)
        cout << months[8] << " " << (day-243)%31;
    else if(day>273 && day<305)
        cout << months[9] << " " << (day-273)%32;
    else if(day>304 && day<335)
        cout << months[10] << " " << (day-304)%31;
    else if(day>334 && day<366)
        cout << months[11] << " " << (day-334)%32;
    cout << endl;
    
                
}

DayOfYear DayOfYear::operator++(int)
{
    if(day==365)
    {
        day=0;
    }
    else
        day++;
    return *this;
}
DayOfYear DayOfYear::operator--(int)
{
    if(day==0)
    {
        day=365;
    }
    else
        day--;
    return *this;
}
