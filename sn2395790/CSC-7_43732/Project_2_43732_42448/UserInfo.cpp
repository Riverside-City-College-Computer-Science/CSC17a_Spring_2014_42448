/* 
 * File:   UserInfo.h
 * Author: Scott Nevin
 * Created on June 8, 2014, 6:05 PM
 */

//Include system Libraries
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>
using namespace std;

//Include user libraries
#include "UserInfo.h"

//constructor
void UserInfo::setName(int i){
    //input user name into class
    name = i;
    
}
void UserInfo::setPword(int i){
    //set user password to class
    pword = i;
}
void UserInfo::setMsg(string i){
    //set user secret message to class
    msg = i;
}
void UserInfo::setSlot(int i){
    //set user slot number to class
    slot = i;
}

void UserInfo::erase(){
    
    //erase user's data from files
    name = 0;
    pword = 0;
    msg = ' ';
    cout<<"Deleting information..."<<endl;
    
}

void UserInfo::write(){
    
    //Declare file stream
            ofstream usrFile;
    
            //Open appropriate file
            if(slot==1){
                usrFile.open("userinfo_1.txt",ios::out);
            }
            else if(slot==2){
                usrFile.open("userinfo_2.txt",ios::out);
            }
            else if(slot==3){
                usrFile.open("userinfo_3.txt",ios::out);
            }
            //write information to that file
            usrFile.clear();
            usrFile<<name<<"\n"<<endl;
            usrFile<<setw(10)<<pword<<"\n"<<endl;
            usrFile<<setw(140)<<msg;
            //close the file
            usrFile.close();
            //Output successful file creation
            cout<<endl;
            cout<<"File written!"<<endl;
            cout<<endl;
    
}

