/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on April 24, 2014, 11:08 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
const int ArSize = 200;
int main(int argc, char** argv) {
    int a=1;
    short b=1;
    long c=1;
    float d=1;
    double e=1;
    
    short factorials[ArSize];
    factorials[1] = factorials[2] = 1.0;
    int i;

    for (i = 2; i < ArSize; i++)
        factorials[i] = i * factorials[i-1];
    for (i = 0; i < ArSize; i++)
        cout << i << " ! = " << factorials[i] << "\n";


    return 0;
}

