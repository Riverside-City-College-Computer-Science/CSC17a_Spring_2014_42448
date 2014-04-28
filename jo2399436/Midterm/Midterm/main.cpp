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
void ordering();
//int exiting();
void SpOrder();
void WPack();
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
	cout << "1545 Levi Way\nClaremont, CA 91711\n";
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
	do
	{
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
		ordering();
		break;
	case 2:
		SpOrder();
		break;
	case 3:
		WPack();
		break;
	case 4:
		break;
	case 5:
		//exiting();
		break;
	}
	}while(Mchoice >=1&& Mchoice <=5);
  
	

   
    cin.ignore();
    cin.get();
    return 0;
}
void ordering( )
{

}

void SpOrder()
{
	fstream file;
	SP sp;
	//variables
	int *SPtr;
	char *ptr2;
	const int SIZE = 30;
	int SpOrder;
	int total=0;
	string *F, *C;
	 
	cout << "\nHow many flowers would you like to be special ordered?";
	cin >> SpOrder;
	cin.ignore();
	//allocating memory
	SP *ptr = new SP[SpOrder];
	SPtr = new int[SpOrder];
	F = new string [SpOrder];
	C = new string[SpOrder];
	
	
	//inputing flowers names
	for (int i=0;i < SpOrder; i++)
	{
		cout << "Flower Name " << i+1 << ": ";
		cin >> *(F+i);
		cout << "Color: ";
		cin >> *(C+i);
		cout << "Number of this type of flower:";
		cin >>*(SPtr+i);
	}
	for (int i=0;i< SpOrder;i++)
		total += *(SPtr+i);
	cin.ignore();
	
	char address[30];
	cout << "Please enter the name of the recipient.";
	cin.getline (ptr->recipient, 25 );
	
	cout << "Please enter your address.";
	cin.getline (ptr->address, 30);
	
	cout <<"Please enter you phone number (ex: 9511234567)";
	cin >> ptr->phone;
	cout << "\n\Special Order:\n\n";
	cout << "Name:" << ptr->recipient << endl <<"Address:"<< ptr->address << endl;
	cout << "Phone Number: "<< ptr->phone <<endl <<"Flowers: ";
	for ( int i =0;i < SpOrder; i++)
		{
			cout << *(F+i) << "  ";
			cout << *(SPtr+i) << endl;
		}
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
	cin >> ptr->answer;
	
	if(ptr->answer == 'Y' || ptr->answer == 'y')
	{
		file.open("C:\\Users\\Jazmin\\Documents\\Visual Studio 2010\\Projects\\Midterm\\SpecialOrder.txt");
			if (file.fail())
		{
			cout << "Error opening file.\n";
		}
	else
	{
		file  <<"Name: " <<ptr->recipient << endl << "Address: "<<ptr->address
			<< endl << "Phone: " << ptr->phone <<endl << "Flowers: ";
		for ( int i =0;i < SpOrder; i++)
		{
			file << *(F+i) << "  ";
			file << *(SPtr+i) << endl;
			cout << "Color: " << *(C+i);
		} ;

		file.close();
	}

	}
	else if (ptr->answer == 'N' || ptr->answer == 'n')
	{
		delete SPtr;
		delete ptr;
		delete F;
		delete C;
	}
	else
	cout << "That answer was not recognized.";
}
void WPack()
{
	fstream file;
	int num;
	int total;
	char ans;
	cout << "\t\tWedding Packages:\n____________________________________________\n";
	cout << "1. Bronze Package \nIncludes: Brides Bouquet and Grooms Boutonniere\n";
	cout << "Cost: $125.00 ";
	cout <<"\n\n2. Silver Package \nIncludes: Brides Bouquet and Grooms Boutonniere\n";
	cout << "Maid of Honor Bouquet and Best Man Boutonniere\n";
	cout << "Cost: $200.00";
	cout << "\n\n3. Gold Package \nIncludes Brides Bouquet and Grooms Boutonniere\n";
	cout << "Maid of Honor Bouquet and Best Man Boutonniere\n";
	cout << "5 Bridesmaids and Groomsmen Bouquets and Boutonnieres\n";
	cout << "Cost: $300.00";
	cout <<"\n\n4. Platinum Package \nIncludesBrides Bouquet and Grooms Boutonniere\n";
	cout << "Maid of Honor Bouquet and Best Man Boutonniere\n";
	cout << "5 Bridesmaids and Groomsmen Bouquets and Boutonnieres\n";
	cout << "15 Centerpieces\n";
	cout << "Cost: $550.00\n\n";
	cout << "What package would you ike to order?";
	cin >> num;
	switch(num)
	{
	case 1:
		total = 125;
		break;
	case 2:
		total = 200;
		break;
	case 3:
		total = 300;
		break;
	case 4: 
		total = 550;
		break;
	}
	cout << "Would you like to place your order?";
	cin >> ans;
	if(ans == 'Y' || ans == 'y')
	{
		file.open("C:\\Users\\Jazmin\\Documents\\Visual Studio 2010\\Projects\\Midterm\\WeddingOrder.txt");
			if (file.fail())
		{
			cout << "Error opening file.\n";
		}
		else
		{
			cout << "Your order is being saved.";
			file << "Total: $" << total;
			file.close();
		}
	}
	else if(ans == 'N' || ans == 'n')
		cout << "Your order was cancelled.\n";
	else
		cout <<"That was not recognized";
	
	
	


}
//void FPack()
//{}


