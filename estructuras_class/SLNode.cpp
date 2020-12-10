#include <cstddef>
#include "./SLNode.h"

SLNode::SLNode()
{
    next = NULL;
}

SLNode::SLNode(A const &data) : data(data)
{
    next = NULL;
}

