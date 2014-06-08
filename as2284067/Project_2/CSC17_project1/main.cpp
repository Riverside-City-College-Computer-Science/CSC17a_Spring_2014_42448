/* 
 * File:   main.cpp
 * Author: Abel Salazar
 * Created on April 10, 2014, 9:53 AM
 * project 2
 */

//system libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;
//global constant

struct Keno{
    //for Quick pick
    int Random;
    //Self-pick numbers
    int Self;
    //for printing 80 numbers
    int stDraw;
    //draw for the bingo draw
    int nDraw;
    int counter;
};


//function prototype
void menu(float &);
//game titles
float slotsGame(float &);
float blackJack(float &);
float craps(float &);
float keno(float &);

//helper functions

Keno sCheck(Keno [],int);
Keno rCheck(Keno [],int);
Keno sort(Keno [], int);
Keno prBin(Keno [],int);
Keno Bingo(Keno [],int);
Keno UserPic(Keno [],int);
Keno randfill(Keno [], int);
Keno PrntDat(Keno[],int);
Keno prntDat(Keno[],int);
Keno fillDat(Keno[],int);
void isHigher(int [], float &, float &);
void placeBet(float , float);
int charPCvn(int);
void secondRound(int [], int [],int , float , float );
void firstPHand(int [], int []);
void hit(int [], int [] , int [], float &);
void compHit(int [], int [], int []);
void secondHand(float &);
int firstHand(int [], int [],float &, float &, char);
int charCvn(int );
void aces(int &);
bool isPos(int, float &);
void randGen  (int [], int, int);
void prntArray(int [], int, int);
void cvn_char (int [], int, int);
void prntSpc();
bool is_Winner(int [], int);
bool ifSave();
bool isPositive(float, float);
string loadGame();
int convertString(string);
int convertNum(char);
int thouConvert(int, int);
void saveGame(float &);
int placeBet();
int prize(int);



//execution
int main(int argc, char** argv) {
    
    float m=0;
    float& money = m;
    float total;
    bool save;
    string load;
    int loadChar;
    
    srand(static_cast<unsigned short>(time(0)));
    
    prntSpc();
    cout << "Welcome to Abel's Casino!" <<endl;
    cout << "Home of the loosest slots on this side of California" <<endl;
    cout << "As a new gamer you will begin with $100 in comped chips"
            <<endl;
    save = ifSave();
    if(save == true){
        money = 100;
    }else
    {
        load = loadGame();
        loadChar = convertString(load);
        money = loadChar;
    }
    prntSpc();
    menu(money);
    cout << "You have = $" <<money<<endl;
    
    return 0;
}

//basic menu that allows the user to pick a game
void menu(float& cash){
    int choice = 0;
    cout << "Choose your game" << endl;
    cout << "1" << setw(30) << setfill('*') << "" << "Slots" <<endl;
    cout << "2" << setw(30) << setfill('-') << "" << "BlackJack" <<endl;
    cout << "3" << setw(30) << setfill('*') << "" << "Craps" <<endl;
    cout << "4" << setw(30) << setfill('-') << "" << "Keno" <<endl;
    cout << "5" << setw(30) << setfill('*') << "" << "Exit" <<endl;
    cin >> choice;
    
    switch(choice){
        case 1: slotsGame(cash);break;
        case 2: blackJack(cash);break;
        case 3: craps(cash);break;
        case 4: keno(cash);break;
        case 5: saveGame(cash);cout << "Exiting program" <<endl;break;
        default: cout << "<Error> invalid entry" <<endl;menu(cash);break;
    }
}

