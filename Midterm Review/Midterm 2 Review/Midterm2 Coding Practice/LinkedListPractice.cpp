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
        LinkedList()
        {
            head = nullptr;
        }

        ~LinkedList()
        {
            Node* curr = head;
            while (curr != nullptr)
            {
                Node* nextNode = curr->next;
                delete curr;
                curr = nextNode;
            }
        }

        void insert(int val)
        {
            Node* newNode = new Node();
            newNode->data = val;
            newNode->next = nullptr;

            if (head == nullptr)
            {
                head = newNode;
            }
            else
            {
                Node* temp = head;
                while (temp->next != nullptr)
                {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }

        void display()
        {
            Node* temp = head;
            while (temp != nullptr)
            {
                std::cout<<temp->data<<" -> ";
                temp = temp->next;
            }
            std::cout<<"nullptr"<<std::endl;
        }

        void deleteNode(int val)
        {
            if (head == nullptr)
            {
                std::cout<<"List is empty, therefore no deletion has been made."<<std::endl;
                return;
            }

            if (head->data == val)
            {
                Node* temp = head;
                head = head->next;
                delete head;
                return;
            }

            Node* curr = head;
            Node* prev = nullptr;
            while (curr != nullptr && curr->data != val)
            {
                prev = curr;
                curr = curr->next;
            }

            if (curr->data = val)
            {
                prev->next = curr->next;
                delete curr;
            }
            else
            {
                std::cout<<"No node in this list matches this value."<<std::endl;
            }
        }
};