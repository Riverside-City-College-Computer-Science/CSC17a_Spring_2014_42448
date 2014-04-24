/* 
 * File:   main.cpp
 * Author: abel salazar
 */

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

//global constants

//function prototypes
int cvnstr(string);

//execution
int main(int argc, char** argv) {
    //variable declaration
    const int SIZE=50;
    string user;
    char letter[SIZE];
    
    cout << "Enter a string of up to 50 letters" <<endl;
    cin >> user;
    
    int total;
    total = cvnstr(user);
    
    cout << "There are  " << total << " characters in the string" <<endl;
    
    //exit stage
    return 0;
}

int cvnstr(string user){
    int tot = 0;
    tot = user.size();
    return tot;
}