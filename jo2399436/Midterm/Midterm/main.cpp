// Author: Jazmin Onofre
//Assignment: Midterm Project
//////////////////////////////////////////////////////////////////////////
//System Libraries
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <iomanip>
#include "STRUCT.h"
using namespace std;

//Function Prototypes
//void writeFile();
//void inputData();
//void ordering();
//int exiting();
void SpOrder();
//void WPack();
//void FPack();


int main(int argc, char** argv) 
{
	Order or;
	DataB db[]={{"Alstroemeria", 300, 2.00},{"Agapanthus", 400, 3.40},{"Amaryllis", 200, 8.00},
    {"Aster", 200, 2.20},{"Bird of Paradise", 300 ,4.00},{"Calla", 200, 4.00},{"Carnation", 500, 0.50},
    {"Chrysanthemum", 400, 1.50},{"Daffodil", 400, 1.50},{"Daisy", 400, 1.50},{"Delphinium", 300, 2.50},
    {"Ginger (Red)", 200, 4.00},{"Gardenia", 100, 18.00},{"Gladiolus", 250, 3.50},{"Iris", 400, 2.00},
    {"Lily", 400, 3.00},{"Orchid", 100, 27.00}, {"Roses", 400, 2.00},{"Sunflower", 150, 3.20},{"Tulip", 250, 1.40}};
    
	//variables
	int NSize;
	int Mchoice;
	
    cout << "\n\nThe Bloom Room\n";
	cout << "1545 Levi Way\n Claremont, CA 91711 ";
    cout << "_______________________________________________" << endl;
    cout << "Name\t\tAmount in Stock\t Price per Stem\n\n";
	cout << "_______________________________________________\n\n";
    for (int i=0; i < 20; i++)
    {
        cout << db[i].FName;
		NSize = strlen(db[i].FName);
		if ( NSize < 8)
			cout <<"\t\t\t"<< db[i].amount<<"\t\t";
		else if (NSize >= 15)
			cout <<"\t"<< db[i].amount<<"\t\t";
		else
			cout <<"\t\t"<< db[i].amount<<"\t\t";
		cout << "$ " <<setprecision(2)<< db[i].price<< endl;
    }
	cout << "______________________________________________";
	cout << "\n\n\t\t    Menu: \n______________________________________________";
	cout << "\n\n\t 1: Order a Bouquet \n\t 2: Special Order\n";
	cout << "\t 3: Wedding Packages \n\t 4: Funeral Packages \n\t 5: Exit";
	cout << "\n______________________________________________";
	cout << "\nPlease enter the choice number of your command.\n";
	cin >> Mchoice;
	cout << endl;
	switch(Mchoice)
	{
	case 1:
		break;
	case 2:
		SpOrder();
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		//exiting();
		break;
	}
  
	

   
    cin.ignore();
    cin.get();
    return 0;
}
//void ordering()
//{
//
//}
//int exiting()
//{
//return 0;
//}
void SpOrder()
{
	fstream file;
	//variables
	string *SPtr;
	int *SPtr2;
	const int SIZE = 25;
	int SpOrder;
	int total=0;
	char answer;
	char AD[50];
	char PN[10];
	char recipient[SIZE];
	cout << "\nHow many flowers would you like to be special ordered?";
	cin >> SpOrder;
	//allocating memory
	SPtr = new string[SpOrder];
	SPtr2 = new int[SpOrder];
	//inputing flowers names
	for (int i=0;i < SpOrder; i++)
	{
		cout << "Flower " << i+1 << ": ";
		getline(cin, *(SPtr+i));
		cout << "Number of this type of flower:";
		cin >>*(SPtr2+i);
	}
	for (int i=0;i< SpOrder;i++)
		total += *(SPtr2+i);
	cout << "Please enter the name of the recipient.";
	getline(recipient, SIZE);
	cout << "Please enter your address.";
	cin >> AD;
	cout <<"Please enter you phone number (ex: 9511234567)";
	cin >> PN;
	cout << "\n\Special Order:\n\n";
	cout << "Name:" << recipient << endl <<"Address:"<< AD << endl;
	cout << "Phone Number: "<< PN<<endl <<"Flowers: ";
	for ( int i =0;i < SpOrder; i++)
		cout << *(SPtr+i) << endl;
	cout <<"Price of Flowers: Varies\n";
	cout << "A representative will call you within the day to give you the quote.\n";
	cout << "Shipping will take between 4-6 days ( in state shipping only)\n";
	if ( total <=10)
		cout << "Shipping Cost: $3.99\n";
	else if (total > 10 && total <=25)
		cout << "Shipping Cost: $6.99\n";
	else if (total > 25 && total <= 75)
		cout << "Shipping Cost: $9.99\n";
	else if(total >75 && total <= 100)
		cout << "Shipping Cost: $11.99\n";
	else if (total > 100 && total <=200)
		cout << "Shipping Cost: $13.99\n";
	else 
		cout << "Shipping Cost: 19.99\n";
	cout <<"Would you like to place this order?(Y/N)\n";
	cin >> answer;
	
	if(answer == 'Y' || answer == 'y')
	{
		file.open("SpecialOrder.txt", ios::out);
		file  <<recipient << endl << AD << endl;
		file <<  PN<<endl ;

		file.close();

	}
	else if (answer == 'N' || answer == 'n')
	{
		delete SPtr;
		delete SPtr2;
	}
	else
	cout << "That answer was not recognized.";
}
//void WPack()
//{}
//void FPack()
//{}


