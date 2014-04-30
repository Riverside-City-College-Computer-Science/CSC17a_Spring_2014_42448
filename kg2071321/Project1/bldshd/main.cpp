/* 
 * File:   main.cpp
 * Author: Kamron Golbaf
 *Project1
 * Created on March 19, 2013, 1:42 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <fstream>

using namespace std;

void Menu();
int getN();
void def(int);
void beginner(int&, char [][3], string, string [10], int [10]);
void intermediate(int&, char [][3], string, string [10], int [10]);
void advanced(int&, char [][3], string, string [10], int [10]);
void highscores(char [][3], string [10], int [10]);
void fillscores(char [][3], string [10], int [10]);

    int main(int argv,char *argc[])
    {
        string set_level;
        char initials[10][3];
        string level[10];
        int attempts[10];
        int users_count = 0;       
        string directions;
    	int inN;
    	
    	fillscores(initials, level, attempts);
    	
        system("notepad.exe directions.txt");
    	
        do{
         Menu();
         inN=getN();
         switch(inN){
          case 1:    beginner(users_count, initials, set_level, level, attempts);break;
          case 2:    intermediate(users_count, initials, set_level, level, attempts);break;
          case 3:    advanced(users_count, initials, set_level, level, attempts);break;
          case 4:    highscores(initials, level, attempts);break;
          default:   def(inN);}
        }while(inN<5);
        
        cout << users_count << endl;
        system("PAUSE");
        return EXIT_SUCCESS;
    }
    void Menu()
    {
            cout <<"**********************************************************\n";
            cout<<"\tWelcome to MASTERMIND!"<<endl;
            cout<<"****************************************"<<endl;
            cout<<"-For Beginner Level Type 1"<<endl;
            cout<<"-For Intermediate Level Type 2"<<endl;
            cout<<"-For Advanced Level Type 3"<<endl;
            cout<<"-To view high scores Type 4"<<endl;
            cout<<"-To Exit Game Type 5 \n"<<endl;
    }
    int getN()
    {
           int inN;
		   cin>>inN;
           return inN;
    }    
    void fillscores(char initials[][3], string level[10], int attempts[10])
    {
        for(int i = 0; i < 10; i++)
        {
            level[i] = "000";
            attempts[i] = 0;
            
            for(int j = 0; j < 3; j++)
            {
                 initials[i][j] = '0';   
            }} 
    }   
    void highscores(char initials[][3], string level[10], int attempts[10])
    {
        cout << setw(25) << "TOP 10 SCORES\n";
        cout << setw(10) << "PLAYER" << setw(10) << "LEVEL" << setw(10) << "TRIES\n";
        
        for(int i = 0; i < 10; i++)
        {
            cout << setw(6);
            
            for(int j = 0; j < 3; j++)
            {
                cout << initials[i][j];
            }            
            cout << setw(11) << level[i] << setw(8) << attempts[i] << endl;   
        }    
    }   
    void beginner(int& users_count, char initials[][3], string set_level, string level[10], int attempts[10])
    {      
        char init1,init2,init3,num1,num2,num3,ans1=32,ans2=32,ans3=32,replay;
        int ran1,ran2,ran3,num1_value,num2_value,num3_value;
        short max_tries_beg=10; 
        bool mastermind = false;
        
        set_level = "BEG";
        level[users_count] = set_level;
        
        srand(static_cast<unsigned int>(time(0)));
        do
        {
        ran1=rand()%10;
        do{ran2=rand()%10;}
        while(ran2 == ran1);
        do{ran3=rand()%10;}
        while((ran3 == ran1) || (ran3 == ran2));
        
        cout<<"************************************"<<endl<<endl;
        cout << "-You Chose Beginner Level"<<endl;
        cout << "-You have 10 Tries, Guess a 3-Digit Number."<<endl;
                
                for(int user_tries = 0; (user_tries < max_tries_beg) && (mastermind == false); user_tries++)
                {//for loop starting bracket
                    
                    cout<<"Enter Guess " << user_tries + 1<< ": ";
                    cin>>num1>>num2>>num3;

                    cout << "\nYou Entered" << endl;

                    num1_value = num1 - 48;
                    num2_value = num2 - 48;
                    num3_value = num3 - 48;
                    //***********NUM1_VALUE CHECK***********
                    if(num1_value == ran1)
                        {ans1 = 42;}
                    else if((num1_value == ran2) || (num1_value == ran3))
                        {ans1 = 94;}
                    else
                        {ans1 = 32;}
                    //*************NUM2_VALUE CHECK********** 
                    if(num2_value == ran2)
                        {ans2 = 42;}
                    else if((num2_value == ran1) || (num2_value == ran3))
                        {ans2 = 94;}
                    else
                        {ans2 = 32;}
                    //************NUM3_VALUE CHECK**********
                    if(num3_value == ran3)
                        {ans3 = 42;}
                    else if((num3_value == ran2) || (num3_value == ran1))
                        {ans3 = 94;}
                    else
                        {ans3 = 32;}
                    cout<<num1_value<<num2_value<<num3_value<<endl;
                    cout<<ans1<<ans2<<ans3<<endl;

                    if((num1_value == ran1) && (num2_value == ran2) && (num3_value == ran3)){
                        mastermind = true;
                        cout<<"CONGRATULATIONS! You are the MASTERMIND of the Beginner Level!!"<<endl;
                        cout<< "It took " << user_tries + 1 << " to beat the game\n";
                        cout<<"Enter your 3-Character name"<<endl;
                        
                        for(int i = 0; i < 3; i++)
                        {
                            cin >> initials[users_count][i];   
                        }                
                        attempts[users_count] = user_tries + 1;
                        
                        level[users_count] = set_level;
                        
            			users_count++;
                    }
                    cout << "--------------\n";}
             		    
        if(mastermind == false)
        { cout << "Sorry, you didn't make the cut\n";}           
        cout << "Would you like to play Beginner Level again? <Y/N>: ";
        cin >> replay;
        mastermind = false;
        }
        while((replay == 'Y') || (replay == 'y'));//while loop ending bracket
    
    cout << "THANK YOU FOR PLAYING MASTERMIND!"<<endl;
    }         //end prob1
    void intermediate(int& users_count, char initials[][3], string set_level, string level[10], int attempts[10])
    {
        char init1,init2,init3,num1, num2, num3, num4,ans1 = 32,ans2 = 32,ans3 = 32,ans4 = 32, replay;
        int ran1,ran2,ran3,ran4, num1_value, num2_value, num3_value, num4_value;
        short max_tries_int = 5; 
        bool mastermind = false;
        
        
    srand(static_cast<unsigned int>(time(0)));
    do{
        ran1=rand()%10;
        do{ran2=rand()%10;}
        while(ran2 == ran1);
        do{ran3=rand()%10;}
        while((ran3 == ran1) || (ran3 == ran2));
        do{ran4=rand()%10;}
        while((ran4 == ran1) || (ran4 == ran2) || (ran4 == ran3));
        
        set_level = "INT";
        level[users_count] = set_level;
        
        cout<<"**************************************"<<endl<<endl;
        cout << "-You Chose Intermediate Level"<<endl;
                cout << "-You have 5 Tries, Guess a 4-Digit Number"<<endl;
                               
                for(int user_tries = 0; (user_tries < max_tries_int) && (mastermind == false); user_tries++)
                {//for loop starting bracket
                    cout<<"Enter Guess " << user_tries + 1<< ": ";
                    cin>>num1>>num2>>num3>>num4;

                    cout << "You Entered" << endl;

                    num1_value = num1 - 48;
                    num2_value = num2 - 48;
                    num3_value = num3 - 48;
                    num4_value = num4 - 48;

                    //**********NUM1_VALUE CHECK**********
                    if(num1_value == ran1)
                        {ans1 = 42;}
                    else if((num1_value == ran2) || (num1_value == ran3) || (num1_value == ran4))
                        {ans1 = 94;}
                    else
                        {ans1 = 32;}
                    //**********NUM2_VALUE CHECK**********
                    if(num2_value == ran2)
                        {ans2 = 42;}
                    else if((num2_value == ran1) || (num2_value == ran3) || (num2_value == ran4))
                        {ans2 = 94;}
                    else
                        {ans2 = 32;}
                    //*********NUM3_VALUE CHECK**********
                    if(num3_value == ran3)
                        {ans3 = 42;}
                    else if((num3_value == ran2) || (num3_value == ran1) || (num3_value == ran4))
                        {ans3 = 94;}
                    else
                        {ans3 = 32;}
                    //*******NUM4_VALUE CHECK*******
                    if(num4_value == ran4)
                        {ans4 = 42;}
                    else if((num4_value == ran2) || (num4_value == ran3) || (num4_value == ran1))
                        {ans4 = 94;}
                    else
                        {ans4 = 32;}
                    cout<<num1_value<<num2_value<<num3_value<<num4_value<<endl;
                    cout<<ans1<<ans2<<ans3<<ans4<<endl;

                    if((num1_value == ran1) && (num2_value == ran2) && (num3_value == ran3) && (num4_value == ran4))
                    {mastermind = true;
                        cout<<"CONGRATULATIONS! You are the MASTERMIND of the Intermediate Level!!"<<endl;
                        cout<< "It took " << user_tries + 1 << " to beat the game\n";
                        cout<<"Enter your 3-Character name"<<endl;                   
                        
                        for(int i = 0; i < 3; i++)
                        {
                            cin >> initials[users_count][i];   
                        }                     
                        attempts[users_count] = user_tries + 1;
                        
                        level[users_count] = set_level;
						
					    users_count++; 
                    }
                    cout << "---------------"<<endl;
                }              
                if(mastermind == false)
        { cout << "Sorry, you didn't make the cut\n";}            
        cout << "Would you like to play Intermediate Level again? <Y/N>: ";
        cin >> replay;
        mastermind = false;
    }while((replay == 'Y') || (replay == 'y'));//while loop ending bracket
    
    cout << "THANK YOU FOR PLAYING MASTERMIND!"<<endl;
    }
    void advanced(int& users_count, char initials[][3], string set_level, string level[10], int attempts[10])
    {
        char init1,init2,init3,num1,num2,num3,ans1=32,ans2=32,ans3=32,replay;
        int ran1,ran2,ran3,num1_value,num2_value,num3_value;
        short max_tries_adv=5; 
        bool mastermind = false;
        srand(static_cast<unsigned int>(time(0)));
        
        set_level = "ADV";
        level[users_count] = set_level;
        
        do
        {
        ran1=rand()%10;
        do{ran2=rand()%10;}
        while(ran2 == ran1);
        do{ran3=rand()%10;}
        while((ran3 == ran1) || (ran3 == ran2));
        
           cout<<"***********************************"<<endl<<endl;
           cout << "-You Chose Advanced Level"<<endl;
                cout << "-You have 5 Tries, Guess a 3-Digit Number."<<endl;
                
                for(int user_tries = 0; (user_tries < max_tries_adv) && (mastermind == false); user_tries++)
                {//for loop starting bracket
                    
                    cout<<"Enter Guess " << user_tries + 1<< ": ";
                    cin>>num1>>num2>>num3;

                    cout << "\nYou Entered" << endl;

                    num1_value = num1 - 48;
                    num2_value = num2 - 48;
                    num3_value = num3 - 48;
                    //***********NUM1_VALUE CHECK***********
                    if(num1_value == ran1)
                        {ans1 = 42;}
                    else if((num1_value == ran2) || (num1_value == ran3))
                        {ans1 = 94;}
                    else
                        {ans1 = 32;}
                    //*************NUM2_VALUE CHECK********** 
                    if(num2_value == ran2)
                        {ans2 = 42;}
                    else if((num2_value == ran1) || (num2_value == ran3))
                        {ans2 = 94;}
                    else
                        {ans2 = 32;}
                    //************NUM3_VALUE CHECK**********
                    if(num3_value == ran3)
                        {ans3 = 42;}
                    else if((num3_value == ran2) || (num3_value == ran1))
                        {ans3 = 94;}
                    else
                        {ans3 = 32;}
                    cout<<num1_value<<num2_value<<num3_value<<endl;
                    cout<<ans1<<ans2<<ans3<<endl;

                    if((num1_value == ran1) && (num2_value == ran2) && (num3_value == ran3)){
                        mastermind = true;
                        cout<<"CONGRATULATIONS! You are the MASTERMIND of the Advanced Level!!"<<endl;
                        cout<< "It took " << user_tries + 1 << " to beat the game\n";
                        cout<<"Enter your 3-Character name"<<endl;                     
                        
                        for(int i = 0; i < 3; i++)
                        {
                            cin >> initials[users_count][i];   
                        }                    
                        attempts[users_count] = user_tries + 1;
                        
                        level[users_count] = set_level;
                        
                        users_count++;
                    } 
                    cout << "--------------\n";}
                if(mastermind == false)
        { cout << "Sorry, you didn't make the cut\n";}            
        cout << "Would you like to play Advanced Level again? <Y/N>: ";
        cin >> replay;
        mastermind = false;
        }
        while((replay == 'Y') || (replay == 'y'));//while loop ending bracket
    
    cout << "THANK YOU FOR PLAYING MASTERMIND!\n";
    cout <<"**********************************************************\n\n\n\n\n";
    }
    void def(int inN)
    {
           cout<<"You Entered "<<inN<<" to Exit the Game"<<endl;
    }
  
