/* 
 * File:   main.cpp
 * Author: Scott Nevin
 * Purpose: Collect sales data and print report
 * Created on March 4, 2014
 */

//Libraries
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
using namespace std;

//Global constants and variables

//Function prototypes
void input(string &, string &, float &);
float calc(float, float &, float &);
void output(string, string, float, float, float, float);

int main(int argc, char** argv) {
    
    //Declare Variables
    string mnth, year;
    float totSls, sales, stTax, cntTax;
    
    //Gather input
    input (mnth, year,totSls);
    
    //Calculate tax collected and total sales
    sales = calc(totSls, stTax, cntTax);
    
    //output sales report
    output(mnth, year, totSls, sales, stTax, cntTax);

    return 0;
}

void input(string &m, string &y, float &t){
    
    //Collect month and year information
    cout<<"Input the Month and Year you would like a report for:"<<endl;
    cout<<"Month: ";
    cin>>m;
    cout<<"Year: ";
    cin>>y;
    cout<<endl;
    
    //collect sales information
    cout<<"Input total Sales amount (including tax) for ";
    cout<<m<<", "<<y<<endl;
    cout<<"$";
    cin>>t;  
}

float calc(float tot, float &st, float &cnty){
    
    //Declare variable for sales
    float s;
    
    //calculate product sales from total sales
    s = tot / 1.06;
    
    //Calculate state tax and county tax
    st = s * .04;//state sales tax of 4%
    cnty = s * .02;//county sales tax of 2%
       
    return s;
}

void output(string m, string y, float tot, float sls, float st, float cnt){
    
    cout<<"Sales Report"<<endl;
    cout<<"Month: "<<m<<endl;
    cout<<"---------------------"<<endl;
    cout<<"Total Collected: "<<setw(4)<<"$"<<setw(10)<<setprecision(2)<<showpoint<<fixed<<tot<<endl;
    cout<<"Sales: "<<setw(14)<<"$"<<setw(10)<<sls<<endl;
    cout<<"County Sales Tax: "<<setw(3)<<"$"<<setw(10)<<cnt<<endl;
    cout<<"State Sales Tax: "<<setw(4)<<"$"<<setw(10)<<st<<endl;
    cout<<"Total Sales Tax: "<<setw(4)<<"$"<<setw(10)<<st+cnt<<endl;
    
}