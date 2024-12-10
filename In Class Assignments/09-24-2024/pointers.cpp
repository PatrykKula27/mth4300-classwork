#include <iostream>
using namespace std;

int main()
{
    int num = 42;
    int* nptr = &num;

    cout << "Address of variable: " << nptr << ". " << "Value of the integer variable: " << *nptr << "." << endl;

    num = 11;
    
    cout << "Address of variable: " << nptr << ". " << "Updated value of the integer varialbe: " << *nptr << "." << endl;
    return 0;
}