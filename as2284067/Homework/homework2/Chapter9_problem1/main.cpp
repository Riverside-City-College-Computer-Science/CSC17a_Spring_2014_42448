/* 
 * File:   main.cpp
 * Author: Abel Salazar
 * Created on March 12, 2014, 9:10 PM
 * The sole purpose of this program is to make a dynamic array
 */

//system libraries
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

//global constants

//function prototypes
int *fillAry(int);
void prntAry(int[],int,int);
void destroy(int[]);

//execution begins here
int main(int argc, char** argv) {
    //variable declaration
    srand(static_cast<unsigned int>(time(0)));
    
    int num = 0;
    cout << "Enter the size of the array you would like"<<endl;
    cin >> num;
    //creating a dynamic array
    int *ptr=fillAry(num);
    //print array
    prntAry(ptr,num,10);
    //destroy allocated memory
    destroy(ptr);
    
    //exit stage
    return 0;
}

//destroys allocated memory
void destroy(int a[]){
    delete []a;
}

//prints array, 10 integers per line
void prntAry(int a[],int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%10==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

//fills array with random single integers
//between 1 and 9
int *fillAry(int n){
    if(n<2)n=2;
    //fill with 1 digit numbers
    int *a=new int [n];
    for(int i=0;i<n;i++){
        a[i]=rand()%9+1;
    }
    return a;
}
