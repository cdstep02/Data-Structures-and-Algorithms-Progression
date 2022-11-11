#include "StackType.h"
#include <iostream>
#include <string>

using namespace std;

int WellFormedParExp(string exp) 
{
	StackType<char> ExpHolder;
	int numPar = 0;
	for(int i = 0; i < exp.size(); ++i)
	{
		char oPar = '(', cPar = ')';
		char oBra = '[', cBra = ']';
		char oCur = '{', cCur = '}';
		char pa = exp[i];
		char tempPa;
		if(pa == oPar || pa == oBra || pa == oCur)
		{
			if(pa == oPar)
			{
				tempPa = cPar;
			}
			else if(pa == oBra)
			{
				tempPa = cBra;
			}
			else if(pa == oCur)
			{
				tempPa = cCur;
			}
			ExpHolder.Push(tempPa);
		}
		else if(pa == cPar || pa == cBra || pa == cCur)
		{
			//tests to see if there is an opening parenthesis
			if(ExpHolder.IsEmpty() == true)
			{
				return -1;
			}
			//tests to see if the closing parenthesis matches the one at the top of the stack
			else if(pa != ExpHolder.Peek())
			{
				return -1;
			}
			//if closing parenthesis matches the one at the top of the stack we have a set of parenthesis
			else
			{
				numPar += 1;
				ExpHolder.Pop();
			}
		}
	}
	if(numPar == 0 && ExpHolder.IsEmpty() == false)
	{
		return - 1;
	}
	return numPar;
}


