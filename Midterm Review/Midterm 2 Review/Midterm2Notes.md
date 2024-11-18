# Study Guide

## Topics:
1. Operator Overload
2. STL Vector 
3. Destructors
4. Arrow Operators
5. Linked List
6. STL List + Iterators
7. Selection Sort 
8. Big O
9. File Streams

## 1. Operator Overload
Operator Overloading allows you to redefine how operators work with user-defined data types. It allows the user to create specific scenarios for each operator in a class. Operators such as ```+```, ```-```, ```==```, ```<<```, ```>>```, ```*```, and ```/``` can be overloaded.

General Syntax: 

```cpp
ClassName operator+(const ClassName& other)
{
    return ClassName(val + other.val, value + other.value);
}
```

In order to overload an operator, a function must first state the class, then followed up by the keyword ```operator``` along with the operator that the user wishes to overload. The user then must pass the class by reference within the parameters as well as the necessary variables that the operator requires.

This case is different when it comes to overloading output and input operators. The syntax goes as follows:

```cpp
friend std::ostream& operator<<(std::ostream& newOutput, ClassName& classOutput)
{
    newOutput<<"("<<classOutput.val<<", "classOutput.value<<")"<<std::endl;
    return newOutput;
}

friend std::istream& operator>>(std::istream& newInput, ClassName classInput)
{
    std::cout<<"Enter a value: "<<std::endl;
    newInput>>classInput.val>>classInput.value;
    return newInput;
}
```

When it comes to overloading output ```(<<)``` and input ```(>>)```, you MUST use the keyword ```friend``` in order for the operator overload to properly function. You must also pass by reference a brand new variable using either ofstream or ifstream, as well as a ClassName variable which takes the user's input. This allows output and input operator overload to occur.

### Syntax for Every Operator Overload Case
```cpp
#include <iostream>
#include <cmath>

class points3D
{
    private:
        double var1;
        double var2;
        double var3;

    public:
        points3D(double v1 = 0.0, double v2 = 0.0, double v3 = 0.0)
        {
            var1 = v1;
            var2 = v2;
            var3 = v3;
        }

        points3D operator+(points3D& other)
        {
            return points3D(var1 + other.var1, var2 + other.var2, var3 + other.var3);
        }

        points3D operator-(points3D& other)
        {
            return points3D(var1 - other.var1, var2 - other.var2, var3 - other.var3);
        }

        points3D operator*(double other)
        {
            return points3D(var1*other, var2*other, var3*other);
        }

        points3D operator/(double other)
        {
            return points3D(var1/other, var2/other, var3/other);
        }

        bool operator==(points3D& other)
        {
            return (var1 == other.var1) && (var2 == other.var2) && (var3 == other.var3);
        }

        friend std::ostream& operator<<(std::ostream& noutput, const points3D& newOutput)
        {
            noutput<<"("<<newOutput.var1<<", "<<newOutput.var2<<", "<<newOutput.var3<<")"<<std::endl;
            return noutput;
        }

        friend std::istream& operator>>(std::istream& ninput, points3D& newInput)
        {
            std::cout<<"Enter a Point (x, y, z): "<<std::endl;
            ninput>>newInput.var1>>newInput.var2>>newInput.var3;
            return ninput;
        }

        double displayMagnitude()
        {
            return sqrt(pow(var1,2) + pow(var2, 2) + pow(var3, 2));
        }
};
```

### Explanation:
* For overloading operators such as ```+```, ```-```, ```*```, ```/```, and ```==```, the syntax is generally the same.
* For overloading operators such as ```<<``` and ```>>```, you must use ```friend``` and ```istream/ostream``` in order for the operator overload to properly function. The syntax vastly differs from the other methods.
* For overloading operators in general, you must pass an object by reference.

### Summary
* Operator overloading allows you to redefine how operators work with user-defined types.
* It makes code more intuitive by allowing the use of standard operators with custom objects.
* Not all operators can be overloaded, and you cannot change the fundamental behavior of an operator (like its precedence).
* Operator overloading helps create clean, readable, and maintainable code when used wisely.


## 2. STL Vector
A ```C++``` ```vector``` is a dynamic array that can grow or shrink in size. It is part of the Standard Template Library (STL) and is implemented as a template class to allow storage of any data type. A ```template``` in C++ allows you to create generic classes or functions that can operate with any data type. The ```vector``` class is written as a template so that it can hold elements of any type.

