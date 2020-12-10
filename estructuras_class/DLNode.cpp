#include <iostream>
#include <iomanip>
#include "DLNode.h"

DLNode::DLNode()
{
    next = prev = NULL;
}

DLNode::DLNode(int data) : data(data)
{
    next = prev = NULL;
}

DLNode::~DLNode()
{
}
