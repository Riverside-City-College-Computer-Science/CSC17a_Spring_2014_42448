/* 
 * File:   main.cpp
 * Author: Kamron Golbaf
 *Project1
 * Created on April 17, 2014, 1:42 PM
 */
 
using namespace std;

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <vector>

//the struct is an organized form of the data for a user who finishes the game
struct high_scores
{
	char initials[3];
	string level;
	int attempts;
};

void Menu();
int getN();
void def(int);
void beginner(int& users_count, vector<high_scores> &player_list, string set_level, bool matched_choice[10], int& num_games);
void intermediate(int& users_count, vector<high_scores> &player_list, string set_level, bool matched_choice[10], int& num_games);
void advanced(int& users_count, vector<high_scores> &player_list, string set_level, bool matched_choice[10], int& num_games);
void highscores(vector<high_scores> &player_list, int num_games);
void fillscores(vector<high_scores> &player_list, int num_games, fstream& to_file);

//marks if the user's current guess has already been used and works in conjunction
//with another piece of code to display which numbers have not been picked
//If the user guesses the number 1, the the number is marked as already used
//and will not be shown under the "Numbers not tried" list of the CURRENT game
void check_matches(int number, bool matched_choice[10]);

//saves the scores from the current game to a file for later use
void save_scores(vector<high_scores> &player_list, fstream& to_file, int num_games);

//displays the scores saved to a file from previous games
void view_saved_scores(vector<high_scores> &player_list, fstream& to_file);

int main(int argv,char *argc[])
{
    string set_level;
    int users_count = 0;       
    string directions;
	int inN, num_games = 0;
	bool matched_choice[10];
	vector<high_scores> player_list;
	fstream to_file;
	
	//opens up notepad to display the instructions
    system("notepad.exe directions.txt");
	
	do{
    	cout << "How many games would you like to play?: ";
    	cin >> num_games;
	}while(num_games <= 0);
	
	player_list.resize(num_games);
	fillscores(player_list, num_games, to_file);
    	
	do{	
		Menu();
		
		inN=getN();
		
		switch(inN)
		{
			case 1:
					beginner(users_count, player_list, set_level, matched_choice, num_games);
					break;
						
			case 2:
					intermediate(users_count, player_list, set_level, matched_choice, num_games);
					break;
						
			case 3:	
					advanced(users_count, player_list, set_level, matched_choice, num_games);
					break;
						
			case 4:
					highscores(player_list, num_games);
					break;
						
			case 5:
					view_saved_scores(player_list, to_file);
					break;
						
			default:
					def(inN);
		}
	}while(inN<6);
	        
    save_scores(player_list, to_file, num_games);
	
    system("PAUSE");
    return EXIT_SUCCESS;
}
    
void Menu()
{
        cout <<"\n***************************************\n";
        cout<<"\tWelcome to MASTERMIND!"<<endl;
        cout<<"****************************************"<<endl;
        cout<<"-Type 1 For Beginner Level"<<endl;
        cout<<"-Type 2 For Intermediate Level"<<endl;
        cout<<"-Type 3 For Advanced Level"<<endl;
        cout<<"-Type 4 For Current High Scores"<<endl;
        cout<<"-Type 5 For Past High Scores"<<endl;
        cout<<"-Type 6 To Exit Game"<<endl;
}

int getN()
{
       int inN;
       cout << "\nYour selection?: ";
	   cin>>inN;
       return inN;
}
    
void fillscores(vector<high_scores> &player_list, int num_games, fstream& to_file)
{
    for(int i = 0; i < num_games; i++)
    {
        player_list[i].level = "000";
        player_list[i].attempts = 0;
        
        for(int j = 0; j < 3; j++)
        {
             player_list[i].initials[j] = '0';   
        }
	}
}
    
