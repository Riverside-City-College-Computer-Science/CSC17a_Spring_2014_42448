/* 
 * File: main.cpp
 * Author: Miguel Gaona
 * Created on March 10, 2014, 3:41 PM
 */

//system libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Function Prototypes
int * fillAry(int);
void prntAry(int*, int, int);
void sort(int *, int [], int);
int maxFreq(int *, int);
float mean(int *,int);
float median(int *,int);
int *numode(int *,int, int);
void destroy(int *);


int main(int argc, char** argv) {
    const int SIZE=50;
    srand(time(0));
    int brray[SIZE];
     //fill the array with 0-9
    int *array=fillAry(SIZE);
    //print the array
    prntAry(array,SIZE,10);
    //sort a copied array
    sort(array,brray,SIZE);
    //print the sorted array
    prntAry(brray,SIZE,10);
    cout << endl;
    cout << "Mean: " << mean(brray, SIZE)<<endl;
    cout << "Median: " << median(brray, SIZE)<<endl;
    cout << "Max frequency: " << maxFreq(brray, SIZE)<<endl;
    int *mode= numode(brray, SIZE, maxFreq(brray, SIZE));
    cout << "Number of modes: " << mode[0]<<endl;
    cout << "Mode(s): "; 
    for(int i=2;i<mode[0]+2;i++)
    {
        cout << mode[i] << " ";
    }
    destroy(array);
    destroy(mode);
    return 0;
}
//repetitive count
int *fillAry (int n)
{
    //allocate memory
    int *a=new int[n];
    //fill array
    for (int i=0; i<n; i++)
    {
        a[i]=rand()%9;
    }
    return a;
    //return array
}
int maxFreq(int *a, int n)
{
    int count=1, max=1;
    for(int i=1;i<n;i++)
    {
        if(a[i-1]==a[i])
        {
            count++;
            if(count>max)max=count;
        }
        else
        {
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
    for (int i=0; i<n; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            if (b[i]>b[j])
            {
                int temp=b[i];
                b[i]=b[j];
                b[j]=temp;
            }
        }
    }
}
void prntAry(int *a, int n, int perLine)
{
    cout << endl;
    for (int i=0; i<n; i++)
    {
        cout << a[i] << " ";
        if(i%perLine==(perLine-1))
        {
            cout << endl;
        }
    }
}

void destroy (int *a)
{
    delete [] a;
}

float mean(int array[],int size)
{
    float total;
    for(int i=0;i<size;i++)
    {
        total+=array[i];
    }
    return total/size;
}

float median(int array[],int size)
{
    float temp=0;
    if(size%2==1)
    {
        return array[size/2];
    }
    else if(size%2==0)
    {
        temp+=array[size/2-1];
        temp+=array[size/2];
        return temp/2.0;
    }
}
int* numode(int *array, int size, int freq)
{
    int mode=0;
 
    int count=1, max=1;
    for(int i=1;i<size;i++)
    {
        if(array[i-1]==array[i])
        {
            count++;
            if(count==freq)
            {
                mode++; 
            }
        }
        else
        {
            count=1;
        }
    }
    int *a=new int[mode+2];
    a[0]=mode;
    a[1]=freq;
    count=1; 
    max=1;
    int j=0;
    
    for(int i=1;i<size;i++)
    {
        if(array[i-1]==array[i])
        {
            count++;
            if(count==freq)
            {
                a[2+j]=array[i];
                j++;
            }
        }
        else
        {
            count=1;
        }
    }
    
    return a;
}

