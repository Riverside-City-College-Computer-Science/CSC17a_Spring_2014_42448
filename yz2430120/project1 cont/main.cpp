/* 
 * File:   main.cpp
 * Author: Zhang, Yi
 *
 * Created on April 15, 2014, 9:57 AM
 */

///System Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cstring>
#include <fstream>
using namespace std;
///No Global Constants

///Libiary
#include "Player.h"

///Function Prototypes
void filcard(Player[],int [],int);
bool test1(int []);
bool test2(int [],int[],int,int []);
void change(Player[], int [],int);
void shwcard(int [],int[]);
void arrange(int[]);
char *Name(string,string);
void Leveasy(int []);
void Levhard(int []);
int level();
int main(int argc, char** argv) {
    
    string introduction;
    fstream intro("instruction.txt",ios::in);
    if(intro){
        getline(intro,introduction,'$');
    cout<<introduction<<endl;        
    }
    else cout<<"The file is missing"<<endl;
    cout<<endl;
    
      ///Initialize random number seed
  srand(static_cast<unsigned int>(time(0)));
  short eayorhad,size1;
  const int size2=5;
  cout<<"Welcome to the game 5 Poker~"<<endl;
  cout<<"How many players want to play the game?"<<endl;
  cin>>size1;
  cin.ignore();
  Player *a;
  a=new Player[size1];
  int copy[size2],number[size2];  
 char **name=new char *;
  
  for(int i=0;i<size1;i++){      
  cout<<"Player "<<(i+1)<<endl;
  name[i]=Name((a+i)->name.firstN,(a+i)->name.lastN);
  cout<<"Hello, "<<name[i]<<endl;
  
 ///pick 5 Cards  
 do{ filcard(a,copy,i);}while(!test1(copy));  
 ///choose difficulty level
 eayorhad=level(); 
 ///show cards and change cards
   cout<<"Your cards are:"<<endl;
  shwcard((a+i)->card,number);
  change(a,copy,i);
    cout<<"Your new cards are:"<<endl;
   shwcard((a+i)->card,number);
   cout<<endl;
///print out the result
  if(eayorhad==0) Leveasy(number);
  else Levhard(number);
  cout<<endl;
  cin.ignore();      
  }
 
 cout<<"The game has reached the end, and the users' names have been save to the file \"users.txt\"."<<endl;
 cout<<"Goodbye, have a good day."<<endl;
 
 ofstream username;
 username.open("users.txt",ios::out);
 for(int i=0;i<size1;i++){
     username<<name[i]<<endl;
 }
 

 ///Close files
 username.close();
 intro.close();
 
  ///Release the memory
 for(int i=0;i<size1;i++){
     delete name[i];
 }
  delete []a;
  delete []name;
    return 0;
}
void filcard(Player a[],int copy[],int b){
    
    a[b].card[0]=rand()%52+1;
    copy[0]=a[b].card[0];
    a[b].card[1]=rand()%52+1;
    copy[1]=a[b].card[1];
    a[b].card[2]=rand()%52+1;
    copy[2]=a[b].card[2];
    a[b].card[3]=rand()%52+1;
    copy[3]=a[b].card[3];
    a[b].card[4]=rand()%52+1;
    copy[4]=a[b].card[4];
}

///test1 makes sure the 5 cards are different
bool test1(int copy[]){
    ///Sorting first
  arrange(copy);
    for(int i=0;i<4;i++){
        if(copy[i]==copy[i+1])return false;
        
    }
    return true;
}

