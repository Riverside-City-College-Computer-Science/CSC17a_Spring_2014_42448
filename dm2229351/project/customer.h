/**
 * \struct customer
 *
 * \ingroup project
 * 
 *
 * \brief Struct
 *
 * Struct to define my customer base
 * 
 *
 * \note Attempts at zen rarely work.
 *
 * \author Author Diego Montelongo
 *
 * \version Version 1.0
 *
 * \date $Date: 2014/04/29
 *
 * Contact: diego.motelongo@gmail.com
 *
 * Created on: 04/29/2014
 *
 */

#ifndef CUSTOMER_H
#define	CUSTOMER_H
#include <string.h>
struct customer{
    int member;
    string f_name;
    string l_name;
    string *movies;
    float balance;
    bool out,pastdue;
};

#endif	/* CUSTOMER_H */

