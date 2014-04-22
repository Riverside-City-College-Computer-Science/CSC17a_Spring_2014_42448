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
    unsigned int slot, check, pword;
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
    //FOR NEW USER    
    //Prompt user to select save slot
        if(choice=='y'||choice=='Y'){
        //select save slot
            cout<<"Please select a save slot 1-3"<<endl;
            cin>>slot;

            //test if input is valid
            if(slot<1||slot>3){
                do{
                    //ask for input again
                    cout<<"Invalid input. select 1-3"<<endl;
                    cout<<"Please select a save slot 1-3"<<endl;;
                    cin>>slot;

                }while(slot<1||slot>3);
            }
            //test if save slot is already occupied
            if(user[slot-1].name!=0){
                do{
                    //ask for input again
                    cout<<"That slot already contains data."<<endl;
                    cout<<"Please choose another slot."<<endl;;
                    cin>>slot;

                }while(user[slot-1].name!=0);
            }
            
            //Prompt user to input data to be encrypted
            cout<<"New Account:"<<endl;
            cout<<"Input your name: ";
            cin>>temp;
            //send name to hash and save
            user[slot-1].name = ELFHash(temp);
            //Prompt user for new password
            cout<<"Input new password: ";
            cin>>temp;
            //send password to hash and save
            user[slot-1].pword = ELFHash(temp);
            //ask user for secret message to be encrypted
            cin.ignore();
            cout<<"Input secret message to be encrypted(140 characters or less): ";
            getline(cin, msg);
            //test string length
            
            //mess that string up
                 for (int i =0;i<msg.length();i++){
                 msg[i]+=70;
                 }
            //save encrypted message string
            user[slot-1].msg = msg;
            
            //Open appropriate file
            if(slot-1==0){
                usrFile.open("userinfo_1.txt",ios::out);
            }
            else if(slot-1==1){
                usrFile.open("userinfo_2.txt",ios::out);
            }
            else if(slot-1==2){
                usrFile.open("userinfo_3.txt",ios::out);
            }
            //write information to that file
            usrFile.clear();
            usrFile<<user[slot-1].name<<"\n"<<endl;
            usrFile<<setw(10)<<user[slot-1].pword<<"\n"<<endl;
            usrFile<<setw(140)<<user[slot-1].msg;
            //close the file
            usrFile.close();
            //Output successful file creation
        cout<<"New file created!"<<endl;
        cout<<endl;
        }
        
        //FOR EXISTING USERS
        //prompt user to log into their account
        cout<<"***PLEASE LOG IN***"<<endl;
        cout<<"REMEMBER IT'S CASE SENSITIVE!"<<endl;
        cout<<"Enter name: ";
        cin>>temp;
        //send to hash and compare with existing files
        check = ELFHash(temp);
        //test if file under such name exists
        if(check!=user[0].name&&check!=user[1].name&&check!=user[2].name){
            //inform user of error
            cout<<"Sorry, there is no user information under that name."<<endl;
            cout<<"Run the program again, making sure you spell your name correctly."<<endl;
            cout<<"Remember, its case sensitive."<<endl;
            cout<<"If you need to create an account, run the program again "<<endl;
            cout<<"and select Y for 'Are you a new user?'"<<endl;
            return true;
        }
        check=0;
        //set password check number
        pword = user[slot-1].pword;
        //Prompt for password
        cout<<"Password: ";
        cin>>temp;
        //send through hash and verify
        check = ELFHash(temp);
        if(check!=pword){
            do{
               //ask for input again
                cout<<"Invalid Password"<<endl;
                cout<<"Password: ";
                cin>>temp;
                check = ELFHash(temp);
                
            }while(check != pword);
            
        }
        
        //Ask user what they would like to do 
        cout<<"_________________MENU_________________"<<endl;
        cout<<endl;
        cout<<"1......Decrypt and view secret message"<<endl;
        cout<<"2................Change secret message"<<endl;
        cout<<"3..............................Log out"<<endl;
        

    return 0;
}

