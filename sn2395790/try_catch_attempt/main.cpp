/* 
 * File:   main.cpp
 * Author: Scott
 *
 * Created on June 8, 2014, 5:36 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    //Declare variables
    int temp=0;
    
    try{
        cout<<"Try statement"<<endl;
        if(temp<5) throw 6;
        cout<<"This shouldnt display"<<endl;
        
    }
    catch(int i){
        cout<<"Exception: "<<i<<" caught"<<endl;
        temp = i;
    }
    
    cout<<"Temp = "<<temp;

    return 0;
}

