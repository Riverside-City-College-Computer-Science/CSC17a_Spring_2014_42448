/* 
 * File:   functions.h
 * Author: Scott Nevin
 * Purpose: Function Declarations for mastermind program
 * Created on April 9, 2014, 2:42 PM
 */

#ifndef FUNCTIONS_H
#define	FUNCTIONS_H

//Function prototypes
char rndDgit();//random digit generator
void prpCode(char[], char[], int);//generates and tests code before gameplay
void usrGess(char[], int);//accepts user input during gameplay
void tstGess(char[], char[], char [], char[], int);//tests user's guess against the code
bool tstWin(char[]);//tests if code is 100% correct in order to break loop
int menu();//Displays menu and collects user's decision 
void score(int);//writes user high score to a file and displays high score
void rules();//displays rules to the game

#endif	/* FUNCTIONS_H */

