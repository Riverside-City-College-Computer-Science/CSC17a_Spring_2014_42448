#include "Car.h"

Car::Car(int y,string m){
    yearModel=y;
    make=m;
    speed=0;
}
int Car::getyearModel()
{
    return yearModel;
}
string Car::getMake()
{
    return make;
}
int Car::getSpeed()
{
    return speed;
}
void Car::accelerate()
{
    speed+=5;
}
void Car::brake()
{
    speed-=5;
}
void Car::print()
{
    cout << make << " " << yearModel << " going " << speed << " fast" << endl;
}