/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on May 17, 2014, 11:13 PM
 */

#include <cstdlib>
#include "ShiftSupervisor.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    ShiftSupervisor sup("Diego",335449,"04-04-2014",50000,5000);
    cout << "\nEmployee \t" << sup.getName();
    cout << "\nEmp_ID \t\t" << sup.getNum();
    cout << "\nEmp Hire Date\t" << sup.getHireDate();
    cout << "\nSup. Salary\t" << sup.getSalary();
    cout << "\nSup Bonus\t" << sup.getProduction();
    return 0;
}

