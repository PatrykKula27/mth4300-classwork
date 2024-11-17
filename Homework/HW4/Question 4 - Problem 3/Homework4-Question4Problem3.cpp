#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <iterator>
#include <algorithm>

struct node
{
    std::string first_name;
    std::string last_name;
};

class LinkedList
{
public:
    std::list<node> lst;

    void insert(const std::string& first_name, const std::string& last_name)
    {
        node new_node;
        new_node.first_name = first_name;
        new_node.last_name = last_name;
        lst.push_back(new_node);
    }

    void SelectionSort()
    {
        if (lst.size() <= 1)
        {
            return;
        }

        for (auto i = lst.begin(); i != lst.end(); ++i)
        {
            auto min_iter = i;

            for (auto j = std::next(i); j != lst.end(); ++j)
            {
                if (j->first_name < min_iter->first_name || (j->first_name == min_iter->first_name && j->last_name < min_iter->last_name))
                {
                    min_iter = j;
                }
            }

            if (min_iter != i)
            {
                std::swap(i->first_name, min_iter->first_name);
                std::swap(i->last_name, min_iter->last_name);
            }
        }
    }

    void printList() const
    {
        for (const auto& person : lst)
        {
            std::cout<<person.first_name<<" "<< person.last_name<<std::endl;
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

        for (const auto& person : lst)
        {
            outFile<<person.first_name<<" "<< person.last_name<<std::endl;
        }
        outFile.close();
    }

    void readFromFile(const std::string& filename)
    {
        std::ifstream inFile(filename);
        if (!inFile)
        {
            std::cerr<<"Error: Unable to open file for reading."<<std::endl;
            return;
        }

        std::string first_name, last_name;
        while (inFile>>first_name>>last_name)
        {
            insert(first_name, last_name);
        }
        inFile.close();
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

    list.readFromFile("names_list.txt");
    list.SelectionSort();
    list.writeToFile("sorted_names.txt");
    list.printList();

    return 0;
}
