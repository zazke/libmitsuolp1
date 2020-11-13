/* "general use" queue.  Names borrowed from STL queue
 *
 * Caller takes care of memory management.  Neither push or pop cares.  They
 * only receive pointers.
 *
 * Usefull only to: FIFO pointers
 */

#ifndef ESTRUCTURAS_VOIDPTR_QUEUE_H
#define ESTRUCTURAS_VOIDPTR_QUEUE_H

void queue_create(void *&q);

/* ONLY call this if queue is empty.  Otherwise you might get memory leaks */
void queue_delete(void *&q);

/* push the already allocated pointer to the back (@tail) of the queue */
void queue_push(void *q, void *elem);

/* pop front (@head) element of the queue */
void *queue_pop(void *q);

/* returns 1 if empty, 0 otherwise. */
int queue_isempty(void *q);

/* Access front (@head) element.  Do not delete it please! */
void *queue_front(void *q);

/* Access back (@tail) element.  Do not delete it please! */
void *queue_back(void *q);

/* traverses queue front to back (FIFO) */
void queue_traverse(void *q, void (*f)(void *))

#endif /* ESTRUCTURAS_VOIDPTR_STACK_H */