void highscores(vector<high_scores> &player_list, int num_games)
{
    cout << setw(25) << "TOP " << num_games - 1 << " SCORES\n";
    cout << setw(10) << "PLAYER" << setw(10) << "LEVEL" << setw(10) << "TRIES\n";
    
    for(int i = 0; i < num_games; i++)
    {
        cout << setw(6);
        
        for(int j = 0; j < 3; j++)
        {
            cout << player_list[i].initials[j];
        }
        
        cout << setw(11) << player_list[i].level << setw(8) << player_list[i].attempts << endl;   
    }    
}   
    
void beginner(int& users_count, vector<high_scores> &player_list, string set_level, bool matched_choice[], int& num_games)
{ 
    char init1,init2,init3,num1,num2,num3,ans1=32,ans2=32,ans3=32,replay;
    int ran1,ran2,ran3,num1_value,num2_value,num3_value;
    short max_tries_beg=10; 
    bool mastermind = false;        
    
    set_level = "BEG";
    srand(static_cast<unsigned int>(time(0)));
    
    do
    {
    	//adds more games if the user plays more games than they entered when the program started
		if(users_count == num_games)
		{
			player_list.resize(num_games + 1);
			
			num_games++;
		}
        
        //this resets the "Numbers Not Tried" portion for each new game played
        for(int i = 0; i < 10; i++)
        {
        	matched_choice[i] = false;
        }
        
        ran1=rand()%10;
        
        do
		{
			ran2=rand()%10;
		}while(ran2 == ran1);
		
        do
		{
			ran3=rand()%10;
		}while((ran3 == ran1) || (ran3 == ran2));
    
        cout<<"************************************"<<endl<<endl;
        cout << "-You Chose Beginner Level"<<endl;
        cout << "-You have 10 Tries, Guess a 3-Digit Number."<<endl;
                
        for(int user_tries = 0; (user_tries < max_tries_beg) && (mastermind == false); user_tries++)
        {//for loop starting bracket
        
        
        	//the next cout and for loop show the numbers that have not been used this game
			cout << "\n\tNumbers that have not been tried: ";
			
			for(int i = 0; i < 10; i++)
			{
				if(matched_choice[i] == false)
				{
					cout << i;
				}
				
				else
				{
					cout << "";
				}
			}
            
            cout<<"\nEnter Guess " << user_tries + 1<< ": ";
            cin>>num1>>num2>>num3;
			
            cout << "\nYou Entered" << endl;

            num1_value = num1 - 48;
            num2_value = num2 - 48;
            num3_value = num3 - 48;
            
            //marks the numbers as used so that they are not displayed
			//for the "Numbers not tried" portion of the game
            check_matches(num1_value, matched_choice);
            check_matches(num2_value, matched_choice);
            check_matches(num3_value, matched_choice);
            
            //***********NUM1_VALUE CHECK***********
            if(num1_value == ran1)
            {
				ans1 = 42;
			}
			
            else if((num1_value == ran2) || (num1_value == ran3))
            {
				ans1 = 94;
			}
			
            else
            {
				ans1 = 32;
			}
                
            //*************NUM2_VALUE CHECK********** 
            if(num2_value == ran2)
			{
				ans2 = 42;
			}
                
            else if((num2_value == ran1) || (num2_value == ran3))
            {
				ans2 = 94;
			}
                
            else
            {
				ans2 = 32;
			}
                
            //************NUM3_VALUE CHECK**********
            if(num3_value == ran3)
            {
				ans3 = 42;
			}
			
            else if((num3_value == ran2) || (num3_value == ran1))
            {
				ans3 = 94;
			}
                
            else
            {
				ans3 = 32;
			}
                
            cout<<num1_value<<num2_value<<num3_value<<endl;
            cout<<ans1<<ans2<<ans3<<endl;

            if((num1_value == ran1) && (num2_value == ran2) && (num3_value == ran3))
			{
                mastermind = true;
                
                cout << "--------------\n";
                cout<<"\t*****CONGRATULATIONS!*****\n\tYou are the MASTERMIND of the Beginner Level!!"<<endl;
                cout<< "It took " << user_tries + 1 << " tries to beat the game\n";
                cout<<"Enter your 3-Character name"<<endl;
                                        
                for(int i = 0; i < 3; i++)
                {
                    cin >> player_list[users_count].initials[i];   
                }

                player_list[users_count].attempts = user_tries + 1;
                player_list[users_count].level = set_level;
				
				users_count++;
            }
            
            cout << "--------------\n";
		}
                 
    if(mastermind == false)
    {
		cout << "Sorry, you didn't make the cut\n";}            
	    cout << "Would you like to play Beginner Level again? <Y/N>: ";
	    cin >> replay;
	    mastermind = false;
    }
    while((replay == 'Y') || (replay == 'y'));
	//while loop ending bracket

	cout << "THANK YOU FOR PLAYING MASTERMIND!"<<endl;
}//end prob1
    
