# Study Guide

## Topics:
1. Operator Overload
2. STL Vector 
3. Destructors
4. Arrow Operators
5. Linked List
6. STL List
7. Selection Sort 
8. Big O
9. File Streams
10. Iterators

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
friend std::ostream& operator<<(std::ostream* newOutput, ClassName& classOutput)
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
class MyVector {
private:
    T* data;          // Pointer to dynamically allocated array
    size_t size;      // Number of elements currently in the vector
    size_t capacity;  // Capacity of the vector (how many elements it can hold)

public:
    // Constructor
    MyVector() : size(0), capacity(1) {
        data = new T[capacity];  // Allocate memory for 1 element
    }

    // Destructor
    ~MyVector() {
        delete[] data;  // Free dynamically allocated memory
    }

    // Method to add an element
    void push_back(const T& value) {
        if (size == capacity) {
            resize();  // Resize if capacity is reached
        }
        data[size] = value;
        size++;
    }

    // Method to access elements
    T& operator[](size_t index) {
        if (index >= size) throw std::out_of_range("Index out of range");
        return data[index];
    }

    // Method to get the size of the vector
    size_t getSize() const { return size; }

private:
    // Helper method to resize the vector when capacity is reached
    void resize() {
        capacity *= 2;  // Double the capacity
        T* newData = new T[capacity];  // Allocate larger array

        // Copy old data to new array
        for (size_t i = 0; i < size; i++) {
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

int main() {
    std::vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    std::cout << "Vector elements: ";
    for (size_t i = 0; i < v.size(); ++i) {
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
        int val1;
        int val2;
    
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
struct Node {
    int data;        // Data part of the node
    Node* next;      // Pointer to the next node
};
```

a. **Creating the Linked List**
We'll create a class ```LinkedList``` that manages the list, starting with an empty head pointer.

```cpp
#include <iostream>

// Node structure
struct Node {
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
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    // Method to insert a node at the end
    void insert(int value) {
        Node* newNode = new Node();  // Create a new node
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            // If list is empty, new node becomes the head
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;  // Traverse to the last node
            }
            temp->next = newNode;  // Insert at the end
        }
    }

    // Method to display the linked list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    // Method to delete a node by value
    void deleteNode(int value) {
        if (head == nullptr) {
            std::cout << "List is empty, cannot delete" << std::endl;
            return;
        }

        // If the head node holds the value to be deleted
        if (head->data == value) {
            Node* temp = head;
            head = head->next;  // Move head to the next node
            delete temp;        // Free memory of old head
            return;
        }

        // Search for the node to delete
        Node* current = head;
        Node* previous = nullptr;
        while (current != nullptr && current->data != value) {
            previous = current;
            current = current->next;
        }

        // If the value is found, delete the node
        if (current != nullptr) {
            previous->next = current->next;
            delete current;
        } else {
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