Here's a simplified example of a template class for a ```vector```:

```cpp
#include <iostream>

template <typename T>
class MyVector 
{
private:
    T* data;          // Pointer to dynamically allocated array
    size_t size;      // Number of elements currently in the vector
    size_t capacity;  // Capacity of the vector (how many elements it can hold)

public:
    // Constructor
    MyVector() : size(0), capacity(1) 
    {
        data = new T[capacity];  // Allocate memory for 1 element
    }

    // Destructor
    ~MyVector() 
    {
        delete[] data;  // Free dynamically allocated memory
    }

    // Method to add an element
    void push_back(const T& value) {
        if (size == capacity) 
        {
            resize();  // Resize if capacity is reached
        }
        data[size] = value;
        size++;
    }

    // Method to access elements
    T& operator[](size_t index) 
    {
        if (index >= size) 
        {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    // Method to get the size of the vector
    size_t getSize() const 
    { 
        return size; 
    }

private:
    // Helper method to resize the vector when capacity is reached
    void resize() 
    {
        capacity *= 2;  // Double the capacity
        T* newData = new T[capacity];  // Allocate larger array

        // Copy old data to new array
        for (size_t i = 0; i < size; i++) 
        {
            newData[i] = data[i];
        }

        delete[] data;  // Delete old array
        data = newData;  // Point to new array
    }
};
```

#### Key Components of the Vector Template
* Data Member (```T* data```):
  * The vector stores a pointer to a dynamically allocated array where the elements are stored. The type ```T``` is determined when an object of ```MyVector``` is instantiated (for example, ```MyVector<int>``` would use an array of integers).

* Size and Capacity:
  * The ```size``` keeps track of the number of elements that have been added to the vector, while ```capacity``` represents the amount of allocated memory. If more elements are added than the current capacity, the array is resized (usually doubled).

* Constructor and Destructor:
  * The constructor initializes the vector with a default capacity of 1. The destructor releases the memory when the object goes out of scope to prevent memory leaks.

* push_back():
  * This function adds an element to the vector. If the vector is full (i.e., ```size == capacity```), it calls ```resize()``` to allocate a larger array and copy the existing elements to the new array.

* operator[]:
  * Overloading the ```[]``` operator allows access to elements by their index, just like an array. It also checks for out-of-bounds access.

* resize():
  * This is a helper function that reallocates memory for the vector when the current capacity is reached, ensuring that the vector can continue to grow dynamically.

### Real-world Vector Example in STL
The ```std::vector``` class in the STL works similarly, but with many more features and optimizations (e.g., iterators, range-based access, etc.). Here's how you'd use ```std::vector```:

```cpp
#include <iostream>
#include <vector>

int main() 
{
    std::vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    std::cout << "Vector elements: ";
    for (size_t i = 0; i < v.size(); ++i) 
    {
        std::cout << v[i] << " ";
    }

    return 0;
}
```

In this case, the ```std::vector<int>``` stores integers, dynamically grows, and manages its memory efficiently without the need for manual memory management.

### Why Use a Template for Vectors?
Using templates allows you to write generic code that works with any data type. This avoids code duplication and makes the ```vector``` class versatile, enabling you to store objects of any type:

```std::vector<int>``` for integers
```std::vector<std::string>``` for strings
```std::vector<MyClass>``` for user-defined types like ```MyClass```

### Summary
The ```vector``` template class in C++ is a powerful and flexible way to handle dynamic arrays. By using templates, the ```vector``` class can store elements of any type, and with functions like ```push_back()``` and dynamic resizing, it efficiently manages memory and grows as needed. The STL ```std::vector``` is a well-optimized implementation of this idea.


## 3. Destructors
Destructors are a special function that is automatically called when an object leaves the scope of the program or is explicitly deleted within the program. Their main purpose is to free up space that was previously used by the object, such as allocated memory, file handling operations, or network connections. Destructors are extremely crucial for preventing memory leaks and overall smoothness of a program, as having resource leaks occur within your program can lead to performance issues and even crashes. Destructors cannot be overloaded. A class can have only one destructor, which has no parameters and no return type.

The syntax for a destructor goes as follows:

