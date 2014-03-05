/* 
 * File:   main.cpp
 * Author: Scott Nevin
 * Purpose: Searching/ Sorting routines, modified for pointers
 * Created on February 24, 2014, 12:58 PM
 */


//Libraries
#include <iostream>//cout
#include <cstdlib>//srand
#include <ctime>//time
using namespace std;

//Global variables and constants

//Function Prototypes 
void filAry(int *, int);
void prntAry(const int *, int, int);
void cpy (const int *, int *, int);
void mrkSort(int *, int);
void swap (int &, int &);
bool findVal(int*, int, int);

//Begin execution here
int main(int argc, char** argv) {
    
    //seed number generator
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables
    const int SIZE = 100;
    int array[SIZE], bray[SIZE];
    
    //fill array
    filAry(array, SIZE);
    
    //copy the array
    cpy (array, bray, SIZE);
    
    //sort the copy
    mrkSort (bray, SIZE);
    
    //print array
    prntAry (array, SIZE, 10);
    prntAry (bray, SIZE, 10);
    
    //Pick a random number to find
    int val = rand()%90+10;
    cout<<"The value to find in the array = "<<val<<endl;
    if(findVal(array, SIZE, val))cout<<"This value was found in the array!"<<endl;
    else cout<<"This value is not present in the array."<<endl;

    //Exit stage right
    return 0;
}

//Fill array with two digit numbers
void filAry(int *a, int n){
    
    //check size of the array
    if(n<=1)n=2;
    for(int i=0;i<n;i++){
        //a[i]=rand()%90+10; 
        //the original ^^
        *(a+i)=rand()%90+10;
    }   
}

//Print Array
void prntAry(const int *a, int n, int perline){
    
    //check size of the array
    if(n<=1)n=2;
    for(int i=0;i<n;i++){
        //converted to pointer
        cout<<*(a+i)<<" ";
        if(i%10==(perline-1))cout<<endl;
    }
    cout<<endl;
}

//copy array
void cpy (const int *a, int *b, int n){
    
    //copy array to index
    if(n<=1)n=2;
    for(int i=0;i<n;i++){
        *(b+i)=a[i];
      }
}

//Sort Array
void mrkSort(int *a, int n){
    
    //find minimum at starting position
    for(int i=0; i<n-1; i++){
        //swap the larger values as you go down list
        for(int j=i+1; j<n; j++){
            //check for swap
            //some converted to pointers
            if(*(a+i)>a[j])swap(a[i],a[j]);
        }
    }
    
}

//Search routine
bool findVal(int *a, int n, int val){
    
    for(int i=0;i<n;i++){
        if(a[i]==val)return true;
    }
    return false;
}

//function to swap
void swap (int &a, int &b){
    
    //Switch the values
    int temp =a;
    a=b;
    b=temp;   
}