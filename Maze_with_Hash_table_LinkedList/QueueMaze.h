/*
  QueueMaze.h
*/

#ifndef QUEUE_L_H
#define QUEUE_L_H

#include "mazeLL.h"

typedef int QueueItemType;

class Queue
{
private:
    LinkedList  L;   //  list of queue items

public:
    Queue();
    Queue( const Queue& q );
    ~Queue();
    
    void Insert( QueueItemType newItem, QueueItemType newItem2);
    int  Delete(int &i, int &j);
    
    int  GetFront(int &i, int &j);
    char  GetEnd();
    
    bool IsEmpty();
    
    void Print();
};
#endif
