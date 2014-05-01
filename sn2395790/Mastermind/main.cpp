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
#include <windows.h>
using namespace std;

//Global Variables and constants.

//Function Prototypes
#include "functions.h"

//Execution begins here
int main(int argc, char** argv) {
    
    //seed random number generator
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int SIZE=4, ply=0, tries, temp;
    char code[SIZE], index[SIZE], guess[SIZE], symb[SIZE], choice;
    bool win = true;
    
    //Loop game
    do{
        //initialize tries again
        tries = 12;
        ply=0;
        
        //show menu and prompt user for option 
        choice = menu();
        
        //begin game if user selected so
        if(choice==1){
            //generate random code
            prpCode(code, index, SIZE);
            
            //output small key for user 
                cout<<"\nKey: "<<endl;
                cout<<"    X -> correct number, correct position"<<endl;
                cout<<"    0 -> correct number, incorrect position"<<endl;
                cout<<"    _ -> number not in code or duplicate number detected"<<endl;
                cout<<"\nRemember: Position of symbols in feedback does NOT "<<endl;
                cout<<"          correspond to position of numbers in code."<<endl;
                cout<<"You have 12 guesses remaining\n"<<endl;

            //initiate loop for user input
            do{
                
                //Prompt user for guess
                usrGess(guess, SIZE);

                //test user's guess
                tstGess(guess, index, code, symb, SIZE);

                //output results array
                for(int i=0;i<SIZE;i++){
                    cout<<symb[i]<<" ";
                }
                cout<<endl;
                ply++;
                //set win bool variable
                win = tstWin(symb);

            }while(ply<tries&&win==true);

            //output victory or defeat
            if(win==false){
                cout<<"CODE CRACKED!"<<endl;
            }
            else cout<<"You did not win"<<endl;

            //output code
            for(int i=0;i<SIZE;i++){
                cout<<code[i];
            }
            cout.flush()<<" was the code"<<endl;
            Sleep(500);
            
            if(win==true){
            //press enter to continue
            cout<<"Press ENTER to continue..."<<endl;
            cin.get();
            //cin.get()
            }
            
            //send player to high scores function
            if(win==false){
                
                score(ply);
            
                //press enter to continue
                cout<<"Press ENTER to continue..."<<endl;
                cin.get();
                //cin.get();
            }     
        }
        //output rules 
        if(choice==2){
            rules();
            //press enter to continue
            cout<<"Press ENTER to continue..."<<endl;
            cin.get();
            //cin.get();
        }
        if(choice==3){
            score(0);
            //press enter to continue
            cout<<"Press ENTER to continue..."<<endl;
            cin.get();
            //cin.get();
        }
        
        //exit game
    }while(choice!=4);   
    
    //Exit Stage right
    return 0;
}
