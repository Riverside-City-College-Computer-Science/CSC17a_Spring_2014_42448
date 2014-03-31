/* 
 * File:   main.cpp
 * Author: abel salazar
 * Created on March 25, 2014, 6:07 PM
 */

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

//global constants

//function prototypes
void destroy(char []);
void reverse(char [], char [],int);
void getchar(char [], string , int);
void prntary(char [],int);

//execution
int main(int argc, char** argv) {
    //variable declaration
    string front;
    
    cout << "Enter a string" <<endl;
    cin >> front;
    
    int size = front.size();
    char bckwrd [size];
    char bckwrd2[size];
    
    getchar(bckwrd, front, size);
    reverse(bckwrd, bckwrd2 , size);
    
    cout << "first switch"<<endl;
    prntary(bckwrd, size);
    cout << "a array" <<endl;
    prntary(bckwrd , size);
    cout << "b array" <<endl;
    prntary(bckwrd2, size);
    
    destroy(bckwrd);
    destroy(bckwrd2);
    //exit stage
    return 0;
}

void prntary(char a[], int m){
    cout <<endl;
    for(int i=0;i<m;i++){
        cout<<a[i]<< " ";
    }
    cout <<endl;
}

void getchar(char a[], string front ,int size){
    for(int i=0;i<size;i++){
        int j=size;
        j--;
        a[i]=front[j];
        front.pop_back();
    }
}

void reverse(char a[],char b[],int m){
    for(int j=0;j<m;j++){
        int i=m;
        i--;
        a[j]=b[i];
    }
}

void destroy(char bckwrd[]){
    delete [] bckwrd;
}