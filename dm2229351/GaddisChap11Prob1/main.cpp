/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on March 29, 2014, 1:51 PM
 */

#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

struct movie{
        string title;
        string director;
        int release;
        int runtime;
};

void printmovie(movie);
int main(int argc, char** argv) {

    
    movie movie1={"Diego Movie", "Diego", 1982, 200};
    movie movie2={"Jerry Movie", "Jerry", 2000, 240};
    printmovie(movie1);
    printmovie(movie2);
    return 0;
}

void printmovie(movie mov)
{
    cout << "Title: " << mov.title << endl;
    cout << "Director: " << mov.director << endl;
    cout << "Release Year: " << mov.release << endl;
    cout << "Runtime: " << mov.runtime << endl;
    cout << endl;
}

