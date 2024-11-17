#include <iostream>
#include <fstream>
#include <string>

struct node
{
    std::string first_name;
    std::string last_name;
    node* next;
};

class LinkedList
{
    private:
        node* head;
    
    public:
        LinkedList(): head(nullptr) {}

        ~LinkedList()
        {
            while (head)
            {
                node* temp = head;
                head = head->next;
                delete temp;
            }
        }

        void insert(const std::string& first_name, const std::string& last_name)
        {
            node* new_node = new node{first_name, last_name, nullptr};

            if (!head)
            {
                head = new_node;
                return;
            }

            node* temp = head;

            while (temp->next)
            {
                temp = temp->next;
            }
            
            temp->next = new_node;
        }
        
        void SelectionSort()
        {
            if (!head || !head->next) // Edge case
            {
                return;
            }

            for (node* i = head; i != nullptr; i = i->next) // Selection sort
            {
                node* min = i;

                for (node* j = i->next; j != nullptr; j = j->next)
                {
                    if (j->first_name < min->first_name || (j->first_name == min->first_name && j->last_name < min->last_name))
                    {
                        min = j;
                    }

                }
                std::swap(i->first_name, min->first_name);
                std::swap(i->last_name, min->last_name);
            }
        }

        void printList() const
        {
            node* temp = head;

            while (temp)
            {
                std::cout<<temp->first_name<<" "<<temp->last_name<<std::endl;
                temp = temp->next;
            }
        }

        void writeToFile(const std::string& filename) const
        {
            std::ofstream outFile(filename);
            if (!outFile)
            {
                std::cerr<<"File is invalid. Unable to open."<<std::endl;
                return;
            }

            node* temp = head;

            while (temp)
            {
                outFile<<temp->first_name<<" "<<temp->last_name<<std::endl;
                temp = temp->next;
            }
            outFile.close();
        }
};

int main()
{
    std::ofstream outFile("names_list.txt", std::ios::app);
    if (!outFile)
    {
        std::cerr<<"File is invalid. Unable to open."<<std::endl;
        return 1;
    }

    outFile<<"Patryk Kula"<<std::endl;
    outFile.close();

    LinkedList list;

    std::ifstream inFile("names_list.txt");
    if (!inFile)
    {
        std::cerr<<"File is invalid. Unable to open."<<std::endl;
        return 1;
    }

    std::string first_name, last_name;

    while (inFile>>first_name>>last_name)
    {
        list.insert(first_name, last_name);
    }

    inFile.close();

    list.SelectionSort();
    list.writeToFile("sorted_names.txt");
    list.printList();
    return 0;
}