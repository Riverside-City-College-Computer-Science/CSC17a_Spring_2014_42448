/* 
 * Author: Paul Lee
 * Date: 03/05/14
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

void prob1();
void prob2();
void prob3();
void prob4();
void prob5();
void timesTen(int);
void prob6();
void prob7();
bool search(int, int[]);
void menu();

int main(){
    //menu stuff
    int select;
    do{
        menu();
        cin >> select;
        switch (select) {
            case 1:
                prob1();
                break;
            case 2:
                prob2();
                break;
            case 3:
                prob3();
                break;
            case 4:
                prob4();
                break;
            case 5:
                prob5();
                break;
            case 6:
                prob6();
                break;
            case 7:
                prob7();
                break;
            default:
                cout<<"please try again"<<endl;
                break;
        }
    }
    while(select<8);
    return 0;
}

void menu(){
    cout<<"enter the problem you would like to see"<<endl;
    cout<<"1 - chapter 2"<<endl;
    cout<<"2 - chapter 3"<<endl;
    cout<<"3 - chapter 4"<<endl;
    cout<<"4 - chapter 5"<<endl;
    cout<<"5 - chapter 6"<<endl;
    cout<<"6 - chapter 7"<<endl;
    cout<<"7 - chapter 8"<<endl;
    cout<<"enter 8 to quit"<<endl;
}

void prob1(){
    int age = 19;
    float weight = 125;
    cout<<"problem 2.20 Gaddis p.58"<<endl;
    cout<<"My age is "<<age<<" my weight is "<<weight<<" pounds."<<endl;
}

void prob2(){
    char letter;
    cout<<"problem 3.12 Gaddis p.106"<<endl;
    cout<<"please enter a single character and press enter to view the ASCII "
            "code. "<<endl;
    cin>>letter;
    cout<<static_cast<int>(letter)<<endl;
}

void prob3(){
    float sales, bonus=200, total;
    cout<<"problem 4.10 Gaddis p.165"<<endl;
    cout<<"enter the amount of $";
    cin>>sales;
    if(sales>50000){
        total=(sales*.25)+bonus;
        cout<<"your total earnins is $"<<total<<endl;
    }
    else{
        cout<<"sorry, you did not reach over $50,000"<<endl;
    }
}

void prob4(){
    cout<<"problem 5.11 Gaddis p.257"<<endl;
    for(int i=0; i<=20; i++){
        cout<<i*5<<" ";
    }
}

void prob5(){
    int number;
    cout<<"problem 6.7 Gaddis p.323"<<endl;
    cout<<"enter a number to multiply by 10"<<endl;
    cin>>number;
    timesTen(number);
}

void timesTen(int number){
    cout<<number*10<<endl;
}

void prob6(){
    cout<<"problem 7.6 Gaddis p.389"<<endl;
    int values[5], count;
    for(count = 0; count<5; count++)
        values[count] = count+1;
    for(count = 0; count<5; count++)
        cout<<values[count]<<endl;
}

void prob7(){
    cout<<"Programming challenge 1 chapter 8 Gaddis p.487"<<endl;
    int accNum[18] = {5658845, 4520125, 7895122, 8777541, 8451277, 1302850,
        8080152, 4562555, 5552012, 5050552, 7825877, 1250255,
        1005231, 6545231, 3852085, 7576651, 7881200, 4581002};
    int input;
    cout<<"enter your account number"<<endl;
    cin>>input;
    if(search(input, accNum)){
        cout<<"your acc #"<<input<<" came out as a match!"<<endl;
    }
    else{
        cout<<"sorry we do not recognize your account number"<<endl;
    }
}

bool search(int num, int array[]){
    for(int i=0; i<18; i++){
        if(num==array[i])
            return true;
    }
    return false;
}