```cpp
class ClassName
{
    private:
        int* val1;
        int* val2;
    
    public:
        ClassName(int a, int b)
        {
            val1 = a;
            val2 = b;
        }

        ~ClassName()
        {
            // Destructor implementation
            delete val1;
            delete val2;
        }

        void functionCall()
        {
            std::cout<<"Function"<<std::endl;
        }
};

int main()
{
    ClassName* variable = new ClassName();
    variable.functionCall();
    delete variable;
    return 0;
}
```

In this code, a class is created, containing two private variables, a constructor, a destructor, and a function. When ```main.cpp``` is run, it first creates the object of ```ClassName``` using a pointer in order to allocate memory. It then calls a function, followed by deleting the object from the memory. When the line ```delete variable``` is run, the destructor is called which frees up memory in the heap.

### Summary
In summary, destructors play a vital role in managing the lifecycle of objects in C++ and ensuring proper cleanup of resources. Always consider using a virtual destructor in polymorphic base classes and ensure that dynamically allocated resources are properly released.


## 4. Arrow Operators
In C++, arrow operators ```(->)``` is used to access members (methods or variables) of an object via a pointer. It is essentially a shorthand for dereferencing the pointer and then accessing the member.

The syntax for an arrow operator goes as follows:
```cpp
pointer->variable;
```
This syntax is equivalent to:
```cpp
(*pointer).member
```
When you have a pointer to an object, the key phrase ```*pointer``` dereferences the pointer to give you direct access to the object. Then, the usage of a period ```(.)``` accesses the members of the aformentioned object. The arrow operator ```(->)``` essentially combines these two operators into one, creating a shorthanded version.

### Example
For example, let us assume the following class:

```cpp
class MyClass
{
    public:
        int value;

        void display()
        {
            std::cout<<"Value: "<<value<<std::endl;
        }
};
```

If you were to create a pointer to an object of this class, you would have to input the following:

```cpp
MyClass obj;
MyClass* ptr = &obj;
```

You can use the arrow operator to directly access the members of the object via the pointer:

```cpp
ptr->value = 15;
ptr->display();
```

### Real World Example
```cpp
#include <iostream>

class Example
{
public:
    int value;
    void display() 
    {
        std::cout<<"Value: "<<value<<std::endl;
    }
};

int main() 
{
    Example obj;         // Create an object
    obj.value = 10;      // Access using dot operator (.)
    
    Example* ptr = &obj; // Pointer to the object
    
    // Access members using the arrow operator
    ptr->value = 20;     // Equivalent to (*ptr).value = 20;
    ptr->display();      // Equivalent to (*ptr).display();
    
    return 0;
}
```

### Why Use the Arrow Operator?
The arrow operator simplifies the syntax, making the code cleaner and easier to read when working with pointers. Instead of having to type (*ptr).member every time, you can simply use ptr->member.

### Key Points:
* -> is only used when dealing with pointers to objects.
* If you're not using a pointer but a regular object, you should use the dot operator (.) instead.
* The arrow operator is equivalent to dereferencing the pointer and then using the dot operator (.).

### Example with dynamic memory:
If you dynamically allocate an object using new, you access its members through the arrow operator:

```cpp
MyClass* dynamicObj = new MyClass();
dynamicObj->value = 10;  // Use the arrow operator for pointer
dynamicObj->display();
delete dynamicObj;       // Don't forget to free dynamically allocated memory
```

### Summary:
The arrow operator (->) simplifies accessing members of an object through a pointer.
It is equivalent to dereferencing the pointer and then accessing the member.
It is often used when working with dynamically allocated objects or class instances managed through pointers.


## 5. Linked List
A **linked list** is a linear data structure where elements, called nodes, are stored in sequence, but unlike arrays, they are not stored in contiguous memory locations. Each node contains two parts:

* **Data:** The actual value the node holds.
* **Pointer (next):** A pointer/reference to the next node in the sequence.

The main advantage of linked lists over arrays is that they can grow and shrink dynamically, without needing to know their size in advance. However, they don't allow random access to elements, meaning you must traverse the list from the head to access a specific element.

### Basic Structure of a Node
In a **singly linked list**, each node points to the next node, and the last node points to ```nullptr``` (signifying the end of the list). Here's how a node is typically represented:

```cpp
struct Node 
{
    int data;        // Data part of the node. We access this variable using an arrow pointer (exampleNode->data).
    Node* next;      // Pointer to the next node. We access this variable using an arrow pointer (exampleNode->next).
};
```

