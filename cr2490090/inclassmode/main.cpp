/* 
 *Created By: Caleb Rosenquist
 *Februrary 24th, 2014
 *To implement a similar sorting method than the homework we were assigned (dynamic arrays). 
 */

//Libraries
#include <cstdlib> //srand
#include <iostream> //cout
#include <ctime> //time
using namespace std;

//Global Variables and Constants

//Function Prototypes
int * fillArray(int);
void printArray(const int *, int, int);
int * cpy(const int *, int);
void markSort(int *, int);
void bubSort(int *, int);
int binSearch(int *, int, int);
bool findValue(int *, int, int);
void swap(int &, int &);
void destroy(int *);
float mean(int *, int);
float median(int *, int);
void mode(int *, int);


//Execution Begins Here
int main(int argc, char** argv) {
    //Set random seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables
    const int SIZE=100;
    int *array=fillArray(SIZE); //delcare and fill array
    
    //Copy the array
    int *bArray=cpy(array, SIZE);
    int *bubArray=cpy(array,SIZE);
    
    //Sort the copy
    markSort(bArray,SIZE);
    bubSort(bubArray,SIZE);
    
    //Print the array
    printArray(array,SIZE,10);
    cout<<endl<<"Sorted with Mark Sort";
    printArray(bArray,SIZE,10);
    cout<<endl<<"Sorted with Bubble Sort";
    printArray(bubArray,SIZE,10);
    
    //Pick a random number to find
    int val=rand()%90+10;
    cout<<"The value to find in the array = " << val << endl;
    if(findValue(array, SIZE, val))cout<<"This value is in the array"<<endl;
    else cout<<"The value is not found in the array"<<endl;
    cout<<endl<<"Using Binary Search"<<endl;
    if(binSearch(bArray, SIZE, val)>0)cout<<"This value is in the array"<<endl<<endl;
    else cout<<"The value is not found in the array"<<endl<<endl;
    
    cout<<"The Mean equals: "<<mean(bArray, SIZE)<<endl;
    cout<<"The Median equals: "<<median(bArray,SIZE)<<endl;
    mode(bArray, SIZE);
    
    destroy(array);
    destroy(bArray);
    //Exit Stage right
    return 0;
}

int *fillArray(int n){//Fill the array with 2 digit random digits
    //Check the size of the array
    if(n<=1)n=2;
    //Allocate Dynamic Memory
    int *a=new int[n];
    
    for(int i=0; i<n;i++){
        *(a+i)=rand()%90+10;
    }
    return a;
}
void printArray(const int *a, int n, int perLine){
    //Output the array
    cout << endl;
    for(int i=0; i<n;i++){
        cout << *(a+i)<<" ";
        if(i%10==(perLine-1))cout<<endl;
    }
    cout << endl;
}
int *cpy(const int *a, int n){
    //Replicate the values of one array into another
    if(n<=1)n=2;
    int *b=new int[n];
    for(int i=0; i<n;i++){
        b[i]=*(a+i);
    }
    return b;
}
void markSort(int *a, int n){
    //Finds the minimum at this starting position
    for(int i=0;i<n-1;i++){
        //Swap the larger values as you go down the list
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j])swap(a[i],a[j]);
        }
    }
}
void bubSort(int *a, int n){
    bool descend=false;
    bool change=false;
    int temp=-1,k=0;
    while(descend==false){
        for(int i=0;i<n-1;i++){
            if(a[i]>a[i+1]){
                swap(a[i],a[i+1]);
                k++;
            }
        }
        if(k==0)descend=true;
        else{
            k=0;
        }
    }
}
int binSearch(int *a, int n, int v){
    int low=0;
    int high=n;
    while(low+1<high){
        int test = (low+high)/2;
        if(a[test]>v) high=test;
        else low=test;
    }
    if(a[low]==v)return low;
    else return -1;
}
bool findValue(int *a, int n, int value){
    for(int i=0; i<n;i++){
        if(a[i]==value)return true;
    }
    
    return false;
}
void swap(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
}
void destroy(int *a){
    delete [] a;
}
float mean(int *a, int n){
    float ave=0;
    for(int i=0;i<n;i++){
        ave+=a[i];
    }
    return ave/n;
}
float median(int *a, int n){
    if(n%2){
        return a[(n-1)/2];
    }
    else{
        return ((a[n/2])+(a[(n/2)-1]))/2.0;
    }
}
void mode(int *a, int n){
    int number=a[0]; 
    int element=number;
    int count=1;
    int highest=1;
    int maxFreq=0;
    int modeCount=0;
    int occur=0;

    //Counts how many times the current number occurs
    for (int i=1;i<=n;i++){
        if (a[i]==number){ 
            highest++;
        }
        else{ //If the new number is different from the previous, this route is taken
            if (highest>count){
                count=highest; //Updates the highest frequency 
                element=number;
            }
            highest=1; //Sets the individual count back to zero for the upcoming new number
            number=a[i];
        } 
    }
    
    //Registers how many numbers within the original array that share highest frequency
    int* freqCount = new int[100];
    for(int i=10;i<=n;i++){
        //Reset Counter
        int frequency=0;
        for(int j=0;j<=n;j++){
            //If Found increment the counter
            if(a[j]==i)frequency++;
            else{
                freqCount[i]=frequency;
            }
        }
        if(maxFreq<frequency)maxFreq=frequency;
    }

    //Checks how many times the highest frequency occurs within freqCount
    for(int j=0;j<=n;j++){
            if(freqCount[j]==maxFreq){
            occur++;
            }
    }
    
    //Output the results
    if(maxFreq==1){
        cout<<"Holy shit, not a single mode exists within this entire array!"<<endl;
    }else{
        cout << "The Mode equals: {";
        for(int i=0;i<=n;i++){
                if(freqCount[i]==maxFreq){
                 if(occur==1){
                    cout<<i<<"}"<<endl;
                  }else{
                      cout<<i<<", ";
                       occur--;
                    }
                }
        }
        cout<<"    with a frequency of: "<<maxFreq<<endl;
        destroy(freqCount);
    }
}