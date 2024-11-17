#include <iostream>

struct Node
{
    int data;
    Node* next;
};

Node* head = nullptr;

bool deleteNthNodeFromEnd(int n)
{
    if (!head || n <= 0)
    {
        return false;
    }

    Node* prev = nullptr;
    Node* fast = head;
    Node* slow = head;

    for (int i = 0; i < n; ++i) 
    {
        if (!fast)
        {
            return false;
        }
        fast = fast->next;
    }


    while (fast) 
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next;
    }

    if (!prev)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    else
    {
        prev->next = slow->next;
        delete slow;
    }

    return true;
}

// Time Complexity: O(n)
// Space Compplexity: O(1)