//The spine of craps
float craps(float& money){
    float bet;
    int y=2; int z=3;
    bool realNum;
    int SIZE = 50;
    int dice[SIZE];
    int x = 6;
    char decision = 'y';
    int round1=0, round2=0;
    prntSpc();
    cout << "Hello welcome to craps" << endl;
    cout << "In this game you roll 2 die and if your first roll is a 7 or 11"
            << endl << "You win! " << "If you roll a 2, 3, or a 12, you lose "
            << endl << "automatically. If you roll any other number you try to"
            << endl << "roll it again in the second round." <<endl;
    cout << "BEWARE, if you roll a 7 in the second or after round you lose"
            <<endl;
    cout << endl<<endl<<endl;
    
    while(decision == 'Y' || decision == 'y'){
        cout << "Would you like to continue   ( Y / N )?" <<endl;
        cin >> decision;
        prntSpc();
        if(decision == 'Y' || decision == 'y'){
                cout << "Enter the amount of money you would like to bet." <<endl;
                cin >> bet;
                prntSpc();
                realNum = isPositive(money, bet);
    if(realNum == true){
        money -= bet;
        cout << "Your balance is = " << money <<endl;
        randGen(dice, SIZE, x);
        cout << "You have rolled" << endl << dice[0] <<" and " << dice[1] << endl;
        round1 = dice[0] + dice[1];
        cout << "Your total is " << round1 <<endl;
    if(round1 == 7 || round1 == 11){
        cout << "You win!" <<endl;
        money += bet*2;
        cout << "Your total money is = $" <<money <<endl; 
    }
    else if(round1 == 2 || round1 == 3 || round1 == 12){
        cout << "You lose" <<endl;
        cout << "Your total money is = $" <<money <<endl; 
    }
    else{
        while(round2 != round1 && round2 != 7){
        cout << "Nothing yet ...." <<endl<<endl<<endl;
        cout << "Going to next round" << endl;
        cout << "Your roll is " << dice[y] << " and " << dice[z] <<endl;
        round2 = dice[y] + dice[z];
        cout << "Your total is " << round2 <<endl;
        if(round2 == 7){
            cout << "You have lost" <<endl;
            cout << "Your total money is = $" <<money <<endl;
            round2 = round1;
        }else if(round2 == round1){
            cout << "You have won" <<endl;
            money += bet*2;
            cout << "Your total money is = $" <<money <<endl; 
        }
        else{
            cout << "Nothing yet ...." <<endl;
            cout << "Your total money is = $" <<money <<endl; 
        }
        y+=2;
        z+=2;
        }
    }
        }else if(decision == 'N' || decision == 'n'){
                //return money;
                menu(money);
        }
        else{
            cout << "<Error> invalid entry" <<endl;
            craps(money);
        }
        }else{
            cout << "Error, invalid entry" <<endl;
            craps(money);
        }
    }

}

//determines is the amount of money the user has is greater than 0
//It makes sure the user is not betting more than they have
bool isPositive(float money, float bet){
    if(bet < money && bet > 0){
        return true;
    }else{
        return false;
    }
}

//Basic skeleton for black jack
float blackJack(float& money){
    int SIZE = 4;
    int x = 13;
    int cards[SIZE];
    int startHand[SIZE];
    int hitArray[x];
    char decision = 'y', choice;
    float bet = 0;
    prntSpc();
    cout << "Welcome to blackjack" <<endl;
    cout << "You will be playing a private match against a bot" <<endl;
    cout << "You currently have $" << money<<endl;
    while(decision == 'y' || decision == 'y'){
    cout << "Would you like to continue? ( Y / N )?" <<endl;
    cin >> decision;
    if(decision == 'y' || decision == 'y'){
    randGen(startHand, SIZE, x);
    firstHand(startHand, cards, money, bet, decision);
    hit(startHand, cards, hitArray, money);
    if(cards[1] <= 21){
        compHit(startHand, cards, hitArray);
        isHigher(cards, money, bet);
    }else{
        cout << "Player busts" <<endl;
    }
    }else if(decision == 'N' || decision == 'n'){
        menu(money);
    }else
    {
        cout << "Error, invalid entry"<<endl;
        blackJack(money);
    }    
    }
}

