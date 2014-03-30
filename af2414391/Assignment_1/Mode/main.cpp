/* 
 * Name: Alec Farfan
 * Date: 03/14/14
 * Purpose: Calculate Mean Median and Mode
 */
 
//Include libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//No global variables or constants

//Function prototypes
void destroy(int*);
float median(int*,int);
float mean(int*,int);
int *mode(int*,int,int,int);
int numMode(int*,int,int);
int findMax(int*,int);
void sort(int*,int);
void prntAry2(int*,int);
void prntAry1(int*,int);
int *fillAry(int);

//Execution begins here
int main(int argc, char** argv) {

    //Declare repeat variable and seed random number
    char repeat;
    srand(static_cast<unsigned int>(time(0)));
    
    do{
        //Declare Variables
        int size=50;
        int maxFreq=0,maxMode=0;
        
        //Create and fill an array with random two digit numbers
        int* setAry=fillAry(size);
        
        //Sort the array
        sort(setAry,size);
        prntAry1(setAry,size);
        
        //Find the max frequency 
        maxFreq=findMax(setAry,size);
        maxMode=numMode(setAry,size,maxFreq);
        int *modeAry=mode(setAry,maxMode,size,maxFreq);
        float aryMean=mean(setAry,size);
        float aryMed=median(setAry,size);
        
        cout<<"The max frequency is: "<<maxFreq<<endl;
        cout<<"There are "<<maxMode<<" elements with max frequency"<<endl;
        cout<<"The set with max frequency is ";
        prntAry2(modeAry,maxMode);
        cout<<"The median of the array is "<<aryMed<<endl;
        cout<<"The mean of the array is "<<aryMean<<endl;
        
        //Delete dynamically allocated memory
        destroy(setAry);
        destroy(modeAry);
        
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
void prntAry1(int* array,int size){
    for(int i=0;i<size;i++){
        cout<<*(array + i)<<" ";
        if(i%10==9&&i!=size-9){cout<<endl;}
    }
    cout<<endl;
}
void prntAry2(int* array,int size){
    cout<<"{ ";
    for(int i=0;i<size;i++){
        cout<<*(array + i)<<" ";
        if(i%10==9&&i!=size-9){cout<<endl;}
    }
    cout<<"}"<<endl;
}
void sort(int* array,int size){
    
    for(int i=0;i<size-1;i++){
        int min=i;
        int minEl=*(array+i);
        for(int j=i+1;j<size;j++){
            if(*(array + j)<minEl){
                min=j;
                minEl=*(array+j);}
        }
        *(array + min) = *(array + i);
        *(array + i)=minEl;
    }
}
void destroy(int* array){
    delete [] array;
    array=0;
}
int findMax(int* array,int size){
    int count=1, maxFreq=1;
    
    for(int i=0;i<size-1;i++){
        if(*(array+i)==*(array+i+1)){
            count++;}
        else{
            if(count>maxFreq){
            maxFreq=count;}
            count=1;}
    }
    return maxFreq;
}
int numMode(int* array,int size,int maxFreq){
    int count=1, modes=0;
    
    for(int i=0;i<size-1;i++){
        if(*(array+i)==*(array+i+1)){
            count++;}
        else{
            if(count==maxFreq){
            modes++;}
            count=1;}
    }
    return modes;
}
int *mode(int* array,int moSize,int setSize,int maxFreq){
    int *modeAry = new int [moSize];
    int count=0,elCount=0;
    for(int i=0;i<setSize-1;i++){
        if(*(array+i)== *(array+i+1)){
            count++;}
        else{ 
            if(count==maxFreq){
            *(modeAry+elCount)= *(array+i);
            elCount++;}
            count=1;}
     }   
    return modeAry;    
}
float mean(int* array, int size){
    float total=0;
    for(int i=0;i<size;i++){
        total+=*(array+i);}
    
    total/=size;
    return total;
}
float median(int* array,int size){
    float med=0;
    size/=2;
    if(size%2==0){
        size+=1;
        med=*(array+size-1);}
    else{
        med=*(array+size-1);
        med+=*(array+size);
        med/=2.0;
    }
    return med;
}