void change(Player a[],int copy[],int b){
    char ans;
    int check[5], temp[5];
    for(int i=0;i<5;i++){
        cout<<"Do you want to change your card "<<(i+1)<<"? (Type \"Y\" or \"y\" to change, type anything else to keep it)"<<endl;
        cin>>ans;
        if(toupper(ans)=='Y'){
            do{
                a[b].card[i]=rand()%52+1;
                check[i]=a[b].card[i];
            }while(!test2(check,copy,i,temp));           
        }
        
    }
}
///test2 makes sure after changing the cards, the 5 cards are still different, and the cards have changed for sure.
bool test2(int a[],int copy[],int j,int temp[]){
    int i;
    ///If the changed card equals one of the 5 original cards, return false
    for( i=0;i<5;i++){
        if(a[j]==copy[i])return false;
    }
    ///If the changed card equals one of those cards which has just been changed,return false
    for(i=0;i<j;i++){
        if (a[j]==temp[i])return false;
    }
    ///If the changed card passes the first two, record it with temp[] for later test, and return ture
    temp[j]=a[j];  
    
    return true;
}
 void shwcard(int a[],int number[]){
     float b[5];
     string suit[5];    
   
       for(int i=0;i<5;i++){
          b[i]=a[i]/13.0;  
      
        if(b[i]<=1)suit[i]="Heart";
        else if(1<b[i]&&b[i]<=2)suit[i]="Spade";
        else if(2<b[i]&&b[i]<=3)suit[i]="Club";
        else if(3<b[i]&&b[i]<=4)suit[i]="Diamond";
       
          number[i]=a[i]%13;
          
        cout<<"Card "<<(i+1)<<": ";
        if(number[i]==1)cout<<suit[i]<<" "<<"Ace"<<endl;
        else if(number[i]==0)cout<<suit[i]<<" "<<"King"<<endl;
        else if(number[i]==12)cout<<suit[i]<<" "<<"Queen"<<endl;
        else if(number[i]==11)cout<<suit[i]<<" "<<"Jack"<<endl;
        else cout<<suit[i]<<" "<<number[i]<<endl;
         
     }    
     
 }
 void arrange(int a[]){
      int temp;
     for(int i=0;i<4;i++){
        for(int j=i+1;j<5;j++){
            if(a[i]>a[j]){
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
 }
char *Name(string a,string b){
     int length1,length2,size;
     cout<<"Input your first name:"<<endl;
     getline(cin,a);
     cout<<"Input your last name:"<<endl;
     getline(cin,b);
     length1=a.length();
     length2=b.length();
     size=length1+length2+1;
     char *first,*last;     
     first=new char[length1+2];
     last=new char[length2+1];
     for(int i=0;i<length1;i++){
         first[i]=a[i];
              }
     first[length1]=' ';
     first[length1+1]='\0';
     for(int i=0;i<length2;i++){
         last[i]=b[i];
     }
     last[length2]='\0';
     strcat(first,last);
     delete []last;
     return first;
 }

 int level(){
     string a;
     short b;
     enum Level{easy,hard};
     cout<<"Which level you want to choose for your game? (Type in \"easy\" or \"hard\")"<<endl;
     cin>>a;
     while(a!="easy"&&a!="hard"){
         cout<<"Type in \"easy\" or \"hard\" "<<endl;
         cin>>a;                  
     }     
     if(a=="easy")b=1;
     else b=2;
       switch(b){
         case 1: return easy; break;         
         case 2:return hard;break;      
     }
     
 }
  void Leveasy(int a[]){
     int i,pair=0;
     arrange(a);
      for( i=0;i<4;i++){
         if(a[i]==a[i+1]){
             pair++;            
         }
     }   
     if(a[0]==a[1]&&a[1]==a[2]&&a[2]!=a[3]&&a[3]!=a[4]||a[0]!=a[1]&&a[1]==a[2]&&a[2]==a[3]&&a[3]!=a[4]||a[0]!=a[1]&&a[1]!=a[2]&&a[2]==a[3]&&a[3]==a[4])
         cout<<"You get a three of a kind, very good!"<<endl;    
     else if(pair==1) cout<<"You get a pair, good!"<<endl;
     else if(pair==2) cout<<"You get two pairs, nice!"<<endl;     
     else if(a[0]==a[1]&&a[1]==a[2]&&a[2]==a[3]&&a[3]!=a[4]||a[0]!=a[1]&&a[1]==a[2]&&a[2]==a[3]&&a[3]==a[4])
         cout<<"You get a four of a kind, amazing!"<<endl;     
     else if(a[0]==a[1]&&a[1]==a[2]&&a[2]==a[3]&&a[3]==a[4])
         cout<<"You get a five of a kind, excellent!"<<endl;
     else if(a[0]==a[1]&&a[1]==a[2]&&a[3]==a[4]||a[0]==a[1]&&a[2]==a[3]&&a[3]==a[4])
         cout<<"You get a full house, nice!"<<endl;
     else cout<<"Sorry, you lost!"<<endl;
     
 }
 void Levhard(int a[]){
      int i,pair=0;
     arrange(a);
      for( i=0;i<4;i++){
         if(a[i]==a[i+1]){
             pair++;            
         }
     }   
     if(a[0]==a[1]&&a[1]==a[2]&&a[2]!=a[3]&&a[3]!=a[4]||a[0]!=a[1]&&a[1]==a[2]&&a[2]==a[3]&&a[3]!=a[4]||a[0]!=a[1]&&a[1]!=a[2]&&a[2]==a[3]&&a[3]==a[4])
         cout<<"You get a three of a kind, very good!"<<endl;    
     else if(pair==2) cout<<"You get two pairs, nice!"<<endl;     
     else if(a[0]==a[1]&&a[1]==a[2]&&a[2]==a[3]&&a[3]!=a[4]||a[0]!=a[1]&&a[1]==a[2]&&a[2]==a[3]&&a[3]==a[4])
         cout<<"You get a four of a kind, amazing!"<<endl;     
     else if(a[0]==a[1]&&a[1]==a[2]&&a[2]==a[3]&&a[3]==a[4])
         cout<<"You get a five of a kind, excellent!"<<endl;
     else if(a[0]==a[1]&&a[1]==a[2]&&a[3]==a[4]||a[0]==a[1]&&a[2]==a[3]&&a[3]==a[4])
         cout<<"You get a full house, nice!"<<endl;
     else cout<<"Sorry, you lost!"<<endl;
     
 }
  
 