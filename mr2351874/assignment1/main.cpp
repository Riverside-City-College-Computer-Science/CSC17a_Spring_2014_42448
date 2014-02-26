/* 
 * File:   main.cpp
 * Author: michael
 *
 * Created on February 19, 2014, 3:49 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

/*
 * 
 */
void printArr( int*, int, int );
//void fillArr( int[], int );
int *fillArr( int );
void bubbleSort( int*, int );
void swap1( int&, int& );
int binarySearch( int*, int, int );

int main( int argc, char** argv ) {
    ///*
    srand( time( NULL ) );

    int size = 100;
//    int arr[size];
    int *arr = fillArr( size );

    cout << "your array\n";
    //fillArr( arr, size );
    printArr( arr, size, 10 );

    bubbleSort( arr, size );

    cout << "your array\n";
    printArr( arr, size, 10 );

    cout << "Binary search for what value? ";
    short qval;
    cin >> qval;

    cout << "Its at index " << binarySearch( arr, size, qval );
    //*/
    return 0;
}

int *fillArr( int s ) {
    int *a = new int[s];
    for ( int i = 0; i < s; i++ ) {
        *(a + i)= rand( ) % 90 + 10;
    }
    
    return a;
}

void printArr( int *a, int s, int perLine ) {
    cout << endl;
    for ( int i = 0; i < s; i++ ) {
        cout << *(a + i) << " ";
        if ( i % 10 == ( perLine - 1 ) ) cout << endl;
    }
    cout << endl;
}

void bubbleSort( int *arr, int s ) {
    bool swap = false;

    do {
        swap = false;
        for ( int i = 0; i < s - 1; i++ ) {
            if ( *(arr+i) > *(arr+(i + 1)) ) {
                swap1( *(arr + i), *(arr + (i + 1) ) );
                swap = true;
            }

        }
    }    while ( swap );
}

int binarySearch( int *arr, int size, int val ) {
    int first = 0, last = size - 1;
    int mid;

    bool found = false;

    while ( !found && first <= last ) {
        mid = ( first + last ) / 2;
        if ( *(arr + mid) == val ) {
            found = true;
            return mid;
        } else if ( *(arr + mid) > val ) {
            last = mid - 1;
        } else {
            first = mid + 1;
        }
    }
    return -1;
}

void swap1( int &n1, int &n2 ) {
    n1 ^= n2;
    n2 = n1 ^ n2;
    n1 ^= n2;
}