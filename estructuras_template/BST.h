/* 
 * Binary search tree (template) implementation
 *
 * Contains object of type T.  (Pointers not supported)
 * 
 * Requires:
 *      T::operator< (strict total order)   (insert)
 *      operator<<(ostream, T)              (print)
 */

#ifndef BST_H
#define BST_H

#include <iostream>
#include "DLNode.h"

namespace tpl   /* TemPLate namespace to avoid name collition without
                   ugly names */
{

template <typename T>
class BST {
    /* private access (by default) */
    DLNode<T> *root;
    void destroyp(DLNode<T> *root);
    void insertp(DLNode<T> *&root, DLNode<T> *newnode);
    void printp(std::ostream &os, DLNode<T> *root);
public:
    BST();
    virtual ~BST();
    /* insert element */
    void insert(T data);
    /* Print tree InOrder */
    std::ostream & print(std::ostream &os);
};

template<typename T>
BST<T>::BST()
{
    root = NULL;
}

template<typename T>
BST<T>::~BST()
{
    destroyp(root);
}

template<typename T>
void BST<T>::destroyp(DLNode<T>* root)
{    
    if (!root)
        return;
    destroyp(root->prev);
    destroyp(root->next);
    delete root;
}

template<typename T>
void BST<T>::insert(T data)
{
    DLNode<T> *newnode;

    newnode = new DLNode<T>(data);
    insertp(root, newnode);
}

template<typename T>
void BST<T>::insertp(DLNode<T>*& root, DLNode<T>* newnode)
{
    if (!root) {
        root = newnode;
        return;
    }
    if (newnode->data < root->data) {
        insertp(root->prev, newnode);
    } else {
        insertp(root->next, newnode);
    }
}

template<typename T>
std::ostream& BST<T>::print(std::ostream& os)
{
    printp(os, root);
    return os;
}

template<typename T>
void BST<T>::printp(std::ostream& os, DLNode<T>* root)
{
    if (!root)
        return;
    printp(os, root->prev);
    os << root->data << '\n';
    printp(os, root->next);
}

}   /* end of namespace tpl */

#endif /* BST_H */
