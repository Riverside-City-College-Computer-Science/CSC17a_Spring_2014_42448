/*  Joseph Reimbold
    March 28, 2014
    Assignment 2
 */

//Libraries
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <cstring>
using namespace std;

//Global Constants


//Function Prototypes
void Menu();
short getChoice();
void dflt(short);
void prob1();
void prob2();
void prob3();
void prob4();
void prob5();
void prob6();

//Structures for Problems
struct MovieData
{
    string title;     //Movie Title
    string director;  //Director Name
    int yrRls;        //Year Released
    int time;         //Running Time (in minutes)
};

struct MovieData2
{
    string title;     //Movie Title
    string director;  //Director Name
    int yrRls;        //Year Released
    int time;         //Running Time (in minutes)
    int budget;       //Budget
    int gross;        //Gross (USA)
};

struct Sales
{
    string dvsn;      //division name
    float first;      //first quarter sales
    float second;     //second quarter sales
    float third;      //third quarter sales
    float fourth;     //fourth quarter sales
    float ttlSls;     //total annual sales
    float avgSls;     //average quarter sales
};

//Function Prototypes for Problems
int cntChrs(char *);
void reverse(char *);
int cntWrds(char *);
void destroy(char *);
void prntMov(const MovieData);
void prntMov2(const MovieData2);
void getSls(Sales &);
void prntSls(const Sales);


//Begin Execution Here!!!
int main(){
    short choice;
    do{
        Menu();
        choice=getChoice();
        cout<<endl;
        switch(choice){
        case 1:    prob1();break;
        case 2:    prob2();break;
        case 3:    prob3();break;
        case 4:    prob4();break;
        case 5:    prob5();break;
        case 6:    prob6();break;
        default:   dflt(choice);}
    }while(choice>=1&&choice<=6);
    return 0;
}

void Menu(){
    cout<<"Assignment 3 Problems"<<endl;
    cout<<"Type 1 for Gaddis 7th Edition Chapter 10 problem 1"<<endl;
    cout<<"Type 2 for Gaddis 7th Edition Chapter 10 problem 2"<<endl;
    cout<<"Type 3 for Gaddis 7th Edition Chapter 10 problem 3"<<endl;
    cout<<"Type 4 for Gaddis 7th Edition Chapter 11 problem 1"<<endl;
    cout<<"Type 5 for Gaddis 7th Edition Chapter 11 problem 2"<<endl;
    cout<<"Type 6 for Gaddis 7th Edition Chapter 11 problem 3"<<endl;
    cout<<"Type anything else to exit \n"<<endl;
}

short getChoice(){
        int n;
        cin>>n;
        return n;
}


//Begin Gaddis 7th Edition Chapter 10 problem 1
void prob1(){
    //declare variables
    const int SIZE=21;
    char *word=new char[SIZE];
    int num;

    //get character string
    cin.ignore();
    cout<<"Enter a string of 20 characters or less"<<endl;
    cin.getline(word,SIZE);

    //output number of characters
    cout<<endl;
    cout<<"The number of characters in"<<endl
        <<"the string you input is: "<<cntChrs(word)<<endl<<endl;
    
    //delete dynamically created array
    destroy(word);
}//End Gaddis Chap10 Prob1

int cntChrs(char *a){
    int n=0;
    
    while(a[n]!='\0')n++;
    
    return n;
}


//Begin Gaddis 7th Edition Chapter 10 problem 2
void prob2(){
     //declare variables
    const int SIZE=21;
    char *word=new char[SIZE];
    
    //get Cstring from user
    cin.ignore();
    cout<<"Enter a string of 20 or less characters:"<<endl;
    cin.getline(word,SIZE);
    cout<<endl;
    //int szwrd=strlen(word);
    
    //reverse the word
    reverse(word);
    
    //output reversed word
    cout<<"Here is your string backwards!"<<endl;
    cout<<word<<endl<<endl;
    
    //destroy! and exit main
    destroy(word);
     
}//End Gaddis Chap10 Prob2

void reverse(char *a){
    char *first=a;
    char *last=a + strlen(a);
    
    while(first<last){
        --last;
        char temp=*first;
        *first=*last;
        *last=temp;
        ++first;
    }
}
 
void destroy(char *a){
    delete []a;
}

