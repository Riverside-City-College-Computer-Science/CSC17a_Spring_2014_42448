/* 
 * Name: Alec Farfan
 * Date: 03/14/14
 * Purpose: Gaddis Chapter 9 Problem 11 (Array Expander)
 */
 
//Include libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//No global variables or constants

//Function prototypes
int *dubAry(int*,int);
void prntAry(int*,int);
int *fillAry(int);
//Execution begins here
int main(int argc, char** argv) {

    //Declare repeat variable
    char repeat;
    srand(static_cast<unsigned int>(time(0)));
    
    do{
        //Declare variables
        int size=50;
        
        //Fill and print the original array
        cout<<"     Original Array"<<endl;
        int *array1=fillAry(size);
        prntAry(array1,size);
        
        //Reverse and print the array
        cout<<"     Doubled Array"<<endl;
        int *array2=dubAry(array1,size);
        prntAry(array2,size*2);
        
        //Ask user if they would like to repeat the program
        cout<<"Would you like to repeat the program? Enter Y"<<endl;
        cout<<"to repeat or enter anything else to exit:";
        cin>>repeat;
        system("CLS");
        
    }while(repeat=='Y'||repeat=='y');
    //End of program
    return 0;
}
int *fillAry(int size){
    int *array = new int [size];
    for(int i=0;i<size;i++){
        *(array+i)=rand()%90+10;
    }
    return array;
}
void prntAry(int* array,int size){
    for(int i=0;i<size;i++){
        cout<<*(array + i)<<" ";
        if(i%10==9&&i!=size-9){cout<<endl;}
    }
    cout<<endl;
}
int *dubAry(int* array,int size){
    int dubble=size*2,
        count=0;
    int *dub = new int [dubble];
    
    
    for(int i=0;i<size;i++){
        *(dub+i)=*(array+i);
    }
    for(int j=size;j<dubble;j++){
        *(dub+j)=*(array+count);
        count++;}
    return dub;
}
