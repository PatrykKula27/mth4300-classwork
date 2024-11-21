// Write the code for the method (adds a node to the end of a linked list).
// Return true if successful otherwise false.
// Do not use stl.
#include <iostream>

bool LinkedList::push_back(int val)
{
    newNode = new Node; // Create a new node
    newNode->data = val; // Assigns the value to the node's data
    newNode->next = nullptr; // Points next to nullptr

    if (head == nullptr) // Assigns newNode to the head because there are no nodes in the linked list.
    {
        head = newNode;
        return 1;
    }

    Node* curr = head; // Creates the node pointer current and points it to the beginning of the linked list.
    while (curr->next) // While the current pointer still points to an existent node that comes after it.
    {
        curr = curr->next; // Traverses through the linked list.
    } // The while loop terminates once curr->next points to nullptr.
    curr->next = newNode; // Replaces curr's nullptr with the new node, which includes the node, it's value, and a pointer to next (which is nullptr)
    return true;
}