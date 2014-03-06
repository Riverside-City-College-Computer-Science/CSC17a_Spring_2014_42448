/*
 *Name: Alec Farfan
 *Date: 2/17/14
 *Purpose: Gaddis Chapter 9 Problem 1 (Create a Dynamic Array of Integers)
 */
 
//Include Libraries
#include <cstdlib>
#include <iostream>
using namespace std;

//No Global Variables

//Function Prototypes
void print(int,int*);
void fill(int,int*);
int *alloc(int&,int*);

//Execution Begins Here
int main(int argc, char *argv[])
{
    //Declare Variables
    char repeat; 
    int numEls;
do{   
      
    //Dynamically allocate an array
    int *arry=alloc(numEls,arry);//initialize a pointer to the new array
    fill(numEls,arry);//Fill the array 
    print(numEls,arry);//Print the array
    delete [] arry;//Delete the dynamically allocated array
    
    //Ask the user if they would like to repeat the program
    cout<<"Would you like to repeat the program? Enter Y"<<endl; 
    cout<<"to repeat or enter anything else to exit:";
    cin>>repeat;
    system("CLS");
    }while(repeat=='Y'||repeat=='y');    
    //End of Program
    return EXIT_SUCCESS;
}
int *alloc(int& numEls, int* arry){
    cout<<"Enter the amount of elements you would like in the array:";
    cin>>numEls;
    
    arry = new int[numEls];
    return arry;
}
void fill(int numEls, int* arry){
     for(int i=0;i<numEls;i++){
         *(arry + i)=i + 1;}
}
void print(int numEls, int* arry){
     for(int i=0;i<numEls;i++){
        cout<<*(arry + i)<<" ";}  
        cout<<endl;   
}