a. **Creating the Linked List**
We'll create a class ```LinkedList``` that manages the list, starting with an empty head pointer.

```cpp
#include <iostream>

// Node structure
struct Node 
{
    int data;
    Node* next;
};

// Linked List class
class LinkedList {
private:
    Node* head;  // Points to the first node (or nullptr if the list is empty)

public:
    // Constructor
    LinkedList() : head(nullptr) {}

    // Destructor to clean up memory
    ~LinkedList() {
        Node* current = head; // Sets the current pointer to the head of the linked list.
        while (current != nullptr)  // While the current pointer doesn't point to a nullptr. Terminates once all nodes are nullptr.
        {
            Node* nextNode = current->next; // Creates a new node and traverses to the next node.
            delete current; // Deletes the current pointer, which essentially deletes the node that it was previously in.
            current = nextNode; // Sets current to the next node.
        }
    }

    // Method to insert a node at the end
    void insert(int value) 
    {
        Node* newNode = new Node();  // Create a new node
        newNode->data = value; // Value is assigned to the new node's data variable.
        newNode->next = nullptr; // The next pointer is initialized to nullptr, indicating that this node does not point to another node yet.

        if (head == nullptr) // If list is empty, new node becomes the head
        {
            head = newNode; // Adds the value to the empty list.
        }
        else // Starting from head, it moves from node to node using the next pointer until it reaches the last node (where temp->next == nullptr).
        {
            Node* temp = head; // A temp node pointer is created, which is given the value of head. Terminates when the node is nullptr.
            while (temp->next != nullptr)
            {
                temp = temp->next;  // Traverse to the last node. Move temp to the next node
            }
            temp->next = newNode;  // Insert at the end
            // Once the last node is found (temp is pointing to it), its next pointer is updated to point to the new node. This effectively appends the new node to the end of the list.
        }
    }

    // Method to display the linked list
    void display()
    {
        Node* temp = head; // A temp node pointer is created, which is given the value of head. Terminates when the node is nullptr.
        while (temp != nullptr) // While temp is pointing at a node with a value attached to it
        {
            std::cout << temp->data << " -> "; // Prints out the node's data value
            temp = temp->next; // Traverses to the next node.
        }
        std::cout << "nullptr" << std::endl; // Prints out nullptr
    }

    // Method to delete a node by value
    void deleteNode(int value)
    {
        if (head == nullptr) // If the list is empty, nothing occurs.
        {
            std::cout << "List is empty, cannot delete" << std::endl;
            return;
        }

        // If the head node holds the value to be deleted
        if (head->data == value)
        {
            Node* temp = head; // Creates a temporary pointer pointing at the list's head
            head = head->next;  // Move head pointer to the next node, traversing it forward.
            delete temp;        // Frees memory of old head. Deletes the node.
            return;
        }

        // Search for the node to delete
        Node* current = head; // Sets a node to point to the first value in the list, the head. This node is temporary.
        Node* previous = nullptr; // Sets a node to point to the previous value in the list. Because we're starting at the beginning of the list, this initially points to nullptr.
        while (current != nullptr && current->data != value) // While the current pointer isn't null and current's data value doesn't equal the value that we are trying to delete.
        {
            previous = current; // Traverses the previous pointer forward.
            current = current->next; // Traverses the current pointer forward.
        }

        // If the value is found, delete the node
        if (current != nullptr) // If the current pointer isn't null (the value has been found), change the previous pointer's address (currently set to previous->next, which is the current node) to the node that follows the current node (current->next).
        {
            previous->next = current->next;
            delete current; // Deletes the node because it has been found.
        }
        else // Case for when the value is not found within the list.
        {
            std::cout << "Value not found in the list" << std::endl;
        }
    }
};
```
b. **Operations on Linked List**
Now let's use the ```LinkedList``` class to insert, display, and delete nodes.

```cpp
int main() {
    LinkedList list;

    // Insert elements
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);

    // Display the linked list
    std::cout << "Linked List: ";
    list.display();  // Output: 10 -> 20 -> 30 -> 40 -> nullptr

    // Delete an element
    list.deleteNode(20);
    std::cout << "After deleting 20: ";
    list.display();  // Output: 10 -> 30 -> 40 -> nullptr

    return 0;
}
```

