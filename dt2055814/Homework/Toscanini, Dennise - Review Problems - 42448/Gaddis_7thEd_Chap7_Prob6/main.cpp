/*
	Dennise Toscanini
	March 6, 2014
	Gaddis_7thEd_Chap7_Prob6
*/

//Libraries
#include <iostream>
#include <fstream>
using namespace std;

//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
	int i=0;
	const int SIZE=10;
	int numbrs[SIZE];
	ifstream inputFile;
	
	inputFile.open("numbers.txt");
	
	while (i<SIZE && inputFile>>numbrs[i])
		i++;
		
	inputFile.close();
	
	cout<<"The numbers are: "<<endl;
	
	for(i=0;i<SIZE;i++)
		cout<<numbrs[i]<<" ";
	cout<<endl;
	cout<<endl;
	
	//highest
	int high=numbrs[0];
	for(i=0;i<SIZE;i++){
		if(numbrs[i]>high)
		high=numbrs[i];
	}
	cout<<"The highest number is: "<<high<<endl;
	cout<<endl;
	
	//lowest
	int low=numbrs[0];
	for(i=0;i<SIZE;i++){
		if(numbrs[i]<low)
		low=numbrs[i];
	}
	cout<<"The lowest number is: "<<low<<endl;
	cout<<endl;
	
	//total
	int total=0;
	for(i=0;i<SIZE;i++)
	total+=numbrs[i];
	
	cout<<"The total of all numbers is: "<<total<<endl;
	cout<<endl;
	
	//average
	int tot=0;
	float avrg;
	for(i=0;i<SIZE;i++)
		tot+=numbrs[i];
		avrg=static_cast<float>(tot)/static_cast<float>(SIZE);
		
		
	cout<<"The average of all numbers is: "<<avrg<<endl;	
		
	
	//Exit Stage Right
	return 0;
}

