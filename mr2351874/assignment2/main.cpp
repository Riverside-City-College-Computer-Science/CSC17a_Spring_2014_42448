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
#include <limits>

using namespace std;

int *fillArray( int size );
int *fillNumericArr( int size );
int *blankArray( int s );
int *copy(const int *,int);
int* makeModeArray(int *a, int size );

int maxFreq( int *a, int size );
int numModes( int *a, int size );

float mean ( int *a, int size );
float median( int *a, int size );

void printArr( int *a, int s );
void printArr( int *a, int s, int perLine );
void bubbleSort( int*, int );
void swap1( int&, int& );
void destroy(int *);
void meanMedianMode();
void mode( int *a, int size);

int main( int argc, char** argv ) {
   
    srand( time( NULL ) );
    
    meanMedianMode();
    return 0;
}

void meanMedianMode(){
    const int SIZE = 25;
    int *array = fillNumericArr( SIZE );
    
    printArr( array, SIZE, 10 );
    int *sorted = copy( array, SIZE );
    bubbleSort( sorted, SIZE );
        
    cout << "Mean: " << setprecision(2) << fixed << mean( array, SIZE ) << endl;
    cout << "Median: " << setprecision(2) << fixed << median( sorted, SIZE ) << endl;
    cout << "Mode:\n";
    
    
    printArr( sorted, SIZE, 10 );
    mode( sorted, SIZE );
    //cout<<numModes(sorted, SIZE);        
    
    destroy( array );
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
    //bubbleSort( medianArr, size );
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

void mode( int *a, int size){
    int *b = makeModeArray(a, size);
    printArr(b, b[0]+2);
    destroy(b);
}

int maxFreq( int *a, int size ){
    int count = 1;
    int max = 1;
    
    for ( int i = 1; i < size; i++ ){
        if ( *(a + i - 1) == *(a+i) ){
            count++;
            if ( count > max ){
                max = count;
            }
        }
        else{
            count = 1;
        }
    }
    return max;
}

int numModes( int *a, int size ){
    int count = 0;
    int lastMode = std::numeric_limits<int>::max();
    int occurance = 1;
    
    for ( int i = 1; i < size; i++ ) {
        if ( *(a + i - 1) == *(a + i ) ){
            occurance++;
            if ( occurance >= 2 ) {
                if ( lastMode != *(a + i - 1) ) {
                    count++;
                    //cout<< *(a+i-1)<<", ";
                    lastMode = *(a + i - 1);
                }
           }
        }
        else{
            occurance = 1;
        }
    }
    
    return count;
}

int* makeModeArray(int *a, int size ){
    int modes = numModes( a, size );
    int occurance = 1;
    int lastMode = std::numeric_limits<int>::max();
    
    int *result = blankArray(modes+2);
    
    *(result + 1) = maxFreq( a, size);
    *(result) = modes;
    
    int stupid = 2;
    for ( int i = 1; i < size; i++ ) {
        if ( *(a + i - 1) == *(a + i) ){
            occurance++;
            if ( occurance >= 2 ) {
                if ( lastMode != *(a + i - 1) ) {
                    //cout<< *(a+i-1)<<", ";

                    lastMode = *(a + i - 1);
                    //fuck u 
                    result[ stupid++ ] = a[i - 1];
                }
           }
        }
        else{
            occurance = 1;
        }
    }
    return result;
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