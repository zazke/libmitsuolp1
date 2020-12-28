/* Placeholder for a class */

/* When needed, 0 is highest priority */

#ifndef ESTRUCTURAS_CLASS_A_H
#define ESTRUCTURAS_CLASS_A_H

#include <fstream>

class A
{
    int data;
    unsigned int priority;
public:
    A();
    A(int i);
    A(int i, int p);
    A(A const &orig);
    ~A();
    std::istream &read(std::istream &is);
    std::ostream& print(std::ostream &os) const;
    int operator<<(A const &rhs);
    int operator<(A const &rhs);
};

std::istream &operator>>(std::istream &is, A &a);
std::ostream &operator<<(std::ostream &os, A const &a);

#endif /* ESTRUCTURAS_CLASS_A_H */
