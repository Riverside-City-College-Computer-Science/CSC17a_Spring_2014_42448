/*
	Dennise Toscanini
	March 5, 2014
	Gaddis_7thEd_Chap6_Prob7
*/

//Libaraies
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants

//Function Prototypes
float celcius(float);

//Execution Begins Here
int main(int argc, char** argv) {
	float fahr;
	
	cout<<"Fahrenheit to Celcius Conversion"<<endl;
	cout<<"--------------------------------"<<endl;
			
	cout<<"--------------------------------"<<endl;
	cout<<"Fahrenheit      |        Celcius"<<endl;	
	
	for(float i=0;i<10;i++){
		cout<<left<<i<<"               |     "<<right<<celcius(i)<<endl;
	}
		for(float i=10;i<=20;i++){
		cout<<left<<i<<"              |     "<<right<<celcius(i)<<endl;
	}
	
	cout<<"--------------------------------"<<endl;
	cout<<"Please enter a temperature in "<<endl;
	cout<<"fahrenheit that you would like "<<endl;
	cout<<"to convert to celcius: "<<endl;
	cin>>fahr;
	
	cout<<"Converts to: "<<celcius(fahr)<<" degrees celcius"<<endl;
	
	return 0;
}

float celcius(float f){
	return ((f-32)*5/9);
}