//the basic skeleton for the slot machine game
float slotsGame(float& money){
    int SIZE = 9;
    int array[SIZE];
    int brray[SIZE];
    int x = 6;
    int y = 3;
    bool winner;
    string load;
    int loadChar, bet;
    char decision = 'y';
    while(decision == 'Y' || decision == 'y'){
        if(money > 0){
        cout << "Would you like to continue? ( Y / N )?";
        cin >> decision;
        prntSpc();
        if(decision == 'Y' || decision == 'y'){
        //generates random numbers for array
        bet = placeBet();
        cout << "Bet is " << bet <<endl;
        randGen(array, SIZE, x);
         //prints numbers for my testing
        //prntArray(array, SIZE, y);
        //prints random chars in template
        prntSpc();
        
        //uses a dummy array to fill in screen so it looks like it is moving
        for(int s = 0; s < 300; s++){
                prntSpc();
                randGen(brray, SIZE, x);
                cvn_char(brray, SIZE, 3);
        }
        //prints actual characters that will be used
        prntSpc();
        cout << "DING     DING     DING" <<endl<<endl<<endl;
        cvn_char(array, SIZE, 3);
        winner = is_Winner(array, SIZE);
        if(winner == true){
            int cash;
            //adds bet times modifier to money
            cash = prize(bet);
            money += cash;
            cout << "You're a winner" <<endl;
            cout << "     (^-^)     "<<endl;
            cout << "Your balance is $" << fixed << showpoint << setprecision(2)
                    << money <<endl;
            cout <<endl;
        }//takes bet amount from money
        else{
            money -= bet;
            cout << "You have lost" <<endl;
            cout << "    (-_-)    " <<endl;
            cout << "Your balance is $" << fixed << showpoint << setprecision(2)
                    << money <<endl;
            cout <<endl;
        }
        }
        else if(decision == 'N' || decision == 'n'){
            menu(money);
        }
        
        else{
            cout << "Terminating program" <<endl;
        }
        //ends program if you run out of money
        }else{
            decision = 'N';
        cout << "You have run out of money" <<endl;
        cout << "      (/^-^)/      " <<endl;
        cout << "THANKS FOR PLAYING " <<endl;
    }
    }
}

//holds the template for Keno
float keno(float & money){
    const int SIZE = 80;
    Keno Draw[SIZE];
    const int size = 8;
    int choice;
    int bet = 10;
    
    if(money <=0){
        cout<< "You have run out of money "<<endl;
        menu(money);
    }
    
    cout << "Keno is by having a random drawing of 80 numbers" <<endl;
    cout << "Each round the user can either pick 8 numbers or buy a quick pick"
            <<endl<< "which chooses 8 random numbers. To win you have to get at"
            " least 1 number"<<endl<<"correctly. Higher amounts of correct "
            "numbers increases the pay-outs" <<endl;
    
    cout << "Would you like to buy a quick pick or choose your own numbers?"
            <<endl;
    cout<<endl<<endl<<endl;
    cout << "enter the number 1 for: Quick Pick" <<endl;
    cout << "enter the number 2 for: Self Pick" <<endl;
    cout << "enter the number 3 for: main menu" <<endl;
    cin>>choice;
    
    fillDat(Draw,SIZE);
    prntDat(Draw,SIZE);
    
    Bingo(Draw,size);
    
    switch(choice){
        case 1: randfill(Draw,size);
                rCheck(Draw,size);
                break;
        case 2: UserPic(Draw,size);
                sCheck(Draw,size);
                break;
        case 3: menu(money);        
        default: cout << "<Error> invalid entry" << endl;break;
    }
    //fills in winning numbers with 0 to show them in a grid
    for(int i=0;i<SIZE;i++){
            for(int j=0;j<size;j++){
                if(Draw[i].stDraw == Draw[j].nDraw ){
                    Draw[i].stDraw=0;
                }
            }
        }
    money -= bet;
    prntDat(Draw,SIZE);
    sort(Draw,size);
    prBin(Draw,size);
    cout<<endl;
    
    cout<<"You got "<<Draw[0].counter<<" of them correct"<<endl;
    bet = bet * Draw[0].counter * 2;
    money+=bet;
    cout << "You have a total of " << money << " money"<<endl;
    keno(money);
}

//Checks if the self pick numbers are the same as the winning numbers
//it counts how many wins if there are any
Keno sCheck(Keno Draw[], int size){
    int count = 0;
    for(int i=0;i<size;i++){
        for(int j=0;j<i;j++){
            if( Draw[i].nDraw == Draw[j].Self){
                count++;
            }
        }
    }
    Draw[0].counter =count;
}

