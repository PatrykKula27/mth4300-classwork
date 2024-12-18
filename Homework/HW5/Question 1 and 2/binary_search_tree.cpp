#include <iostream>
#include <stack>
#include"binary_search_tree.h"


BinarySearchTree::BinarySearchTree():root(nullptr){}


BinarySearchTree::~BinarySearchTree()
{
    destroy(root);
    root=nullptr;
}


void BinarySearchTree::destroy(Node* curr_del)
{
    if(!curr_del) return;

    destroy(curr_del->left);
    destroy(curr_del->right);

    delete curr_del;
    curr_del=nullptr;
}


Node* BinarySearchTree::getRoot()
{
    return root;
}


Node* BinarySearchTree::insert(Node* start, int val)
{
     if (!root) 
    {
        root= new Node(val);
        return root;
    }

    if (!start) return new Node(val);  // found position to insert

    else if (val < start->data) start->left = insert(start->left, val);  

    else if (val > start->data) start->right = insert(start->right, val); 
    
    return start;
}


void BinarySearchTree::inOrder(Node* start)
{
    if (!start) return;

    inOrder(start->left);
    std::cout<<start->data<<" -> ";
    inOrder(start->right);
}


Node* BinarySearchTree::search(int val)
{
    Node* curr=root;
    while (curr)
    {
        if(val < curr->data) curr=curr->left;

        else if (val > curr->data) curr=curr->right;

        else return curr; // val==curr->data, so we found node
    }

    return nullptr;
}


Node* BinarySearchTree::deleteNode(Node* start, int val)
{
    if(!start) return nullptr;

    else if(val < start->data) start->left=deleteNode(start->left,val);

    else if(val > start->data) start->right=deleteNode(start->right,val); 
    
    else
    {
        if(start->left && start->right)//two children
        {
            Node* min_node = findMin( start->right );
            start->data = min_node->data;
            start->right = deleteNode( start->right, start->data );
        }


       else //at most one children
       {
            Node* save_spot=start->left?start->left:start->right;
            delete start;
            return save_spot;
       } 

    }

    return start;
}


Node* BinarySearchTree::findMin(Node* start)
{
    if(!start) return nullptr;
    
    while(start->left) start=start->left;

    return start;
}

int BinarySearchTree::findKthSmallest(Node* start, int& k) // Problem 1
{
    if (!start)
    {
        return -1;
    }

    int leaf = findKthSmallest(start->left, k);

    if (k == 0)
    {
        return leaf;
    }

    k--;

    if (k == 0)
    {
        return start->data;
    }

    return findKthSmallest(start->right, k);
}

bool BinarySearchTree::isValidBST(Node* start, int min, int max) // Problem 1
{
    if (!start)
    {
        return true;
    }

    if ((start->data <= min) || start->data >= max)
    {
        return false;
    }

    return (isValidBST(start->left, min, start->data) && isValidBST(start->right, start->data, max));
}

void BinarySearchTree::postOrder(Node* root)
{
    if (!root)
    {
        return;
    }

    std::stack<Node*> nStack;
    std::stack<Node*> output;

    nStack.push(root);

    while (!nStack.empty()) // Traversal
    {
        Node* current = nStack.top();
        nStack.pop();
        output.push(current);

        if (current->left)
        {
            nStack.push(current->left);
        }

        if (current->right)
        {
            nStack.push(current->right);
        }
    }

    while (!output.empty())
    {
        Node* current = output.top();
        output.pop();
        std::cout<<current->data<<" ---> ";
    }

    std::cout<<"END";
}