#include <iostream>
#include "Stack.h"

using namespace std;

Stack::Stack()
{
    top = NULL;
}

Stack::~Stack()
{
    SLNode *prev;

    while (top) {
        prev = top;
        top = top->next;
        delete prev;
    }
}

void Stack::push(A data)
{
    SLNode *newnode;

    newnode = new SLNode(data);
    newnode->next = top;
    top = newnode;
}

A Stack::pop()
{
    A datat;
    SLNode *nodet;

    if (!top) {
        cerr << "Warning: no elements to pop in stack\n";
        return datat;
    }

    nodet = top;
    datat = top->data;
    top = top->next;
    delete nodet;
    return datat;
}

int Stack::isempty()
{
    return top == NULL;
}
