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
    float Cost;
    float FirstYear;
    float Profit;
};

//global constants

//function prototypes
void fillDat(MovieData &);
void prntDat(MovieData);
void profits(MovieData &);


//execution 
int main(int argc, char** argv) {
    //variable declaration
    MovieData first;
    MovieData second;
    MovieData third;
    MovieData fourth;
    
    //filling data and adding up total profits
    fillDat(first);
    profits(first);
    fillDat(second);
    profits(second);
    fillDat(third);
    profits(third);
    fillDat(fourth);
    profits(fourth);
    
    //prints all data for the 4 movies
    cout << "The first movie "<<endl;
    prntDat(first);
    cout << "The second movie" <<endl;
    prntDat(second);
    cout << "Third movie" <<endl;
    prntDat(third);
    cout << "Fourth movie" <<endl;
    prntDat(fourth);
    
    
    //exit stage
    return 0;
}

//calculates profit
void profits(MovieData &movie){
    movie.Profit = movie.FirstYear - movie.Cost;
}


//prints the data out
void prntDat(MovieData movie){
    cout << endl;
    cout << fixed << setprecision(2)<<endl;
    cout << "Title               |" <<movie.Title << endl;
    cout << "Director            |" <<movie.Director<<endl;
    cout << "Produced            |" <<movie.Year <<endl;
    cout << "Time                |" <<movie.Minutes<<endl;
    cout << "COST                |" << movie.Cost<<endl;
    cout << "FIRST YEAR REVENUE  |" << movie.FirstYear<<endl;
    cout << "PROFIT              |" <<movie.Profit<<endl;
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
    cout << "Enter the production cost" << " ";
    cin >> movie.Cost;
    cout << "Enter the first year's revenue" << " ";
    cin >> movie.FirstYear;
    cout << endl;
    
}