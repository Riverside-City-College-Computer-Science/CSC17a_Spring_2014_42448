/*
	Dennise Toscanini
	March 4, 2014
	Gaddis_7thEd_Chap5_Prob11
*/

//Libraries
#include <iostream>
using namespace std;

//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
	//Declare Variables
	float pop, rate, days, total;
	
	do{
		cout<<"Please enter the staring number"<<endl;
		cout<<"of organism:"<<endl;
		cin>>pop;
	}while(pop<2);
	
	do{
	cout<<"Please enter the daily population"<<endl;
	cout<<"increase(as a percentage):"<<endl;
	cin>>rate;
	}while(rate<0);
	
	do{
	cout<<"Please enter how many days"<<endl;
	cout<<"they will multipy: "<<endl;
	cin>>days;
	}while(days<1);
	
	
	for (int i=1; i<=days; i++){
		float temp=0;
		
		temp=((rate/1.0e2)*pop);
		total+=(temp+pop);
		
		cout<<"Day "<<i<<": "<<total<<endl;
	}
		
	
	

	//Exit Stage Right
	return 0;
}
