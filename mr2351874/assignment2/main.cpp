/* 
 * File:   main.cpp
 * Author: michael
 *
 * Created on February 26, 2014, 4:20 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <cmath>

using namespace std;

int *fillArray( int size );
int *fillNumericArr( int size );
int *blankArray( int s );
int * copy(const int *,int);
int *mode( int *a, int size);

float mean ( int *a, int size );
float median( int *a, int size );

void printArr( int *a, int s );
void printArr( int *a, int s, int perLine );
void bubbleSort( int*, int );
void swap1( int&, int& );
void destroy(int *);


int main( int argc, char** argv ) {
   
    srand( time( NULL ) );
    
    const int SIZE = 25;
    
    int *array = fillNumericArr( SIZE );
    
    printArr( array, SIZE, -1 );
        
    cout << "Mean: " << setprecision(2) << fixed << mean( array, SIZE ) << endl;
    cout << "Median: " << setprecision(2) << fixed << median( array, SIZE ) << endl;
    cout << "Mode:\n";
    printArr( mode( array, SIZE ), SIZE );
    destroy( array );
    return 0;
}



float mean ( int *a, int size ){
    float result = 0;
    
    for( int i = 0; i < size; i++ ){
        result += (float) *( a + i );
    }
    
    result /= (float) size;
    return result;            
}

float median( int *a, int size ){
    int *medianArr = copy( a, size);
    
    //printArr( medianArr, size );
    bubbleSort( medianArr, size );
    //printArr( medianArr, size );
    
    float result = 0;
    
    if ( size % 2 != 0 ) { //odd number
        int i = floor( ( (float) size / 2 ) );
        result = (float) *( medianArr + i );
    }
    else{ //even
        int i = size / 2 - 1;
        result = ( (float) *( medianArr + i ) + (float) *( medianArr + i +1 ) ) / 2;
    }
    
    destroy( medianArr );
    return result;
}

int *mode( int *a, int size){
    int *modes = blankArray( size * 2);
    
    for( int i = 0; i < size; i++ ){
        //go through orig array
        int val =  *(a+i);
        //check if the mode array has a one of the values
        for ( int j = 0; j < size; j+=2 ){
            if ( *( modes + j) == val ){
                //TODO finish this
            }
        }
    }
    return modes;
}

int *fillArray( int size ){
    int *a = new int [size];
    for ( int i = 0; i < size; i++ ) {
        *(a + i)= rand( ) % 90 + 10;
    }
    return a;
}

int *fillNumericArr( int size ){
    int *a = new int [size];
    for ( int i = 0; i < size; i++ ) {
        *(a + i) = i % 10;
    }
    return a;
}

int *blankArray( int s ){
    int *a = new int[s];
    for( int i = 0; i < s; i++){
        *(a + i) = 0;
    }
    return a;
}
void printArr( int *a, int s ){
    printArr( a, s, -1 );
}

void printArr( int *a, int s, int perLine ) {
    for ( int i = 0; i < s; i++ ) {
        cout << *(a + i) << ", ";
        if ( i % 10 == ( perLine - 1 ) && perLine != -1 ){
            cout << endl;
        }
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

void swap1( int &n1, int &n2 ) {
    n1 ^= n2;
    n2 = n1 ^ n2;
    n1 ^= n2;
}

int *copy(const int *a,int n){
    //Copy a to b
    if( n <= 1 ) n = 2;
    int *b = new int[n];
    for( int i = 0; i < n; i++){
        *( b + i ) = *( a + i) ;
    }
    return b;
}

void destroy(int *a){
    delete [] a;
}