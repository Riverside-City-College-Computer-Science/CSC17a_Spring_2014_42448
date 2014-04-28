
#ifndef STRUCT_H
#define	STRUCT_H

struct DataB
{
    char FName[17];
    int amount;
    float price;
};

struct Order
{
    char FlName[17];
    int Amount;
    float total;
    char delivery;
    char address[30];
    char date[9];
    char itemDone[100];
};

struct SP
{
	char recipient[25];
	char address[30];
	int phone;
	char answer;
	

};



#endif	/* STRUCT_H */