### Key Linked List Operations
* **Insertion:**
  * To insert a new node, we can add it to the head (beginning), tail (end), or any position in between.
  * In our example, we added nodes at the end (tail insertion).

* **Traversal:**
  * Since linked lists don't provide random access (like arrays), we have to start from the ```head``` and follow the ```next``` pointers until we reach the desired node or the end of the list.

* **Deletion:**
  * Deleting a node involves adjusting the ```next``` pointer of the previous node to point to the node after the one being deleted, and then freeing the memory of the deleted node.

* **Search:**
  * To search for a node, we traverse the list from the ```head```, checking each node's data.


#### Advantages of Linked Lists
* **Dynamic Size:** Linked lists can grow or shrink as needed, unlike arrays which require a fixed size.
* **Efficient Insertion/Deletion:** Inserting or deleting elements at the beginning or middle of the list is more efficient than arrays, as there’s no need to shift elements.

#### Disadvantages of Linked Lists
* **No Random Access:** Accessing elements requires linear traversal, unlike arrays where you can access any element in constant time.
* **Extra Memory:** Each node requires additional memory for the pointer(s), which can lead to increased memory usage compared to arrays.

### Conclusion
Linked lists are a fundamental data structure in computer science, used when dynamic size and efficient insertion/deletion are needed. The singly linked list is the simplest form, while more complex types like doubly and circular linked lists provide additional flexibility in traversal and manipulation.


## 6. STL List
In C++, much like ```std::vector```, there is also ```std::list```. STL List is a doubly linked list, which means that in addition to it's head, the linked list has pointers for both ```next``` and ```prev```.

STL list allows fast insertion and deletion at any position (constant time for these operations), but unlike STL Vector, it does NOT support random access memory, as each element must be accessed sequentially.

### Key Features
* Dynamic Size (automaticaly resizes if needed).
* Traversal both forwards and backwards via iterators.
* Efficient insertion/deletion from both ends and at the center (in comparison to vectors).

### Iterators
In STL List, doubly linked lists allow for bi-directional traversal, which occur via the usage of iterators. Iterators are similar to pointers, and in addition to the aforementioned traversal, iterators can also be used to insert or delete elements in a doubly linked list.

### STL List + Iterator Example:

```cpp
std::list<int> newList = {1, 2, 3, 4};
std::list<int>::iterator it = newList.begin(); // Points the iterator to the first element of the STL List
++it; // Moves the iterator forward to the next element
newList.insert(it, 10); // Inserts the value 10 before the iterator's current position.
```

Iterators become invalid after modifying the list struture at their position.


## 7. Selection Sort
In C++, Selection Sort is a simple comparison-based sorting algorithm. It works by repeatedly finding the minimum or maximum element from the unsorted part of the list and swapping it with the first unsorted element. This process is repeated for the remaining unsorted portion of the list, gradually sorting the entire list. Despite it's simplicity, it has an $O(n^2)$ time complexity, making it inefficient for large datasets.

### Steps for Selection Sort:
* Start with the first element: Assume that the first element of the unsorted portion is the largest.
* Compare with the rest of the elements: Compare this element with every other element in the unsorted portion. If any element is larger, update the largest element's position.
* Swap: After finding the largest element in the unsorted portion, swap it with the last element of the unsorted portion.
* Move to the next element: Repeat the process for the next element (excluding the already sorted part at the end).
* Repeat until the entire array is sorted.

### C++ Implementation of Selection Sort (Finding Maximum Element)
```cpp
#include <iostream>
using namespace std;

void selectionSort(int arr[], int n)
{
    for (int i = n-1; i >= 0; i--)
    {
        // Find the maximum element in the unsorted portion
        int maxIndex = i;
        for (int j =0; j <= i; j++)
        {
            if (arr[j] > arr[maxIndex])
            { 
                maxIndex = j;  // Update maxIndex if a smaller element is found           
            }
        }
        // Swap the found maximum element with the first element of the unsorted portion
        swap(arr[maxIndex], arr[i]);
    }
}

void printArray(int arr[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main() 
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    selectionSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
```

### Explanation:
1. Outer Loop ```for (int i = n - 1; i >= 0; i--)```:
   * Each iteration places the maximum element in the unsorted portion at the correct position at the end of the array.

2. Inner Loop ```for (int j = 0; j <= i; j++)```:
   * This loop looks for the maximum element in the unsorted portion (from 0 to i).
   * It updates maxIndex whenever it finds an element larger than the current maximum.

