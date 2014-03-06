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
#include <ctime>
#include <iomanip>
using namespace std;

//Global Variables and constants

//Function prototypes
int sumDgt(int [], int []);//get the sum of all digits
int luhn(int);//perform luhn algorithm
void prpLuhn(char cc[],int n);
char rndDgit();

//Begin execution here
int main(int argc, char** argv) {
    
    //Seed random number generator
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables
    int SIZE=12;
    int array[SIZE];
    int brray[SIZE];
    char ccCard[SIZE];
    int sum, chck, val=0, inval=0;
    float perVal, perInval;
    
    //loop for 1000 numbers
    for(int i=0;i<10000;i++){
    
    //Input number using function
    prpLuhn(ccCard, SIZE-2);
    
    //Ouput card number prior to luhn operation
    cout<<ccCard;
    
    //convert to array and validate
    for (int i=1;i<11;i++){
        array[i]=ccCard[i-1]-48;
    }
    
    //Sum digits in array
    sum = sumDgt(array, brray);
    
    //Perform Luhn Algorithm
    chck = luhn(sum);
    
    //Test and ouput 
    if(chck==array[10]){
        cout<<"  check = "<<chck<<"  - Valid"<<endl;
        val++;
    }
    else{
        cout<<"  check = "<<chck<<"  - Invalid"<<endl;
        inval++;
    }
}
    
    //set percentages
    perVal = val / 100.0;
    perInval = inval / 100.0;
    
    //Display results
    cout<<"This program generated "<<val<<" valid card numbers "<<endl;
    cout<<"and "<<inval<<" invalid card numbers."<<endl;
    cout<<setprecision(2)<<showpoint<<fixed<<perVal<<"% valid, "<<perInval<<"% invalid."<<endl;

    //Exit stage right
    return 0;
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
        
        //Test and double 
        b[i]*=2;
        if (b[i]>9) b[i]-=9;
            
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
    //cout<<"Check digit = "<<c<<endl;
    
    return c;  
}

void prpLuhn(char cc[],int n){
    //Create a random cc in prep for Luhn checksum
    for(int i=0;i<n;i++){
        cc[i]=rndDgit();
    }
    //Put null terminator at the end
    for(int i=n;i<=n+1;i++){
        cc[i]='\0';
    }
}

char rndDgit(){
    return rand()%10+48;
}
