/* 
 * File:   TeamLeader.h
 * Author: Diego
 *
 * Created on May 17, 2014, 11:27 PM
 */
#include <iostream>
#include "ProductionWorker.h"

using namespace std;

#ifndef TEAMLEADER_H
#define	TEAMLEADER_H

class TeamLeader : public ProductionWorker
{
private:
    int bonus;
    int total_training;
    int req_training;
public:
    TeamLeader(string name, int num, string date,int s, double r, int bonus, int hours_w,int hours_n)
    :  ProductionWorker( name,  num,  date, s, r)
    {this->bonus=bonus;total_training=hours_w;req_training=hours_n;}
    int getBonus(){return bonus;}
    int getTotalTraining(){return total_training;}
    int getReqTraining(){return req_training;}
    void setBonus(int b){bonus=b;}
    void setTotalTraining(int t){total_training=t;}
    void setReqTraining(int t){req_training=t;}
    
};


#endif	/* TEAMLEADER_H */

