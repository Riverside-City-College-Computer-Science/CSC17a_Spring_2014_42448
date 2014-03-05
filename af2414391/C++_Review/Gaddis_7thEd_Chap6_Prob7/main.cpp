/*
 * Name: Alec Farfan
 * Date: 03/04/14
 * Purpose: C++ Review Chapter 6 Problem (Gaddis)
 */
 
//Include Libraries 
#include <cstdlib>
#include <iostream>
using namespace std;

//No Global Variables

//Function Prototypes
float celcius(float);
void getIns(float&);

//Execution begins here
int main(int argc, char *argv[]){
    
    //Declare repeat variable
    char repeat;
    
do{
   //Title output
   cout<<"               Farenheiht to Celcius Converter"<<endl<<endl;
   
   //Declare Variables
   float faren=0,celci=0;//Original temperature in farenheight
   celci=celcius(faren);//Convert the farenheiht temperature to celcius
   
   //Output conversions from numbers 0 - 20 by calling the celcius function in a loop
   for(int i=0;i<21;i++){
   faren=i;
   celci=celcius(faren);
   cout<<faren<<" degrees farenheit converted to celcius is :"<<celci<<endl;}
   cout<<endl;
           
   //Ask user if they would like to repeat the program 
   cout<<"Would you like to repeat the program? Enter Y"<<endl;
   cout<<"to repeat or enter anything else to exit:"; 
   cin>>repeat; 
   system("CLS"); 
   }while(repeat=='Y'||repeat=='y');
    
    //End of program
    return EXIT_SUCCESS;
}
float celcius(float faren){
    float convert=(5.0/9.0)*(faren-32);
    return convert;
}
