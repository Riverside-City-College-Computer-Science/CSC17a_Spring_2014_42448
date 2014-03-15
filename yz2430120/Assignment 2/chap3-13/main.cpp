/* 
 * File:   main.cpp
 * Author: Zhang,Yi
 *
 * Created on March 2, 2014, 9:36 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;


int main(int argc, char** argv) {
    float value,assessment,tax;
    cout << setprecision(2) << fixed << showpoint;
    cout<<"the actual value (type in)";
    cin>>value;
    assessment=0.6*value;
    tax=64*assessment/10000;
    cout<<"the assessment value is "<<assessment<<endl;
    cout<<"the tax is "<<tax<<endl;
    return 0;
}

