//Libraries
#include "Personal.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Pdata::Pdata(string n,string add,int a,string p){
    setName(n);
    setAddress(add);
    setAge(a);
    setPhone(p);
}

void Pdata::setName(string n){
    name=n;
}

void Pdata::setAddress(string add){
    address=add;
}

void Pdata::setAge(int a){
    age=a;
}

void Pdata::setPhone(string p){
    phone=p;
}

string Pdata::getName() const{
    return name;
}

string Pdata::getAddress() const{
    return address;
}

int Pdata::getAge() const{
    return age;
}

string Pdata::getPhone() const{
    return phone;
}

void Pdata::prnt() const{
    cout<<"Info:"<<endl;
    cout<<"Name:    "<<getName()<<endl
        <<"Address: "<<getAddress()<<endl
        <<"Age:     "<<getAge()<<endl
        <<"Phone:   "<<getPhone()<<endl<<endl;
}