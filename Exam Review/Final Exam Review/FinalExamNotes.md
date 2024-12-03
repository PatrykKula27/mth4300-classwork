# Final Exam Study Guide

The Final Exam will be cumulative, however, 70% of it will be the last 5-6 topics covered in class. The other 30% consists of the topics covered in Midterms 1 and 2.

## Midterm Review Links
1. Midterm 1 Review: [Notes](./Midterm%201%20Review%20FIles/Midterm1Notes%20FINAL.md) | [Review](./Midterm%201%20Review%20FIles/Midterm1Review%20FINAL.md)
2. Midterm 2 Review: [Notes](./Midterm%202%20Review%20FIles/Midterm2Notes%20FINAL.md) | [Review](./Midterm%202%20Review%20FIles/Midterm2Review%20FINAL.md)

## Topics:
1. [Binary Trees](#1-binary-trees)
2. [Binary Search Trees](#2-binary-search-trees)

## 1. Binary Trees
A ```binary tree``` in C++ is a hierarchical data structure in which each node has at mode two children, often referred to as the left and right child respectively. 

### Basic Concepts of a Binary Tree:
* Node - A basic unit of a binary tree. Each node tontains a ```data value```, a ```left child pointer```, and a ```right child pointer```.
* Root - The topmost node in a binary tree. 
  * Think of it as the first node in a tree.
* Leaf - A node where it's left and right child are ```nullptr```, essentially making it a parent with no child. Leaf nodes are found towards the end of a binary tree.
* Height - The number of edges on the longest path from the root to a leaf. 
  * Think of it as the route that takes the longest time to get to your destination.
* Depth - The number of edges from the root to a leaf. 
  * Think of it as the route that takes the least time to get to your destination.

### Types of Binary Trees:
* Full Binary Tree: Every node has either 0 or 2 children.
* Complete Binary Tree: All levels are fully filled except possibly the last, which is filled from the left.
* Perfect Binary Tree: All internal nodes have two children, and all leaves are at the same level.
* Balanced Binary Tree: The difference between the height of the left and right subtrees is not more than one for every node.

### Structure of a Node in C++:
The fundamental building block of a binary tree is a node, which can be defined using a ```struct``` in C++. The node structure in binary trees are the same as a node structure in a doubly linked list.

```cpp
#include <iostream>

// Define a structure for a node in a binary tree
struct Node
{
    int data; // Data stored in the node
    Node* left; // Pointer to the left child
    Node* right; // Pointer to the right child

    // Constructor to initialize a new node
    Node(int value) 
    {
        data = value; // Sets the data to whatever value it is given.
        left = nullptr; // Sets the left child to nullptr.
        right = nullptr; // Sets the right child to nullptr.
    }
};
```

### Binary Tree Operations
In order for Binary Trees to properly function, methods are created for certain operations such as insertion and traversal.

#### Insertion
The ```insertion``` operation places a new node at the correct position in the tree. Here's an example of inserting a node into a ```binary search tree```, where the left child contains a smaller value and the right child contains a larger value.

```cpp
// Function to insert a new node in the binary search tree (BST)
Node* insert(Node* root, int value) 
{
    if (root == nullptr) 
    {
        return new Node(value);  // If the tree is empty, create a new node
    }
    
    if (value < root->data) 
    {
        root->left = insert(root->left, value);  // Insert in the left subtree
    } else 
    {
        root->right = insert(root->right, value); // Insert in the right subtree
    }
    
    return root;
}
```

#### Traversal
```Traversal``` is the process of visiting all nodes in the tree. There are three primary methods:

##### 1. In-Order Traversal (Left, Root, Right)
For BSTs, this traversal returns elements in sorted order.

```cpp
// In-order traversal of the binary tree
void inOrder(Node* root) 
{
    if (root != nullptr) 
    {
        inOrder(root->left);        // Visit left subtree
        cout << root->data << " ";  // Visit root
        inOrder(root->right);       // Visit right subtree
    }
}
```

##### 2. Pre-order Traversal (Root, Left, Right):
Used for copying a tree or for prefix expression evaluation.

```cpp
// Pre-order traversal of the binary tree
void preOrder(Node* root) 
{
    if (root != nullptr) 
    {
        cout << root->data << " ";  // Visit root
        preOrder(root->left);       // Visit left subtree
        preOrder(root->right);      // Visit right subtree
    }
}
```

##### 3. Post-order Traversal (Left, Right, Root):
Useful for deleting a tree or postfix expression evaluation.

```cpp
// Post-order traversal of the binary tree
void postOrder(Node* root) 
{
    if (root != nullptr) 
    {
        postOrder(root->left);      // Visit left subtree
        postOrder(root->right);     // Visit right subtree
        cout << root->data << " ";  // Visit root
    }
}
```

## 2. Binary Search Trees
A Binary Search Tree (BST) is a data structure that organizes elements (or nodes) in a hierarchical manner, making it efficient for operations like searching, insertion, and deletion. Here's a breakdown of how BSTs work in C++ and their basic concepts.

### Properties of a Binary Search Tree
* Each node has a key (or value).
* The left child of a node contains keys that are less than the node's key.
* The right child of a node contains keys that are greater than the node's key.
* No duplicate keys (optional, but common in BSTs).