3. Swapping:
* The largest element found in the unsorted portion is swapped with the last element of that portion ```arr[i]```.


#### Example Output:
```c
Original array: 64 25 12 22 11 
Sorted array: 11 12 22 25 64
```

### Time Complexity:
* Worst Case Time Complexity: O(n²) where n is the number of elements in the array.
* Space Complexity: O(1), as no extra memory is used except for temporary variables.


## 8. Big O
Big O Notation is a mathematical notation used in computer science to describe the ```Time Complexity (how fast/the number of steps the algorithm takes to complete it's function)``` and/or ```Space Complexity (how much memory/the number of additional memory calls the algorithm needs to complete)``` an algorithm uses as the input size grows.

The Big O Notation mainly focusses on the worst-case scenario of an algorithm, helping to estimate how the performance of it scales with larger inputs.

### Big O Notation - Simplified
```Big O Notation``` describes the upper bound of the time or space complexity of an algorithm, showing how its performance scales as the input size increases. To simplify Big O expressions, we must follow these key principles:

1. **Ignore Constants**
   - Constants don't really matter in Big O because we're only concerned with how the algorithm grows as the input size grows. Constants have little to no impact on time or space complexity.
   - Examples:
     - $O(2n)$ simplifies to just $O(n)$.
     - $O(100n + 5)$, just like the previous example, simplifies to just $O(n)$.

2. **Drop any non-dominant terms**
   - When an algorithm has multiple terms in it's Big O Notation, keep only the term that grows the fastest as $n$ increases.
   - Examples:
     - $O(n^2 + n)$ simplifies to just $O(n^2)$ because $n^2$ grows faster than $n$ as $n$ increases.
     - $O(n^3 + n^2 + n)$ simplifies to $O(n^3)$ because $n^3$ grows faster than $n^2$ and $n$ as $n$ increases.

3. **Focus on the worst-case scenario**
   - Big O Notation primarily focusses on the worst-case scenario of an algorithm, i.e., the most time or space it will use as the input grows in size.

### Common Big O Complexities (in increasing order of growth):

- $O(1)$ – Constant time
- $O(\log n)$ – Logarithmic time
- $O(n)$ – Linear time
- $O(n \log n)$ – Linearithmic time
- $O(n^2)$ – Quadratic time
- $O(2^n)$ – Exponential time
- $O(n!)$ – Factorial time

As the input size $n$ grows, the dominant term becomes the most significant. That's why lower-order terms and constants are ignored.

### Determining an Algorithm's Time/Space Complexity
To determine an algorithm's time complexity, you analyze how the number of operations grows as the input size increases. This involves counting the dominant operations (like comparisons or assignments) in the algorithm and expressing this growth as a function of the input size, typically using Big O notation. For space complexity, you assess how much memory the algorithm uses relative to the input size, considering both auxiliary space (temporary memory used) and space for input/output. Both complexities are typically determined by examining the algorithm’s loops, recursive calls, and data structures.

### Summary:
Big O notation abstracts away constants and lower-order terms to focus on growth trends.
It helps compare algorithms and predict how they will scale as inputs increase.


## 9. File Streams
In C++, inputting and outputting files is handled using file streams from the ```<fstream>``` library. This library provides three key classes for file operations:

* ifstream: For reading from files (input file stream).
* ofstream: For writing to files (output file stream).
* fstream: For both reading and writing (input-output file stream).

### Opening and Closing Files using Fstream
To perform file operations in C++, first you must open the file. Streams can be opened either in the constructor or using the ```.open()``` method.

* Opening a File: When you open a file for reading/writing, the file stream is associated with a file on your disk.
* Closing a File: You should close the file after all operations to free up system resources.

#### Reading from Files (ifstream)
To read from a file in C++, you use the ```ifstream``` class.

```cpp
#include <iostream>
#include <string>
#include <fstream>

int main()
{
    std::ifstream inputFile("file1.txt"); // Opens the file for reading
    if (!inputFile.is_open()) // Checks if the file has properly opened. If it didn't, C++ will output an error message.
    {
        std::cerr<<"Error opening the file."<<std::endl;
        return 1;
    }

    std::string line; // Creates a string variable for each line in the file
    while (std::getLine(inputFile, line)) // Reads the file line by line
    {
        std::cout<<line<<std::endl // Outputs each line to the console.
    }

    inputFile.close(); // Closes the file to free up system resources
    return 0;
}
```