//Begin Gaddis 7th Edition Chapter 10 problem 3
void prob3(){
     //declare variables
    const int SIZE=101;
    char *line=new char[SIZE];
    
    //get Cstring from user
    cin.ignore();
    cout<<"Enter a phrase less than 100 characters:"<<endl;
    cin.getline(line,SIZE);
    cout<<endl;
    
    //count number of words in line
    cout<<"The number of spaces in your phrase is "<<cntWrds(line)<<endl<<endl;
    
    //destroy! and exit main
    destroy(line);
     
}//End Gaddis Chap10 Prob 3

int cntWrds(char *a){
    int words=1;
    
    for(int i=0;i<strlen(a);i++){
        if(*(a+i)==32)words++;
        //cout<<a[i]<<endl;
    }
    
    return words;
}

//Begin Gaddis Chapter 11 Problem 1
void prob4(){
    //declare variables
    const int NUM_MOVIES=2;
    MovieData movies[NUM_MOVIES]={
                                   {"Jurassic Park","Steven Spielberg",1993,127},
                                   {"Serenity","Joss Whedon",2005,119}
                                 };
    
    //print information about the movies one by one
    for(int i=0;i<NUM_MOVIES;i++){
        cout<<"Info for Movie "<<i+1<<endl;
        prntMov(movies[i]);
    }    
    
}//End Gaddis Chap11 Prob1
    
    
void prntMov(const MovieData m){
    cout<<"Title:     "<<m.title<<endl;
    cout<<"Director:  "<<m.director<<endl;
    cout<<"Release:   "<<m.yrRls<<endl;
    cout<<"Run Time:  "<<m.time<<endl<<endl;
    
}

//Begin Gaddis Chapter 11 Problem 2
void prob5(){
    //declare variables
    const int NUM_MOVIES=2;
    MovieData2 movie[NUM_MOVIES]={
                                    {"Jurassic Park","Steven Spielberg",1993,127,63000000,357067947},
                                    {"Serenity","Joss Whedon",2005,119,40000000,25514517}
                                  };
    
    //print information about the movies one by one
    for(int i=0;i<NUM_MOVIES;i++){
        cout<<"Info for Movie "<<i+1<<endl;
        prntMov2(movie[i]);
    }    
    
}//End Gaddis Chap11 Prob2
    
    
void prntMov2(const MovieData2 m){
    cout<<"Title:           "<<m.title<<endl;
    cout<<"Director:        "<<m.director<<endl;
    cout<<"Release:         "<<m.yrRls<<endl;
    cout<<"Run Time (mins): "<<m.time<<endl;
    cout<<"Budget:          $"<<m.budget<<endl;
    cout<<"Gross (USA):     $"<<m.gross<<endl<<endl;
    
}

//begin Gaddis Chap11 Prob3
void prob6(){
    //declare variables
    Sales east={"East",0,0,0,0,0,0},
          west={"West",0,0,0,0,0,0},
          north={"North",0,0,0,0,0,0},
          south={"South",0,0,0,0,0,0};
    
    //get sales figures from user
    getSls(east);
    getSls(west);
    getSls(north);
    getSls(south);
    
    //print sales figures
    prntSls(east);
    prntSls(west);
    prntSls(north);
    prntSls(south);
}//end Gaddis Chap11 Prob3

void getSls(Sales &d){
    cout<<d.dvsn<<" Division: "<<endl;
    cout<<"Enter First-Quarter Sales: $";
    cin>>d.first;
    cout<<"Enter Second-Quarter Sales: $";
    cin>>d.second;
    cout<<"Enter Third-Quarter Sales: $";
    cin>>d.third;
    cout<<"Enter Fourth-Quarter Sales: $";
    cin>>d.fourth;
    cout<<endl;
    
    //calculate total and average sales
    d.ttlSls=d.first+d.second+d.third+d.fourth;
    d.avgSls=d.ttlSls/4;
}

void prntSls(const Sales d){
    cout<<fixed<<setprecision(2);
    cout<<d.dvsn<<" Division"<<endl;
    cout<<"First-Quarter Sales:   $"<<d.first<<endl;
    cout<<"Second-Quarter Sales:  $"<<d.second<<endl;
    cout<<"Third-Quarter Sales:   $"<<d.third<<endl;
    cout<<"Fourth-Quarter Sales:  $"<<d.fourth<<endl;
    cout<<"Total Annual Sales:    $"<<d.ttlSls<<endl;
    cout<<"Average Quarter Sales: $"<<d.avgSls<<endl<<endl;
}

void dflt(short val){
        cout<<"You typed "<<val<<" to exit the program"<<endl;
}
