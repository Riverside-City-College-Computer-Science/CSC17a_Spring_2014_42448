/* 
 * File:   main.cpp
 * Author: Scott Nevin
 * Purpose: Use basic hash functions to encrypt and save user log in data
 * for use with future log ins
 * Created on April 8, 2014, 10:06 AM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "GeneralHashFunctions.h"
using namespace std;

//Global Variables and Constants

//Function Prototypes
char newUsr();
int slotChs(int, int, int);

//Initialize structure for user data
struct info{
    int name;
    int pword;
    string msg;
};

//Execution begins here
int main(int argc, char** argv) {
    
    //declare variables
    string msg, temp;
    info user[3];//array of structures for user data
    char choice;
    int slot, check, pword;
    fstream usrFile;
    
    //bring in all user data for testing
        //File 1
        usrFile.open("userinfo_1.txt",ios::in);
        usrFile>>user[0].name;
        usrFile>>user[0].pword;
        //close the file
        usrFile.close();
        //File 2
        usrFile.open("userinfo_2.txt",ios::in);
        usrFile>>user[1].name;
        usrFile>>user[1].pword;
        //close the file
        usrFile.close();
        //File 3
        usrFile.open("userinfo_3.txt",ios::in);
        usrFile>>user[2].name;
        usrFile>>user[2].pword;
        //close the file
        usrFile.close();
        
        //Get if user is new or not
        choice = newUsr();
        
        if(choice=='y'||choice=='Y'){
        //ask user for slot choice
        slot = slotChs();
        
        }


    return 0;
}

int slotChs(int a[]){
    
    //Declare slot variable
    int slot;
    
            //select save slot
            cout<<"Please select a save slot 1-3"<<endl;
            cin>>slot;

            //test if input is valid
            if(slot<1||slot>3){
                do{
                    //ask for input again
                    cout<<"Invalid input. select 1-3"<<endl;
                    cout<<"Please select a save slot 1-3"<<endl;
                    cin.ignore();
                    cin>>slot;

                }while(slot<1||slot>3);
            }
            //test if save slot is already occupied
            if(user[slot-1].name!=0){
                do{
                    //ask for input again
                    cout<<"That slot already contains data."<<endl;
                    cout<<"Please choose another slot."<<endl;
                    cin.ignore();
                    cin>>slot;

                }while(user[slot-1].name!=0);
            }

}

char newUsr(){
    
    //declare temporary choice variable
    char choice;
    
    //Ask if user is new
        cout<<"Are you a new user? y/n"<<endl;
        cin>>choice;
        
            //test if user input is valid
        if(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n'){
            do{
                //ask for input again
                cout<<"Invalid input. select y or n"<<endl;
                cout<<"Are you a new user? y/n"<<endl;
                cin>>choice;
                
            }while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n');
        }
        return choice;
}