void intermediate(int& users_count, vector<high_scores> &player_list, string set_level, bool matched_choice[], int& num_games)
{    	
    char init1,init2,init3,num1, num2, num3, num4,ans1 = 32,ans2 = 32,ans3 = 32,ans4 = 32, replay;
    int ran1,ran2,ran3,ran4, num1_value, num2_value, num3_value, num4_value;
    short max_tries_int = 5; 
    bool mastermind = false;
            
    set_level = "INT";
    srand(static_cast<unsigned int>(time(0)));
		
	do
	{
    	//adds more games if the user plays more games than they entered when the program started
		if(users_count == num_games)
		{
			player_list.resize(num_games + 1);
			
			num_games++;
		}
        
        //this resets the "Numbers Not Tried" portion for each new game played
        for(int i = 0; i < 10; i++)
        {
        	matched_choice[i] = false;
        }
        
        ran1=rand()%10;
        
        do
		{
			ran2=rand()%10;
		}while(ran2 == ran1);
		
        do
		{
			ran3=rand()%10;
		}while((ran3 == ran1) || (ran3 == ran2));
		
        do
		{
			ran4=rand()%10;
		}while((ran4 == ran1) || (ran4 == ran2) || (ran4 == ran3));
        
        cout<<"**************************************"<<endl<<endl;
        cout << "-You Chose Intermediate Level"<<endl;
        cout << "-You have 5 Tries, Guess a 4-Digit Number"<<endl;
                               
        for(int user_tries = 0; (user_tries < max_tries_int) && (mastermind == false); user_tries++)
        {//for loop starting bracket
        
        	//the next cout and for loop show the numbers that have not been used this game
			cout << "\n\tNumbers that have not been tried: ";
			
			//Displays the numbers that have not been picked yet
			for(int i = 0; i < 10; i++)
			{
				if(matched_choice[i] == false)
				{
					cout << i;
				}
				
				else
				{
					cout << "";
				}
			}
	
	        cout<<"\nEnter Guess " << user_tries + 1<< ": ";
	        cin>>num1>>num2>>num3>>num4;
	
	        cout << "You Entered" << endl;

            num1_value = num1 - 48;
            num2_value = num2 - 48;
            num3_value = num3 - 48;
            num4_value = num4 - 48;
            
            //marks the numbers as used so that they are not displayed
			//for the "Numbers not tried" portion of the game
            check_matches(num1_value, matched_choice);
            check_matches(num2_value, matched_choice);
            check_matches(num3_value, matched_choice);
            check_matches(num4_value, matched_choice);

            //**********NUM1_VALUE CHECK**********
            if(num1_value == ran1)
            {
				ans1 = 42;
			}
                
            else if((num1_value == ran2) || (num1_value == ran3) || (num1_value == ran4))
            {
				ans1 = 94;
			}
			
            else
            {
				ans1 = 32;
			}
                        
	        //**********NUM2_VALUE CHECK**********
	        if(num2_value == ran2)
	        {
				ans2 = 42;
			}
	            
	        else if((num2_value == ran1) || (num2_value == ran3) || (num2_value == ran4))
	        {
				ans2 = 94;
			}
	            
	        else
	        {
				ans2 = 32;
			}
	            
	        //*********NUM3_VALUE CHECK**********
	        if(num3_value == ran3)
	        {
				ans3 = 42;
			}
			
	        else if((num3_value == ran2) || (num3_value == ran1) || (num3_value == ran4))
	        {
				ans3 = 94;
			}
	            
	        else
	        {
				ans3 = 32;
			}
	            
	        //*******NUM4_VALUE CHECK*******
	        if(num4_value == ran4)
	        {
				ans4 = 42;
			}
	            
	        else if((num4_value == ran2) || (num4_value == ran3) || (num4_value == ran1))
	        {
				ans4 = 94;
			}
	            
	        else
	        {
				ans4 = 32;
			}
			
	        cout<<num1_value<<num2_value<<num3_value<<num4_value<<endl;
	        cout<<ans1<<ans2<<ans3<<ans4<<endl;

            if((num1_value == ran1) && (num2_value == ran2) && (num3_value == ran3) && (num4_value == ran4))
            {
			    mastermind = true;
			    
			    cout << "---------------"<<endl;
                cout<<"\t*****CONGRATULATIONS!*****\n\tYou are the MASTERMIND of the Intermediate Level!!"<<endl;
                cout<< "It took " << user_tries + 1 << " tries to beat the game\n";
                cout<<"Enter your 3-Character name"<<endl;                   
                
                for(int i = 0; i < 3; i++)
                {
                    cin >> player_list[users_count].initials[i];   
                }
				         
                player_list[users_count].attempts = user_tries + 1;
                player_list[users_count].level = set_level;
                
				users_count++;
            }
            
            cout << "---------------"<<endl;
        }
        
        if(mastermind == false)
        {
			cout << "Sorry, you didn't make the cut\n";
		}
		           
        cout << "Would you like to play Intermediate Level again? <Y/N>: ";
        cin >> replay;
        
        mastermind = false;
    }while((replay == 'Y') || (replay == 'y'));
	//while loop ending bracket

    cout << "THANK YOU FOR PLAYING MASTERMIND!"<<endl;
}
	
