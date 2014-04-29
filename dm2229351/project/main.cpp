//============================================================================
// Name        : project.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
//============================================================================
//standard libraries
#include <iostream>
#include <cctype>



using namespace std;
///our own libraries
#include "customer.h"
///my function prototypes
void printmenu();
void setBalance(customer *, float);
void addBalance(customer *, float);
void payBalance(customer *, float);
void changeFirst(customer *, string);
void changeLast(customer *, string);
void checkout(customer*, int);
void print(customer *, int);
void pastdue(customer*);
void del(customer *);

int main() {
    ///create new customer and set out to false and balance to 0
    customer *cust = new customer;
    cust->out=false;
    cust->balance=0;
    int input;
    int movie_size;
    float balance;
    string name;
    ///start with the welcome screen
    cout << "\t\t\nWelcome to Diego's video rental" << endl;
    ///ask for customer starting info
    cout << "Please enter customer's account number: ";
    cin >> cust->member;
    cout << "\nPlease enter customer's first name: ";
    cin >> cust->f_name;
    cout << "\nPlease enter customer's last name: ";
    cin >> cust->l_name;
    cout << "\nWhat would you like to do for Mr. " << cust->l_name << endl;
    ///do while loop to allow to come back for menu
    do{
        ///print main menu
        printmenu();
        cin >> input;
        switch(input){
            ///enter customers balance
        case 1:
            cout << "\nWhat is the customer's balance: ";
            cin >> balance;
            setBalance(cust,balance);
            break;
        case 2:
            ///add to a customers balance
            cout << "\nHow much more do you wish to add to a customer's balance: ";
            cin >> balance;
            addBalance(cust,balance);
            break;
        case 3:
            ///apply payment to customers account
            cout << "\nHow much is the customer paying today: ";
            cin >> balance;
            payBalance(cust,balance);
            break;
        case 4:
            ///change the customers first name
            cout << "\nWhat is the new first name: ";
            cin >> name;
            changeFirst(cust,name);
            break;
        case 5:
            ///chjange the customers last name
            cout << "\nWhat is the new last name: ";
            cin >> name;
            changeLast(cust,name);
            break;
        case 6:
            ///checkout movies to the custoemrs
            cout << "\nHow many movies are we checking out: ";
            cin >> movie_size;
            checkout(cust,movie_size);
            break;
        case 7:
            ///print all customer pertinent info
            print(cust, movie_size);
            break;
        case 8:
            ///set the customers account as past due
            pastdue(cust);
            break;
        case 9:
            ///delete the customer info array
            del(cust);
            break;
            
    }
    }while(input!=9);
    
    


}
///main menu function
void printmenu()
{
    cout << "\n\n1. Enter a new balance for the customer enter: " << endl;
    cout << "2. Add a balance to a customer" << endl;
    cout << "3. Enter a customer payment" << endl;
    cout << "4. Change first name of customer" << endl;
    cout << "5. Change last name of customer" << endl;
    cout << "6. Checkout movies to a customer" << endl;
    cout << "7. Print out customer information" << endl;
    cout << "8. Mark customer as past due" << endl;
    cout << "9. Quit the program\n" << endl;

}
///set the customer balance
void setBalance(customer *a, float bal)
{
    a->balance=bal;
}
///add to customers balance
void addBalance(customer *a, float bal)
{
    a->balance+=bal;
    cout << "\nCustomer's new balance is $" << a->balance << endl;
}
///apply payment to customers balance and apply warning if customer overpaying
void payBalance(customer *a, float bal)
{
    a->balance-=bal;
    if(a->balance<0){
        cout << "\nPlease inform the customer he is overpaying and will"
                " have a credit of $" << a->balance << endl;
    }
}
///change the first name of the customer
void changeFirst(customer *a, string name)
{
    a->f_name=name;
    cout << "\nPlease confirm with the customer the spelling of their name"
            " first name will now be " << a->f_name << endl;
}
///change the last name of the customer
void changeLast(customer *a, string name)
{
    a->l_name=name;
    cout << "\nPlease confirm with the customer the spelling of their name"
            " last name will now be " << a->l_name << endl;
}
///checkout movies to the customer
void checkout(customer *a,int size)
{
    a->out=true;
    a->movies=new string[size];
    ///ask for the title of the movies
    for(int i=0;i<size;i++)
    {
        cout << "\nPlease enter title of movie #" << i+1 << ": ";
        cin >> a->movies[i];
    }
}
///print all customer info and check for past due or movies out
void print(customer *a, int size)
{
    cout << "\nCustomer Account Information: "
            "\nName:\t" << a->f_name << " " << a->l_name <<
            "\nAccount Number:\t" << a->member << 
            "\nCustomer Balance:\t" << a->balance;
    if(a->pastdue)
    {
        cout << "\nCustomer's account is currently past due";
    }
    if(a->out)
    {
        cout << "\nMovies currently checked out:";
                for(int i=0;i<size;i++)
                {
                    cout << "\n\t\t" << i+1 << a->movies[i];
                }
        cout << endl;
    }
    
}
//mark an account as past due
void pastdue(customer *a)
{
    if (a->balance<1)
    {
        cout << "\nError cannot mark an account with no balance as past due!\n";
    }
    else{
        char choice;
        cout << "\nAre you sure you want to mark the customer as past due? (y/n) " << endl;
        cin >> choice;
        if(choice =='y' || choice == 'Y')
        {
           a->pastdue=true;
        }
    }
}
///delete the customer informationa nd check if he has movies out
void del(customer *a)
{
    if(a->out)
    {
        delete []a->movies;
    }
    delete a;
}