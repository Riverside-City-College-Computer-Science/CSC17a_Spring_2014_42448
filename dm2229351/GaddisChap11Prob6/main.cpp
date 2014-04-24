/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on March 30, 2014, 12:39 PM
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

struct Player{
    string name;
    int number;
    int points;
};

using namespace std;

void input( Player&);
void print(Player[]);

int main(int argc, char** argv) {
    Player players[12];
    for(int i=0;i<12;i++)
    {
        cout << "Please enter data for the " << i+1 << "st player" << endl;
        input(players[i]);
    }
    print(players);

    return 0;
}

void input(Player &player)
{
        string inputname;
        int input;
        cout << "Please enter players name: " << endl;
        cin >> inputname;
        player.name=inputname;
        cout << "Please enter the players number"<< endl;
        cin >> input;
        while(input<0)
        {
            cout << "\nInvalid player number: ";
                    cin >> input;
        }
        player.number=input;
        cout << "Please points scored by player " << endl;
        cin >> input;
        while(input<0)
        {
            cout << "\nInvalid player number of points: ";
                    cin >> input;
        }
        player.points=input;
}
void print(Player players[])
{
    int high=0;
    int total=0;
    int playerhigh;
    
    for(int i=0;i<12;i++)
    {
        total+=players[i].points;
        cout << "Player: " << players[i].name << endl;
        cout << "Number: " << players[i].number << endl;
        cout << "Points scored: " << players[i].points << endl;
        if(players[i].points>high)
        {
            high=players[i].points;
            playerhigh=i;
        }
    }
    cout << "Total points earned by the team was " << total << endl;
    cout << "Highest scoring player was " << players[playerhigh].name << " #" << players[playerhigh].number
            << " with a high score of " << players[playerhigh].points << endl;
            
}