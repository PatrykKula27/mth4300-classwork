#include <iostream>

using namespace std;
/* Create a program that reads real numbers of type double from the user input until it reads a negative number or zero.
The negative number (or zero) means that the input is over.
You are allowed to assume that the input from the user will contain at least one positive element.
The program should calculate the maximum of the numbers provided by the user.*/

int main()
{
    double max = 0;
    double userInput;

    cout<<"Please enter positive real numbers one by one."<<endl;
    cout<<"If you would like to stop, then please enter either a negative number or zero. "<<endl;
    cout<<endl;

    while (true)
    {
        cout<<"Enter a number: ";
        cin>>userInput;
        cout<<endl;

        if (userInput > max)
        {
            max = userInput;
        }

        if (userInput <= 0)
        {
            break;
        }
    }
    
    cout<<"The user's max number is " << max << "."<<endl;
    return 0;
}