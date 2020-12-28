/* Implements singly linked list using classes */

#ifndef ESTRUCTURAS_CLASS_LIST_H
#define ESTRUCTURAS_CLASS_LIST_H

#include <iostream>
#include "./SLNode.h"

class List
{
    /* private by default */
    SLNode *head;
    void printrp(std::ostream &os, SLNode *walk);

public:
    List();
    virtual ~List();
    /* crea la lista leyendola desde un archivo */
    void crear(std::istream &is);
    /* inserta dato ordenadamente */
    void insertar(A &data);
    /* imprime contenidos en archivo */
    void print(std::ostream &os);
    /* imprime (reverse) contenidos en archivo */
    void printr(std::ostream &os);
};

#endif /* ESTRUCTURAS_CLASS_LIST_H */
