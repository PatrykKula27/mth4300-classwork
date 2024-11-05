#include <iostream>

using namespace std;

/* Write a code that checks whether the real number x belongs to the union of the open intervals (5 - 15)U(95 - 202).
If it does, the program should print yes. If it does not, the program should print no.*/ 
bool unionCheck(int num);

int main()
{
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

    uniCheck = unionCheck(userNum);
    if (uniCheck == true)
    {
        cout<<"Your number lies within the open intervals of (5-15)U(95-202)."<<endl;
    }
    else
    {
        cout<<"Your number does not lie within the open intervals of (5-15)U(95-202)."<<endl;
    }
    return 0;
}

bool unionCheck(int num)
{
    if (((num >= 5) && (num <= 15)) || ((num >= 95) && (num <= 202)))
    {
        return true;
    }
    else
    {
        return false;
    }
}