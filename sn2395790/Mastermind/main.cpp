/* 
 * File:   main.cpp
 * Author: Scott Nevin
 * Purpose: Write the code breaking game, Mastermind 
 * Created on April 8, 2014, 10:53 AM
 */

//Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
using namespace std;

//Global Variables and constants

//Function prototypes
char rndDgit();
void prpCode(char[], int);

//Execution begins here
int main(int argc, char** argv) {
    
    //seed random number generator
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int SIZE=4;
    char code[SIZE];
    
    //get random code
    for(int i=0;i<1000;i++){
    prpCode(code, SIZE);
    
    //Display the code
    for(int i=0;i<4;i++){
        cout<<code[i];
    }
    //remove codes with 3 or 4 identical digits
    if(code[0]==code[1]&&code[1]==code[2]){
        cout<<" <----Fail";
    }
    else if(code[1]==code[2]&&code[2]==code[3]){
        cout<<" <----Fail";
    }
    else if(code[0]==code[1]&&code[1]==code[2]&&code[2]==code[3]){
        cout<<" <----Fail";
    }
    cout<<endl;
    }
    
    //Exit Stage right
    return 0;
}

//Generate random code and test for fairness
void prpCode(char code[], int n){
    
    //Generate 4 digit code, using only numbers 1 through 6
    for(int i=0;i<n;i++){
        code[i]=rndDgit();
    }
    //Put null terminator at the end
    for(int i=n;i<=n+1;i++){
        code[i]='\0';
    }
    
}

char rndDgit(){
    return rand()%6+49;
}