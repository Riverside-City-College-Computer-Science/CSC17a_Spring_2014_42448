/*
 *Name: Alec Farfan
 *Date: 2/17/14
 *Purpose: Gaddis Chapter 9 Problem 4 (Test Scores #2)
 */
 
//Include Libraries
#include <cstdlib>
#include <iostream>
using namespace std;

//No Global Variables

//Function Prototypes
void print(int,float*,string*);
void delLow(int&,int**);
void swap(int&,int&);
int set(int,float*,int);
void sort(int,float*,string*);
void average(int,int,int**,float*);
void fillTs(int,int,int**,string*);
void fillSs(int,string*);
int **allocT(int&,int,int**);
float *allocA(int,float*);
string *allocS(int&,string*);

//Execution Begins Here
int main(int argc, char *argv[])
{
    //Declare Variables
    char repeat; 
    
   
do{   
    int numTs=0,numSs=0;
    //Dynamically allocate an array
    string *stdnts=allocS(numSs,stdnts);//initialize a pointer for the string array
    float *avgs=allocA(numSs,avgs);//Initialize a pointer for the float array
    int **tests=allocT(numTs,numSs,tests);//initialize a pointer for the integer array
    fillSs(numSs,stdnts);//Fill the string array with names of students
    fillTs(numTs,numSs,tests,stdnts);//Fill the array 
    average(numSs,numTs,tests,avgs);//Find the average test score for each student 
    sort(numSs,avgs,stdnts);//Sort the array in ascending order
    print(numSs,avgs,stdnts);//Print the array
    
    delete [] stdnts;
    stdnts = 0;
    
    //Ask the user if they would like to repeat the program
    cout<<"Would you like to repeat the program? Enter Y"<<endl; 
    cout<<"to repeat or enter anything else to exit:";
    cin>>repeat;
    system("CLS");
    }while(repeat=='Y'||repeat=='y');    
    //End of Program
    return EXIT_SUCCESS;
}
string *allocS(int& numSs, string* stdnts){
    cout<<"Enter the number of students:";
    cin>>numSs;
    
    stdnts= new string[numSs];
    return stdnts;  
}
float *allocA(int numSs,float* avgs){
    avgs= new float[numSs];
    return avgs;      
}
int **allocT(int& numTs,int numSs, int** tests){
    cout<<"Enter the number of tests:";
    cin>>numTs;
    
    tests = new int*[numSs];
    for(int i=0;i<numSs;i++){
        *(tests + i)= new int[numTs];}
    return tests;
}
void fillSs(int numSs,string* stdnts){
    cout<<"Enter the names of the students, use an"<<endl;
    cout<<"underscore'_' between first and last name."<<endl;
    for(int i=0;i<numSs;i++){
       cout<<"Student "<<i+1<<":";
       cin>> *(stdnts + i);}     
}
void fillTs(int numTs,int numSs,int** tests,string *stdnts){
     for(int j=0;j<numSs;j++){
     cout<<"Enter the test scores for "<<*(stdnts + j)<<"."<<endl;
         for(int i=0;i<numTs;i++){
         cout<<"Test"<<(i+1)<<":";
         cin>> tests[j][i];}}
}
void average(int numSs,int numTs,int** tests, float* avgs){
    for(int j=0;j<numSs;j++){ 
        for(int i=0;i<numTs;i++){
        *(avgs + j)+= tests[j][i];}
        *(avgs + j)/=numTs;}
}
void sort(int numSs,float* avgs, string* stdnts){
     int min;
     for(int i=0;i<numSs-1;i++){
         min=set(i,avgs,numSs);
         swap(*(avgs+i),*(avgs+min));
         swap(*(stdnts+i),*(stdnts+min));}
}
int set(int start,float* avgs,int numSs){
     float small=*(avgs+start);
     int smallEl=start;    
     for(int i=start+1;i<numSs;i++){
         if(*(avgs+i)<small){
         small=*(avgs+i);
         smallEl=i;}}
     return smallEl; 
}
void swap(int& a, int& b){
     int temp=a;
     a=b;
     b=temp;
}
void print(int numSs,float* avgs, string* stdnts){
     cout<<endl;
     cout<<"Average Test Scores"<<endl;
     for(int i=0;i<numSs;i++){
        cout<<*(stdnts+i)<<": "<<*(avgs+i)<<endl;}
}
