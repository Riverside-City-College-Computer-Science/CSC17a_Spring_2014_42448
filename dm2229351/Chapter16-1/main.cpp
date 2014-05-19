/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on May 17, 2014, 10:27 PM
 */

#include <cstdlib>
#include <iostream>
#include "ProductionWorker.h"

using namespace std;


int main(int argc, char** argv) {

    ProductionWorker prod("Diego",335449,"04-04-2014",1,25.65);
    cout << "\nEmployee \t" << prod.getName();
    cout << "\nEmp_ID \t\t" << prod.getNum();
    cout << "\nEmp Hire Date\t" << prod.getHireDate();
    cout << "\nEmployee Shift\t" << prod.getShift();
    cout << "\nEmployee Rate\t" << prod.getRate();
    
    
    return 0;
}

