/* Doubly Link Node.  Auxiliary class to implement data structures with classes
 */

#ifndef ESTRUCTURAS_CLASS_DLNODE_H
#define ESTRUCTURAS_CLASS_DLNODE_H

class DoublyLinkedList;
class Queue;
class BST;

class DLNode
{
    /* private by default */
    int data;
    DLNode *next;
    DLNode *prev;
public:
    DLNode();
    DLNode(int data);
    virtual ~DLNode();
    friend DoublyLinkedList;
    friend Queue;
    friend BST;
};

#endif /* ESTRUCTURAS_CLASS_DLNODE_H */
