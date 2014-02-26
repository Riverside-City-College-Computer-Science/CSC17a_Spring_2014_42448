/* 
 * David Ballantyne
 * Created on February 22, 2014, 10:01 AM
 * purpose: pointer bubble sort and binary search
 */
//Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;
//Global Constants

//function prototypes
void filAray(int *a,int);
void bubSrt(int *a,int);
void search(int*a , int);
void prntAry(const int *a,int,int);
//execution begins here
int main(int argc, char** argv){
    const int SIZE=100;
    int array[SIZE],bub,slc;
    srand(static_cast<unsigned int>(time(0)));
    filAray(array,SIZE); 
    prntAry(array,SIZE,10);
    bubSrt(array,SIZE);
    prntAry(array,SIZE,10);   
	search(array,SIZE);
    prntAry(array,SIZE,10);
 
    return 0;
}
void filAray(int *a,int n){
    for(int i=0;i<n;i++){
         *(a+i)=rand()%90+10;
    }
}
void bubSrt(int *a,int n){
    bool swap;
    int temp;
    do{
        swap=false;
    for(int i=0;i<n;i++){
        if(*(a+i)>*(a+(i+1))){
            temp=*(a+i);
            *(a+i)=*(a+(i+1));
           *(a+(i+1))=temp;
            swap=true;
        }
    }
    }while(swap);
}
void prntAry(const int *a,int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
       cout<<*(a+i)<<" ";
        if(i%10==(perLine-1))cout<<endl;
    }
    cout<<endl;
}
void search(int *a, int size){
    int value;
    int first=0;
    int middle=0, position=-1;
    int last=size-1;
      
        bool found = false; 
		cout<<"Enter a value between 10-99: \n";      
        cin>>value;
        while(!found && first<=last){
        	middle=(first+last)/2;
        	if(*(a+middle)==value){
        		found= true;
        		position=value;
        	}
        	else if (*(a+middle)>value){
        		last=middle-1;
       		}
        	else
        	first=middle+1;
        	}
		if(*(a+middle)==value){	
		cout<<"Your value is "<<value<<" was found in the "<< middle+1<<" position of the array."<<endl;
        }
        else
         cout<<"Your value was not found."<<endl;
            cout<<endl;
}
