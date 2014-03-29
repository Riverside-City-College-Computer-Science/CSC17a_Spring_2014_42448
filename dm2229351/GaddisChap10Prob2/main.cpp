/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on March 28, 2014, 9:55 PM
 */
#include <iostream>
#include <string>

using namespace std;

void count(char *);

int main(int argc, char**argv) {

    const int SIZE=51;
    char input[SIZE];
    char copy[SIZE];
    cout << "Please enter a string to return a count of characters\n";
    cin.getline(input, SIZE);
    count(input);
    cout << input << " is the string backwards\n";
    return 0;
}

void count(char *a)
{
    char *front = a;
    char *back = a + strlen(a)-1;
    while(front<back)
    {
        char tmp = *front;
        *front++=*back;
        *back-- = tmp;
    } 
}