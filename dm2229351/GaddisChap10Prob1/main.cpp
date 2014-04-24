/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on March 28, 2014, 9:26 PM
 */

#include <iostream>
#include <string>

using namespace std;

int count(char *);

int main(int argc, char**argv) {

    const int SIZE=51;
    char input[SIZE];
    cout << "Please enter a string to return a count of characters\n";
    cin.getline(input, SIZE);
    cout << count(input) << " is the number of characters in the string\n";
    return 0;
}

int count(char *a)
{
    int count=0;
    while(*a!='\0')
    {
        count++;
        a++;
    }
    return count;
}