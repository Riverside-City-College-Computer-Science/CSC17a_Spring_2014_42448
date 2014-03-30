/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on March 7, 2014, 7:49 PM
 * Gaddis, 7th Edition - Chapter 5, Problem 11
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Define local constants & variables
    int iNumOrg, iNumDys, dayCnt=0; 
    float orgCnt=0;
    float iInc, pctInc;
    //Get user input
    cout << "Starting size of the population: ";
    cin >> iNumOrg;
    if (iNumOrg >= 2) {
        cout << "Average daily population increase (%): ";
        cin >> iInc;
        if (iInc >= 0) {
            cout << "Number of days they will multiply: ";
            cin >> iNumDys;
            if (iNumDys >= 1) {
                cout << setprecision(0) << fixed;
                orgCnt = iNumOrg;
                pctInc = iInc/100.0;
                cout << "Day: " << dayCnt<< " Organisms: " << orgCnt << endl;
                do {
                    orgCnt += (orgCnt * pctInc);
                    dayCnt++;
                    cout << "Day: " << dayCnt<< " Organisms: " 
                         << orgCnt << endl;
                } while (dayCnt < iNumDys);
            } else
                cout << "Invalid number of days to multiply." << endl;
        } else
            cout << "Invalid daily population increase." << endl;
    } else
        cout << "Invalid number of organisms." << endl;
    //Exit, stage right!
    return 0;
}

