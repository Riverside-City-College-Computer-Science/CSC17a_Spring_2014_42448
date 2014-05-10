#include "Person.h"

Person::Person(string n,int a,string addy,string num)
{
    name=n;
    age=a;
    address=addy;
    phone=num;
}
void Person::setName(string n)
{
    name=n;
}
void Person::setAge(int a)
{
    age=a;
}
void Person::setAddress(string a)
{
    address=a;
}
void Person::setPhone(string p)
{
    phone=p;
}
void Person::print()
{
    cout << name << endl;
    cout << age << endl;
    cout << address << endl;
    cout << phone << endl;
}