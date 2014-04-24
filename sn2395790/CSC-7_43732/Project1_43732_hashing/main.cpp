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
int getSLot();//find the memory slot of existing user
string getMsg();//takes in new user secret message and encrypts it
void write(int, int, int, string);//write new user information to a file
int logIn(int, int, int, int, int, int);//for all users to log into their accounts

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
    int slot=0, check, pword, flA, flB, flC, menu;
    fstream usrFile;
    bool login=false;
    
    //bring in all user data for testing
        //File 1
        usrFile.open("userinfo_1.txt",ios::in);
        usrFile>>user[0].name;
        usrFile>>user[0].pword;
        usrFile>>user[0].msg;
        //close the file
        usrFile.close();
        //File 2
        usrFile.open("userinfo_2.txt",ios::in);
        usrFile>>user[1].name;
        usrFile>>user[1].pword;
        usrFile>>user[1].msg;
        //close the file
        usrFile.close();
        //File 3
        usrFile.open("userinfo_3.txt",ios::in);
        usrFile>>user[2].name;
        usrFile>>user[2].pword;
        usrFile>>user[2].msg;
        //close the file
        usrFile.close();
        
        //initialize structure element variables
        //to save space when sending to functions
        flA = user[0].name;
        flB = user[1].name;
        flC = user[2].name;
        
        //Get if user is new or not
        choice = askNew();
        
        if(choice=='y'||choice=='Y'){
            
            //if all data spaces taken, exit program
            if(flA!=0&&flB!=0&&flC!=0){
                
                //Display bad news
                cout<<"Unfortunately, all data slots are taken."<<endl;
                cout<<"This program cannot accept any new users at this time"<<endl;
                cout<<"If you already have an account, please restart the program and log in"<<endl;
                return true;
            }
            //ask user for slot choice
            slot = slotChs(flA, flB, flC);

            //get user name
            user[slot-1].name = getName();

            //get user password
            user[slot-1].pword = getPword();

            //get secret message
            user[slot-1].msg = getMsg();

            //write new info to file
            write(user[slot-1].name, user[slot-1].pword, slot, user[slot-1].msg);

            cout<<endl;
            slot = slot-1;
        }
        
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
        
        //FOR EXISTING USERS
        if(choice=='n'||choice=='N'){
        slot = logIn(user[0].name, user[1].name, user[2].name, user[0].pword, user[1].pword, user[2].pword);
        }
        
        if(slot==5){
            return 1;
        }
        else{
            //Display Menu
            //Ask user what they would like to do 
            do{
                cout<<"_________________MENU_________________"<<endl;
                cout<<endl;
                cout<<"1......Decrypt and view secret message"<<endl;
                cout<<"2................Change secret message"<<endl;
                cout<<"3..............................Log out"<<endl;
                cout<<"Please select a menu item...";
                cin>>choice;
                
                //Validate input
                if(choice<'1'||choice>'3'){
                do{
                    //ask for input again
                    cout<<"Invalid input. select 1-3"<<endl;
                    cout<<"Please select an option 1-3"<<endl;
                    cin>>choice;

                }while(choice<'1'||choice>'3');
            }
                
                //Proccess decryption or rewriting of secret message
                if(choice=='1'){
                    cout<<"Encrypted message:"<<endl;
                    cout<<user[slot].msg<<endl;
                    cout<<"Decrypted message:"<<endl;
                    
                    //decrpytion
                    msg = user[slot].msg;
                    for (int i=0;i<msg.length();i++){
                         if(i%2==0){
                            msg[i]-=28;
                        }
                         else{
                           msg[i]-=37;
                        }
                    }
                    //display message
                    cout<<msg<<endl;
                }
                
                //Process new message encryption and writing
                else if(choice=='2'){
                    
                    //decrpytion
                    msg = user[slot].msg;
                    for (int i=0;i<msg.length();i++){
                         if(i%2==0){
                             msg[i]-=28;
                        }
                        else{
                             msg[i]-=37;
                     }
                    }
                    //output old message and prompt for new one
                    cout<<"Old message: ";
                    cout<<msg<<endl;
                    cout<<"Enter new message:"<<endl;
                    cin.ignore();
                    getline(cin, msg);
                    
                    //encrypt and rewrite file
                    for(int i=0;i<msg.length();i++){
                        if(i%2==0){
                              msg[i]+=28;
                        }
                        else{
                             msg[i]+=37;
                        }
                    }
                    user[slot].msg = msg;
                    
                    //rewrite file using write function
                    write(user[slot].name,user[slot].pword, slot+1,user[slot].msg);
                    
                    //output success
                    cout<<"New message encrypted and saved."<<endl;
                }
                
            }while(choice!='3');

        }

    //Exit stage right
    return 0;
}

int logIn(int an, int bn, int cn, int ap, int bp, int cp){
    
    //declare variables
    string temp;
    int check, pword, slot=0;
    
    //prompt user to log into their account
    cout<<"***PLEASE LOG IN***"<<endl;
    cout<<"REMEMBER IT'S CASE SENSITIVE!"<<endl;
    cout<<"Enter name: ";
    cin.ignore();
    getline(cin, temp);
    
    //send to hash and compare with existing files
    check = ELFHash(temp);
    
    //test if file under such name exists
    if(check!=an && check!=bn && check!=cn){
        //inform user of error
        cout<<"Sorry, there is no user information under that name."<<endl;
        cout<<"Run the program again, making sure you spell your name correctly."<<endl;
        cout<<"Remember, its case sensitive."<<endl;
        cout<<"If you need to create an account, run the program again "<<endl;
        cout<<"and select Y for 'Are you a new user?'"<<endl;
        slot = 5;//my equivalent for "return true" at this point
    }
    if(slot!=5){
        //reinitialize slot variable with slot of current user
        if(check==an){
            slot = 0;
        }
        else if(check==bn){
            slot = 1;
        }
        else if(check==cn){
            slot = 2;
        }

        //set password check number
        if(slot==0){
            pword = ap;
        }
        else if(slot==1){
            pword = bp;
        }
        else if(slot==2){
            pword = cp;
        }

        //Prompt for password
        cout<<"Password: ";
        cin>>temp;

        //send through hash
        check = ELFHash(temp);

        //test password
        if(check!=pword){
            do{
               //ask for input again
                cout<<"Invalid Password"<<endl;
                cout<<"Password: ";
                cin>>temp;
                check = ELFHash(temp);

            }while(check != pword);

        }
    }
    return slot;

}

void write(int n, int p, int slot, string m){
    
            //Declare file stream
            ofstream usrFile;
    
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
            usrFile<<n<<"\n"<<endl;
            usrFile<<setw(10)<<p<<"\n"<<endl;
            usrFile<<setw(140)<<m;
            //close the file
            usrFile.close();
            //Output successful file creation
            cout<<endl;
            cout<<"File written!"<<endl;
            cout<<endl;
    
}

string getMsg(){
    
    //initialize temporary variables
    string msg;
    
    //prompt user for secret message
    cout<<"Input secret message: "<<endl;
    cin.ignore();
    getline(cin, msg);
    
    //encrypt string
    for (int i=0;i<msg.length();i++){
        
        if(i%2==0){
            msg[i]+=28;
        }
        else{
            msg[i]+=37;
        }
    }
    
    return msg;

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