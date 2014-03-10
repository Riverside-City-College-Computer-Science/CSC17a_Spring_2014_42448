/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on March 10, 2014, 1:16 PM
 */

#include <cstdlib>
#include <vector>
#include <iostream>
#include <ctime>

using namespace std;

/*
 * 
 */
void fillStat( int a[], int s ); // fill static arr
void printStat( int a[], int s, int p ); //print static arr
void fillVector( vector<int> &v, int s );
void printVector( vector<int> &v, int );
void destroy( int* );

int* fillDyna( int s );

int main(int argc, char** argv) {
    srand( time( NULL ) );
    //static vars
    const int SIZE = 100;
    int sArr[SIZE];
    fillStat( sArr, SIZE );
    printStat( sArr, SIZE, 25 );
    
    cout << "dynamic array \n";
    int *dArr = fillDyna( SIZE );
    printStat( sArr, SIZE, 25 );
    
    cout << "vector \n";
    vector<int> vec;
    fillVector( vec, SIZE );
    printVector( vec, 25 );
    
    destroy( dArr );
    return 0;
}

void fillStat( int a[], int s ){
    for( int i = 0; i < s; i++ ){
        a[i] = rand() % 90 + 10;
    }
}

int* fillDyna( int s ){
    if( s < 2 ) s = 2;
    int *a = new int[s];
    for( int i = 0; i < s; i++ ){
        *(a+i) = rand() % 90 + 10;
    }
    return a;
}

void fillVector( vector<int> &v, int s ){
    for( int i = 0; i < s; i++ ){
        v.push_back( rand() % 90 + 10 );
    }
}

void printStat( int a[], int s, int p ){
    for( int i = 0; i < s; i++ ){
        cout << a[i] << ", ";
        if( i % p == p - 1 ){
            cout << endl;
        }
    }
}

void printVector( vector<int> &v, int p ){
    for( int i = 0; i < v.size(); i++ ){
        cout << v[i] << ", ";
        if( i % p == p - 1) cout << endl;
    }
}

void destroy( int *a ){
    delete [] a;
}