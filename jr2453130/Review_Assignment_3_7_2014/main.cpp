/*  Joseph Reimbold
    November 15, 2013
    Assignment 6
 */

//Libraries
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

//Global Constants


//Function Prototypes
void Menu();
short getChoice();
void dflt(short);
void prob0();
void prob1();
void prob2();
void prob3();
void prob4();
void prob5();
void prob6();
void prob7();
void prob8();
void prob9();



//Begin Execution Here!!!
int main(){
    short choice;
    do{
        Menu();
        choice=getChoice();
        cout<<endl;
        switch(choice){
        case 0:    prob0();break;
        case 1:    prob1();break;
        case 2:    prob2();break;
        case 3:    prob3();break;
        case 4:    prob4();break;
        case 5:    prob5();break;
        case 6:    prob6();break;
        default:   dflt(choice);}
    }while(choice>=0&&choice<=6);
    return 0;
}

void Menu(){
    cout<<"Review Assignment"<<endl;
    cout<<"Type 0 for Gaddis 7th Edition Chapter 3 problem 12"<<endl;
    cout<<"Type 1 for Gaddis 7th Edition Chapter 3 problem 13"<<endl;
    cout<<"Type 2 for Gaddis 7th Edition Chapter 4 problem 10"<<endl;
    cout<<"Type 3 for Gaddis 7th Edition Chapter 5 problem 11"<<endl;
    cout<<"Type 4 for Gaddis 7th Edition Chapter 6 problem 7"<<endl;
    cout<<"Type 5 for Gaddis 7th Edition Chapter 7 problem 6"<<endl;
    cout<<"Type 6 for Gaddis 7th Edition Chapter 8 problem 7"<<endl;
    cout<<"Type anything else to exit \n"<<endl;
}

short getChoice(){
        int n;
        cin>>n;
        return n;
}

//Begin Gaddis 7th Edition Chapter 3 Problem 12
void prob0(){
     //Declare Variables
     string month;
     float ttl;
     
     cout<<"Calculating sales tax!"<<endl<<endl;
     
     cout<<"Enter Month: ";
     cin>>month;
     
     cout<<"How much money was in the register? $";
     cin>>ttl;
     cout<<endl;

     cout<<"Monthly Sales Report"<<endl
         <<"Month: "<<month<<endl
         <<fixed<<setprecision(2)
         <<"Total cash in register: $"<<ttl<<endl
         <<"Total Sales:            $"<<ttl/1.06<<endl
         <<"County Sales Tax (2%):  $"<<(ttl/1.06)*.02<<endl
         <<"State Sales Tax (4%):   $"<<(ttl/1.06)*.04<<endl
         <<"Total Sales Tax:        $"<<ttl-(ttl/1.06)<<endl<<endl;

}//End Gaddis Chap3 Prob12


//Begin Gaddis 7th Edition Chapter 3 Problem 13
void prob1(){
     //Declare Variables
     float val, aval, tax=6.4e-1f, ptax;
     
     //get property value from user
     cout<<"What is the value of the property?"<<endl;
     cin>>val;
     
     //Calculate property tax
     aval=val*6.0e-1f;
     ptax=(aval/100)*tax;
     
     cout<<setprecision(2)<<fixed;
     cout<<"The assessment value of the property is $"<<aval<<"."<<endl;
     cout<<"The property tax for this property is $"<<ptax<<"."<<endl<<endl;
     
}//End Gaddis Chap3 Prob13


//Begin Gaddis 7th Edition Chapter 4 Problem 10
void prob2(){
     
}//End Gaddis Chap4 Prob10


//Begin Gaddis 7th Edition Chapter 5 Problem 11
void prob3(){
     
}//End Gaddis Chap5 Prob 11


//Begin Gaddis 7th Edition Chapter 6 Problem 7
void prob4(){
     
}//End Gaddis Chap6 Prob7


//Begin Gaddis 7th Edition Chapter 7 Problem 6
void prob5(){
     
}//End Gaddis Chap7 Prob6


//Begin Gaddis 7th Edition Chapter 8 Problem 7
void prob6(){
     
}//End Gaddis Chap8 Prob7

void dflt(short val){
        cout<<"You typed "<<val<<" to exit the program"<<endl;
}
