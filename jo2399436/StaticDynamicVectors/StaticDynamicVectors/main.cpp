// Author Jazmin Onofre

//System Libraries
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

// No global constants

//Function Prototypes
void filStat(int [], int);	// fill a static array
void prnStat(int [], int, int);	//print a static array
int *fillDyn(int);	// fill a dynamic array
void prntDyn(int [], int, int);	// print a dynamic array
void destroy( int []);	// destory allocated memory
void fillVec(vector<int> &, int);
void prntVec(vector<int> &, int);


int main(int argc, char* argv)
{
	// set randoms number seed
	srand(static_cast<unsigned int>(time(0)));
	//Declare our static variables
	const int SIZE = 100;
	int sArray[SIZE];

	//Fill the static arrray
	filStat(sArray, SIZE);
	// print stat array
	prnStat(sArray, SIZE, 10);
	// declare our dynamic array
	int size = SIZE;
	int *dArray = fillDyn(size);
	prntDyn(dArray, size, 10);
	//Destory the memory allocated
	destroy(dArray);

	//declare the vector
	vector<int> vArray;
	// fill the vector
	fillVec(vArray,size);
	//print the vectr
	prntVec(vArray, 10);




	cin.ignore();
	cin.get();

	return 0;
}

void destroy( int a[])
{
	delete []a;
	a =0;
}

//Printing a Vector
void prntVec(vector<int> &a, int perLine)
{
	cout << endl;
	cout << "This is a vector." << endl;
	for (int i = 0; i < a.size();i++)
	{
		cout << a[i] << " ";
		if(i%perLine == (perLine - 1))
			cout << endl;
	}
	cout << endl;
}

//Printing a dynamic array
void prntDyn(int a[], int n, int perLine)
{
	cout << endl;
	cout << "This is a dynamic array." << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
		if(i%perLine == (perLine - 1))
			cout << endl;
	}
}



// print a static array
void prnStat(int a[], int n, int perLine)
{
	cout << "This is a Static array!";
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
		if(i%perLine == (perLine - 1))
			cout << endl;
	}
	cout << endl;
}

// Fill a dynamic array i.e vector
void fillVec(vector<int> &a, int n)
{
	for (int i = 0; i < n; i++)
	{
		a.push_back(rand()%90+10);
	}
}


int *fillDyn( int n)
{
	// declasre and allocate a dynamic array
	if(n<2)
		n =2;

	//allocate array
	int *a=new int[n];
	
	for (int i = 0; i < n; i++)
	{
		a[i] = rand()%90+10;
	}
	//return 
	return a;
}



//2 digit numbers
void filStat(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = rand()%90+10;
	}

}