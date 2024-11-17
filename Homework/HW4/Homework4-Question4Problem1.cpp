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
                std::cout<<val<<" "<<std::endl;
            }
            std::cout<<std::endl;
        }
};

LinkedList mergedList(LinkedList list1, LinkedList list2)
{
    LinkedList list3;

    list1.lst.merge(list2.lst);

    list3.lst = list1.lst;

    return list3;
}

int main()
{
    LinkedList list1, list2;

    list1.insert(10);
    list1.insert(20);
    list1.insert(30);

    list2.insert(40);
    list2.insert(50);
    list2.insert(60);

    LinkedList list3 = mergedList(list1, list2);

    std::cout<<"List 1"<<std::endl;
    list1.printList();
    std::cout<<std::endl;

    std::cout<<"List 2"<<std::endl;
    list2.printList();
    std::cout<<std::endl;

    std::cout<<"List 3"<<std::endl;
    list3.printList();
    std::cout<<std::endl;
    return 0;
}

// Time Complexity: O(n + m)
// Space Complexity: O(1)