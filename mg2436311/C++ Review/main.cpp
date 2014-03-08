/* 
 * Author: Miguel Gaona
 * Class: CIS 17a
 * Section: 42448
 * Created on March 5, 2014, 9:47 AM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
using namespace std;

void Menu();
int getChoice();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();
float celsius(float);
struct MonthlyBudget
{
    float housing,
          utilities,
          expenses,
          transport,
          food,
          medical,
          insurance,
          entertain,
          clothes,
          misc;
};
void printExpenses(MonthlyBudget, MonthlyBudget);
void getExpenses(MonthlyBudget &);

    int main(int argv,char *argc[])
    {
	int choice;
        
        do
        {
         Menu();
         choice=getChoice();
         switch(choice)
            {
              case 1:    problem1();break;
              case 2:    problem2();break;
              case 3:    problem3();break;
              case 4:    problem4();break;
              case 5:    problem5();break;
              case 6:    problem6();break;
              case 7:    problem7();break;
              default:   def(choice);
            }
        }
        while(choice<8);
        
        return 0;
    }
    void Menu()
    {
           cout<<"Type 1 for problem 1"<<endl;
           cout<<"Type 2 for problem 2"<<endl;
           cout<<"Type 3 for problem 3"<<endl;
           cout<<"Type 4 for problem 4"<<endl;
           cout<<"Type 5 for problem 5"<<endl;
           cout<<"Type 6 for problem 6"<<endl;
           cout<<"Type 7 for problem 7"<<endl;
           cout<<"Type 8 to exit"<<endl<<endl;
    }
    int getChoice()
    {
           int choice;
           cin>>choice;
           return choice;
    }
    void problem1()
    {
        cout<<"In problem #1"<<endl<<endl;
        
     	const float YEN_PER_DOLLAR = .952;
	const float EUROS_PER_DOLLAR = .7157;
	float dollars;

	cout<<"Enter the amount in dollars to be converted: $";
	cin>>dollars;

        cout<<"The amount in Euros is: "<<dollars*EUROS_PER_DOLLAR<<endl;
        cout<<"The amount in Yen is: "<<dollars*YEN_PER_DOLLAR<<endl;
        cout<<endl<<endl<<endl;
    }
    void problem2()
    {
        cout<<"In problem #2"<<endl<<endl;
        
        string month;
        int year;
        float total;
        float sales;
        const float STATE_TAX = .04;
        const float COUNTY_TAX = .02;
        float state_tax_collected;
        float county_tax_collected;
        float total_tax;

        cout<<"Enter the month: ";
        cin>>month;
        cout<<"Enter the year: ";
        cin>>year;
        cout<<"Enter the amount collected at the register: $";
        cin>>total;

        sales = total/1.06;
        state_tax_collected = sales*STATE_TAX;
        county_tax_collected = sales*COUNTY_TAX;
        total_tax = county_tax_collected + state_tax_collected;

        cout<<fixed<<setprecision(2);
        cout<<endl<<endl;
        cout<<"Month: "<<month<<" "<<year<<endl;
        cout<<"----------------"<<endl;
        cout<<"Total collected:     $"<<total<<endl;
        cout<<"Sales:               $"<<sales<<endl;
        cout<<"County Sales Tax:    $"<<county_tax_collected<<endl;
        cout<<"State Sales Tax:     $"<<state_tax_collected<<endl;
        cout<<"Total Sales Tax:     $"<<total_tax<<endl;
        cout<<endl<<endl;
    
    }
    void problem3()
    {
           cout<<"In problem # 3"<<endl<<endl;
           
           const float base_fee = 10.00;
           const float tiny_fee = 0.04;
           const float small_fee = 0.06;
           const float med_fee = 0.08;
           const float large_fee = 0.10;
           float total_fees;
           int checks;
           
           cout<<"How many checks have you written this past month?: ";
           cin>>checks;
           
           if (checks < 20)
           {
              total_fees = base_fee + large_fee;
           }
           else if (checks>=20 && checks<=39)
           {
               total_fees = base_fee + med_fee;
           }
           else if (checks>=40 && checks<=59)
           {
               total_fees = base_fee + small_fee;
           }
           else if (checks>=60)
           {
               total_fees = base_fee + tiny_fee;
           }
           else if (checks < 0)
           {
               cout<<"That is not a valid input. Please run the program again"
                       "and input a positive number.";
           }
           
           cout<<"You're total fee is $"<<total_fees<<endl<<endl;
    }
    void problem4()
    {
           cout<<"In problem # 4"<<endl<<endl;
           
           int number;
           int guess;
           
           srand(time(0));
           number = rand()%99 + 1;

           cout<<"Welcome to the Number Guessing Game! Try to guess my number."<<endl;
           
           do {
                cout<<"Enter your guess: ";
                cin>>guess;
                
                if (guess < number)
                {
                    cout<<"Too low. Try Again."<<endl;
                }
                else if (guess > number)
                {
                   cout<< "Too high. Try Again."<<endl;
                }
           } while (guess != number);
           
          cout<<"Congratulations! You figured out my number!"<<endl<<endl;
    }
    void problem5()
    {
        cout<<"In problem # 5"<<endl<<endl;
        
        float degF;
        float degC;
        
	cout<<"Enter a temperature in Fahrenheit: ";
	cin>>degF;
        
        degC = celsius(degF);
        
	cout<<"Converts to: "<<degC<<" degrees Celsius"<<endl<<endl;
    }
    void problem6()
    {
          cout<<"In problem # 6"<<endl<<endl;
           
          MonthlyBudget first, second;
           
          first.housing = 500;
          first.utilities = 150;
          first.expenses = 65;
          first.transport = 50;
          first.food = 250;
          first.medical = 30;
          first.insurance = 100;
          first.entertain = 150;
          first.clothes = 75;
          first.misc = 50;       
          
          getExpenses(second);
          printExpenses(first, second);
           
          cout<<endl<<endl;
    }
    void problem7()
    {
	cout<<"In problem # 7"<<endl<<endl;
        
                
    }
    void def(int choice)
    {
           cout<<"You typed "<<choice<<" to exit the program"<<endl;
    }
    float celsius(float f)
    {
        float c = (5/9)*(f-32);
        return c;
    }
    void getExpenses(MonthlyBudget &second)
    {
        cout<<"Enter your expenses for the month."<<endl;
        cout<<"Housing: ";
        cin>>second.housing;
        cout<<"Utilities: ";
        cin>>second.utilities;
        cout<<"Household Expenses: ";
        cin>>second.expenses;
        cout<<"Transportation: ";
        cin>>second.transport;
        cout<<"Food: ";
        cin>>second.food;
        cout<<"Medical: ";
        cin>>second.medical;
        cout<<"Insurance: ";
        cin>>second.insurance;
        cout<<"Entertainment: ";
        cin>>second.entertain;
        cout<<"Clothing: ";
        cin>>second.clothes;
        cout<<"Miscellaneous: ";
        cin>>second.misc;
    }
    void printExpenses(MonthlyBudget first, MonthlyBudget second)
    {
        float atotal = first.housing+first.utilities+first.expenses+first.transport+first.food+first.medical+first.insurance+first.entertain+first.clothes+first.misc,
              btotal = second.housing+second.utilities+second.expenses+second.transport+second.food+second.medical+second.insurance+second.entertain+second.clothes+second.misc,
              debt;
        
           
           cout<<fixed<<setprecision(2);
           cout<<"Your budget for this month."<<endl;
           cout<<"*************************"<<endl;
           cout<<"Housing               "<<first.housing<<endl;
           cout<<"Utilities             "<<first.utilities<<endl;
           cout<<"Household Expenses    "<<first.expenses<<endl;
           cout<<"Transportation        "<<first.transport<<endl;
           cout<<"Food                  "<<first.food<<endl;
           cout<<"Medical               "<<first.medical<<endl;
           cout<<"Insurance             "<<first.insurance<<endl;
           cout<<"Entertainment         "<<first.entertain<<endl;
           cout<<"Clothing              "<<first.clothes<<endl;
           cout<<"Miscellaneous         "<<first.misc<<endl<<endl;
           cout<<"*************************"<<endl;
           cout<<"TOTAL: $"<<atotal<<endl;
           cout<<"*************************"<<endl<<endl;
           
           cout<<fixed<<setprecision(2);
           cout<<"Your expenses this month."<<endl;
           cout<<"*************************"<<endl;
           cout<<"Housing               "<<second.housing<<endl;
           cout<<"Utilities             "<<second.utilities<<endl;
           cout<<"Household Expenses    "<<second.expenses<<endl;
           cout<<"Transportation        "<<second.transport<<endl;
           cout<<"Food                  "<<second.food<<endl;
           cout<<"Medical               "<<second.medical<<endl;
           cout<<"Insurance             "<<second.insurance<<endl;
           cout<<"Entertainment         "<<second.entertain<<endl;
           cout<<"Clothing              "<<second.clothes<<endl;
           cout<<"Miscellaneous         "<<second.misc<<endl;
           cout<<"*************************"<<endl;
           cout<<"TOTAL: $"<<btotal<<endl;
           cout<<"*************************"<<endl;
           
           debt = atotal - btotal;
           if(debt<0)
           {
               cout<<"You are $"<<abs(debt)<<" over budget";
           }
           else if(debt>0)
           {
               cout<<"You are $"<<debt<<" under budget";
           }
    }