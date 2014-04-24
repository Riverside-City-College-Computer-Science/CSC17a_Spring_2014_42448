/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on March 29, 2014, 2:02 PM
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

struct movie2{
        string title;
        string director;
        int release;
        int runtime;
        int production;
        int revenue;
};

void printmovie2(movie2);
int main(int argc, char** argv) {

    
    movie2 movie1={"Diego Movie", "Diego", 1982, 200,50000,100000};
    movie2 movie2={"Jerry Movie", "Jerry", 2000, 240,100000,50000};
    printmovie2(movie1);
    printmovie2(movie2);
    return 0;
}

void printmovie2(movie2 mov)
{
    int net=mov.revenue-mov.production;
    cout << "Title: " << mov.title << endl;
    cout << "Director: " << mov.director << endl;
    cout << "Release Year: " << mov.release << endl;
    cout << "Runtime: " << mov.runtime << endl;
    if(net>0)
        cout << "Profit: " << net;
    else
        cout << "Loss: " << abs(net);
    cout << endl;
}