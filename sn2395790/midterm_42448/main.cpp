//Dr. Mark E. Lehr
//April 21st, 2014
//Menu to be used for the midterm
//homework and final, etc....

//Library includes Here!!!
#include <iostream>
using namespace std;

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
        cout<<"In problem # 1"<<endl<<endl;
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