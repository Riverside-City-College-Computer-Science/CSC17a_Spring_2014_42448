/* 
 * File:   main.cpp
 * Author: Dennise Toscanini
 * Created on March 3, 2014, 1:10 PM
 */
//System Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

//Global Constants

//Function Prototypes
int *fillAry(int);
void prntAry(int *,int,int);
void sort(int *,int*,int);
int maxfreq(int *,int);
int nuModes(int *,int,int);
void destroy(int *);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    const int SIZE=105;
    int brray[SIZE];
    //fill the array
    int narray=200;
    int *array=fillAry(narray);
    //print the array
    prntAry(array,SIZE,10);
    //Sort the array
    sort(array,brray,SIZE);
    //Print the sorted array
    prntAry(brray,SIZE,10);
    //what is the max frequency
    cout<<"The max frequency in the array equals= "<<maxfreq(brray,SIZE)<<endl; 
    //Exit Stage Right
    destroy(array);
    return 0;
}

void destroy(int *a){
    delete [] a;
}

//Find the max frequency
int maxfreq(int *a,int n){
    //Declare counter
    int count=1,max=1;
    //loop and compare
    for(int i=1;i<n;i++){
        if(a[i-1]==a[i]){
            count++;
            if(count>max)max=count;
            
        }else {
            count=1;
        }
    }
    return max;
}

//Sort the array
void sort(int *a,int *b,int n){
    //make a copy
    for(int i=0;i<n;i++){
        b[i]=a[i];   
    }
    //sort the copied array
    for(int i=0;i<n-1;i++){
        for (int j=i+1;j<n;j++){
            if(b[i]>b[j]){
                int temp=b[i];
                b[i]=b[j];
                b[j]=temp;
            }
        }
    }
}

//Print the array
void prntAry(int *a,int n,int perLine){
    cout<<endl; 
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))
            cout<<endl;
     }  
}

//Repetitive count with one digit elements
int *fillAry(int n){
   //allocate memory
   int *a=new int[n]; 
   //Fill the array
   for(int i=0;i<n;i++){
       a[i]=i%10;
   }
   return a;
}