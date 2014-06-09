/* 
 * File:   main.cpp
 * Author: Scott Nevin
 * Purpose: Use basic hash functions to encrypt and save user log in data
 * for use with future log ins
 * Created on April 8, 2014, 10:06 AM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include "GeneralHashFunctions.h"
#include "UserInfo.h"
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
//Function prototypes for MASTERMIND
char rndDgit();//random digit generator
void prpCode(char[], char[], int);//generates and tests code before gameplay
void usrGess(char[], int);//accepts user input during gameplay
void tstGess(char[], char[], char [], char[], int);//tests user's guess against the code
bool tstWin(char[]);//tests if code is 100% correct in order to break loop
int menuM();//Displays menu and collects user's decision 
void score(int);//writes user high score to a file and displays high score
void rules();//displays rules to the game

//Initialize structure for user data
struct info{
    int name;
    int pword;
    string msg;
};
//Initialize structure for high scores
struct highscore{
    string name;
    int score;
};

//Execution begins here
int main(int argc, char** argv) {
    
    //seed random number generator
    srand(static_cast<unsigned int>(time(0)));
    
    //declare variables
    string msg, temp;
    info user[3];//array of structures for user data
    char choice;
    int slot=0, check, pword, flA, flB, flC, menu;
    fstream usrFile;
    bool login=false;
    UserInfo current;
    //Declare Variables for MASTERMIND
    int SIZE=4, ply=0, tries, tempM;
    char code[SIZE], index[SIZE], guess[SIZE], symb[SIZE], choiceM;
    bool win = false;
    
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
            
            try{
                //if all data spaces taken, exit program
                if(flA!=0&&flB!=0&&flC!=0)throw 1;
            }
            catch(int i){
                
                if(i==1){
                    //Display bad news
                    cout<<"Unfortunately, all data slots are taken."<<endl;
                    cout<<"This program cannot accept any new users at this time"<<endl;
                    cout<<"If you already have an account, please restart the program and log in"<<endl;
                    return true;
                }
            }
            //ask user for slot choice
            slot = slotChs(flA, flB, flC);
            //set slot choice to class
            current.setSlot(slot);

            //get user name
            user[slot-1].name = getName();
            //set name to class
            current.setName(user[slot-1].name);

            //get user password
            user[slot-1].pword = getPword();
            //set password to class
            current.setPword(user[slot-1].pword);

            //get secret message
            user[slot-1].msg = getMsg();
            //set message to class
            current.setMsg(user[slot-1].msg);

            //write new info to file
            current.write();
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
        try{
            if(choice=='n'||choice=='N'){
            slot = logIn(user[0].name, user[1].name, user[2].name, user[0].pword, user[1].pword, user[2].pword);
            cout<<"slot in use: "<<slot<<endl;
            current.setSlot(slot);
            if(slot==5)throw 1;
            }
        }
        catch(int i){
            if(i== 1) {
                cout<<" \n Program Ended..."<<endl;
                return 1;
            }
        }

            //Display Menu
            //Ask user what they would like to do 
            do{
                cout<<"_________________MENU_________________"<<endl;
                cout<<endl;
                cout<<"1......Decrypt and view secret message"<<endl;
                cout<<"2................Change secret message"<<endl;
                cout<<"3......................Play Mastermind"<<endl;
                cout<<"4.......................Delete account"<<endl;
                cout<<"5..............................Log out"<<endl;
                cout<<"Please select a menu item...";
                cin>>choice;
                
                //Validate input
                if(choice<'1'||choice>'5'){
                do{
                    //ask for input again
                    cout<<"Invalid input. select 1-5"<<endl;
                    cout<<"Please select an option 1-5"<<endl;
                    cin>>choice;

                }while(choice<'1'||choice>'5');
            }
                
                //Proccess decryption or rewriting of secret message
                if(choice=='1'){
                    cout<<"Encrypted message:"<<endl;
                    cout<<user[slot-1].msg<<endl;
                    cout<<"Decrypted message:"<<endl;
                    
                    //decrpytion
                    msg = user[slot-1].msg;
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
                    user[slot-1].msg = msg;
                    current.setMsg(user[slot-1].msg);
                    
                    //rewrite file using write function
                    //write(user[slot].name,user[slot].pword, slot+1,user[slot].msg);
                    current.write();
                    
                    //output success
                    cout<<"New message encrypted and saved."<<endl;
                }
                
                if(choice=='3'){
                       //MASTERMIND
                    //Loop game
                    do{
                        //initialize tries again
                        tries = 12;
                        ply=0;

                        //show menu and prompt user for option 
                        choiceM = menuM();

                        //begin game if user selected so
                        if(choiceM==1){
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

                            }while(ply<tries&&win==false);

                            //output victory or defeat
                            if(win==true){
                                cout<<"CODE CRACKED!"<<endl;
                            }
                            else cout<<"You did not win"<<endl;

                            //output code
                            for(int i=0;i<SIZE;i++){
                                cout<<code[i];
                            }
                            cout.flush()<<" was the code"<<endl;
                            Sleep(500);

                            if(win==false){
                            //press enter to continue
                            cout<<"Press ENTER to continue..."<<endl;
                            cin.get();
                            cin.get();
                            }

                            //send player to high scores function
                            if(win==true){

                                score(ply);

                                //press enter to continue
                                cout<<"Press ENTER to continue..."<<endl;
                                cin.get();
                                cin.get();
                            }     
                        }
                        //output rules 
                        if(choiceM==2){
                            rules();
                            //press enter to continue
                            cout<<"Press ENTER to continue..."<<endl;
                            cin.get();
                            cin.get();
                        }
                        if(choiceM==3){
                            score(ply);
                            //press enter to continue
                            cout<<"Press ENTER to continue..."<<endl;
                            cin.get();
                            cin.get();
                        }

                        //exit game
                    }while(choiceM!=4);
                }
                
                if(choice=='4'){
                    
                    //Delete user data from file
                    current.erase();
                    current.write();
                }
                
                //EXIT PROGRAM
            }while(choice!='5');


    //Exit stage right
    return 0;
}

int logIn(int an, int bn, int cn, int ap, int bp, int cp){
    
    //declare variables
    string temp;
    int check, pword, slot=0, fail=1;
    
    //prompt user to log into their account
    cout<<"***PLEASE LOG IN***"<<endl;
    cout<<"REMEMBER IT'S CASE SENSITIVE!"<<endl;
    cout<<"Enter name: ";
    cin.ignore();
    getline(cin, temp);
    
    //send to hash and compare with existing files
    check = ELFHash(temp);
    
    //test if file under such name exists USING EXCEPTIONS
    try{
        if(check!=an && check!=bn && check!=cn)throw 5;
    }
    catch(int i){
        
        //inform user of error
            cout<<"Sorry, there is no user information under that name."<<endl;
            cout<<"Run the program again, making sure you spell your name correctly."<<endl;
            cout<<"Remember, its case sensitive."<<endl;
            cout<<"If you need to create an account, run the program again "<<endl;
            cout<<"and select Y for 'Are you a new user?'"<<endl;
            slot = i;
    }
    
    //set current user name to class
    //current.setWName(temp);
    
    if(slot!=5){
        //reinitialize slot variable with slot of current user
        if(check==an){
            slot = 1;
        }
        else if(check==bn){
            slot = 2;
        }
        else if(check==cn){
            slot = 3;
        }

        //set password check number
        if(slot==1){
            pword = ap;
        }
        else if(slot==2){
            pword = bp;
        }
        else if(slot==3){
            pword = cp;
        }

        //Prompt for password
        cout<<"Password: ";
        cin>>temp;

        //send through hash
        check = ELFHash(temp);
        
        //attempt to test and use exceptions
        try{
            //test password
            if(check!=pword){
                do{
                   //ask for input again
                    cout<<"Invalid Password"<<endl;
                    cout<<"Password: ";
                    cin>>temp;
                    check = ELFHash(temp);
                    fail++;
                    //if too many attempts were taken, kick user out
                    if(fail==10) throw 5;
                }while(check != pword);
            }
        }
        catch(int i){
            //display that user is out of attempts
            cout<<"MAXIMUM PASSWORD ATTEMPTS REACHED"<<endl;
            cout<<"EXIT AND TRY AGAIN..."<<endl;
            slot = i;
        }
    }
    return slot;

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

//Functions for MASTERMIND
//display rules
void rules(){
    
    //Display everything the user needs to know about playing
    cout<<"\n                                    Welcome to Mastermind!"<<endl;
    cout<<"   In Mastermind, you will try to break a 4 digit secret code, chosen by the computer. The digits in"<<endl;
    cout<<" the code will range from 1 to 6, you will have to guess what the digits are in the code, as well as"<<endl;
    cout<<" putting them in their correct positions. There may be two, or even three of the same digit. After  "<<endl;
    cout<<" every guess you will receive Feedback from the computer as to how accurate your guess was.         "<<endl;
    cout<<" The Feedback:"<<endl;
    cout<<"   Feedback will be given in the form of a few symbols. X means that a number is a correct value and"<<endl;
    cout<<" is also in it's correct position. 0 means that a value is correct, but not in the correct spot. A _"<<endl;
    cout<<" means that a number does not belong in the code at all. It sounds easy, but be careful, because the"<<endl;
    cout<<" position of the symbols in the feedback does NOT correspond to the number you entered in that space."<<endl;
    cout<<" For example:  you enter: 5247, and receive: X00_ as feedback. This does NOT mean that the number 5  "<<endl;
    cout<<" in in it's correct position, it could be any of the numbers. Also the two 0's could mean that the "<<endl;
    cout<<" 4 and 7 are in incorrect positions. That's it! Good Luck!\n"<<endl;
}

//show and write high scores
void score(int n){
    //declare file variables
    string name, tempN;
    int tempI;
    fstream scoreFile;
    highscore scores[11];
    
    //High scores 
        //read in high scores from file
         scoreFile.open("highscores.txt",ios::in);

         //bring in values from file
         for(int i=0;i<10;i++){

             scoreFile>>scores[i].name;
             scoreFile>>scores[i].score;
         }
         //Close file
         scoreFile.close();

         //test users new score
         if(n<scores[9].score&&n>0){

             cout<<"\nNew High Score!"<<endl;
             cout<<"Input name:  ";
             cin.ignore();
             getline(cin, name);

             //set new score to 11th spot in array
             scores[10].name = name;
             scores[10].score = n;

             //sort scores
             for(int i = 10; i>0;i--){
                 if (scores[i].score < scores[i-1].score){
                     //sort scores
                     tempI = scores[i].score;
                     scores[i].score = scores[i-1].score;
                     scores[i-1].score = tempI;

                     //sort names
                     tempN = scores[i].name;
                     scores[i].name = scores[i-1].name;
                     scores[i-1].name = tempN;
                 }
             }
         }

         //Open file for writing
         scoreFile.open("highscores.txt", ios::out);

         //Clear file for writing
         scoreFile.clear();

         //write scores to file
         for(int i = 0; i<11;i++){
             scoreFile<<scores[i].name<<setw(15)<<scores[i].score<<endl;
         }

         //close that file
         scoreFile.close();
        

         //output high scores
         cout<<"Records for least attempts to crack the code!\n"<<endl;
         cout<<"NAME          ATTEMPTS"<<endl;
         for(int i=0; i<10;i++){
         cout<<setw(15)<<left<<scores[i].name<<scores[i].score<<endl;
         }
}
//Menu
int menuM(){
    
    int n;
    
    //Output title
    cout<<"   __   __  _______  _______  _______  _______  ______    __   __  ___   __    _  ______   __  "<<endl;
    cout<<"  |  |_|  ||   _   ||       ||       ||       ||    _ |  |  |_|  ||   | |  |  | ||      | |  | "<<endl;
    cout<<"  |       ||  |_|  ||  _____||_     _||    ___||   | ||  |       ||   | |   |_| ||  _    ||  | "<<endl;
    cout<<"  |       ||       || |_____   |   |  |   |___ |   |_||_ |       ||   | |       || | |   ||  | "<<endl;
    cout<<"  |       ||       ||_____  |  |   |  |    ___||    __  ||       ||   | |  _    || |_|   ||__| "<<endl;
    cout<<"  | ||_|| ||   _   | _____| |  |   |  |   |___ |   |  | || ||_|| ||   | | | |   ||       | __  "<<endl;
    cout<<"  |_|   |_||__| |__||_______|  |___|  |_______||___|  |_||_|   |_||___| |_|  |__||______| |__| "<<endl;
    cout<<"\n                          ______________________________________"<<endl;
    cout<<"                         |       PLEASE SELECT AN OPTION:       |"<<endl;
    cout<<"                         |       1. PLAY GAME                   |"<<endl;
    cout<<"                         |       2. VIEW RULES                  |"<<endl;
    cout<<"                         |       3. VIEW HIGH SCORES            |"<<endl;
    cout<<"                         |       4. EXIT                        |"<<endl;
    cout<<"                         |______________________________________|"<<endl;
    
    //Collect user's choice
    cin>>n;
    
    //validate selection
    if(n<1||n>4){
        do{
            cout<<"INVALID CHOICE"<<endl;
            cout<<"Select 1, 2, 3, or 4"<<endl;
            cin>>n;
        }while(n<1||n>4);
    }
    
    return n;
}
//function that tests if user's guess is totally correct
bool tstWin(char r[]){
    
    try{
        //test if code is correct
        if(r[0]=='X'&&r[1]=='X'&&r[2]=='X'&&r[3]=='X')throw 1;
    }
    catch(int i){
        if(i==1)return true;
        else return false;
    }
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
    
    if(temp.length()!=4){
        do{
            cout<<"Invalid guess"<<endl;
            cout<<"Enter a 4 digit code: ";
            cin>>temp;
            
        }while(temp.length()!=4);
    }
    
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
    
    //output a bunch of fancy stuff for code generation
    cout.flush()<<"GENERATING CODE";
    for(int i=0;i<4;i++){
        cout.flush()<<" .";
        Sleep(500);
    }
    cout<<endl;
    for(int i=0;i<4;i++){
        for(int i=0;i<30;i++){
            cout.flush()<<rndDgit();
            Sleep(15);
        }
        cout<<" --> ?"<<endl;
    }
    Sleep(800);
    cout.flush()<<"CODE GENERATED: ????"<<endl;
    Sleep(200);
    
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
        try{
            //reject if first three digits are identical
            if(code[0]==code[1]&&code[1]==code[2]) throw 1;
            //reject if last three digits are identical
            else if(code[1]==code[2]&&code[2]==code[3])throw 1;
            //reject if all digits are identical
            else if(code[0]==code[1]&&code[1]==code[2]&&code[2]==code[3]) throw 1;
            else throw 0;
        }
        catch(int i){
            
            if(i==0)badnum = false;
            else badnum = true;
        }
        
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