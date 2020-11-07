/* Singly liked list "structure" using only `void *` + some functions to operate
 * over it.
 *
 * Data is added to the list such that the list is always (increasingly) sorted
 * according to a comparison function.
 *
 * Usefull only to: traverse (e.g. print).
 */

#ifndef ESTRUCTURAS_VOIDPTR_LIST_H
#define ESTRUCTURAS_VOIDPTR_LIST_H

void list_create(void *&head);

/* Add the already (dynamically) allocated `elem` to the list.  Keep the list
 * sorted. */
void list_add(void *&head, void *elem, 
        int (*compar)(void const *, void const *));

void list_traverse(void *head, void (*f)(void *));

/* (dynamically) deallocates all elements of list */
void list_free(void *&head, void (*dealloc_elem)(void *));

#endif /* ESTRUCTURAS_VOIDPTR_LIST_H */
