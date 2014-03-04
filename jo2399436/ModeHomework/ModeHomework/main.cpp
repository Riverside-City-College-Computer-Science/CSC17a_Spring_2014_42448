

//System Libraries
#include <iostream>
#include <cstdlib>

using namespace std;

//Global Constants

//Function Prototypes
void fillArray(int [], int);
void printArray(int[], int, int);
void sort(int[], int[], int);
int maxFreq(int[], int);
int nuModes(int[], int, int);


int main(int argc, char** argv)
{

	// Declare some variabels
	const int SIZE = 105;
	int array[SIZE], brray[SIZE];

	//Fill the array with 0-9
	fillArray(array,SIZE);

	//Print the array
	printArray(array,SIZE,10);

	//Sort the array
	sort(array,brray,SIZE);

	//Print tthe sorted array
	printArray(brray,SIZE,10);
	//What is the max freq
	cout << "That max frequency in the array = " << maxFreq(brray, SIZE) <<endl;

	cin.get();


	return 0;
}

// Requires sorted array for input
int maxFreq(int a[], int n)
{
	// Declare counters
	int count = 1, max = 1;
	//Lopp and compare
	for ( int i  = 1; i < n; i++)
	{
		if(a[i - 1] == a[i])
		{
			count++;
			if(count > max)
				max = count;
		}
		else 
		{
			count = 1;
		}
	}
	return max;
}

void sort(int a[], int b[], int n)
{
	// Make a copy
	for (int i = 0; i < n; i++)
	{
		b[i] = a[i];
	}
	//Sort the copied array
	for (int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
			{
				if(b[i] > b[j])
				{
					int temp = b[i];
					b[i] = b[j];
					b[j] = temp;
				}
			}
	}
}

void printArray(int a[], int n, int perLine)
{
		cout << endl;
		
		for (int i = 0; i < n; i++)
		{
			cout << a[i] << " ";
			if(i%perLine == (perLine -1))
				cout << endl;
		}
		cout << endl;
}

//Repetitive count with one digit elements
void fillArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
		a[i] = i%10;
	
}

