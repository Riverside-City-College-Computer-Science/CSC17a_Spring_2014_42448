/*
	Dennise Toscanini
	March 3, 2014
	Gaddis_7thEd_Chap3_Prob13
*/

//Libraries
#include <iostream>
using namespace std;

//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
	float val, asVal, propTx;
	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	
	cout<<"County Property Tax Collection"<<endl;
	cout<<"------------------------------"<<endl;
	cout<<endl;
	
	cout<<"Please enter the actual value"<<endl;
	cout<<"of your property:"<<endl;
	cout<<"$";
	cin>>val;
	
	asVal = val*6.0e-1f;
	propTx = ((asVal/1.00e2f)*6.4e-1f);
	
	cout<<endl;
	cout<<"-------------------------------"<<endl;
	cout<<"Assesment value:              $"<<asVal<<endl;
	cout<<"Property tax:                 $"<<propTx<<endl;
	
	
	//Exit Stage Right
	return 0;
}
