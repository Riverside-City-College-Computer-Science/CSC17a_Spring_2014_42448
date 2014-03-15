/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on March 13, 2014, 7:29 PM
 */

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

float mean(int *,int);
void sort(int [], int);
/*
 * 
 */
int main(int argc, char** argv) {

    //get desired array size
    cout << "Please enter array size:\n";
    int size;
    cin >> size;
    cout << "You entered " << size << " as array size.\n\n";
   
    int* testScores = new int[size];
    
    cout << "Please enter the test scores (negative numbers are not allowed): \n";
	
        int i = 0;
	int score;
	
	//enter test scores
	while (i < size)
	{
		cin >> score;
		while (score < 0)
		{
			cout << "You cannot enter a negative score! Try again: \n";
			cin >>score;
		}
		*(testScores+i) = score;
		i++;
	}
        
        cout << "You entered: \n";
        i=0;
        while (i < size)
        {
            cout << *(testScores+i) << "\n";
            i++;
        }
        cout << "\n";
        
       

	//function that sorts in ascending order
        sort(testScores,size);
        cout << "The test scores in ascending order are: \n";
        i=0;
        while (i < size)
        {
            cout << *(testScores+i) << "\n";
            i++;
        }
        cout << "\n";
        
        
	//call the function for average
        cout << "\nThe average test score is: \n" << mean(testScores, size);
        
	//display sorted scores and averages with appropriate headings

	delete[] testScores;
    
   
    return 0;
}

//function to calculate average score
float mean(int array[],int size)
{
    float total=0;
    for(int i=0;i<size;i++)
    {
        total+= *(array+i);
    }
    return total/size;
}

void sort(int a[], int n)
{
    {
    //Finds the minimum at this starting position
    for(int i=0;i<n-1;i++)
    {
        //Swaps the larger values as you go down the list
        for(int j=i+1;j<n;j++)
        {
            //Check for swap
            if(*(a+i)>*(a+j))swap(*(a+i),*(a+j));
        }
    }
    }
   
}
