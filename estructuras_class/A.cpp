#include <iostream>
#include "A.h"

using namespace std;

A::A() : data(0), priority(666)
{
}

A::A(int i) : data(i), priority(666)
{
}

A::A(int i, int p) : data(i), priority(p)
{
}

A::A(A const &orig) : data(orig.data), priority(orig.priority)
{
}

A::~A()
{
}

std::ostream &A::print(std::ostream &os) const
{
    os << data << " (" << priority << ")\n";
    return os;
}

int A::operator<<(A const &rhs)
{
    return rhs.priority < priority;
}

int A ::operator<(A const &rhs)
{
    return data < rhs.data;
}

std::ostream &operator<<(std::ostream &os, A const &a)
{
    return a.print(os);
}
