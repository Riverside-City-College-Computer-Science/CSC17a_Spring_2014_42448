/*
	Dennise Toscanini
	March 3, 2014
	Gaddis_7thEd_Chap3_Prob12
*/

//Libraries
#include <iostream>
#include <string>
using namespace std;

//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
	string month, year;
	float totAmnt, sales, cntyTx, stateTx, totSTx;
	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	
	cout<<"Monthly Sales Tax Report"<<endl;
	cout<<"------------------------"<<endl;
	cout<<"Please enter month: "<<endl;
	cin>>month;
	cout<<endl;
	cout<<"Please enter year: "<<endl;
	cin>>year;
	cout<<endl;
	cout<<"Please enter total amount collected"<<endl;
	cout<<"at cash register:"<<endl;
	cout<<"$";	
	cin>>totAmnt;
		
	sales = totAmnt/1.06e0f;
	cntyTx = sales*.02e0f;
	stateTx = sales*.04e0f;
	totSTx = cntyTx+stateTx;
	
	cout<<endl;
	cout<<"Month: "<<month<<endl;
	cout<<"Year: "<<year<<endl;
	cout<<"------------------------"<<endl;
	cout<<"Total Collected:       $"<<totAmnt<<endl;
	cout<<"Sales:                 $"<<sales<<endl;
	cout<<"County Sales Tax:      $"<<cntyTx<<endl;     
	cout<<"Sales Sales Tax:       $"<<stateTx<<endl;
	cout<<"Total Sales Tax:       $"<<totSTx<<endl;
	
	
	
	//Exit Stage Right
	return 0;
}
