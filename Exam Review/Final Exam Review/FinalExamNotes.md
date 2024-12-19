# Final Exam Study Guide

The Final Exam will be cumulative, however, 70% of it will be the last 5-6 topics covered in class. The other 30% consists of the topics covered in Midterms 1 and 2.

## Midterm Review Links
1. Midterm 1 Review: [Notes](./Midterm%201%20Review%20FIles/Midterm1Notes%20FINAL.md) | [Review](./Midterm%201%20Review%20FIles/Midterm1Review%20FINAL.md)
2. Midterm 2 Review: [Notes](./Midterm%202%20Review%20FIles/Midterm2Notes%20FINAL.md) | [Review](./Midterm%202%20Review%20FIles/Midterm2Review%20FINAL.md)

## Topics:
1. [Binary Trees](#1-binary-trees)
2. [Binary Search Trees](#2-binary-search-trees)
3. [Stacks](#3-stacks)
4. [Queues](#4-queues)
5. [Hash Tables](#5-hash-tables)
6. [Maps](#6-maps)
7. [Key Differences Between Maps and Unordered Maps](#7-key-differences-between-stdmap-and-stdunorderd_map)

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

## Main Operatios

### Insertion
The insertion operation places a new node at the correct position in the tree. Inserting a node into a BST involves placing a new value in the correct poition according to the BST property:

* **Left Subtree:** Nodes must have values smaller than the parent.
* **Right Subtree:** Nodes must have values greater than the parent.

**Steps to Insert a Node**<br>
1. Start from the Root of the tree (the top-most node in a tree).
2. Traverse to the Correct Position. If the new value is smaller than the current node, then it will move to the left subtree. If the new value is greater than the current node, then it will move to the right subtree. You repeat this process until the node reaches nullptr (empty spot).
3. Insert the Node by replacing nullptr.

```cpp
Node* BinarySearchTree::insert(Node* start, int val)
{
    if (!root) // Base case for if the root is empty.
    {
        root = new Node(val);
        return root;
    }

    if (!start) // Case for when there is a root node, but it does not have any children. This adds in a child to the leaf.
    {
        return new Node(val);
    }
    else if (val < start->data) // If val is less than the current data, we move to the left child of the node, then recursively calls the function to repeat the process.
    {
        start->left = insert(start->left, val);
    }
    else if (val > start->data) // If val is greater than the current data, we move to the right child of the node, then recursively calls the function to repeat the process.
    {
        start->right = insert(start->right, val);
    }
    return start;
}
```

#### Example Walkthrough
Insertions:
* Start with an empty tree: root = nullptr.
* Insert 5<
* Tree is empty, so 5 becomes the root.
```markdown
    5
```

* Insert 3
* 3 < 5, so insert 3 into the left subtree.
```markdown
    5
   /
  3
```

* Insert 8
* 8 > 5, so insert 8 into the right subtree.
```markdown
    5
   / \
  3   8
```

* Insert 2
* 2 < 5 (go left) and 2 < 3 (go left again), so insert 2 as the left child of 3.
```markdown

    5
   / \
  3   8
 /
2
```

* Insert 4
* 4 < 5 (go left) and 4 > 3 (go right), so insert 4 as the right child of 3.
```markdown
    5
   / \
  3   8
 / \
2   4
```
In-order Traversal After Inserts
The in-order traversal of a BST visits nodes in sorted order. For the example above, the output would be:
```
2 3 4 5 8
```
This confirms that the BST property is maintained after insertions.

### Search
Searching involves finding whether a specific value exists within a BST.

```cpp
Node* BinarySearchTree::search(int val)
{
    Node* current = root;
    
    while (current)
    {
        if (val < current->data) // If the value is less than the current, we traverse down the left leaf.
        {
            current = current->left;
        }
        else if (val > current->data) // If the value is greater than the current, we traverse down the right leaf.
        {
            current = current->right;
        }
        else // The value being searched for has been found, so it is returned.
        {
            return current;
        }
    }
    return nullptr; // Returns if the value can't be found, or if there is no values within the BST.
}
```

### Deletion
Deletion involves finding the given value in a BST and deleting it from the BST.

```cpp
Node* BinarySearchTree::deleteNode(Node* start, int val)
{
    if (!start) // If the start is null, then we return nullptr. This is because the value doesn't exist.
    {
        return nullptr;
    }
    else if (val < start->data) // The val isn't equal to the current data, however it is less than data, so we traverse down to the left and recursively call the function.
    {
        start->left = deleteNode(start->left, val);
    }
    else if (val > start->data)  // The val isn't equal to the current data, however it is greater than data, so we traverse down to the right and recursively call the function.
    {
        start->right = deleteNode(start->right, val);
    }
    else // Once we have finished traversing (we have located the value), we then must deal with the leaf node's children, and this differs depending on the case.
    {
        if (start->left && start->right) // For cases with two children.
        {
            Node* inOrderSuccessor = findMin(start->right); // We create a temporary node for the child leaf with the bigger value.

            start->data = inOrderSuccessor->data; // We replace the parent node with the child leaf with the bigger value.
            start->right = deleteNode(start->right, start->data); // We recursively delete the right leaf node.
        }
        else // For cases with one child.
        {
            Node* temp;
            if (start->left != nullptr) 
            {
                temp = start->left;
            } 
            else 
            {
                temp = start->right;
            }

            delete start;
            delete temp;
        }
    }
}
```

#### Example Walkthrough
1. Input Tree:
```markdown
        5
       / \
      3   8
     / \
    2   4
```

2. Delete 3:
   * Node 3 has two children.
   * Replace 3 with its inorder successor (4).
   * Delete 4 from the right subtree.

3. Output Tree:
```markdown
        5
       / \
      4   8
     /
    2
```
This approach ensures the BST property is maintained throughout the operation.

### Complexity:
* Time Complexity:
  * Insertion, Deletion, Search: O(log n) for balanced trees (O(n) in the worst case for unbalanced trees).
* Space Complexity:
  * O(n), where n is the number of nodes in the tree.

### Conclusion:
Binary trees are a powerful data structure that can be used for efficient searching, sorting, and hierarchical data organization. Implementing binary trees in C++ is straightforward with the use of pointers and recursive functions for operations like insertion, traversal, and search.


## 3. Stacks
A **Stack** is a linear data structure that follows the **Last In, First Out** principle, meaning that the last element added to the stack is the first one to be removed. It can be visualized as a collection of items stacked on top of each other, where only the topmost item can be accessed or removed. 

A real-world example of this would be stacking a collection of textbooks, ranging from numbers 1 through 10, with 1 being the first book added to the stack and 10 being the last one added to the stack. If you were to modify the stack, you could only do modifications to the 10th book added to the stack, as this follows the **Last In, First Out** principle of a stack.

### Key Operations of a Stack:
* **Push:** Adds an element to the top of the stack.
* **Pop:** Just like other data structures, pop removes an element from the top of the stack.
* **Peek (or Top):** Returns the top element of a stack without removing it.
**isEmpty:** Self-explanatory - It checks if the stack is empty or not.

### Stack Implementation in C++
There are two main ways to implement a Stack in C++. Stacks can be implemented using:

1. The Standard Template Library ```<stack>``` class. (This is preferred for simplicity and efficiency).
2. Manual implementation via arrays and/or linked lists.

### STL Stack
Below is the provided stack class from the C++ STL.

```cpp
#include <iostream>
#include <stack>

int main()
{
    std::stack<int> userStack;

    userStack.push(10);
    userStack.push(20);
    userStack.push(30);

    std::cout<<"Top element in the stack: "<<userStack.top()<<std::endl; // Output: 30
    userStack.pop();
    std::cout<<"Top element in the stack after the pop operation: "<<userStack.top()<<std::endl; // Output: 20

    std::cout<<"Is the stack empty?";
    if (userStack.isEmpty())
    {
        std::cout<<"Yes."<<std::endl;
    }
    else
    {
        std::cout<<"No."<<std::endl;
    }

    return 0;
}
```

### Manual Implementation Using Arrays:
Below is a stack class that has been built manually using arrays:

```cpp
#include <iostream>

class Stack
{
    private:
        int* arr;
        int top;
        int capacity;
    
    public:
        Stack(int size)
        {
            capacity = size;
            arr = new int[size];
            top = -1;
        }

        ~Stack()
        {
            delete[] arr;
        }

        void push(int val)
        {
            if (top == (capacity -1))
            {
                std::cout<<"Stack Overflow! Cannot push "<<val<<"!"<<std::endl;
                return;
            }

            arr[++top] = val; // We use a pre-increment here, rather than a post-increment. This is because if we were to use a post-incremeent (top++), then we would be overwriting the current position's value AND THEN incrementing to the next position. Doing a pre-increment allows us to first incremement towards the next position, then replace the value.
        }

        void pop()
        {
            if (top == -1)
            {
                std::cout<<"Stack Underflow! Cannot pop."<<std::endl;
                return;
            }
            top--;
        }

        int peek()
        {
            if (top == -1)
            {
                std::cout<<"The Stack is empty!"<<std::endl;
                return -1;
            }
            return arr[top];
        }

        bool isEmpty()
        {
            return top == -1;
        }
};
```

### Manual Implementation Using Linked Lists:
Below is a stack class that has been built manually using linked lists:

```cpp
#include <iostream>

struct Node
{
    int data:
    Node* next;
};

class Stack
{
    private:
        Node* top;
    
    public:
        Stack()
        {
            top = nullptr;
        }

        ~Stack()
        {
            while (top)
            {
                Node* temp = top;
                top = top->next;

                delete temp;
            }
        }

        void push(int val)
        {
            Node* newNode = new Node();
            newNode->data = val;
            newNode->next = top;

            top = newNode;
        }

        void pop()
        {
            if (!top)
            {
                std::cout<<"Stack Underflow! Cannot pop."<<std::endl;
                return;
            }

            Node* temp = top;
            top = top->next;

            delete temp;
        }

        int peek()
        {
            if (!top)
            {
                std::cout<<"Stack is Empty! Cannot peek."<<std::endl;
                return -1;
            }

            return top->data;
        }

        bool isEmpty()
        {
            return top == nullptr;
        }
};
```

### Applications of a Stack:
* **Expression Evaluation:** Parsing and evaluating expressions (e.g., postfix evaluation).
* **Undo Mechanism:** Used in text editors for undo operations.
* **Recursion:** Call stack in programming.
* **Depth-First Search (DFS):** Used in graph and tree traversal algorithms.

### Advantages of a Stack:
* Simplicity: Ideal for solving problems like reversing a string or validating parentheses.
* Efficient: Push and pop operations are O(1).
* Useful in algorithms like depth-first search, function call stacks, etc.


## 4. Queues
Queues are a type of container adapter that is provided by the Standard Template Library. Queues are based on the **First In, First Out** principle, meaning that elements are inserted at the back and then removed from the front.

A real world example of this would be creating a pile of books on a table, where whenever you added a book to the pile, you lift up the bottom book of the pile to slide in the next book (i.e. If the 9th book were at the bottom and you wanted to add in the 10th, you would lift up the 9th slightly to slide in the 10th to the bottom). If you wanted to remove a book from the queue, you would simply grab the book at the top of the pile, which would be book #1 since it was the first book to be added into this pile.

### Key Characteristics of a Queue
* **First In, First Out Principle:** The first element that is added into the queue is the first one that will be removed.
* **Restricted Access:** Elements can only be added to the back of the queue and Elemennts can only be removed from the front of the queue.
* **Underlying Container:** The ```queue``` container adapter is implemented using either a deque or a list as the underlying container.

### Key Operations of a Queue
The ```std::queue``` class is defined in the ```<queue>``` header. 
* **push()** - Adds an element to the back of the queue.
* **pop()** - Removes the front-most element of the queue.
* **front()** - Returns a reference to the front-most element of a queue.
* **back()** - Returns a reference to the last element of a queue.
* **empty()** - Checks if the queue is empty.
* **size()** - Returns the size of the queue.

### STL Queue
Below is the provided queue class from the C++ STL.

```cpp
#include <iostream>
#include <queue>

int main()
{
    std::queue<int> userQueue;

    userQueue.push(10);
    userQueue.push(20);
    userQueue.push(30);

    std::cout<<"The front of the queue is: "<<userQueue.front()<<"."<<std::endl; // Output: 10
    std::cout<<"The back of the queue is: "<<userQueue.back()<<"."<<std::endl; // Output: 30

    userQueue.pop();
    std::cout<<"The front of the queue after the pop operation is: "<<userQueue.front()<<"."<<std::endl; // Output: 20

    std::cout<<"The size of the queue is: "<<userQueue.size()<<"."<<std::endl;

    if (userQueue.empty())
    {
        std::cout<<"The queue is empty."<<std::endl;
    }
    else
    {
        std::cout<<"The queue is NOT empty."<<std::endl;
    }

    return 0;
}
```

### Real-World Use Cases
* **Task Scheduling:** Managing tasks where the first task added is processed first.
* **Print Queue:** Sending print jobs to a printer in the order they were received.
* **Breadth-First Search (BFS) in Graphs:** To explore nodes level by level.

### Specialized Queues
* **Priority Queue:** A variant where elements are removed based on priority instead of FIFO. Implemented using std::priority_queue.
* **Double-ended Queue (Deque):** Elements can be added/removed from both ends. Use std::deque.

### Breadth-First Search on Binary Search Trees
**Breadth-First Search (BFS)** for a binary tree is a traversal method where nodes are visited level by level, starting from the root and proceeding to the next level. This approach is also known as **level-order traversal.**

An easy way to understand how BFS works is to think of it like this: you start at the root, then go down a level and then read the values from left to right. Once you have read all of the values in this level, you repeat the process.

### Example
#### Given Binary Tree:
```markdown
       1
      / \
     2   3
    / \   \
   4   5   6
```

#### BFS Traversal:
1. Start with the root: ```1```.
2. Enqueue ```1```. Queue: ```[1]```.
3. Dequeue ```1```, process it, and enqueue its children (```2``` and ```3```). Queue: ```[2, 3]```.
4. Dequeue ```2```, process it, and enqueue its children (```4``` and ```5```). Queue: ```[3, 4, 5]```.
5. Dequeue ```3```, process it, and enqueue its right child (```6```). Queue: ```[4, 5, 6]```.
6. Dequeue ```4```, process it (no children to enqueue). Queue: ```[5, 6]```.
7. Dequeue ```5```, process it (no children to enqueue). Queue: ```[6]```.
8. Dequeue ```6```, process it (no children to enqueue). Queue: ```[]```.
**Result:** The BFS traversal is: ```1, 2, 3, 4, 5, 6```.

### BFS Implementation

```cpp
#include <iostream>
#include <queue>

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

void breadthFirstSearch(BinarySearchTree& t)
{
    std::queue<Node*> q; // Creates a queue for all of the nodes in the BST

    if (t.getRoot()) // Prints out the root.
    {
        std::cout<<t.getRoot()->data<<std::endl;
        q.push(t.getRoot()); // Adds the root to the queue.
    }

    int nodesPerLevel = 1; // Base Case.

    while (!q.isEmpty()) // While the queue isn't empty
    {
        for (int i = 0; i < nodesPerLevel; i++) // Traverses through each level of the tree. Does not exceed past the amount of nodes within each level.
        {
            Node* n = q.front(); // Sets a temporary node to the front of the queue.
            q.pop(); // Removes the front-most node from the queue.

            if (n->left) // If there is a left-child node, then print it out and add it to the back of the queue.
            {
                std::cout<<" -> "<<n->left->data;
                q.push(n->left);
            }

            if (n->right) // If there is a right-child node, then print it out and add it to the back of the queue.
            {
                std::cout<<" -> "<<n->right->data;
                q.push(n->right);
            }
        }

        std::cout<<std::endl;
        nodesPerLevel = q.size(); // Re-adjusts the nodesPerLevel variable to match the queue size.
    }
}
```

### Key Points
* BFS is suitable for exploring all nodes level by level.
* It uses a queue to maintain the order of exploration.
* BFS is different from Depth-First Search (DFS)(used in pre-order,post-order, and in-order), which explores as far as possible along each branch before backtracking.


## 5. Hash Tables
A hash table is a data structure that maps keys to values for efficient lookup. It uses a hashing function to convert keys into indices (or hash codes) within an array, where the values are stored.

Hash tables are widely used for their average-case time complexity of $O(1)$ for lookup, insertion, and deletion.

### Key Concepts of Hash Tables
* Hash Function
    * A function that takes a key and computes an integer value (hash code), which is used as the index in the hash table.
    * A good hash function minimizes collisions (different keys mapping to the same index).
    * Example: For a hash table that is set to the size 10:
    ```cpp
    hashCode = key % 10;
    ```
* Buckets:
    * Each index in the hash table array is called a bucket.
    * A bucket may store one or more key-value pairs if collisions occur.
* Collisions:
    * Occurs when multiple keys produce the same has code.
    * Collision resolution techniques are required to handle these.
* Load Factor:
    * Ratio of the number of elements in the hash table to its size.
    * When the load factor exceeds a threshold, the table is resized (rehashed).

### Operations in a Hash Table
1. **Insertion** - Apply the hash function to compute the index for the key, then store the key-value pair at the computed index.
2. **Search** - Use the hash function to compute the index, then check the bucket for the key.
3. **Deletion** - Compute the index using the hash function, then locate and remove the key-value pair from the bucket.

### Collision Resolution Techniques
1. **Chaining** - Each bucket stores a list (or chain) of key-value pairs. When a collision occurs, the new pair is appended to the list at that index.
Example:
```css
Bucket 0 -> [key1: value1] -> [key2: value2]
```

2. **Open Addressing** - Instead of chaining, the hash table searches for the next available bucket. Below are some of the most common methods of open addressing:
    * Linear Probing: Check the next index sequentially.
    * Quadratic Probing: Check indices using a quadratic formula
    * Double Hashing: Use a secondary hash function to find an alternate bucket.

### Hash Table Implementation
Below is an example of a hash table being implemented:

```cpp
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <utility>

class HashTable
{
    private:
        std::vector<std::list<std::pair<int, std::string>>> table;
        int numBuckets;

        int hashFunction(int key) const // Function that computes an index for a given key.
        {
            return key % numBuckets;
        }
    
    public:
        HashTable(int buckets)
        {
            numBuckets = buckets;
            table = buckets;
        }

        void insert(int key, const std::string &value)
        {
            int index = hashFunction(key);

            for (auto &pair: table[index])
            {
                if (pair.first == key)
                {
                    pair.second = value; // Updates the value if the key already exists.
                    return;
                }
            }
            table[index].emplace_back(key, value); // Adds the new key-value pair
        }

        void remove(int key)
        {
            int index = hashFunction(key);

            auto &chain = table[index];
            for (auto it = chain.begin(); it != chain.end(); ++it)
            {
                if (it->first == key)
                {
                    chain.erase(it);
                    return;
                }
            }
        }

        std::string search(int key) const
        {
            int index = hashFunction(key);

            for (const auto &pair: table[index])
            {
                if (pair.first == key)
                {
                    return pair.second;
                }
            }
            return "Key does not exist within the hash table.";
        }

        void display() const
        {
            for (int i = 0; i < numBuckets; ++i)
            {
                std::cout<<"Bucket "<<i<<": ";
                for (const auto &pair: table[i])
                {
                    std::cout<<"["<<pair.first<<": "<<pair.second<<"] ";
                }
                std::cout<<std::endl;
            }
        }
};
```

### Applications of Hash Tables
* **Databases:** Indexing for fast query results.
* **Caching:** Efficient storage and retrieval of frequently accessed data.
* **Symbol Tables:** Compilers and interpreters use hash tables to store identifiers and their attributes.
* **Sets:** Implementing data structures like sets.

### Advantages of Hash Tables
* **Fast Access:** Average-case time complexity for lookup, insertion, and deletion is $O(1)$.
* **Simple Implementation:** Easier to implement than other associative data structures like trees.

### Disadvantages of Hash Tables
* **Worst-Case Performance:** If many collisions occur, performance can degrade to $O(n)$.
* **Memory Overhead:** Requires extra memory for hash codes and potential chaining.
* **Hash Function Dependency:** Poor hash functions can lead to more collisions.


## 6. Maps
In the C++ Standard Template Library, **std::unordered_map** is a container that stores key-value pairs in an unordered manner. Unlike std::map, which maintains elements in a sorted order, std::unordered_map uses a hash table to achieve faster lookups.

### Key Features
1. **Unordered Storage:** - Elements are not stored in any specific order.
2. **Fast Operations** - Functions such as lookup, insertion, and deletion all have an average-case time complexity of $O(1)$. However, if a hash collision occurs, the complexity degrades to $O(n)$, which is the worst case.
3. **Unique Keys:** - Each key in an unordered map must be unique. If you attempt to insert a unique duplicate key to an unordered map, it will overwrite the existing value that is already present.

### When to Use std::unordered_map
* **Fast Lookup:** Use when you need fast access and don't care about the order of elements.
* **Memory Usage:** It may use more memory than ```std::map``` because of the hash table.
* **Custom Hash Functions:** You can define a custom hash function for complex key types.

### Maps Implementation and Example
Below is the code to STL Unordered Map:

```cpp
#include <iostream>
#include <unordered_map>
#include <string>

int main()
{
    std::unordered_map<std::string, int> myUnorderedMap; // Declaration for an unordered map.

    myUnorderedMap["Apple"] = 10;
    myUnorderedMap["Banana"] = 20;
    myUnorderedMap["Cherry"] = 30;

    std::cout<<"Value for the key Banana: "<<myUnorderedMap["Banana"]<<std::endl; // Accessing elements within an unordered map.

    for (const auto &pair: myUnorderedPair) // Iterating through every element within an unordered map -- prints everything.
    {
        std::cout<<pair.first<<": "<<pair.second<<"."<<std::endl;
    }

    if (myUnorderedMap.find("Apple") != myUnorderedMap.end()) // Checks if the key is in the unordered map.
    {
        std::cout<<"This key is present within the unordered map."<<std::endl;
    }
    else
    {
        std::cout<<"This key is NOT present within the unordered map."<<std::endl;
    }

    myUnorderedMap.erase("Banana"); // Erases the key Banana from the unordered map.
    std::cout<<"Size after the erasure: "<<myUnorderedMap.size()<<std::endl; // Displays the size of the unordered map.

    return 0;
}
```

## 7. Key Differences Between ```std::map``` and ```std::unorderd_map```
--------------------------------------------------------------------
| Feature              | std::map           | std::unordered_map   |
|----------------------|--------------------|----------------------|
| Ordering             | Sorted by key      | Unordered            |
| Implementation       | Balanced BST       | Hash Table           |
| Lookup Complexity    | $O(logn)$          | $O(1)$(average case) |
| Insertion Complexity | $O(logn)$          | $O(1)$(average case) |
| Key Requirements     | Requires operator< | Requires std::hash   |
--------------------------------------------------------------------