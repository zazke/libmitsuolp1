#include <cstddef>  // NULL
#include "bintree.h"

/* "node[ELEM]": pointer to stored element
 * "node[LEFT]": pointer to left node (leaf)
 * "node[RIGHT]": pointer to right node (leaf)
 */

enum { ELEM, LEFT, RIGHT };

void bintree_create(void *&root)
{
    root = NULL;
}

void bintree_add(void *&root, void *elem, 
        int (*compar)(void const *, void const *))
{
    void **node;
    void **newnode;


    if (!root) {
        // empty tree
        newnode = new void * [3];
        newnode[ELEM] = elem;
        newnode[LEFT] = newnode[RIGHT] = NULL;
        root = newnode;
        return;
    }
    node = (void **)root;
    if (compar(elem, node[ELEM]) < 0) 
        // less than elements go to the LEFT side of tree
        bintree_add(node[LEFT], elem, compar);
    else
        bintree_add(node[RIGHT], elem, compar);
}

/* pls do not delete retrieved object.  NULL if elem not found */
void *bintree_get(void *root, void *elem,
        int (*compar)(void const *, void const *))
{
    void **node;

    if (!root) return NULL;
    node = (void **) root;
    if (compar(elem, node[ELEM]) < 0)
        return bintree_get(node[LEFT], elem, compar);
    else if (compar(elem, node[ELEM]) > 0)
        return bintree_get(node[RIGHT], elem, compar);
    else
        return node[ELEM];
}

void bintree_traverse(void *root, void (*f)(void *))
{
    void **node = (void **)root;

    if (!root) return;
    bintree_traverse(node[LEFT], f);
    f(node[ELEM]);
    bintree_traverse(node[RIGHT], f);
}

void bintree_free(void *&root, void (*dealloc_elem)(void *))
{
    void **node = (void **)root;

    if (!root) return;
    bintree_free(node[LEFT], dealloc_elem);
    dealloc_elem(node[ELEM]);
    bintree_free(node[RIGHT], dealloc_elem);
    delete node;
    root = NULL;
}
