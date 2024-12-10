#include <iostream>
#include <cmath>
using namespace std;

int fibonacci(int num); // F(n) = F(n − 1) + F(n − 2)

int main()
{
    int userNum;

    cout<<"Please enter a number: ";
    cin>>userNum;
    cout<<endl;

    cout<<"Fibonacci sequence for " << userNum<< ": " << fibonacci(userNum)<<endl;
    return 0;
}

int fibonacci(int num)
{
    if (num <= 1)
    {
        return num;
    }
    return (fibonacci(num - 1) + fibonacci(num - 2));
}