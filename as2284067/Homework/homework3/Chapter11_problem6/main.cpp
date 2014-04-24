/* 
 * File:   main.cpp
 * Author: abel salazar
 * Created on March 26, 2014, 9:14 PM
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

//structures
struct Soccer{
    string Name;
    int Number;
    int Points;
};

//global constants

//function prototypes
void fillDat(Soccer [], int);
void sum(Soccer [], Soccer [],int);
void prntDat(const Soccer [],const Soccer [], int);


//execution
int main(int argc, char** argv) {
    //variable declaration
    const int SIZE = 12;
    const int n = 1;
    Soccer team [SIZE];
    Soccer total[n];
    
    fillDat(team,SIZE);
    sum(team,total,SIZE);
    prntDat(team,total,SIZE);
    
    //exit stage
    return 0;
}

//prints names, numbers and points scored by each player
void prntDat(const Soccer a[],const Soccer b[], int size){
    cout << endl;
    for(int i=0;i<size;i++){
        cout << "Player name:   " << a[i].Name <<endl;
        cout << "Player number: " << a[i].Number <<endl;
        cout << "Player Points: " << a[i].Points <<endl;
    }
    cout << endl;
    
    cout << "Total point scored: " << b[0].Points <<endl;
}


//adds the points from one array and puts the total in a second array of 1
void sum(Soccer a[], Soccer b[],int size){
    b[0].Points = 0;
    for(int j=0;j<size;j++){
        b[0].Points+=a[j].Points;
    }
}

//fills array of structures with user input
void fillDat(Soccer a[], int n){
    
    for(int i=0;i<n;i++){
        cout << endl;
        cout << "Enter the player's name" << ": ";
        cin >> a[i].Name;
        cout << "Enter the player's number" << ": ";
        cin >> a[i].Number;
        cout << "Enter the player's points scored" << ": ";
        cin >> a[i].Points;
        cout << endl;
    }
}