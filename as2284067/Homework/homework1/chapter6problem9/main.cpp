/* 
 * File:   main.cpp
 * Author: Abel Salazar
 * Created on March 6, 2014, 6:21 PM
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;
//global constant

//function prototype
void randNum(int [], int);
void filldat(int [], int);
void readDat(string &);

//execution begins here
int main(int argc, char** argv) {
    srand(time(0));
    string file;
    int SIZE = 10;
    int array[SIZE];
    
    //randNum(array, SIZE);
    //filldat(array, SIZE);
    
    readDat(file);
    
    //exit stage right
    return 0;
}

void readDat(string & line){
    ifstream myfile("grades.dat");
    if(myfile.is_open()){
        while(getline(myfile, line)){
                cout << line <<"\n";
        }
    myfile.close();
    }else{
        cout << "Unable to open file"<<endl;
    }
}

//used to fill data randomly
void filldat(int array[], int size){
    ofstream myfile;
    myfile.open("grades.dat");
    myfile << "Salazar Abel ";
    for(int i=0;i<size;i++){
        myfile << array[i] << " ";
    }
    myfile.close();
}

//generates numbers for array
void randNum(int a[], int n){
    for(int i=0;i<n;i++){
        a[i]=rand()%10+1;
    }
}
