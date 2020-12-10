/* Implementation of PriorityQueue.  Priority data is inside object. 
 * Object has to have operator <<() that sorts it by priority (weak total
 * order).
 */

#ifndef ESTRUCTURAS_CLASS_PRIORITYQUEUE_H
#define ESTRUCTURAS_CLASS_PRIORITYQUEUE_H

#include "SLNode.h"

class PriorityQueue
{
    /* private by default */
    SLNode *head;
    SLNode *tail;
public:
    PriorityQueue();
    virtual ~PriorityQueue();
    /* push element to the end (tail) of the sub-queue of elements with the
     * same priority as `data` */
    void push_back(A const &data);
    /* pop element from the beginning (head) of the queue */
    A pop_front();
    /* True if queue is empty; False otherwise */
    int isempty();
};

#endif /* ESTRUCTURAS_CLASS_PRIORITYQUEUE_H */
