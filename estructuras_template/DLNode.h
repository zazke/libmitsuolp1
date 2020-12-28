#ifndef DLNODE_H
#define DLNODE_H

#include <iostream>

namespace tpl
{

template <typename T>
class BST;

template <typename T>
class DLNode
{
    /* private by default */
    T data;
    DLNode *next;
    DLNode *prev;
public:
    DLNode();
    DLNode(T const & data);
    virtual ~DLNode();
    friend tpl::BST<T>;
};

template<typename T>
DLNode<T>::DLNode()
{
    next = prev = NULL;
}

template<typename T>
DLNode<T>::DLNode(T const & data) : data(data)
{
    next = prev = NULL;
}

template<typename T>
DLNode<T>::~DLNode()
{
}

}

#endif /* DLNODE_H */