//Checks if the random numbers are the same as the winning numbers
//it counts how many wins if there are any
Keno rCheck(Keno Draw[], int size){
    int count = 0;
    for(int i=0;i<size;i++){
        for(int j=0;j<i;j++){
            if( Draw[i].nDraw == Draw[j].Random){
                count++;
            }
        }
    }
    Draw[0].counter =count;
}

//sorts the winning numbers from smallest to largest
Keno sort(Keno Draw[],int size){
    int temp;
    for(int i=0;i<size;i++){
        for(int j=0;j<i+1;j++){
            if(Draw[i].nDraw < Draw[j].nDraw){
                temp = Draw[i].nDraw;
                Draw[i].nDraw = Draw[j].nDraw;
                Draw[j].nDraw = temp;
            }
        }
    }
}

//prints out the winning numbers
Keno prBin(Keno Draw[], int size){
    cout<<endl<<endl;
    for(int i=0;i<size;i++){
        cout<<Draw[i].nDraw <<" ";
    }
    cout<<endl<<endl;
}

//randomly chooses winning numbers between 1 and 80
Keno Bingo(Keno Draw[],int size){
    for(int i=0;i<size;i++){
        Draw[i].nDraw=rand()%80+1;
    }
}

//Gets the users input for 8 values between 1 and 80
//It error checks the numbers until the values of the 8 numbers are correct
Keno UserPic(Keno Draw[], int size){
    cout<<"Enter 8 numbers between 1 and 80"<<endl;
    int count = 0;
    do{
        cout << "Enter number " << count <<endl;
        cin>> Draw[count].Self;
        if(Draw[count].Self > 0 && Draw[count].Self < 81){
            count++;
        }else{
            cout<<"Enter a number that is between 1 and 80!!" <<endl;
        }
    }while(count != 8);
}

//Prints the Quick pick numbers
Keno PrntDat(Keno Draw[],int size){
    cout<<endl<<endl;
    for(int i=0;i<size;i++){
        cout<<setw(2)<<setfill(' ')<<Draw[i].Random <<" ";
    }
    cout<<endl<<endl;
}

//Randomly fills 8 slots with random values
Keno randfill(Keno Draw[], int size){
    for(int i=0;i<size;i++){
        Draw[i].Random=rand()%80+1;
    }
    cout<<"Your quick pick numbers" <<endl; 
    PrntDat(Draw,size);
    
}

//Prints the 80 integers in rows of 10
Keno prntDat(Keno Draw[], int SIZE){
    cout<<endl<<endl;
    for(int i=0;i<SIZE;i++){
        cout<<setw(2)<<setfill(' ')<<Draw[i].stDraw<<" ";
        if(i%10==10-1)cout<<endl;
    }
    cout<<endl<<endl;
}

//Fills an array with numbers 1-80 in sequential order
Keno fillDat(Keno Draw[], int SIZE){
    for(int i=0;i<SIZE;i++){
        Draw[i].stDraw = i+1;
    }
}

//Determines while total hand is higher and then returns the amount of winnings
//the user gets if the user did in fact win.
void isHigher(int b[], float & money, float & bet){
    if(b[1] > b[0] && b[1] <= 21){
        cout << "You are the WINNER!" <<endl;
        cout << "You have won $" << bet*2 <<endl;
        money += bet * 2 ;
        cout << "Your new total is $" << money<<endl;
    }else if(b[1] == b[0] && b[1] <= 21){
        cout << "You push" <<endl;
        cout << "Your bet has been returned to you" <<endl;
        money += bet;
        cout << "Your new total is $"<<money<<endl;
    }else if(b[1] < b[0] && b[0] <=21){
        cout << "You have lost" <<endl;
        cout << "Your total is $" << money<<endl;
    }else if (b[0] > 21 && b[1] < 21){
        cout << "You win" << bet * 2 <<endl;
        money += bet;
        cout << "Your new total is $" << money <<endl;
    }else{
        cout <<endl;
    }
}

