/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on April 10, 2014, 1:00 PM
 */

//Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

//Global variables and constants

//Function prototypes

//Begin execution here
int main(int argc, char** argv) {
    
    //Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables
    unsigned int num, rep=0;
    int SIZE = 10;
    int freq[SIZE];
    
    //Set frequency array to all zero values
    for(int i=0;i<10;i++){
        freq[i]=0;
    }
    //Record the start time
    int strTime=time(0);
    
    //initiate random number generator loop
    do{
        //Generate number
        num=rand();
        
        //test ranges
        if(num<pow(10,10)&&num>pow(10,9)){
            freq[9]++;
        }
        else if(num<pow(10,9)&&num>pow(10,8)){
            freq[8]++;
        }
        else if(num<pow(10,8)&&num>pow(10,7)){
            freq[7]++;
        }
        else if(num<pow(10,7)&&num>pow(10,6)){
            freq[6]++;
        }
        else if(num<pow(10,6)&&num>pow(10,5)){
            freq[5]++;
        }
        else if(num<pow(10,5)&&num>pow(10,4)){
            freq[4]++;
        }
        else if(num<pow(10,4)&&num>pow(10,3)){
            freq[3]++;
        }
        else if(num<pow(10,3)&&num>pow(10,2)){
            freq[2]++;
        }
        else if(num<pow(10,2)&&num>pow(10,1)){
            freq[1]++;
        }
        else if(num<pow(10,1)&&num>pow(10,0)){
            freq[0]++;
        }
        rep++;
    }while(num>pow(10,2));
    
    //Take the time it took
    int endTime=time(0);
    cout<<"The total time taken = "<<endTime-strTime<<" (secs)"<<endl;
    cout<<"Number of values tested = "<<rep<<endl;
    
    //output statistical results
    cout<<"integer value <10^10 occurred: "<<freq[9]<<" times"<<endl;
    cout<<"integer value <10^9  occurred: "<<freq[8]<<" times"<<endl;
    cout<<"integer value <10^8  occurred: "<<freq[7]<<" times"<<endl;
    cout<<"integer value <10^7  occurred: "<<freq[6]<<" times"<<endl;
    cout<<"integer value <10^6  occurred: "<<freq[5]<<" times"<<endl;
    cout<<"integer value <10^5  occurred: "<<freq[4]<<" times"<<endl;
    cout<<"integer value <10^4  occurred: "<<freq[3]<<" times"<<endl;
    cout<<"integer value <10^3  occurred: "<<freq[2]<<" times"<<endl;
    cout<<"integer value <10^2  occurred: "<<freq[1]<<" times"<<endl;
    cout<<"integer value <10^1  occurred: "<<freq[0]<<" times"<<endl;
    
    //Exit stage right
    return 0;
}

