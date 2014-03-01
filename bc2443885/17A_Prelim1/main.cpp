/* Bradd Carey
 * 19 Feb 2014
 * 
 * Purpose:  Demonstrate ability to use pointers, binary search and bubble sort
 */

//Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>

//No Global Constants

//F(x) Prototypes
void bubSort(int, int*);
void randArr(int,int*);
void prntArr(int, int, int*);
void xorSwap(int&,int&);
void search(int, int*);
bool repeat();

using namespace std;

int main(int argc, char** argv) {
    
    //Variables
    int const SIZE=100, LINE=10;
    srand(time(0));
    
    //I don't think dynamic arrays are good practice in the place of vectors
    //But since the assignment calls for it...
    int* a = new int[100]; 
    
    //Create Array
    cout<<"Creating Random Array..."<<endl;
    randArr(SIZE,a);
    
    //Print Unsorted Array
    cout<<endl<<"Unsorted Array:  "<<endl;
    prntArr(SIZE,LINE,a);
    
    //Sort Array
    cout<<endl<<"Using Bubble Sort..."<<endl;
    bubSort(SIZE,a);
    
    //Print Sorted Array
    cout<<endl<<"Sorted Array:  "<<endl;
    prntArr(SIZE,LINE,a);
    
    //Binary Search
    search(SIZE,a);
        
    //End
    cout<<"Program Terminating..."<<endl;
    delete[] a; //Gotta clean up that memory
    return 0;
}
void bubSort(int s, int* a){
    //Sort up to the last value
    for(int i=0;i<s-1;i++){
        //Sort up to the last value that was last sorted
        for(int c=0;c<s-i-1;c++){
            if(a[c] > a[c+1]){
                xorSwap(a[c],a[c+1]);
            }
        }
    }
}
void randArr(int s,int* a){
    for(int i=0;i<s;i++){
        a[i]=rand()%90+10;
    }
}
void prntArr(int s, int l, int* a){
    for(int i=0;i<s;i++){
        cout<<a[i]<<" ";
        if(!((i+1)%l)){
            cout<<endl;
        }
    }
}
void xorSwap(int& a, int& b){
    //xorSwap because it's classy
    a ^= b;
    b ^= a;
    a ^= b;
}
void search(int s, int* a){
    int v;
    do{
        bool found = false;
        do{
            cout<<endl<<"Enter a value to search for [10-99] or [0] to exit:  ";
            cin>>v;
        }while((v<10||v>99)&&v!=0);
        if(v){
            for(int i=0;i<s;i++){
                if(a[i]==v){
                    if(((i+1)!=11)&&((i+1)%10==1)){
                        cout<<"Your value ("<<v<<") was found in the "<<i+1<<"st position of the array."<<endl;
                    }
                    else if(((i+1)!=12)&&((i+1)%10==2)){
                        cout<<"Your value ("<<v<<") was found in the "<<i+1<<"nd position of the array."<<endl;
                    }
                    else if(((i+1)!=13)&&((i+1)%10==3)){
                        cout<<"Your value ("<<v<<") was found in the "<<i+1<<"rd position of the array."<<endl;
                    }
                    else{
                        cout<<"Your value ("<<v<<") was found in the "<<i+1<<"th position of the array."<<endl;
                    }
                    found = true;
                }

            }
            if(!found)
                    cout<<"Your value was not found."<<endl;
            cout<<endl;
        }
    }while(v);
}
