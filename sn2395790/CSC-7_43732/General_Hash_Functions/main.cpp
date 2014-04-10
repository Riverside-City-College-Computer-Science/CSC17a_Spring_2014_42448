/* 
 * File:   main.cpp
 * Author: Scott 
 * Purpose: Use encryption methods to authenticate user input
 * Created on April 8, 2014, 10:06 AM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include "GeneralHashFunctions.h"
using namespace std;

//Global Variables and Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    
    std::string key = "KEY";

   std::cout << "General Purpose Hash Function Algorithms Test" << std::endl;
   std::cout << "By Arash Partow - 2002        " << std::endl;
   std::cout << "Key: "                          << key           << std::endl;
   std::cout << " 1. RS-Hash Function Value:   " << RSHash(key)   << std::endl;
   std::cout << " 2. JS-Hash Function Value:   " << JSHash(key)   << std::endl;
   std::cout << " 3. PJW-Hash Function Value:  " << PJWHash(key)  << std::endl;
   std::cout << " 4. ELF-Hash Function Value:  " << ELFHash(key)  << std::endl;
   std::cout << " 5. BKDR-Hash Function Value: " << BKDRHash(key) << std::endl;
   std::cout << " 6. SDBM-Hash Function Value: " << SDBMHash(key) << std::endl;
   std::cout << " 7. DJB-Hash Function Value:  " << DJBHash(key)  << std::endl;
   std::cout << " 8. DEK-Hash Function Value:  " << DEKHash(key)  << std::endl;
   std::cout << " 9. FNV-Hash Function Value:  " << FNVHash(key)  << std::endl;
   std::cout << "10. BP-Hash Function Value:   " << BPHash(key)   << std::endl;
   std::cout << "11. AP-Hash Function Value:   " << APHash(key)   << std::endl;

   return true;

    return 0;
}

