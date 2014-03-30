/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on March 28, 2014, 11:23 PM
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
    cout << count(input) << " is the number of words in the sentence\n";
    return 0;
}

int count(char *a)
{
    int count=1;
    while(*a!='\0')
    {
        if(*a==' ')
            count++;
        a++;
    }
    return count;
}