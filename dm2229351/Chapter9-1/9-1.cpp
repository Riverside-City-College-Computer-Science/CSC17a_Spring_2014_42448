/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on March 13, 2014, 10:57 PM
 */

#include <cstdlib>

using namespace std;

/*
 * 
 */
int* array (int);
int main(int argc, char** argv) {

    array(20);
    return 0;
}

int *array(int size)
{
    int *a=new int[size];
    return a;
}