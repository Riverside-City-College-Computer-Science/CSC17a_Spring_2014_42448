/*
 *Name: Alec Farfan
 *Date: 2/17/14
 *Purpose: Gaddis Chapter 9 Problem 2 (Test Scores #1)
 */
 
//Include Libraries
#include <cstdlib>
#include <iostream>
using namespace std;

//No Global Variables

//Function Prototypes
void print(int,int*,float);
void swap(int&,int&);
int set(int,int*,int);
void sort(int,int*);
void average(int,int*,float&);
void fill(int,int*);
int *alloc(int&,int*);

//Execution Begins Here
int main(int argc, char *argv[])
{
    //Declare Variables
    char repeat; 
    int numEls=0;
   
do{   
     float avg=0;  
    //Dynamically allocate an array
    int *arry=alloc(numEls,arry);//initialize a pointer to the new array
    fill(numEls,arry);//Fill the array 
    average(numEls,arry,avg);//Find the average test score
    sort(numEls,arry);//Sort the array in ascending order
    print(numEls,arry,avg);//Print the array
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
    cout<<"Enter the number of tests:";
    cin>>numEls;
    
    arry = new int[numEls];
    return arry;
}
void fill(int numEls, int* arry){
     cout<<"Enter the test scores."<<endl;
     for(int i=0;i<numEls;i++){
         cout<<"Test"<<(i+1)<<":";
         cin>> *(arry + i);}
}
void average(int numEls,int *arry, float& avg){
    for(int i=0;i<numEls;i++){ 
        avg+= *(arry + i);}
    avg/=numEls; 
}
void sort(int numEls,int *arry){
     int min;
     for(int i=0;i<numEls-1;i++){
         min=set(i,arry,numEls);
         swap(*(arry+i),*(arry+min));}
}
int set(int start,int* arry,int numEls){
     int small=*(arry+start);
     int smallEl=start;    
     for(int i=start+1;i<numEls;i++){
         if(*(arry+i)<small){
         small=*(arry+i);
         smallEl=i;}}
     return smallEl; 
}
void swap(int& a, int& b){
     int temp=a;
     a=b;
     b=temp;
}
void print(int numEls, int* arry, float avg){
     cout<<endl;
     cout<<"The average test score is:"<<avg<<endl;
     for(int i=0;i<numEls;i++){
        cout<<*(arry + i)<<" "<<endl;}
}
