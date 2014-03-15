/* 
 * File:   main.cpp
 * Author: Scott Nevin  
 * Purpose: Calculate mean, median, and mode of a number set
 * Created on March 3, 2014, 12:55 PM
 */

//Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Global Constants and Variables

//Function Prototypes
void filAry(int[], int);
void prntAry(int[],int, int);
void sort(int[], int[], int);
int maxFreq(int[], int);
int numModes(int [], int, int);
int modeNm(int [], int, int, int);
float sumAry(int [], int);

//Begin execution here
int main(int argc, char** argv) {
    
    //Declare variables
    const int SIZE=105;
    int array[SIZE], bray[SIZE], names[SIZE];
    int max, modes, count =1, num=0;
    float mean;
    
    //Fill the array with 0-9 digits
    filAry(array, SIZE);
    
    //Print the array
    prntAry(array, SIZE, 10);
    
    //Copy and sort array
    sort(array, bray, SIZE);
    
    //Print new array
    prntAry(bray, SIZE, 10);
    cout<<endl;
    
    //Find Max Frequency
    cout<<"The max. frequency in the array = "<<maxFreq(bray, SIZE)<<endl;
    max = maxFreq(bray, SIZE);
    
    //Find the number of modes
    modes = numModes(bray, SIZE, max);
    
    cout<<"Number of modes = "<<modes<<endl;
   
    //Get the names of those modes
    //Couldn't get it to work in a function, had to embed it
    cout<<"Names of modes: ";
    //loop and compare
    for(int i=1;i<SIZE;i++){
        if(bray[i-1]==bray[i]){
            count++;
            if(count==max){
                count=1;
                cout<<bray[i]<<", ";
            }
        }
    }
    cout<<endl;
    
    //Display that median
    cout<<"Median = "<<bray[SIZE/2]<<endl;
    
    //Lets find that mean
    mean = sumAry(bray, SIZE);
    
    //Display the mean
    cout<<"Mean = "<<mean<<endl;
    
    
//Exit Stage Right
    return 0;
}

//repetitive count with random 2 digit elements
void filAry(int a[], int n){
    
    for(int i=0;i<n;i++){
        a[i]=i%10;
    }
}

//Print array
void prntAry(int a[],int n, int perline){
    
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perline==(perline-1))cout<<endl;
    }
    cout<<endl;
}

//Copy then sort the array
void sort(int a[], int b[], int n){
    
    //make the copy
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
        
    //sort the copied array
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(b[i]>b[j]){
                    int temp=b[i];
                    b[i]=b[j];
                    b[j]=temp;
                }
            }
        }
    }

//Requires sorted array for an input
int maxFreq(int a[], int n){
    
    //Declare counters
    int count=1, max=1;
    
    //loop and compare
    for(int i=1;i<n;i++){
        if(a[i-1]==a[i]){
            count++;
            if(count>max)max=count;
        }else{
            count=1;
        }
    }
    return max;
}

//Collect the number of modes
int numModes(int a[], int n, int max){
    
    //Declare counters
    int count=1, num=0;
    
    //loop and compare
    for(int i=1;i<n;i++){
        if(a[i-1]==a[i]){
            count++;
            if(count==max){
                num++;
                count=1;
                
            }
        }
    }
    return num;   
}

float sumAry(int a[], int n){
    
    //Declare the sum and mean variable
    int sum=0;
    float mean=0;
    
    //sum the array
    for(int i=1;i<n;i++){       
        sum+=a[i];
    }
    
    //Calculate mean
    mean = sum *1.0 / n;
    
    return mean;
}

