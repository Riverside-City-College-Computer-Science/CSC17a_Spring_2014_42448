/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on March 30, 2014, 1:04 PM
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

struct Speaker{
    string name;
    string phone;
    string speak;
    int fee;
};

void printarr(Speaker []);
void printmenu();
void enterdata(Speaker &);

int main(int argc, char** argv) {

    Speaker community[10];
    int input=1;
   while (input>0)
   {
        printmenu();
        cin >> input;
        if(input<0)
            break;
        switch(input)
        {
            case 1: 
                for(int i=0;i<10;i++)
                {
                    cout << "Please enter data for the " << i+1 << "st person" << endl;
                    enterdata(community[i]);
                }
                break;
            case 2:
                cout << "Enter which community person you want to change (0-9)";
                cin >> input;
                enterdata(community[input]);
                break;
            case 3:
                printarr(community);
                break;
            default:
                cout << "Invalid menu choice";
                break;
        }
   }
    return 0;
}

void enterdata(Speaker &speak)
{
    int fee;
    cout << "Please enter a name" << endl;
    cin >> speak.name;
    cout << "Please enter phone number: " << endl;
    cin >> speak.phone;
    cout << "Please enter speaking topic: " << endl;
    cin >> speak.speak;
    cout << "Please enter required fee: " << endl;
    cin >> fee;
    if(fee<0){
        cout << "Invalid fee, must be positive value, please re-enter: " << endl;
        cin >> fee;
    }
    speak.fee=fee;

}

void printarr(Speaker speak[])
{
    for(int i=0;i<10;i++)
    {
        cout << "Name: " << speak[i].name << endl;
        cout << "Phone: " << speak[i].phone << endl;
        cout << "Speaking Topic: " << speak[i].speak << endl;
        cout << "Fee required: " << speak[i].fee << endl;
    }
    
}
void printmenu()
{
    cout << "Please enter what you would like to do (or -1) to quit: "
            "\n1)Enter new data into all the speakers"
            "\n2)Change contents of a speaker"
            "\n3)Display all the data" << endl;
}