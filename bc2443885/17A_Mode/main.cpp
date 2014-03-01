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

//Required Function Prototypes Prototypes
float mean(int*,int);        //Returns the mean
float median(int*,int);      //Returns the median
int* mode(int*,int,int);     //Returns an array that contains each mode (low to high)

//Functions for generating, sorting and printing arrays
void randArr(int,int*);       //Generate a random array
void prntArr(int, int, int*); //Print that array
void bubSort(int, int*);      //Bubble Sort
void xorSwap(int&,int&);      //Exclusive Or Swap for Bubble Sort

//Functions associated with getting information about the mode
void modeOut(int*,int);       //Outputs Mode Information to Console
int* count(const int*,int);   //Generates an array for frequency
int freq(int*,int);           //Returns the highest frequency
int numMode(int*,int);        //Returns the Number of Modes

using namespace std;

int main(int argc, char** argv) {
    
    //Variables
    int const SIZE=100, LINE=10;
    srand(time(0));
    int* a = new int[SIZE]; 
    
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
    
    //Return Mean
    cout<<endl<<"Mean:  "<<mean(a,SIZE);
    
    //Return Median
    cout<<endl<<"Median:  "<<median(a,SIZE);
    
    //Return Mode
    modeOut(a,SIZE);
        
    //End
    cout<<endl<<"Program Terminating..."<<endl;
    delete[] a; //Gotta clean up that memory
    return 0;
}

//Required Functions
float mean(int* a,int s){
    float temp=0;
    for(int i=0;i<s;i++){
        temp += a[i];
    }
    return temp/s;
}
float median(int* a,int s){
    //If Odd
    if(s%2)
        return a[(s-1)/2];
    else
        //Find two middle values and average them
        return ((a[s/2]+a[(s/2)-1])/2.0);
}
int* mode(int *b,int s,int modes){
    //Find Highest Frequency
    int high = freq(b,s);
    
    //Create an Array with 'modes' elements
    int* c = new int[modes+2];
    
    //Populate the first two elements of c with number of modes and frequency
    c[0] = modes;
    c[1] = high;
    
    //Fill array with modes
    for(int j=2;j<modes+2;j++){
        for(int i=0;i<s;i++){
            if(b[i]==high){
                c[j]=i;
                j++;
            }
        }
    }
    
    //Return Dynamic Mode Array
    return c;
}

//Array Functions
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
void xorSwap(int& a, int& b){
    //xorSwap because it's classy
    a ^= b;
    b ^= a;
    a ^= b;
}

//Functions for Finding Mode(s)
int* count(const int* a, int s){
    int* count = new int[s+1];
    for(int i=10;i<100;i++){
        //Reset Counter
        int c=0;
        for(int j=0;j<s;j++){
            //If Found increment the counter
            if(a[j]==i)
                c++;
            else{
                count[i]=c;
            }
        }
    }
    return count;
}
void modeOut(int* a,int s){
    //Generate a counter array
    int* b = new int[s+1];
    b = count(a,s);
    cout<<endl;
    
    //Find Number of modes
    int num = numMode(b,s);
    
    //Create Mode Array
    int *d;
    d = mode(b,s,num);
    
    //Output Modes
    cout<<"Mode :  {";
    for(int i=2;i<num+2;i++){
        if(i==2)
            cout<<d[i];
        else
            cout<<","<<d[i];
    }
    cout<<"}"<<endl;
    
    //Clean up memory
    delete[] b;
    delete[] d;
    
}
int freq(int* b,int s){
    int high = 0;
    for(int i=0;i<s;i++){
        if(b[i]>high)
            high=b[i];
    }
    return high;
}
int numMode(int *b,int s){
    //Find Highest Frequency
    int high = freq(b,s);
    
    //Count the number of indexes with that highest frequence
    int numModes = 0;
    for(int i=0;i<s;i++){
        //If frequency is highest increment
        if(b[i]==high)
            numModes++;
    }
    return numModes;
}
