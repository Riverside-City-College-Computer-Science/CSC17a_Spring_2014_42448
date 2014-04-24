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
char askNew();//asks user if they are new and returns the answer
int slotChs(int, int, int);//user chooses an available memory space
int getName();//takes in new user name
int getPword();//takes in new user password
string getMsg();//takes in new user secret message and encrypts it

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
    int slot, check, pword, flA, flB, flC;
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
        
        //initialize availability variables
        flA = user[0].name;
        flB = user[1].name;
        flC = user[2].name;
        
        //Get if user is new or not
        choice = askNew();
        
        if(choice=='y'||choice=='Y'){
        //ask user for slot choice
        slot = slotChs(flA, flB, flC);
        
        //get user name
        user[slot-1].name = getName();
        
        //get user password
        user[slot-1].pword = getPword();
        
        //get secret message
        user[slot-1].msg = getMsg();
        
        }

    //Exit stage right
    return 0;
}

string getMsg(){
    
    //initialize temporary variables
    string msg;
    
    //prompt user for secret message
    cout<<"Input secret message: "<<endl;
    getline(cin, msg);
    
    //encrypt string
    for (int i=0;i<msg.length();i++){
        msg[i]+=72;
    }

}

int getPword(){
    
    //initialize temporary variable
    string temp;
    int pword;
    
    //Prompt user for password
    cout<<"Enter new Password: ";
    cin>>temp;
    
    //Send name to hash function for encryption
    pword = ELFHash(temp);
    
    return pword;
}

int getName(){
    
    //initialize temporary variable
    string temp;
    int name;
    
    //Prompt user for name
    cout<<"Enter name for new account: ";
    cin>>temp;
    
    //Send name to hash function for encryption
    name = ELFHash(temp);
    
    return name;
}

int slotChs(int a, int b, int c){
    
    //Declare variables
    int slot;
    int temp;//temporary storage of availability
    
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
            
            //set temporary check variable to file availability
            if(slot==1){
                temp = a;
            }
            else if(slot==2){
                temp = b;
            }
            else if(slot==3){
                temp = c;
            }
            //test if save slot is already occupied
            if(temp!=0){
                do{
                    //ask for input again
                    cout<<"That slot already contains data."<<endl;
                    cout<<"Please choose another slot."<<endl;
                    cin>>slot;
                    
                        if(slot==1){
                    temp = a;
                    }
                    else if(slot==2){
                        temp = b;
                    }
                    else if(slot==3){
                        temp = c;
                    }
                }while(temp!=0);
            }
            return slot;

}

char askNew(){
    
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