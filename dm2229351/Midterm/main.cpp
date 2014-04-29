/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on April 23, 2014, 12:07 PM
 */

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct account{
    int acct_num;
    int balance;
    int *deposits;
    int *withdrawals;
    int deps;
    int withs;
};

struct employee{
    string first;
    string last;
    float hours;
    float rate;
    float pay;
};
struct statsResult
{
    float avg;
    float median;
    int *mode;   //array containing the modes
    int nModes;  //number of modes in the array
    int maxFreq; //max frequency of modes
};
statsResult *avgMedMode(int *,int); 
void printStat(statsResult *);
//Global Constants Here!!!

//Function Prototypes Here!!!
void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();

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
    cout << endl;
    cout<<"Menu for the Midterm"<<endl;
    cout<<"Type 1 for problem 1"<<endl;
    cout<<"Type 2 for problem 2"<<endl;
    cout<<"Type 3 for problem 3"<<endl;
    cout<<"Type 4 for problem 4 (Encryption)"<<endl;
    cout<<"Type 5 for problem 4 (Decryption)"<<endl;
    cout<<"Type 6 for problem 5 and 6"<<endl;
    cout<<"Type anything else to exit \n"<<endl;
}

int getN(){
        int inN;
        cin>>inN;
        return inN;
}

void problem1(){
        cout<<"In problem # 1"<<endl<<endl;
        account *acc = new account;
        cout << "Please enter account number\n";
         do {
             cout << "Account number must be 5 digits, please re-enter:\n";
             cin >> acc->acct_num;
         }
        while (acc->acct_num < 10000 || acc->acct_num > 99999);
        cout << "Please enter beginning account balance\n";
        cin >> acc->balance;
        //start withdrawals
        cout << "Please enter number of withdrawals: \n";
        cin >> acc->withs;
        acc->withdrawals=new int[acc->withs];
        for (int i=0; i< acc->withs; i++)
        {
            cout << "\nPlease enter " <<  i+1 << "st check: ";
            cin >> acc->withdrawals[i];
            acc->balance-=acc->withdrawals[i];
        }
        cout << "Balance after withdrawals: " << acc->balance << endl;
        
        //Start deposits
        cout << "Please enter number of deposits: \n";
        cin >> acc->deps;
        acc->deposits=new int[acc->deps];
        for (int i=0; i< acc->deps; i++)
        {
            cout << "\nPlease enter " <<  i+1 << "st check: ";
            cin >> acc->deposits[i];
            acc->balance+=acc->deposits[i];
        }
        if(acc->balance<0){
            acc->balance-=12;
            cout << "Account was overdrawn, $12 fee was assessed and included in balance\n";
        }
        cout << "Balance after deposits: " << acc->balance << endl;
        delete acc;       
}

void problem2(){
    while (true){
        cout<<"In problem # 2 enter negative values in hours or rate to quit"<<endl<<endl;
        employee emp;
        emp.pay=0;
        cout << "Please enter first name of employee: ";
        cin >> emp.first;
        cout << "\nPlease enter last name of employee: ";
        cin >> emp.last;
        cout << "\nPlease enter hours worked: ";
        cin >> emp.hours;
        if(emp.hours<0)
            break;
        cout << "Please enter rate of pay of employee: ";
        cin >> emp.rate;
        if(emp.rate<0)
            break;
        if (emp.hours<20)
        {
            emp.pay+=emp.hours*emp.rate;
        }
        else if(emp.hours > 20 && emp.hours<=40 )
        {
            emp.pay+=(2*emp.rate)*(emp.hours-20);
            emp.pay+=20*emp.rate;
        }
        else if(emp.hours >40)
        {
            emp.pay+=(emp.hours-40)*(3*emp.rate);
            emp.pay+=20*(2*emp.rate);
            emp.pay+=20*emp.rate;
        }
        cout << "Check payable to " << emp.first << " " << emp.last << endl;
        cout << "For the amount of " << emp.pay << endl;
    }      
}

void problem3(){
        cout<<"In problem # 3"<<endl<<endl;
        int size,*array;
        statsResult *p;
        cout <<  "Enter size of array: ";
        cin >> size;
        array=new int[size];
        for(int i=0;i<size;i++)
        {
            cout << "\nEnter data into array: ";
            cin >> array[i];
        }
        p=avgMedMode(array,size);
        printStat(p);
        delete []p->mode;
        delete p;
}

