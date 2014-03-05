/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on February 24, 2014, 1:07 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

void prtA( int *, int, int);
void fillA( int *, int );
void cpy( int *, int *, int);
void mrksort( int *, int);
void swap( int &, int &);
bool find( int *, int, int);

int main(int argc, char** argv) {
    const int size = 100;
    int a[size];
    int b[size];
    
    srand(time(NULL));
    
    fillA( a, size);
    cpy( a, b, size);
    prtA( b, size, 10);
    mrksort(b, size);
    prtA( b, size, 10);
    
    int val = rand() % 90 + 10;
    cout<< "find this " << val<<endl;
    cout << ( find(b, size, val) ? "found "  : "not found" );
    
    return 0;
}
void mrksort( int *a, int n){
    for(int i = 0; i < n-1; i++){
        for (int j = i+1; j < n; j++) {
            if ( *(a+i) > *(a+j) ) {
                swap( *(a+i), *(a+j) );
            }
        }

    }
}

void prtA( int a[], int n, int per){
    for(int i = 0; i < n; i++){
        cout<< *(a+i)<<" ";
        if(i%10==(per - 1)) cout<<endl;
    }
    cout<<endl;
}

void fillA( int a[], int n ){
    for(int i =0; i< n; i++){
        *(a+i) = rand() % 90 + 10;
    }
}

void cpy( int *s, int d[], int n){
    for(int i =0; i< n; i++){
        *(d+i) = *(s+i);
    }
}

void swap( int &a, int &b){
    a ^= b;
    b = a ^ b;
    a ^= b;
}

bool find( int *a, int n, int v){
    for(int i =0; i< n; i++){
        if ( *(a+i) == v ) {
            return true;
        }

    }
}