// Made by Edward Arvinius
// Run this game in your terminal

#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
#include<cstdlib>
using namespace std;

//----- Function Prototypes -----

void print(string m[][10], int rowSize, int columnSize);
void summonGophers(string g[][10], int rowSize, int columnSize);
void checkFunction(string m[][10], string g[][10], int rowSize, int columnSize, int xValue, int yValue);
void countValues(string m[][10], string g[][10], int rowSize, int columnSize, int xValue, int yValue);

//-------- Main Function --------
int main()
{

//--------- Variables ----------
const int mapRow = 10;
const int mapColumn = 10;
const int gopherRow = 10;
const int gopherColumn = 10;

int xValue;
int yValue;
bool go = true;
bool count = true;

//--------- 2d-arrays ---------
string m[mapRow][mapColumn];
string g[gopherRow][gopherColumn];

//----- Map for-loop ---------
for(int i = 0; i < mapRow; i++)
  {
    for(int j = 0; j < mapColumn; j++)
      {
        m[i][j] = "+";
      }
  }



//----- Gopher for-loop ------
for(int k = 0; k < gopherRow; k++)
  {
    for(int h = 0; h < gopherColumn; h++)
      {
        g[1][2] = "g";;
        g[1][8] = "g";;
        g[2][5] = "g";;
        g[2][6] = "g";;
        g[5][3] = "g";;
        g[6][9] = "g";;
        g[7][2] = "g";;
        g[8][5] = "g";;
        g[3][1] = "g";;
        g[9][2] = "g";;
  }
}
  print(m, mapRow, mapColumn);

  while(go == true){

	count = true;
	while(count == true){

  		cout << "Enter x-value betewwn 0 - 9: " << endl;
  		cin >> yValue;
  		cout << "Enter y-value between 0 - 9: " << endl;
		cin >> xValue;


     		if(xValue > 9 || xValue < 0)	{
     			cout << "Invalid choice, try again " << endl;
     		}	else{ count = false;
     				if(yValue > 9 || yValue < 0){
     					cout << "Invalid choice, try again " << endl;
     				}else{ count = false;


     					if(m[xValue][yValue] != "+"){
     						cout << "Already opened, try again. " << endl;
     					}else{ count = false;
    
    					}
   				}
  			}
 		}


	if(g[xValue][yValue] == "g"){
	cout << "You hit a gopher! You lose! " << endl;
	m[xValue][yValue]="g";
	break;
	}
	countValues(m, g, mapRow, mapColumn, xValue, yValue);
	print(m, mapRow, mapColumn);

	}

return 0;
}



//---------------- Functions -----------------------

void print(string m[][10], int rowSize, int columnSize)
  {
    int score = 0;
    cout << "  0123456789" << endl;
    for(int i = 0; i < rowSize; i ++)
      {
        cout << i;
       	cout << "|";
          for(int j = 0; j < columnSize; j++)
          {


           if(m[i][j] == "-1"){
            cout << "0";
            }else
            cout << m[i][j];
   	    
		    if(m[i][j] != "+"){ //Score counter
		    score++;
          }
        }
	cout << "|" << endl;
      }
    cout << endl;
    cout << "|-----------------------------------|" << endl;
    cout << "|------ Open 90 slots to win! ------|" << endl;
    cout << "|---------- Slots opened: " << score << " --------|" << endl;
    cout << "|-----------------------------------|" << endl;
    cout << endl;
	if(score >= 90){
	cout << "------ Congratulations! You reached 90 points! You winn!!! -------" << endl;
       
  }
 }

void summonGophers(string g[][10], int rowSize, int columnSize)
  {
    for(int k = 0; k < rowSize; k++)
      {
        for(int h = 0; h < columnSize; h++)
          {
            cout << g[k][h];
          }
	cout << endl;
      }
  }
void countValues(string m[][10], string g[][10], int rowSize, int columnSize, int xValue, int yValue)
{
 
int temp = 0;
for(int i = -1; i < 2; i++)
    {
     for(int j = -1; j < 2; j++)
    {
    int newX = xValue + i;
    int newY = yValue + j;
    if((newX > -1) && (newY > -1) && (newX < 10) && (newY < 10)){ 
    if(g[newX][newY]=="g")
    {
     temp++;
    }
   }
  }
 }

  char tempchar = '0' + temp;
  if(m[xValue][yValue] != "-1"){
  m[xValue][yValue]= tempchar;
  }
  if(tempchar == '0'){
  checkFunction(m, g, rowSize, columnSize, xValue, yValue);
  }
 }

void checkFunction(string m[][10], string g[][10], int rowSize, int columnSize, int xValue, int yValue)
  {
   if(m[xValue][yValue] == "0")
    {
    m[xValue][yValue] = "-1";

    if((xValue > 0) && (yValue > 0))
    { 
     countValues(m, g, rowSize, columnSize, xValue-1, yValue-1);
    }

    if(xValue > 0)
    {
     countValues(m, g, rowSize, columnSize, xValue-1, yValue);
    } 
    if((xValue > 0) && (yValue < 9))
    {
     countValues(m, g, rowSize, columnSize, xValue-1, yValue+1);
    } 
    if(yValue < 9)
    {
     countValues(m, g, rowSize, columnSize, xValue, yValue+1);
    }
    if((xValue < 9) && (yValue < 9))
    {
     countValues(m, g, rowSize, columnSize, xValue+1, yValue+1);
    }
    if((xValue < 9))
    {
     countValues(m, g, rowSize, columnSize, xValue+1, yValue);
    } 
    if((yValue > 0) && (xValue < 9))
    {
     countValues(m, g, rowSize, columnSize, xValue+1, yValue-1);
    } 
    if((yValue > 0))
    { 
     countValues(m, g, rowSize, columnSize, xValue, yValue-1);
    }
  }  
}