/* 
 * Nhat Nguyen
 * Created on February 24, 2014, 1:05 PM
 * Sort Search like your homework with pointers
 */

//System Libaries
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

//Global Constants

//Function Prototypes
int * filAray(int);
void prntAry(const int *, int, int);
int * cpy(const int *, int);
void mrkSort(int *, int);
void swap(int &, int &);
bool findVal(int *, int, int);
void destroy(int *);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables and set random number seed
    srand(static_cast<unsigned int>(time((0))));
    const int SIZE=100;
    int *array=filAray(SIZE);
    //Copy the array
    int *brray=cpy(array,SIZE);
    mrkSort(brray,SIZE);
    //Print the array
    prntAry(array,SIZE,10);
    prntAry(brray,SIZE,10);
    //Pick a random number to find
    int val=rand()%90+10;
    cout<<endl<<"The value to find in the array = "<<val<<endl;
    if(findVal(array,SIZE,val))cout<<"This value is in the array."<<endl;
    else cout<<"The value is not found in the array."<<endl;
    //Exit Stage Right
    destroy(array);
    destroy(brray);
    return 0;
}

//Fill array with 2 random digits
int * filAray(int n){
    //Check the size of the array
    if(n<=1)n=2;
    //Allocate Dynamic Memory
    int*a=new int[n];
    for(int i=0;i<n;i++){
        *(a+i)=rand()%90+10;
    }
    return a;
}
void prntAry(const int *a, int n, int perLine){
    //Output the array
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<*(a+i)<<" ";
        if(i%10==(perLine-1))cout<<endl;
    }
}

int * cpy(const int *a, int n){
    if(n<=1)n=2;
    int *b=new int[n];
    for(int i=0;i<n;i++){
        *(b+i)=*(a+i);
    }
    return b;
}

void mrkSort(int *b, int n){
    //Find the minimum position 
    for(int i=0;i<n-1;i++){
        //Swaps the larger values as you go down the list
        for(int j=i+1;j<n;j++){
            //Check the swap
            if(*(b+i)>*(b+j))swap(*(b+i),*(b+j));
        }
    }
}

bool findVal(int *a, int n, int val){
    for(int i=0;i<n;i++){
        if(*(a+i)==val)return true;
    }
    return false;
}

void swap(int &a, int &b){
    int temp=a;
        a=b;
        b=temp;
}

void destroy(int *a){
    delete []a;
}