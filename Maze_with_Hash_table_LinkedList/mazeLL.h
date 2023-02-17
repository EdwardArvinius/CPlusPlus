/*
  mazeLL.h
*/

#include <iostream>

using namespace std;


class LinkedList
{
private:

    struct node
    {
	int data;
	int data2;
	node* next;
    };

    typedef node* nodeptr;
    nodeptr start;
    nodeptr end;
    
    int count;
    
public:

    LinkedList()    // Constructor
    {
	start = NULL;
	end = start;
	count = 0;
    }
    
    ~LinkedList()   // Destructor
    {
	nodeptr p = start, n;
	
	while(p != NULL)
	{
	n = p;
	p = p ->next;
	delete n;
	}
    }


   void AddNode(int x, int y);  // Put a node at the end of the linked list.

   void DeleteNode();    //  Delete the first node in the list.
    
   int  FirstNode(int &i, int &j);    //  Return the first or last node.
   char  LastNode();
   
   void PrintNodes();    //  Output the values in the nodes, one integer per line.

   bool IsInList(char x);    //  Return true if a node with the value x
   			    //  is in the list.
      

   char Size();    //  Return a count of the number of nodes in the list.

};
