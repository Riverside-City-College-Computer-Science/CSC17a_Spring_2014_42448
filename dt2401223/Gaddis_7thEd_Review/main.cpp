/* 
 * File:   main.cpp
 * Author: Devin Taniguchi
 * Created on February 26, 2014, 12:15 PM
 * Purpose: Review
 */

//Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>
using namespace std;

//Global Constants

//Function Prototypes
void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();
void celcius(float);

//Execution States here
    int main(int argv,char *argc[])
    {
        int inN;
        do{
            Menu();
            inN=getN();
            switch(inN){
            case 1:    problem1();break;
            case 2:    problem2();break;
            case 3:    problem3();break;
            case 4:    problem4();break;
            case 5:    problem5();break;
            case 6:    problem6();break;
            case 7:    problem7();break;
            default:   def(inN);}
        }while(inN<7);
        return 0;
    }
    void Menu(){
            cout<<"Menu for the Homework Review"<<endl;
            cout<<"Type 1 for problem 3.12"<<endl;
            cout<<"Type 2 for problem 3.13"<<endl;
            cout<<"Type 3 for problem 4.10"<<endl;
            cout<<"Type 4 for problem 5.11"<<endl;
            cout<<"Type 5 for problem 6.7"<<endl;
            cout<<"Type 6 for problem 7.6"<<endl;
            cout<<"Type 7 for problem 8.7"<<endl;
            cout<<"Type anything else to exit"<<endl;
    }
    int getN(){
            int inN;
            cin>>inN;
            return inN;
    }
    void problem1(){
            cout<<"In problem # 3.12"<<endl<<endl;
            cout<<fixed<<showpoint<<setprecision(2)<<endl;
            //Declare Variables
            float total,
                  pSale,
                  cTax,
                  sTax,
                  tTax;
            string mnth;
            int yr;
            //Calculate 
            cout<<"Please enter the month, the year, and the total amount "
                  "collected in that order"<<endl;
            cin>>mnth;
            cin>>yr;
            cin>>total;
            cTax=total-(total/1.02);
            sTax=total-(total/1.04);
            tTax=sTax+cTax;
            pSale=total-tTax;
            //Output results
            cout<<"Month: "<<mnth<<endl;
            cout<<"Year: "<<yr<<endl;
            cout<<"-----------------------------"<<endl;
            cout<<"Total Collected: "<<total<<endl;
            cout<<"Sales: "<<pSale<<endl;
            cout<<"County Sales Tax: "<<cTax<<endl;
            cout<<"State Sales Tax: "<<sTax<<endl;
            cout<<"Total Sales Tax: "<<tTax<<endl;
            cout<<endl;
    }

    void problem2(){
            cout<<"In problem # 3.13"<<endl<<endl;
            cout<<fixed<<showpoint<<setprecision(2)<<endl;
            //Declare Variables
            float asVal,
                  acVal,
                  pTax;
            cout<<"What is the property's actual value?"<<endl;
            cin>>acVal;
            //Calculate
            asVal=acVal*.6;
            if((asVal/100)>1){
                pTax=(asVal/100)*.64;
            }
            else{pTax=0;
            }
            //Output Results
            cout<<"Property's actual value: "<<acVal<<endl;
            cout<<"Property's assessment value: "<<asVal<<endl;
            cout<<"Property Tax: "<<pTax<<endl;
    }

    void problem3(){
            cout<<"In problem # 4.10"<<endl<<endl;
            cout<<fixed<<showpoint<<setprecision(2)<<endl;
            //Declare Variables
            float sold,
                  cost,
                  fCost;
            cout<<"How many units were sold?"<<endl;
            cin>>sold;
            while(sold<=0){
                cout<<"Please enter a value greater than 0."<<endl;
                cin>>sold;
            }
            //Calculate
            cost=sold*99;
            if(sold>=10){
                if(sold>=20){
                    if(sold>=50){
                        if(sold>=100){
                            fCost=(cost)-(cost-((cost)*.50));
                            
                        }
                        else{
                            fCost=(cost)-(cost-((cost)*.40));
                        }
                    }
                    else{
                        fCost=(cost)-(cost-((cost)*.30));
                    }
                    
                }
                else{
                    fCost=(cost)-(cost-((cost)*.20));
                }
            }
            else{
                fCost=cost;
            }
            cout<<"Total cost is $"<<fCost<<endl;
    }

    void problem4(){
            cout<<"In problem # 5.11"<<endl<<endl;
            //Declare variables
            float iPop,
                  nPop,
                  cPop,
                  inc,
                  period;
            //Input
            cout<<"What is the initial number of the population?"<<endl;
            cin>>iPop;
            cout<<"What is the rate that the population is multiplying?"
                    "(in percentage)"<<endl;
            cin>>inc;
            inc*=.01;
            cout<<"How long is the population multiplying for? (days)"<<endl;
            cin>>period;
            cPop=iPop;
            cout<<"-----------------------------------"<<endl;
            cout<<"Day          Population"<<endl;
            cout<<"1            "<<iPop<<endl;
            //Loop
            for(int i=2;i<period;i++){
                nPop=(cPop*inc)+cPop;
                cout<<i<<"            "<<nPop<<endl;
                cPop=nPop;
            }
            
            
    }

    void problem5(){
            cout<<"In problem # 6.7"<<endl<<endl;
            //Declare Variables
    }

    void problem6(){
            cout<<"In problem # 7.6"<<endl<<endl;
    }

    void problem7(){
            cout<<"In problem # 8.7"<<endl<<endl;
    }
    
    void def(int inN){
            cout<<"You typed "<<inN<<" to exit the program"<<endl;
    }
    
    float celcius(float f){
        float c;
        c=(5/9)*(f-32);
        cout<<c;
    }

