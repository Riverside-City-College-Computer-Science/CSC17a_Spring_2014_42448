/* 
 * File:   UserInfo.h
 * Author: Scott Nevin
 * Created on June 8, 2014, 6:05 PM
 */

#ifndef USERINFO_H
#define	USERINFO_H

#include <string>
using namespace std;

//This class stores the info of a new user to be written to a file
class UserInfo{
    
private:
    int name;
    int pword;
    int slot;
    string msg;
    
public:
    void setName(int);
    void setPword(int);
    void setMsg(string);
    void setSlot(int);
    void write();
    void erase();
    
};

#endif	/* USERINFO_H */

