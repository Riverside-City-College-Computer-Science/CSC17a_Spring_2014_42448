/* 
 * Name: Alec Farfan
 * Date: 03/11/14
 * Purpose: Gaddis Chapter 9 Problem 5 (Pointer Rewrite)
 */

//Include libraries
#include <cstdlib>
#include <iostream>
using namespace std;

//No global variables or constants

//Function prototypes
int doSomething(int*,int*);
int getIns(int);
//Execution begins here
int main(int argc, char** argv) {

    //Declare repeat variable
    char repeat;
    
do{
    
   //Declare variables
    int num1=0,num2=0,num3=0;
    int *ptr1,*ptr2;
    ptr1=&num1;
    ptr2=&num2;
    
    //Prompt user for input
    cout<<"Enter one number:";
    num1=getIns(num1);
    cout<<"Enter another number:";
    num2=getIns(num2);
    cout<<endl;   
   
    //Change the value of the two variables by passing them into a function
    num3=doSomething(ptr1,ptr2);//as pointers instead of reference variables

    
    //Output results to user
    cout<<"The first entry is now the second entry multiplied by ten: "<<num1<<endl;
    cout<<"The second entry is now the first entry multiplied  by ten: "<<num2<<endl;
    cout<<"The sum of the two new numbers is:"<<num3<<endl;
    cout<<"**The values where changed without using pass by reference"<<endl;
    cout<<"but instead utilizes pointers passed into a function******"<<endl;
    cout<<endl;
    
   //Ask user if they would like to repeat the program  
   cout<<"Would you like to repeat the program? Enter Y"<<endl;
   cout<<"to repeat or enter anything else to exit:";
   cin>>repeat; 
   }while(repeat=='Y'||repeat=='y');
   
    //End of program
    return 0;
}
int getIns(int num){
    cin>>num;
    return num;
}
int doSomething(int* x,int* y){
    int *temp = new int;
    *temp=*x;
    
    *x= (*y)*10;
    *y=(*temp)*10;
    
    delete temp;
    temp=0;
    
    return (*x)+(*y);
}