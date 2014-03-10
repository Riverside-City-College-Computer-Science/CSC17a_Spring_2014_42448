/* Bradd Carey
 * 09 Mar 2014
 * 
 * Assignment 1
 */

//Libraries
#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

//Global Variables

//Main Function Prototypes
void menu();
bool repeat(int);
void program1();
void program2();
void program3();
void program4();
void program5();
void program6();
void program7();
void program8();
void program9();

//Program Function Prototypes
int isNum(string);
void randArray(int*, int, int, int);        
void printArray(int*, int, int);
void printArray(int*, string*, int);
void getScores(int*, int);
int* copyArray(int*, int);
int* sortArray(int*, int);
void getNScores(int*, string*, int);
void sortArray(int*, string*, int);
float getMedian(int*, int);
int* reverseArray(int*,int);

//Not my Functions
int doSomething(int &x, int &y);

//Main
int main(int argc, char** argv) {
    srand(time(0));
    menu();
    cout<<"\nThank you for using Assignment 1!\n\nGOODBYE!!";    
    return 0;
}
  
//Main Function Prototypes
void menu(){
    string c;
    //Begin Menu
    do{
        cout<<"**********************************************************"
            <<"\nWelcome to Bradd's Assignment 1 - CSC17A - 42448"
            <<"\n----------------------------------------------------------"
            <<"\n[1]  Array Allocator      - Gaddis 9.1"
            <<"\n[2]  Test Scores #1       - Gaddis 9.2" 
            <<"\n[3]  Drop Lowest Score    - Gaddis 9.3"            
            <<"\n[4]  Test Scores #2       - Gaddis 9.4"            
            <<"\n[5]  Median Function      - Gaddis 9.9"           
            <<"\n[6]  Reverse Array        - Gaddis 9.10"           
            <<"\n[7]  Array Expander       - Gaddis 9.11"
            <<"\n[8]  Element Shifter      - Gaddis 9.12"
            <<"\n[9]  Pointer Rewrite      - Gaddis 9.5";
        do{
            cout<<"\n----------------------------------------------------------"
                <<"\nPlease Enter the number of the program you'd like to use:  ";
            getline(cin,c);
        }while(!isNum(c));
        
        switch(isNum(c)){
            case 1:  program1()  ; break;
            case 2:  program2()  ; break;    
            case 3:  program3()  ; break;
            case 4:  program4()  ; break;
            case 5:  program5()  ; break;
            case 6:  program6()  ; break;
            case 7:  program7()  ; break;
            case 8:  program8()  ; break;
            case 9:  program9()  ; break;
        
        }
        
    }while(repeat(0));
}
bool repeat(int c){
    string r;
    if(c==1){
        cout<<"\nEnter [0] to exit to Main Menu, else repeat.  ";
        getline(cin,r);
        if(r[0]!='0')
            return true;
        else
            return false;
    }
    else if(c==2){
        getline(cin,r);
    }
    else{
        cout<<"\nEnter [0] to exit Program, else repeat.  ";
        getline(cin,r);
        if(r[0]!='0')
            return true;
        else
            return false;
    }
    
    
}
void program1(){
    cout<<"\n************************************************"; 
    cout<<"\n**  Array Allocator ****************************";
    cout<<"\n************************************************";
    cout<<"\nThis program creates a random array of 'n' integers and returns it.\n";
    int n;
    do{
        do{
            cout<<endl<<"Enter the size of your array:  ";
            cin>>n;
            cin.ignore();
        }while(n<=1);
        int* a = new int[n];
        randArray(a,n,1,10);
        cout<<"Here is your array:  \n";
        printArray(a,n,10);
        delete [] a;
    }while(repeat(1)); 
}
void program2(){
    cout<<"\n************************************************"; 
    cout<<"\n**  Test Scores #1   ***************************";
    cout<<"\n************************************************";
    cout<<"\nThis program sorts integer based test scores.\n";
    
    int n;
    do{
        do{
            cout<<endl<<"Enter the number of scores:  ";
            cin>>n;
            cin.ignore();
        }while(n<=1);
        int* a = new int[n];
        getScores(a,n);
        a = sortArray(a,n);
        cout<<endl<<"The sorted scores:  "<<endl;
        printArray(a,n,10);
        delete [] a;
    }while(repeat(1)); 
}
void program3(){
    cout<<"\n************************************************"; 
    cout<<"\n**  Drop Lowest Score   ************************";
    cout<<"\n************************************************";
    cout<<"\nThis program allows input of integer test scores and drops the lowest.\n";
    
    int n;
    do{
        do{
            cout<<endl<<"Enter the total number of scores:  ";
            cin>>n;
            cin.ignore();
        }while(n<=1);
        int* a = new int[n];
        getScores(a,n);
        a = sortArray(a,n);
        int* b = new int[n-1];
        for(int i=0;i<n-1;i++)
            b[i]=a[i+1];
        cout<<endl<<"The new scores with the lowest drop:  "<<endl;
        printArray(b,n-1,10);
        delete [] a;
        delete [] b;
    }while(repeat(1)); 
}
void program4(){
    cout<<"\n************************************************"; 
    cout<<"\n**  Test Scores #2   ***************************";
    cout<<"\n************************************************";
    cout<<"\nThis program allows sorting of scores while showing the names associated.\n";
    
    int n;
    do{
        do{
            cout<<endl<<"Enter the total number of scores:  ";
            cin>>n;
            cin.ignore();
        }while(n<=1);
        int* a = new int[n];
        string* b = new string[n];
        getNScores(a,b,n);
        sortArray(a,b,n);
        cout<<endl<<"The sorted scores:  "<<endl;
        printArray(a,b,n);
        delete [] a;
        delete [] b;
    }while(repeat(1)); 
}
void program5(){
    cout<<"\n************************************************"; 
    cout<<"\n**  Median Function   **************************";
    cout<<"\n************************************************";
    cout<<"\nThis program return the median of a random array\n";
    int n;
    do{
        do{
            cout<<endl<<"Enter the size of your array:  ";
            cin>>n;
            cin.ignore();
        }while(n<=1);
        int* a = new int[n];
        randArray(a,n,10,99);
        cout<<endl<<"Random Array:  "<<endl;
        printArray(a,n,10);
        cout<<endl<<"Sorted Array:  "<<endl;
        a = sortArray(a,n);
        printArray(a,n,10);
        float median = getMedian(a,n);
        cout<<endl<<"Median = "<<median<<endl;
        delete [] a;
    }while(repeat(1)); 
}
void program6(){
    cout<<"\n************************************************"; 
    cout<<"\n**  Reverse Array   ****************************";
    cout<<"\n************************************************";
    cout<<"\nThis function creates a random array and then reverses it.\n";
    int n=25;
    do{
        int* a = new int[n];
        randArray(a,n,10,99);
        cout<<endl<<"Random Array:  "<<endl;
        printArray(a,n,5);
        for(int i=0, j=n-1;i<j;i++){
            a[i]^=a[j];
            a[j]^=a[i];
            a[i]^=a[j];
            j--;
        }
        cout<<endl<<"Reversed Array:  "<<endl;
        printArray(a,n,5);
        delete [] a;
    }while(repeat(1)); 
}
void program7(){
    cout<<"\n************************************************"; 
    cout<<"\n**  Array Expander   ***************************";
    cout<<"\n************************************************";
    cout<<"\nThis program takes an array and expands it for more input.\n";
    int n=10;
    do{
        int* a = new int[n];
        randArray(a,n,0,9);
        cout<<endl<<"Random Array:  "<<endl;
        printArray(a,n,10);
        int* b = new int[2*n-1];
        for(int i=0;i<n;i++)
            b[i]=a[i];
        cout<<endl<<"Expanded Array:  "<<endl;
        printArray(b,2*n,10);
        delete [] a;
        delete [] b;
    }while(repeat(1)); 
}
void program8(){
    cout<<"\n************************************************"; 
    cout<<"\n**  Element Shifter   **************************";
    cout<<"\n************************************************";
    cout<<"\n\n";
    int n=10;
    do{
        int* a = new int[n];
        randArray(a,n,10,99);
        cout<<endl<<"Random Array:  "<<endl;
        printArray(a,n,10);
        int* b = new int[n+1];
        for(int i=0;i<n;i++)
            b[i+1]=a[i];
        cout<<endl<<"Shifted Array:  "<<endl;
        printArray(b,n+1,n+1);
        delete [] a;
        delete [] b;
    }while(repeat(1)); 
}
void program9(){
    cout<<"\n************************************************"; 
    cout<<"\n**  Pointer Rewrite   **************************";
    cout<<"\n************************************************";
    cout<<"\nThis program rewrites a function with reference variables to pointers\n";
    int x = 10, y =5;
    int& a = x;
    int& b = y;
    do{
        cout<<"x = "<<x<<", y = "<<y<<endl;
        doSomething(a,b);
        cout<<"After doing stuff:  "<<endl;
        cout<<"x = "<<x<<", y = "<<y<<endl;
    }while(repeat(1)); 
}

