/* 
 * Author: Abel Castillon Jr.
 * Date: February 27, 2014
 * Purpose: C++ Review Problems Chapters 2-8 One Problem from each chapter.
 * Programming Challenges
 * Chapter 2 - Sum of Two Numbers (DONE)
 * Chapter 3 - Miles per Gallon (DONE)
 * Chapter 4 - Roman Numeral Converter (switch statement needs to display outputs)
 * Chapter 5 - Sum of Numbers 
 * Chapter 6 - Markup
 * Chapter 7 - Largest / Smallest Array Values
 * Chapter 8 - Charge Account Validation
 */
//Library
#include <cstdlib>
#include <iostream>
using namespace std;

//Global Variables and Constructs

//Functional Prototypes
void Problem_one();
void Problem_two();
void Problem_three();
void Problem_four();
void Problem_five();
void Problem_six();
void Problem_seven();
void progMenu();

//Execution Begins Here!
int main(int argc, char** argv){
    //Declare menu variables
    char ans, choice;
    //Prompt user menu
    progMenu();
    //Accept user choice input
    cin >> choice;
    //Problem Menu
    switch(choice){
        //Problem 1
        case '1':{
            Problem_one();
            break;
        }
        //Problem 2
        case '2':{
            Problem_two();
            break;
        }
        //Problem 3
        case '3':{
            Problem_three();
            break;
        }
        //Problem 4
        case '4':{
            Problem_four();
            break;
        }
        //Problem 5
        case '5':{
            Problem_five();
            break;
        }
        //Problem 6
        case '6':{
            Problem_six();
            break;
        }
        //Problem 7
        case '7':{
            Problem_seven();
            break;
        }
    }
    //Exit Stage Right!
    return 0;
}

//Displays menu
void progMenu(){
    cout << " C++ Review Homework Menu " << endl;
    cout << " ------------------------- " << endl;
    cout << " 1. Chapter 2 - Sum of Two Integers " << endl;
    cout << " 2. Chapter 3 - Miles per Gallon " << endl;
    cout << " 3. Chapter 4 - Roman Numeral Converter " << endl;
    cout << " 4. Chapter 5 - " << endl;
    cout << " 5. Chapter 6 - " << endl;
    cout << " 6. Chapter 7 - " << endl;
    cout << " 7. Chapter 8 - " << endl;
    cout << " " << endl;
    cout << " Enter a number to go to that homework problem. " << endl;
}

//Chapter 2 Introduction to C++ - Sum of Two Integers
void Problem_one(){
    //Program will calculate the sum of two integers
    cout << " Sum of Two Integers " << endl;
    cout << " ------------------- " << endl;
    
    //Declare integer variables
    int a,b,total;
    
    //Prompt user to enter value for 'a'
    cout << " Enter first integer " << endl;
    //Accept integer for 'a'
    cin >> a;
    //Display user entered integer
    cout << " You entered : " << a << endl;
    
    //Prompt user to enter value for 'b'
    cout << " Enter second integer " << endl;
    //Accept integer for 'b'
    cin >> b;
    //Display user second entered integer
    cout << " You entered : " << b << endl;
    
    //Calculate sum
    total = a + b;
    
    //Display sum of two integers a + b
    cout << " Total =  " << total << endl;
    
}

//Chapter 3 Expressions and Interactivity - Miles Per Gallon
void Problem_two(){
    //Program will calculate a car's gas millage.
    cout << " MPG Calculator " << endl;
    cout << " -------------- " << endl;
    cout << " This program will calculate a car's gas millage. " << endl;
    
    //Declare variables
    int tank, miles,mpg;
    
    //Ask user to enter number of gallons car can hold
    cout << " Enter the number of gallons the car can hold " << endl;
    //cin gallons car can hold
    cin >> tank;
    
    //Ask user to enter number of miles car can drive per full tank.
    cout << " Enter the number of miles the car can drive per full tank of gas " << endl;
    //cin number of miles car can drive per full tank.
    cin >> miles;
    
    //Calculate the number of miles per gallon of gas.
    mpg = miles / tank;
    
    //Display results
    cout << " Your vehicle total Miles Per Gallon = " << mpg << " MPG " << endl;
}

//Chapter 4 Making Decisions - Roman Numeral Converter
void Problem_three(){
    cout << " Roman Numeral Converter " << endl;
    cout << " ----------------------- " << endl;
    cout << " This program will take an integer between 1 - 10 " << endl;
    cout << " Then it will convert it into Roman Numeral Form " << endl;
    //Declare variable choice
    int choice;
    //Accept user choice
    cin >> choice;
    //Validation: Do not accept numbers less than 1 or greater than 10
    if(choice < 1 || choice > 10){
        cout << " Invalid choice. Please enter a number 1 - 10 " << endl;
        //Accept user input again
        cin >> choice;
    }
    //Declare switch statement
    switch(choice){
        //Roman Numeral I
        case '1':{
            cout << " Roman Numeral = I " << endl;
            break;
        }
        //Roman Numeral II
        case '2':{
            cout << " Roman Numeral = II " << endl;
            break;
        }
        //Roman Numeral III
        case '3':{
            cout << " Roman Numeral = III " << endl;
            break;
        }
        //Roman Numeral IV
        case '4':{
            cout << " Roman Numeral = IV " << endl;
            break;
        }
        //Roman Numeral V
        case '5':{
            cout << " Roman Numeral = V " << endl;
            break;
        }
        //Roman Numeral VI
        case '6':{
            cout << " Roman Numeral = VI " << endl;
            break;
        }
        //Roman Numeral VII
        case '7':{
            cout << " Roman Numeral = VII " << endl;
            break;
        }
        //Roman Numeral VIII
        case '8':{
            cout << " Roman Numeral = VIII " << endl;
            break;
        }
        //Roman Numeral IX
        case '9':{
            cout << " Roman Numeral = IX " << endl;
            break;
        }
        //Roman Numeral X
        case '10':{
            cout << " Roman Numeral = X " << endl;
            break;
        }
    }
}

//Chapter 5 Looping - Sum of Numbers
void Problem_four(){
    //Program will ask user for a positive integer value.
    //Program will use a loop to get the sum of all the integers from 1 up to that number
    //Input Validation: Do not accept a negative starting number
}

//Chapter 6 Function - MarkUp
void Problem_five(){
    //Program will ask user to enter an item's wholesale cost and its markup percentage
    //Program will then display the item's retail price.
    //
}

//Chapter 7 Arrays - Largest / Smallest Array Values
void Problem_six(){
    //Program will let user enter 10 values into an array.
    //The program will display the largest and the smallest values stored in the array.
}

//Chapter 8 Searching and Sorting Arrays - Charge Account Validation
void Problem_seven(){
    //Program will let user enter a charge account number.
    //Program should determine if the number is valid by checking for it in a list:
    //5658845   4520125 7895122 8777541 8451277 1302850
    //8080152   4562555 5552012 5050552 7825877 1250255
    //1005231   6545231 3852085 756651  7881200 4581002
    
    //List of numbers above should initialize in a  single-dimension array.
    //A simple linear search should be used to locate the number entered by user.
    //If user enters number in the array, program will display message saying "valid"
    //If user enters number not in array, program will display message saying "invalid"
    
}