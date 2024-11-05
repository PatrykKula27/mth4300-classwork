#ifndef LINKEDLIST_h
#define LINKEDLIST_h

#include <iostream>
struct Node
{
    int data;
    Node* next;
};

class LinkedList
{
    private:
        Node* head;
    public:
        LinkedList() : head(nullptr) {}
        ~LinkedList(){}

        void insert(int value);
        void display();
        void deleteNode(int value);
        void deleteNodeByPosition(int position);

        LinkedList reverseOrder(LinkedList& regList);
};

#endif