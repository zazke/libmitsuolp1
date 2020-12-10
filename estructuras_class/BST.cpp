#include <iostream>
#include "BST.h"

using namespace std;

BST::BST()
{
    root = NULL;
}

BST::~BST()
{
    destroyp(root);
}

void BST::destroyp(DLNode *root)
{
    if (!root)
        return;
    destroyp(root->prev);
    destroyp(root->next);
    delete root;
}

void BST::insert(int data)
{
    DLNode *newnode;

    newnode = new DLNode(data);
    insertp(root, newnode);
}

void BST::insertp(DLNode *&root, DLNode *newnode)
{
    if (!root) {
        root = newnode;
        return;
    }
    if (newnode->data < root->data) {
        insertp(root->prev, newnode);
    } else {
        insertp(root->next, newnode);
    }
}

void BST::print()
{
    printp(root);
}

void BST::printp(DLNode *root)
{
    if (!root)
        return;
    printp(root->prev);
    cout << root->data << '\n';
    printp(root->next);
}
