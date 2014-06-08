/* 
 * File:   classes.h
 * Author: diegomontelongo
 *
 * Created on May 4, 2014, 11:43 PM
 */

#ifndef DATE_H
#define	DATE_H
class Date{
    private: 
        int month, day, year;
    public:
        Date(int,int,int);
        //12/25/2012 December 25, 2012 25 December 2012
        void printDateDashes();
        void printDateMonthFirst();
        void printDateDayFirst();
};



#endif	/* CLASSES_H */

