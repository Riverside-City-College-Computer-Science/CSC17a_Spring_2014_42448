/*      Scott Nevin
 *      April 24, 2014
 *      Midterm for CSC-17A
 *      42448
 */

//Libraries
#include <iostream>
#include <cstdlib>
#include <string>
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
//Function prototypes for problem 1
void acntNum(string &);//collects and validates account number
void acntSum(string, int, int, int, int);//outputs data collected into a report
int getBal();//collects initial balance
int getChk();//collects total amount of checks written
int getDep();//collects total amount of deposits made 
int getTot(int, int, int);//calculates new balance of account

//Declare structures
//Structure for problem 1
struct info{
    string accnt;//user's account number
    int begBal;//balance at beginning of the month
    int chcks;//total of checks written during the month
    int depst;//total of deposits made during the month
    int newBal;//balance after calculations
};

//Begin Execution Here!!!
int main(int argv,char *argc[]){
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
        default:   def(inN);}
    }while(inN>=1&&inN<=6);
    return 0;//If midterm not perfect, return something other than 1
}

void Menu(){
    cout<<"Menu for the Midterm"<<endl;
    cout<<"Type 1 for problem 1"<<endl;
    cout<<"Type 2 for problem 2"<<endl;
    cout<<"Type 3 for problem 3"<<endl;
    cout<<"Type 4 for problem 4"<<endl;
    cout<<"Type 5 for problem 5"<<endl;
    cout<<"Type 6 for problem 6"<<endl;
    cout<<"Type anything else to exit \n"<<endl;
}

int getN(){
        int inN;
        cin>>inN;
        return inN;
}

void problem1(){
    
    //initialize user info structure
    info user;
    
    //Collect user Account number
    acntNum(user.accnt);
    
    //collect initial balance
    user.begBal = getBal();
    
    //collect checks written
    user.chcks = getChk();
    
    //collect deposits made
    user.depst = getDep();
    
    //calculate new balance
    user.newBal = getTot(user.begBal, user.chcks, user.depst);
    
    //output account summary
    acntSum( user.accnt, user.begBal, user.chcks, user.depst, user.newBal);
    
    cout<<endl;
    
    //EXIT PROBLEM 1
}
//Functions for problem 1
void acntSum(string a, int b, int c, int d, int n){
    
    //output account report
    cout<<"__________ACCOUNT REPORT___________"<<endl;
    cout<<"Acnt. Number.................."<<a<<endl;
    cout<<"Balance at 1st of month......$"<<b<<endl;
    cout<<"Checks written...............$"<<c<<endl;
    cout<<"Deposits made................$"<<d<<endl;
    cout<<"Total Account balance........$"<<n<<endl;
    
    //if account is overdrawn, make new report charge $12
    if(n<0){
        //charge $12
        n-=12;
        
        //output bad news
        cout<<"You have overdrawn this month and a fee of $12"<<endl;
        cout<<"has been charged to your account."<<endl;
        cout<<"Your new account balance is $"<<n<<endl;
    }
}

int getTot(int b, int c, int d){
    
    //declare variables
    int total=0;
    
    total = b + (c*-1) + d;
    
    return total;
    
}

int getDep(){
    
    //Declare variables
    int temp, choice, total=0;
    
    //prompt user for number of deposits ,made
    cout<<"How many deposits did you make this month?"<<endl;
    cin>>choice;
    
    //test if input is valid
    if(choice<0){
        do{
            //inform user of error and prompt for balance again
            cout<<"Invalid amount, please enter a value above 0"<<endl;
            cin>>choice;

        }while(choice<0);
    }
    
    //collect amount of each deposit using loop
    cout<<"Input amount of each deposit:"<<endl;
    for(int i=0;i<choice;i++){
        
        //collect check data
        cout<<"Deposit #"<<i+1<<": ";
        cin>>temp;
        
        //validate input
        if(temp<0){
            do{
                //inform user of error and prompt for balance again
                cout<<"Invalid amount, please enter a value above 0"<<endl;
                cout<<"Deposit #"<<i<<": ";
                cin>>temp;

             }while(temp<0);
        }
         
         //add amount to total
         total += temp;
    }
    
    //return total amount
    return total;
    
}
int getChk(){
    
    //Declare variable
    int temp, choice, total=0;
    
    //prompt user for number of checks written
    cout<<"How many checks did you write this month?"<<endl;
    cin>>choice;
    
    //test if input is valid
    if(choice<0){
        do{
            //inform user of error and prompt for balance again
            cout<<"Invalid amount, please enter a value above 0"<<endl;
            cin>>choice;

        }while(choice<0);
    }
    
    //collect amount of each check using loop
    cout<<"Input amount of each check:"<<endl;
    for(int i=0;i<choice;i++){
        
        //collect check data
        cout<<"Check #"<<i+1<<": ";
        cin>>temp;
        
        //validate input
        if(temp<0){
            do{
                //inform user of error and prompt for balance again
                cout<<"Invalid amount, please enter a value above 0"<<endl;
                cout<<"Check #"<<i<<": ";
                cin>>temp;

             }while(temp<0);
        }
         
         //add amount to total
         total += temp;
    }
    
    //return total amount
    return total;
}

int getBal(){
    
    //declare variable
    int temp;
    
    //prompt user for initial account balance
    cout<<"What was the balance of your account at the beginning of the month?"<<endl;
    cin>>temp;
        
        return temp;
}

void acntNum(string &accnt){
    
    //Prompt user for account number
    cout<<"Please enter 5 digit Account number: ";
    cin>>accnt;
    
    //test if string length is correct
    if(accnt.length()!=5){
        do{
            //prompt user to reenter number
            cout<<endl;
            cout<<"Invalid account number"<<endl;
            cout<<"Account number must be 5 digits exactly"<<endl;
            cout<<"Please enter 5 digit Account number: ";
            cin>>accnt;
            cout<<endl;
            
        }while(accnt.length()!=5);
    }
        
    //Place null terminator
    accnt[5]='\0';
}

void problem2(){
        cout<<"In problem # 2"<<endl<<endl;
}

void problem3(){
        cout<<"In problem # 3"<<endl<<endl;
}

void problem4(){
        cout<<"In problem # 4"<<endl<<endl;
}

void problem5(){
        cout<<"In problem # 5"<<endl<<endl;
}

void problem6(){
        cout<<"In problem # 6"<<endl<<endl;
}

void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}