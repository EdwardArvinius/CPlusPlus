#include<iostream>
#include<fstream>
using namespace std;

//------ Function Prototypes---------

double highTemp(double[]);
double lowTemp(double[]);
double avgHighTemp(double[]);
double avgLowTemp(double[]);
double changeInSnowDepth(double[]);


int main(){


ifstream infile; 


int rows = 31;

int days[31];
double High[31];
double Low[31];
double Precip[31];
double Snow[31];
double SnowDepth[31];

infile.open("weather1337.txt"); // open the file
for(int i = 0; i < rows; i++){
infile >> days[i];
infile >> High[i];
infile >> Low[i];
infile >> Precip[31];
infile >> Snow[31];
infile >> SnowDepth[31];

/*
for(int k = 0; k < 31; k++)
{

cout << SnowDepth[k] << endl;

}
*/

}

infile.close();

double highestTemp = highTemp(High);
cout << "The highest recorded temerature is: " <<  highestTemp << endl;

double lowestTemp = lowTemp(Low);
cout << "The lowest recorded temperature is: " << lowestTemp << endl;

double averageHigh = avgHighTemp(High);
cout << "The average daily high temperature is: " << averageHigh << endl;

double averageLow = avgLowTemp(Low);
cout << "The average daily low temperature is: " << averageLow << endl;

}



//----- highest recorded temperature - Function -------
double highTemp(double High[]){
double highestTemp= High[0];
for(int i = 1; i < 31; i++){
if(highestTemp < High[i])
highestTemp = High[i];
}
return highestTemp;
}



//----- lowest recorded temperature- Function -------
double lowTemp(double Low[]){
double lowestTemp = Low[0];
for(int i = 1; i < 31; i++){
if(lowestTemp > Low[i])
lowestTemp = Low[i];
}
return lowestTemp;

}


//----- average daily high temerature- Function -----
double avgHighTemp(double High[]){
double averageHigh = 0;
for(int i=0; i < 31; i++)
	averageHigh = averageHigh + High[i];
averageHigh = averageHigh / 31;
return averageHigh;
}


//----- average daily low temperature- Function -----
double avgLowTemp(double Low[]){
double averageLow = 0;
for(int i=0; i < 31; i++)
	averageLow = averageLow + Low[i];
averageLow = averageLow / 31;
return averageLow;
}


