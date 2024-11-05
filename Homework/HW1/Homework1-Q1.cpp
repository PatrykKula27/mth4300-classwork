#include <iostream>

using namespace std;

int max(int a, int b);

// Write a code that calculates max{a,b} and stores the result in the variable m.
int main()
{
    int a, b, m;

    cout<<"Please enter the first number: ";
    cin>>a;
    cout<<endl;

    cout<<"Please enter the second number: ";
    cin>>b;
    cout<<endl;

    m = max(a, b);

    cout<<"The maximum number between " << a << " and " << b << " is " << m << "."<<endl;
    return 0;
}

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}