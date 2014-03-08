/*  Scott Nevin
 *  March 6, 2014
 *  Purpose: Convert to foregin currencies
*/

//Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants and Variables
const float YEN_PER_DOLLAR = 8.314e1f;
const float EUROS_PER_DOLLAR = 7.337e-1;

//Execution begins here
int main(){

    //Declare variables
    float usd, yen, euros;

    //Prompt user for dollar amount to be converted
    cout<<"Enter amount to be converted in US Dollars."<<endl;
    cout<<"$";
    cin>>usd;

    //calculate conversions
    yen = usd * YEN_PER_DOLLAR;
    euros = usd * EUROS_PER_DOLLAR;

    //Output results
    cout<<"$"<<setprecision(2)<<fixed<<usd<<" = "<<setprecision(2)<<fixed<<yen<<" Yen"<<endl;
    cout<<"$"<<setprecision(2)<<fixed<<usd<<" = "<<setprecision(2)<<fixed<<euros<<" Euros"<<endl;

    //exit main
    return 0;
}

