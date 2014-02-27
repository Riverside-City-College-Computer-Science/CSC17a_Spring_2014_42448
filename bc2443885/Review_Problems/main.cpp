/* Bradd Carey
 * 26 Feb 2014
 * 
 * 
 */

//Libraries
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

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

//Sub Function Prototypes
int isNum(string);  //Returns 0 if invalid and program number if valid



int main(int argc, char** argv) {
    
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
    if(c){
        cout<<"\nEnter [0] to exit to Main Menu, else repeat.  ";
        getline(cin,r);
        if(r[0]!='0')
            return true;
        else
            return false;
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
    cout<<"\n\n";
    do{
        
    }while(repeat(1)); 
}
void program4(){
    cout<<"\n************************************************"; 
    cout<<"\n**  Population   *******************************";
    cout<<"\n************************************************";
    cout<<"\n\n";
    do{
        
    }while(repeat(1)); 
}
void program5(){
    cout<<"\n************************************************"; 
    cout<<"\n**  Celsius Temperature Table   ****************";
    cout<<"\n************************************************";
    cout<<"\n\n";
    do{
        
    }while(repeat(1)); 
}
void program6(){
    cout<<"\n************************************************"; 
    cout<<"\n**  Number Analysis Program   ******************";
    cout<<"\n************************************************";
    cout<<"\n\n";
    do{
        
    }while(repeat(1)); 
}
void program7(){
    cout<<"\n************************************************"; 
    cout<<"\n**  Binary String Search   *********************";
    cout<<"\n************************************************";
    cout<<"\n\n";
    do{
        
    }while(repeat(1)); 
}

//Program Function Prototypes

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