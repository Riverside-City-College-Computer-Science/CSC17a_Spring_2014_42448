/* 
 * File:   main.cpp
 * Author: Abel Salazar
 * Created on March 6, 2014, 3:06 PM
 */

//system libraries
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

//global constants
const float rate1 = .015;
const float rate2 = .01;

//function prototypes

//execution begins here
int main(int argc, char** argv) {
    //variable declaration
    float intrst, total, minPymnt, accBal, temp, totTemp;
    int x = 0;
    //get input for initial balance
    while(x ==0){
        cout << "Enter balance on account" <<endl;
        cin >> accBal;
        
        if(accBal <= 1000)
        {
                intrst = (accBal * rate1);
                temp = accBal + intrst;
                minPymnt = temp * rate2;
                total = accBal + intrst;
                //output minimum payment
                if(temp < 10)
                {
                cout << "Your minimum payment is $" << fixed << setprecision(2)
                        << temp <<endl; 
                cout << "Your total balance is $" << fixed << setprecision(2) <<
                        total <<endl;
                }
                else if(minPymnt <= 10)
                {
                cout << "The minimum possible payment is $10" << endl <<
                    "Your payment is $10" <<endl;
                cout << "Your total balance is $" << fixed << setprecision(2) <<
                        total <<endl;
                }
                else
                {
                cout << "Your minimum payment is $" << fixed << setprecision(2) 
                        << minPymnt <<endl;
                }
                cout << "Total balance with interest is $" << fixed << 
                        setprecision(2) << total <<endl;
        }
        else if(accBal > 1000)
        {
                temp = 1000 * rate1;
                totTemp = (accBal - 1000) * rate2;
                total = accBal + temp + totTemp;
                minPymnt = total * rate2;
                //output total and minimum payment
                cout << "The total owed is $" << fixed << setprecision(2) <<
                        total <<endl;
                cout << "Your minimum payment is $" << fixed << setprecision <<
                        minPymnt <<endl;
        }
        //error checking for non numbers
        else
        {
            cout << "enter a valid number" <<endl;
        }
    }
    //exit stage right
    return 0;
}

