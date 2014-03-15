/* 
 * File:   main.cpp
 * Author: michael
 *
 * Created on February 24, 2014, 3:08 PM
 */

#include <cstdlib>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

/*
 * 
 */
const int NUM7=4;

void p3_12();
void p4_10();
void p5_10();
void p7_7();
void p8_1();
void fillN7(float sales[][NUM7], int s);
void printN7(float sales[][NUM7], int s);
void bubbleSort( int arr[], int s );
int binarySearch( int arr[], int size, int val );
void swap1( int &n1, int &n2 );

void Menu()
    {
           cout<<"Type 1-5 for problem 1-5"<<endl;
           cout<<"Type 6 to exit \n"<<endl;
    }
int getN()
    {
           int inN;
		   cin>>inN;
           return inN;
    }

int main( int argc, char** argv ) {
    int inN;
        do {
            Menu();
            inN=getN();
            switch(inN){
                case 1:    p3_12();break;
                case 2:    p4_10();break;
                case 3:    p5_10();break;
                case 4:    p7_7();break;
                case 5:    p8_1();break;
                default:   cout<<"done\n";
            }
        }
        while( inN < 6 );
    return 0;
}

void p3_12(){
    //set up the ticket prices
    const float at = 6.00, ct = 3.00;
    //tickets sold
    int ats, cts;
    //make the profit var
    float gross, income;
    string movie;
    //ask for info
    cout<<"Enter the movie name\n";
    cin>>movie;
    cout<<"Enter the amount of adult tickets sold\n";
    cin>>ats;
    cout<<"Enter the amount of child tickets sold\n";
    cin>>cts;
    gross = (ats * at) + (cts * ct);
    income = gross * .20;
    //format and print
    cout<<"Movie name:            "<<setw(10)<<movie<<
            "\nadult tickets sold   "<<setw(10)<<ats<<
            "\nchild tickets sold   "<<setw(10)<<cts<<
            "\ngross profit         "<<setw(8)<<"$"<<gross<<
            "\nnet profit           "<<setw(8)<<"$"<<income<<
            "\namount to distributor"<<setw(8)<<"$"<<gross - income<<endl;
}

void p4_10(){
    cout<< "enter a amount to buy ";
    int amt;
    cin >> amt;
    while(amt<1){
        cout<<"Cant buy 0 buy more than 0";
        cin>>amt;
    }
    cout << "discount of ";
    if ( amt >= 10 && amt < 20 ) {
        cout << "20%";
    }
    else if ( amt >= 20 && amt < 50 ) {
        cout << "30%";
    }
    else if ( amt >= 50 && amt < 100 ) {
        cout << "40%";
    }
    else if ( amt >= 100 ) {
        cout << "50%";
    }
    else{
        cout << "none";
    }
    cout<<endl;
}

void p5_10(){
        short years;
        int m;//month loop
        int tr=0,r=0;//rain
        cout<<"how many years of rainfall are you going to average\n";
        cin>>years;
        while(years<1){
            cout<<"Cant average zero years re-enter years\n";
            cin>>years;
        }
        
        //loop for years;
        for(int y=1;y<=years;y++){
            
            for(m=1;m<=12;m++){
                
                cout<<"How many inches of rain did you get in month "<<m<<endl;
                cin>>tr;
                while(tr<0){
                    cout<<"you cant have negative measures, re-enter the number of inches\n";
                    cin>>tr;
                }
                r+=tr;
            }
        }
        cout<<r<<endl;
        r=r/(years*12);
        cout<<"the average amount of rain is: "<<r<<"in\n";
        
}

void p7_7(){
  const int divs = 6;  
  float sales[divs][NUM7];
  fillN7(sales, divs);
  printN7(sales, divs);
}


void fillN7(float sales[][NUM7], int s){
    char random='n';
    cout<<"Enter y to fill out numbers or enter n to randomize it\n";
    cin>>random;
    if(random=='y'){
        for(int i=0; i<s; i++){
            cout<<"Division #"<<i+1<<endl;
            for(int x=0;x<NUM7; x++){
                cout<<"Enter the sales for quarter "<<x+1<<endl;
                cin>>sales[i][x];
            }
        }
    }else{
        for(int i=0; i<s; i++){
            for(int x=0;x<NUM7; x++){
                sales[i][x]=(rand()%99+10)+((rand()%98+10)/100.0f);
            }
        }
    }
    ofstream out;
    out.open("num7.txt");
    for(int i =0; i<s; i ++){
        for(int x=0; x<NUM7; x++){
            out<<sales[i][x]<<" ";
        }
        out<<endl;
    }
    out.close();
    
}

void printN7(float sales[][NUM7], int s){
    float sum[s];
    float diff=0;
    float com[s];//com short of company
    for(int i=0; i<s; i++){
        com[i]=0;
    }
    for(int i=0; i<s; i++){
        cout<<"Division "<<i+1<<endl;
        for(int x=0;x<NUM7; x++){
            if(x!=0){
                diff=sales[i][x]-sales[i][x-1];
            }
            cout<<setprecision(2)<<fixed<<"\tQuarter "<<x+1<<" $"<<sales[i][x]<<"\tDifference  $"<<diff<<endl;
            sum[i]+=sales[i][x];
            diff=0;
        }
    }
    //print sum for each division
    for(int i=0; i<s;i++){
        cout<<"Total sales for division "<<i+1<<" is $"<<sum[i]<<endl;
    }

}

void p8_1(){
    const int size = 18;
    int accounts[size] = {5658845, 8080152, 1005231, 4520125, 4562555, 6545231, 7895122, 5552012, 3852085, 8777541, 5050552, 7576651, 8451277, 7825877, 7881200, 1302850, 1250255, 4581002};
    cout << "enter a account number\n";
    int testaccount;
    cin >> testaccount;
    bubbleSort( accounts, size );
    if ( binarySearch( accounts , size, testaccount ) != -1 ) {
        cout << testaccount << " was a valid account number\n";
    }
    else{
        cout << testaccount << " was not a valid account number\n";
    }
}

void bubbleSort( int arr[], int s ) {
    bool swaped = false;

    do {
        swaped = false;
        for ( int i = 0; i < s - 1; i++ ) {
            if ( *(arr+i) > *(arr+(i + 1)) ) {
                swap( *(arr + i), *(arr + (i + 1) ) );
                swaped = true;
            }

        }
    }    while ( swaped );
}

int binarySearch( int arr[], int size, int val ) {
    int first = 0, last = size - 1;
    int mid;

    bool found = false;

    while ( !found && first <= last ) {
        mid = ( first + last ) / 2;
        if ( arr[mid] == val ) {
            found = true;
            return mid;
        } else if ( arr[mid] > val ) {
            last = mid - 1;
        } else {
            first = mid + 1;
        }
    }
    return -1;
}
void swap1( int &n1, int &n2 ) {
    n1 ^= n2;
    n2 = n1 ^ n2;
    n1 ^= n2;
}