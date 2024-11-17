#include <iostream>
#include <list>

class LinkedList
{
    public:
        std::list<int> lst;

        void insert(int val)
        {
            lst.push_back(val);
        }

        void printList() const
        {
            for (int val : lst)
            {
                std::cout<<val<<" ";
            }
            std::cout<<std::endl;
        }

        bool deleteNthNodeFromEnd(int n)
        {
            if (n <= 0 || lst.empty()) // edge case
            {
                return false;
            }

            int size = lst.size();
            int start = size - n;
            if (start < 0)
            {
                return false;
            }

            auto it = lst.begin();
            std::advance(it, start);
            lst.erase(it);

            return true;
        }
};

int main()
{
    LinkedList list1;

    list1.insert(15);
    list1.insert(30);
    list1.insert(45);
    list1.insert(60);
    list1.insert(75);
    list1.insert(90);
    list1.insert(105);

    std::cout<<"List 1"<<std::endl;
    list1.printList();

    std::cout<<"Delete from Node Position 4"<<std::endl;
    if (list1.deleteNthNodeFromEnd(4))
    {
        std::cout<<"Updated List"<<std::endl;
        list1.printList();
    }
    else
    {
        std::cout<<"No Deletion was made due to an error."<<std::endl;
    }
    
    return 0;
}