#include <iostream>
using namespace std;

int main()
{
    int x = 10;
    int* y = &x;

    x = 17;
    *y = 22;

    cout<<x<<endl;
    return 0;
}

// The code will print out 22.
/* Reasoning:
The *y operation dereferences the pointer y,
meaning it accesses the value stored at the address y is pointing to.
Since y points to x, this effectively modifies the value of x.

So, *y = 22 assigns the value 22 to x through the pointer y. Now, x holds the value 22.
*/