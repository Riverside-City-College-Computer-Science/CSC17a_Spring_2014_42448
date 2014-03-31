/* 
 * File:   main.cpp
 * Author: Abel Salazar
 * Created on March 14, 2014, 3:07 PM
 */

//system library
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
//global constants

//function prototypes
void fillArray(int [],int);
void arrSelectSort(int *[], int);
void showArray(const int [], int);
void showArrPtr(int *[], int);

//execution begins here
int main(int argc, char** argv) {
    int NUM_DONATIONS = 15;
    cout << "Enter the number of donations" <<endl;
    cin >> NUM_DONATIONS;
    srand(static_cast<unsigned int>(time(0)));
    
    
    //array of donation amounts
    int donations[NUM_DONATIONS];
    //array of pointers
    
    fillArray(donations,NUM_DONATIONS);
    
    int *arrPtr[NUM_DONATIONS];
    
    for(int count = 0; count < NUM_DONATIONS; count++){
        arrPtr[count] = &donations[count];
    }
    
    arrSelectSort(arrPtr, NUM_DONATIONS);
    
    cout << "The donations, sorted in ascending order, are: \n";
    showArrPtr(arrPtr, NUM_DONATIONS);
    
    cout << "The donations, in their original order, are: \n";
    showArray(donations, NUM_DONATIONS);
    return 0;
}

 void fillArray(int a[], int size){
     for(int i=0;i<size;i++){
         a[i]=rand()%100+1;
     }
 }

 void arrSelectSort(int *arr[], int size){
      int startScan, minIndex;
      int *minElem;
      
      for (startScan = 0; startScan < (size - 1); startScan++){
           minIndex = startScan;
           minElem = arr[startScan];
           for(int index = startScan + 1; index < size; index++){
               if (*(arr[index]) < *minElem){
                    minElem = arr[index];
                    minIndex = index;
               }
           }
           arr[minIndex] = arr[startScan];
           arr[startScan] = minElem;
      }
 }
 void showArray(const int arr[], int size){
       for (int count = 0; count < size; count++){
            cout << arr[count] << " ";
       }
        cout << endl;
 }
 
 void showArrPtr(int *arr[], int size){
      for (int count = 0; count < size; count++){
           cout << *(arr[count]) << " ";
      }
      cout << endl;
 }
  
  