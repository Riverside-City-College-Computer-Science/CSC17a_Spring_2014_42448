//Libraries
#include "Car.h"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

//Constructor
Car::Car(int y,string m){
    yearModel=y;
    make=m;
    speed=0;
}

//Accessors
int Car::getYear() const{
    return yearModel;
}

string Car::getMake() const{
    return make;
}

int Car::getSpeed() const{
    return speed;
}

void Car::prntSpd() const{
    cout<<"Current speed: "<<speed<<endl;
}

//Mutators
void Car::accel(){
    speed+=5;
}

void Car::brake(){
    speed-=5;
}

