//Mark E. Lehr
//October 27th, 2011
//Menu to be used for the midterm
//homework and midterm, etc....

#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;

struct movie{
        string title;
        string director;
        int release;
        int runtime;
};

struct movie2{
        string title;
        string director;
        int release;
        int runtime;
        int production;
        int revenue;
};
struct Division{
    float q1sales,q2sales,q3sales,q4sales;
    float ann_sales,avg_quart;
};
struct Weather{
    int rainfall;
    int htemp,ltemp,avgtemp;
};
struct Player{
    string name;
    int number;
    int points;
};
struct Speaker{
    string name;
    string phone;
    string speak;
    int fee;
};
enum year {January, February, March, April, May, June, July, August,
    September, October, November, December};

void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();
void problem8();
void problem9();
void problem10();
void problem11();
void problem12();
void problem13();
int count(char *);
void count1(char *);
int count2(char *);
void printmovie(movie);
void printmovie2(movie2);
void input( Division&);
void print(Division);
void input( Weather&);
void print(Weather[]);
void input( Player&);
void print(Player[]);
void printarr(Speaker []);
void printmenu();
void enterdata(Speaker &);

    int main(int argv,char *argc[])
    {
	int inN;
        do{
         Menu();
         inN=getN();
         switch(inN){
          case 1:    problem1();break;
          case 2:    problem2();break;
          case 3:    problem3();break;
          case 4:    problem4();break;
          case 5:    problem5();break;
          case 6:    problem6();break;
          case 7:    problem7();break;
          case 8:    problem8();break;
          case 9:    problem9();break;
          case 10:    problem10();break;
          case 11:    problem11();break;
          case 12:    problem12();break;
          case 13:    problem13();break;         
          default:   def(inN);}
        }while(inN<14);
        return 1;
    }
    void Menu()
    {
           cout<<"Type 1 for 10-1"<<endl;
           cout<<"Type 2 for 10-2"<<endl;
           cout<<"Type 3 for 10-3"<<endl;
           cout<<"Type 4 for 11-1"<<endl;
           cout<<"Type 5 for 11-2"<<endl;
           cout<<"Type 6 for 11-3"<<endl;
           cout<<"Type 7 for 11-4"<<endl;
           cout<<"Type 8 for 11-5"<<endl;
           cout<<"Type 9 for 11-6"<<endl;
           cout<<"Type 10 for 11-9"<<endl;
           cout<<"Type 11 for problem 12-1"<<endl;
           cout<<"Type 12 for problem 12-2"<<endl;
           cout<<"Type 13 for problem 12-5"<<endl;          
           cout<<"Type 14 to exit \n"<<endl;
    }
    int getN()
    {
           int inN;
           cin>>inN;
           return inN;
    }
    void problem1()
    {

           cout<<"In problem # 10-1"<<endl<<endl;
           const int SIZE=51;
           char input[SIZE];
           cout << "Please enter a string to return a count of characters\n";
           cin.ignore(10000,'\n');
           cin.getline(input, SIZE);
           cout << count(input) << " is the number of characters in the string\n";
    }
    void problem2()
    {
           cout<<"In problem # 10-2"<<endl<<endl;
               const int SIZE=51;
    char input[SIZE];
    cout << "Please enter a string reverse\n";
    cin.ignore(10000,'\n');
    cin.getline(input, SIZE);
    count(input);
    cout << input << " is the string backwards\n";
    }
    void problem3()
    {
           cout<<"In problem # 10-3"<<endl<<endl;
           const int SIZE=51;
    char input[SIZE];
    cout << "Please enter a string to return a count of words\n";
    cin.ignore(100,'\n');
    cin.getline(input, SIZE);
    cout << count(input) << " is the number of words in the sentence\n";
    }
    void problem4()
    {
           cout<<"In problem # 11-1"<<endl<<endl;
               movie movie1={"Diego Movie", "Diego", 1982, 200};
    movie movie2={"Jerry Movie", "Jerry", 2000, 240};
    printmovie(movie1);
    printmovie(movie2);
    }
    void problem5()
    {
           cout<<"In problem # 11-2"<<endl<<endl;
               movie2 movie1={"Diego Movie", "Diego", 1982, 200,50000,100000};
    movie2 mo={"Jerry Movie", "Jerry", 2000, 240,100000,50000};
    printmovie2(movie1);
    printmovie2(mo);
    }
    void problem6()
    {
           cout<<"In problem # 11-3"<<endl<<endl;
           Division north,east,west,south;
    cout << "\nPlease enter the sales figures for north division\n";
    input(north);
    print (north);
    cout << "\nPlease enter the sales figures for east division\n";
    input(east);
    print (east);
    cout << "\nPlease enter the sales figures for west division\n";
    input(west);
    print (west);    
    cout << "\nPlease enter the sales figures for south division\n";
    input(south);
    print (south);    
           
    }
    void problem7()
    {
		cout<<"In problem # 11-4"<<endl<<endl;
                Weather Month[12];
    for(int i=0;i<12;i++)
    {
        cout << "Please enter data for the " << i+1 << "st month" << endl;
        input(Month[i]);
    }
    print(Month);
    }
    void problem8()
    {
           cout<<"In problem # 11-5"<<endl<<endl;
               Weather Month[12];
    for(year calendar=January;calendar<=December;calendar=static_cast<year>(calendar+1))
    {
        cout << "Please enter data for the " << calendar+1 << "st month" << endl;
        input(Month[calendar]);
    }
    print(Month);
    }
    void problem9()
    {
           cout<<"In problem # 11-6"<<endl<<endl;
           Player players[12];
    for(int i=0;i<12;i++)
    {
        cout << "Please enter data for the " << i+1 << "st player" << endl;
        input(players[i]);
    }
    print(players);
    }
    void problem10()
    {
           cout<<"In problem # 11-9"<<endl<<endl;
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
    }
    void problem11()
    {
           cout<<"In problem # 12-1"<<endl<<endl;
           string filename;
    fstream namefile;
    string input;
    cout << "Please enter the name of the file\n";
    cin >> filename;
    namefile.open(filename.c_str(), ios::in);
    int count=0;
    if(namefile)
    {
        getline(namefile, input);
        while(namefile){
             if(count==10)
            {
                cout << "The entire file has been displayed";
                break;
            }
            cout << input << endl;
            getline(namefile, input);
            count++;
           
        }
    }
    
    cout << endl;
    namefile.close();
    }
    void problem12()
    {
           cout<<"In problem # 12-2"<<endl<<endl;
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
    }
    void problem13()
    {
           cout<<"In problem # 12-5"<<endl<<endl;
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
            cout << count+1 << ": " << input << endl;
            getline(namefile, input);
            count++;
        }
    }
    
    cout << endl;
    namefile.close();
    }
    
    void def(int inN)
    {
           cout<<"You typed "<<inN<<" to exit the program"<<endl;
    }
    int count(char *a)
  {
    int count=0;
    while(*a!='\0')
    {
        count++;
        a++;
    }
    return count;
}
    void count1(char *b)
{
    char *front = b;
    char *back = b + strlen(b)-1;
    while(front<back)
    {
        char tmp = *front;
        *front++=*back;
        *back-- = tmp;
    } 
}
    int count2(char *a)
{
    int count=1;
    while(*a!='\0')
    {
        if(*a==' ')
            count++;
        a++;
    }
    return count;
}
    
    void printmovie(movie mov)
{
    cout << "Title: " << mov.title << endl;
    cout << "Director: " << mov.director << endl;
    cout << "Release Year: " << mov.release << endl;
    cout << "Runtime: " << mov.runtime << endl;
    cout << endl;
}
    
    void printmovie2(movie2 mov)
{
    int net=mov.revenue-mov.production;
    cout << "Title: " << mov.title << endl;
    cout << "Director: " << mov.director << endl;
    cout << "Release Year: " << mov.release << endl;
    cout << "Runtime: " << mov.runtime << endl;
    if(net>0)
        cout << "Profit: " << net;
    else
        cout << "Loss: " << abs(net);
    cout << endl;
}
    void input(Division &div)
{
    float sales[4];
    float input;
    for(int i=0;i<4;i++)
    {
        cout << "Please enter quarter " << i+1 << " sales: " ;
        cin >> input;
        if(input<0)
        {
            cout << "\nSales not valid please re-enter: ";
                    cin >> input;
        }
        sales[i]=input;
    }
    div.q1sales=sales[0];
    div.q2sales=sales[1];
    div.q3sales=sales[2];
    div.q4sales=sales[3];
    
        
}
void print(Division div)
{
    float ann = (div.q1sales+div.q2sales+div.q3sales+div.q4sales);
    float avv = ((div.q1sales+div.q2sales+div.q3sales+div.q4sales)/4.0);
    cout << "Total annual sales: $" << ann << endl;
    cout << "Total average quarterly sales: $" << avv;
}

