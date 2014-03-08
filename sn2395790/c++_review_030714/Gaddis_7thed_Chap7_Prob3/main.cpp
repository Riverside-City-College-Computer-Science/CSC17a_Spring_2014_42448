/* 
 * File:   main.cpp
 * Author: Scott Nevin
 * Purpose: Measure adn give stats for rainfall
 * Created on March 7, 2014
 */

//Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

//Global variables and constants

//Function prototypes
void getRain(string[], int[], int);
    int Total(int[], int);
    int Avg(int[], int);
    int highRain(int[], int);
    int lowRain(int[], int);

//Begin execution here
int main(int argc, char** argv) {

    //Declare Variables
        const int MONTH=12;
         int high, low, total, avg;

         //Array of salsa names
         string names[MONTH] = {"January", "February", "March", "April", "May",
         "June", "July", "August","September", "October", "November", "December"};

         //Array of rainfall
         int rain[MONTH];

         //Get number of jars sold
         getRain(names, rain, MONTH);

         //Get total rainfall, average rainfall and highest/lowest rainfall
         total = Total(rain, MONTH);
         avg = Avg(rain, MONTH);
         high = highRain(rain, MONTH);
         low = lowRain(rain, MONTH);

         //Display sales report header
         cout<<endl<<endl;
         cout<<"          Rainfall Report \n\n";
         cout<<"   Month                Rainfall (inches) \n";
         cout<<"______________________________________ \n";

         //Display name and jars sold
         for (int type = 0; type < MONTH; type++){

             cout<<setw(10)<<names[type]<<setw(24)<<rain[type]<<endl;
         }

         //Display total sales and high/low
         cout<<"\nTotal Rainfall:"<<setw(19)<<total<<endl;
         cout<<"Average rainfall per month: "<<setw(6)<<avg<<endl;
         cout<<"Highest rainfall month: "<<names[high]<<endl;
         cout<<"Lowest rainfall month  : "<<names[low]<<endl;


        //Exit Stage Right
        return 0;
}

void getRain(string names[], int rain[], int size){

        for (int type = 0; type < size; type++){

            //Get amount of rain
            cout<<"How many inches of rain were there in "<<names[type]<<"?"<<endl;
            cin>>rain[type];

            //validate input
            while (rain[type] < 0){

                cout<<"Rainfall must be 0 or more. Please re-enter: ";
                cin>>rain[type];
            }
        }
    }

int Total(int array[], int size){

        int total = 0;

        for (int pos = 0; pos < size; pos++)
            total += array[pos];

        return total;
    }

int Avg(int array[], int size){

        int total = 0;
        int avg;

        for (int pos = 0; pos < size; pos++){
            total += array[pos];
        }
        avg = total / 12;

        return avg;
    }

int highRain(int array[], int SIZE){

        int highIndx = 0;

        for (int pos = 1; pos < SIZE; pos++){

            if (array[pos] > array[highIndx])
                highIndx = pos;
        }
        return highIndx;

    }
int lowRain(int array[], int SIZE){

        int lowIndx = 0;

        for (int pos = 1; pos < SIZE; pos++){

            if (array[pos] < array[lowIndx])
                lowIndx = pos;
        }
        return lowIndx;
}