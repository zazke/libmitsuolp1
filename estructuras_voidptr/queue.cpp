#include <cstddef>   // NULL
#include "stack.h"

/* "ends[HEAD]": pointer to front node (NULL if queue empty)
 * "ends[TAIL]": pointer to back node (NULL if queue empty)
 */

enum { HEAD, TAIL};

/* "node[ELEM]": pointer to stored element
 * "node[NEXT]": pointer to next node
 */

enum { ELEM, NEXT };

void queue_create(void *&q)
{
    void **ends;

    ends = new void * [2];
    ends[HEAD] = ends[TAIL] = NULL;
    q = ends;
}

void queue_delete(void *&q)
{
    void **ends;

    ends = (void **)q;
    delete ends;
    q = NULL;
}

void queue_push(void *q, void *elem)
{
    void **ends = (void **)q;
    void **newnode;
    void **node;

    newnode = new void * [2];
    newnode[ELEM] = elem;
    newnode[NEXT] = NULL;

    if (!ends[HEAD]) {
        // queue is empty
        ends[HEAD] = ends[TAIL] = newnode;
    }
    else {
        node = (void **)ends[TAIL];
        node[NEXT] = newnode;
        ends[TAIL] = newnode;
    }
}

void *queue_pop(void *q)
{
    void **ends = (void **)q;
    void **node;
    void *elem;

    if (!ends[HEAD]) {
        // queue is empty
        return NULL;
    }
    else {
        if (ends[HEAD] == ends[TAIL]) {
            // last element
            ends[TAIL] = NULL;
        }
        node = (void **)ends[HEAD];
        elem = node[ELEM];
        ends[HEAD] = node[NEXT];
        delete node;
        return elem;
    }
}

int queue_isempty(void *q)
{
    void **ends = (void **) q;

    return (ends[HEAD] == NULL) ? 1 : 0;
}

void *queue_front(void *q)
{
    void **ends = (void **) q;

    if (!ends[HEAD]) return NULL;
    else return ((void **) ends[HEAD])[ELEM];
}

void *queue_back(void *q)
{
    void **ends = (void **) q;

    if (!ends[HEAD]) return NULL;
    else return ((void **) ends[TAIL])[ELEM];
}
