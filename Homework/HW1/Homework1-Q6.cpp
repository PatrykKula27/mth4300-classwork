#include <iostream>

using namespace std;

/* Create a program that reads 10 real numbers from the standard input and calculates their sum.
After the user enters the 10 numbers the program should print all the numbers entered by the user, and also print the sum of the numbers.*/

int main()
{
    int sum = 0;
    int numbers[10];
    int userNum;

    for (int i = 0; i < 10; i++)
    {
        while (true) // Prevents the user from inputting any numbers that are less than or equal to 0.
        {
            cout<<"Please enter a real number: ";
            cin>>userNum;
            cout<<endl;
            if (userNum > 0)
            {
                break;
            }
            cout<<"This is not a real number."<<endl;
        }
        sum += userNum; // Adds the user's input to the sum.
        numbers[i] = userNum; // Adds the user's input to the array.
    }

    cout<<"The user inputted the following numbers: ";
    for (int i = 0; i < 10; i++) // Prints out the array in one line.
    {
        cout<<numbers[i]<<" ";
    }
    cout<<endl;
    cout<<"The sum of the user-inputted numbers is: " << sum << "." <<endl;
    return 0;
}