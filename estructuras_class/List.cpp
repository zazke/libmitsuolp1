#include <iostream>
#include <fstream>
#include <iomanip>
#include "./List.h"

using namespace std;

List::List()
{
    head = NULL;
}

List::~List()
{
    SLNode *prev;

    while (head) {
        prev = head;
        head = head->next;
        delete prev;
    }
}

void List::crear(std::istream &is)
{
    A a;

    while (is >> a) {
        insertar(a);
    }
}

void List::insertar(A & data)
{
    SLNode *walk, *prev, *newnode;

    newnode = new SLNode(data);
    walk = head;
    prev = NULL;
    while (walk) {
        if (data < walk->data)
            break;
        prev = walk;
        walk = walk->next;
    }
    newnode->next = walk;
    if (prev)
        prev->next = newnode;
    else
        head = newnode;
}

void List::print(std::ostream &os)
{
    SLNode *walk;

    os << "Datos de la lista: \n";
    walk = head;
    while (walk) {
        os << walk->data;
        walk = walk->next;
    }
}

void List::printr(std::ostream &os)
{
    printrp(os, head);
}

void List::printrp(std::ostream &os, SLNode *walk)
{
    if (!walk)
        return;
    printrp(os, walk->next);
    os << walk->data;
}

/* end of file */