//Determines weather the computer will add more cards to its hand
void compHit(int a[], int b[], int c[]){
    int size = 20;
    int x = 13;
    int i = 0;
    randGen(c, size, x);
    while(b[0] < 17){
        cout << "The dealer draws a " <<charCvn(c[i])<<endl;
        b[0]+=c[i];
        i++;
        cout << "The dealers total is now " <<b[0]<<endl;
        if(b[0] > 21){
            cout << "The dealer Busts" <<endl;
            
        }
        }
}

//Gives the user the option to hit
//Hit adds a random number to the hand he currently has
//If the total is higher than 21 the function stops looping
void hit(int a[], int b[], int hit[],float & money){
    char choice = 'y';
    int x = 13;
    int size = 20;
    int i = 1;
    randGen(hit, size, x);
    while(b[1] < 21 && choice == 'y' || choice == 'Y'){
        cout << "You you like to hit?" <<endl;
        cin >> choice;
        if(choice == 'y' || choice == 'Y'){
            b[1] += hit[i];
            cout << "Your card is " << charCvn(hit[i]) <<endl;
            i++;
            cout << "New total is " << b[1] <<endl;
            if(b[1] > 21){
                cout << "You have lost" <<endl;
            }
        }else if(choice == 'N' || choice == 'n'){
            cout << "You have decided to stand"<<endl;
        }else {
            cout << "Error invalid entry" <<endl;
        }
    }
    
}

//gets users input for the amount they would like to bet
//It then subtracts it from the total amount of money the user has
void placeBet(float money, float bet){
    cout << "How much would you like to bet?" << endl;
    cin >> bet;
    money -= bet;
}


//returns the value of the actual character
int charCvn(int num){
    int newNum;
    switch(num){
        case 1 : cout <<"A "<<endl;aces(num);return num;break;
        case 2 : cout <<"2 "<<endl;newNum=2;return newNum;break;
        case 3 : cout <<"3 "<<endl;newNum=3;return newNum;break;
        case 4 : cout <<"4 "<<endl;newNum=4;return newNum;break;
        case 5 : cout <<"5 "<<endl;newNum=5;return newNum;break;
        case 6 : cout <<"6 "<<endl;newNum=6;return newNum;break;
        case 7 : cout <<"7 "<<endl;newNum=7;return newNum;break;
        case 8 : cout <<"8 "<<endl;newNum=8;return newNum;break;
        case 9 : cout <<"9 "<<endl;newNum=9;return newNum;break;
        case 10: cout <<"10"<<endl;newNum=10;return newNum;break;
        case 11: cout <<"J "<<endl;newNum=10;return newNum;break;
        case 12: cout <<"Q "<<endl;newNum=10;return newNum;break;
        case 13: cout <<"K "<<endl;newNum=10;return newNum;break;
        default:charCvn(newNum);break;
        //return newNum;
    }
}

//takes a number and outputs the corresponding value.
int charPCvn(int num){
    switch(num){
        case 1 : cout <<"A "<<endl;break;
        case 2 : cout <<"2 "<<endl;break;
        case 3 : cout <<"3 "<<endl;break;
        case 4 : cout <<"4 "<<endl;break;
        case 5 : cout <<"5 "<<endl;break;
        case 6 : cout <<"6 "<<endl;break;
        case 7 : cout <<"7 "<<endl;break;
        case 8 : cout <<"8 "<<endl;break;
        case 9 : cout <<"9 "<<endl;break;
        case 10: cout <<"10"<<endl;break;
        case 11: cout <<"J "<<endl;break;
        case 12: cout <<"Q "<<endl;break;
        case 13: cout <<"K "<<endl;break;
        default:charPCvn(num);break;
        //return newNum;
    }
}

//determines weather the use would like to continue or fold
void secondRound(int a[], int b[], int size , float bet, float money){
    char decision;
    cout << "Would you like to raise, call or fold?" <<endl;
    cout << "In the format" <<endl;
    cout << "r = raise"<<endl<<"c = call"<<endl<<"f = fold"<<endl;
    cin >> decision;
    if(decision == 'R' || decision == 'r'){
        cout << "How much would you like to raise?" <<endl;
        cin >> bet;
        money -= bet;
        
    }else if(decision == 'C' || decision == 'c'){
        cout << "The dealer calls" <<endl;
        }
    else if(decision == 'F' || decision == 'f'){
        cout << ";You have folded" <<endl;
    }
    else{
        cout << "Error invalid entry" <<endl;
    }
}


