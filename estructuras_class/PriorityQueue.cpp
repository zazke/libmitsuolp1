#include <iostream>
#include "PriorityQueue.h"

using namespace std;

PriorityQueue::PriorityQueue()
{
    head = tail = NULL;
}

PriorityQueue::~PriorityQueue()
{
    SLNode *prev;

    while (head) {
        prev = head;
        head = head->next;
        delete prev;
    }
    tail = NULL;    // :)
}

void PriorityQueue::push_back(A const &data)
{
    SLNode *walk, *prev, *newnode;

    newnode = new SLNode(data);
    walk = head;
    prev = NULL;
    while (walk) {
        if (walk->data << data)
            break;
        prev = walk;
        walk = walk->next;
    }
    newnode->next = walk;
    if (prev) {
        prev->next = newnode;
    } else {
        head = newnode;
    }
    if (!walk) {
        tail = newnode;
    }
}

A PriorityQueue::pop_front()
{
    A datat;
    SLNode *nodet;

    if (!head) {
        cerr << "Warning: no elements in queue to pop\n";
        return datat;
    }
    datat = head->data;
    nodet = head;
    head = head->next;
    delete nodet;
    if (!head)
        tail = NULL;
    return datat;
}

int PriorityQueue::isempty()
{
    return head == NULL;
}
