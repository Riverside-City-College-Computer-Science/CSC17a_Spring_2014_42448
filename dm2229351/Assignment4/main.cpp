//Mark E. Lehr
//October 27th, 2011
//Menu to be used for the midterm
//homework and midterm, etc....

#include <iostream>
#include "Employee.h"
#include "ProductionWorker.h"
#include "ShiftSupervisor.h"
#include "TeamLeader.h"
#include "CustomerData.h"
#include "PersonData.h"
#include "PreferredCustomer.h"
using namespace std;
void custMailingList(bool);
void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();


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
          default:   def(inN);}
        }while(inN<8);
        return 1;
    }
    void Menu()
    {
           cout<<"\nType 1 for problem 15-1"<<endl;
           cout<<"Type 2 for problem 15-2"<<endl;
           cout<<"Type 3 for problem 15-3"<<endl;
           cout<<"Type 4 for problem 15-7"<<endl;
           cout<<"Type 5 for problem 15-8\n"<<endl;
           
    }
    int getN()
    {
           int inN;
           cin>>inN;
           return inN;
    }
    void problem1()
    {
           cout<<"In problem # 1"<<endl<<endl;
               ProductionWorker prod("Diego",335449,"04-04-2014",1,25.65);
    cout << "\nEmployee \t" << prod.getName();
    cout << "\nEmp_ID \t\t" << prod.getNum();
    cout << "\nEmp Hire Date\t" << prod.getHireDate();
    cout << "\nEmployee Shift\t" << prod.getShift();
    cout << "\nEmployee Rate\t" << prod.getRate();
    }
    void problem2()
    {
           cout<<"In problem # 2"<<endl<<endl;
               ShiftSupervisor sup("Diego",335449,"04-04-2014",50000,5000);
    cout << "\nEmployee \t" << sup.getName();
    cout << "\nEmp_ID \t\t" << sup.getNum();
    cout << "\nEmp Hire Date\t" << sup.getHireDate();
    cout << "\nSup. Salary\t" << sup.getSalary();
    cout << "\nSup Bonus\t" << sup.getProduction();
    }
    void problem3()
    {
           cout<<"In problem # 3"<<endl<<endl;
           TeamLeader team("Diego",335449,"04-04-2014",1,23.25, 5000, 25, 50);
    cout << "\nTeam Leader Name \t" << team.getName();
    cout << "\nTeam Leader_ID \t\t" << team.getNum();
    cout << "\nTeam Leader Hire Date\t" << team.getHireDate();
    cout << "\nTeam Leader Shift\t" << team.getShift();
    cout << "\nTeam Leader Rate\t" << team.getRate();
    cout << "\nTeam Leader Bonus Possible\t" << team.getBonus();
    cout << "\nTeam Leader Training Hours Worked\t" << team.getTotalTraining();
    cout << "\nTeam Leader Training Hours Needed\t\t" << team.getReqTraining();
    }
    void problem4()
    {
           cout<<"In problem # 4"<<endl<<endl;
            CustomerData cust("Diego", "Montelongo", "12533 Black Horse","Eastvale",
            "CA",91752,"909-524-8487",1,true);
    cout << cust.getFirstName() << " " << cust.getLastName() << endl;
    cout << cust.getAddress() << " " << cust.getCity() << ", " << cust.getZip() << endl;
    cout << cust.getPhone() << " Customer Unique ID: " << cust.getCustNum() << endl;
    custMailingList(cust.getMailingList());
    
    CustomerData cust1("Julie", "Montelongo", "12533 Black Horse","Eastvale",
            "CA",91752,"909-524-8487",2,true);
    cout << cust1.getFirstName() << " " << cust1.getLastName() << endl;
    cout << cust1.getAddress() << " " << cust1.getCity() << ", " << cust1.getZip() << endl;
    cout << cust1.getPhone() << " Customer Unique ID: " << cust1.getCustNum() << endl;
    custMailingList(cust1.getMailingList());
    
    CustomerData cust2("George", "Lopez", "48654 Engle Ase","Charlieville",
            "CA",95554,"909-524-1300",3,false);
    cout << cust2.getFirstName() << " " << cust2.getLastName() << endl;
    cout << cust2.getAddress() << " " << cust2.getCity() << ", " << cust2.getZip() << endl;
    cout << cust2.getPhone() << " Customer Unique ID: " << cust2.getCustNum() << endl;
    custMailingList(cust2.getMailingList());
    }
    void problem5()
    {
           cout<<"In problem # 5"<<endl<<endl;
           int choice;
           double purchase=0;
            PreferredCustomer pref("Diego", "Montelongo", "12533 Black Horse","Eastvale",
            "CA",91752,"909-524-8487",1,true);
            while(choice<3){
                cout << "What would  you like to do for customer?" << endl;
                cout << "1. Displayer customer information" << endl;
                cout << "2. Enter customer purchase" << endl;
                cout << "3. Quit" << endl;
                cin >> choice;
                switch(choice)
                {
                    case 1:
                        cout << pref.getFirstName() << " " << pref.getLastName() << endl;
                        cout << pref.getAddress() << " " << pref.getCity() << ", " << pref.getZip() << endl;
                        cout << pref.getPhone() << " Customer Unique ID: " << pref.getCustNum() << endl;
                        custMailingList(pref.getMailingList()); 
                        break;
                    case 2:
                                cout << "Please enter purchase amount (positive number): ";
                                cin >> purchase;
                                while(purchase <1)
                                {
                                    cout << "Please enter purchase amount (positive number): ";
                                cin >> purchase;
                                }
                        pref.addPurchaseAmount(purchase);
                        if(pref.getPurchaseAmount()>499 && pref.getPurchaseAmount()<1000)
                            pref.setDiscountLevel(.05);
                        else if(pref.getPurchaseAmount()>999 && pref.getPurchaseAmount()<1500)
                            pref.setDiscountLevel(.06);
                        else if(pref.getPurchaseAmount()>1499 && pref.getPurchaseAmount()<2000)
                            pref.setDiscountLevel(.07);
                        else if (pref.getPurchaseAmount()>2000)
                            pref.setDiscountLevel(.1);
                        break;
                }
                cout << "\nCustomer's purchase amount is " <<  pref.getPurchaseAmount() << endl;
                cout << "Customer's discount level is " << pref.getDiscountLevel() << endl;
            }
    }
    void def(int inN)
    {
           cout<<"You typed "<<inN<<" to exit the program"<<endl;
    }
    
    void custMailingList(bool m)
{
    if(m)
    {
        cout << "Customer is in our mailing list" << endl;
    }
    else
        cout << "Customer is not on our mailing list" << endl;
}