//deals out the first hand of the user in black jack
int firstHand(int a[], int b[], float & money, float & bet,char decision){
    
    if(decision == 'y' || 'Y'){
    prntSpc();
    cout << "Place your initial bet, remember to keep it below your total cash"
            <<endl;
    cin >> bet;
    if(bet < money && bet > 0){
    money -=bet;
    prntSpc();
    cout << "Your hand is " <<endl;
        a[0]=charCvn(a[0]);
        a[1]=charCvn(a[1]);
        b[1]=a[0]+a[1];
        cout << "For a total of" << b[1]<<endl;
    cout<<endl<<endl<<endl;
    cout << "The dealers hand is "<<endl;
    
        a[2]=charCvn(a[2]);
        a[3]=charCvn(a[3]);
        b[0]=a[2]+a[3];
        cout << "For a total of" << b[0]<<endl;
    cout <<endl<<endl<<endl;
    
    }else if(decision == 'N' || decision == 'n'){
        menu(money);
    }else{
        cout << "Error, invalid entry" <<endl;
        blackJack(money);
    }
    }else{
        cout << "You have made an invalid bet" <<endl;
    }
}

//allows user to choose between a hard or soft ace
void aces(int & num){
    char choice;
    cout << "Would you like to make the A a hard or soft ace?"<<endl;
    cout << "Hard is 11 --- enter 'H' for hard" <<endl;
    cout << "Soft is 1  --- enter 'S' for soft" <<endl;
    cin >> choice;
    if(choice == 'H' || choice == 'h'){
        num = 11;
    }else if(choice == 'S' || choice == 's'){
        num = 1;
    }else{
        cout << "Invalid entry" <<endl; aces(num);
    }
}

//determines if the amount of money the user has is positive
bool isPos(int cash, float& money){
    if(cash > 0 && cash < money)return true;
    else return false;
}

//used to modify the initial bet for the money to be paid out
int prize(int bet){
    int total = bet *4;
    return total;
}


int placeBet(){
    int bet, tot;
    cout << "Enter 1, 2 or 3 for the bet you would like to make" <<endl;
    cout << "1 for " << fixed << setw(30) << setfill('*') << " " << "$1.00\n";
    cout << "2 for " << fixed << setw(30) << setfill('*') << " " << "$5.00\n";
    cout << "3 for " << fixed << setw(30) << setfill('*') << " " << "$25.00\n";
    cout << "Bets are modified by 4 when you win" <<endl;
    cin >> bet;
    switch(bet){
        case 1: tot = 1; return tot;
            break;
        case 2: tot = 5; return tot;
            break;
        case 3: tot = 25; return tot;
            break;
        default: cout << "<Error> invalid number" <<endl; placeBet();
            break;
    }
    
 }

//determines victory
bool is_Winner(int a[], int SIZE){
    bool winner;
    //horizontal
    if(a[0] == a[1] && a[1] == a[2]){
        winner = true;
    }else if(a[3] == a[4] && a[4] == a[5]){
        winner = true;
    }else if(a[6] == a[7] && a[7] == a[8]){
        winner = true;
    //vertical    
    }else if(a[0] == a[3] && a[3] == a[6]){
        winner = true;
    }else if(a[1] == a[4] && a[4] == a[7]){
        winner = true;
    }else if(a[2] == a[5] && a[5] == a[8]){
        winner = true;
    }else{
        winner = false;
    }
    return winner;
}

//pushes old code out of the way
void prntSpc(){
    for(int j = 0; j < 25; j++){
        cout <<endl;
    }
}

