#include <iostream>

using namespace std;

void question1();
void question2();
void question3();

int main()
{
    cout<<"Question 1: "<<endl;
    question1();
    cout<<endl;

    cout<<"Question 2: "<<endl;
    question2();
    cout<<endl;

    cout<<"Question 3: "<<endl;
    question3();
    cout<<endl;
    return 0;
}

void question1()
{
    // Write a code that calculates max{a,b} and stores the result in the variable m.
    int a, b, m;

    cout<<"Please enter the first number: ";
    cin>>a;
    cout<<endl;

    cout<<"Please enter the second number: ";
    cin>>b;
    cout<<endl;

    if (a > b)
    {
        m = a;
    }
    else
    {
        m = b;
    }

    cout<<"The maximum number between " << a << " and " << b << " is " << m << "."<<endl;
}

void question2()
{
    /* Write a code that checks whether the real number x belongs to the union of the open intervals (5 - 15)U(95 - 202).
    If it does, the program should print yes. If it does not, the program should print no.*/ 
    int userNum;
    bool uniCheck;
    while (true)
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

    if (((userNum >= 5) && (userNum <= 15)) || ((userNum >= 95) && (userNum <= 202)))
    {
        uniCheck = true;
    }
    else
    {
        uniCheck = false;
    }

    if (uniCheck == true)
    {
        cout<<"Your number lies within the open intervals of (5-15)U(95-202)."<<endl;
    }
    else
    {
        cout<<"Your number does not lie within the open intervals of (5-15)U(95-202)."<<endl;
    }
}

void question3()
{
    /*Assume that the user is asked to provide an integer x through the standard input.
    The program will check whether x is bigger than 100.
    If it is, then the program will print:
    Congratulations! You know about big numbers!
    If x is not bigger than 100, then the program will print:
    Good enough. Try with a bigger number next time.*/
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
}