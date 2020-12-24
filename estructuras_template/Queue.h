/* Implementation of Queue data-structure using class template
 * 
 * data contained:
 *      class T
 *
 *  Requires:
 *      operator<<(ostream, Queue)
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "SLNode.h"

namespace tpl
{

template <typename T>
class Queue
{
    /* private by default */
    SLNode<T> *head;
    SLNode<T> *tail;
public:
    Queue();
    ~Queue();
    /* push element to the end (tail) of the queue */
    void push_back(T &data);
    /* pop element from the beginning (head) of the queue */
    T pop_front();
    /* True if queue is empty; False otherwise */
    int isempty();
};

template<typename T>
Queue<T>::Queue()
{
    head = tail = NULL;
}

template<typename T>
Queue<T>::~Queue()
{
    while (head) {
        head = head->next;
    }
}

template<typename T>
void Queue<T>::push_back(T & data)
{
    SLNode<T> *newnode;

    newnode = new SLNode<T>(data);
    if (tail) {
        tail->next = newnode;
    }
    tail = newnode;
    if (!head) {
        head = newnode;
    }
}

template<typename T>
T Queue<T>::pop_front()
{
    T datat;
    SLNode<T> *nodet;

    if (!head) {
        std::cerr << "Warning: no elements in queue to pop\n";
    }
    datat = head->data;
    nodet = head;
    head = head->next;
    delete nodet;
    if (!head)
        tail = NULL;
    return datat;
}

template<typename T>
int Queue<T>::isempty()
{
    return head == NULL;
}

}   /* end of namespace tpl */

#endif /* QUEUE_H */