void input(Weather &month)
{
    int input;
        cout << "Please enter low temperature in Fahrenheit between -100 and +140" << endl;
        cin >> input;
        while(input<-100 || input >140)
        {
            cout << "\nTemperature is not valid: ";
            cin >> input;
        }
        month.ltemp=input;
        cout << "Please enter high temperature in Fahrenheit between -100 and +140"<< endl;
        cin >> input;
        while(input<-100 || input >140)
        {
            cout << "\nTemperature is not valid: ";
                    cin >> input;
        }
        month.htemp=input;
        cout << "Please enter total rainfall " << endl;
        cin >> input;
        month.rainfall=input;
        month.avgtemp=(month.ltemp+month.htemp/2);
}
void print(Weather month[])
{
    float totalaverage=0;
    int totalrain=0;
    int low=0,high=0;
    int monthlow,monthhigh;
    
    for(int i=0;i<12;i++)
    {
        if(month[i].ltemp<low)
        {
            low=month[i].ltemp;
            monthlow=i+1;
        }
        if(month[i].htemp>high)
        {
            high=month[i].htemp;
            monthhigh=i+1;
        }
        totalrain+=month[i].rainfall;
        totalaverage+=month[i].avgtemp;
    }
    
    totalaverage/=12;
    cout << "Total rainfall for the year is: " << totalrain << endl;
    cout << "Average rainfall for the year is: " << totalrain/12 << endl;
    cout << "Average temperatures for all months: " << totalaverage << endl;
    cout << "Highest temp happened in the " << monthhigh << "st month at " << high << " degrees" << endl;
    cout << "Lowest temp happened in the " << monthlow << "st month at " << low << " degrees";
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