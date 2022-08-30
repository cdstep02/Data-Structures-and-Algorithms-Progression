#include <iostream>
#include <string>
#include <sstream>
using namespace std;
/*
#Exercise 3.18 pg.89
Given an array storing integers ordered by value, modify the binary search routine to return the position of the integer with the greatest 
value less than K when K itself does not appear in the array. Return ERROR if the least value in the array is greater than K.
*/

string BinarySearch(int* array, int k, int size)
{
	int upperB = size;
	int lowerB = -1;
	int nextB = 0;
	int position = 0;
	string error = "error";
	if(array[0] > k)
	{
		return error;
	}
	else
	{
	
		while(lowerB + 1 != upperB - 1)
		{
			int i = (upperB + lowerB) / 2;
			if(k < array[i])
			{
				upperB = i;
			}
			if(k > array[i])
			{
				lowerB = i;
				if(nextB < array[i])
				{
					nextB = array[i];
				}
			}
			if(k == array[i])
			{
				position = i;
				ostringstream str2;
				str2 << position;
				string sPosition = str2.str();
				return sPosition;
			}
		}
		ostringstream str1;
		str1 << nextB;
		string sNextB = str1.str();  
		return sNextB;
    }
}

int main()
{
	int arrSize = 0;
	cout << "How many numbers will your list have?";
	cin >> arrSize;
	int* inputArr = new int[arrSize];
	for(int i = 0; i < arrSize; ++i)
	{
		cout << "Enter a number:";
		int num;
		cin >> num;
		inputArr[i] = num;
	}
	cout << "Which of the values would you like to find the position of: ";
	for(int j = 0; j < arrSize; ++j)
	{
		
		cout << inputArr[j] << "  ";
	}
	cout << ":";
	int kVal= 0;
	cin >> kVal;
	string nextBest = BinarySearch(inputArr, kVal, arrSize);
	cout << "The next greatest number is: " << nextBest;
	return 0;
}
