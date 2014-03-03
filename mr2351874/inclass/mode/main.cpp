/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on March 3, 2014, 1:06 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

/*
 * 
 */
void print( int *a, int s, int per );
void sort( int a[], int d[] , int s );
void destroy( int* );

int*  fillArray( int s );

int maxFreq( int a[], int s );

int main(int argc, char** argv) {
    srand( time( NULL ) );
    
    int size = 105;
    int *arr = fillArray( size );
    int *sorted;

    print( arr, size, 10);
    
    sort( arr, sorted, size );
    
    print( sorted, size, 10);
    
    //what is the max freq 
    cout<< "the max freq is: " << maxFreq( sorted, size ) << endl;
    return 0;
}

int* fillArray( int s ){
    int *a = new int[s];
    for(int i =0; i< s; i++){
        *(a+i) = i %10;
    }
    return a;
}

void sort( int a[], int b[], int s ){
    //copy
    for(int i = 0; i < s; i++ ){
        b[i] = a[i];
    }
    //sort
    for(int i = 0; i < s-1; i++){
        for (int j = i + 1; j < s; j++) {
            if ( b[i] > b[j]  ) {
                swap( b[i], b[j] );
            }
        }

    }
}

void print( int *a, int s, int per ){
    for(int i = 0; i < s; i++){
        cout<< *(a+i)<< " ";
        if( i % 10 == ( per - 1) ){
            cout << endl;
        }
    }
    cout<<endl;
}

//find the max freq req sorted array
int maxFreq( int a[], int s ){
    //counters
    int count = 1;
    int max = 1;
    //loop and compare
    for(int i = 1 ; i < s; i++){
        if ( a[i-1] == a[i] ){
            count++;
            if (count > max) {
                max = count;
            }
        }
        else{
            count = 1;
        }
    }
    return max;
}

void destroy( int *a ){
    delete [] a;
}