/* 
 * File:   main.cpp
 * Author: abel salazar
 * Created on March 25, 2014, 11:47 PM
 */

#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

//structures
struct MovieData{
    string Title;
    string Director;
    int Year;
    int Minutes;
};

//global constants

//function prototypes
void fillDat(MovieData &);
void prntDat(MovieData);


//execution 
int main(int argc, char** argv) {
    //variable declaration
    MovieData first;
    MovieData second;
    
    fillDat(first);
    fillDat(second);
    
    cout << "The first movie "<<endl;
    prntDat(first);
    cout << "The second movie" <<endl;
    prntDat(second);
    
    //exit stage
    return 0;
}

//prints the data out
void prntDat(MovieData movie){
    cout << endl;
    cout << fixed << setprecision(2)<<endl;
    cout << movie.Title << endl;
    cout << movie.Director<<endl;
    cout << movie.Year<<endl;
    cout << movie.Minutes<<endl;
    cout << endl;
}

//gets input for movie data
void fillDat(MovieData & movie){
    cout << endl;
    cout << "Enter the title of the movie" << " ";
    cin >> movie.Title;
    cout << "Enter the director's name" << " ";
    cin >> movie.Director;
    cout << "Enter the year the film was released" << " ";
    cin >> movie.Year;
    cout << "Enter the running time of the film in minutes" << " ";
    cin >> movie.Minutes;
    cout << endl;
    
}