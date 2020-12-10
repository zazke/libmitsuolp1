/* Single Link Node.  Auxiliary class to implement data structures with classes
 */

#ifndef ESTRUCTURAS_CLASS_SLNODE_H
#define ESTRUCTURAS_CLASS_SLNODE_H

#include "A.h"

class List;
class Stack;
class PriorityQueue;

class SLNode
{
    /* private by default */
    A data;
    class SLNode *next;
public:
    SLNode();
    SLNode(A const &data);
    friend class List;
    friend class Stack;
    friend class PriorityQueue;
};

#endif /* ESTRUCTURAS_CLASS_SLNODE_H */
