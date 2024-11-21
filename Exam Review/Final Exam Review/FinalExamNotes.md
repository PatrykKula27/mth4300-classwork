# Final Exam Study Guide

The Final Exam will be cumulative, however, 70% of it will be the last 5-6 topics covered in class. The other 30% consists of the topics covered in Midterms 1 and 2.

## Midterm Review Links
1. Midterm 1 Review: [Notes](./Midterm%201%20Review%20FIles/Midterm1Notes%20FINAL.md) | [Review](./Midterm%201%20Review%20FIles/Midterm1Review%20FINAL.md)
2. Midterm 2 Review: [Notes](./Midterm%202%20Review%20FIles/Midterm2Notes%20FINAL.md) | [Review](./Midterm%202%20Review%20FIles/Midterm2Review%20FINAL.md)

## Topics:
1. Binary Trees + Binary Search Tree

## 1. Binary Trees & Binary Search Trees
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

