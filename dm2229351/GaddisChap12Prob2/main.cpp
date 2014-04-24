
/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on March 28, 2014, 11:27 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    string filename;
    fstream namefile;
    string input;
    string userinput;
    cout << "Please enter the name of the file\n";
    cin >> filename;
    namefile.open(filename.c_str(), ios::in);
    int count=0;
    if(namefile)
    {
        getline(namefile, input);
        while(namefile){
            if((count%24)==0)
            {
                if(count!=0){
                cout << "\n Please push a key and enter to continue";
                cin >> userinput;
                }
            }
            cout << input << endl;
            getline(namefile, input);
            count++;
        }
    }
    
    cout << endl;
    namefile.close();

    return 0;
}

