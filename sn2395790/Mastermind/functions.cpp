/* 
 * File:   functions.cpp
 * Author: Scott Nevin
 * Purpose: Functions for mastermind program 
 * Created on April 8, 2014, 10:53 AM
 */

//System libraries
#include <cstdlib>
#include <iostream>
#include <string>
#include "functions.h"
using namespace std;

//function that tests if user's guess is totally correct
bool tstWin(char r[]){
    
    //test if code is correct
    if(r[0]=='X'&&r[1]=='X'&&r[2]=='X'&&r[3]=='X') return false;
    else 
        return true;
}
//Function that tests user's guess and gives user feedback
void tstGess(char g[], char c[], char a[], char r[], int n){
    
    //declare temporary symbol array counter
    int y = 0;
    
    //initialize symbol array with blank spaces
    for(int i=0;i<n;i++){
        r[i]='_';
    }
    //Put null terminator at the end of symbol array
        for(int i=n;i<=n+1;i++){
            r[i]='\0';
        }
    //test if any digits are correct in position and value
    for(int i=0;i<n;i++){
        if(g[i]==c[i]){
            r[y]='X';
            //give guess and code indeces new values
            //this will prevent them being checked again
            g[i]=0;
            c[i]=7;
            //if symbol array is used, increment array space
            y++;
        }
    }
    //test if any values are valid (incorrect position)
    for(int i=0;i<n;i++){
        if(g[i]==c[0]||g[i]==c[1]||g[i]==c[2]||g[i]==c[3]){
            r[y]='0';
            //give guess and code indeces new values
            //this will prevent them being checked again
            g[i]=0;
            c[i]=7;
            y++;
        }
    }
    //reset values in index array
    for(int i=0;i<n;i++){
        c[i]=a[i];
    }
    
}

//accept user's guess
void usrGess(char g[], int n){
    
    //declare temporary guess string
    string temp;
    
    //prompt user for guess
    cout<<"Input your guess:";
    cin>>temp;
    
    //convert the string to the guess array
    for(int i=0;i<n;i++){
        g[i]=temp[i];
    }
    //Put null terminator at the end
        for(int i=n;i<=n+1;i++){
            g[i]='\0';
        }
}

//Generate random code and test for fairness
void prpCode(char code[], char index[], int n){
    
    //declare bool value for number testing
    bool badnum;
    
    //loop number generator until an acceptable code is generated
    do{
        //Generate 4 digit code, using only numbers 1 through 6
        for(int i=0;i<n;i++){
            code[i]=rndDgit();
        }
        //Put null terminator at the end
        for(int i=n;i<=n+1;i++){
            code[i]='\0';
        }
        //test if number is acceptable
        //reject if first three digits are identical
        if(code[0]==code[1]&&code[1]==code[2]) badnum = true;
        //reject if last three digits are identical
        else if(code[1]==code[2]&&code[2]==code[3])badnum = true;
        //reject if all digits are identical
        else if(code[0]==code[1]&&code[1]==code[2]&&code[2]==code[3]) badnum = true;
        else badnum = false;
        
    }while(badnum==true);
    
    //Create index
        for(int i=0;i<n;i++){
            index[i]=code[i];
        }
        //Put null terminator at the end
        for(int i=n;i<=n+1;i++){
            index[i]='\0';
        }
    
    
}

//Random digit generator
char rndDgit(){
    return rand()%6+49;
}
