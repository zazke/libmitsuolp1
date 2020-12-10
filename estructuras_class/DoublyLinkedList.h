/* Implementation for INF281 of doubly linked list using classes */

#ifndef ESTRUCTURAS_CLASS_DOUBLYLINKEDLIST_H
#define ESTRUCTURAS_CLASS_DOUBLYLINKEDLIST_H

#include "DLNode.h"

class DoublyLinkedList
{
    /* private by default */
    DLNode *head;
public:
    DoublyLinkedList();
    virtual ~DoublyLinkedList();
    /* insert in orderly manner */
    void insert(int data);
    /* print whole list to stdout */
    void print();
};
    

#endif /* ESTRUCTURAS_CLASS_DOUBLYLINKEDLIST_H */
