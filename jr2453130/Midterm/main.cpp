/* 
 * File:   main.cpp
 * Author: Joseph Reimbold
 *
 * Created on April 23, 2014, 9:21 AM
 */

//Library includes Here!!!
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

//Global Constants Here!!!

//Structures
struct BankAcc
{
    string acc; //I've tried everything...
    int iBal;
    int chckTot;
    int depTot;    
};

struct Payrate
{
    string name;
    float hours;
    float pay;
    float gross;
};

struct statsResult
{
    float avg;
    float median;
    int *mode;   //array containing the modes
    int nModes;  //number of modes in the array
    int maxFreq; //max frequency of modes
};

//Function Prototypes Here!!!
void Menu();
int gtChoice();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();

//Function Prototypes for Problems
statsResult *avgMedMode(int *,int);
//printStat();

//Begin Execution Here!!!
int main(int argv,char *argc[]){
    int choice;
    do{
        Menu();
        choice=gtChoice();
        switch(choice){
        case 1:    problem1();break;
        case 2:    problem2();break;
        case 3:    problem3();break;
        case 4:    problem4();break;
        case 5:    problem5();break;
        case 6:    problem6();break;
        default:   def(choice);}
    }while(choice>=1&&choice<=6);
    return 0;//If midterm not perfect, return something other than 1
}

void Menu(){
    cout<<"Menu for the Midterm"<<endl;
    cout<<"Type 1 for problem 1"<<endl;
    cout<<"Type 2 for problem 2"<<endl;
    cout<<"Type 3 for problem 3"<<endl;
    cout<<"Type 4 for problem 4"<<endl;
    cout<<"Type 5 for problem 5"<<endl;
    cout<<"Type 6 for problem 6"<<endl;
    cout<<"Type anything else to exit \n"<<endl;
}

int gtChoice(){
    int inN;
    cin>>inN;
    return inN;
}

void problem1(){
    cout<<"In problem # 1"<<endl<<endl;
    
    //Declare Variables
    BankAcc user;
    string accnt;
    int chk, checks, dep, deps, fBal;
    user.chckTot=0;
    user.depTot=0;
    
    //Get user account number
    do{
        cout<<"Enter your 5 digit bank account number: ";
        cin>>user.acc;
        if(user.acc.length()!=5)cout<<"This is not a correct account number."<<endl;
    }while(user.acc.length()!=5);
    
    
    //Get user starting balance
    cout<<"Enter your current balance: $";
    cin>>user.iBal;
    
    //Get user's checks and total
    cout<<"How many checks?: ";
    cin>>checks;
    for(int i=0;i<checks;i++){
        //if(checks==0)break;
        cout<<"Enter check "<<i+1<<" amount: $";
        cin>>chk;
        user.chckTot+=chk;
    }
    
    //Get user's deposits and total
    cout<<"How many deposits?: ";
    cin>>deps;
    for(int j=0;j<deps;j++){
        cout<<"Enter deposit "<<j+1<<" amount: $";
        cin>>dep;
        user.depTot+=dep;
    }
    
    //Calculate end balance and if fee is applied
    fBal=(user.iBal-user.chckTot)+user.depTot;
    if(fBal<0){
        fBal-=12;
        cout<<"You were negative! Enjoy a $12 fee!"<<endl;
    }
    cout<<"Your final balance is $"<<fBal<<endl<<endl;
}

void problem2(){
    cout<<"In problem # 2"<<endl<<endl;
    
    //Declare Variables
    int numEmps;
    
    //Get number of employees
    cout<<"How many employees are there? ";
    cin.ignore();
    cin>>numEmps;
    Payrate emps[numEmps];
    
    for(int i=0;i<numEmps;i++){
        //get name of employee
        cin.ignore();
        cout<<"What is the employee's name?: ";
        getline(cin,emps[i].name);
        
        //get hours worked for employee
        cout<<"How many hours worked?: ";
        do{
            cin>>emps[i].hours;
        }while(emps[i].hours<0);
        
        //get pay rate for employee
        cout<<"Pay rate of employee?: ";
        do{
            cin>>emps[i].pay;
        }while(emps[i].pay<0);
        
        //calculate pay for employee
        if(emps[i].hours>40){
            emps[i].gross=((emps[i].hours-40)*emps[i].pay*3)+(emps[i].pay*2*20)+(emps[i].pay*20);
        }
        else if(emps[i].hours>20){
            emps[i].gross=((emps[i].hours-20)*emps[i].pay*2)+(emps[i].pay*20);
        }
        else{
            emps[i].gross=(emps[i].hours*emps[i].pay);
        }
    }
    
    for(int j=0;j<numEmps;j++){
        //output information to user
        cout<<"Pay Info"<<endl;
        cout<<"Name:         "<<emps[j].name<<endl;
        cout<<"Hours worked: "<<emps[j].hours<<endl;
        cout<<"Pay rate:     "<<emps[j].pay<<endl;
        cout<<"Gross Pay:    $"<<emps[j].gross<<endl;
    }
    cout<<endl;
}

void problem3(){
    cout<<"In problem # 3"<<endl<<endl;
    
    //declare variables
    int size;
    
    //get size of array
    cout<<"How many ints in the array?: ";
    cin>>size;
    int *array=new int[size];
    
    //fill array
    for(int i=0;i<size;i++){
        cout<<"Enter element "<<i<<": ";
        cin>>array[i];
    }
    cout<<endl;
    
    //calculate
    avgMedMode(array,size);
    
    
    delete []array;
}

statsResult *avgMedMode(int *a,int n){
        
    
}



void problem4(){
    cout<<"In problem # 4"<<endl<<endl;
}

void problem5(){
    cout<<"In problem # 5"<<endl<<endl;
}

void problem6(){
    cout<<"In problem # 6"<<endl<<endl;
}

void def(int choice){
    cout<<"You typed "<<choice<<" to exit the program"<<endl;
}