/* 
 * Name: Alec Farfan
 * Date: 03/12/14
 * Purpose: Gaddis Chapter 9 Problem 6 (Modification #1 of Book's Example)
 */

//Include libraries
#include <cstdlib>
#include <iostream>
using namespace std;

//No global variables or constants

//Function Prototypes 
void arrSelectionSort(int*[],int);
void showArray(const int[],int);
void showArrPtr(int*[],int);
void getDons(int*,int);
int* getPtr(int&);
//Execution begins here
int main(int argc, char** argv) {

    //Declare repeat variable
    char repeat;
    
do{
    //Declare variables
    int numDons=0; //Number of donations
    
    //An array to be filled with donation amounts
    int *donations=getPtr(numDons);
    getDons(donations,numDons);
    
    //An array of pointers to int
    int *arrPtr[numDons];
    
    //Each element of arrPtr is a pointer to int. Make each
    //element point to an element in the donations array.
    for (int count = 0; count < numDons; count++){
        arrPtr[count]= (donations+count);}
    
    //Sort the elements of the array of pointers
    arrSelectionSort(arrPtr, numDons);
    
    //Display the donations using the array of pointers. This
    //will display them in sorted order.
    cout << "The donations, sorted in ascending order, are: \n";
    showArrPtr(arrPtr,numDons );
    
    //Display the donations in their original order.
    cout << "The donations, in their original order, are: \n";
            showArray(donations,numDons);
            
    delete [] donations;       
    
    cout<<"Would you like to repeat the program? Enter Y"<<endl;
    cout<<"to repeat or enter anything else to exit:";
    cin>>repeat;
  }while(repeat=='Y'||repeat=='y');    
      
    //End of program
    return 0;
}
int* getPtr(int& numDons){
    cout<<"Enter the number of donations to be inputed:";
    cin>>numDons;
    int * ptr = new int[numDons];
    
    return ptr;
}
void getDons(int* donations,int size){
    cout<<"Enter the donation amounts"<<endl;
    for(int i=0;i<size;i++){
        cout<<i+1<<":";
        cin>>*(donations+i);}
}
void arrSelectionSort(int *arr[],int size){
    int startScan, minIndex;
    int *minElem;
    
    for (startScan = 0; startScan < (size - 1); startScan++){
        minIndex = startScan;
        minElem = arr[startScan];
        for (int index = startScan + 1; index < size; index++){
            if(*arr[index]<*minElem){
                minElem = arr[index];
                minIndex = index;}
        }
        arr[minIndex] = arr[startScan];
        arr[startScan]=minElem;
    }
}
void showArray(const int arr[], int size){
    for (int count = 0; count< size; count++){
        cout << arr[count] << " ";
    }
    cout<<endl;
}
void showArrPtr(int *arr[],int size){
    for (int count = 0; count < size; count++){
        cout << *(arr[count]) << " ";
    }
    cout<<endl;
}