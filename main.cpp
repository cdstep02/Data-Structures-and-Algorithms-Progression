#include "AUList.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
using namespace std;
//figure this out today
AUList csvtoAUList(string csvfile) { //convert a csv file to a list structure
    AUList retCCList;
    int counter = 0;
	ifstream ReadFile(csvfile); //open the csv file for reading
    string line, curvalue;
    //here we need to delete the columns in the csv file
	getline(ReadFile, line); //throw away the first line (column names)
    while (getline(ReadFile,line) && counter < 200) {        
        stringstream ss(line); //turn the line into a string-stream
        int fielditer=0;
        AircraftStrike newrec;
		while(getline(ss, curvalue, ',')){ //Separate each variable per sample from the comma separator
            switch (fielditer) { //some values need to be converted to an int using stoi
            	case 0:
            		if(curvalue == "")//conditional statement ensures that we 
            		{
            			newrec.year = -1;
					}
					else
					{
						newrec.year=stoi(curvalue);
					}
				  	break;
            	case 1: newrec.aircraft=curvalue; break;
            	case 2:
					if(curvalue == "")
					{
						newrec.engines = -1;
					} 
					else
					{
						newrec.engines=stoi(curvalue);
					}
				 	break;
            	case 3: newrec.phase=curvalue; break;
            	case 4: newrec.species=curvalue; break;
            	case 5: newrec.impact=curvalue; break; 
			}
            fielditer++;
        }
        retCCList.PutItem(newrec);
        counter++;
    }
    return retCCList;
}

int main(int argc, char** argv) {
	AUList StrikeData=csvtoAUList("database.csv");
	StrikeData.PrintList(); //Print the data record-by-record
}
    
