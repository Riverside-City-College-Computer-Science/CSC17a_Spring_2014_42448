//Libraries
#include "Date.h"
#include <iostream>
#include <cstdlib>
using namespace std;

void Date::outOne(int d,int m,int y) const{
    cout<<endl;
    cout<<"Output One:"<<endl;
    cout<<m<<"/"<<d<<"/"<<y<<endl;
}
void Date::outTwo(int d,int m,int y) const{
    //December 25,2012
    cout<<endl;
    cout<<"Output Two:"<<endl;
    if(m==1)cout<<"January "<<d<<", "<<y<<endl;
    else if(m==2)cout<<"February "<<d<<", "<<y<<endl;
    else if(m==3)cout<<"March "<<d<<", "<<y<<endl;
    else if(m==4)cout<<"April "<<d<<", "<<y<<endl;
    else if(m==5)cout<<"May "<<d<<", "<<y<<endl;
    else if(m==6)cout<<"June "<<d<<", "<<y<<endl;
    else if(m==7)cout<<"July "<<d<<", "<<y<<endl;
    else if(m==8)cout<<"August "<<d<<", "<<y<<endl;
    else if(m==9)cout<<"September "<<d<<", "<<y<<endl;
    else if(m==10)cout<<"October "<<d<<", "<<y<<endl;
    else if(m==11)cout<<"November "<<d<<", "<<y<<endl;
    else cout<<"December "<<d<<", "<<y<<endl;
    cout<<endl;
}
void Date::outThree(int d,int m,int y) const{
    //25 December 2012
    cout<<"Output Three:"<<endl;
    if(m==1)cout<<d<<" January "<<y<<endl;
    else if(m==2)cout<<d<<" February "<<y<<endl;
    else if(m==3)cout<<d<<" March "<<y<<endl;
    else if(m==4)cout<<d<<" April "<<y<<endl;
    else if(m==5)cout<<d<<" May "<<y<<endl;
    else if(m==6)cout<<d<<" June "<<y<<endl;
    else if(m==7)cout<<d<<" July "<<y<<endl;
    else if(m==8)cout<<d<<" August "<<y<<endl;
    else if(m==9)cout<<d<<" September "<<y<<endl;
    else if(m==10)cout<<d<<" October "<<y<<endl;
    else if(m==11)cout<<d<<" November "<<y<<endl;
    else cout<<d<<" December "<<y<<endl;
    cout<<endl;
}
