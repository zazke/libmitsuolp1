#include <iostream>
#include "Queue.h"

using namespace std;

Queue::Queue()
{
    head = tail = NULL;
}

Queue::~Queue()
{
    while (head) {
        head = head->next;
        delete head->prev;
    }
}

void Queue::push_back(int data)
{
    DLNode *newnode;

    newnode = new DLNode(data);
    newnode->prev = tail;
    if (tail) {
        tail->next = newnode;
    }
    tail = newnode;
    if (!head) {
        head = newnode;
    }
}

int Queue::pop_front()
{
    int datat;
    DLNode *nodet;

    if (!head) {
        cerr << "Warning: no elements in queue to pop\n";
        return -1;
    }
    datat = head->data;
    nodet = head;
    head = head->next;
    delete nodet;
    if (!head)
        tail = NULL;
    return datat;
}

int Queue::isempty()
{
    return head == NULL;
}
