/* Implementation of Binary search tree using just classes (No
 * templates). 
 */

#ifndef ESTRUCTURAS_CLASS_BST_H
#define ESTRUCTURAS_CLASS_BST_H

#include "DLNode.h"

class BST
{
    /* private access by default */
    DLNode *root;
    void destroyp(DLNode *root);
    void insertp(DLNode *&root, DLNode *newnode);
    void printp(DLNode *root);
public:
    BST();
    virtual ~BST();
    /* insert element */
    void insert(int data);
    /* Print tree InOrder */
    void print();
};

#endif /* ESTRUCTURAS_CLASS_BST_H */
