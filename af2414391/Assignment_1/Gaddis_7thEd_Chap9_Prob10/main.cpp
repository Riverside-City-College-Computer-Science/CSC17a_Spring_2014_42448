/* 
 * Name: Alec Farfan
 * Date: 03/14/14
 * Purpose: Gaddis Chapter 9 Problem 10 (Reverse the Array)
 */
 
//Include libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//No global variables or constants

//Function prototypes
int *revAry(int*,int);
void prntAry(int*,int);
int *fillAry(int);
//Execution begins here
int main(int argc, char** argv) {

    //Declare repeat variable
    char repeat;
    srand(static_cast<unsigned int>(time(0)));
    
    do{
        //Declare variables
        int size=50;
        
        //Fill and print the original array
        cout<<"     Original Array"<<endl;
        int *array1=fillAry(size);
        prntAry(array1,size);
        
        //Reverse and print the array
        cout<<"     Reversed Array"<<endl;
        int *array2=revAry(array1,size);
        prntAry(array2,size);
        
        //Ask user if they would like to repeat the program
        cout<<"Would you like to repeat the program? Enter Y"<<endl;
        cout<<"to repeat or enter anything else to exit:";
        cin>>repeat;
        system("CLS");
        
    }while(repeat=='Y'||repeat=='y');
    //End of program
    return 0;
}
int *fillAry(int size){
    int *array = new int [size];
    for(int i=0;i<size;i++){
        *(array+i)=rand()%90+10;
    }
    return array;
}
void prntAry(int* array,int size){
    for(int i=0;i<size;i++){
        cout<<*(array + i)<<" ";
        if(i%10==9&&i!=size-9){cout<<endl;}
    }
    cout<<endl;
}
int *revAry(int* array,int size){
    int *rev = new int [size];
    int dec = size-1;
    
    for(int i=0;i<size;i++){
        *(rev+i)=*(array+dec);
        dec--;
    }
    return rev;
}