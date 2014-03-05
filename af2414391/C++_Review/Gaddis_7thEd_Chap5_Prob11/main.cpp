/*
 * Name: Alec Farfan
 * Date: 03/01/14
 * Purpose: C++ Review Chapter 5 Problem (Gaddis)
 */
 
//Include Libraries 
#include <cstdlib>
#include <iostream>
using namespace std;

//No Global Variables

//No Function Prototypes

//Execution begins here
int main(int argc, char *argv[]){
    
    //Declare repeat variable
    char repeat;
    
do{
   //Declare Variables
   float initialO=0, numDays=0; 
   float prcnt; 
    
   //Reques users for input
   cout<<"             Population Program             "<<endl<<endl; 
   
   do{   
      cout<<"Enter the number of the population at the beggining:";
      cin>>initialO;
      if(initialO<2){
         cout<<"Error. Initial size of population must be at least 2"<<endl;}
      }while(initialO<2);
   do{   
      cout<<"Enter the number of days you want to calculate for:";
      cin>>numDays;
      if(numDays<1){
         cout<<"Error. Number of days to calculate must be at least 1"<<endl;}
      }while(numDays<1);   
   do{   
      cout<<"Enter the percentage increase per day without % sign:";
      cin>>prcnt;
      if(prcnt<0){
         cout<<"Error. Percentage increase must be a positive number"<<endl;}
      }while(prcnt<0);   
   
    //Calculate and show increase in population
    prcnt/=100.0;
    float eachDay=initialO;
    cout<<"Day 1: "<<initialO<<endl; 
    for(int i=1;i<numDays+1;i++){
       eachDay=eachDay+(eachDay*prcnt);
       cout<<"Day "<<i+1<<": "<<eachDay<<endl;}
        
   //Ask user if they would like to repeat the program 
   cout<<"Would you like to repeat the program? Enter Y"<<endl;
   cout<<"to repeat or enter anything else to exit:"; 
   cin>>repeat; 
   system("CLS"); 
   }while(repeat=='Y'||repeat=='y');
    
    //End of program
    return EXIT_SUCCESS;
}
