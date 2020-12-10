#ifndef ESTRUCTURAS_CLASS_STACK_H
#define ESTRUCTURAS_CLASS_STACK_H

#include "./SLNode.h"

class Stack
{
    /* private by default */
    SLNode *top;
public:
    Stack();
    virtual ~Stack();
    /* push element to the top of the stack */
    void push(A data);
    /* pop element from the top of the stack */
    A pop();
    /* True if stack has no elements; False otherwise */
    int isempty();
};

#endif /* ESTRUCTURAS_CLASS_STACK_H */
