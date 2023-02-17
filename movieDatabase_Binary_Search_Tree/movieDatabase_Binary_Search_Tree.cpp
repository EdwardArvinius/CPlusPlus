/*

Edward Arvinius
CS 121
Bruce Bolden
11/5/2018

This program holds information for a small movie database
using a binary search tree

*/

#include <istream>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

typedef struct treeNode // Declaration of Tree Node 
{
  int year;
  string title;
  list < string > actors;
  treeNode *left;
  treeNode *right;

} *treePtr;

treePtr root = NULL;

//Function Prototypes
void Display_All_Titles( treePtr root );		     // Displays all movie titles
void Display_Actors_Of_Movies( treePtr root, string title ); // Input Movie, Display Actors
void Display_Movies_Of_Actors( treePtr root, string name );  // Input Actor, Display Movies
void Display_Movies_Year( treePtr p, int key); 		     // Display movies of a specific year
treePtr Fill_BST(treePtr p, int y, string t, list < string > a); // Fills the BST


int main ()
{

  ifstream inFile ("tvDB.txt");
  string S;
  treePtr root = NULL;
  int count = 0;
  if (inFile.is_open ()) // This checks if the file is opened
    {
      while (getline (inFile, S)) // Read in first line
	{
	  if (S == "") 
	    {
	      continue;
	    }
	  count++;

	  int y = S.find_last_of (" "); // This removes the () from year
	  string title = S.substr (0, y);  // Finds title
	  string year = S.substr (y + 2, S.length () - y - 3); // Finds year
	  list < string > actor; 	// declaration of linked list

	  while (getline (inFile, S)) // Loops to read the actors into the list
	    {
	      if (S == "")
		{
		  break;
		}
	      else
		{
		  actor.push_back (S);
		}
	    }
           root = Fill_BST (root, atoi(year.c_str ()), title, actor); //Fills BST
	}
    }

  int choice;
  int Quit_Program = 0;

  do	// Menu			
    {
	cout << "\n----- Welcome to the Movie Program! ----- " << endl;
        cout << "-------- What would you to do:  --------- " << endl;
	cout << endl;
	cout << "(1) Display all movies in the library? " << endl;
	cout << "(2) Search for an actor and see what movies he/she has been in?" << endl;
	cout << "(3) Search for a year and see what movies came out that year? " << endl;
	cout << "(4) Search for a movie and see all the actors in it? " << endl;
	cout << "(0) Exit the program" << endl;
      
	cin >> choice;

      switch (choice)
	{

	case 0:
	  cout << "Thank you, good bye." << endl;
	  Quit_Program = 1;
	  break;
	case 1: 		     // Displays all movie titles
	  Display_All_Titles (root);		    
	  break;  
	case 2:
	  {
	    string name;
	    cout << "Enter a name: " << endl;
	    cin.ignore ();
	    getline (cin, name); //Gets input from user
	    cout << endl;
	    cout << "Here are all the movie(s) with " << name << ":" << endl;

            Display_Movies_Of_Actors(  root,  name );  // Input Actor, Display Movies
	    break;
	  }

	case 3:
	  int year;
	  cout << "Enter the year you would like to search for: " << endl;
	  cin >> year;
	  cout << endl;
	  cout << "The movie(s) that were made in " << year << " are:" << endl;

          Display_Movies_Year( root, year ); 		     // Display movies of a specific year
	  break;

	case 4:
	  {
	    string title;
	    cout << "Enter the title of a movie: " << endl;
	    cin.ignore ();
	    getline (cin, title);//Gets input from user
	    cout << endl;
	    cout << "The actors in the movie " << title << " are:" << endl;

            Display_Actors_Of_Movies( root, title ); // Input Movie, Display Actors
	    break;
	  }

	default: //Default case
	  cout << "Try again." << endl;

	}

    }
  while (Quit_Program == 0);

  return 0;
}



// Functions



void Display_Actors_Of_Movies( treePtr root, string title ) // Input Movie, Display Actors
{
  if (root == NULL)
    return;
  if (root->left)
    Display_Actors_Of_Movies (root->left, title);

  if (root->title == title)
    {  //Loop and print actors if the movie title is found in tree node
      for (list < string >::iterator temp = root->actors.begin (); 
			temp != root->actors.end (); ++temp)	
{
	  cout << *temp << endl;

	}
    }

  if (root->right)
    Display_Actors_Of_Movies (root->right, title);
}



void Display_Movies_Year( treePtr p, int key) 	 // Display movies of a specific year
{

  if (p == NULL)
    return;
  if (p->left) //Traverse through tree
    Display_Movies_Year (p->left, key);
  if (p->year == key)
    {
      cout << p->title << endl;
    }
  if (p->right)
    Display_Movies_Year (p->right, key);
}

void Display_Movies_Of_Actors( treePtr root, string name )  // Input Actor, Display Movies
{
  if (root == NULL)
    return;
  if (root->left)
    Display_Movies_Of_Actors (root->left, name);	//loop and traverse through the linked list to find actor
  for (list < string >::iterator temp = root->actors.begin ();
       temp != root->actors.end (); ++temp)
    {

      if (*temp == name) // Prints the movie title if the actor is found in the list
	{
	  cout << root->title << endl;
	}
    }
  if (root->right)
    Display_Movies_Of_Actors (root->right, name);

}


void Display_All_Titles(treePtr root) //Prints film titles
{
  if (root == NULL)
    return;
  if (root->left) //Traverse through tree
    Display_All_Titles (root->left);
  cout << root->title << endl;
  if (root->right)
    Display_All_Titles (root->right);
}

treePtr Fill_BST (treePtr p, int y, string t, list < string > a)//Fill Tree
{
  treePtr temp = new treeNode;
  temp->year = y;
  temp->title = t;
  temp->actors = a;
  temp->left = NULL;
  temp->right = NULL;
  if (p == NULL) //First node
    {
      p = temp;
    }
  else
    {

      treePtr curr = p;
      treePtr prev = p;
      while (curr != NULL) // uses the year as key to organize the tree
	{
	  if (curr->year > y)
	    {
	      prev = curr;
	      curr = curr->left;
	    }
	  else
	    {
	      prev = curr;
	      curr = curr->right;
	    }
	}
      if (prev->year > y)
	{
	  prev->left = temp;
	}
      else
	{
	  prev->right = temp;
	}
    }

  return p;
}
