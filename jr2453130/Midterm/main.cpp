/* 
 * File:   main.cpp
 * Author: Joseph Reimbold
 *
 * Created on April 23, 2014, 9:21 AM
 */

//Library includes Here!!!
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

//Global Constants Here!!!

//Structures
struct BankAcc
{
    string acc; //I've tried everything...
    int iBal;
    int chckTot;
    int depTot;    
};

struct Payrate
{
    string name;
    float hours;
    float pay;
    float gross;
};

struct statsResult
{
    float avg;
    float median;
    int *mode;   //array containing the modes
    int nModes;  //number of modes in the array
    int maxFreq; //max frequency of modes
};

//Function Prototypes Here!!!
void Menu();
int gtChoice();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();

//Function Prototypes for Problem 3
int * fillArray(int);
void sort(int *,int);
statsResult * avgMedMode(int *,int);
void printStat(statsResult *);

//Function Prototypes for Problem 4
void encrypt(int [],int,string);
void decrypt(int [],int,string);

//Begin Execution Here!!!
int main(int argv,char *argc[]){
    int choice;
    do{
        Menu();
        choice=gtChoice();
        switch(choice){
        case 1:    problem1();break;
        case 2:    problem2();break;
        case 3:    problem3();break;
        case 4:    problem4();break;
        case 5:    problem5();break;
        case 6:    problem6();break;
        default:   def(choice);}
    }while(choice>=1&&choice<=6);
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

int gtChoice(){
    int inN;
    cin>>inN;
    return inN;
}

void problem1(){
    cout<<"In problem # 1"<<endl<<endl;
    
    //Declare Variables
    BankAcc user;
    string accnt; //I can't figure out any other way than to use strings
                  //and after ridiculous searching online can't find a way. :(
    int chk, checks, dep, deps, fBal;
    user.chckTot=0;
    user.depTot=0;
    
    //Get user account number
    do{
        cout<<"Enter your 5 digit bank account number: ";
        cin>>user.acc;
        if(user.acc.length()!=5)cout<<"This is not a valid account number."<<endl;
    }while(user.acc.length()!=5);
    
    
    //Get user starting balance
    cout<<"Enter your current balance: $";
    cin>>user.iBal;
    
    //Get user's checks and total
    cout<<"How many checks?: ";
    cin>>checks;
    for(int i=0;i<checks;i++){
        //if(checks==0)break;
        cout<<"Enter check "<<i+1<<" amount: $";
        cin>>chk;
        user.chckTot+=chk;
    }
    
    //Get user's deposits and total
    cout<<"How many deposits?: ";
    cin>>deps;
    for(int j=0;j<deps;j++){
        cout<<"Enter deposit "<<j+1<<" amount: $";
        cin>>dep;
        user.depTot+=dep;
    }
    
    //Calculate end balance and if fee is applied
    fBal=(user.iBal-user.chckTot)+user.depTot;
    if(fBal<0){
        fBal-=12;
        cout<<"You were negative! Enjoy a $12 fee!"<<endl;
    }
    cout<<"Your final balance is $"<<fBal<<endl<<endl;
}

void problem2(){
    cout<<"In problem # 2"<<endl<<endl;
    
    //Declare Variables
    int numEmps;
    
    //Get number of employees
    cout<<"How many employees are there? ";
    cin.ignore();
    cin>>numEmps;
    Payrate emps[numEmps];
    
    for(int i=0;i<numEmps;i++){
        //get name of employee
        cin.ignore();
        cout<<"What is the employee's name?: ";
        getline(cin,emps[i].name);
        
        //get hours worked for employee
        cout<<"How many hours worked?: ";
        do{
            cin>>emps[i].hours;
        }while(emps[i].hours<0);
        
        //get pay rate for employee
        cout<<"Pay rate of employee?: ";
        do{
            cin>>emps[i].pay;
        }while(emps[i].pay<0);
        
        //calculate pay for employee
        if(emps[i].hours>40){
            emps[i].gross=((emps[i].hours-40)*emps[i].pay*3)+(emps[i].pay*2*20)+(emps[i].pay*20);
        }
        else if(emps[i].hours>20){
            emps[i].gross=((emps[i].hours-20)*emps[i].pay*2)+(emps[i].pay*20);
        }
        else{
            emps[i].gross=(emps[i].hours*emps[i].pay);
        }
    }
    
    for(int j=0;j<numEmps;j++){
        //output information to user
        cout<<"Pay Info"<<endl;
        cout<<"Name:         "<<emps[j].name<<endl;
        cout<<"Hours worked: "<<emps[j].hours<<endl;
        cout<<"Pay rate:     "<<emps[j].pay<<endl;
        cout<<"Gross Pay:    $"<<emps[j].gross<<endl;
    }
    cout<<endl;
}

void problem3(){
    cout<<"In problem # 3"<<endl<<endl;
    
    /*
    3) Write a function using the following structure and prototype.

    struct statsResult
    {
        float avg;
        float median;
        int *mode;   //array containing the modes
        int nModes;  //number of modes in the array
        int maxFreq; //max frequency of modes
    };

    statsResult *avgMedMode(int *,int);
    
    The function takes in an integer array and the size of the array.
    Then returns a pointer to a structure containing the average, median
    and mode.  You will then write a printStat() function that will print
    the results contained in the stats structure.  I will input a small 
    array to test this out so ask for how many inputs to fill the array, 
    then the values to place into the array.  Make sure you delete the 
    dynamic array creation for the mode when you exit the problem.
    */
    
    //declare variables
    int nums;
    
    //get size of array
    cout<<"How many integers in the array?: ";
    cin>>nums;
    
    //fill array
    int *array=fillArray(nums);
    
    //sort array for median/mode
    sort(array,nums);
    
    //calculate
    statsResult *stats=avgMedMode(array,nums);
    
    //print results
    printStat(stats);
    
    //seek and destroy!
    delete []array;
    delete []stats;
    
    cout<<endl<<endl;
    //Exit stage right
}

int * fillArray(int n){
    //Declare allocated memory
    int *a=new int[n];
    
    //fill array
    for(int i=0;i<n;i++){
        cout<<"Enter element "<<i+1<<": ";
        cin>>a[i];
    }
    cout<<endl;
    return a;
}

void sort(int *a,int n){
    //sort the copied array
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    cout<<"Sorted Array: ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

statsResult * avgMedMode(int *a,int n){
    //declare variables
    int sum=0;
    statsResult *s = new statsResult;
    
    //get avg
    float nums=static_cast<float>(n);
    for (int i=0;i<n;i++){
        sum+=a[i];
    }
    s->avg=(sum/nums);
    
    //get median
    if(n%2==0)s->median=(a[(n/2)-1]+a[n/2])/2.0;
    else
        s->median=a[(n/2)];
    
    //get max freq
    int count=1, max=1;
    
    //loop and compare
    for(int i=1;i<n;i++){
        if(a[i-1]==a[i]){
            count++;
            if(count>max)max=count;
        }else{
            count=1;
        }
    }
    s->maxFreq=max;
    
    //get num modes
    int modes=0;
    for(int i=1;i<n;i++){
        if(a[i-1]==a[i]){
            count++;
            if(count==max){
                modes++;
                count=1;                
            }
        }
    }
    s->nModes=modes;
    
    //get modes
    int *m=new int[s->nModes];
    int mcount=0;
    for(int i=1;i<n;i++){
        if(a[i-1]==a[i]){
            count++;
            if(count==max){
                count=1;
                m[mcount]=a[i];
                mcount++;
            }
        }
    }
    s->mode=m;

    return s;
}

void printStat(statsResult *s){
    cout<<endl<<"Avg: "<<s->avg<<endl<<"Median: "<<s->median<<endl
        <<"Num Modes: "<<s->nModes<<endl<<"Max Freq: "<<s->maxFreq<<endl;
    cout<<"Mode(s): ";
    for(int i=0;i<s->nModes;i++){
        cout<<s->mode[i]<<" ";
    }
    cout<<endl<<endl;
}

void destroy(int *a){
    delete []a;
}


void problem4(){
    cout<<"In problem # 4"<<endl<<endl;
    
    int SIZE=4, len=4;
    string code; //I can't figure out any other way than to use strings
                 //and after ridiculous searching online can't find a way. :(
    int digits[SIZE];
    char crypt;
    
    do{
        cout<<"Do you want to encrypt a code or decrypt a code?"<<endl;
        cout<<"Enter E(e) for encrypt or D(d) to decrypt:";
        cin>>crypt;
        if(crypt!='E'&&crypt!='e'&&crypt!='D'&&crypt!='d')
            cout<<"Not valid selection!"<<endl;
    }while(crypt!='E'&&crypt!='e'&&crypt!='D'&&crypt!='d');
    
    //get number from user
    do{
        cout<<"Enter 4-digit code ONLY using 0-7"<<endl;
        cin>>code;
        len=code.length();
        if(len!=4)cout<<"This is not a valid 4-digit code!"<<endl;
    }while(len!=4);
    
    //pull int digits from string
    for (int i=0;i<SIZE;i++){
        digits[i]=code[i]-48;
    }
    
    //decide whether to run encryption or decryption
    if(crypt=='E'||crypt=='e')encrypt(digits,SIZE,code);
    else decrypt(digits,SIZE,code);
    
}

void encrypt(int d[],int n,string c){
    //encrypt data
    for(int i=0;i<n;i++){
        d[i]+=3;
        d[i]%=8;
    }
    
    //swap 1 and 2, then 3 and 4
    int temp;
    temp=d[0];
    d[0]=d[1];
    d[1]=temp;
    temp=d[2];
    d[2]=d[3];
    d[3]=temp;
    
    //output encrypted code
    cout<<"\nEncrypted Code:"<<endl;
    for(int j=0;j<n;j++){
        cout<<d[j];
    }
    cout<<endl<<endl;
}

void decrypt(int d[],int n,string c){
    //decrypt data
    for(int i=0;i<n;i++){
        if(d[i]>=3&&d[i]<=7)d[i]-=3;
        if(d[i]>=0&&d[i]<=2)d[i]+=5;
    }
    
    //swap 1 and 2, then 3 and 4
    int temp;
    temp=d[0];
    d[0]=d[1];
    d[1]=temp;
    temp=d[2];
    d[2]=d[3];
    d[3]=temp;
    
    //output encrypted code
    cout<<"\nDecrypted Code:"<<endl;
    for(int j=0;j<n;j++){
        cout<<d[j];
    }
    cout<<endl<<endl;
}

void problem5(){
    cout<<"In problem # 5"<<endl<<endl;
    
    cout<<"In problem # 5"<<endl<<endl;
    
    
    /*
    //calculating the ranges
    double factorial=1;
    int n;
    cout<<"Give n:";
    cin>>n;
    
    for (int i=1;i<=n;i++){
        factorial=factorial*i;
        cout<<i<<": "<<factorial<<endl;
    }
     * 
    cout<<"Factorial of "<<n<<" = "<<factorial<<endl<<endl;
    */
    
    cout<<"a) The highest factorial for a byte variable is 5!"<<endl;
    cout<<"b)"<<endl;
    cout<<"The highest factorial for a short variable is 7!"<<endl;
    cout<<"The highest factorial for a int variable is 12!"<<endl;
    cout<<"The highest factorial for a long variable is 20!"<<endl;
    cout<<"The highest factorial for a float variable is 34!"<<endl;
    cout<<"The highest factorial for a double variable is 170!"<<endl<<endl;
}

void problem6(){
    cout<<"In problem # 6"<<endl<<endl;
    
    cout<<"a)"<<endl;
    cout<<"Convert 2.125 to Binary, Octal and Hex"<<endl;
    cout<<"Binary: 10.001"<<endl;
    cout<<"Octal:  2.1"<<endl;
    cout<<"Hex:    2.2"<<endl;
    
    cout<<"Convert 0.06640625 to Binary, Octal and Hex"<<endl;
    cout<<"Binary: 0.00010001"<<endl;
    cout<<"Octal:  0.042"<<endl;
    cout<<"Hex:    0.11"<<endl<<endl;
    cout<<"Convert into float representation"<<endl;
    cout<<"-2.125 -> F0000001"<<endl;
    cout<<"0.06640625 -> 880000FD"<<endl<<endl;
    
    cout<<"b)"<<endl;
    cout<<"Convert from float representation to decimal"<<endl;
    cout<<"46666601 ->  0.55"<<endl
        <<"46666602 ->  1.10"<<endl
        <<"B9999AFE -> -1.10"<<endl<<endl;
    
    
    
}

void def(int choice){
    cout<<"You typed "<<choice<<" to exit the program"<<endl;
}