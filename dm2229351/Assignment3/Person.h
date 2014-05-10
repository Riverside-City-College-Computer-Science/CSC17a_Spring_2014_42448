/* 
 * File:   Person.h
 * Author: diegomontelongo
 *
 * Created on May 8, 2014, 12:06 AM
 */
#include <iostream>
using namespace std;

#ifndef PERSON_H
#define	PERSON_H

class Person{
private:
    string name;
    int age;
    string address;
    string phone;
public:
    Person(string,int,string,string);
    void setName(string);
    void setAge(int);
    void setAddress(string);
    void setPhone(string);
    string getName(){return name;}
    int getAge(){return age;}
    string getAddress(){return address;}
    string getPhone(){return phone;}
    void print();
};

#endif	/* PERSON_H */

