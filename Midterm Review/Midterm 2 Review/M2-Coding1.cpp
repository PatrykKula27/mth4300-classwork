// Write the code for the method (adds a node to the end of a linked list).
// Return true if successful otherwise false.
// Do not use stl.
#include <iostream>

bool LinkedList::push_back(int val)
{
    newNode = new Node;
    newNode->data = val;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode;
        return 1;
    }

    Node* curr = head;
    while (curr->next)
    {
        curr = curr->next;
    }
    curr->next = newNode;
    return true;
}