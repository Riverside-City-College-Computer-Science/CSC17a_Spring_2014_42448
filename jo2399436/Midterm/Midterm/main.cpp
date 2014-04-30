// Author: Jazmin Onofre
//Assignment: Midterm Project
//////////////////////////////////////////////////////////////////////////
//System Libraries
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include "STRUCT.h"
using namespace std;

//Golbal Variables

//Function Prototypes
void ordering();
//int exiting();
void SpOrder();
void WPack();
//void FPack();


int main(int argc, char** argv) 
{
	//variables
	int Mchoice;
	//Displaying the menu and the store location 
    cout << "\n\nThe Bloom Room\n";
	cout << "1545 Levi Way\nClaremont, CA 91711\n";

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
	}
	}while(Mchoice >=1&& Mchoice <5);
  
	
    cin.ignore();
    cin.get();
    return 0;
}
// for Orders the  carries displays the info and then saves the order if the user wishes
void ordering( )
{
	DataB db[]={{"1. Alstroemeria", 300, 2.00},{"2. Agapanthus", 400, 3.40},{"3. Amaryllis", 200, 8.00},
    {"4. Aster", 200, 2.20},{"5. Bird of Paradise", 300 ,4.00},{"6. Calla", 200, 4.00},{"7 Carnation", 500, 0.50},
    {"8. Chrysanthemum", 400, 1.50},{"9. Daffodil", 400, 1.50},{"10. Daisy", 400, 1.50},{"11. Delphinium", 300, 2.50},
    {"12. Ginger (Red)", 200, 4.00},{"13. Gardenia", 100, 18.00},{"14. Gladiolus", 250, 3.50},{"15. Iris", 400, 2.00},
    {"16. Lily", 400, 3.00},{"17. Orchid", 100, 27.00}, {"18. Roses", 400, 2.00},{"19. Sunflower", 150, 3.20},{"20. Tulip", 250, 1.40}};
    Order order;
	int NSize;
	int choice, num;
	int *ptr;

	cout << "_______________________________________________" << endl;
    cout << "Name\t\tAmount in Stock\t Price per Stem\n\n";
	cout << "_______________________________________________\n\n";
    for (int i=0; i < 20; i++)
    {
        cout << db[i].FName;
		NSize = strlen(db[i].FName);
		if ( NSize < 8)
			cout <<"\t\t"<< db[i].amount<<"\t\t";
		else if (NSize >= 15)
			cout <<"\t"<< db[i].amount<<"\t\t";
		else
			cout <<"\t\t"<< db[i].amount<<"\t\t";
		cout<< fixed << showpoint << setprecision(2) << "$ " << db[i].price<< endl;
    }
	cout << "How many bouquets would you like to order? ";
	cin >> num;
	Order *ptr = new Order[num];












}

void SpOrder()
{
	fstream file;
	SP sp;
	//variables
	int *SPtr;
	char *ptr2;
	string phone;
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
	cout << "Please enter the name of the recipient. ";
	cin.getline (ptr->recipient, 25 );
	
	cout << "Please enter your address. ";
	cin.getline (ptr->address, 30);
	
	cout <<"Please enter you phone number (ex: 9511234567) ";
	cin >> phone;
	cout << "\n\Special Order:\n\n";
	cout << "Name:" << ptr->recipient << endl <<"Address:"<< ptr->address << endl;
	cout << "Phone Number: "<< phone <<endl <<"Flowers: ";
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
		file.open("SpecialOrder.txt", ios::out | ios::app);
			if (file.fail())
		{
			cout << "Error opening file.\n";
		}
	else
	{
		file  <<"\nName: " <<ptr->recipient << endl << "Address: "<<ptr->address
			<< endl << "Phone: " << phone <<endl; 
		for ( int i =0;i < SpOrder; i++)
		{
			file << "Flower: " << *(F+i) << endl;
			file << "Amount: "<< *(SPtr+i) << endl;
			file << "Color: " << *(C+i) << endl;;
		}
		cout <<"Your order was saved.\n";

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
// This function presents a list of wedding packages and their contents
//and lets the user enter their choice and leave a phone number
void WPack()
{
	//variables
	fstream file;
	int num;
	int total;
	string pckN;
	char ans;
	char name[20], pNum[15];
	//wedding packages
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
	cout << "What package would you ike to order? ";
	cin >> num;
	//switch case for input
	switch(num)
	{
	case 1:
		pckN = "Bronze Package";
		total = 125;
		break;
	case 2:
		pckN = "Silver Package";
		total = 200;
		break;
	case 3:
		pckN = "Gold Package";
		total = 300;
		break;
	case 4: 
		pckN = "Platinum Package";
		total = 550;
		break;
	}
	cin.ignore();
	cout << "Please leave your name and phone number for our wedding planner to call you back.";
	cout << "We will then call to schedule an appointment  for you to pick from our \n";
	cout << "special selection of flowers.\nName: ";
	cin.getline(name, 20);
	cout << "\nNumber: ";
	cin.getline(pNum, 15);
	cout << "\nWould you like to place your order? (Y/N) ";
	cin >> ans;
	if(ans == 'Y' || ans == 'y')
	{
		file.open("WeddingOrder.txt", ios::out | ios::app);
			if (file.fail())
		{
			cout << "Error opening file.\n";
		}
		else
		{
			cout << "Your order is being saved.\n";
			file << "Name: " << name;
			file << "\nPhone Number: " << pNum;
			file << "\nPackage Name: " << pckN << "\nTotal: $ " << total << endl << endl;
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


