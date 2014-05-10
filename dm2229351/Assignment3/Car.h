/* 
 * File:   Car.h
 * Author: diegomontelongo
 *
 * Created on May 7, 2014, 11:54 PM
 */
#include <iostream>
using namespace std;

#ifndef CAR_H
#define	CAR_H

class Car{
private:
    int yearModel;
    string make;
    int speed;
public:
    Car(int,string);
    int getyearModel();
    string getMake();
    int getSpeed();
    void accelerate();
    void brake();
    void print();
};



#endif	/* CAR_H */

