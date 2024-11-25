# Midterm 1 Review

## Sections 
1. [True or False](#true-or-false) <!-- no toc -->
2. [Short Answers](#short-answers)
3. [Coding](#coding)

## True or False:
### 1. The command to compile and rename a file is: g++ main.cpp -o main
```True``` - This is the command to compile a file in the terminal.

### 2. Docker's MAIN purpose is to make programs faster.
```False``` - Docker's main purpose is not to make programs faster but to provide a lightweight, portable, and consistent environment for building, shipping, and running applications. By using containers, Docker ensures that applications behave the same way regardless of the environment (e.g., development, testing, or production).

### 3. The float data type takes up more memory in a program than the double.
```False``` - Double stores more numbers than float.

### 4. While loops are used when you need a program to loop, and the number of times it will loop is detetmined at run time.
```True```

### 5. Is this syntax correct: 
```cpp
int matrix[3][3] = {1, 2, 3},{4, 5, 6},{7, 8, 9};
```
```False```

### 6. Base case for recursion is always required.
```True```

### 7. Arrays are technicaly pointers.
```True```

### 8. ```new``` is used to mark an item as never seen before
```False```

### 9. A method refers to a private variable in a class.
```False```

### 10. All variables on the heap must be referenced using pointers.
```True```



## Short Answers:
### 1. Name one function defined inside iostream.
cin, cout

### 2. What is the terminal command to create a new folder?
mkdir

### 3. Fix the function below:
```cpp
void my_function(int param1, param2)
{
    cout<"hello"<<endl;
    return 7;
}
```

Fixed Code:

```cpp
int my_function(int param1, int param2)
{
    std::cout<<"hello"<<std::endl;
    return 7;
}
```

### 4. What is 28%8 equal to?
28 % 8 = 4

### 5. What does the sizeof function return?
The sizeof function returns the size in bytes of the input variable.

### 6. Whats a disadvantage of recursion?
Recursion can cause a stack overflow.

### 7. Set a pointer to point to nothing
```cpp
int* ptr = nullptr;
```

### 8. Whats a dangling pointer and how is it caused.
A dangling pointer is a pointer that points to a variable that is no longer used. It is caused when the program doesn't set the pointer to nullptr after use.

### 9. For private attributes of a class, what is the name of the special method used to set the values of the attributes?
Constructor

### 10. The variable ```int* pointer = &x;``` is stored on the heap or the stack?
Stack.



## Coding