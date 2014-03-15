/* Bradd Carey
 * 02 Mar 2014
 * 
 * 
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

//Program Function Prototypes
float celsius(float);
void randArr(int,int*);       //Generate a random array
void prntArr(int, int, int*); //Print that array
int getHigh(int,int*);        //Returns the highest element in the array
int getLow(int,int*);         //Returns the lowest element in the array
int getTotal(int,int*);       //Returns the sum of elements in the array
float mean(int*,int);         //Returns the mean
void strSort(string[],int);   //Sorts string arrays
void prntArr(int, string*);   //Prints string array
void prntVec(vector<string>);

//Sub Function Prototypes
int isNum(string);  //Returns 0 if invalid and program number if valid

int main(int argc, char** argv) {
    srand(time(0));
    menu();
    cout<<"\nThank you for using Assignment 5!\n\nGOODBYE!!";    
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
            <<"\n[1]  Monthly Sales Tax    - Gaddis 3.12"
            <<"\n[2]  Property Tax         - Gaddis 3.13" 
            <<"\n[3]  Software Sales       - Gaddis 4.10"            
            <<"\n[4]  Population           - Gaddis 5.11"            
            <<"\n[5]  Celsius Temp Table   - Gaddis 6.7"           
            <<"\n[6]  Number Analysis      - Gaddis 7.6"           
            <<"\n[7]  Binary String Search - Gaddis 8.7";
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
    cout<<"\n**  Monthly Sales Tax **************************";
    cout<<"\n************************************************"<<endl;
    cout<<"This program calculates various taxes from sales and prints a report\n\n";
    string month;
    float cash;
    
    do{
        //Get Input
        cout<<"Please input the following:  \n";
        cout<<"Month:  ";
        getline(cin,month);
        cout<<"Total Cash from Register:  ";
        cin>>cash;
        cin.ignore();
        
        //Display Report
        cout<<"Month:  "<<month<<endl
            <<fixed<<setprecision(2)
            <<"--------------------------------"<<endl
            <<"Total Collected:       $"<<cash<<endl
            <<"Sales:                 $"<<cash/1.06<<endl
            <<"County Sales Tax (2%): $"<<cash*.02<<endl
            <<"State Sales Tax (4%):  $"<<cash*.04<<endl
            <<"Total Sales Tax:       $"<<cash-(cash/1.06)<<endl;
        
    }while(repeat(1)); 
}
void program2(){
    cout<<"\n************************************************"; 
    cout<<"\n**  Property Tax   *****************************";
    cout<<"\n************************************************";
    cout<<"\nThis program calculate property tax.\n";
    
    float cash;
    do{
        //Get Input      
        cout<<"Enter Property Worth:  ";
        cin>>cash;
        cin.ignore();
        
        //Display Report
        cout<<"Property Report:  "
            <<fixed<<setprecision(2)
            <<"--------------------------------"<<endl
            <<"Total Worth:       $"<<cash<<endl
            <<"Assessment Value:  $"<<cash*0.6<<endl
            <<"Property Tax:      $"<<cash*0.6/100.0*0.64<<endl;
    }while(repeat(1)); 
}
void program3(){
    cout<<"\n************************************************"; 
    cout<<"\n**  Software Sales   ***************************";
    cout<<"\n************************************************";
    cout<<"\nThis program calculates discounts on package sales.\n";
    
    int sales;
    
    do{
        do{
            cout<<"\nEnter the number of units sold:  ";
            cin>>sales;
        }while(sales<=0);
        cout<<fixed<<setprecision(2);
        if(sales<10)
            cout<<"Total Price at (0%) discount:  $%"<<static_cast<float>(sales)*99.0;
        else if(sales<=19)
            cout<<"Total Price at (20%) discount:  $"<<static_cast<float>(sales)*99.0*0.2;
        else if(sales<=49)
            cout<<"Total Price at (30%) discount:  $"<<static_cast<float>(sales)*99.0*0.3;
        else if(sales<=99)
            cout<<"Total Price at (40%) discount:  $"<<static_cast<float>(sales)*99.0*0.4;
        else
            cout<<"Total Price at (50%) discount:  $"<<static_cast<float>(sales)*99.0*0.5;
    }while(repeat(1)); 
}
void program4(){
    cout<<"\n************************************************"; 
    cout<<"\n**  Population   *******************************";
    cout<<"\n************************************************";
    cout<<"\nThis program will predict population increases based on a few parameters.\n";
    
    int pop;
    float percent;
    int days;
    
    do{
        //Get Input
        cout<<"\nPlease input the following:  \n";
        do{
            cout<<"Starting Population:  ";
            cin>>pop;
            cin.ignore();
        }while(pop<2);
        do{
            cout<<"Percent growth per day:  ";
            cin>>percent;
            cin.ignore();
        }while(percent<0);
        do{
            cout<<"Number of days:  ";
            cin>>days;
            cin.ignore();
        }while(days<1);
        
        //Output
        cout<<"Estimated population by day:"<<endl
            <<"---------------------------------"<<endl;
        for(int i=0;i<=days;i++){
            float temp = 0;
            cout<<"Day "<<i<<":  "<<pop<<endl;
            temp = static_cast<float>(pop)*(percent/100.0);
            pop = static_cast<int>(temp);
        }
    }while(repeat(1)); 
}
void program5(){
    cout<<"\n************************************************"; 
    cout<<"\n**  Celsius Temperature Table   ****************";
    cout<<"\n************************************************";
    cout<<"\nThis program converts Celsius to Fahrenheit.\n";
    
    float f;
    cout<<"\nExample Conversion Table:"<<endl
        <<"|------------------------------|\n"
        <<"|  Fahrenheit  |  Celsius      |\n"
        <<"|--------------|---------------|\n";
    for(int i=0;i<=20;i++){
        cout<<"|  "<<left<<setw(10)<<i<<"  |  "<<setw(11)<<celsius(static_cast<float>(i))<<"  |\n";
        }
    cout<<"|------------------------------|\n";
    
    do{
        cout<<endl<<"Enter a Fahrenheit temp to convert:  ";
        cin>>f;
        cin.ignore();
        cout<<"Temperature in Celsius:  "<<celsius(f)<<endl;
    }while(repeat(1)); 
}
void program6(){
    cout<<"\n************************************************"; 
    cout<<"\n**  Number Analysis Program   ******************";
    cout<<"\n************************************************";
    cout<<"\nThis program generates a random array, and displays information about it.\n";
    
    const int SIZE=10;
    int* a = new int[SIZE];
    
    do{
        //Generate Random Array of (0-9)
        randArr(SIZE,a);
        //Print the array
        prntArr(SIZE,5,a);
        cout<<endl;
        //Find highest
        cout<<"Largest:  "<<getHigh(SIZE,a)<<endl;
        //Find highest
        cout<<"Smallest:  "<<getLow(SIZE,a)<<endl;
        //Find highest
        cout<<"Total:  "<<getTotal(SIZE,a)<<endl;
        //Find highest
        cout<<"Average:  "<<mean(a,SIZE)<<endl;
        
    }while(repeat(1));
    //Memory Clean
    delete a;
}
void program7(){
    cout<<"\n************************************************"; 
    cout<<"\n**  Binary String Search   *********************";
    cout<<"\n************************************************";
    cout<<"\nThis program will predict your team captain choice in a number of guesses.\n";
    
    const int NUM_NAMES = 20;
    string names[NUM_NAMES] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
                               "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
                               "Taylor, Terri", "Johnson, Jill",
                               "Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
                               "James, Jean", "Weaver, Jim", "Pore, Bob",
                               "Rutherford, Greg", "Javens, Renee",
                               "Harrison, Rose", "Setzer, Cathy",
                               "Pike, Gordon", "Holland, Beth" };
    
    do{
        //Set up
        vector<string> vnames(names, names + 20);
        cout<<endl<<"Please choose your team captain from the list below:  "<<endl;
        prntVec(vnames);
        sort(vnames.begin(),vnames.end());
        
        cout<<endl<<"Once you've chosen a team captain press enter to continue..."<<endl;
        repeat(2);
        
        //Explanation
        cout<<endl<<"I will guess which person you've chosen from the list, then you"
            <<endl<<"tell me if their name is alphabetically higher or lower than "
            <<endl<<"your chosen captain.\n";
        
        //Start Process
        int c=0;
        int place;
        for(int i=0;i<6;i++){
            //Guess
            place=vnames.size()/2;
            cout<<endl<<"Is your captain \""<<vnames[place]<<"\"?  "<<endl;
            //Get input
            do{
                cout<<"Enter [0] for yes, [1] for lower, [2] for higher.  ";
                cin>>c;
                cin.ignore();
            }while(c!=0&&c!=1&&c!=2);
            if(c==1)
                vnames.erase(vnames.begin()+place,vnames.end());
            else if(c==2)
                vnames.erase(vnames.begin(),vnames.begin()+place);
            else if(!c){
                cout<<endl<<"Hooray I Guessed Right!";
                i=6;
            }
            cout<<endl;
        }
        
    }while(repeat(1)); 
}

//Program Function Prototypes
float celsius(float f){
    return (f-32.0)*5/9;
}
void randArr(int s,int* a){
    for(int i=0;i<s;i++){
        a[i]=rand()%10;
    }
}
void prntArr(int s, int l, int* a){
    for(int i=0;i<s;i++){
        cout<<a[i]<<" ";
        if(!((i+1)%l)){
            cout<<endl;
        }
    }
}
void prntArr(int s, string* a){
    for(int i=0;i<s;i++)
        cout<<a[i]<<endl;
}
float mean(int* a,int s){
    float temp=0;
    for(int i=0;i<s;i++){
        temp += a[i];
    }
    return temp/s;
}
int getHigh(int s,int* a){
    int foo=0;
    for(int i=0;i<s;i++)
        if(foo<a[i])
            foo=a[i];
    return foo;
}
int getLow(int s,int *a){
    int foo=10;
    for(int i=0;i<s;i++)
        if(foo>a[i])
            foo=a[i];
    return foo;
}
int getTotal(int s,int *a){
    int foo=0;
    for(int i=0;i<s;i++)
        foo+=a[i];
    return foo;
}
void prntVec(vector<string> a){
    for(int i=0; i<a.size(); i++) {
        cout<<left<<setw(18)<<a[i];
        if(!((i+1)%4))
            cout<<endl;
    }
}

//Upkeep Prototypes
int isNum(string a){
    if(a.length()>1)
        return 0;
    for(int i=0;i<a.length();i++){
        if((a[i]-'0'<1)||(a[i]-'0'>7))
            return 0;
    }
    return a[0]-'0';
}