//takes ints and outputs characters in their place
void cvn_char(int a[], int SIZE, int n){
    for(int i = 0; i < SIZE; i++){
        if(a[i] == 1){
            cout << " * " << 'A' << " * ";
            if(i%3 == n-1)cout <<endl <<endl;
        }else if(a[i] == 2){
            cout << " * " << 'B' << " * ";
            if(i%3 == n-1)cout<<endl<<endl;
        }else if(a[i] == 3){
            cout<< " * "  << 'C' << " * ";
            if(i%3 == n-1)cout<<endl<<endl;
        }else if(a[i] == 4){
            cout<< " * "  << 'D' << " * ";
            if(i%3 == n-1)cout<<endl<<endl;
        }else if(a[i] == 5){
            cout<< " * "  << 'E' << " * ";
            if(i%3 == n-1)cout<<endl<<endl;
        }else{
            cout<< " * "  << 'F' << " * ";
            if(i%3 == n-1)cout<<endl<<endl;
        }
}
}

//uses array and size to print out a screen more pleasing to the user
void prntArray(long a[], int SIZE, int n){
    cout <<endl;
    for(int i = 0; i < SIZE; i++){
        cout << left << setw(2)<< a[i] << " ";
        if(i%3 == n-1)cout <<endl;
    }
    cout <<endl;
}


//generates values to populate array
void randGen(int  a[], int SIZE, int x){
    int i = 0;
    do{
        a[i] = rand()%x + 1;
        i++;
    }while(i < SIZE);
}

//determines whether to start a new game or to use value from saved game
bool ifSave(){
    int save;
    cout << "Would you like to start a new game?" <<endl;
    cout << "Enter 1 for " << setw(15) << setfill('-') <<""<<"NEW GAME" <<endl;
    cout << "Enter 2 for " << setw(15) << setfill('-') <<""<<
            "CONTINUE SAVED GAME" <<endl;
    cin >> save;
    switch(save){
        case 1: return true;
            break;
        case 2: return false;
            break;
        default: cout << "<Error> Invalid input" <<endl;
            break;
    }
}

//reads in from file "saved_game.txt
string loadGame(){
    string line;
    ifstream savefile("saved_game.txt");
    getline(savefile, line);
    //cout << line <<endl;
    return line;
}

// converts string from saved file for money
// maximum size for money is 500,000
// uses input from main function
// takes string from "saved_game.txt" and finds it size
// once it has the size it reads each value and puts it into char array
// uses the array and calls converter function to assign an int to each value
// calls thousands function to assign its full value
// it is then added together
int convertString(string number){
    int SIZE = 10;
    char array[SIZE];
    int totSIZE = 500000;
    int total[totSIZE];
    int tot = 0;
    
    int size, num, thousands, count = 0;
    size = number.size();
    count = size;
    for(int i = 0; i < size; i++){
        count--;
        array[i] = number[i];
        //cout << array[i];
        num = convertNum(array[i]);
        //cout << num << endl;
        thousands = thouConvert(num, count);
        //cout << "Thousands conversion = " << thousands << endl;
        tot += thousands;
    }
    cout << "You have a total of $" << tot << " in your saved game!" <<endl;
    return tot;
}

//used to conver characters from input string to ints
int convertNum(char load){
    int num = 0;
    switch(load){
        case '0':
            num = 0;
            return num;
            break;
        case '1':
            num = 1;
            return num;
            break;
        case '2':
            num = 2;
            return num;
            break;
        case '3':
            num = 3;
            return num;
            break;
        case '4':
            num = 4;
            return num;
            break;
        case '5':
            num = 5;
            return num;
            break;
        case '6':
            num = 6;
            return num;
            break;
        case '7':
            num = 7;
            return num;
            break;
        case '8':
            num = 8;
            return num;
            break;
        case '9':
            num = 9;
            return num;
            break;
    }
}
// takes 10 and uses count - n as a power.
//multiplies the amount by each integer
int thouConvert(int number, int size){
    int tot;
    tot = number * (pow(10, size));
    return tot;
}

//takes in global variable
//saves to saved_game.txt
//closes file
void saveGame(float& money){
    cout << "Would you like to save your game?  ( Y / N )?" <<endl;
            char choice;
            cin >> choice;
            if(choice == 'Y' || choice == 'y'){
                ofstream myfile("saved_game.txt");
                if(myfile.is_open()){
                        myfile << money;
                        myfile.close();
                        cout << "Your game has been saved" <<endl;
                }else cout << "Unable to open file";
            }else{
                cout << endl;
            }
}
