/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on May 17, 2014, 11:27 PM
 */

#include <cstdlib>
#include <iostream>
#include "TeamLeader.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    TeamLeader team("Diego",335449,"04-04-2014",1,23.25, 5000, 25, 50);
    cout << "\Team Leader Name \t" << team.getName();
    cout << "\nTeam Leader_ID \t\t" << team.getNum();
    cout << "\nTeam Leader Hire Date\t" << team.getHireDate();
    cout << "\nTeam Leader Shift\t" << team.getShift();
    cout << "\nTeam Leader Rate\t" << team.getRate();
    cout << "\nTeam Leader Bonus Possible\t" << team.getBonus();
    cout << "\nTeam Leader Training Hours Worked\t" << team.getTotalTraining();
    cout << "\nTeam Leader Training Hours Needed\t\t" << team.getReqTraining();
    
    return 0;
}

