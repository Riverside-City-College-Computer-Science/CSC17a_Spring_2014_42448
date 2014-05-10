/* 
 * File:   Personal.h
 * Author: Joe
 *
 * Created on May 9, 2014, 4:16 PM
 */

#include <string>
using namespace std;

#ifndef PERSONAL_H
#define	PERSONAL_H

class Pdata
{
private:
    string name;
    string address;
    int age;
    string phone;
public:
    //Constructor
    Pdata(string,string,int,string);
    //Mutators
    void setName(string);
    void setAge(int);
    void setAddress(string);
    void setPhone(string);
    //Accessorts
    string getName() const;
    int getAge() const;
    string getAddress() const;
    string getPhone()const;
    void prnt() const;
};
#endif	/* PERSONAL_H */

