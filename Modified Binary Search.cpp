#include <iostream>
#include <cmath>
using namespace std;
/*
Excercise 3.17 pg.89
Given an array storing integers ordered by value, modify the binary search routine to return the position of the first integer with value 
K in the situation where K can appear multiple times in the array. Be sure that your algorithm is T(log n), that is, do not resort to 
sequential search once an occurrence of K is found.
*/
//this function handles the modified binary search
int modifiedBinary(int* array, int k, int size)
{
	int upperB = size;
	int lowerB = -1;
	
	//the first position of the k-value
	int position;
	int counter = 0;
	while(lowerB + 1 != upperB - 1)
	{
		int i = (upperB + lowerB) / 2;
		//int difference = (size - 1) - i;
		if(k < array[i])
		{
			upperB = i;
		}
		if(k == array[i])
		{
			position = i;
			counter = 1;
			if(i == 0)
			{
				return position;
			}
			else
			{
						
				if(k > array[i - 1])
				{
					return position;
				}
				else
				{
				
					position = i - 1;
					upperB = i - 1;
				
				}
			
			}
			
		}
		if(k > array[i])
		{
			lowerB = i;
		
		}
	}
	return position;
}


int main()
{
	int arraySize = 0;
	cout << "How many numbers will your list have?:";
	cin >> arraySize;
	int* sortedArray = new int[arraySize];
	for(int i = 0; i < arraySize; ++i)
	{
		cout << "Enter a number:";
		int num;
		cin >> num;
		sortedArray[i] = num;
	}
	cout << "Which of the values would you like to find the first instance of: ";
	for(int j = 0; j < arraySize; ++j)
	{
		
		cout << sortedArray[j] << "  ";
	}
	cout << ":";
	int kValue = 0;
	cin >> kValue;
	int firstP = modifiedBinary(sortedArray, kValue, arraySize);
	
	cout << "The first instance of " << kValue << " is at position " <<  firstP << " in the array";
	
	return 0;	
}
