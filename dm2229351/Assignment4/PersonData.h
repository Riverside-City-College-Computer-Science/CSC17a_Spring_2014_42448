/* 
 * File:   PersonData.h
 * Author: Diego
 *
 * Created on May 18, 2014, 8:59 PM
 */
#include <iostream>

using namespace std;

#ifndef PERSONDATA_H
#define	PERSONDATA_H

class PersonData{
protected:
    string lastName;
    string firstName;
    string address;
    string city;
    string state;
    int zip;
    string phone;
public:
    PersonData(string l, string f, string a, string c, string s, int z, string p)
    {lastName=l;firstName=f;address=a;city=c;state=s;zip=z;phone=p;}
    string getLastName(){return lastName;}
    string getFirstName(){return firstName;}
    string getAddress(){return address;}
    string getCity(){return city;}
    string getState(){return state;}
    int getZip(){return zip;}
    string getPhone(){return phone;}
    void setLastName(string l){lastName=l;}
    void setFirstName(string f){firstName=f;}
    void setAddress(string a){address=a;}
    void setCity(string c){city=c;}
    void setState(string s){state=s;}
    void setZip(int z){zip=z;}
    void setPhone(string p){phone=p;}
};
#endif	/* PERSONDATA_H */

