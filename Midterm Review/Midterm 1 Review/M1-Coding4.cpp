#include <iostream>
using namespace std;

void func(int n);

int main()
{
    func(10);
    return 0;
}

void func(int n)
{
    if (n == 0)
    {
        cout<<endl;
        return;
    }

    cout<<"#";
    func(n-1);
    cout<<"%";
}

/* 
The following code prints out 10 # and 10 %.
After recursion prints out all 10 #, the function unwinds,
printing 10 % in reverse order.
*/

/*
Recursion unwinding means executing the remaining instructions in each function call
after the recursive call has returned.
In this case, as the recursion unwinds, the % characters are printed,
starting from func(1) all the way up to func(10).
*/