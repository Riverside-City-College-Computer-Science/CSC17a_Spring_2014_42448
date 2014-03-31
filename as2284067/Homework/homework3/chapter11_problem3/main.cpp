/* 
 * File:   main.cpp
 * Author: abel salazar
 * Created on March 26, 2014, 6:10 PM
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

//structures
struct Sales{
    string Division;
    float FirstQ;
    float SecondQ;
    float ThirdQ;
    float FourthQ;
    float Total;
    float Average;
};

//global constants

//function prototypes
void fillDat(Sales &);
void sumTot (Sales &);
void avTot  (Sales &);
void prntDat(const Sales);

//execution
int main(int argc, char** argv) {
    //variable declaration
    Sales West;  West.Division  = "West";
    Sales East;  East.Division  = "East";
    Sales North; North.Division = "North";
    Sales South; South.Division = "South";
    
    //populating the structure
    fillDat(West);
    fillDat(East);
    fillDat(North);
    fillDat(South);
    
    //finds the sum of each divisions quarter
    sumTot(West);
    sumTot(East);
    sumTot(North);
    sumTot(South);
    
    //finds the average of the quarters
    avTot(West);
    avTot(East);
    avTot(North);
    avTot(South);
    
    //prints out the data for the 4 divisions
    prntDat(West);
    prntDat(East);
    prntDat(North);
    prntDat(South);
    
    //exit stages
    return 0;
}

//prints data for 4 divisions
void prntDat(const Sales div){
    cout << endl;
    cout << fixed << setprecision(2) <<endl;
    cout << "Division |" << div.Division <<endl;
    cout << "1st qrtr |" << div.FirstQ <<endl;
    cout << "2nd qrtr |" << div.SecondQ <<endl;
    cout << "3rd qrtr |" << div.ThirdQ <<endl;
    cout << "4th qrtr |" << div.FourthQ <<endl;
    cout << "Total    |" << div.Total <<endl;
    cout << "Average  |" << div.Average <<endl;
}

//finds the average of the 4 quarter sales
void avTot(Sales & av){
    av.Average=av.Total/4;
}

//adds all of quarters together
void sumTot (Sales &tot){
    tot.Total = tot.FirstQ+tot.SecondQ+tot.ThirdQ+tot.FourthQ;
}

//gets input from the user in order from each division
//the division is predetermined when call is made for each division
void fillDat(Sales & div){
    cout <<endl;
    cout << "Entering " << div.Division << " division" << endl;
    cout << "Enter first quarter sales" << " ";
    cin >> div.FirstQ;
    cout << "Enter second quarter sales" << " ";
    cin >> div.SecondQ;
    cout << "Enter third quarter sales" << " ";
    cin >> div.ThirdQ;
    cout << "Enter fourth quarter sales" << " ";
    cin >> div.FourthQ;
    cout <<endl;
}
