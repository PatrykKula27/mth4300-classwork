#include <iostream>
#include <cmath>
using namespace std;

/*Prompt the user to give you the size of a 2 dimensional array.
Then, fill up all of the even indices of the columns by the power of the index. (row^col).*/

int main()
{
    int row;
    int col;

    cout<<"Please input the amount of rows for the 2D Array: ";
    cin>>row;
    cout<<endl;

    cout<<"Please input the amount of columns for the 2D Array: ";
    cin>>col;
    cout<<endl;

    int userArr[row][col]; // Initalizes the array based on the user's inputted integers.

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if ((j % 2 == 0) && (i != 0))
            {
                userArr[i][j] = pow(i, j); 
            }
            else
            {
                userArr[i][j] = 0;
            }
        }
    }

    cout<<"The user created the following array: "<<endl;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout<<userArr[i][j]<< " ";
        }
        cout<<endl;
    }
    return 0;
}