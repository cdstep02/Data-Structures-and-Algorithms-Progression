#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int factorial(int n);
double distance(double x1, double x2, double y1, double y2);
double path();
/*
we need to create the brute force algorithm. This brute force algorithm will do the following:
Traverse the graph by visiting each node exactly once and returning to the start node
*/
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
	
	//once we get and store the information we need to utilize it in a logical way
	//we will get the number of nodes, and the position of the nodes
	return 0;
}
//The purpose of this function is to find the total number of distinct paths that can be traversed
int factorial(int n) {
	int product = n;
	for(int i = n - 1; i > 0; --i) {
		product = product * i;
	}
	return product;
}

// The purpose of this function is to return the distance between 2 nodes
double distance(double x1, double x2, double y1, double y2) {
	double a = pow(x2 - x1, 2);
	double b = pow(y2 - y1, 2);
	double c = sqrt((a + b));
	return c;
}

