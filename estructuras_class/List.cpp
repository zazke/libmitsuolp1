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

void List::crear(const char *filename)
{
    ifstream ifs(filename);
    int i;

    if (ifs.fail())
        cerr << "error: no se pudo abrir archivo \"" << filename << "\"\n";

    while (ifs >> i) {
        A a(i);
        insertar(a);
    }
}

void List::insertar(A data)
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

void List::print(const char *filename)
{
    ofstream cout(filename);
    SLNode *walk;

    if (cout.fail())
        cerr << "error: no se pudo abrir archivo \"" << filename << "\"\n";

    cout << "Datos de la lista: \n";
    walk = head;
    while (walk) {
        cout << walk->data;
        walk = walk->next;
    }
}

void List::printr(const char *filename)
{
    ofstream ofs(filename);

    if (ofs.fail())
        cerr << "error: no se pudo abrir archivo \"" << filename << "\"\n";
    
    ofs << "Datos de la lista (en reverso): \n";
    printrp(ofs, head);
}

void List::printrp(std::ostream &os, SLNode *walk)
{
    if (!walk)
        return;
    printrp(os, walk->next);
    os << walk->data;
}

/* end of file */
