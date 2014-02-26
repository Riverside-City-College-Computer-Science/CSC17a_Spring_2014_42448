/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on February 24, 2014, 12:58 PM
 */

//System Libraries
#include <cstdlib>//srand
#include <iostream>//cout
#include <ctime>//time
using namespace std;

//Global constants

//Function Prototypes
void filAray(int [],int);
void prntAry(const int [],int,int);
void cpy(const int [],int [],int);
void mrkSort(int [],int);
void swap(int &,int &);
bool findVal(int [],int,int);

int main(int argc, char** argv) {
    //Set the random seed
    srand(static_cast<unsigned int>(time(0)));
    //Declare variables
    const int SIZE=100;
    int array[SIZE],brray[SIZE];
    //Fill the array
    filAray(array,SIZE);
    //Copy the array
    cpy(array,brray,SIZE);
    //Sort the copy
    mrkSort(brray,SIZE);
    //Print the arrays
    prntAry(array,SIZE,10);
    prntAry(brray,SIZE,10);
    //Pick a random number to find
    int val=rand()%90+10;
    cout<<"The value to find in the array = "<<val<<endl;
    if(findVal(array,SIZE,val))cout<<"This value is in the array"<<endl;
    else cout<<"The value is not found in the array"<<endl;
    //Exit stage right
    return 0;
}

bool findVal(int a[],int n ,int val){
    for(int i=0;i<n;i++){
        if(a[i]==val)return true;
    }
    return false;
}

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

void mrkSort(int a[],int n){
    //Finds the minimum at this starting position
    for(int i=0;i<n-1;i++){
        //Swaps the larger values as you go down the list
        for(int j=i+1;j<n;j++){
            //Check for swap
            if(a[i]>a[j])swap(a[i],a[j]);
        }
    }
}

void cpy(const int a[],int b[],int n){
    //Copy a to b
    if(n<=1)n=2;
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
}

void prntAry(const int a[],int n,int perLine){
    //Output the array
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%10==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

//Fill array with 2 digit random digits
void filAray(int a[],int n){
    //Check the size of the array
    if(n<=1)n=2;
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10;
    }
}

