/* 
 * Implementation of Singly Linked Node (SLN) using class templates
 *
 * Data contained:
 *      class T
 *
 * Requires:
 *      (copy ctor of T (if T has dynamically allocated data))
 */

#ifndef SLNODE_H
#define SLNODE_H

#include <cstddef>

namespace tpl
{

template <typename T>
class Queue;

template <typename T>
class SLNode
{
    /* private by default */
    T data;
    SLNode *next;
public:
    SLNode();
    SLNode(T const &data);
    virtual ~SLNode();
    friend Queue<T>;
};

template<typename T>
SLNode<T>::SLNode()
{
    next = NULL;
}

template<typename T>
SLNode<T>::SLNode(T const &data) : data(data)
{
    next = NULL;
}

template<typename T>
SLNode<T>::~SLNode()
{
}

}   /* end of namespace tpl */

#endif /* SLNODE_H */

