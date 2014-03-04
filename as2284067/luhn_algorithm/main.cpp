/* 
 * File:   main.cpp
 * Author: abel
 * beginning generator by Dr. Mark Lehr
 * Created on March 3, 2014, 7:34 PM
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Global Constants

//Function Prototypes
char rndDgit();
void prpLuhn(char[],int);
void Luhn(char[],int);
char split(char [],int);
void destroy(char []);
int cvnChar(char [],int);

int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    const int SIZE=12;
    char crdCard[SIZE];
    //Prepare for Luhn encoding
    cout<<"A random number created in Prep for Luhn Digit"<<endl;
    prpLuhn(crdCard,SIZE-2);
    //Output the preLuhn credit card
    cout<<crdCard<<endl;
    
    cvnChar(crdCard,SIZE);
    
    split(crdCard,SIZE);
    
    
    //Exit Stage Right
    return 0;
}

int cvnChar(char a[],int m){
    int *num = new int [m];
    for(int i=0;i<m;i++){
    switch(a[i]){
        case '0': num[i]= 0;break;
        case '1': num[i]= 1;break;
        case '2': num[i]= 2;break;
        case '3': num[i]= 3;break;
        case '4': num[i]= 4;break;
        case '5': num[i]= 5;break;
        case '6': num[i]= 6;break;
        case '7': num[i]= 7;break;
        case '8': num[i]= 8;break;
        case '9': num[i]= 9;break;
        return *num;
    }
    }
}

char split(char a[], int n){
    int size = n;
    char *b = new char [size];
    cout <<endl;
    for(int i=1;i<size;i++){
        b[i] = a[i-1];
        cout << b[i];
        i++;
        b[i] = (a[i-1]);
        cout << b[i];
    }
    cout <<endl;
    return *b;
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



