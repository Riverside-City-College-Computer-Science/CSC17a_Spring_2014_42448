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
void SpOrder();
void WPack();

int main(int argc, char** argv) 
{
	//variables
	int Mchoice;
	//Displaying the menu and the store location 
    cout << "\n\nThe Bloom Room\n";
	cout << "1545 Levi Way\nClaremont, CA 91711\n";

	//displays the menu after choosing an option the menu come back
	do
	{
		cout << "______________________________________________";
		cout << "\n\n\t\t    Menu: \n______________________________________________";
		cout << "\n\n\t 1: Order a Bouquet \n\t 2: Special Order\n";
		cout << "\t 3: Wedding Packages \n\t 4: Exit";
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
	case 4: 
		cout << "You are exiting.";
		break;
	}
	}while(Mchoice >=1&& Mchoice <4);
  
	
    cin.ignore();
    cin.get();
    return 0;
}
// for Orders the  carries displays the info and then saves the order if the user wishes
//writes to the file if the user wants to save the data
void ordering( )
{
	fstream file;
	DataB db[]={{"1. Alstroemeria", 40.00},{"2. Agapanthus",  68.00},{"3. Amaryllis", 160.00},
    {"4. Aster",  44.00},{"5. Bird of Paradise" ,80.00},{"6. Calla", 80.00},{"7. Carnation",  15.00},
    {"8. Chrysanthemum",  30.00},{"9. Daffodil", 20.00},{"10. Daisy",  20.00},{"11. Delphinium",  50.00},
    {"12. Ginger (Red)",  80.00},{"13. Gardenia",  180.00},{"14. Gladiolus",  70.00},{"15. Iris",  40.00},
    {"16. Lily",  80.00},{"17. Orchid", 430.00}, {"18. Rose",  40.00},{"19. Sunflower", 75.00},{"20. Tulip",  50.00}};
    Order order;
	int NSize;
	int choice, num, total =0;
	char noMsg[11] = "No message";
	char noDel[20] = "Not being delieved";
	
	cout << "_______________________________________________" << endl;
    cout << "Name\t\tAmount in Stock\t Price per Stem\n\n";
	cout << "_______________________________________________\n\n";
    for (int i=0; i < 20; i++)
    {
        cout << db[i].FName;
		NSize = strlen(db[i].FName);
		if ( NSize < 8)
			cout <<"\t\t"<< fixed << showpoint << setprecision(2) << "$ "  << db[i].price<< endl;
		else if (NSize >= 16)
			cout <<"\t"<< fixed << showpoint << setprecision(2) << "$ "  << db[i].price<< endl;
		else
			cout <<"\t\t"<< fixed << showpoint << setprecision(2) << "$ "  << db[i].price<< endl;
		
    }
	cout << "\n\nHow many bouquets would you like to order? ";
	cin >> num;
	Order *oR = new Order[num];
	string *N = new string[num];
	int *T = new int[num];
	

	cout << "\nFrom the list above enter the number of the boquet you wish to buy. ";
	for (int i =0;i < num; i++)
	{
		cout << "\nChoice : " << i+1 << "   " ;
		cin >> choice;
		switch(choice)
		{
		case 1: *(N+i) = "Alstroemeria"; *(T+i) = 40; break;
			case 2: *(N+i) = "Agapanthus"; *(T+i) = 68; break;
			case 3: *(N+i) = "Amaryllis"; *(T+i) = 160; break;
			case 4: *(N+i) = "Aster"; *(T+i) = 44; break;
			case 5: *(N+i) = "Bird of Paradise"; *(T+i) = 80; break;
			case 6: *(N+i) = "Calla"; *(T+i) = 80; break;
			case 7: *(N+i) = "Carnation"; *(T+i) = 15; break;
			case 8: *(N+i) = "Chrysanthemum"; *(T+i) = 30; break;
			case 9: *(N+i) = "Daffodil"; *(T+i) = 20; break;
			case 10: *(N+i) = "Dasiy"; *(T+i) = 20; break;
			case 11: *(N+i) = "Delphinium"; *(T+i) = 50; break;
			case 12: *(N+i) = "Ginger (Red)"; *(T+i) = 80;  break;
			case 13: *(N+i) = "Gardenia"; *(T+i) = 180; break;
			case 14: *(N+i) = "Gladiolus"; *(T+i) = 70; break;
			case 15: *(N+i) = "Iris"; *(T+i) = 40; break;
			case 16: *(N+i) = "Lily"; *(T+i) = 80; break;
			case 17: *(N+i) = "Orchid"; *(T+i) = 430; break;
			case 18: *(N+i) = "Rose"; *(T+i) = 40;  break;
			case 19: *(N+i) = "Sunflower"; *(T+i) = 75; break;
			case 20: *(N+i) = "Tulip"; *(T+i) = 50; break;
		}
	}
	for ( int i =0;i < num; i++)
		total+= *(T+i);
	cin.ignore();
	cout <<"Please enter the name for who the flowers are for. ";
	cin.getline(oR->to, 25);
	cout << "Please enter the name of the sender. ";
	cin.getline(oR->from, 25);
	cout << "Would you like to send a message with the flowers? (Y/N) ";
	cin >> oR->Msg;
	if(oR->Msg == 'Y' ||oR->Msg == 'y' )
	{
		cin.ignore();
		cout << "Please enter a message no more than 100 characters.\n";
		cin.getline(oR->msg, 100);
		
	}
	else if(toupper(oR->Msg) == 'N')
	{
		cout << "We'll skip the message then.";
		strncpy(oR->msg, noMsg, 11);
	}
	else
		cout << "That answer was not understood.";

	cout << "\nWould you like to have these delivered?(Y/N) ";
	cout << "\nThe fee will be $ 3.00 \n";
	cin >> oR->delivery;
	if(toupper(oR->delivery) == 'Y')
	{
		cin.ignore();
		cout << "What is the address for the flowers to be delievered to. \n";
		cin.getline(oR->address, 40);
		total += 3; 
		cout <<"Total: "<< total;
	}
	else if(toupper(oR->delivery) == 'N')
	{
		cout << "\nTotal: $" << total;
		strncpy(oR->address, noDel, 20);
	}
	else
		cout << "That answer was not understood.";
	cout << "\nWould you like to place this order? (Y/N)";
	cin >> oR->save;
	if(toupper(oR->save) == 'Y')
	{
		file.open("Order.txt", ios::out | ios::app);
			if (file.fail())
		{
			cout << "Error opening file.\n";
		}
		else
		{
			file << "To: " << oR->to <<"\nFrom: " << oR->from;
			file << "\nAddress: " << oR->address;
			file << "\nMessage: " << oR->msg;
			file << "\nFlowers: " ;
			for (int i =0;i<num;i++)
				file << *(N+i) << endl;
			file << "Total: $" << total;
			file << endl << endl;
			cout <<"Your order was saved.\n";

			file.close();
		}
	}

	else if(toupper(oR->save) == 'N')
	{
		cout << "Order not saved. \n";
		
	}
	else
		cout << "That wasnt understood.";
	delete []N;
	delete []T;
	delete []oR;	
	
		

}
// a function to sspecial order what the store does not carry.

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
	cout << "\nSpecial Order:\n\n";
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
		cout << "Order not saved\n";
	}
	else
	cout << "That answer was not recognized.";
		delete [] SPtr;
		delete [] ptr;
		delete [] F;
		delete [] C;
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
