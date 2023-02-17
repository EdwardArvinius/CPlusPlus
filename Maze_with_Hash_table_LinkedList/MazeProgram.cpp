/*
MazeProgram.cpp
*/

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

#include "QueueMaze.h"

using namespace std;

int main()
{
Queue q1;

    int curr;
    int width;
    int height; 
    int row;
    int column;    
    int newRow;
    int newColumn;
    string filename;
    char const mS = 'S'; // Start cell
    char const mU = '.'; // unvisited cell
    char const mQ = 'Q'; // mark as queued
    char const mF = 'F'; // mark as finished if adjecent to G
    char const mV = 'V'; // mark as visited
    char const mG = 'G'; // goal cell
    char const mW = '#'; // wall cell
    bool goalFound = false;
    char** arrayMaze;

cout << "Enter Maze file name: ";
cin >> filename;

ifstream fIn;			 // create input stream
fIn.open( filename.c_str());     // read imput from file

if( !fIn )
{
  cout << "Unable to open file: " << filename << endl;
  exit(-1);
}


fIn >> width >> height; 	// get width and height of maze

cout << "width: " << width << " height: " << height << endl;    




arrayMaze = new char*[height]; // allocate number of rows

for(int i = 0; i < height; i++)
{
  arrayMaze[i] = new char[width]; // allocate number of columns
}

// Find S (Start)

for(row = 0; row < height; row++)
{
    for(column = 0; column < width; column++)
    {
	fIn >> arrayMaze[row][column];
	if((arrayMaze[row][column]) == mS)
	{
          newRow = row;
	  newColumn = column;
        }
    }
    cout << endl;
}

cout << "Start = (" << newRow << "," << newColumn << ")" << endl;


// Print Maze
for(row = 0; row<width; row++)
{
    for(column = 0; column<height; column++)
    {
	cout << arrayMaze[row][column];
    }
    cout << endl;
}



    q1.Insert( newRow, newColumn );      // add the start position



while(curr = q1.Delete(row,column))
{
   if((column+1) < width)
   {
      if((arrayMaze[row][column+1]) == mG)
      {
        goalFound = true;
        arrayMaze[row][column] = mF;
        break;
      }
   }
   if((row+1) < height)
   {
      if((arrayMaze[row+1][column]) == mG)
      {
	goalFound = true;
	arrayMaze[row+1][column] = mF;
	break;
      }
   }
   if(column > 0)
   {
      if((arrayMaze[row][column-1]) == mG)
      {
	goalFound = true;
	arrayMaze[row][column-1] = mF;
	break;
      }
   }
   if(row > 0)
   {
      if((arrayMaze[row-1][column]) == mG)
      {
	goalFound = true;
	arrayMaze[row-1][column] = mF;
	break;
      }
   }
   if((column+1) < width)
   {
      if((arrayMaze[row][column+1]) == mU)
      {
	q1.Insert(row,(column+1));
	arrayMaze[row][column+1] = mV;
      }
   }
   if((row+1) < height)
   {
      if((arrayMaze[row+1][column]) == mU)
      {
	q1.Insert((row+1),column);
	arrayMaze[row+1][column] = mV;
      }
   }
   if(column > 0)
   {
      if((arrayMaze[row][column-1]) == mU)
      {
	q1.Insert(row,(column-1));
	arrayMaze[row][column-1] = mV;
      }
   }
   if(row > 0)
   {
      if((arrayMaze[row-1][column]) == mU)
      {
	q1.Insert((row-1),column);
	arrayMaze[row-1][column] = mV;
      }
   }
  arrayMaze[row][column] == mV;

}

if(goalFound)
{
  cout << "The program solved the maze!" << endl;
}
else
{
  cout << "No possible solution. " << endl;
}

// Print Maze
for(int i = 0; i<width; i++)
{
    for(int j = 0; j<height; j++)
    {
	cout << arrayMaze[i][j];
    }
    cout << endl;
}


return 0;
}

