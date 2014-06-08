//Libraries
#include "Employee.h"
#include <iostream>
#include <cstdlib>
using namespace std;

//Constructors
Employee::Employee(){
    name="";
    idNumber=0;
    department="";
    position="";
}
Employee::Employee(string n,int i, string d, string p){
    //set based on user input
    name=n;
    idNumber=i;
    department=d;
    position=p;
}
Employee::Employee(string n,int i){
    name=n;
    idNumber=i;
    department="";
    position="";
}

//Mutators
void Employee::setName(string n){
    name=n;
}

void Employee::setId(int i){
    idNumber=i;
}

void Employee::setDept(string d){
    department=d;
}

void Employee::setPos(string p){
    position=p;
}

//Accessors
string Employee::getName() const{
    return name;
}

int Employee::getId() const{
    return idNumber;
}

string Employee::getDept() const{
    return department;
}

string Employee::getPos() const{
    return position;
}

void Employee::outEmp() const{
    cout<<getName()<<endl;
    cout<<getId()<<endl;
    cout<<getDept()<<endl;
    cout<<getPos()<<endl<<endl;
}