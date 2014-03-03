/*
 * Name: Alec Farfan
 * Date: 03/01/14
 * Purpose: C++ Review Chapter 3 Problem (Gaddis)
 */
 
//Include Libraries 
#include <cstdlib>
#include <iostream>
using namespace std;

//No Global Variables or Constants

//No Function Prototypes

//Execution Begins Here
int main(int argc, char *argv[]){
    
    //Declare repeat variable
    char repeat;

do{
    //Declare Variables
    string month,year;
    float gross=0,county=0,state=0,product=0,totalTax=0;
    
    //Get input for the current year and month
    cout<<"Enter the year:";
    cin>>year;   
    cout<<"Enter the month:";
    cin>>month;
    cout<<"Enter gross sales for the month:";
    cin>>gross;

    //Calculate totals
    product=gross/1.06;
    county=product*.02;
    state=product*.04;
    totalTax=product*.06;
    cout<<endl;

    //Output results
    cout<<month<<"         "<<year<<endl<<endl;
    cout<<"Gross Sales: $"<<gross<<endl;
    cout<<"Product Sales: $"<<product<<endl;
    cout<<"County Sales Tax: $"<<county<<endl;
    cout<<"State Sales Tax: $"<<state<<endl;
    cout<<"Total Sales Tax: $"<<totalTax<<endl;
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
