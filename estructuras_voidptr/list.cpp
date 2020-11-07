#include <cstddef>   // NULL
#include "list.h"

/* "node[ELEM]": pointer to stored element
 * "node[NEXT]": pointer to next node
 */

enum { ELEM, NEXT };

void list_create(void *&head)
{
    head = NULL;
}

void list_add(void *&head, void *elem, 
        int (*compar)(void const *, void const *))
{
    void **newnode;
    void **walk;
    void **prev;

    newnode = new void * [2];
    newnode[ELEM] = elem;
    newnode[NEXT] = NULL;
    // `alloc_ind_elem` should be an "indirect alloc" where `*elem` is
    // allocated.  Since we do not know the data, we cannot pass the data, just
    // it's address.  Works, but leads to errors.
    //elem = alloc_ind_elem(elem);
    //newnode = new void * [2];
    //newnode[ELEM] = elem;
    //newnode[NEXT] = NULL;
    
    if (head == NULL) {
        // list empty
        head = newnode;
        return;
    }
    walk = (void **) head;
    prev = NULL;
    while (walk && compar(elem, walk[ELEM]) >= 0) {
        prev = walk;
        walk = (void **) walk[NEXT];
    }
    if (!prev) {
        head = newnode;
        newnode[NEXT] = walk;
    } else {
        prev[NEXT] = newnode;
        newnode[NEXT] = walk;
    }

    // try doing it with just one indirect pointer instead of walk and prev.
    // (indirect points to the next element pointer)
}

void list_traverse(void *head, void (*f)(void *))
{
    void **walk;

    for (walk = (void **) head; walk; walk = (void **) walk[NEXT]) {
        f(walk[ELEM]);
    }
}

void list_free(void *&head, void (*dealloc_elem)(void *))
{
    void **walk;
    void **prev;

    walk = (void **) head;
    prev = NULL;
    while (walk) {
        prev = walk;
        walk = (void **) walk[NEXT];
        dealloc_elem(prev[ELEM]);
        delete prev;
    }
    head = NULL;
}
