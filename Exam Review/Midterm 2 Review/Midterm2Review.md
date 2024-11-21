# Midterm 2 Review

## True or False

### 1. Returning by reference allows you to avoid copying an object, improving performance, but returning by value ensures the caller receives a new copy of the object.
```True``` - Passing/Returning by reference adheres to modifying an already existent variable using a pointer.

### 2. The this pointer in C++ is a constant pointer that holds the address of the current object.
```True``` - This points to the object for which a member function is called. Since it is a constant pointer, you cannot change the address it holds. However, you can use it to access the members of the current object.

### 3. The size of an std::vector is fixed once it is created and cannot change.
```False``` - A vector's size can be altered.

### 4. std::list in C++ allows random access to its elements, just like std::vector.
```False``` - In the STL list class, you are never allowed to randomly access elements of a list using square brackets.

### 5. You can overload the arrow (->) operator in a class, and it is commonly used when a class contains or behaves like a pointer.
```True``` - This operator is often overloaded in classes that act as "smart pointers" or in cases where the class behaves like a pointer. When you overload the -> operator, it enables your class instances to use pointer-like syntax, allowing you to access members of another object indirectly.

### 6. In a singly linked list, each node has a pointer to the previous node as well as the next node.
```False``` - A singly linked list only has a pointer to the head node and to the next node. A doubly linked list has pointers to both the next and preious nodes, as well as a head node.

### 7. The time complexity of the selection sort algorithm is $O(n*log(n))$ in the worst case.
```False``` - The worst case is $O(n^2)$, with n being the number of elements in an array.

### 8. The fstream class in C++ allows for both input and output operations on files.
```True``` - The functions ifstream and ofstream are used for write and read respectively.

### 9. Overloaded operators must have at least one operand that is of user-defined type(a class).
```True``` - A user-defined type must be passed through in order for operation overload to properly function. For example, you cannot overload the + operator for two integers directly, but you can overload it for a user-defined class, such as a Complex class, to define custom behavior for addition.

### 10. (*ptr).method() is the same as ptr->method()
```True``` - In C++, (*ptr) and -> are functionally the same.


## Short Answers

### 1. How do you declare a member function that guarantees it will not modify the object it belongs to?
You would use the keyword const(). For example: void method() const.

### 2. What happens to the elements of a vector when it resizes after exceeding its current capacity?
The elements are copied to a new array that is double it's size.

### 3. What is an advantage of using std::list over std::vector?
An advantage of using std::list over std::vector is the space time for push_front() is constant.
The space time for vector is O(n), while the space time for list is O(1).
Another advantage is list is a true dynamic structure, while vector is a simulated dynamic structure.

### 4. In stl the list stl data structure has a method named push front() that adds an element to the front of the list. What is the time complexity of this method?
The time complexity for push_front() in stl list is O(1).

### 5. What operator do you have to overload as friend function(typically)?
The operators that you have to overload as friend functions are input/extracction (>>) and output/insertion (<<) functions.

### 6. What class in fstream is used to only open files?
The class ofstream is used to only open files. Ofstream is only used to read files, while ifstream is used to write files.

### 7. When is a destructor called?
A destructor is called when the class is at the end of scope (the code's closing curly brace.)
```cpp
Destructor example: ~MyClass() {}.
```

### 8. Given the files main.cpp myclass1.cpp myclass1.h how would you compile these in a terminal
You would compile these files in the terminal with the following line: ```g++ main.cpp myclass1.cpp -o class1.out```
When compiling your code in a terminal, you only compile the interfaces (.cpp files). You leave out the implementation (.h files).

### 9. Write any function signature that uses default parameters(arguments).
Function signature with default parameters (arguments):
```cpp
int function(int x, int y = 7) {}
```

### 10. How does the selection sort algorithm determine which element to swap at each step?
A selection sort algorithm determinues which elements to swap at each step by finding either the maximum or the minimum.

## Coding

### Question 1: Write the code for the method(adds a node to the end of a linked list. Return true if successful otherwise false. Do not use stl).
```cpp
bool LinkedList::push_back(int val) {}
```

```cpp
#include <iostream>

bool LinkedList::push_back(int val)
{
    newNode = new Node; // Create a new node
    newNode->data = val; // Assigns the value to the node's data
    newNode->next = nullptr; // Points next to nullptr

    if (head == nullptr) // Assigns newNode to the head because there are no nodes in the linked list.
    {
        head = newNode;
        return 1;
    }

    Node* curr = head; // Creates the node pointer current and points it to the beginning of the linked list.
    while (curr->next) // While the current pointer still points to an existent node that comes after it.
    {
        curr = curr->next; // Traverses through the linked list.
    } // The while loop terminates once curr->next points to nullptr.
    curr->next = newNode; // Replaces curr's nullptr with the new node, which includes the node, it's value, and a pointer to next (which is nullptr)
    return true;
}
```

### Question 2: Find the 5+ errors in the code:
```rectangle.h```
```cpp
#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
    public:
        Rectangle(double width, double height); // Constructor

        double getPerimeter() const; // Member function to get perimeter

        void setHeight(double height) const; // Sets height

        void getHeight(); // Gets height
        
    private:
        double width; // Member variables
        double height;
};
#endif // RECTANGLE_H
```

```rectangle.cpp```
```cpp
#include<iostream>
#include "rectangle.h"

// Constructor definition
Rectangle::Rectangle(double width, double height) : width(width), height(height) {}

// Function to calculate the area of the rectangle
double Rectangle::getArea() const
{
    return width * height;
}

// Sets height
double Rectangle::getPerimeter() const
{
    return 2 * (width + height);
}

// Function to calculate the perimeter of the rectangle
double Rectangle::setHeight(double h) const
{
    height=h;
}

// Gets height
void getHeight()
{
    return height;
}
```

```main.cpp```
```cpp
#include <iostream>

int main()
{
    Rectangle rect(10.0, 5.0); // Create a Rectangle object with width 5.0 and height 3.0
    std::cout << "Area: " << rect.getArea() << std::endl;
    std::cout << "Perimeter: " << rect.getPerimeter() << std::endl;
    std::cout <<rect<< std::endl;
    return 0;
}
```

#### Error #1: In rectangle.h - 
The function setHeight has const() placed in front of it despite being a function that is supposed to alter
the height variable of the class. The keyword const() disallows the function to alter the height variable.

#### Error #2: In rectangle.cpp - 
The function getHeight() should be a double return type, rather than being set as a void.

#### Error #3: In rectangle.cpp - 
The funtion getHeight() is written incorrectly. It should be Rectangle::getHeight().
This is because the function getHeight() is a member of the Rectangle class.

#### Error #4: In rectangle.cpp - 
Ambiguous constructor initializer list. The variables' names in the constructor must be different to the variables
already established in the class.

#### Error #5: In main.cpp - 
main.cpp does NOT include "rectangle.h". This is missing from the code, as not including it will disallow the program
to access the class and it's functions.

#### Error #6: In main.cpp - 
There is no overload of the insertion operator in ```(std::cout<<rect<<std::endl;)```.