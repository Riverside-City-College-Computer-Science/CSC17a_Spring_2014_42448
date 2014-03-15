/* 
 * File:   main.cpp
 * Author: Abel Salazar
 * Created on March 12, 2014, 10:05 PM
 */

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
//global constants

//function prototypes
int *fillAry(int);
void prntAry(int [], int,int);
void sortAry(int [],int);
void average(int [],int);
void dropScore(int [], int &);
void destroy(int []);

//execution begins here
int main(int argc, char** argv) {
    //variable declaration
    int size=0;
    
    //seed time
    srand(static_cast<unsigned short>(time(0)));
    cout<< "Enter the amount of test scores you have"<<endl;
    cin >> size;
    
    //fill dynamic array
    int *tests=fillAry(size);
    
    //print dynamic array before sort
    prntAry(tests,size,10);
    //sort values
    sortAry(tests,size);
    //print sorted values
    prntAry(tests,size,10);
    //destroy allocated memory
    average(tests,size);
    dropScore(tests,size);
    
    destroy(tests);
    
    
    //exit stage
    return 0;
}

void destroy(int a[]){
    delete [] a;
}

//drops the score on the last 10 scores
void dropScore(int a[], int &n){
    int size=0;
    if(n>10){
        size=n-10;
        int brray[size];
        brray[0]=0;
        for(int i=0;i<size;i++){
            brray[0]+=a[i];
        }
        brray[0]=brray[0]/size;
        cout<<endl;
        for(int j=0;j<size;j++){
            cout << a[j]<< " ";
        }
        cout<<endl;
        cout << "New test score average is " << brray[0] <<endl;
    }else{
        cout << "There are not enough scores to drop 10"<<endl;
    }
}

void average(int a[],int size){
    const int SIZE = 1;
    int brray[SIZE]= {0};
    for(int i=0;i<size;i++){
        brray[0]+=a[i];
    }
    cout << "Total is " <<brray[0]<<endl;
    brray[0]/=size;
    cout << "Average is " <<brray[0]<<endl;
}

void sortAry(int a[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[i]>a[j]){
                int temp = a[i];
                a[i] = a[j];
                a[j]=temp;
            }
        }
    }
}

void prntAry(int a[], int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%10==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

int *fillAry(int SIZE){
    if(SIZE<2)SIZE=2;
    int *a = new int [SIZE];
    for(int i=0;i<SIZE;i++){
        a[i]=rand()%90+10;
    }
    return a;
}
