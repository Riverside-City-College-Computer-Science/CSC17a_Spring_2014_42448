/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on March 13, 2014, 11:44 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int * Reverse(int[],int);

int main(int argc, char** argv) {
    int size=10;
    int a[size];
    for(int i=0; i<size; i++) 
        a[i]=i;
    cout << "Array in order\n";
    for(int i=0; i<size; i++)
        cout << a[i] << endl;
    int *b=Reverse(a,size);
    cout << "Array in reverse\n";
    for(int i=0; i<size; i++)
        cout << b[i] << endl;

    return 0;
}

int* Reverse(int a[],int size)
{
    int *b= new int[size];
    int max=size;
    for (int i=0;i<size;i++)
    {
        b[i]=a[--max];
    }
    return b;
}

