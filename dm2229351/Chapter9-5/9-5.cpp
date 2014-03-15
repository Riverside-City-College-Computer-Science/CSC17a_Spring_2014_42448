/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on March 13, 2014, 11:30 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int doSomething(int*, int*);

int main(int argc, char** argv) {

    int x=3,y=2;
    doSomething(&x,&y);
    cout << x << " " << y;
    return 0;
}

int doSomething(int *x, int *y)
{
    int temp = *x;
    *x=*y*10;
    *y=temp*10;
    return *x+*y;
}