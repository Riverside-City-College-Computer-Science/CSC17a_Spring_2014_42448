/* 
 * File:   main.cpp
 * Author: Zhang,Yi
 *
 * Created on March 2, 2014, 9:48 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;


int main(int argc, char** argv) {
const int NUM_NAMES = 20;
string names[NUM_NAMES] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
"Griffin, Jim", "Stamey, Marty", "Rose, Geri",
"Taylor, Terri", "Johnson, Jill",
"Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
"James, Jean", "Weaver, Jim", "Pore, Bob",
"Rutherford, Greg", "Javens, Renee",
"Harrison, Rose", "Setzer, Cathy",
"Pike, Gordon", "Holland, Beth" };
char again;
for(int i=0;i<NUM_NAMES;i++)
{
    for(int j=i+1;j<NUM_NAMES;j++){
        if (names[i]>names[j])
        { string temp;
                    temp=names[j];
                    names[j]=names[i];
                 names[i]=temp;
        
        }
        
    }
}
for(int a=0;a<20;a++){
    cout<<names[a]<<"       ";
    if ((a%5)==4)cout<<endl;
}

string search;
getline(cin,search);
bool found=false;
int first=0,last=19,middle;
while(!found&&first<=last){
    middle=(first+last)/2;
    if(names[middle]==search){
        found=true;        
    }
    else if (names[middle]<search)
    first=middle+1;
    else last=middle-1;
    
}
if(first>last)cout<<"not found"<<endl;
else cout<<"The position is "<<middle<<endl;



    return 0;
}