void problem4(){
        cout<<"In problem # 4 Encryption"<<endl<<endl;
        char nums[4];
        int number[4];
        do{
            cout <<"Enter a valid 4 digit code to encrypt(0-7)";
            cin >> nums;
            for(int i=0;i<4;i++)
            {
                number[i]=nums[i]-'0';
            }
        }while(number[0]>7 || number[1]>7 || number[2]>7 || number[3]>7);
        for(int i=0;i<4;i++)
        {
            number[i]+=3;
            number[i]%=8;
        }
        int temp=number[0];
        number[0]=number[1];
        number[1]=temp;
        temp=number[2];
        number[2]=number[3];
        number[3]=temp;
        cout << "Your encrypted number is: ";
        for(int i=0;i<4;i++)
        {
            cout << number[i];
        }
        cout << endl;      
}

void problem5(){
        cout<<"In problem # 4 Decryption"<<endl<<endl;
        char nums[4];
        int number[4];
        do{
            cout <<"Enter a valid 4 digit code to decrypt(0-7)";
            cin >> nums;
            for(int i=0;i<4;i++)
            {
                number[i]=nums[i]-'0';
            }
        }while(number[0]>7 || number[1]>7 || number[2]>7 || number[3]>7);
        int temp=number[0];
        number[0]=number[1];
        number[1]=temp;
        temp=number[2];
        number[2]=number[3];
        number[3]=temp;
        for(int i=0;i<4;i++)
        {
            if(number[i]>2)
            {
                number[i]-=3;
            }
            else
            {
                number[i]+=5;
            }
        }
        cout << "Your decrypted number is: ";
        for(int i=0;i<4;i++)
        {
            cout << number[i];
        }
        cout << endl;
}

void problem6(){
        cout<<"In problem # 5 and 6"<<endl<<endl;
        cout << "5a) 5!" << endl;
        cout << "5b) short: 7!\nint: 16!\nlong: 16!\nfloat: 34!\ndouble: 170!\n";
        cout << "6a) 2.125 \t hex: 2.2 \t bin: 10.001 \t octal: 2.1" << endl;
        cout << "6a) 0.06640625 \t hex: 0.11 \t bin: 0.00010001 \t octal: 0.0428" << endl;
        cout << "6a) -2.125 float representation: C4000002" << endl;
        cout << "6a) .066440625 float representation: 08800000" << endl;
        cout << "6b) 46666601 to dec is 1.09375" << endl;
        cout << "6b) 46666602 to dec is 2.1875" << endl;
        cout << "6b) B9999AFE to dec is -3774874x2^232" << endl;
}

void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}

statsResult *avgMedMode(int *a,int size)
{
    statsResult *s = new statsResult;
    //average
    float total=0;
    for(int i=0;i<size;i++)
    {
        total+=a[i];
    }
    s->avg=total/size;
    //median
    float temp=0;
    if(size%2==1)
    {
        s->median=a[size/2];
    }
    else if(size%2==0)
    {
        temp+=a[size/2-1];
        temp+=a[size/2];
        s->median=temp/2.0;
    }
    //---max frequency-----------------------
    int count=1, max=1, freq;
    for(int i=1;i<size;i++){
        if(a[i-1]==a[i]){
            count++;
            if(count>max)max=count;
        }else{
            count=1;
        }
    }
    freq=max;
    s->maxFreq=freq;
    //=====================modes======================
    int mode=0;
 
    count=1, max=1;
    for(int i=1;i<size;i++){
        if(a[i-1]==a[i]){
            count++;
            if(count==freq){
                mode++; 
            }
        }else{
            count=1;
        }
    }
    s->nModes=mode;
    s->mode=new int[mode];
    count=1; 
    max=1;
    int j=0;
    for(int i=1;i<size;i++){
        if(a[i-1]==a[i]){
            count++;
            if(count==freq){
                s->mode[j]=a[i];
                j++;
            }
        }else{
            count=1;
        }
    }
    return s;
}

void printStat(statsResult *a){
    cout << "Average is: " << a->avg << endl;
    cout << "Median is: " << a->median << endl;
    cout << "Number of modes: " << a->nModes << endl;
    cout << "Max Frequency: " << a->maxFreq << endl;
    cout << "Modes in the array is/are: ";
    for(int i=0;i<a->nModes;i++)
        cout << a->mode[i] << " ";
    cout << endl;
}