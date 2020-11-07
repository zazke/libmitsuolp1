/* "general use" binary tree
 *
 * Data is inserted mantaining the tree ordered.
 *
 * Usefull only to: Store and retrieve (random) data fast,  traverse tree.
 */

#ifndef ESTRUCTURAS_VOIDPTR_BINTREE_H
#define ESTRUCTURAS_VOIDPTR_BINTREE_H

void bintree_create(void *&root);

/* allocate elem yourself before inserting in tree */
void bintree_add(void *&root, void *elem, 
        int (*compar)(void const *, void const *));

/* pls do not delete retrieved object.  NULL if elem not found */
void *bintree_get(void *root, void *elem,
        int (*compar)(void const *, void const *));

void bintree_traverse(void *root, void (*f)(void *));

void bintree_free(void *&root, void (*dealloc_elem)(void *));

#endif /* ESTRUCTURAS_VOIDPTR_BINTREE_H */