void advanced(int& users_count, vector<high_scores> &player_list, string set_level, bool matched_choice[], int& num_games)
{
    char init1,init2,init3,num1,num2,num3,ans1=32,ans2=32,ans3=32,replay;
    int ran1,ran2,ran3,num1_value,num2_value,num3_value;
    short max_tries_adv=5; 
    bool mastermind = false;
    
    set_level = "ADV";
    srand(static_cast<unsigned int>(time(0)));
    
    do
    {
    	//adds more games if the user plays more games than they entered when the program started
		if(users_count == num_games)
		{
			player_list.resize(num_games + 1);
			
			num_games++;
		}
        
        //this resets the "Numbers Not Tried" portion for each new game played
        for(int i = 0; i < 10; i++)
        {
        	matched_choice[i] = false;
        }
        ran1=rand()%10;
    
        do
		{
			ran2=rand()%10;
		}while(ran2 == ran1);
		
        do
		{
			ran3=rand()%10;
		}while((ran3 == ran1) || (ran3 == ran2));
        
		cout<<"***********************************"<<endl<<endl;
		cout << "-You Chose Advanced Level"<<endl;
		cout << "-You have 5 Tries, Guess a 3-Digit Number."<<endl;
	                
        for(int user_tries = 0; (user_tries < max_tries_adv) && (mastermind == false); user_tries++)
        {//for loop starting bracket
        
        	//the next cout and for loop show the numbers that have not been used this game
			cout << "\n\tNumbers that have not been tried: ";
					
			for(int i = 0; i < 10; i++)
			{
				if(matched_choice[i] == false)
				{
					cout << i;
				}
				
				else
				{
					cout << "";
				}
			}
	
            cout<<"\nEnter Guess " << user_tries + 1<< ": ";
            cin>>num1>>num2>>num3;

            cout << "\nYou Entered" << endl;

            num1_value = num1 - 48;
            num2_value = num2 - 48;
            num3_value = num3 - 48;
            
            //marks the numbers as used so that they are not displayed
			//for the "Numbers not tried" portion of the game
            check_matches(num1_value, matched_choice);
            check_matches(num2_value, matched_choice);
            check_matches(num3_value, matched_choice);
            
            //***********NUM1_VALUE CHECK***********
            if(num1_value == ran1)
            {
				ans1 = 42;
			}
				
            else if((num1_value == ran2) || (num1_value == ran3))
            {
				ans1 = 94;
			}
	                
            else
            {
				ans1 = 32;
			}
                
            //*************NUM2_VALUE CHECK********** 
            if(num2_value == ran2)
            {
				ans2 = 42;
			}
                
            else if((num2_value == ran1) || (num2_value == ran3))
            {
				ans2 = 94;
			}
                    
            else
            {
				ans2 = 32;
			}
                
            //************NUM3_VALUE CHECK**********
            if(num3_value == ran3)
            {
				ans3 = 42;
			}
	                
            else if((num3_value == ran2) || (num3_value == ran1))
            {
				ans3 = 94;
			}
                
            else
            {
				ans3 = 32;
			}
                
            cout<<num1_value<<num2_value<<num3_value<<endl;
            cout<<ans1<<ans2<<ans3<<endl;

            if((num1_value == ran1) && (num2_value == ran2) && (num3_value == ran3))
			{
                mastermind = true;
                
                cout << "---------------"<<endl;
                cout<<"\t*****CONGRATULATIONS!*****\n\tYou are the MASTERMIND of the Advanced Level!!"<<endl;
                cout<< "It took " << user_tries + 1 << " tries to beat the game\n";
                cout<<"Enter your 3-Character name"<<endl;                     
                
                for(int i = 0; i < 3; i++)
                {
                    cin >> player_list[users_count].initials[i];   
                }
	                
                player_list[users_count].attempts = user_tries + 1;
                player_list[users_count].level = set_level;
                
                users_count++;
            } 
	            
	        cout << "--------------\n";
		}
					
        if(mastermind == false)
        {
			cout << "Sorry, you didn't make the cut\n";
		}
		
        cout << "Would you like to play Advanced Level again? <Y/N>: ";
        cin >> replay;
        
	    mastermind = false;
	}while((replay == 'Y') || (replay == 'y'));
	//while loop ending bracket
	
	cout << "THANK YOU FOR PLAYING MASTERMIND!\n";
	cout <<"**********************************************************\n\n\n\n\n";
}
    
