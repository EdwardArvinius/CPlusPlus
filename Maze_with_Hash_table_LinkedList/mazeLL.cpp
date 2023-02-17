/* 
 mazeLL.cpp
*/
#include <iostream>
#include "mazeLL.h"

using namespace std;

void LinkedList::AddNode(int x, int y)
{
    nodeptr n, nTmp;

    n = new node;
    n->data = x;  // initialize row #
    n->data2 = y; // initialize column #
    n->next = NULL;
    count++;

    if( start == NULL )
    {
        start = n;
        end   = start;
    }
    else
    {
        end->next = n;
        nTmp = end;
        end  = nTmp->next;
    }
}

void LinkedList::DeleteNode()
{
    nodeptr curr;

    if( start != NULL )
    {
        curr = start;
        start = start->next;
        delete curr;
        
        count--;
    }
}

int LinkedList::FirstNode(int &i, int &j)
{
    
    
    if( start != NULL )
	{
        i = start->data;
        j = start->data2;
       }
    return 0;
}

char LinkedList::LastNode()
{
    if( end != NULL )
        return end->data;
}

void LinkedList::PrintNodes()
{
    nodeptr p = start;

    while( p != NULL )
    {
        cout << p->data;
	cout << p->data2 << endl;
        p = p->next;
    }

}


bool LinkedList::IsInList(char x)
{
    nodeptr p = start;

    while (p != NULL && x > p->data)
        p = p->next;

    return (x == p->data);
}


char LinkedList::Size()
{
    return count;
}
 
