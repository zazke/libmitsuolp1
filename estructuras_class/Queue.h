/* Implementation of Queue using classes.  This time I used Doubly Linked Nodes
 * just to practice with them.
 */

#ifndef ESTRUCTURAS_CLASS_QUEUE_H
#define ESTRUCTURAS_CLASS_QUEUE_H

#include "DLNode.h"

class Queue
{
    /* private by default */
    DLNode *head;
    DLNode *tail;
public:
    Queue();
    ~Queue();
    /* push element to the end (tail) of the queue */
    void push_back(int data);
    /* pop element from the beginning (head) of the queue */
    int pop_front();
    /* True if queue is empty; False otherwise */
    int isempty();
};

#endif /* ESTRUCTURAS_CLASS_QUEUE_H */
