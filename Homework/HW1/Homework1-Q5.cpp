#include <iostream>

using namespace std;

/*Assume that the user is asked to provide an integer x through the standard input.
The program will check whether x is bigger than 100.
If it is, then the program will print:
Congratulations! You know about big numbers!
If x is not bigger than 100, then the program will print:
Good enough. Try with a bigger number next time.*/

int main()
{
    int x;

    while (true)
    {
        cout<<"Please enter a real number: ";
        cin>>x;
        cout<<endl;
        if (x > 0)
        {
            break;
        }
        cout<<"This is not a real number."<<endl;
    }

    if (x > 100)
    {
        cout<<"Congratulations! You know about big numbers!"<<endl;
    }
    else
    {
        cout<<"Good enough. Try with a bigger number next time."<<endl;
    }
    return 0;
}