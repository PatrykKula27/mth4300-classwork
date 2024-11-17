/*
True or False, Short Answers and Coding -- Midterm Review

True or False:
1. True - Passing/Returning by reference adheres to modifying an already existent variable using a pointer.
2. True - This points to the object for which a member function is called.
          Since it is a constant pointer, you cannot change the address it holds.
          However, you can use it to access the members of the current object.
3. False - A vector's size can be altered.
4. False - In the STL list class, you are never allowed to randomly access elements of a list using square brackets.
5. True - This operator is often overloaded in classes that act as "smart pointers" or
          in cases where the class behaves like a pointer.
          When you overload the -> operator, it enables your class instances to use pointer-like syntax,
          allowing you to access members of another object indirectly.
6. False - A singly linked list only has a pointer to the head node and to the next node.
           A doubly linked list has pointers to both the next and preious nodes, as well as a head node.
7. False - The worst case is O(n^2), with n being the number of elements in an array.
8. True - The functions ifstream and ofstream are used for write and read respectively.
9. True - A user-defined type must be passed through in order for operation overload to properly function.
          For example, you cannot overload the + operator for two integers directly,
          but you can overload it for a user-defined class, such as a Complex class,
          to define custom behavior for addition.
10. True - In C++, (*ptr) and -> are functionally the same.

Short Answers:
1. You would use the keyword const(). For example: void mehtod() const()
2. The elements are copied to a new array that is double it's size.
3. An advantage of using std::list over std::vector is the space time for push_front() is constant.
   The space time for vector is O(n), while the space time for list is O(1).

   Another advantage is list is a true dynamic structure, while vector is a simulated dynamic structure.
4. The time complexity for push_front() in stl list is O(1).
5. The operators that you have to overload as friend functions are input/extracction (>>) and output/insertion (<<) functions.
6. The class ofstream is used to only open files. Ofstream is only used to read files, while ifstream is used to write files.
7. A destructor is called when the class is at the end of scope (the code's closing curly brace.)
   Destructor example: ~MyClass() {}.
8. You would compile these files in the terminal with the following line:
   g++ main.cpp myclass1.cpp -o class1.out

   When compiling your code in a terminal, you only compile the interfaces (.cpp files).
   You leave out the implementation (.h files).
9. Function signature with default parameters (arguments):
   int function(int x, int y = 7) {}
10. A selection sort algorithm determinues which elements to swap at each step by finding either the maximum or the minimum.

Coding:
1. Functions to study for coding questions:
- Linked List
   - Push Back
   - Push Front
- Vector
- Selection Sort
   - Max/Min

2. Find the 5 errors.

Error #1: In rectangle.h - 
The function setHeight has const() placed in front of it despite being a function that is supposed to alter
the height variable of the class. The keyword const() disallows the function to alter the height variable.

Error #2: In rectangle.cpp - 
The function getHeight() should be a double return type, rather than being set as a void.

Error #3: In rectangle.cpp - 
The funtion getHeight() is written incorrectly. It should be Rectangle::getHeight().
This is because the function getHeight() is a member of the Rectangle class.

Error #4: In rectangle.cpp - 
Ambiguous constructor initializer list. The variables' names in the constructor must be different to the variables
already established in the class.

Error #5: In main.cpp - 
main.cpp does NOT include "rectangle.h". This is missing from the code, as not including it will disallow the program
to access the class and it's functions.

Error #6: In main.cpp - 
There is no overload of the insertion operator in (std::cout<<rect<<std::endl;)
*/

/*
Topics to Study:
- Operator Overload
- STL Vector
- Linked Lists
- Destructors
- Arrow Operators
- Selection Sort
- Big O
- File Stream
- STL List
- Iterators
*/