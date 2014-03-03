/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on March 3, 2014, 12:48 PM
 */

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

/*
 * 
 */
int * fillAry(int);
void prntAry(int*, int, int);
void sort(int *, int [], int);
int maxFreq(int *, int);
float mean(int *,int);
float median(int *,int);
int numode(int *,int, int);
void destroy(int *);


int main(int argc, char** argv) {
    const int SIZE=105;
    int brray[SIZE];
     //fill the array with 0-9
    int *array=fillAry(SIZE);
    //print the array
    prntAry(array,SIZE,10);
    //sort a copied array
    sort(array,brray,SIZE);
    //print the sorted array
    prntAry(brray,SIZE,10);
    cout << "The max freq in the array = " << maxFreq(brray, SIZE);
    destroy(array);
    return 0;
}
//repetitive count
int *fillAry (int n)
{
    //allocate memory
    int *a=new int[n];
    //fill array
    for (int i=0; i<n; i++){
        a[i]=i%10;
    }
    return a;
    //return array
}
int maxFreq(int *a, int n){
    int count=1, max=1;
    for(int i=1;i<n;i++){
        if(a[i-1]==a[i]){
            count++;
            if(count>max)max=count;
        }else{
            count=1;
        }
    }
    return max;
}
void sort(int *a, int b[], int n)
{
    for (int i=0; i<n; i++)
    {
        b[i]=a[i];
    }
    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            if(b[i]>b[j]){
                int temp=b[i];
                b[i]=b[j];
                b[j]=temp;
            }
        }
    }
}
void prntAry(int *a, int n, int perLine){
    cout << endl;
    for (int i=0; i<n; i++){
        cout << a[i] << " ";
        if(i%perLine==(perLine-1))cout << endl;
    }
}

void destroy (int *a){
    delete [] a;
}
float mean(int array,int size)
{
    
}
float median(int array,int size)
{
    
}
int numode(int array ,int size, int freq)
{

}

