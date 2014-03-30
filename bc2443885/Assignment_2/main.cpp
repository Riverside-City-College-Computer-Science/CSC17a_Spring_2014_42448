/* Bradd Carey
 * 29 Mar 2014
 * 
 * Assignment 2
 */

//Libraries
#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <sstream>

//Objects
#include "moviedata.h"
#include "corporate.h"
#include "weather.h"
#include "soccer.h"
#include "customer.h"

using namespace std;

//Global Constants
const int MONTH = 12;

//Enumerators
enum{ JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC, LAST };

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
void program10();
void program11();
void program12();
void program13();

//Program Function Prototypes
int isNum(string);
void addAcct(customer[],int);
void editAcct(customer[],int);
void prntAcct(customer[],int);
void allAcct(customer[],int);

//Main
int main(int argc, char** argv) {
    srand(time(0));
    menu();
    cout<<"\nThank you for using Assignment 2!\n\nGOODBYE!!";    
    return 0;
}
  
//Main Function Prototypes
void menu(){
    string c;
    //Begin Menu
    do{
        cout<<"**********************************************************"
            <<"\nWelcome to Bradd's Assignment 2 - CSC17A - 42448"
            <<"\n----------------------------------------------------------"
            <<"\n[1]   String Length        - Gaddis 10.1"
            <<"\n[2]   Backward String      - Gaddis 10.2" 
            <<"\n[3]   Word Counter         - Gaddis 10.3"            
            <<"\n[4]   Movie Data           - Gaddis 11.1"            
            <<"\n[5]   Movie Profit         - Gaddis 11.2"           
            <<"\n[6]   Corporate Sales Data - Gaddis 11.3"           
            <<"\n[7]   Weather Statistics   - Gaddis 11.4"
            <<"\n[8]   Weather Mod          - Gaddis 11.5"
            <<"\n[9]   Soccer Scores        - Gaddis 11.6"
            <<"\n[10]  Customer Accounts    - Gaddis 11.6"
            <<"\n[11]        - Gaddis 11.6"
            <<"\n[12]        - Gaddis 11.6"
            <<"\n[13]        - Gaddis 11.6";
        do{
            cout<<"\n----------------------------------------------------------"
                <<"\nPlease Enter the number of the program you'd like to use:  ";
            getline(cin,c);
        }while(!isNum(c));
        int choice = isNum(c);
        
        switch(choice){
            case 1: program1()  ; break;
            case 2: program2()  ; break;    
            case 3: program3()  ; break;
            case 4: program4()  ; break;
            case 5: program5()  ; break;
            case 6: program6()  ; break;
            case 7: program7()  ; break;
            case 8: program8()  ; break;
            case 9: program9()  ; break;
            case 10:program10() ; break;
            case 11:program11() ; break;
            case 12:program12() ; break;
            case 13:program13() ; break;
            
            

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
    cout<<"\n**  String Length ******************************";
    cout<<"\n************************************************";
    cout<<"\nDisplays the length of a string.\n";
    string s;
    do{
        cout<<"Please enter a string:  ";
        getline(cin,s);
        cout<<endl<<endl<<"Your string is "<<s.length()<<" characters long."<<endl;
    }while(repeat(1)); 
}
void program2(){
    cout<<"\n************************************************"; 
    cout<<"\n**  Backward String  ***************************";
    cout<<"\n************************************************";
    cout<<"\nTurns any string into demon speak.\n";
    string s;
    string r;
    int j;
    do{
        cout<<"Please enter a string:  ";
        getline(cin,s);
        r=s;
        j=s.length()-1;
        for(int i=0;i<s.length();i++){
            r[i]=s[j];
            j--;
        }
            
        cout<<"Your string backwards is: "<<r<<endl;
    }while(repeat(1)); 
}
void program3(){
    cout<<"\n************************************************"; 
    cout<<"\n**  Word Counter   *****************************";
    cout<<"\n************************************************";
    cout<<"\nCounts the number of words in a string\n";
    string s;
    string cpy;
    int words;
    bool edit=false;
    do{
        words = 0;
        cout<<"Please enter a string:  ";
        getline(cin,s);
        cpy = s;
        
        //Remove numbers and symbols
        for(int i=0;i<cpy.length();i++){
            if(!((cpy[i]==' ')||(cpy[i]>='A'&&cpy[i]<='Z')||(cpy[i]>='a'&&cpy[i]<='z'))){
                cpy.erase(cpy.begin()+i);
                i--;
                edit=true;
            }
        }
        
        //Count words
        if(!(cpy.length()==0))
            words++;
        for(int i=0;i<cpy.length();i++)
            if(cpy[i]==' ')
                words++;
        
        if(edit)
            cout<<"Terribly sorry I had to remove some odd characters"<<endl
                <<"Your edited string is:  "<<endl
                <<cpy;
        cout<<endl<<endl<<"Your string has "<<words<<" words in it!"<<endl;
    }while(repeat(1)); 
}
void program4(){
    cout<<"\n************************************************"; 
    cout<<"\n**  Movie Data   *******************************";
    cout<<"\n************************************************";
    cout<<"\nStores data about two of your favorite movies in structures\n";
    movieData mov1;
    movieData mov2;
    string temp;
    do{
        //Get data about 1st Movie
        cout<<"1st Movie "<<endl;
        cout<<"Title:  ";
        getline(cin,mov1.title);
        cout<<"Director:  ";
        getline(cin,mov1.director);
        do{
            cout<<"Release Year:  ";
            getline(cin,temp);
        }while(!isNum(temp));
        mov1.year = isNum(temp);
        do{
            cout<<"Runtime (min):  ";
            getline(cin,temp);
        }while(!isNum(temp));
        mov1.runtime = isNum(temp);
        cout<<endl;
        
        //Get data about 2nd Movie
        cout<<"2nd Movie "<<endl;
        cout<<"Title:  ";
        getline(cin,mov2.title);
        cout<<"Director:  ";
        getline(cin,mov2.director);
        do{
            cout<<"Release Year:  ";
            getline(cin,temp);
        }while(!isNum(temp));
        mov2.year = isNum(temp);
        do{
            cout<<"Runtime (min):  ";
            getline(cin,temp);
        }while(!isNum(temp));
        mov2.runtime = isNum(temp);
        cout<<endl;
        
        //Print relevant Data
        cout<<"Movie 1:  "<<mov1.details()<<endl<<endl;
        cout<<"Movie 2:  "<<mov2.details()<<endl<<endl;

    }while(repeat(1)); 
}
void program5(){
    cout<<"\n************************************************"; 
    cout<<"\n**  Movie Profit   *****************************";
    cout<<"\n************************************************";
    cout<<"\nStores data about two of your favorite movies in structures\n";
    movieData mov1;
    movieData mov2;
    string temp;
    do{
        //Get data about 1st Movie
        cout<<"1st Movie "<<endl;
        cout<<"Title:  ";
        getline(cin,mov1.title);
        cout<<"Director:  ";
        getline(cin,mov1.director);
        do{
            cout<<"Release Year:  ";
            getline(cin,temp);
        }while(!isNum(temp));
        mov1.year = isNum(temp);
        do{
            cout<<"Runtime (min):  ";
            getline(cin,temp);
        }while(!isNum(temp));
        mov1.runtime = isNum(temp);
        do{
            cout<<"Production Cost:  ";
            getline(cin,temp);
        }while(!isNum(temp));
        mov1.cost = isNum(temp);
        do{
            cout<<"Revenue:  ";
            getline(cin,temp);
        }while(!isNum(temp));
        mov1.revenue = isNum(temp);
        cout<<endl;
        
        //Get data about 2nd Movie
        cout<<"2nd Movie "<<endl;
        cout<<"Title:  ";
        getline(cin,mov2.title);
        cout<<"Director:  ";
        getline(cin,mov2.director);
        do{
            cout<<"Release Year:  ";
            getline(cin,temp);
        }while(!isNum(temp));
        mov2.year = isNum(temp);
        do{
            cout<<"Runtime (min):  ";
            getline(cin,temp);
        }while(!isNum(temp));
        mov2.runtime = isNum(temp);
        do{
            cout<<"Production Cost:  ";
            getline(cin,temp);
        }while(!isNum(temp));
        mov2.cost = isNum(temp);
        do{
            cout<<"Revenue:  ";
            getline(cin,temp);
        }while(!isNum(temp));
        mov2.revenue = isNum(temp);
        cout<<endl;
        
        //Print relevant Data
        cout<<"Movie 1:  "<<mov1.details()<<mov1.profit()<<endl<<endl;
        cout<<"Movie 2:  "<<mov2.details()<<mov2.profit()<<endl<<endl;
    }while(repeat(1)); 
}
void program6(){
    cout<<"\n************************************************"; 
    cout<<"\n**  Corporate Sales Data   **********************";
    cout<<"\n************************************************";
    cout<<"\nMaintains data relevant to corporate sales.\n";
    corporate east;
    east.name = "East";
    corporate west;
    west.name = "West";
    corporate north;
    north.name = "North";
    corporate south;
    south.name = "South";
    do{
        //Get Info
        east.getInfo();
        west.getInfo();
        north.getInfo();
        south.getInfo();
        
        //Display Info
        cout<<setw(10)<<left;
        cout<<"|       | East        | West        | North       | South       |"<<endl
            <<"| Q1    | $"<<setw(10)<<left<<east.q1<<" | $"<<setw(10)<<left<<west.q1
            <<" | $"<<setw(10)<<left<<north.q1<<" | $"<<setw(10)<<left<<south.q1<<" |"<<endl
            <<"| Q2    | $"<<setw(10)<<left<<east.q2<<" | $"<<setw(10)<<left<<west.q2
            <<" | $"<<setw(10)<<left<<north.q2<<" | $"<<setw(10)<<left<<south.q2<<" |"<<endl
            <<"| Q3    | $"<<setw(10)<<left<<east.q3<<" | $"<<setw(10)<<left<<west.q3
            <<" | $"<<setw(10)<<left<<north.q3<<" | $"<<setw(10)<<left<<south.q3<<" |"<<endl
            <<"| Q4    | $"<<setw(10)<<left<<east.q4<<" | $"<<setw(10)<<left<<west.q4
            <<" | $"<<setw(10)<<left<<north.q4<<" | $"<<setw(10)<<left<<south.q4<<" |"<<endl
            <<"| Total | $"<<setw(10)<<left<<east.t<<" | $"<<setw(10)<<left<<west.t
            <<" | $"<<setw(10)<<left<<north.t<<" | $"<<setw(10)<<left<<south.t<<" |"<<endl
            <<"| Avg   | $"<<setw(10)<<left<<east.av<<" | $"<<setw(10)<<left<<west.av
            <<" | $"<<setw(10)<<left<<north.av<<" | $"<<setw(10)<<left<<south.av<<" |"<<endl;
    }while(repeat(1)); 
}
void program7(){
    cout<<"\n************************************************"; 
    cout<<"\n**  Weather Statistics  ************************";
    cout<<"\n************************************************";
    cout<<"\nStore information relevant to weather by month\n";
    
    //Declare stuff
    weather w[MONTH];
    for(int i=0;i<MONTH;i++){
        switch(i){
            case 0: w[i].name="January"; break;
            case 1: w[i].name="February"; break;
            case 2: w[i].name="March"; break;
            case 3: w[i].name="April"; break;
            case 4: w[i].name="May"; break;
            case 5: w[i].name="June"; break;
            case 6: w[i].name="July"; break;
            case 7: w[i].name="August"; break;
            case 8: w[i].name="September"; break;
            case 9: w[i].name="October"; break;
            case 10: w[i].name="November"; break;
            case 11: w[i].name="December"; break;
        }
    }
    string highMon, lowMon;
    int hTemp, lTemp, tRain;
    float avgTemp, avgRain;
    
    do{
        //Reset
        hTemp=-101;
        lTemp=141;
        tRain=0;
        avgTemp=0;
        avgRain=0;
        
        //Get information across all months
        for(int i=0;i<MONTH;i++){
            w[i].getInfo();
            cout<<endl;
        }
        
        //Output Statistics
        cout<<endl<<endl<<"Yearly Statistics:  "<<endl;
        //Calculate and display total rainfall
        for(int i=0;i<MONTH;i++)
            tRain+=w[i].tRain;
        cout<<"Total Rainfall:  "<<tRain<<endl;
        
        //Calculate and display average rainfall
        avgRain = static_cast<float>(tRain)/12.0;
        cout<<"Average Rainfall:  "<<avgRain<<endl;
        
        //Calculate and display highest temp
        for(int i=0;i<MONTH;i++)
            if(w[i].hTemp>hTemp){
                hTemp=w[i].hTemp;
                highMon=w[i].name;
            }
        cout<<"Highest Temp:  "<<hTemp<<" ("<<highMon<<")"<<endl;
        
        //Calculate and display lowest temp
        for(int i=0;i<MONTH;i++)
            if(w[i].lTemp<lTemp){
                lTemp=w[i].lTemp;
                lowMon=w[i].name;
            }
        cout<<"Lowest Temp:  "<<lTemp<<" ("<<lowMon<<")"<<endl;
        
        //Calculate and display average temp
        for(int i=0;i<MONTH;i++)
            avgTemp+=static_cast<float>(w[i].aTemp);
        avgTemp/=12.0;
        cout<<"Average Temp:  "<<avgTemp<<endl;
        
    }while(repeat(1)); 
}
void program8(){
    cout<<"\n************************************************"; 
    cout<<"\n**  Weather Statistics Mod  ********************";
    cout<<"\n************************************************";
    cout<<"\nStore information relevant to weather by month with enumerators\n";
    
    //Declare stuff
    weather w[MONTH];
    for(int i=JAN;i!=LAST;i++){
        switch(i){
            case 0: w[i].name="January"; break;
            case 1: w[i].name="February"; break;
            case 2: w[i].name="March"; break;
            case 3: w[i].name="April"; break;
            case 4: w[i].name="May"; break;
            case 5: w[i].name="June"; break;
            case 6: w[i].name="July"; break;
            case 7: w[i].name="August"; break;
            case 8: w[i].name="September"; break;
            case 9: w[i].name="October"; break;
            case 10: w[i].name="November"; break;
            case 11: w[i].name="December"; break;
        }
    }
    string highMon, lowMon;
    int hTemp, lTemp, tRain;
    float avgTemp, avgRain;
    
    do{
        //Reset
        hTemp=-101;
        lTemp=141;
        tRain=0;
        avgTemp=0;
        avgRain=0;
        
        //Get information across all months
        for(int i=JAN;i!=LAST;i++){
            w[i].getInfo();
            cout<<endl;
        }
        
        //Output Statistics
        cout<<endl<<endl<<"Yearly Statistics:  "<<endl;
        //Calculate and display total rainfall
        for(int i=JAN;i!=LAST;i++)
            tRain+=w[i].tRain;
        cout<<"Total Rainfall:  "<<tRain<<endl;
        
        //Calculate and display average rainfall
        avgRain = static_cast<float>(tRain)/12.0;
        cout<<"Average Rainfall:  "<<avgRain<<endl;
        
        //Calculate and display highest temp
        for(int i=JAN;i!=LAST;i++)
            if(w[i].hTemp>hTemp){
                hTemp=w[i].hTemp;
                highMon=w[i].name;
            }
        cout<<"Highest Temp:  "<<hTemp<<" ("<<highMon<<")"<<endl;
        
        //Calculate and display lowest temp
        for(int i=JAN;i!=LAST;i++)
            if(w[i].lTemp<lTemp){
                lTemp=w[i].lTemp;
                lowMon=w[i].name;
            }
        cout<<"Lowest Temp:  "<<lTemp<<" ("<<lowMon<<")"<<endl;
        
        //Calculate and display average temp
        for(int i=JAN;i!=LAST;i++)
            avgTemp+=static_cast<float>(w[i].aTemp);
        avgTemp/=12.0;
        cout<<"Average Temp:  "<<avgTemp<<endl;
            
    }while(repeat(1)); 
}
void program9(){
    cout<<"\n************************************************"; 
    cout<<"\n**  Soccer Scores  *****************************";
    cout<<"\n************************************************";
    cout<<"\nStore and display info about a soccer team\n";
    
    //Declare
    player p[12];
    
    do{
        //Get data
        for(int i=0;i<12;i++){
            cout<<"Player "<<i+1<<":  "<<endl;
            p[i].getInfo();
            cout<<"--------------------"<<endl;
        }
        //Output Data
        cout<<"| Name     | Number   | Score    |";
        for(int i=0;i<12;i++)
            p[i].printInfo();
    }while(repeat(1)); 
}
void program10(){
    cout<<"\n************************************************"; 
    cout<<"\n**  Customer Accounts  *************************";
    cout<<"\n************************************************";
    cout<<"\nStore and display info about customer accounts\n";
    
    //Declare
    const int ACCT = 20;
    customer c[ACCT];
    for(int i=0;i<ACCT;i++)
        c[i].zip = 0;
    string ch;
    int choice;
    
    //Menu
    do{
        cout<<"**********************************************************"
            <<"\nCustomer Accounts Main Menu"
            <<"\n----------------------------------------------------------"
            <<"\n[1]  Add Account Info"
            <<"\n[2]  Edit Account Info" 
            <<"\n[3]  Retrieve Customer info by name"            
            <<"\n[4]  Print all Customer data"            
            <<"\n[0]  Exit Program";
        do{
            cout<<"\n----------------------------------------------------------"
                <<"\nPlease enter choice:  ";
            getline(cin,ch);
        }while(isNum(ch)<0||isNum(ch)>4);
        choice = isNum(ch);
        
        switch(choice){
            case 0: break;
            case 1: addAcct(c,ACCT)  ; break;    
            case 2: editAcct(c,ACCT)  ; break;
            case 3: prntAcct(c,ACCT)  ; break;
            case 4: allAcct(c,ACCT)  ; break;
            
        }
    }while(choice);
}
void program11(){
    
}
void program12(){
    
}
void program13(){
    
}

//Program Function Prototypes
int isNum(string a){
    int n=0;
    string b=a;
    for(int i=0;i<a.length();i++){
        if((a[i]-'0'<0)||(a[i]-'0'>9))
            return 0;
    }
    for(int i=0,j=a.length()-1;i<a.length();i++){
        b[i]=a[j];
        j--;
    }
        
    for(int i=a.length()-1;i>=0;i--)
        n+=((b[i]-'0')*pow(10,i));
    return n;
}
void addAcct(customer c[],int s){
    int n;
  //Find an empty record
    for(int i=0;i<s;i++)
        if(!c[i].zip)
            n=i;
  //Fill with data
    c[n].setInfo();
    cout<<"Data for "<<c[n].name<<" successfully added!"<<endl;
}
void editAcct(customer c[],int s){
    string search;
    int n=-1;
    
    cout<<"Enter a name to search for:  ";
    getline(cin,search);
    for(int i=0;i<s;i++)
        if(strcmp(search.c_str(),c[i].name.c_str())==0)
            n=i;
    if(n==-1)
        cout<<"No account records for:  "<<search<<endl;
    else{
        cout<<endl;
        c[n].setInfo();
    }       
}
void prntAcct(customer c[],int s){
    string search;
    int n=-1;
    
    cout<<"Enter a name to search for:  ";
    getline(cin,search);
    for(int i=0;i<s;i++)
        if(strcmp(search.c_str(),c[i].name.c_str())==0)
            n=i;
    if(n==-1)
        cout<<"No account records for:  "<<search<<endl;
    else{
        cout<<endl<<c[n].printInfo();
    }
}
void allAcct(customer c[],int s){
    for(int i=0;i<s;i++)
        if(c[i].zip)
            cout<<"---------------------------------"<<endl<<c[i].printInfo();
}