void def(int inN)
{
	cout<<"You Entered "<<inN<<" to Exit the Game"<<endl;
}
	  
void check_matches(int number, bool matched_choice[10])
{
	//marks the number as read so it does not show up under the "Numbers Not Tried" area of the game
	for(int i = 0; i < 10; i++)
	{
		if(number == i)
		{
			matched_choice[i] = true;
		}	
	}
}

void save_scores(vector<high_scores> &player_list, fstream& to_file, int num_games)
{
	//opens the file
	to_file.open("savedHighscore.txt", ios::out | ios::app);
	
	//writes the new scores from the current game to the file and keeps the previous scores as well
	for(int i = 0; i < num_games; i++)
	{
		to_file << player_list[i].attempts << " " << player_list[i].initials[0] << " " << player_list[i].initials[1]
				<< " " << player_list[i].initials[2] << " " << player_list[i].level << endl;
	}
	
	//closes the file
	to_file.close();
}

void view_saved_scores(vector<high_scores> &player_list, fstream& to_file)
{
	char initial_1, initial_2, inital_3;
	string level;
	int attempts;
	
	//opens the file for inputting the user data to the screen
	to_file.open("savedHighscore.txt", ios::in);
	
	//writes the data column headers to the screen
	cout << setw(11) << "Attempts" << setw(11) << "Initials" << setw(8) << "Level" << endl;
	cout << "------------------------------\n";
	
	//writes all the user data in the file to the screen
	while(to_file >> attempts >> initial_1 >> initial_2 >> inital_3 >> level && (!to_file.eof()))
	{
		cout << setw(8) << attempts << setw(8) << initial_1 << initial_2
			 << inital_3 << setw(10) << level << endl;
	}
	
	//clears resets the eof flag and closes the file
	to_file.clear();
	to_file.close();
}
