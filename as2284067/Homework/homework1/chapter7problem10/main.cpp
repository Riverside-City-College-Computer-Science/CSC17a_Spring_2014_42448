/* 
 * File:   main.cpp
 * Author: Abel Salazar
 * Created on March 6, 2014, 7:58 PM
 */

#include <iostream>
#include <cstdlib>

using namespace std;
//global constants
const int ROWS=10;
const int COLS=10;

//function prototype

//execution begins here
int main(int argc, char** argv) {
    int array[ROWS][COLS]={};
    int count=0;
    int count1=0;
    
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            array[i][j]=0+'A';
        }
    }
    for(int a=0;a<ROWS;a++){
        cout << count << "|";
        count++;
        for(int b=0;b<COLS;b++){
            count1++;
            cout << array[a][b]<<" ";
            if(count1%10==0)cout<<endl;
        }
    }
    
    //exit stage right
    return 0;
}

