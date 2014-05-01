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
#include <fstream>
#include <iomanip>
#include <windows.h>
#include "functions.h"
using namespace std;

//Initialize structure for high scores
struct highscore{
    string name;
    int score;
};

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
int menu(){
    
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
    
    //test if code is correct
    if(r[0]=='X'&&r[1]=='X'&&r[2]=='X'&&r[3]=='X') return true;
    else 
        return false;
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
