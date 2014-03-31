//Mark E. Lehr
//October 27th, 2011
//Menu to be used for the midterm
//homework and midterm, etc....

#include <iostream>
#include <string>

using namespace std;

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
           cout<<"Type 1 for problem 1"<<endl;
           cout<<"Type 2 for problem 2"<<endl;
           cout<<"Type 3 for problem 3"<<endl;
           cout<<"Type 4 for problem 4"<<endl;
           cout<<"Type 5 for problem 5"<<endl;
           cout<<"Type 6 for problem 6"<<endl;
           cout<<"Type 7 for problem 7"<<endl;
           cout<<"Type 8 for problem 8"<<endl;
           cout<<"Type 9 for problem 9"<<endl;
           cout<<"Type 10 for problem 10"<<endl;
           cout<<"Type 11 for problem 11"<<endl;
           cout<<"Type 12 for problem 12"<<endl;
           cout<<"Type 13 for problem 13"<<endl;          
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

           cout<<"In problem # 1"<<endl<<endl;
           const int SIZE=51;
           char input[SIZE];
           cout << "Please enter a string to return a count of characters\n";
           cin.ignore(10000,'\n');
           cin.getline(input, SIZE);
           cout << count(input) << " is the number of characters in the string\n";
    }
    void problem2()
    {
           cout<<"In problem # 2"<<endl<<endl;
               const int SIZE=51;
    char input[SIZE];
    char copy[SIZE];
    cout << "Please enter a string reverse\n";
    cin.ignore(10000,'\n');
    cin.getline(input, SIZE);
    count(input);
    cout << input << " is the string backwards\n";
    }
    void problem3()
    {
           cout<<"In problem # 3"<<endl<<endl;
           const int SIZE=51;
    char input[SIZE];
    cout << "Please enter a string to return a count of words\n";
    cin.ignore(100,'\n');
    cin.getline(input, SIZE);
    cout << count(input) << " is the number of words in the sentence\n";
    }
    void problem4()
    {
           cout<<"In problem # 4"<<endl<<endl;
    }
    void problem5()
    {
           cout<<"In problem # 5"<<endl<<endl;
    }
    void problem6()
    {
           cout<<"In problem # 6"<<endl<<endl;
    }
    void problem7()
    {
		cout<<"In problem # 7"<<endl<<endl;
    }
    void problem8()
    {
           cout<<"In problem # 1"<<endl<<endl;
    }
    void problem9()
    {
           cout<<"In problem # 2"<<endl<<endl;
    }
    void problem10()
    {
           cout<<"In problem # 3"<<endl<<endl;
    }
    void problem11()
    {
           cout<<"In problem # 4"<<endl<<endl;
    }
    void problem12()
    {
           cout<<"In problem # 5"<<endl<<endl;
    }
    void problem13()
    {
           cout<<"In problem # 6"<<endl<<endl;
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