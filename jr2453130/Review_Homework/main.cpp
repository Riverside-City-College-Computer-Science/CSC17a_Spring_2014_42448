/* 
 * File:   main.cpp
 * Author: Joseph Reimbold
 * Purpose: Searching/Sorting routines, modified for pointers 
 * and dynamic arrays
 * Created on February 24, 2014, 12:58 PM
 */

//Libraries
#include <iostream>//cout
#include <cstdlib>//srand
#include <ctime>//time
using namespace std;

//Global variables and constants

//Function Prototypes 
//this function is modified
int * filAry(int);
void prntAry(const int *, int, int);
int * cpy (const int *, int);
void bubSort(int *, int);
void swap (int &, int &);
bool bnSrch(int*, int, int);
void destroy(int *);

//Begin execution here
int main(int argc, char** argv) {
    
    //seed number generator
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables and fill array
    const int SIZE = 100;
    int *array=filAry(SIZE);
    
    //copy the array
    int *brray=cpy(array, SIZE);
    
    //print original array
    prntAry (array, SIZE, 10);
        
    //sort with bubble sort
    bubSort(brray, SIZE);
    
    //print array
    prntAry (brray, SIZE, 10);
    
    //Check to see if 50 is in the array
    int val = 50;
    cout<<"The value to find in the array = "<<val<<endl;
    if(bnSrch(brray, SIZE, val))cout<<"This value was found in the array!"<<endl;
    else cout<<"This value is not present in the array."<<endl;
    
    //Destroy
    destroy(array);
    destroy(brray);

    //Exit stage right
    system("PAUSE");
    return 0;
}

//Fill array with two digit numbers
//this has been modified for dynamic array
int *filAry(int n){
    
    //check size of the array
    if(n<=1)n=2;
    //allocate new dynamic memory
    int *a=new int[n];
    
    for(int i=0;i<n;i++){
        //a[i]=rand()%90+10; 
        //the original ^^
        *(a+i)=rand()%90+10;
    } 
    return a;
}

//Print Array
void prntAry(const int *a, int n, int perline){
    
    //check size of the array
    if(n<=1)n=2;
    for(int i=0;i<n;i++){
        //converted to pointer
        cout<<*(a+i)<<" ";
        if(i%10==(perline-1))cout<<endl;
    }
    cout<<endl;
}

//copy array
int * cpy (const int *a, int n){
    
    int *b=new int[n];
    //copy array to index
    if(n<=1)n=2;
    for(int i=0;i<n;i++){
        *(b+i)=*(a+i);
      }
    return b;
}

//Bubble Sort
void bubSort(int *a, int n){
    bool bbl;
    do{
        bbl=false;
        for (int i=0;i<n-1;i++){
            if(*(a+i)>*(a+i+1)){
                swap(*(a+i),*(a+i+1));
                bbl=true;
            }
        }
    }while(bbl);
}

//Search routine
bool bnSrch(int *a, int n, int val){
    int first=0, last=n-1, mid;
    bool found=false;
    while(!found&&first<=last){
        mid=(first+last)/2;
        if(*(a+mid)==val)
            found=true;
        else if(*(a+mid)>val)
            last=mid-1;
        else first=mid+1;
    }
    return found;
}

//function to swap
void swap (int &a, int &b){
    
    //Switch the values
    int temp =a;
    a=b;
    b=temp;   
}

void destroy(int *a){
    delete [] a;
}
