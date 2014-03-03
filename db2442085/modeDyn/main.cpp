/* 
 * File:   main.cpp
 * Author: David Ballantyne
 * Created on March 3, 2014, 1:09 PM
 * purpose: Mode Array
 */
//Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

//Global Constants

//function prototypes
int * filAray(int);
void prntAry(int *, int, int);
int * sort(const int *,int);
int maxFreq(int *,int);
int * numModes(int *, int, int);
void destroy(int *);
//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    const int SIZE=105;
    int *array=filAray(SIZE);
    int *brray=sort(array,SIZE);
    int max;
    //print array
    prntAry(array,SIZE,10);
    //print
    prntAry(brray,SIZE,10);
    //exit stage right
    max=maxFreq(brray,SIZE);
    cout<<"The max frequency is "<<max<<endl;
    int *crray=numModes(brray,SIZE,max);
    //print
    prntAry(crray,SIZE,10);
    
    destroy(array);
    destroy(brray);
    destroy(crray);      
    return 0;
}
void destroy(int *a){
    delete a;
}
int * numModes(int *a, int n, int m){
    int * b=new int(n);
    int count=1;
    for(int i=1;i<n;i++){
         if(a[i-1]==a[i]){
             count++;
             if(count==m) b[i]=a[i];
         }else{
                 count=1;
         }   
       }
    return b;
}
//requires sorted array (binary search)
int maxFreq(int *a,int n){
    //declare counters
    int count=1, max=1;
    //loop compare
     for(int i=1; i<n;i++){
         if(a[i-1]==a[i]){
             count++;
             if(count>max)max=count;
         }else{
             count=1;
         }
     }
    return max;
}
int * sort(const int *a, int n){
    int * b=new int(n);
    //make copy
    for(int i=0; i<n;i++){
        b[i]=a[i];
    }
    //sort copied array
    for(int i=0; i<n-1;i++){
        for(int j=i+1; j<n;j++){
            if (b[i]>b[j]){
                int temp=b[i];
                b[i]=b[j];
                b[j]=temp;
                }
         }
    }
    return b;
}
void prntAry(int *a ,int n, int perLine){
    cout<<endl;
    for(int i=0; i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==perLine-1)cout<<endl;
    }
    cout<<endl;
}
//repetitive count w/ 1 digit elements
int * filAray(int n){
    int * a=new int(n);
    for(int i=0; i<n;i++){
        a[i]=i%10;
    }
    return a;
}