##### Explanation:
* std::ifstream inputFile("example.txt");: Opens the file example.txt for reading.
* std::getline(inputFile, line);: Reads one line from the file at a time into the line variable.
* inputFile.close();: Closes the file after reading.

#### Writing to Files (ofstream)
To write to a file in C++, you use the ```ofstream``` class.

If the file doesn't exist, then a new one will be created. If it does exit, by default, this file will be overwritten unless specified otherwise.

```cpp
#include <iostream>
#include <fstream>

int main()
{
    std::ofstream outputFile("file2.txt"); // Opens the file for writing
    if (!outputFile.is_open()) // Checks if the file has properly opened. If it didn't, C++ will output an error message.
    {
        std::cerr<<"Error opening the file."<<std::endl;
        return 1;
    }

    outputFile<<"This is a line of text.\n"; // Writing a line of text to the file
    outputFile<<"This is another line of text.\n"; // Writing a second line of text to the file

    outputFile.close(); // Closes the file to free up system resources
    return 0;
}
```

##### Explanation:
* std::ofstream outputFile("output.txt");: Opens output.txt for writing. If the file doesn't exist, it is created.
* outputFile << "text";: Writes text to the file.
* outputFile.close();: Closes the file after writing.

#### Reading and Writing Files (fstream)
To both read from and write to a file in C++, you use the ```fstream``` class.

You need to specify the mode explicitly using flags such as ```std::ios::in``` for reading, ```std::ios::out``` for writing, and ```std::ios::app``` for appending.

```cpp
#include <iostream>
#include <string>
#include <fstream>

int main()
{
    std::fstream file("file3.txt" | std::ios::in | std::ios::out | std::ios::app) // Opens the file for reading, writing, and appending.
    if (!file.is_open()) // Checks if the file has properly opened. If it didn't, C++ will output an error message.
    {
        std::cerr<<"Error opening the file."<<std::endl;
        return 1;
    }

    file<<"Adding in a line.\n"; // Writing to the file
    file.seekg(0, std::ios::beg); // Moves the file pointer to the beginning for reading.

    std::string line; // Creates a string variable for each line in the file
    while (std::getLine(file, line)) // Reads the file line by line
    {
        std::cout<<line<<std::endl // Outputs each line to the console.
    }

    file.close(); //Closes the file to free up system resources
    return 0;
}
```

##### Explanation:
* ```std::fstream file("data.txt", std::ios::in | std::ios::out);```: Opens data.txt for both reading and writing.
* file << "text";: Writes to the file.
* file.seekg(0, std::ios::beg);: Moves the file pointer back to the start to read from the file.
* std::getline(file, line);: Reads lines from the file.

### File Open Modes
When opening files, you can use different modes to control how the file is accessed:
* std::ios::in: Open for reading.
* std::ios::out: Open for writing (default behavior is to overwrite the file).
* std::ios::app: Append to the file without erasing its content.
* std::ios::binary: Open the file in binary mode (useful for non-text data).

### Checking for File Errors
You can check if a file was successfully opened using the .is_open() method. Additionally, file streams support several flags to detect errors:

* fail(): Checks if a failure occurred (e.g., trying to read past the end of the file).
* eof(): Checks if the end of file has been reached.
* bad(): Checks for non-recoverable errors like hardware failure.
* good(): Returns true if no errors occurred.

### Example: Copying File Contents
Here's a full example of how to read from one file and write its content into another:

```cpp
#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream inputFile("input.txt");  // Opens the file for reading
    std::ofstream outputFile("output.txt"); // Opens the file for writing 

    if (!inputFile || !outputFile) // Checks if the files have properly opened. If it didn't, C++ will output an error message.
    {
        std::cerr<<"Error opening the files."<<std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line))  // Reads the file line by line
    {
        outputFile<<line<<std::endl; // Write each line to output
    }

    inputFile.close(); //Closes the file to free up system resources
    outputFile.close(); //Closes the file to free up system resources
    return 0;
}
```

### Conclusion
Use ifstream for reading, ofstream for writing, and fstream for both reading and writing.
Always check if the file was opened successfully.
Remember to close the file after operations to release resources.
Use appropriate file open modes depending on whether you want to overwrite, append, or open in binary mode.