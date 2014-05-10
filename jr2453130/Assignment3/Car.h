/* 
 * File:   Car.h
 * Author: Joe
 *
 * Created on May 9, 2014, 3:58 PM
 */

#include <string>
using namespace std;

#ifndef CAR_H
#define	CAR_H

class Car
{
private:
    int yearModel;
    string make;
    int speed;
public:
    //Constructor
    Car(int,string);
    //Accessors
    int getYear() const;
    string getMake() const;
    int getSpeed() const;
    void prntSpd() const;
    //Mutators
    void accel();
    void brake();
};
#endif	/* CAR_H */

