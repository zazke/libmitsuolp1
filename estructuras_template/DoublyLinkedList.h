#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
#include "DLNode.h"

namespace tpl
{

template <typename T>
class DoublyLinkedList
{
    /* private by default */
    DLNode<T> *head;
    DLNode<T> *tail;
public:
    DoublyLinkedList();
    virtual ~DoublyLinkedList();
    /* create list from input file */
    void create(std::istream &is);
    /* insert in orderly manner */
    void insert(T const & data);
    /* print whole list */
    void print(std::ostream &os);
    /* print whole list reverse order */
    void printr(std::ostream &os);
    /* print whole list select order */
    void printsel(std::ostream &os, int d);
};


template<typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    head = NULL;
    tail = NULL;
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    DLNode<T> *prev;

    while (head) {
        prev = head;
        head = head->next;
        delete prev;
    }
}

template<typename T>
void DoublyLinkedList<T>::create(std::istream &is)
{
    T t;

    while (is >> t) {
        insert(t);
    }
}

template<typename T>
void DoublyLinkedList<T>::insert(const T& data)
{
    DLNode<T> *walk, *prev, *newnode;

    newnode = new DLNode<T>(data);
    walk = head;
    prev = NULL;
    while (walk) {
        if (data < walk->data)
            break;
        prev = walk;
        walk = walk->next;
    }
    newnode->next = walk;
    newnode->prev = prev;
    if (walk) {
        walk->prev = newnode;
    } else {
        tail = newnode;
    }
    if (prev) {
        prev->next = newnode;
    } else {
        head = newnode;
    }
}

template<typename T>
void DoublyLinkedList<T>::print(std::ostream &os)
{
    DLNode<T> *walk;

    walk = head;
    while (walk) {
        os << walk->data << '\n';
        walk = walk->next;
    }
}

template<typename T>
void DoublyLinkedList<T>::printr(std::ostream& os)
{
    DLNode<T> *walk;

    walk = tail;
    while (walk) {
        os << walk->data << '\n';
        walk = walk->prev;
    }
}

} /* end of namespace tpl */

#endif /* DOUBLYLINKEDLIST_H */
