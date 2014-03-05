/*
 * Name: Alec Farfan
 * Date: 03/04/14
 * Purpose: C++ Review Chapter 8 Problem (Gaddis)
 */
 
//Include Libraries 
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

//No Global Variables

//Function Prototypes
int biSearch(string[],string,int);
void print(string[],int);
void sort(string[],int);

//Execution begins here
int main(int argc, char *argv[]){
    
    //Declare repeat variable
    char repeat;
    string value;
do{
   //Declare Variables
   const int SIZE = 20;
   int foundIn=0;
   string nameAry[SIZE]={"Collins, Bill","Smith, Bart","Allen, Jim","Griffin, Jim","Stamey, Marty",
                 "Rose, Geri","Taylor, Terri","Johnson, Jill","Alison, Jeff","Looney, Joey",
                 "Wolfe, Bill","James, Jean","Weaver, Jim","Pore, Bob","Rutherford, Greg",
                 "Javens, Renee","Harrison, Rose","Setzer, Cathy","Pike, Gordon","Holland, Beth"};

   
   //Print the unsorted array
   print(nameAry,SIZE);
   
   //Have the user input a name to search for
   cout<<"Enter one of the names exactly as it apears to search for it:";
   std::getline(std::cin,value);
   cout<<endl;
   
   //Sort the array of names
   sort(nameAry,SIZE);
   print(nameAry,SIZE);//Print the array again
   
   //Search for a string value using the binary search
   foundIn=biSearch(nameAry,value,SIZE);
   
   //Output results to user
   if(foundIn>-1){
      cout<<value<<" was found in subscript number "<<foundIn<<"."<<endl;}
   else{
      cout<<value<<" was not found in the array."<<endl;}    
           
   //Ask user if they would like to repeat the program 
   cout<<"Would you like to repeat the program? Enter Y"<<endl;
   cout<<"to repeat or enter anything else to exit:"; 
   cin>>repeat; 
   system("CLS");
   cin.ignore(); 
   }while(repeat=='Y'||repeat=='y');
    
    //End of program
    return EXIT_SUCCESS;
}
void sort(string array[],int size){
    for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            if(array[j]<array[i]){
            string temp = array[i];
            array[i] = array[j];
            array[j] = temp;}}}
}
void print(string array[],int size){
    for(int i=0;i<size;i++){
        cout<<array[i]<<" | ";
        if(i%5==4){ cout<<endl;}
    }
    cout<<endl;
}       
int biSearch(string array[],string value, int size){
    int low=0, high=size-1, position = -1, middle;
    bool found = false;
    
    while(!(found)&&low<=high){
       middle = (high+low)/2;
       if(array[middle]==value){
          found=true;
          position=middle;}
       else if(array[middle]>value){
          high=middle-1;}
       else{
          low=middle+1;}     
    } 
    return position;
}
