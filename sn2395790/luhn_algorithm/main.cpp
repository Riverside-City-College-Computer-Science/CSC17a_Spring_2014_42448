/* 
 * File:   main.cpp
 * Author: Scott Nevin
 * Purpose: Program the Luhn algorithm
 * Created on February 25, 2014, 10:16 AM
 */


//Libraries
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

//Global Variables and constants

//Function prototypes
string input();//Gather input
int sumDgt(int [], int []);//get the sum of all digits
int luhn(int);//perform luhn algorithm

//Begin execution here
int main(int argc, char** argv) {
    
    //Declare variables
    int SIZE=12;
    int array[SIZE];
    int brray[SIZE];
    string accnt;
    int sum, chck;
    
    //Input number using function
    accnt = input();
    
    //convert to array and validate
    for (int i=1;i<11;i++){
        array[i]=accnt[i-1]-48;
    }
    
    //Get the sum of all digits
    sum = sumDgt(array,brray);
    cout<<"Sum of digits = "<<sum<<endl;
    
    //Perform Luhn Algorithm
    chck = luhn(sum);
    array[11] = chck;
    
    //Test and ouput 
    if(array[11]==0){
        cout<<"This is a valid account number"<<endl;
    }
    else
        cout<<"This is not a valid account number"<<endl;

    //Exit stage right
    return 0;
}

string input(){
    
    string a;
    
    //Input number
    cout<<"Input 10 digit account number: "<<endl;
    cin>>a;
    
    return a;
}

int sumDgt(int a[], int b[]){
    
    //Copy array
    for(int i=1;i<11;i++){
        b[i]=a[i];
    }
    
    //declare sum variable and array index
    int s=0;
    
    //Double every other digit
    for(int i=0;i<11;i++){
        
        //Test digits and double/sum appropriately
        if (a[i]<5) b[i]*=2;
        else if (a[i]==5) b[i]=1;
        else if (a[i]==6) b[i]=3;
        else if (a[i]==7) b[i]=5;
        else if (a[i]==8) b[i]=7;
        else if (a[i]==9) b[i]=9;
            
        i++;
    }   
    
    //Sum all digits
        for(int i=1;i<11;i++){
            
            s+=b[i];
        }
        return s;      
}

int luhn(int s){
    
    //Declare temporary check digit
    int c;
    
    //Multiply by 9 then mod 10
    c = s * 9 % 10;
    cout<<"Check digit = "<<c<<endl;
    
    return c;  
}