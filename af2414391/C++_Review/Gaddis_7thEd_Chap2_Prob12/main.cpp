/*
 * Name: Alec Farfan
 * Date: 03/01/14
 * Purpose: C++ Review Chapter 2 Question From Gaddis
 */
 
//Include Libraries 
#include <cstdlib>
#include <iostream>
using namespace std;

//No Global Variables or constants

//No Function Prototypes

//Execution Begins Here
int main(int argc, char *argv[]){
   
   //Declare repeat variable
   char repeat;
do{   
    //Declare Variables 
    float acre = 43560, land=389767;
    float numAcre = land/acre;//Calculate number of acres
    
    cout<<"One Acre of land is equivalent to 43,560 square feet. The number"<<endl;
    cout<<"of acres in a tract of land with 389,767 square feet is: "<<numAcre<<endl;
    cout<<endl;
    
   //Ask the user if they would like to repeat the program
   cout<<"Would you like to repeat the program? Enter Y "<<endl;
   cout<<"to repeat or enter anything else to exit:";
   cin>>repeat;
   }while(repeat=='Y'||repeat=='y');
    
    //End of Program
    system("PAUSE");
    return EXIT_SUCCESS;
}
