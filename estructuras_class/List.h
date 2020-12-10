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
    void crear(const char *filename);
    /* inserta dato ordenadamente */
    void insertar(A data);
    /* imprime contenidos en archivo */
    void print(const char *filename);
    /* imprime (reverse) contenidos en archivo */
    void printr(const char *filename);
};

#endif /* ESTRUCTURAS_CLASS_LIST_H */
