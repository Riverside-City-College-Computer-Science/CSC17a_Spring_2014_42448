/*
	Dennise Toscanini
	March 3, 2014
	Gaddis_7thEd_Chap4_Prob10
*/

//Libraries
#include <iostream>
using namespace std;

//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
	//Declare Variables
	float quant, cost, discnt;
	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	
	do{
		cout<<"Please enter total number"<<endl;
		cout<<"of units sold:"<<endl;
		cin>>quant;
	}while(quant<=0);
	
	cout<<endl;
	
	if(quant<10){
		cost=quant*9.9e1f;
		cout<<"Total cost of purchase:"<<endl;
		cout<<"$"<<cost;
	}
	else if(quant>=10 && quant<=19){
		discnt=((quant*9.9e1f)*2.0e-1f);
		cost=((quant*9.9e1f)-discnt);
		cout<<"Total cost of purchase:"<<endl;
		cout<<"$"<<cost;
 }
	else if(quant>=20 && quant<=49){
		discnt=((quant*9.9e1f)*3.0e-1f);
		cost=quant*9.9e1f-discnt;
		cout<<"Total cost of purchase:"<<endl;
		cout<<"$"<<cost;
	}
	else if(quant>=50 && quant<=99){
		discnt=((quant*9.9e1f)*4.0e-1f);
		cost=((quant*9.9e1f)-discnt);
		cout<<"Total cost of purchase:"<<endl;
		cout<<"$"<<cost;
	}
	else if(quant>=100){
		discnt=((quant*9.9e1f)*5.0e-1f);
		cost=((quant*9.9e1f)-discnt);
		cout<<"Total cost of purchase:"<<endl;
		cout<<"$"<<cost;			
 }
	//Exit Stage Right
	return 0;
}
