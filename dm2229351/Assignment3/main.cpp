//Dr. Mark E. Lehr
//April 21st, 2014
//Menu to be used for the midterm
//homework and final, etc....

//Library includes Here!!!
#include <iostream>
using namespace std;

#include "Car.h"
#include "Date.h"
#include "Employee.h"
#include "Person.h"
#include "RetailItem.h"
#include "Numbers.h"
#include "DayOfYear.h"

//Global Constants Here!!!

//Function Prototypes Here!!!
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
void problem8();
void problem9();
void problem10();

//Begin Execution Here!!!
int main(int argv,char *argc[]){
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
        case 8:    problem8();break;
        case 9:    problem9();break;
        case 10:   problem10();break;
        default:   def(inN);}
    }while(inN>=1&&inN<=10);
    return 0;//If midterm not perfect, return something other than 1
}

void Menu(){
    cout<<"\nMenu for the Midterm"<<endl;
    cout<<"Type 1 for problem 10-1"<<endl;
    cout<<"Type 2 for problem 10-2"<<endl;
    cout<<"Type 3 for problem 10-3"<<endl;
    cout<<"Type 4 for problem 10-4"<<endl;
    cout<<"Type 5 for problem 10-5"<<endl;
    cout<<"Type 6 for problem 11-1"<<endl;
    cout<<"Type 7 for problem 11-2"<<endl;
    cout<<"Type 8 for problem 11-3"<<endl;
    cout<<"Type 9 for problem 11-4"<<endl;
    cout<<"Type 10 for problem 11-5"<<endl;
    cout<<"Type anything else to exit \n"<<endl;
}

int getN(){
        int inN;
        cin>>inN;
        return inN;
}

void problem1(){
    cout<<"In problem # 10-1"<<endl<<endl;
    int day=-1, month=-1, year=-1;
    while((month<1 || month >12))
    {
        cout << "Please enter a month (1-12)" << endl;
        cin >> month;
    }
    while((day<1 || day >31))
    {
        cout << "Please enter a day (1-31)" << endl;
        cin >> day;
    }
    cout << "Please enter a year" << endl;
    cin >> year;
    
    Date date(day,month,year);
    date.printDateDashes();
    date.printDateDayFirst();
    date.printDateMonthFirst();

}

void problem2(){
    cout<<"In problem # 10-2"<<endl<<endl;
    Employee emp1("Susan Meyes",47899,"Accounting","Vice President");
    Employee emp2("Mark Jones",39119,"IT","Programmer");
    Employee emp3("Joy Rogers",81774,"Manufacturing","Engineer");
    
    emp1.printEmployee();
    emp2.printEmployee();
    emp3.printEmployee();
}

void problem3(){
    cout<<"In problem # 10-3"<<endl<<endl;
    Car car(2006,"Chrysler 300");
    for(int i=0;i<5;i++)
    {
        car.accelerate();
        car.print();
    }
    for(int i=0;i<5;i++)
    {
        car.brake();
        car.print();
    }
}

void problem4(){
    cout<<"In problem # 10-4"<<endl<<endl;
    Person me("Diego Montelongo", 31, "12533 Black Horse St", "909-524-8487");
    me.print();
    Person friend1("Uni Aguilar",33,"1033 Cambrin Rd", "951-342-6578");
    friend1.print();
    Person brother("Fermin Montelongo",36,"2015 Sastre Ave", "909-732-7497");
    brother.print();
}

void problem5(){
    cout<<"In problem # 10-5"<<endl<<endl;
    RetailItem r1("Jacket", 12, 59.95);
    RetailItem r2("Designer Jeans", 40, 34.95);
    RetailItem r3("Shirt", 20, 24.95);
    cout << "Item\t\t" << "Description\t\t" << "Units on Hand\t\t" << "Price" << endl;
    r1.print(1);
    r2.print(2);
    r3.print(3);
}

void problem6(){
    int number=-1;
        cout<<"In problem # 11-1"<<endl<<endl;
        while(number<0 || number>9999)
        {
            cout << "Please enter a number from 0 to 9999\n";
            cin >> number;
        }
    Numbers num1(number);
    num1.print();
}

void problem7(){
        cout<<"In problem # 11-2"<<endl<<endl;
            DayOfYear day1(45);
    DayOfYear day2(85);
    DayOfYear day3(125);
    DayOfYear day4(165);
    DayOfYear day5(254);
    DayOfYear day6(365);
    
    day1.print();
    day2.print();
    day3.print();
    day4.print();
    day5.print();
    day6.print();
}

void problem8(){
        cout<<"In problem # 11-3"<<endl<<endl;
        int number;
        string month;
        cout << "Please enter a day" << endl;
        cin >> number;
        cout << "Please enter a month" << endl;
        cin >> month;
        DayOfYear x(number,month);
        cout << x.getDay() << " is the day" << endl;
        x++;
        cout << x.getDay() << " is the day after ++" << endl;
        x--;
        cout << x.getDay() << " is the day after --" << endl;
}

void problem9(){
        cout<<"In problem # 11-4"<<endl<<endl;
}

void problem10(){
        cout<<"In problem # 11-5"<<endl<<endl;
}
void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;

}