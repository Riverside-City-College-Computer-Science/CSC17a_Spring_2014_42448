#include <string>

#ifndef STRUCT_H
#define	STRUCT_H

struct DataB
{
    char FName[20];
    float price;
};

struct Order
{
	char save;
	char to[25];
	char from[25];
    char delivery, Msg;
    char address[50];
	char msg[100];
    
  };

struct SP
{
	char recipient[25];
	char address[30];
	char answer;
};





#endif	/* STRUCT_H */

