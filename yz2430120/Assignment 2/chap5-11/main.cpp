/* 
 * File:   main.cpp
 * Author: Zhang,Yi
 *
 * Created on March 2, 2014, 7:38 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;


int main(int argc, char** argv) {
    int number,days;
    float percentage;
    char again;
    do{
    cout<<"Enter the starting number of organisms: ";
    cin>>number;
    while (number<2){
        cout<<"Try again:";cin>>number;
    }
    cout<<"Enter the average increase in percentage:";
    cin>>percentage;
    while (percentage<0){
        cout<<"Try again:";cin>>percentage;
    }
    cout<<"How many days do you want?"<<endl;
    cin>>days;
     while (days<1){
        cout<<"Try again:";cin>>days;
    }
    for(int a=1;a<=days;a++){
        int population=number*(percentage/100+1);
        cout<<"The population for day "<<a<<" is "<<population<<endl;
        number=population;
    }
    cout<<"Press \"y\" if you want to do again"<<endl;
    cin>>again;
    }while(again=='y');
    return 0;
}

