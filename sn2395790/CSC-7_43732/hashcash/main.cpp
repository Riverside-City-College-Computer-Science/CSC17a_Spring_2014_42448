/* 
 * File:   main.cpp
 * Author: Scott Nevin 
 * Purpose: Use encryption methods to authenticate user input
 * Created on April 8, 2014, 10:06 AM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
#include "HashFunctions.h"
using namespace std;

//Global Variables and Constants

//Function Prototypes
void stats(char);//function that conducts hash functions

//Execution begins here
int main(int argc, char** argv) {
    
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables
    string key = "Example";
    int exmpl = rand();
    char choice;
    
    //combine string and random number into a single string
    //string conversion method taken from Dr. Mark E. Lehr
    ostringstream convert;  
    convert << exmpl++;      
    string strRnd = convert.str();
    string newMsg=key+strRnd;
    
  //Prompt user for hash function to be tested
    cout<<"Select hash function to take statistics on:"<<endl;
    cout<<"1.   RS-Hash Function "<<endl;
    cout<<"2.   JS-Hash Function "<<endl;
    cout<<"3.  PJW-Hash Function "<<endl;
    cout<<"4.  ELF-Hash Function "<<endl;
    cout<<"5. BKDR-Hash Function "<<endl;
    cout<<"6. SDBM-Hash Function "<<endl;
    cout<<"7.  DJB-Hash Function "<<endl;
    cout<<"8.  DEk-Hash Function "<<endl;
    cout<<"9.  FNV-Hash Function "<<endl;
    cout<<"10.  BP-Hash Function "<<endl;
    cout<<"11.  AP-Hash Function "<<endl;
    cin>>choice;
    
/*
   cout << "General Purpose Hash Function Algorithms Test" << std::endl;
   cout << "By Arash Partow - 2002        " << std::endl;
   cout << "Key: "                          << key<<exmpl<< std::endl;
   cout << " 1. RS-Hash Function Value:   " << RSHash(newMsg)   << std::endl;
   cout << " 2. JS-Hash Function Value:   " << JSHash(newMsg)   << std::endl;
   cout << " 3. PJW-Hash Function Value:  " << PJWHash(newMsg)  << std::endl;
   cout << " 4. ELF-Hash Function Value:  " << ELFHash(newMsg)  << std::endl;
   cout << " 5. BKDR-Hash Function Value: " << BKDRHash(newMsg) << std::endl;
   cout << " 6. SDBM-Hash Function Value: " << SDBMHash(newMsg) << std::endl;
   cout << " 7. DJB-Hash Function Value:  " << DJBHash(newMsg)  << std::endl;
   cout << " 8. DEK-Hash Function Value:  " << DEKHash(newMsg)  << std::endl;
   cout << " 9. FNV-Hash Function Value:  " << FNVHash(newMsg)  << std::endl;
   cout << "10. BP-Hash Function Value:   " << BPHash(newMsg)   << std::endl;
   cout << "11. AP-Hash Function Value:   " << APHash(newMsg)   << std::endl;

   return true;
*/
    return 0;
}

