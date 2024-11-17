#include <iostream>

struct Node
{
    int val;
    Node* next;
    Node(int x): val(x), next(nullptr) {}
};

class LinkedList
{
    public:
        Node* head;
        LinkedList(): head(nullptr) {}

    int addNode(int value)
    {
        if(head == nullptr)
        {
            head = new Node(value);
            return 0;
        }

        Node* curr = head;
        while (curr->next)
        {
            curr = curr->next;
        }
        curr->next = new Node(value);
        return 1;
    }

    LinkedList merge(LinkedList l1, LinkedList l2)
    {
        Node temp(0);
        Node* end = &temp;

        Node* l1node = l1.head;
        Node* l2node = l2.head;

        while (l1node && l2node)
        {
            if (l1node->val <= l2node->val)
            {
                end->next = l1node;
                l1node = l1node->next;
            }
            else
            {
                end->next = l2node;
                l2node = l2node->next;
            }
            end = end->next;
        }

        end->next = l1node ? l2node : l2node;

        LinkedList mergedList;
        mergedList.head = temp.next;
        return mergedList;
    }
};

int main()
{
    return 0;
}

// Time Complexity: O(n + m)
// Space Complexity: O(1)