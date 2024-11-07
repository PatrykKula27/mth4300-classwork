#include "LinkedList.h"
#include <iostream>

// Constructor.
LinkedList::LinkedList() : head(nullptr) {}

// Destructor.
LinkedList::~LinkedList()
{
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

// Method to insert a node at the end.
void LinkedList::insert(int value, int pos)
{
    Node* newNode = new Node(); // Creates a new node.
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr && pos == 0)
    {
        // If list is empty, new node becomes the head.
        head = newNode;
    }
    else if(pos == 0)
    {
        newNode->next=head;
        head=newNode;
    }
    // Search for the position to insert
    else
    {
        Node* temp = head;
        while(temp != nullptr && (pos - 1) > 0)
        {
            temp = temp->next;
            pos--;
        }

        if (temp != nullptr && pos == 1) 
        {
            newNode->next = temp->next;
            temp->next = newNode; 
        }

        else
        {
            std::cout<<"unable to add node, pos invalid"<<std::endl;
            delete newNode;
        }
    }
}

// Method to display the linked list.
void LinkedList::display()
{
    Node* temp = head;
    while (temp != nullptr)
    {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "nullptr" << std::endl;
}

// Method to delete a node by value.
void LinkedList::deleteNode(int value)
{
    if (head == nullptr)
    {
        std::cout << "List is empty, cannot delete" << std::endl;
        return;
    }

    // If the head node holds the value to be deleted.
    if (head->data == value) 
    {
        Node* temp = head;
        head = head->next;  // Move head to the next node.
        delete temp;        // Free memory of old head.
        return;
    }

    // Search for the node to delete.
    Node* current = head;
    Node* previous = nullptr;
    while (current != nullptr && current->data != value) 
    {
        previous = current;
        current = current->next;
    }

    // If the value is found, delete the node.
    if (current != nullptr) 
    {
        previous->next = current->next;
        delete current;
    } 
    else 
    {
        std::cout << "Value not found in the list" << std::endl;
    }
}

// Method to delete node by position.
void LinkedList::deleteNodeAtPosition(int position)
{
    // Ends the method if the list is empty.
    if (head == nullptr)
    {
        std::cout << "List is empty, cannot delete" << std::endl;
        return;
    }

    // Ends the method if the inputted position is invalid.
    if (position < 0)
    {
        std::cout<<"Invalid Position."<<std::endl;
        return;
    }

    //Incrememnt through the list.
    Node* current = nullptr;
    for (int i = 0; i < position -1 && current != nullptr; i++)
    {
        current = current->next;
    }

    // Deletes node at position 0.
    if (position == 0)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    // Ends the method if position is out of bounds.
    if (current == nullptr || current->next == nullptr) 
    {
        std::cout << "Position is out of bounds." << std::endl;
        return;
    }

    // Delete the node at the position.
    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
}

LinkedList LinkedList::reverseOrder(LinkedList& regList)
{
    Node* previous = nullptr;
    Node* current = head;
    while(current != nullptr)
    {
        Node* temp = current->next;
        current->next = previous;
        previous = current;
        current = temp;
    }
    head = previous;
}