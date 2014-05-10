/* 
 * File:   Date.h
 * Author: Joe
 *
 * Created on May 9, 2014, 2:46 PM
 */

#ifndef DATE_H
#define	DATE_H

class Date
{
private:
    int day;
    int month;
    int year;
public:
    void outOne(int,int,int) const;
    void outTwo(int,int,int) const;
    void outThree(int,int,int) const;
};
#endif	/* DATE_H */

