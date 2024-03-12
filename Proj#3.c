#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
#include <string.h>


/*
We need to read input from a file and determine the best path using a greedy heuristic algorithm to do that.

A greedy herustic algorithm uses the greedy aproach to solving a problem which chooses the best move at a point in time. For this problem it would choose the closest vertex to the current node

To start this we must read the input from the files. We can do this by using either fgets or fscanf to scan through the file to get what we want. To do this we need to see how both fscanf and fgets work. Then we will store the input into some type of structure. 
We will use fgets to get and store the inputs

Using 
*/
double distance(double x1, double x2, double y1, double y2); 
	
int main(int argc, char *argv[])
{
	
	//to 
	
	for(int i = 1; i <= argc; ++i)
	{
		FILE *fp;
		int numOfPoints = 0;
	
		double coordinates[3][numOfPoints];
		char numPoints[2]; //hows the number of nodes as a string
		double placeholder = 0;
		char temp [60];
		char dim[9] = "DIMENSION";
		//makes sure the file can be opened
		if((fp = fopen(argv[i], "r")) == NULL)
		{
			printf("Could not open file \n");
			exit(1);
		}
		
		int t = 0; //another counter used for parsing input
		int l; //used for parsing input
		int f = 0; //boolean used for decision making
		int col = 0; //indicates teh column the stuff is in
		int h = 0; //used for storing parsed values
		//this will get input from the file
		while(fgets(temp, 60, fp) != NULL)
		{
			//this will show us how many nodes there are so we can declare our array
			while(f == 0)
			{
				if(strstr(temp, dim) != NULL)
				{
			
						if(temp[t] == ' ')
						{
							l = t + 1;
							while(temp[l] != NULL)
							{
								numPoints[h] = temp[l];
								++h;
								++l;
								f = 1;
							}
							numOfPoints = atoi(numPoints);
						}
						++t;
				}
			}
			int c = 0;//counter to iterate through the line
			int r = 0; //row
			//parses the coordinates
			while(temp[c] != NULL)
			{
				char* num;
				while(temp[c] != ' ')
				{
					num = (char*)malloc(1 * sizeof(char));
					int k = 0;
				//we are storing stuff by having each 3 rows(these contain the node num and coordinates) that support numPoints columns
					num[k] = temp[c];
					++k;
				}
				coordinates[r][col]= atof(*num);
				++r;
				++c;
				
			}
			++col;			
		} 
		
		fclose(fp);
		double path[1] = {1};
		double currNode = 1;
		double minPath = 0;
		
		
	}
	
	printf("Here are all the values: \n");
	//prints of each row
	for(int v = 0; v < numOfPoints; ++v)
	{
		//prints of the columns in the row
		for(int b = 0; b < 3; ++b) 
		{
			printf("%lf ", coordinates[b][v]);
			
		}
		printf("\n");
	}

}
// The purpose of this function is to return the distance between 2 nodes

double distance(double x1, double x2, double y1, double y2) {
	double a = pow(x2 - x1, 2);
	double b = pow(y2 - y1, 2);
	double c = sqrt((a + b));
	return c;
}


