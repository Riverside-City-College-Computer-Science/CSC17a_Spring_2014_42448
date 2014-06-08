//Joseph Reimbold
//May 9th, 2014
//Assignment 3

//Our Libraries
#include "Date.h"
#include "Employee.h"
#include "Car.h"
#include "Personal.h"
#include "RetailItem.h"

//Libraries
#include <iostream>
using namespace std;

//No Globals

//Function Prototpyes
void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();

//Problem Function Prototypes


//Begin Main
    int main(int argv,char *argc[])
    {
	int inN;
        do{
         Menu();
         inN=getN();
         switch(inN){
          case 1:    problem1();break;
          case 2:    problem2();break;
          case 3:    problem3();break;
          case 4:    problem4();break;
          case 5:    problem5();break;
          case 6:    problem6();break;
          case 7:    problem7();break;
          default:   def(inN);}
        }while(inN<8);
        return 0;
    }
    void Menu()
    {
           cout<<"Type 1 for Gaddis Chap13 problem 1"<<endl;
           cout<<"Type 2 for Gaddis Chap13 problem 2"<<endl;
           cout<<"Type 3 for Gaddis Chap13 problem 3"<<endl;
           cout<<"Type 4 for Gaddis Chap13 problem 4"<<endl;
           cout<<"Type 5 for Gaddis Chap13 problem 5"<<endl;
           cout<<"Type 6 for Gaddis Chap14 problem 1"<<endl;
           cout<<"Type 7 for Gaddis Chap14 problem 2"<<endl;
           cout<<"Type 8 to exit \n"<<endl;
    }
    int getN()
    {
           int inN;
           cin>>inN;
           return inN;
    }
    void problem1()
    {
        cout<<"In problem 10.1"<<endl<<endl;
        //declare variables
        Date date;
        int d;
        int m;
        int y;
        
        //get date from user
        do{
        cout<<"Enter the Month:";
        cin>>m;
        if(m<1||m>12)cout<<"Invalid Month!"<<endl;
        }while(m<1||m>12);
        do{
        cout<<"Enter the Day:";
        cin>>d;
        if(d<1||d>31)cout<<"Invalid Day!"<<endl;
        }while(d<1||d>31);
        cout<<"Enter the Year:";
        cin>>y;
        
        //Output formats
        date.outOne(d,m,y);
        date.outTwo(d,m,y);
        date.outThree(d,m,y);
        
    }
    void problem2()
    {
        cout<<"In problem 10.2"<<endl<<endl;
        Employee emp1("Susan Meyes",47899,"Accounting","Vice President");
        Employee emp2("Mark Jones",39119,"IT","Programmer");
        Employee emp3("Joy Rogers",81774,"Manufacturing","Engineer");

        emp1.outEmp();
        emp2.outEmp();
        emp3.outEmp();
           
    }
    void problem3()
    {
           cout<<"In problem 10.3"<<endl<<endl;
           //create car class
           Car car(1971,"Datsun");
           
           cout<<car.getYear()<<" "<<car.getMake()<<" test run:"<<endl;
           //accelerate 5 times
           for(int i=0;i<5;i++){
               car.accel();
               car.prntSpd();
           }
           
           //decelerate 5 times
           for(int i=0;i<5;i++){
               car.brake();
               car.prntSpd();
           }
    }
    void problem4()
    {
           cout<<"In problem 10.4"<<endl<<endl;
           //declare variables
           Pdata per1("Joseph Reimbold","5513 Abc Dr",29,"714-123-4567");
           Pdata per2("Stephanie Reimbold","5513 Abc Dr",28,"714-123-4567");
           Pdata per3("Eric De Anda","Country Club Ave",29,"951-123-4567");
           
           //output informations
           per1.prnt();
           per2.prnt();
           per3.prnt();
           
    }
    void problem5()
    {
           cout<<"In problem 10.5"<<endl<<endl;
           //declare variables
           RetailItem item1("Jacket",12,59.95);
           RetailItem item2("Designer Jeans",40,34.95);
           RetailItem item3("Shirt",20,24.95);
           
           //output infos
           item1.prnt();
           item2.prnt();
           item3.prnt();
    }
    void problem6()
    {
           cout<<"In problem 14.1"<<endl<<endl;
           
    }
    void problem7()
    {
		cout<<"In problem 14.2"<<endl<<endl;
                
    }
    void def(int inN)
    {
           cout<<"You typed "<<inN<<" to exit the program"<<endl;
    }