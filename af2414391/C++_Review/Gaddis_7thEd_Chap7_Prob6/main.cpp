/*
 * Name: Alec Farfan
 * Date: 03/04/14
 * Purpose: C++ Review Chapter 7 Problem (Gaddis)
 */
 
//Include Libraries 
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

//No Global Variables

//Function Prototypes
void sumNavg(int [],int,int&,float&);
void sort(int [],int,int&,int&);
void print(int [],int);
void fill(int [],int);

//Execution begins here
int main(int argc, char *argv[]){
    
    //Declare repeat variable
    char repeat;
    
do{
   //Declare Variables
   const int SIZE=25;
   int array[SIZE]={};
   int high=0,low=0,sum=0;
   float avg;
     
   //Fill and print the array for the first time
   fill(array,SIZE);
   print(array,SIZE);
   
   //Sort the array and print again
   sort(array,SIZE,high,low);
   print(array,SIZE);
           
   //Find the sum and average of the array elements
   sumNavg(array,SIZE,sum,avg);        
           
   //Output results to user
   cout<<"               Array Statistics "<<endl<<endl;
   cout<<"High: "<<high<<endl;
   cout<<"Low: "<<low<<endl;
   cout<<"Total: "<<sum<<endl;
   cout<<"Average: "<<avg<<endl;
   
           
   //Ask user if they would like to repeat the program 
   cout<<"Would you like to repeat the program? Enter Y"<<endl;
   cout<<"to repeat or enter anything else to exit:"; 
   cin>>repeat; 
   system("CLS"); 
   }while(repeat=='Y'||repeat=='y');
    
    //End of program
    return EXIT_SUCCESS;
}
void fill(int array[],int size){
   ifstream istream;
   istream.open("Numbers.dat");
   
   for(int i=0;i<size;i++){
        int temp;
        istream>>array[i];}
            
   istream.close();
}
void print(int array[],int size){
    for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
        if(i%5==4){cout<<endl;}}
   cout<<endl;
}
void sort(int array[],int size,int& high, int& low){
    
    for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
           if(array[j]<array[i]){
               int temp=array[i];
               array[i]=array[j];
               array[j]=temp;}}}
    low=array[0];
    high=array[size-1];
   cout<<endl;
}
void sumNavg(int array[],int size,int& sum,float& avg){
   for(int i=0;i<size;i++){
        sum+=array[i];}    
   avg=sum/static_cast<float>(size); 
}
