#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

DoublyLinkedList::DoublyLinkedList()
{
    head = NULL;
}

DoublyLinkedList::~DoublyLinkedList()
{
    DLNode *prev;

    while (head) {
        prev = head;
        head = head->next;
        delete prev;
    }
}

void DoublyLinkedList::insert(int data)
{
    DLNode *walk, *prev, *newnode;

    newnode = new DLNode(data);
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
    }
    if (prev) {
        prev->next = newnode;
    } else {
        head = newnode;
    }
}

void DoublyLinkedList::print()
{
    DLNode *walk;

    walk = head;
    while (walk) {
        cout << walk->data << '\n';
        walk = walk->next;
    }
}
