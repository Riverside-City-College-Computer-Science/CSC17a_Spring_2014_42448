//Libraries
#include "RetailItem.h"
#include <iostream>
#include <cstdlib>
using namespace std;

//Constructor
RetailItem::RetailItem(string d,int u,float p){
    setDesc(d);
    setUnits(u);
    setPrice(p);    
}

//Mutators
void RetailItem::setDesc(string d){
    desc=d;
}

void RetailItem::setUnits(int u){
    units=u;
}

void RetailItem::setPrice(float p){
    price=p;
}

//Accessors
string RetailItem::getDesc() const{
    return desc;
}

int RetailItem::getUnits() const{
    return units;
}

double RetailItem::getPrice() const{
    return price;
}

void RetailItem::prnt() const{
    cout<<"Info: "<<endl;
    cout<<"Description:   "<<getDesc()<<endl
        <<"Units on Hand: "<<getUnits()<<endl
        <<"Price:         $"<<getPrice()<<endl<<endl;
}