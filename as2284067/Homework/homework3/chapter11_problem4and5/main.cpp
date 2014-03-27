/* 
 * File:   main.cpp
 * Author: abel salazar
 * Created on March 26, 2014, 8:12 PM
 * takes care of problem 4 and 5
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

//structures
struct Weather{
    int TotRain;
    int TempHigh;
    int LowTemp;
    int AvTemp;
};

//global constants
const int month = 12;

//function prototypes
void fillDat(Weather []);
void prntDat(const Weather []);
void sum    (Weather [], Weather []);
void av     (Weather []);
void sort   (Weather []);
void MinMax (Weather [], Weather []);

//execution
int main(int argc, char** argv) {
    //variable declaration
    const int SIZE = 1;
    Weather year[month]={};
    Weather answers[SIZE]={};
    
    fillDat(year);
    sum(year,answers);
    av(answers);
    sort(year);
    MinMax(year,answers);
    prntDat(answers);
    
    //exit stage
    return 0;
}

void prntDat(const Weather a[]){
    cout << endl;
    cout << "Total rainfall:  " << a[0].TotRain <<endl;
    cout << "Temperature high:" << a[0].TempHigh<<endl;
    cout << "Temperature low: " << a[0].LowTemp<<endl;
    cout << "Average temp:    " << a[0].AvTemp<<endl;
    cout << endl;
    
}

void MinMax(Weather a[], Weather b[]){
    b[0].TempHigh=a[month].TempHigh;
    b[0].LowTemp=a[0].LowTemp;
}

void sort(Weather a[]){
    for(int i=0;i<month;i++){
        for(int j=0;j<i;j++){
            if(a[i].TempHigh > a[j].TempHigh){
                int temp = a[i].TempHigh;
                a[i].TempHigh = a[j].TempHigh;
                temp = a[j].TempHigh;
            }
        }
    }
}

//finds average rainfall
void av(Weather b[]){
    b[0].AvTemp = b[0].TotRain / month;
}

//adds data from array of structures
void sum(Weather a[], Weather b[]){
    for(int i=0;i<month;i++){
        b[0].TotRain += a[i].TotRain;
    }
}

//fills array of structures with user input
void fillDat(Weather a[]){
    for(int i=0;i<month;i++){
        cout << endl;
        cout << "Enter in inches, the total rainfall for month "<<(i+1)<< ". ";
        cin >> a[i].TotRain;
        cout << "Enter the temperature high for the month "<<(i+1)<<". ";
        cin >> a[i].TempHigh;
        cout << "Enter the temperature low for the month "<<(i+1)<<". ";
        cin >> a[i].LowTemp;
        cout << endl;
    }
}