/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on March 13, 2014, 11:59 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int * newArray(int[],int);

int main(int argc, char** argv) {
    int size=10;
    int a[size];
    for(int i=0; i<size; i++) 
        a[i]=i;
    cout << "First Array\n";
    for(int i=0; i<size; i++)
        cout << a[i] << endl;
    int *b=newArray(a,size);
    cout << "New Array Doubled\n";
    for(int i=0; i<size*2; i++)
        cout << b[i] << endl;

    return 0;
}

int* newArray(int a[],int size)
{
    int *b= new int[size*2];
    int max=size;
    for (int i=0;i<size;i++)
    {
        b[i]=a[i];
    }
    for (int i=size;i<size*2;i++)
    {
        b[i]=0;
    }
    return b;
}