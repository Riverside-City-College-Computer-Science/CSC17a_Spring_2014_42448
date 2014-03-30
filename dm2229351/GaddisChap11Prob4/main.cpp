/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on March 30, 2014, 11:31 AM
 */



#include <cstdlib>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

struct Weather{
    int rainfall;
    int htemp,ltemp,avgtemp;
};

using namespace std;

void input( Weather&);
void print(Weather[]);

int main(int argc, char** argv) {
    Weather Month[12];
    for(int i=0;i<12;i++)
    {
        cout << "Please enter data for the " << i+1 << "st month" << endl;
        input(Month[i]);
    }
    print(Month);

    return 0;
}

void input(Weather &month)
{
    int input;
        cout << "Please enter low temperature in Fahrenheit between -100 and +140" << endl;
        cin >> input;
        while(input<-100 || input >140)
        {
            cout << "\nTemperature is not valid: ";
            cin >> input;
        }
        month.ltemp=input;
        cout << "Please enter high temperature in Fahrenheit between -100 and +140"<< endl;
        cin >> input;
        while(input<-100 || input >140)
        {
            cout << "\nTemperature is not valid: ";
                    cin >> input;
        }
        month.htemp=input;
        cout << "Please enter total rainfall " << endl;
        cin >> input;
        month.rainfall=input;
        month.avgtemp=(month.ltemp+month.htemp/2);
}
void print(Weather month[])
{
    float totalaverage=0;
    int totalrain=0;
    int low=0,high=0;
    int monthlow,monthhigh;
    
    for(int i=0;i<12;i++)
    {
        if(month[i].ltemp<low)
        {
            low=month[i].ltemp;
            monthlow=i+1;
        }
        if(month[i].htemp>high)
        {
            high=month[i].htemp;
            monthhigh=i+1;
        }
        totalrain+=month[i].rainfall;
        totalaverage+=month[i].avgtemp;
    }
    
    totalaverage/=12;
    cout << "Total rainfall for the year is: " << totalrain << endl;
    cout << "Average rainfall for the year is: " << totalrain/12 << endl;
    cout << "Average temperatures for all months: " << totalaverage << endl;
    cout << "Highest temp happened in the " << monthhigh << "st month at " << high << " degrees" << endl;
    cout << "Lowest temp happened in the " << monthlow << "st month at " << low << " degrees";
}