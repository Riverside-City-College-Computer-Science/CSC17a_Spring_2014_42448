/* Bradd Carey
 * 26 Feb 2014
 * 
 * 
 */

//Libraries
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

//Global Variables

//Main Function Prototypes
void menu();
bool repeat(int);
void program1();
void program2();
void program3();
void program4();
void program5();
void program6();
void program7();

//Sub Function Prototypes
int isNum(string);  //Returns 0 if invalid and program number if valid



int main(int argc, char** argv) {
    
    menu();
    cout<<"\nThank you for using Assignment 5!\n\nGOODBYE!!";
    return 0;
}
  
//Main Function Prototypes
void menu(){
    string c;
    //Begin Menu
    do{
        cout<<"************************************************************************"
            <<"\nWelcome to Bradd's Assignment 1 - CSC17A - 42448"
            <<"\n----------------------------------------------------------------------"
            <<"\n[1]  Monthly Sales Tax - Gaddis 3.12"
            <<"\n[2]  Monthly Sales Tax - Gaddis 3.13" 
            <<"\n[3]  Monthly Sales Tax - Gaddis 4.10"            
            <<"\n[4]  Monthly Sales Tax - Gaddis 5.11"            
            <<"\n[5]  Monthly Sales Tax - Gaddis 6.7"           
            <<"\n[6]  Monthly Sales Tax - Gaddis 7.6"           
            <<"\n[7]  Monthly Sales Tax - Gaddis 8.7";
        do{
            cout<<"\n-----------------------------------------------------------------------"
                <<"\nPlease Enter the number of the program you'd like to use:  ";
            getline(cin,c);
        }while(!isNum(c));
        
        switch(isNum(c)){
            case 1:  program1()  ; break;
            case 2:  program2()  ; break;    
            case 3:  program3()  ; break;
            case 4:  program4()  ; break;
            case 5:  program5()  ; break;
            case 6:  program6()  ; break;
            case 7:  program7()  ; break;
        
        }
        
    }while(repeat(0));
}
bool repeat(int c){
    string r;
    if(c){
        cout<<"\nEnter [0] to exit to Main Menu, else repeat.  ";
        getline(cin,r);
        if(r[0]!='0')
            return true;
        else
            return false;
    }
    else{
        cout<<"\nEnter [0] to exit Program, else repeat.  ";
        getline(cin,r);
        if(r[0]!='0')
            return true;
        else
            return false;
    }
    
    
}
void program1(){
    /*Write a program that asks for five test scores. The program should calculate the average
        test score and display it. The number displayed should be formatted in fixed-point
        notation, with one decimal point of precision.*/
    cout<<"\n************************************************"; 
    cout<<"\n**  Welcome to 24hr Time Calculator   **********";
    cout<<"\n************************************************\n";
    cout<<"This program will convert military time to standard.\n";
    do{
        
    }while(repeat(1)); 
}
void program2(){
    int hours, mins, waitH, waitM, days;
    cout<<"\n************************************************"; 
    cout<<"\n**  Welcome to Waiting Calculator   ************";
    cout<<"\n************************************************";
    cout<<"\nThis program will calculate what time it will be after a waiting period.\n";
    do{
        
    }while(repeat(1)); 
}
void program3(){
    cout<<"\n************************************************"; 
    cout<<"\n**  Welcome to Waiting Calculator (12hr)   *****";
    cout<<"\n************************************************";
    cout<<"\nThis program will calculate what time it will be after a waiting period.\n";
    do{
        
    }while(repeat(1)); 
}
void program4(){
    cout<<"\n************************************************"; 
    cout<<"\n**  Welcome to Change Calculator   *************";
    cout<<"\n************************************************";
    cout<<"\nThis program will tell you how to give change in the fewest coins.\n";
    do{
        
    }while(repeat(1)); 
}
void program5(){
    cout<<"\n************************************************"; 
    cout<<"\n**  Welcome to Deviation Calculator   **********";
    cout<<"\n************************************************";
    cout<<"\nThis program calculates the average and standard deviation.\n";
    do{
        
    }while(repeat(1)); 
}
void program6(){
    cout<<"\n************************************************"; 
    cout<<"\n**  Welcome to Pounds to Kilograms   ***********";
    cout<<"\n************************************************";
    cout<<"\nThis program takes input in pounds and ounces and converts it to metric.\n";
    do{
        
    }while(repeat(1)); 
}
void program7(){
    cout<<"\n************************************************"; 
    cout<<"\n**  Welcome to Kilograms to Pounds   ***********";
    cout<<"\n************************************************";
    cout<<"\nThis program takes input in kilograms and grams and converts it to US Standard.\n";
    do{
        
    }while(repeat(1)); 
}

//Program Function Prototypes

//Upkeep Prototypes
int isNum(string a){
    if(a.length()>1)
        return 0;
    for(int i=0;i<a.length();i++){
        if((a[i]-'0'<1)||(a[i]-'0'>7))
            return 0;
    }
    return a[0]-'0';
}