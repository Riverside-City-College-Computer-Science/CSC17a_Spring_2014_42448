/* 
 * File:   main.cpp
 * Author: lenovo
 *
 * Created on March 2, 2014, 8:46 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;


int main(int argc, char** argv) {
    ifstream input;
    int array[6],count=0;
    //input
    input.open("abc.txt");
    while(count<6){
    input>>array[count];
    count++;
    }
    //display
    cout<<"Display those number"<<endl;
    for(int a=0;a<6;a++)
    cout<<array[a]<<endl;
    //low
    int low;
    low=array[0];
    for(int a=1;a<6;a++){
        
        if (array[a]<low)
            low=array[a];
        
    }
    cout<<"the lowest"<<endl;
    cout<<low<<endl;
    //high
    int high;
    high=array[0];
    for(int a=1;a<6;a++){
        
        if (array[a]>high)
            high=array[a];
        
    }
    cout<<"the highest"<<endl;
    cout<<high<<endl;
    //total
    int total=0;
      for(int a=0;a<6;a++){
        
         total=total+array[a];
        
    }
    cout<<"the total"<<endl;
    cout<<total<<endl;
    //average
    float average;
    average=static_cast<float>(total)/6;
    cout<<"the average"<<endl;
    cout<<average<<endl;
    
    input.close();
    return 0;
}