//Program Function Prototypes
void randArray(int*a, int size, int low, int high){
    for(int i=0;i<size;i++)
        a[i]=rand()%(high+1-low)+low;
}        
void printArray(int *a, int size, int length){
    for(int i=0;i<size;i++){
        cout<<a[i]<<" ";
        if((i+1)%length==0)
            cout<<endl;
    }
}
void printArray(int *a, string* b,int size){
    for(int i=0;i<size;i++){
        cout<<setw(8)<<b[i]<<" "<<a[i]<<endl;
    }
}
void getScores(int *a, int size){
    int temp;
    
    for(int i=0;i<size;i++){
        do{
            cout<<"Enter Score "<<i+1<<":  ";
            cin>>temp;
            cin.ignore();
        }while(temp<0);
        a[i]=temp;
    }
}
void getNScores(int *a, string *b, int size){
    int temp;
    string name;
    for(int i=0;i<size;i++){
        cout<<"Enter Name "<<i+1<<":  ";
        getline(cin, name);
        b[i]=name;
        do{
            cout<<"Enter Score "<<i+1<<":  ";
            cin>>temp;
            cin.ignore();
        }while(temp<0);
        a[i]=temp;
    }
}
int* copyArray(int* a, int size){
    int* b = new int[size];
    for(int i=0;i<size;i++)
        b[i]=a[i];
    return b;
}
int* sortArray(int* a, int size){
    int temp;
    int *b = new int[size]; 
    b = copyArray(a,size);
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(b[i]>b[j]){
               temp=b[i];
               b[i]=b[j];
               b[j]=temp;
                /*b[i]^=b[j];
                b[j]^=b[i];
                b[i]^=b[j];*/                
            }
        }
    }
    return b;
}
void sortArray(int* a, string *b, int size){
    string temp;
    for(int i=0;i<size;i++){
        for(int j=i;j<size-1;j++){
            if(a[i]>a[j]){
                a[i]^=a[j];
                a[j]^=a[i];
                a[i]^=a[j]; 
                temp=b[i];
                b[i]=b[j];
                b[j]=temp;
            }
        }
    }
}
float getMedian(int* a, int size){
    //Odd
    if(size%2)
        return a[(size-1)/2];
    else
        return (((a[size/2])+(a[(size/2)-1]))/2.0);
}
int isNum(string a){
    if(a.length()>1)
        return 0;
    for(int i=0;i<a.length();i++){
        if((a[i]-'0'<1)||(a[i]-'0'>9))
            return 0;
    }
    return a[0]-'0';
}

//Not my functions
int doSomething(int &x, int &y){
    int temp = x;
    x = y * 10;
    y = temp * 10;
    return x + y;
}