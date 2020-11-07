#include <cstddef>   // NULL
#include "stack.h"

/* "node[ELEM]": pointer to stored element
 * "node[NEXT]": pointer to next node
 */

enum { ELEM, NEXT };

void stack_create(void *&top)
{
    top = NULL;
}

void stack_push(void *&top, void *elem)
{
    void **newnode;

    newnode = new void * [2];
    newnode[ELEM] = elem;
    newnode[NEXT] = top;

    top = newnode;
}

void *stack_pop(void *&top)
{
    void **node;
    void *elem;

    if (!top) {
        // empty stack
        return NULL;
    }
    else {
        node = (void **)top;
        elem = node[ELEM];
        top = node[NEXT];
        delete node;
        return elem;
    }
}

int stack_isempty(void *top)
{
    return (top == NULL) ? 1 : 0;
}

void *stack_top(void *top)
{
    if (!top) return NULL;
    else return ((void **) top)[ELEM];
}
