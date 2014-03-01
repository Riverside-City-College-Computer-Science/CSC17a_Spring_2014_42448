/*
 * Name: Alec Farfan
 * Date: 03/01/14
 * Purpose: C++ Review Chapter 4 Problem (Gaddis)
 */
 
//Include Libraries 
#include <cstdlib>
#include <iostream>
using namespace std;

//No Global Variables or Constants

//No Function Prototypes

//Execution begins here
int main(int argc, char *argv[]){
    
    //Declare repeat variable
    char repeat;

do{   
    //Declare Variables   
    int numOrder=0,price=99;   
    float nd=1, d1=.8, d2=.7, d3=.6, d4=.5,
          dUsed=0, total;    
      
    //Request input for the number of packages ordered
    cout<<"Enter the number of packages sold:";
    cin>>numOrder;
    if(numOrder<1){
       do{
       cout<<"Error. Must enter a positive number"<<endl;   
       cout<<"Enter the number of packages sold:";      
       cin>>numOrder;
       }while(numOrder<1);}
      
    //Compute the total cost   
    if(numOrder<10){
       dUsed=nd;}
    if(numOrder>9&&numOrder<20){
       dUsed=d1;}
    if(numOrder>19&&numOrder<50){
       dUsed=d2;}
    if(numOrder>49&&numOrder<100){
       dUsed=d3;}
    if(numOrder>99){
       dUsed=d4;}
    total = numOrder*dUsed*price;
    
    //Output results to user
    cout<<"The total cost of the packages after discount is: $"<<total<<endl;
    cout<<endl;
         
    //Ask the user if they would like to repeat the program    
    cout<<"Would you like to repeat the program? Enter Y"<<endl;
    cout<<"to repeat or enter anything else to exit:";
    cin>>repeat;
    system("CLS");
   }while(repeat=='Y'||repeat=='y');
   
    //End of program
    return EXIT_SUCCESS;
}
